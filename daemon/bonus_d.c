// Changed the numbers around to reflect the 3.5 edition rules.  They havethe same effect
// but are still backwards.  I'm going to leave a copy of the current ones commented out, in
// case we want to change them back.  -Ares 8/22/06
// added in BAB for LA characters. Transformation (mage/sorc spell) also picks up here. N, 5/15.
// added psywarriors ~Circe~ 9/1/15
#include <std.h>
#include <dirs.h>
#include <daemons.h>

#define PO previous_object()
int query_stat_bonus(object who, string stat);

int high_thaco(int level) { return (level - 20); }

varargs int thaco(int level, string myclass,object ob)
{
    string file,*classes,myrace,mysubrace;
    int ret,i;

    if(!intp(level)) { return 0; }
    if(!stringp(myclass)) { return 0; }

    if(objectp(ob))
    {
        if(ob->query("new_class_type"))
        {
            ret = 0;
            if((int)ob->query_property("transformed") || (int)ob->query_property("dance-of-cuts")) { // fighter BAB under transformation/dance.
              ret = (int)ob->query_level();
              ret = ret - 20;
              ret = ret * -1;
              return ret;
            }
            classes = (string *)ob->query_classes();
            if(!sizeof(classes)) { return 0; }
            for(i=0;i<sizeof(classes);i++)
            {
                file = DIR_CLASSES+"/"+classes[i]+".c";
                if(!file_exists(file)) { continue; }
                ret += file->attack_bonus(ob);
            }
            // our LAs work as monster levels, so should give BAB per LA also
            myrace = (string)ob->query_race();
            mysubrace = (string)ob->query("subrace");
            file = DIR_RACES+"/"+myrace+".c";
            if(file_exists(file)) ret += file->level_adjustment(mysubrace);

            ret = ret - 20;
            ret = ret * -1;
            return ret;
        }
    }

    if (myclass == "fighter" || myclass == "ranger" || myclass == "paladin" || myclass == "antipaladin" || myclass == "cavalier" || myclass == "barbarian")
    {
        ret = 20 - (level -1); // going back to the old 1 point per level formula -08/19/07 Ares
      //  if(level < 21) { ret = (20 - (level - 1)); }
      //  else { ret = 1 - high_thaco(level); } // just simplified these equasions, assuming level = 20 -Ares
    }
    if (myclass == "cleric" || myclass == "druid" || myclass == "warlord" || myclass == "psywarrior" || myclass == "monk") //temporary
    {
        if(level < 21) { ret = (20 - (2*((level-1) / 3))); }
        else { ret = 8 - high_thaco(level); }
    }
    if (myclass == "mage" || myclass == "illusionist" || myclass == "psion")
    {
        if(level < 21) { ret = (20 - ((level - 1) / 3)); }
        else { ret = 14 - high_thaco(level); }
    }
    if (myclass == "thief" || myclass == "bard" || myclass == "assassin")
    {
        if(level < 21) { ret = (20 - ((level + 1) / 2)); }
        else { ret = 10 - high_thaco(level); }
    }
    return ret;
}

// 3rd edition style attack bonus.. 1 at level 2 fighter, 39 at level 40 fighter
int attack_bonus(string myclass,int level,object player)
{
    int num;
    num = thaco(level,myclass,player);
    num = 20 - (num);
    return num;
}

int monster_thaco(int hd) { return thaco((int)PO->query_level(),(string)PO->query_class()); }

int query_con_bonus(int num)
{
    if(!intp(num)) { return 0; }
    return (num - 10) / 2;
}

int query_dex_bonus(object target)
{
    object *torso=({});
    int i,dex,ret,enc,bonus,max=10;

    if(!objectp(target)) { return 0; }
    dex = (int)target->query_stats("dexterity");

    ret = (dex - 10) / 2 * -1;

    if(!interactive(target))
    {
        //limiting this to a max of 3 from dex for mobs, simply because mobs end up with stupidly high dex stats
        //unless they are manually set and hopefully this might
        //help balance things out since I removed the double dex bonus to attack that everyone got - Saide
        if(target->query_property("full ac"))
        {
            if(ret > 3) ret = 3;
            return ret;
        }
        else
        {
            return 0;
        }
    }

    // gets the max dex bonus based on armor type
    torso = (object *)target->query_armour("torso");
    if(!sizeof(torso)) { max = 10; }
    else
    {
        for(i=0;i<sizeof(torso);i++)
        {
            if(!objectp(torso[i])) { continue; }
            if(!torso[i]->is_armour()) { continue; }
            bonus = (int)torso[i]->query_max_dex_bonus();
            if(!bonus)
            {
                if(strsrch(base_name(torso[i]),"/d/common/obj/sheath/") != -1) { continue; }
                log_file("armor_no_max",""+base_name(torso[i])+" no set_max_dex_bonus() or is 0.\n");
                if(objectp(environment(torso[i])))
                {
                    tell_object(environment(torso[i]),""+torso[i]->query_name()+" has "
                        "a problem, please contact a wiz.");
                }
                continue;
            }
            if(bonus < max) { max = bonus; }
        }
    }

    // prevents the bonus from being higher than the max allowed by the armor
    max = max * -1;
    if(ret < max) { ret = max; }

    // taking this out since we're letting everybody wear bracers now -Ares
    /*
    // gives a bonus of 1 point per 7 levels for fighter or cleric not wearing heavy armor
    if ((!target->is_class("ranger") && !target->is_class("thief") &&
        !target->is_class("mage") && !target->is_class("psion")) &&
        !target->is_wearing_type("armour") && !target->is_wearing_type("armor"))
    {
        ret = ret + ( ((int)target->query_lowest_level()/7) * -1);
    }
    */

    return ret;
}

int query_stance_bonus(object victim){
  int fnord= 0;

  fnord -= (int)victim->query_defensive_bonus();
  fnord += (int)PO->query_offensive_bonus();
  return fnord;
}


//this could have been accomplished much much easier - simply by doing 1 per level for fighters, 0.75 for clerics and the like, and 0.50 for mages
//adding that up, diving by the number of classes * total level - Saide
int new_bab(int level, object ob)
{
    string *classes, file, myrace, mysubrace;
    int i, ret = 0;
    if(objectp(ob))
    {
        if((int)ob->query_property("transformed") || (int)ob->query_property("dance-of-cuts")) { // fighter BAB under transformation/dance.
            //ret = (int)ob->query_level();
            //changing to query_character_level()
            ret = (int)ob->query_character_level();
            return ret;
        }
        classes = (string *)ob->query_classes();
        if(!sizeof(classes)) { return 0; }
        for(i=0;i<sizeof(classes);i++)
        {
            file = DIR_CLASSES+"/"+classes[i]+".c";
            if(!file_exists(file)) { continue; }
            ret += file->attack_bonus(ob);
            //since mobs are usually much higher level than players - Saide
            if(!interactive(ob)) return ret;
        }
        // ret /= sizeof(classes);  // don't think there should be division here?  Attack bonus from each class should be adding -Ares
        // our LAs work as monster levels, so should give BAB per LA also
        myrace = (string)ob->query_race();
        mysubrace = (string)ob->query("subrace");
        file = DIR_RACES+"/"+myrace+".c";
        if(file_exists(file)) ret += file->level_adjustment(mysubrace);
        return ret;
    }
    return ret;
}


int tohit_bonus(int dex, int str, object target) {
    int ret, exc_str, enc_percent;
    int abonus;

/*   tell_object(PO, "You are the previous object!! [attack]"); */
    abonus = PO->query_attack_bonus();
    if (!abonus) abonus = 0;

    // Putting these in functions all their own for easier maintenance and...
    // sanity. - G.

    ret = query_dex_bonus(target)*(-1);
    //this was decreasing their bonus for some reason. *(-1) to see if it fixes. Nienne, 07/10
    //ret += query_stance_bonus(target);
    ret += abonus;
    ret += (str - 10) / 2;

    return ret;
}

//AC only starting at 10 and going up - Saide
varargs effective_ac(object who)
{
    int MyAc = 0, tmp = 0;

    if(!objectp(who)) return 0;

    //AC is starting at 10 now - Saide
    //AC starts at 10 and goes up
    //however, our AC goes down by default
    //so someone with a 2 AC should have an 18 now
    //or be 8 points away from the base of 10,
    //someone with a -1 AC would have 21 AC -
    //because they are 11 points away from the base
    //I had actually forgot this, then fixed it, then
    //realized I was right the first time - hopefully
    //this will explain why AC is 10 and then
    //the difference from 10 and AC is added
    //if the query_ac is above 0 and why
    //an additional 10 is added if it's below 0 - Saide
    MyAc = 10;
    tmp = (int)who->query_ac();
    if(tmp >= 0) MyAc += (10-tmp);
    else MyAc += 10 + (tmp * -1);
    //mob AC penalty to see if this alleviates some of the "I can't hit, might as well be a caster" problems :P - Saide, June 2016
    if(!interactive(who)) MyAc -= 5;
    return MyAc;
}

//Bonuses to avoid being hit - Saide
varargs ac_bonus(object who, object attacker)
{
    int MyBonus, tmp;
    if(!objectp(who)) return 0;
    if(!objectp(attacker)) return 0;
    MyBonus = 0;
    tmp = query_dex_bonus(who);
    tmp *= -1;
    MyBonus += tmp;
    //2AC dodge bonus to target if they are actively dodging the attacker
    if(FEATS_D->usable_feat(who,"dodge") && (string)who->query_property("dodging") == (string)attacker->query_name()) { MyBonus += 2; }
    return MyBonus;
}

varargs int hit_bonus(object who, object targ, int attack_num, object current)
{
    int th, to_hit, tmp;
    int i,j,min,hold,mysize,fired,bab_scale, pen;
    string *classes;
    object ammo;

    th = 0;

    if(!objectp(who)) { return 0; }
    if (who->query_unconscious() || who->query_bound()) { return 0; }
    if(!objectp(targ)) { return 0; }
    //in 3ed you get base attack bonus for your first attack and then
    //-5 for every subsequent attack which is actually included
    //in the bab tables so attack 1 is full bonus, attack 2
    //is -5, attack 3 is -10 - I am not entirely certain how
    //this will translate here since there are many more
    //attacks for some classes - but will try it out and adjust
    //accordingly - Saide
    //adjusting to -2 penalty per subsequent attack -
    //capping at -6 for everything now - Saide, November 2016
    if (sizeof(distinct_array((object *)who->query_wielded())) > 1)
    {
        if (attack_num == 1) { pen = 2; }
    }
    if (attack_num >= 2) { pen = 2*(attack_num-1); }
    if(pen > 6) pen = 6;

    th -= pen;

    th += (int)who->query_attack_bonus();

    tmp = new_bab((int)who->query_level(), who);
    //tmp *= -1;
    th += tmp;

    to_hit = th;

    if( (current && objectp(current)) && !who->query_property("shapeshifted") && current != who) { // weapon finesse calculations if wielding a weapon
      if(current->is_lrweapon())
      {
          ammo = present(current->query_ammo(),who);
          if(FEATS_D->usable_feat(who,"point blank shot") && objectp(ammo) && ammo->query_shots())
          {
              to_hit += (query_dex_bonus(who) * -1);
              fired = 1;
          }
      }
      if(!fired) // if they didn't fire the ranged wep, it must be a melee weapon
      {
          mysize = (int)who->query_size();
          if(mysize == 1) mysize++; //run small creatures as normal size please.
          mysize -= (int)current->query_size();
          if(FEATS_D->usable_feat(who,"weapon finesse") && (mysize > 0)) // if has-feat & weapon is smaller than user
              to_hit += (query_dex_bonus(who) * -1);
          else to_hit += query_stat_bonus(who, "strength");
      }
    }
    // if no weapon (unarmed), run the same check
    else
    {
        if(FEATS_D->usable_feat(who,"weapon finesse"))
            to_hit += (query_dex_bonus(who) * -1);
        else to_hit += query_stat_bonus(who, "strength");
    }

    // +1 BAB to rock gnome, racial, vs goblinoids
    if((string)who->query_race() == "gnome" && (string)who->query("subrace") == "rock gnome") {
      if((string)targ->query_race() == "goblin" || (string)targ->query_race() == "hobgoblin" || (string)targ->query_race() == "bugbear") to_hit += 1;
    }
    // +1 BAB to morinnen human ethnicity if mounted
    if((string)who->query_race() == "human" && (string)who->query("subrace") == "morinnen" && who->query_in_vehicle()) to_hit += 1;

    if (current && objectp(current) && current != who)
    {
        if(current->query_property("enchantment")) {
            to_hit += (int)current->query_property("enchantment");
        }
    }
    if((!objectp(current) || current == who) && (who->is_class("monk") || FEATS_D->usable_feat(who, "enchanted fists")) && !who->query_property("shapeshifted"))
    {
        //if(find_player("saide")) tell_object(find_player("saide"), "Should be using unarmed enchantments... equal to "+COMBAT_D->unarmed_enchantment(who));
        to_hit += COMBAT_D->unarmed_enchantment(who);
    }
    if(who->query("protecting")) { to_hit -= random(7)+1; }
    if(who->query_blind() && !FEATS_D->usable_feat(who,"blindfight")) { to_hit -= 8 + random(4); }


    // trying to scale bab with each attack, might take some tweaking -Ares
    // only scales on attacks with main hand, so dual wielders don't get penalized more
    bab_scale = (int)who->query_property("bab_scale");

    if(!who->query_property("testing_bab"))
    {
        to_hit += bab_scale;
    }
    return to_hit;
}

//flag = 1 for a touch attack - Saide
varargs int process_hit(object who, object targ, int attack_num, mixed current, object DebugOb, int flag)
{
    object PlayerBoss;
    int attack_roll, bon, AC = 0, pFlag;
    if(!objectp(who)) return 0;
    if(!objectp(targ)) return 0;
    if(!intp(attack_num)) attack_num = 1;
    if(!flag) AC += effective_ac(targ);
    AC += ac_bonus(targ, who);

    if (!interactive(who))
    {
        if(objectp(PlayerBoss = who->query_property("minion")))
        {
            if(userp(PlayerBoss)) pFlag = 1;
        }
        if (who->query_static_bab() && !pFlag) // giving monsters a static base attack bonus to see if this helps armor classes vs monsters -Ares
        {
            bon = (int)who->query_static_bab();
            bon += ((int)who->query_max_hp() / 250); // give some extra chance to hit based on monster health, so bosses don't miss as often
            bon += ((int)hit_bonus(who, targ, attack_num, current) / 2);
        }
        else bon = hit_bonus(who, targ, attack_num, current);
    }
    else
    {
        bon = hit_bonus(who, targ, attack_num, current);
    }

    if(intp(current)) bon += current;
    attack_roll = roll_dice(1, 20);
    //removing the 1 attack roll = automatic miss for now - perhaps it is
    //overly punitive on our game? - Saide May 2016
    /*if(attack_roll == 1 && interactive(who))
    {
        //essentially giving everyone the chance to reroll 1s, since they
        //are a miss now - at least after their first one - Saide
        if((int)who->query_property("rolled_a_1"))
        {
            who->remove_property("rolled_a_1");
            attack_roll = roll_dice(1,20);
        }
        else who->set_property("rolled_a_1", 1);
    }*/

    if(objectp(DebugOb))
    {
        tell_object(DebugOb, "Attack roll = "+ attack_roll);
        tell_object(DebugOb, "Attack bonus = "+ bon);
        tell_object(DebugOb, "AC = "+AC);
    }
    if(attack_roll == 20) return 20;
    //if(attack_roll == 1) return -1;
    //does this change make AC less OP? - Saide, August 2017
    if((bon + 15) < AC)
    {
        if(random(bon+AC+attack_roll) >= AC) return attack_roll;
        return 0;
    }
    if((attack_roll+bon) >= AC) return attack_roll;
    return 0;
}

int query_stat_bonus(object who, string stat)
{
    int ret;
    if(!objectp(who)) return 0;
    if(!stringp(stat)) return 0;
    return ret = (((int)who->query_stats(stat) - 10) / 2);
}


int damage_bonus(int str) {
    int ret;
    int dbonus;
    int estr;

/*   tell_object(PO, "You are the previous object!! [damage]"); */
    dbonus = PO->query_damage_bonus();
    if (!dbonus) dbonus = 0;

    ret += (str - 10) / 2;
    ret += dbonus;
    return ret;
}
//added to allow this to still function since
//the function that called damage_bonus() is located
//in combat_d.c now - which would mean combat_d.c is
//now the previous object - Saide, September 2016
int new_damage_bonus(object attacker, int str)
{
    int dbonus;
    if(objectp(attacker)) dbonus = (int)attacker->query_damage_bonus();
    if (!dbonus) dbonus = 0;

    dbonus += ((str-10) / 2);
    return dbonus;
}
