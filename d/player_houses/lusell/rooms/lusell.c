//Coded by Diego//

#include <std.h>
#include "../lusell.h"

inherit VAULT;

void create(){
   ::create();
   set_name("lusell");
	set_short("mistress' bedroom");
	set_long(
    	"%^RESET%^%^CYAN%^"+
		"The room is large and extravagantly adorned.  Against the "+
		"middle of the east wall you see a %^BOLD%^%^CYAN%^huge canopied "+
		"bed%^RESET%^%^CYAN%^.  In the northwest corner of the room you "+
		"find a %^RESET%^%^RED%^large fireplace%^CYAN%^, "+
		"about the floor in front of the %^RESET%^%^RED%^fireplace "+
		"%^CYAN%^you find many %^RESET%^%^ORANGE%^animal "+
		"skins%^CYAN%^.  In the southern portion of the room "+
		"you find a desk and chair.  The walls are covered with "+
		"tapestries, paintings, and animal heads showing that the "+
		"occupant of this room must be well travelled.  The floor "+
		"is covered in a %^BOLD%^%^RED%^soft red carpet %^RESET%^%^CYAN%^that cushions "+
		"your step comfortably.  Next to the bed you find a reinforced "+
		"rack used for hanging garments and armor.  On the other side of "+
		"the bed is a large table with a mirror and next to that a dresser.\n"+
		"%^RESET%^"
   );
	set_property("indoors",1);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","The room smells of perfume and weapon oil.");
	set_listen("default","The room is very quiet.");
	set_items(([
		"bed" : "The bed is huge, seems almost as large as a parade "+
			"ground.  The canopy is made of a lavender silk and is tied "+
			"back to each post with a silk sash of the same color.  The "+
			"bed itself is soft and luxurious, covered in a crimson satin "+
			"cover and cream colored satin sheets.  The pillows are "+
			"overstuffed and filled with only the best goose down.\n",
		"fireplace" : "The fireplace is large and would provide warmth "+
			"to this room on a cold night.  Fireplace tools are in a can "+
			"near the firepit and the animal skins are arranged in such a "+
			"way that one could lie upon them and luxuriate in the warmth "+
			"and glow of the fire.\n",
		({"animal skins","skins","animal skin","skin"}) : "The skins are "+
			"varied and colorful.  Some of the skins appear to be from rare "+
			"creatures and some come from the more common.  The only thing the "+
			"skins have in common is that they are all soft and comfortable "+
			"to the touch.\n",
		({"tapestries","tapestry","paintings","painting"}) : "The tapestries "+
			"and paintings are rich and colorful and have been cared for over "+
			"the years so that they retain their beauty and their color.  The "+
			"only thing that stands out about these items are the beauty and "+
			"history they represent.  The southern tapestry seems to be depicting "+
			"a scene where the others are brightly colored patterns.\n",
		"southern tapestry" : "This tapestry is finely woven and appears to be "+
			"freshly made.  It is depicting a battle scene between a knight "+
			"clad in dark armor and an elf wielding a longbow.  The elf is on "+
			"the ground begging for his life.  The knight is female and has "+
			"her lance tip poised  at the elf's left eye.  You also notice "+
			"that his right eye is missing and in its place is a golden orb.\n",
		({"animal heads","animal head","heads","head"}) : "Obvious trophies "+
			"from hunts you see many large and dangerous animals represented "+
			"here.  You see a lion, unicorn, rhinocerous and even a white dragon "+
			"represented here.\n",
		({"desk","chair"}) : "The desk and chair are made from mahogany and "+
			"are of the finest workmanship.  The chair is padded with a red "+
			"velvet pillow.  The desktop is orderly and neat and has items "+
			"available for penning notes and letters.\n",
		"dresser" : "The dresser is made of fine  mahogany and has several "+
			"drawers, but nothing remarkable is found upon a search.\n",
		"table" : "The table is a dressing table and has a ewer with clean "+
			"water and a basin sitting atop it.  Under the basin is a neatly "+
			"folded towel.  Before the table is a small stool so that one may "+
			"look at ones reflection while getting ready for the day.\n"
   ]));

  	set_search("heads","Which animal head do you with to search?");
  	set_search("animal head","Which animal head do you with to search?");
  	set_search("animal heads","Which animal head do you with to search?");
  	set_search("animal's head","Which animal head do you with to search?");
  	set_search("lion's head","You see nothing peciliar about this head.");
  	set_search("unicorn's head","You see nothing peciliar about this head.");
  	set_search("rhinocerous' head","You see nothing peciliar about this head.");
  	set_search("dragon's head","The head is enormous and is mounted on "+
  		"the wall in the northeast corner of the room.  The White scales "+
            "on its face glisten like fresh snow and its ivory teeth look deedly and sharp.");
  	set_search("white dragon's head","The head is enormous and is mounted on "+
  		"the wall in the northeast corner of the room.  The White scales "+
  		"on its face glisten like fresh snow and its ivory teeth look deadly and sharp.");
  	set_search("teeth","The teeth look deadly and sharp.  One tooth way back "+
  		"in the mouth looks to be a bit discolored.");
  	set_search("tooth","The tooth looks discolored from being touched, "+
  		"maybe even pressed.");

  	set_exits(([
		"west" : LROOMS+"hall4"
	]));

  	set_door("ornate door",LROOMS+"hall4","west","ruby key");
   set_door_description("ornate door","This door is made from a single "+
   	"piece of mahogony and is lacquered an inlaid with ivory, gold, and rubies.\n");
   set_string("ornate door","open","The door opens into a large hallway.\n");

	if(random(2)){
		switch(random(1)){
			case (0):
  				"daemon/place_d"->place_in(LROOMS,new(LMON+"sergeant"));
  				break;
  			case (1):
  				"daemon/place_d"->place_in(LROOMS,new(LMON+"corporal"));
  				break;
  			default :
  				"daemon/place_d"->place_in(LROOMS,new(LMON+"corporal"));
  				break;
  		}
  	}				
}
void init() {
  ::init();
  add_action("press_em","press");
  add_action("request_em","sift");
}
int request_em(string str) {
	if(!str) {
   	tell_object(TP,"%^BOLD%^Sift what?");
      return 1;
  	}
  	if(str == "fireplace ash" || str == "through fireplace ash" ||
  		str == "ash" || str == "through ash"){
     	tell_object(TP,"You sift through the ash and find an emerald clasp.\n");
     	tell_room(ETP,""+TPQCN+" digs around in the ash of the fireplace.\n",TP);
		new(LOBJ+"ruby_clasp")->move(TO);
      return 1;
   }
}
int press_em(string str) {
	if(!str) {
   	tell_object(TP,"Press what?");
      return 1;
  	}
  	if(str == "tooth"){
   	if(member_array("down",TO->query_exits()) != -1) {
     		tell_object(TP,"You press the dragon tooth until you hear a click!\n"+
     			"A portion of the floor in the northwest corner of the room "+
     			"slides closed.\n");
     		tell_room(ETP,""+TPQCN+" puts "+TP->query_possessive()+" hand in the "+
     			"dragon's mouth and a portion of the floor in the northwest "+
     			"corner of the room slides closed.\n",TP);
     		remove_exit("down");
			tell_room((LROOMS+"dungeon"),"%^BOLD%^A portion of the ceiling slides closed.");
     		(LROOMS+"dungeon")->remove_exit("up");
         return 1;
      }
     	tell_object(TP,"You press the dragon tooth until you hear a click!\n"+
     		"A portion of the floor in the northwest corner of the room slides open.\n");
     	tell_room(ETP,""+TPQCN+" puts "+TP->query_possessive()+" hand in the dragon's "+
     		"mouth and a portion of the floor in the northwest corner of the "+
     		"room slides open.\n",TP);
     	add_exit(LROOMS+"dungeon","down");
		tell_room((LROOMS+"dungeon"),"%^BOLD%^A portion of the ceiling slides open.");
     	(LROOMS+"dungeon")->add_exit(LROOMS+"lusell","up");
     	return 1;
	}
}
