#include <std.h>
#include <daemons.h>

inherit MONSTER;

object ob;
int flag;

void create(){
   	::create();
    	set_name("iron statue");
    	set_short("Iron Statue");
    	set_id( ({"statue", "iron statue","golem","iron golem"}) );
    	set_long("%^CYAN%^"+
    		"Standing eight feet tall, this statue is made of iron.  Rust-free "+
    		"and gray, it is molded to look like a fighter wearing a full "+
    		"face helmet and plate armor.  The statue has both hands "+
            "resting on the pommel of a huge sword, the tip of which rests "+
            "upon the ground in front of it.\n"
    	);
    	set_race("golem");
    	set_body_type("human");
    	set_overall_ac(-10);
    	set_hd(35, 10);
    	set_class("fighter");
    	set_mlevel("fighter", 35);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_gender("male");
    	set_size(3);
  	ob = new("/d/common/obj/weapon/two_hand_sword");
  	    	ob->move(TO);
     		ob->set_property("enchantment",4);
   		ob->set_property("monsterweapon",1);
		command("wield sword");
    	set_stats("strength",22);
    	set_stats("dexterity", 16);
    	set_stats("intelligence", 0);
    	set_stats("wisdom", 0);
    	set_stats("constitution", 20);
    	set_stats("charisma", 14);
     	set_property("swarm",1);
     	set_max_hp(750);
    	set_hp(query_max_hp());
    	add_search_path("/cmds/fighter");
    	set_mob_magic_resistance("average");
	set_property("magic",1);
	set_property("no steal",1);
	set_property("no stab",1);
 	set_property("no hold",1);
	set_property("no paralyze",1);
   	set_property("no bows",1);
     	set_exp(20000);
      set_property("full attacks",1);
      set_max_level(30);
    	set_funcs(({"gas"}));
    	set_func_chance(30);
    	flag = 0;
}
void init(){
    	::init();
  	add_action("kill_em", "destroy");
	add_action("pick_em","pick");
}
int kill_em(string str) {
  	string fool,mname;
  	fool = str;
  	mname = TP->query_name();
  	if(!avatarp(TP) && !(mname == "teva") )
  		return notify_fail("The statue ignores you");
  	if(!str)return notify_fail("Who do you want the golem to destroy?");
 	if(!present(fool, ETO))return notify_fail("Try picking someone in the room!");
 	tell_room(ETO,"The statue suddenly comes to life and attacks!");
 	command("kill " + fool);
 	command("rush " + fool);
      return 0;
}
int pick_em(string str) {
  	if(str == "gates" || str == "lock on gates" || str == "lock"){
 		tell_room(ETO,"The statue suddenly comes to life and attacks!");
    		command("kill " + TP->query_name());
    		command("rush " + TP->query_name());
      }
      return 0;
}
void gas(object targ){
	int dex,con,poison,para;
	con = targ->query_stats("constitution");
	dex = targ->query_stats("dexterity");
	if(random(20) > dex) {
		tell_object(targ,"%^GREEN%^Greenish-gray gas issues out of "+
			"the mouth of the golem and into your face!%^RESET%^");
		tell_room(ETO,"%^GREEN%^Greenish-gray gas issues out of the "+
			"golems mouth into "+targ->query_cap_name()+"'s "
                        "face.%^RESET%^",targ);
		if(random(20) > con){
			targ->force_me("emote %^BOLD%^%^GREEN%^coughs and chokes!%^RESET%^");
			poison = roll_dice(10,6);
			para = random(8) + 3;
	        	targ->set_paralyzed(para,"You are coughing and choking on the gas!");
			targ->set_blind(1);
			targ->add_poisoning(poison);
			targ->setPoisoner(TO);
			targ->add_attacker(TO);
			targ->continue_attack();
		}else{
			targ->force_me("emote %^BOLD%^%^GREEN%^holds his breath and "+
				"hopes for the best.");
			targ->set_blind(1);
			tell_object(targ,"Too bad you could not keep the gas from "+
				"getting into your eyes!");
			targ->force_me("emote howls as the gas enters their eyes.");
		}
	}else {
		tell_object(targ,"%^GREEN%^Greenish-gray gas issues out of the golem's "+
			"mouth, but you manage to avoid breathing any of it.");
		tell_room(ETO,"Greenish_gray gas issues out of the golem's "+
			"mouth, but "+targ->query_cap_name()+" manages to avoid "+
			"breathing any of it.",targ);
	}
}

void heart_beat(){
  	object atkr;
  	if(!objectp(TO)) return;
  	::heart_beat();
  	atkr = query_current_attacker();
  	if(!atkr) {
    		flag = 0;
    		return;
  	}else	flag = 1;
  	if(flag == 0) return;
  	command("rush "+atkr->query_name());
}