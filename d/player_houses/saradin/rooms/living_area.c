//Coded by Diego//
// key moved to here from behind_boxes room by Styx and various typos fixed after Saradin said the other room was retired due to being too inacessible.


#include <std.h>
#include "../saradin.h"

inherit VAULT;
int CRACKED, FLAG;

void create(){
	::create();
	set_name("living area");
   set_short("living area");
   set_long(
   	"%^RESET%^%^CYAN%^"+
   	"The room is lavishly decorated with a fine plush couch "+
   	"and %^BOLD%^magically %^YELLOW%^lit lamps %^RESET%^%^CYAN%^in "+
   	"all four corners of the room.  Along the walls are many "+
   	"various types of paintings and a large finely crafted mirror "+
   	"is in the southwest corner of the room.  A table with a %^MAGENTA%^deck "+
   	"of cards %^CYAN%^is in the northwest corner of the room with four "+
   	"chairs around it.  Two bookshelves stand along the east and "+
   	"west walls and are filled with books.  A fine rug covers the "+
   	"floor and makes the wood floor quite comfortable to walk on."+
   	"%^RESET%^"
   );
  	set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_smell("default","This room smells clean, but not odorless.");
	set_listen("default","You hear only the sound you bring into this room.");
	set_items(([
     	"paintings" : "Which painting are you looking at?  There "+
     		"are four paintings, maybe you should look painting 1 etc.",
	({"chair","chairs"}) : "Standard, but sturdy wooden chairs surround the table.",
	({"painting","painting 1"}) : "This is a painting of a ship sailing the ocean.",
	"painting 2" : "This painting depicts a large battle between goblins and orcs.",
	"painting 3" : "This painting shows a grisly scene of a massive titan "+
			"crushing an elf in his hand.",
	"painting 4" : "This is a risque portrait of a woman bathing.",
	"table" : "A beautifully crafted table that has a "+
			"%^MAGENTA%^deck of cards %^RESET%^sitting on it.",
	"couch" : "Lush and plush, this couch looks quite comfortable.",
	({"bookshelf","bookshelves"}) : "There is a bookshelf in the east "+
		"and the west.  The shelves are filled with book of various subject "+
		"and genre.  The bookshelves are made of a dark stained oak.",
	({"books","book"}) : "The books are of many different subjects and "+
		"many different titles from fiction to history.  The books look "+
		"to be used, but also look to have been cared for in such a way "+
		"so that they will continue to be useable for some time to come.",
	"mirror" : "The mirror is affixed to the wall in the southwest part "+
		"of the room, waiting for someone to gaze into it."
   ]));

//	new("/d/shadow/obj/misc/deckofcards")->move(TO);

   set_exits(([
		"north" : SROOMS+"hallway",
		"south" : SROOMS+"bath",
		"southeast" : SROOMS+"bedroom"
  ]));
   set_search("bookshelf", "On closer inspection, one shelf looks like it is loose in the grooves that hold it.");

   set_door("inner door",SROOMS+"hallway","north","black skeleton key");
     set_door_description("inner door","This door is made "+
   	"from solid oak and there is no knob on this side of the door, "+
   	"but there is a keyhole.");
     set_string("inner door","open","The door opens quietly into the hallway.");

   set_door("bedroom door",SROOMS+"bedroom","southeast","black skeleton key");
     set_locked("bedroom door",1,"lock");
     (SROOMS+"bedroom")->set_locked("bedroom door",1,"lock");
     set_door_description("bedroom door","This is a simply made wooden door with a lock.");
     set_string("bedroom door","open","You open the door noiselessly into the bedroom.");

   set_door("bathroom door",SROOMS+"bath","south","black skeleton key");
     set_locked("bathroom door",0,"lock");
     (SROOMS+"bath")->set_locked("bathroom door",0,"lock");
     set_door_description("bathroom door","This is a simply made wooden door with a lock.");
     set_string("bathroom door","open","You open the door noiselessly into the bathroom.");
   CRACKED = 0;
}

void reset() {
   ::reset();
  if (!present("deck of cards")) {
        new("/d/shadow/obj/misc/deckofcards")->move(TO);
  }
   if(!present("pirate")) {
      new("/d/player_houses/mons/saradin_guard")->move(TO);
      new("/d/player_houses/mons/saradin_guard")->move(TO);
   }
}

void init() {
  	::init();
  	add_action("move_em","unhang");
  	add_action("replace_em","replace");
  	add_action("open_em","open");
  	add_action("push_em","push");
  	add_action("gaze_em","gaze");
	add_action("sit_em","sit");
  	add_action("slide_em","slide");
}

int slide_em(string str) {
   if(!str) {
      tell_object(TP,"%^BOLD%^Slide what?");
      return 1;
   }
   if(str == "shelf") {
	if(FLAG == 1) {
		tell_object(TP,"%^BOLD%^You find nothing behind the "+
			"shelf at the moment.");
		tell_room(TO,"%^BOLD%^"+TPQCN+" fiddles with a shelf on the bookcase.", TP);
		if((string)TP->query_name() == "saradin")
		   tell_object(TP,"%^BOLD%^Someone must have pinched your stashed key.");
		return 1;
	} else {
		tell_room(TO,"%^BOLD%^"+TPQCN+" fiddles with a shelf on the bookcase.", TP);
		tell_room(TO,"%^BOLD%^A hidden key falls from behind the shelf.");
		FLAG = 1;
		new(SOBJ+"skel_key")->move(TO);
		return 1;
	}
   }
}

int sit_em(string str) {
  	if(!str) {
   	tell_object(TP,"Sits on the floor.");
      return 1;
   }
  	if(str == "couch" || str == "on couch" || str == "on the couch"){
		tell_room(TO,"%^BOLD%^"+TPQCN+" sits on the couch with a relaxed sigh.",TP);
		tell_object(TP,"%^BOLD%^You sit on the couch and feel it "+
			"comfortably supporting you.");
   	return 1;
   }else if(str == "chair" || str == "on chair" || str == "on the chair"){
		tell_room(TO,"%^BOLD%^"+TPQCN+" pulls out a chair and sits at the table.",TP);
		tell_object(TP,"%^BOLD%^You pull out a chair and sit down at the table.");
   	return 1;
   }else if(str == "table" || str == "on table" || str == "on the table"){
		tell_room(TO,"%^BOLD%^"+TPQCN+" plops "+TP->query_possessive()+" big "+
			"old butt down on the table.",TP);
		tell_object(TP,"%^BOLD%^You sit on top of the table.");
   	return 1;
   }else{
		tell_room(TO,"%^BOLD%^"+TPQCN+" sits on the "+str+".",TP);
		tell_object(TP,"%^BOLD%^You sit on the "+str+".");
   	return 1;
   }
}
int gaze_em(string str) {
  	if(!str) {
   	tell_object(TP,"Gaze into what?");
      return 1;
   }
  	if(str == "into mirror" || str == "gaze into the mirror"){
  		if(CRACKED == 1){
  			tell_object(TP,"%^CYAN%^The mirror is broken and currently "+
  				"not currently usable.");
  			return 1;
  		}
   	if((int)TP->query_stats("charisma")<8){
   		tell_room(TO,"%^CYAN%^The mirror trembles, shudders and then breaks "+
   			"when "+TPQCN+" gazes into it.",TP);
   		tell_object(TP,"%^CYAN%^You see your ugly face looking back you.  "+
   			"Suddenly you see the mirror tremble and shudder "+
   			"violently, then shatter.  Damn, how many years bad luck is that?");
			add_item("mirror","The mirror is affixed to the wall in the southwest part "+
				"of the room, but it is shattered and not currently usable.");
			CRACKED = 1;
   		return 1;
   	}
   	if((int)TP->query_stats("charisma")>16){
   		tell_room(TO,"%^CYAN%^"+TPQCN+" stares lovingly at "+TP->query_possessive()+" "+
   			"reflection for what seems to be too long a time.",TP);
   		tell_object(TP,"%^CYAN%^You stare into your reflection and can't "+
   			"help but want to continue staring at your lovely self.");
   		TP->set_paralyzed(random(5)+5,"%^BOLD%^%^CYAN%^What a lovely "+
   			"person you are, just look at that reflection!");
   		return 1;
   	}
		tell_room(TO,"%^CYAN%^"+TPQCN+" gazes into the mirror vainly "+
			"admiring "+TP->query_possessive()+" reflection.",TP);
		tell_object(TP,"%^CYAN%^You gaze into the mirror and see your "+
			"lovely reflection looking back at you. "+
			"%^MAGENTA%^**cough cough** %^CYAN%^Yeah right.");
   	return 1;
   }
}
int move_em(string str) {
   if(!str) {
   	tell_object(TP,"Unhang what?");
      return 1;
   }
  	if(str == "painting" || str == "painting 1" || str == "painting one"
  			|| str == "painting 2" || str == "painting two"
  			|| str == "painting 3" || str == "painting three"){
  		tell_object(TP,"You remove the painting from the wall.");
  		tell_room(TO,""+TPQCN+" removes a painting from the wall for some reason.",TP);
  		return 1;
  	}
  	if(str == "painting 4" || str == "painting four"){
  		if(member_array("southwest",TO->query_exits()) != -1) {
      	tell_object(TP,"The painting has already been moved!");
         return 1;
     	}
    	tell_object(TP,"You move the painting and reveal a concealed opening "+
     		"into another room.");
     	tell_room(TO,""+TPQCN+" moves a painting revealing an opening into "+
     		"another room.",TP);
      add_exit(SROOMS+"hall0","southwest");
		return 1;
	}
}
int replace_em(string str) {
	if(!str) {
   	tell_object(TP,"%^BOLD%^Replace what?");
      return 1;
   }
  	if(str == "painting" || str == "painting 1" || str == "painting one"
  			|| str == "painting 2" || str == "painting two"
  			|| str == "painting 3" || str == "painting three"){
  		tell_object(TP,"%^BOLD%^You re-hang the painting on the wall.");
  		tell_room(TO,"%^BOLD%^"+TPQCN+" re-hangs a painting on the wall.",TP);
  		return 1;
  	}
  	if(str == "painting" || str == "painting 4" || str == "painting four"){
     	tell_object(TP,"%^BOLD%^You replace the painting hiding the exit once more.");
     	tell_room(TO,"%^BOLD%^"+TPQCN+" replaces the painting hiding the exit once more.",TP);
     	remove_exit("southwest");
     	return 1;
   }
}
int open_em(string str) {
  	if(!str) {
   	tell_object(TP,"Open what?");
      return 1;
   }
  	if(str == "inner door"){
		tell_room(TO,"%^BOLD%^"+TPQCN+" tries to open the inner door and fails.",TP);
		tell_object(TP,"%^BOLD%^You try to open the inner door and fail.");
   	return 1;
   }
}
int push_em(string str) {
  	if(!str) {
        	tell_object(TP,"%^BOLD%^Push what?");
        	return 1;
    	}
  	if(str == "inner door"){
		tell_room(TO,"%^BOLD%^"+TPQCN+" pushes open the inner door.",TP);
		tell_object(TP,"%^BOLD%^You push open the door and see into the next room.");

    	set_open("inner door",1);
     	(SROOMS+"hallway")->set_open("inner door",1);

    	return 1;
	}
}
