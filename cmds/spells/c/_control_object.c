//Kineticist discipline power - has two options
//When cast on a person, it functions as animate object
//When cast without a target, it pulls objects from the astral plane and 
//causes them to protect the caster. Once a round, an object strikes a 
//random attacker, reducing the fodder by one until they are all gone

#include <magic.h>
#include <std.h>
#include <spell.h>
#include <security.h>

inherit SPELL;

object *animated, *monsters, control,*mydebris;
string arg;
int amount,flag;

void do_animate(object *stuff);
int is_enchanted(object item);
void make_animate(object thing);
void make_debris(int debris);

int object_save(object thisob, mixed targ) 
{
    if (!objectp(thisob)) return 0;
    if (!objectp(targ)) return 0;
    if (is_enchanted(thisob)) return 0;
    if (thisob->query_property("no animate")) return 0;
    if (thisob->query_property("monsterweapon")) return 0;
    if (!thisob->query_name()) return 0;
    if (thisob->is_corpse()) return 0;
    if (thisob->query_weight()>=10000)  return 0;
    return 1;
}

void create() {
    ::create();
    set_spell_name("control object");
    set_spell_level(([ "psion" : 1 ]));
    set_discipline("kineticist");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS control object on <room> || TARGET");
    set_description("This power can be used in two different ways. If "
       "cast on a room, the psionic character draws forth matter from the "
       "Material Plane, which coalesces into debris that protects the caster. "
       "Once per round, a piece of debris will strike a random attacker, "
       "causing damage but destroying the debris in the process.\n\n"
       "If cast on a target, this power functions like animate object. Some "
       "non-magical items in the target's inventory will be animated and fall "
       "under the caster's command. To command the objects, simply use <command "
       "objects to [command]>. Forcing an object to do something will affect "
       "your alignment when appropriate. \n\nEnchanted objects cannot be animated. "
       "Objects will take damage in combat and may be destroyed.  "
       "The objects will remain animated until the power ends or you <dismiss "
       "objects>.\n\nThere is a level effect that limits "
       "how large or how many objects you can animate.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    animated=({});
    monsters=({});
    mydebris=({});
    set_save("will");
    set_helpful_spell(1);
}

string query_cast_string(){
	return "%^MAGENTA%^"+caster->QCN+"'s eyes scan "+caster->QP+" "+
      "surroundings before "+caster->QS+" lifts one hand palm up.";
}

int preSpell(){
    if (!ARG) {
        tell_object(caster,"%^BOLD%^You haven't focused your mind upon "+
           "the objects.%^RESET%^");
        tell_room(place,"%^BOLD%^You feel the woosh of power flow by "+
           "as it disperses unused!%^RESET%^",caster);
        return 0;
    }
    if(present("devicex999", CASTER)) {
        tell_object(caster, "%^CYAN%^You are incapable of controlling two sets of beings.\n");
        return 0;
    }
    if(caster->query_property("control_debris")){
        tell_object(caster,"You are already controlling debris!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    object *inven, *livings;
    int tlevel,mylevel;
    clevel = CLEVEL;
    place = PLACE;
    caster = CASTER;
    arg = ARG;

    if (!objectp(place))
        place = environment(caster);

    mylevel = clevel/8;
    if(mylevel < 1) mylevel = 1;
    if(mylevel > 8) mylevel = 8;
    amount = (4+mylevel);
    if (arg=="room") {
        inven=all_inventory(place);
        livings=all_living(place);
        inven-=livings;
        tell_object(caster,"%^BOLD%^%^MAGENTA%^With a forceful push "+
           "of your psyche, you draw forth matter, shaping it into debris!%^RESET%^");
        tell_room(place,"%^BOLD%^%^MAGENTA%^An unseen force emanating "+
           "from "+caster->QCN+" flows into the room, filling the air with debris.%^RESET%^",caster);
        make_debris(amount);
        caster->set_property("control_debris",1);
        addSpellToCaster();
        return;
    }

    if (target = present(arg,place)) {
        
        if (living(target) && !target->query_property("no animate")) {
            tlevel = target->query_highest_level();
            if(!do_save(target,0)) {
            //if (!"daemon/saving_d"->saving_throw(target,"spell",tlevel-clevel-2)) {
                inven=all_inventory(target);
                tell_object(caster,"%^BOLD%^%^MAGENTA%^With a forceful push "+
                   "of your psyche, you send forth your energy over "+target->QCN+"!");
                tell_room(place,"%^BOLD%^%^MAGENTA%^An unseen force emanating "+
                   "from "+caster->QCN+" flows over "+target->QCN+"!",({caster,target}));
                tell_object(target,"%^BOLD%^%^MAGENTA%^You feel a wave "+
                   "of unseen energy wash over you.");
                inven = filter_array(inven,"object_save",TO,target);
                if (sizeof(inven))
                    do_animate(inven);
                else
                    tell_room(place,"%^CYAN%^The power fails to affect anything.");
            } else
                tell_room(place,"%^CYAN%^The power fails to affect anything.");
        } else {
                tell_object(caster,"%^BOLD%^%^MAGENTA%^With a forceful push "+
                   "of your psyche, you send forth your energy over "+target->QCN+"!");
                tell_room(place,"%^BOLD%^%^MAGENTA%^An unseen force emanating "+
                   "from "+caster->QCN+" flows over "+target->QCN+"!",caster);
            do_animate(({target}));
        }
    } else {
        tell_object(caster,"%^BOLD%^You haven't focused your mind upon "+
           "the objects.");
        tell_room(place,"%^BOLD%^You feel the woosh of power flow by "+
           "as it disperses unused!",caster);
        dest_effect();
        return;
    }
    spell_successful();
}

void do_animate(object *stuff) {
    int i, j, block_time;

    j=sizeof(stuff);
    for (i=0;i<j;i++) {
        if (!objectp(stuff[i])) continue;
        if (is_enchanted(stuff[i])) continue;
        if (stuff[i]->query_property("no animate")) continue;
        if (stuff[i]->query_property("monsterweapon")) continue;
        if (!stuff[i]->query_name()) continue;
        if (stuff[i]->is_corpse()) continue;
        if (amount<1) break;
        // added-prevent extra large items animating even if not set no animate
        if (stuff[i]->query_weight()>=10000)  continue;
        if (stuff[i]->query_weight()>=500) {
            // added to prevent getting max size item until 21st level  *Styx*
            if (amount < 15)   continue;
            if (sizeof(animated)==0) {
                make_animate(stuff[i]);
                amount=0;
                animated+=({stuff[i]});
            } else
                continue;
        } else if ( stuff[i]->query_weight()>100) {
            if (amount < 7) continue;     // was 5
            make_animate(stuff[i]);
            amount-=7;                    // was 5
            animated += ({stuff[i]});
        } else if (stuff[i]->query_weight() >= 50) {
            if (amount < 4) continue;     // was 3
            make_animate(stuff[i]);
            amount-=4;                    // was 3
            animated += ({stuff[i]});

        } else if (stuff[i]->query_weight() >= 25) {
            if (amount < 2) continue;
            make_animate(stuff[i]);
            amount-=2;
            animated += ({stuff[i]});

        } else {
            make_animate(stuff[i]);
            amount--;
            animated+=({stuff[i]});
        }
    }
    control = new("/d/magic/obj/objectremote");
    control->set_mons(monsters);
    control->set_caster(caster);
    control->move(caster);
    control->set_my_spell(TO);
    control->set_property("spelled", ({TO}));
    control->set_property("spell", TO);
    call_out("dest_effect",(2+CLEVEL)*10);
    block_time = (2 + sizeof(monsters))/2; 
    caster->setAdminBlock(block_time);
    tell_object(caster,"%^BOLD%^%^CYAN%^You begin concentrating on "+
       "imposing your will on the objects.");
    call_out("release_block", block_time, caster);
}

void make_debris(int debris) {
    int i, block_time;
    object ob;
    for (i=0;i<debris;i++) {
       if(!objectp(place)) { continue; }
       if(!objectp(caster)) { continue; }
       ob = new("/d/magic/mon/debris");
       ob->setup_debris(caster);
       mydebris += ({ ob });
       ob->add_id(""+(string)caster->query_name()+" summoned");
       ob->add_id(""+(string)caster->query_name()+" summoned debris");
       ob->set_property("spelled",({TO}));
       ob->set_property("spell",TO);
       ob->set_property("spell_creature",TO);
       ob->set_property("minion", caster);
       ob->move(place);
       caster->add_protector(ob);
       caster->add_follower(ob);
       if(!objectp(ob)) { continue; }
       if(!objectp(place)) { continue; }
       if(!objectp(caster)) { continue; }
       if(environment(caster) != place) { continue; }
    }
    tell_object(caster,"%^RESET%^%^ORANGE%^Several pieces of debris float around you, "
       "forming a protective shield.%^RESET%^");
    tell_room(environment(caster),"%^RESET%^%^ORANGE%^Dust fills the air, "
       "swirling violently and forming several pieces of debris that float "
       "around "+caster->QCN+".%^RESET%^",caster);
    environment(caster)->addObjectToCombatCycle(TO,1);
//    caster->execute_attack();
}

void execute_attack(){
   object ppl,boulder;
   string baddie;
   int mylevel,extra;
   if(caster->is_class("psywarrior")){
      mylevel = caster->query_guild_level("psywarrior");
   }else{
      mylevel = caster->query_guild_level("psion");
   }
    if (!flag) {
        ::execute_attack();
        flag = 1;
        return;
    }
    if (!objectp(caster)){
        dest_effect();
        return;
    }
    boulder = present(""+(string)caster->query_name()+" summoned debris",environment(caster));
    if(objectp(boulder)){
//      tell_object(caster,"%^RED%^Boulder found.%^RESET%^");
      ppl = caster->query_current_attacker();
      if (ppl && objectp(ppl)){
        baddie = ppl->QCN;
        extra = ((mylevel*2)/3);
        if(!objectp(ppl)) return;
//        tell_object(caster,"%^RED%^Current attacker: "+baddie+"%^RESET%^");
        tell_object(caster,"%^ORANGE%^You direct a chunk of debris straight at "+ppl->QCN+"!%^RESET%^");
        tell_room(environment(caster),"%^ORANGE%^A piece of floating debris zooms forward, striking "+ppl->QCN+"!%^RESET%^",({caster,ppl}));
        tell_object(ppl,"%^ORANGE%^A chunk of debris suddenly flies at you, striking you!%^RESET%^");
        damage_targ(ppl,ppl->query_target_limb(),extra,"untyped");
        mydebris -= ({boulder});
        boulder->remove();
      }
    }else{
       dest_effect();
       return;
    }
    environment(caster)->addObjectToCombatCycle(TO,1);
}
   
void release_block(object caster) {
    if (!objectp(caster)) {
        remove_call_out("dest_effect");
        dest_effect();
        return ;
    }
    tell_object(caster,"%^BOLD%^%^RED%^You finish concentrating on organizing your army.");
}

int is_enchanted(object item) 
{
    	int loop, allinvsize;
    	object * allinv;
    	if (!objectp(item)) return 1;
    	if (((int)item->is_armor()) && ((string)item->query_type() == "sheath")) 
	{
      	allinvsize = sizeof(allinv = all_inventory(item));
        	for (loop = 0; loop < allinvsize; loop++) 
		{
            	if (allinv[loop]->query_property("enchantment"))
			{
               		return 1;
			}
        	}
    	}
	//Removed - so that things like kits, etc, can still 
	//be animated - leaving the code, in case this
	//changes in the future or something - Saide	
	/*if(item->isMagic())
	{
		return 1;
	}*/
    	return item->query_property("enchantment");
}

void make_animate(object thing) {
    object ob, *inven;
    string *limbs,type;
    int i,j,cond;

    if (!objectp(thing)) return;
    thing->move("/d/magic/obj/place.c");
    ob=new("/d/magic/obj/aobject.c");
    caster->add_follower(ob);
    ob->set_caster(caster);
    if ((int)thing->query_weight()<11) ob->set_size(1);
    else if ((int)thing->query_weight()<101) ob->set_size(2);
    else ob->set_size(3);
    tell_room(place,"%^CYAN%^You see "+thing->query_name()+" begin to move!");
    ob->set_object(thing);
    ob->set_long(thing->query_long());
    ob->set_short(thing->query_short());
    if ( !stringp(thing->query_name()) ) {
        ob->set_name("magic object");
    } else {
        ob->set_name(thing->query_name());
    }
    ob->set_id(thing->query_id());
    ob->add_id("animated_object");
    ob->add_id("summoned monster");
    if (thing->is_armor()) {
        limbs=(string *)thing->query_limbs();
        j=sizeof(limbs);
        for (i=0;i<j;i++) {
            ob->add_limb(limbs[i],limbs[i],0,0,0);
        }
        ob->set_heart(2);
        ob->set_attack_limbs(limbs);
        ob->set_attacks_num(1);
        ob->set_nat_weapon_type("bludgeon");
        ob->set_damage(1,(int)thing->query_ac());
        ob->set_overall_ac(7-(int)thing->query_ac());
        ob->set_hd( ( ((int)thing->query_ac()*2) +1),8); //added +1 for cases=0
        ob->set_max_hp(ob->query_hp());
        cond = thing->query("condition");
        if (cond == 0) cond = 100;
        ob->set_hp((cond * (int)ob->query_max_hp())/100);
        ob->set_exp(100);
        ob->set_heart(3);
        ob->move(place);
        ob->set_property("spelled", ({TO}));
        if(objectp(caster)) ob->set_property("minion", caster);
        ob->set_property("spell", TO);
        ob->set_stats("strength",10);
        ob->set_stats("dexterity",10);
        ob->set_stats("intelligence",1);
        monsters+=({ob});
        return;
    }
    if (thing->is_weapon()) {
        type=thing->query_type();
        ob->set_heart(3);
        switch (type) {
        case "slashing":
        case "thiefslashing":
            ob->add_limb("blade","blade",0,0,0);
            ob->add_limb("hilt","hilt",0,0,0);
            ob->set_attack_limbs(({"blade"}));
            ob->set_nat_weapon_type("slashing");
            break;
        case "piercing":
        case "thiefpiercing":
        case "magepiercing":
            ob->add_limb("tip","tip",0,0,0);
            ob->add_limb("handle","handle",0,0,0);
            ob->set_attack_limbs(({"tip"}));
            ob->set_nat_weapon_type("piercing");
            break;
        case "bludgeon":
        case "magebludgeon":
            ob->add_limb("head","head",0,0,0);
            ob->add_limb("handle","handle",0,0,0);
            ob->set_attack_limbs(({"head"}));
            ob->set_nat_weapon_type("bludgeon");
            break;
        default:
            break;     
        }
        ob->add_limb("body","body",0,0,0);   // added for these cases *Styx*
        ob->set_attack_limbs(({"body"}));    // added for these cases *Styx*
        ob->set_nat_weapon_type("bludgeon"); // added for these cases *Styx*
        ob->set_attacks_num(1);
        ob->set_damage(1,(int)thing->query_wc());
        ob->set_overall_ac(5);
        ob->set_hd( (int)thing->query_wc()+(int)thing->query_large_wc(), 8);  
        ob->set_exp(100);
        ob->set_stats("strength",10);
        ob->set_max_hp(ob->query_hp());
        cond = thing->query("condition");
        if (cond == 0) cond = 100;
        ob->set_hp((cond * (int)ob->query_max_hp())/100);
        ob->move(place);
        ob->set_property("spelled", ({TO}));
        ob->set_property("spell", TO);
        if(objectp(caster)) ob->set_property("minion", caster);
        monsters+=({ob});
        return;
    }
    if (thing->is_container()) {
        inven=all_inventory(thing);
        ob->set_max_internal_encumbrance(500);
        j=sizeof(inven);
        for (i=0;i<j;i++) {
            inven[i]->move(ob);
        }
    }
    ob->add_limb("body","body",0,0,0);
    ob->set_attack_limbs(({"body"}));
    ob->set_nat_weapon_type("bludgeon");
    ob->set_attacks_num(1);
    ob->set_overall_ac(10);
    j=thing->query_weight();
    switch (j) {
    case 0..5:
        ob->set_damage(1,2);
        ob->set_hd(j,8);
        if (j = 0) ob->set_hd(1,2);
        ob->set_hp(ob->query_max_hp());
        break;
    case 6..25:
        ob->set_heart(2);
        ob->set_damage(1,2);
        ob->set_hd(j,8);
        ob->set_hp(ob->query_max_hp());
        break;
    case 26..100:
        ob->set_heart(3);
        ob->set_damage(1,j/7);
        ob->set_hd(j/6,8);
        ob->set_hp(ob->query_max_hp());
        ob->set_stats("strength",16);
        break;
    case 101..499:
        ob->set_heart(4);
        ob->set_damage(1,20);
        ob->set_hd(16,8);
        ob->set_hp(ob->query_max_hp());
        ob->set_stats("strength",17);
        break;
    default:
        ob->set_heart(4);
        ob->set_damage(1,25);
        ob->set_hd(25,8);         //was 30, cut back to 25
        ob->set_stats("strength",20);     //added to keep from maxing to 25
        ob->set_hp(250);
        break;
    }
    if (ob->query_hp() == 0)  ob->set_hp(1);
    ob->set_max_hp(ob->query_hp());
    cond = thing->query("condition");
    if (cond == 0) cond = 100;
    ob->set_hp((cond * (int)ob->query_max_hp())/100);
    ob->set_exp(100);
    ob->move(place);
    ob->set_property("spelled", ({TO}));
    ob->set_property("spell", TO);
    ob->set_property("spell_creature", TO);
    if(objectp(caster)) ob->set_property("minion", caster);
    monsters+=({ob});
    return;
}

void dest_effect() {
    int i,j;
    object ob;
    int hp,mhp, per;

    if(objectp(caster)){
       if(caster->query_property("control_debris")) {
          tell_room(environment(caster),"%^YELLOW%^The debris disperses into "
             "dust and settles back to the ground.%^RESET%^");
          if(sizeof(mydebris)){
             for(i=0;i<sizeof(mydebris);i++){
                if(!objectp(mydebris[i])) continue;
                mydebris[i]->remove();
             }
          }
          caster->remove_property("control_debris");
       }else{
          tell_room(environment(caster),"%^CYAN%^The animated objects "+
             "fall back to the ground, powerless.");
       }
    }
    j=sizeof(monsters);
    seteuid(UID_ROOT);
    for (i=0;i<j;i++) {
        if (!objectp(monsters[i])) continue;
        ob=monsters[i]->query_object();
        hp = monsters[i]->query_hp();
        mhp = monsters[i]->query_max_hp();
        if (mhp > 0)
            per = (hp *100)/mhp;
        else
            per = 0;
        if (per == 0) per = 1;
        if (!objectp(ob)) continue;
        ob->set("condition",per);
        if (objectp(ob))   ob->move(environment(monsters[i]));
        monsters[i]->remove();
    }
    if (objectp(control))
        destruct(control);
    TO->remove();
}