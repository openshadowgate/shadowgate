//Antioch Destroyed, Updated. Kismet.
#include <std.h>
#include <daemons.h>
#include "../antioch.h"
inherit ROOM;

void create() 
{
::create();
   set_terrain(BARREN);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Crumbled Gates of Antioch");
	set_long("%^BOLD%^%^WHITE%^Tendrils of darkness erupt from a hole in the ground!%^RESET%^\n"+
	"%^BOLD%^%^BLACK%^The gates of Antioch once stood here, now they have crumbled. Before them is a %^BOLD%^%^WHITE%^gaping black hole%^RESET%^%^BOLD%^%^BLACK%^, from which rises a %^RED%^poisonous%^BOLD%^%^BLACK%^, dark substance. The sky above is pitch black and the darkness is spreading across the sky like tendrils of shadow, slowly turning the entire world black. Passage to the ruined city to the west seems near impossible and %^YELLOW%^incredibly dangerous%^BOLD%^%^BLACK%^.\n"+ 
	"%^BOLD%^%^RED%^If you dwell here for more than a few seconds, your skin begins to burn, your soul is crushed by darkness and you %^YELLOW%^DIE%^BOLD%^%^RED%^.%^RESET%^\n"+
	"%^RESET%^");
	set_smell("default","The air smells of death and the rotting scent of your own sizzling flesh!");
	set_listen("default","You hear only the sounds of your worst nightmares. %^RED%^Get out! Get out now!%^RESET%^");
	set_items(([
	({"gate","gates","gates of antioch","Gates of Antioch","gates of Antioch"}) : "The gates have crumbled.",
	({"trail","road","path","street","cobbles"}) : "Tendrils of darkness flow from the gaping hole in the ground!",
	({"gaping hole","hole","tendrils"}) : "Tendrils of darkness flow out from the gaping hole in the ground, showing you visions of your worst nightmares.",
	"sky" : "The dark tendrils are turning the sky black, blanketing the world in darkness.",
	]));
	set_exits(([
	"east" : ROOMS+"trail6",
	"west" : ROOMS+"street1",
	]));
	//set_pre_exit_functions(({"west"}),({"go_west"}));
}

void reset()
{
	::reset();
	/*if(!present("guard")) { //commented out due to Ashra plot.  Remove when done.
		new(MONS+"paladin")->move(TO);
		new(MONS+"kyra")->move(TO);
	}*/
}

int go_west()
{
	object obj, shape;
      string race;
	if(!interactive(TP)) return 1;
	if(present("guard") && !TP->query_invis()) {
      if((string)TP->query_name() == "vethor" || (string)TP->query_name() == "spungold") {
         if(present("kyra")) {
            obj = present("kyra");
            obj->force_me("say Due to your crimes against this city, "+TPQCN+", you are no longer welcome here.");
            return 0;
         }
         write("The guard will not let you pass.");
         return 0;
      }
		if(ALIGN->is_evil(TP)) {
			if(present("kyra")) {
				obj = present("kyra");
				obj->force_me("say Weren't you listening? Evil is not welcome here!");
				return 0;
			}
			write("The guard will not let you pass.");
			return 0;
		}
		else if(member_array(TP->query_name(),KILLING_D->query_evil_bounties()) != -1) {
			if(present("kyra")) {
				obj = present("kyra");
				obj->force_me("say We've heard of you and your evil deeds, "+TPQCN+","+
				" if you don't leave at once I will call the guards to collect that"+
				" bounty.");
				obj->call_out("bounty_collection",12,TP);
				return 0;
			}
			write("The guard will not let you pass.");
			return 0;
		}
		else if(member_array(TP->query_name(),KILLING_D->query_bounties()) != -1) {
			if(present("kyra")) {
				obj = present("kyra");
				obj->force_me("say Law breakers are not welcome here, now leave before"+
				" I call the guards to come arrest you!");
				obj->call_out("bounty_collection",8,TP);
				return 0;
			}
			write("The guard will not let you pass.");
			return 0;
		}
		else if((string)TP->query_diety() == "jarmila") {
			return 1;
		}

		race = TP->query_race();
              if(objectp(shape = TP->query_property("shapeshifted"))) race = (string)shape->query_shape_race();
              if(objectp(shape = TP->query_property("altered"))) race = (string)shape->query_shape_race();

		if(race == "drow" || race == "ogre" || race == "half-ogre" || race == "goblin" || race == "orc" || race == "half-orc" || race ==  "hobgoblin" || race == "ogre-mage" || race == "gnoll" || race == "half-drow" || race == "kobold" || race == "bugbear" || race == "minotaur" || race == "yuan-ti") {
			if(present("kyra")) {
				obj = present("kyra");
				obj->force_me("say Haven't I already told you that "+TP->query_race()+" are not welcome in this city?");
				return 0;
			}
			write("The guard will not let you pass.");
			return 0;
		}
		if(race == "dragon") {
			if(present("kyra")) {
				obj = present("kyra");
				obj->force_me("say I stand by my vows. You may not pass!");
				return 0;
			}
			write("The guard will not let you pass.");
			return 0;
		}
		if(race == "elf" && (string)TP->query("subrace") == "fey'ri" && !TP->query_property("altered")) {
			if(present("kyra")) {
				obj = present("kyra");
				obj->force_me("say Haven't I already told you that "+TP->query_race()+" are not welcome in this city?");
				return 0;
			}
			write("The guard will not let you pass.");
			return 0;
		}
	}
	return 1;
}

void set_dir(string str)
{
	object obj;

	if(!present("kyra")) return;
	obj = present("kyra");
	if(str == "west") {
		obj->set_direction("west");
	}
	else if(str == "east") {
		obj->set_direction("east");
	}
}

void say_goodbye(string str)
{
	object obj;

	if(!present("kyra")) return;
	else {
		obj = present("kyra");
		obj->set_direction("east");
		return;
	}
}