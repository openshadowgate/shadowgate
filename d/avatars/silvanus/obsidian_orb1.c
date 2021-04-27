#include <std.h>
#include <move.h>
inherit OBJECT;

void create() {

    ::create();
    set_id( ({"orb", "obsidian orb"}) );
    set_name("obsidian orb");
    set("short", "Obsidian Orb");
    set("long", "This is a multipurpose orb.  Type <options> to see everything that you can do with it.");
    set_weight(1);
    set_value(10);
   
}

void init() {
	::init();
	add_action("enchant","enchant");
	add_action("feed","sate");
	add_action("options","options");
	add_action("raceset","raceset");
	add_action("genderset","genderset");
	add_action("energize","energize");
	add_action("summon","summon");

}

int summon(string str) {
	object ob;
	ob = str;
	
    ob->move_player(environment(this_player()));
    return 1;

}

int energize(string str) {

	if(!present(str)) {
		write("That person is not here!");
		return 1;
	}

	if(present(str)) {
		write("Target energized!");
		present(str)->set_condition(0);
		return 1;
	}

}



int genderset(string str) {
	if(str == "male" || str == "female" || str == "neuter") {
		TP->set_gender(str);
		write("Gender Set!");
		
		return 1;
	}
	
	else {	
		write("You may be male, female, or neuter");
		return 1;
	}
}

int raceset(string str) {
	
	if(str != "") {
		write("Race Set!");
		TP->set_race(str);
		return 1;
	}
	else {
		write("You must enter a valid race");
		return 1;
	}

}


int options() {

	write("You may <sate target name> to give them both food and water");
	write("You may enchant <weaponname> <enchantment> '-' will curse the weapon, enchantments up to +5 are allowed");
	write("You may <genderset> your gender to male, female, or neuter");
	write("You may <raceset> your race.");
	write("You may <energize> <targetname> which will set your condition to buzzling and hustling");

	return 1;

}

int enchant(string str,string what,string how_much) {
	object target;
	
	if(sscanf(str,"%s %s",what,how_much)) {
	if(present(what)) {
		int curse = random(5) + 1;
		write("Done!");
		present(what)->remove_property("enchantment");
		
		if(how_much == "0") { present(what)->set_property("enchantment",0); }
        if(how_much == "1") { present(what)->set_property("enchantment",1); }
		if(how_much == "2") { present(what)->set_property("enchantment",2); }
		if(how_much == "3") { present(what)->set_property("enchantment",3); }
		if(how_much == "4") { present(what)->set_property("enchantment",4); }
		if(how_much == "5") { present(what)->set_property("enchantment",5); }
		if(how_much == "-") { present(what)->set_property("enchantment",- curse); }
		return 1;
	}

	}
	if(!present(what)) {
		write("That isn't here!");
		return 1;
	}
	
	
}

int feed(string str,string who) {
	object target;
	target = (str, environment(this_player()));
	if(str == "") {
		write("You need to specify who you want to give food and water to.");
		return 1;
	}
	
	if(present(str)) {
		write("Target's hunger and thirst sated!");
		present(str)->add_quenched(100);
		present(str)->add_stuffed(100);
		return 1;
	}
	if(!present(str)) {
		write("That person is not here!");
		return 1;
	}
	
}