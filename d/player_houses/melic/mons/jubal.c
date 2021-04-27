#include <std.h>
inherit MONSTER;

int FLAG;
object ob;

void create(){
::create();
	set_name("jubal");
	set_short("Jubal, Hunt Master");
	set_id(({"jubal","hunt master","demon","greater demon"}));
	set_long(
		"Jubal looks at you with smouldering red glowing eyes.  This demon is "+
		"Malar's personal hunt master.  His complexion is a mottled green and "+
		"seems to change as he moves to match the terrain. His skin apperas to "+
		"be made up of tiny smooth scales.  His teeth look very sharp and pointed "+
		"and look to be the teeth of a carnivore.  Jubal smiles a viscious little "+
		"smile as he takes in your reaction to him."
	);
	set_gender("male");
	set_race("demon");
	set_hd(35,50);
	set_max_hp(1000+random(150));
	set_hp(query_max_hp());
	set_alignment(9);
	set_body_type("humanoid");
	set_size(2);
	set_overall_ac(-20);
	set_class("ranger");
	set_mlevel("ranger",45);
	set_class("thief");
	set_mlevel("thief",45);
	set_level(35);
	set_property("full attacks",1);
	set_property("swarm",1);
	set_mob_magic_resistance("average");
	set_property("magic",1);
	set_property("no hold",1);
	set_property("no paralyze",1);
   	set_property("no bows",1);
	set_exp(5000);
	set_emotes(19, ({
		"%^RED%^Jubal whispers:%^RESET%^ I can smell your fear!",
		"%^RED%^Jubal smiles wickedly. %^RESET%^",
		"%^RED%^Jubal whispers: %^RESET%^Your ears will make wonderful trophies!",
		"%^BOLD%^%^RED%^Jubal laughs wildly.%^RESET%^",
		"%^RED%^Jubal whispers: %^RESET%^Run while you can little one, make "+
			"this interesting!",
		"%^RED%^Jubal whispers: %^RESET%^`You really think you have a "+
			"chance...wonderful spirit.",
		"%^RED%^Jubal whispers: %^RESET%^I will bathe in your blood and eat your liver!",
		"%^RED%^Jubal growls: %^BOLD%^%^BLACK%^YOUR SOUL IS ALREADY MINE!%^RESET%^",
		"%^RED%^Jubal whispers: %^RESET%^What is keeping you up!",
		"%^BOLD%^%^CYAN%^Jubal whispers to you: %^RESET%^Malar will feast on your eyes!",
		"%^RED%^Jubal whispers: %^RESET%^Your resistance amuses me greatly."}), 1);
	set_funcs(({"fear"}));
	set_func_chance(20);
	ob = new("/d/attaya/obj/screamer.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wield screamer");
	ob = new("/d/attaya/obj/screamer.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wield screamer");
    	ob = new("/d/laerad/obj/bracers6.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear bracers");
    	ob = new("/d/deku/armours/ring_p.c");
    		ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear ring");
	command("speech whisper");
}
void heart_beat(){
	object ob, demon;
	::heart_beat();
	if(!present("corpse",ETO)){
		if(FLAG == 0)return;
		call_out("reset_flag",5,TO);
		return;
	}
	ob = present("corpse",ETO);
	if(FLAG == 1) return;
	else if(ob->get_was_user()) {
		tell_room(ETO,"%^BOLD%^%^RED%^Jubal offers his kill to Malar!");
		ob->remove();
		FLAG = 1;
	}
	else {
		tell_room(ETO,"%^RED%^Jubal feeds on the life essence of the fallen "+
			"and grows stronger.");
		ob->remove();
		TO->heal(100+random(50));
	}
}

void init(){
::init();
	force_me("watch");
	if(TP->query_invis() && !avatarp(TP) && TP->query_level() > 25) {
		tell_object(TP,"Jubal sniffs the air then look straight at you.");
		TO->force_me("kill "+TP->query_name()+"");
	}
	else if(!TP->query_invis() && interactive(TP) && TP->query_level() > 25) {
		tell_object(TP,"%^RED%^Let the hunt begin and you are the prey!");
		TO->force_me("kill "+TP->query_name()+"");
	}
	else if(!TP->query_invis() && interactive(TP) && TP->query_level() < 26) {
		tell_object(TP,"You are not worth my time.  %^RED%^Begone before I change "+
			"my mind!%^RESET%^");
	}
	if(TP->id("horse")) {
		tell_room(ETO,"The horse gives out a shrill whinny and then keels over"+
			" dead.");
		tell_room(ETO,"%^RED%^Jubal whispers: %^RESET%^Dependence on a horse "+
			"is a weakness.\n"+
			"%^RED%^Jubal whispers: %^RESET%^I have done you a favor and "+
			"made you stronger");
		TO->force_me("cackle");
		TP->die(TO);
	}
   	if(TP->id("animated_object")) {
   		TO->force_me("emote waves his hand");
      	tell_room(ETO,"The objects fall apart!");
      	tell_room(ETO,"%^RED%^Jubal whispers: %^RESET%^Let's make this intersting.");
      	tell_room(ETO,"%^RED%^Jubal whispers: %^RESET%^You will have no need "+
      		"of those animated toys.");
      	TO->force_me("smile wickedly");
      	TP->die(TO);
   	}
}
void fear(object targ){
	int i,j;
	object *inven;
	inven = all_living(ETO);
	j = sizeof(inven);

	for(i=0;i<j;i++) {
		if(!objectp(inven[i])) continue;
		if(inven[i] == TO) continue;
		if(!"daemon/saving_d"->saving_throw(inven[i],"paralyzation_poison_death",-6)) {
			tell_object(inven[i],"%^RED%^Jubal stares into your eyes and you "+
				"feel intense fear!\n"+
				"Your heart pounds in your chest and you are frozen in your tracks!");
			inven[i]->set_tripped(1,"You are still panicked, frozen in "+
				"your tracks.");
		}
		else {
			tell_object(inven[i],"%^GREEN%^Jubal stares into your eyes and you "+
				"feel waves of fear roll over you, but you fight off the urge "+
				"to run.");
		}
	}
}
void die(object ob){
	force_me("yell YOU BASTARD!!!!!!");
	force_me("say MALAR FORGIVE ME!");
	force_me("speech scream");
	force_me("say I WILL HUNT AGAIN!");
	tell_room(ETO,"Jubal's body crumbles to the ground lifeless.");
	::die(ob);
}
void reset_flag(){
	FLAG = 0;
}
