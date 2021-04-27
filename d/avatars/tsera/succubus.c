//Added shadow fan and cleaned
// up code a bit and gave her new desc
//Cythera 4/05
#include "/d/islands/dallyh/ways.h"
#define OBJ "/d/islands/dallyh/marsh/obj/"+

inherit MONSTER;

void create(){
      object ob;
    	::create();
      set_id(({"demon","succubus"}));
      set_name("succubus");
     	set_short("Succubus");
    	set_long("With a body and face that would make any man"+
		" drool, the succubus is a demon that plays on the"+
		" carnal desires of men.  Her tone shapely body is "+
		"the envy of every woman.  Everything about her screams"+
		" perfection, from the proportions of her breasts, waist"+
		" and hips down to her hair.  Large leather wings hint at"+
		" the demonic background of this sensual and seductive "+
		"creature.  The succubus is a demon not to be taken "+
		"lightly.");
    	set_body_type("human");
     	set_gender("female");
	//set_property("no random treasure", 1);
      set_race("succubus");
    	set_overall_ac(-8);
    	set_property("full attacks",1);
    	set("aggressive",23);
    	set_class("fighter");
    	add_search_path("/cmds/fighter");
      set_mlevel("fighter",25);
    	set_property("full attacks",1);
      set_hd(25,120);
      set_hp(400);
      set_exp(9500);
      add_money("gold",random(250)+250);
    	set_funcs(({"beauty"}));
      set_func_chance(50);
	ob = new(OBJ"shadow_fan")->move(TO);
	ob = new("/d/common/obj/rand/rand_leath_head.c");
		if(random(4))
		{
			ob->set_property("monsterweapon",1);
		}
	ob->move(TO);
	ob = new("/d/islands/common/obj/chemise.c");
		if(random(3))
		{
			ob->set_property("monsterweapon",1);
		}
	ob->move(TO);
	command("wearall");
	command("wield fan");
      //if(!random(4))  "/d/common/daemon/randgear_d"->arm_me(TO,"edgedm",80,3);
}

void beauty(){
    object *vars;
    int i;
    vars = all_living(ETO);
    for(i=0;i<sizeof(vars);i++){
        if(vars[i] == TO) continue;
          tell_object(vars[i],"The Succubus looks stunning in the heat of the battle!");
           if(!"/daemon/saving_d"->saving_throw(vars[i],"paralyzation_poison_death"))
              {
                  tell_object(vars[i],"You stop and stare at the beauty of the Succubus and can think of nothing else!");
                vars[i]->do_damage(vars[i]->return_target_limb(),roll_dice(5,6));
                  vars[i]->set_paralyzed(40,"You are too busy admiring the Succubus' looks!");
        } else {
                  tell_object(vars[i],"You clear your head and continue attacking!");
                  vars[i]->do_damage(vars[i]->return_target_limb(),roll_dice(3,6));
        }
    }
}

void init() {
     ::init();
     if(interactive(TP) && !wizardp(TP)&& !TP->query_true_invis())
        force_me("kill "+TPQN);
}
