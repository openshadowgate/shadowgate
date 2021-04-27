#include <std.h>
#include <daemons.h>

inherit MONSTER;

object ob;
string *killers;

void create(){
   	::create();
    	set_name("clay golem");
    	set_short("a statue of an elf");
    	set_id( ({"statue", "elf statue","golem","clay golem"}) );
    	set_long("%^RESET%^%^ORANGE%^"+
    		"Standing five feet tall this statue is made of bright red clay.  It "+
    		"was made by a very skilled artisan and no detail was spared.  The "+
    		"statue is a representation of a very well endowed male elf wearing "+
    		"only a long tunic.  In his hands are two small hammers crossed over "+
    		"his chest.  He is standing at attention as though he watches the "+
    		"room protectively.\n"+
		"%^RESET%^"
    	);
    	set_body_type("human");
    	set_race("golem");

    	set_overall_ac(-8);
    	set_hd(25, 10);
    	set_class("ranger");
    	set_mlevel("ranger", 25);
      set_wielding_limbs(({"right hand","left hand"}));
    	set_gender("male");
    	set_size(2);
    	ob = new("/d/common/obj/weapon/warhammer");
  	    	ob->move(TO);
     		ob->set_property("enchantment",3);
   		ob->set_property("monsterweapon",1);
		command("wield hammer");
  	ob = new("/d/common/obj/weapon/warhammer");
  	    	ob->move(TO);
     		ob->set_property("enchantment",3);
   		ob->set_property("monsterweapon",1);
		command("wield hammer");

    	set_stats("strength",20);
    	set_stats("dexterity", 12);
    	set_stats("intelligence", 0);
    	set_stats("wisdom", 0);
    	set_stats("constitution", 20);
    	set_stats("charisma", 18);
     	set_property("swarm",1);
     	set_max_hp(500);
    	set_hp(query_max_hp());
    	add_search_path("/cmds/ranger");
    	set_mob_magic_resistance("average");
	set_property("magic",2);
	set_property("no stab",1);
 	set_property("no hold",1);
	set_property("no paralyze",1);
   	set_property("no bows",1);
     	set_exp(2500);
      set_property("full attacks",1);
      set_max_level(15);
      set_funcs(({"berserk"}));
    	set_func_chance(30);
}

void init(){
    	::init();
    killers = SAVE_D->query_array("slore_shop_killers");

    add_action("pick_em","pick");
    if( (member_array(TPQN, killers) != -1) && !TP->query_invis() ){
       force_me("emote takes one look at "+TPQCN+" and attacks!\n");
       force_me("kill "+TPQN);
    }
}

int pick_em(string str) {
  	if(str == "lock"){
 		tell_room(ETO,"The statue suddenly comes to life and attacks!");
    		command("kill " + TP->query_name());
      }
      return 0;
}

void berserk(object targ){
   	int i, j;
   	object *inven;

   	inven = all_living(TO);
   	j = sizeof(inven);

	tell_room(ETO,"%^BOLD%^%^ORANGE%^The golem suddenly goes berserk and slams "+
		"his hammers repeatedly into the ground!\n");
	tell_room(ETO,"%^BOLD%^%^ORANGE%^The room rises up and buckles beneath "+
		"your feet!\n");
	if(base_name(ETO) == "/d/player_houses/slore/backroom") {
	   tell_room(("/d/player_houses/slore/library"),"%^BOLD%^%^YELLOW%^You "+
		  "hear loud crashes and a battle just outside the door as the floor "
		  "shakes violently.\n");
	   tell_room(("/d/player_houses/slore/bedroom"),"%^BOLD%^%^YELLOW%^You "+
		  "feel the floor shake rather violently.\n");
	   tell_room(("/d/player_houses/slore/lab"),"%^BOLD%^%^YELLOW%^You "+
		  "feel the floor shake rather violently.\n");
	}
		
   	for(i=0;i<j;i++) {
      	if(!objectp(inven[i])) continue;
      	if(inven[i] == TO) continue;
      	if(inven[i] == TP) continue;
 		if(!inven[i]->query_stats("dexterity")>random(21)){
         		tell_object(inven[i],"%^BOLD%^%^YELLOW%^You are thrown from "+
         			"your feet and land hard on the floor!");
         		inven[i]->do_damage("torso",random(20)+10);
      	}
      	else {
         		tell_object(inven[i],"%^ORANGE%^The room tosses you around, but "+
         			"you manage to remain on your feet with little damage.");
         		inven[i]->do_damage("torso",random(10)+5);
      	}
      	inven[i]->add_attacker(TO);
      	inven[i]->continue_attack();
      	inven[i]->remove_attacker(TO);
   	}
  	if(!targ->query_stats("dexterity")>random(21)){
         	tell_object(targ,"%^BOLD%^%^YELLOW%^You are thrown from "+
         		"your feet and land hard on the floor!");
      	targ->do_damage("torso",random(30)+10);
      	targ->add_attacker(TO);
      	targ->continue_attack();
      	targ->remove_attacker(TO);
      	return 1;
   	}
      tell_object(targ,"%^ORANGE%^The floor tosses you around, but "+
      	"you manage to remain on your feet with little damage.");
   	targ->do_damage("torso",random(15)+10);
   	targ->add_attacker(TO);
   	targ->continue_attack();
   	targ->remove_attacker(TO);
   	return 0;
}