//Coded by Diego//
//Updated by Circe 1/29/04

#include <std.h>
#include "../lusell.h"
inherit VAULT;

void create(){
   ::create();
   set_name("yard3");
	set_short("courtyard");
	set_long(
		"The courtyard is paved in cobblestone and is very large.  "+
		"To the north you see the entry to the keep, the west a "+
		"stable and to the east a practice yard.  To the south you "+
		"see the portcullis that leads over the drawbridge and back "+
		"to Tonovi.  In the center of this part of the courtyard is a "+
		"%^CYAN%^fountain%^RESET%^.\n"
    	);
	set_property("indoors",0);
	set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_smell("default","Fresh smells of the outdoors are here "+
		"mixed with the smell of the stables.");
	set_listen("default","You can hear horses stir in the stables "+
		"and the sounds of guards moving about.");
	set_items(([
		({"walls","wall"}) : "The walls are made of sturdy stone and "+
			"have narrow slits through which archers can fire down on "+
			"the enemy without exposing themselves greatly.\n",
		"floor" : "The floor cobblestone and is kept free of dirt and "+
			"debris even though you know the horses are working toward "+
			"the other aim.\n",
		"fountain" : "%^RESET%^The fountain has been formed into the shape "+
                  "of a %^BOLD%^%^YELLOW%^to%^RED%^r%^YELLOW%^ch %^RESET%^from "+
                  "some recently cooled %^BOLD%^%^BLACK%^lava%^RESET%^.  The "+
                  "%^BLUE%^wa%^BOLD%^%^BLUE%^t%^RESET%^%^BLUE%^er %^RESET%^that "+
                  "spews forth is fairly %^RED%^warm %^RESET%^and, combined with "+
                  "the elements found in the %^BOLD%^%^BLACK%^lava%^RESET%^, looks "+
                  "like an %^BOLD%^%^RED%^eternal %^YELLOW%^fl%^RED%^a%^YELLOW%^me"+
                  "%^RESET%^.  Surrounding the fountain is a small %^GREEN%^garden.",
		"garden" : "%^RESET%^The garden has lovely %^BOLD%^%^MAGENTA%^flowers "+
                  "%^RESET%^and very green %^BOLD%^%^GREEN%^grass%^RESET%^.  When "+
                  "you look closer you notice that the %^BOLD%^%^MAGENTA%^flowers "+
                  "%^RESET%^are all dark in colors: %^BOLD%^%^BLACK%^black%^RESET%^, "+
                  "%^BOLD%^%^BLACK%^gray%^RESET%^, %^RED%^dark red%^RESET%^,and "+
                  "%^MAGENTA%^purple%^RESET%^."
   ]));
  	set_exits(([
   	"south" : LROOMS+"yard1",
		"west" : LROOMS+"yard2",
		"east" : LROOMS+"yard4",
		"north" : LROOMS+"entry"
	]));
}
