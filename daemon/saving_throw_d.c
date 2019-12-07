//Added druids to use cleric saves. They were defaulting to fighter. ~Circe~ 5/17/13
#include <std.h>
#include <daemons.h>
#include <dirs.h>
inherit DAEMON;

//All saves are in the format ({ fort, reflex, will })
// Using a mapping to track the numbers all through the daemon for debug purposes.
mapping save_info=([]);

void create() { ::create(); }

varargs void do_save(object ob, int dc, string type, raw_save)
{
    int *saves,num,save,roll1,i,level,statbonus,mod;
    string *classes,file;

    switch(type) {
      case "fortitude": case "fort":   num = 0; save_info["save_type"] = "fort"; break;
      case "reflex": num = 1; save_info["save_type"] = "reflex"; break;
      case "will":   num = 2; save_info["save_type"] = "will"; break;
    }

    classes = (string)ob->query_classes();
    save = 0;
    //tell_object(find_player("saide"), "ob = "+identify(ob) +", dc = "+dc+", type = "+type);
    for(i=0;i<sizeof(classes);i++) {
        // for each class... step 1: get base saves up to L20 from the class file
        file = DIR_CLASSES+"/"+classes[i]+".c";
        if(!file_exists(file)) continue;

        level = ob->query_class_level(classes[i]);
        if(level > 20) level = 20;
        saves = (string)file->saving_throws(ob);
        if(!sizeof(saves)) continue;

        // starting saving throw from class template; if 1 it is a strong throw (2+ level/2), if 0 it is weak (level/3)
        if(saves[num]) save += (2 + (level/2));
        else save += (level/3);

        // step 2: get any extra points from levels past 20, if applicable
        level = ob->query_class_level(classes[i]);
        if(level < 21) continue;
        level -= 20;
        save += level/2; // past L20, all saves increase at level/2 rate. Let's give the SC a bit of a nudge up!
    }
    save_info["base_class_save"] = save; // this is without any modifiers
    //tell_object(find_player("saide"), "save = "+save);
    // step 3: now that we've collated all class levels for saving throws, let's add stat bonuses!
    switch(type) {
      case "fort": case "fortitude":  statbonus = (int)ob->query_stats("constitution"); break;
      case "reflex": statbonus = (int)ob->query_stats("dexterity");    break;
      case "will":   statbonus = (int)ob->query_stats("wisdom");       break;
    }

    if(ob->is_undead())
        if(type == "fort" ||
           type == "fortitude")
            statbonus = ob->query_stats("charisma");

    statbonus = (statbonus - 10)/2;
    save_info["base_stat_bonus"] = statbonus;
    save += statbonus;
    //tell_object(find_player("saide"), "save = "+save+", statbonus = "+statbonus);
    // step 4: let's move all the misc saving throw bonuses here so we don't muddy the waters! Confusing enough that DCs are a negative mod.
    switch(type) {
      case "fort": case "fortitude":
        mod = (int)ob->query_saving_bonus("fortitude");
        if((string)ob->query_race() == "human" && (string)ob->query("subrace") == "aesatri") mod += 1; // aesatri racial +1 to fort saves
      break;
      case "reflex":
        mod = (int)ob->query_saving_bonus("reflex");
        if((string)ob->query_race() == "human" && (string)ob->query("subrace") == "senzokuan") mod += 1; // senzokuan racial +1 to reflex saves
      break;
      case "will":
        mod = (int)ob->query_saving_bonus("will");
        if((string)ob->query_race() == "human" && (string)ob->query("subrace") == "maalish") mod += 1; // maalish racial +1 to will saves
      break;
    }
    // general sources of bonuses to all saving throws
    if((string)ob->query_race() == "halfling" && (string)ob->query("subrace") == "lightfoot halfling") mod += 1; // lightfoot halfling +1 luck bonus racial
    if((string)ob->query_race() == "gnome" && ((string)ob->query("subrace") == "deep gnome" || (string)ob->query("subrace") == "svirfneblin")) mod += 2; // svirfneblin +2 saves racial
    if(FEATS_D->usable_feat(ob,"resistance"))
        mod += 2;
    if(FEATS_D->usable_feat(ob,"force of personality"))
        mod += ((int)ob->query_stats("charisma") -10)/2;
    save_info["misc_modifiers"] = mod;
    {
        if(type=="will")
            if(ob->is_vampire())
                mod -= (20000-(int)ob->query_bloodlust())/2000;
    }
    save += mod;
    if(raw_save) return save;
    //tell_object(find_player("saide"), "save now = "+save+", mod = "+mod);
    if(!ob->query("new_class_type")) { // this is just a throwback to average out mobs... we'll need something better longterm?
        if(!save || !sizeof(classes)) { save = 0; }
        else { save = save / sizeof(classes); }
    }

    save_info["dc"] = dc;
    save_info["final_saving_throw"] = save;
    //hijacking dc here, if it's positive, make it negative - Saide, December 2016
    //should work okay - if dc is positive then there is no way
    //anyone would EVER fail their saving throw
    if(dc > 0) dc *= -1;
    roll1 = roll_dice(1,20) + save + dc; // note that the mod is inclusive of all bonuses as well as the DC (which is added as a negative)
    //tell_object(find_player("saide"), "save = "+save+", statbonus = "+statbonus +", roll1 = "+roll1);
    save_info["pass_or_fail_by"] = roll1;
    if(roll1 >= 0) { save_info["save_result"] = 1; }
    else { save_info["save_result"] = 0; }
}

int get_save(object who, string type)
{
    return do_save(who, 0, type, 1);
}

void check_save(object ob)
{
    object *weapons;
    int x;
    if(!objectp(ob)) return 0;
    if(save_info["save_result"] != 1)
    {
        if(FEATS_D->usable_feat(ob, "diamond soul"))
        {
            weapons = ob->query_wielded();
            for(x = 0;x < sizeof(weapons);x++)
            {
                if(!objectp(weapons[0])) continue;
                if((int)weapons[0]->query_size() > 1) return 0;
                continue;
            }
            if(!ob->is_ok_armour("barb")) return 0;
            if(ob->spend_ki(1)) return 1;
        }
    }
    return 0;
}

int fort_save(object ob, int dc)
{
    do_save(ob,dc,"fort");
    if(check_save(ob)) do_save(ob,dc,"fort");
    return save_info["save_result"];
}

mapping debug_fort_save(object ob, int dc) {
    do_save(ob,dc,"fort");
    return save_info;
}

int reflex_save(object ob, int dc)
{
    do_save(ob,dc,"reflex");
    if(check_save(ob)) do_save(ob,dc,"reflex");
    return save_info["save_result"];
}

mapping debug_reflex_save(object ob, int dc) {
    do_save(ob,dc,"reflex");
    return save_info;
}

int will_save(object ob,int dc)
{
    do_save(ob,dc,"will");
    if(check_save(ob)) do_save(ob,dc,"will");
    return save_info["save_result"];
}

mapping debug_will_save(object ob,int dc) {
    do_save(ob,dc,"will");
    return save_info;
}
