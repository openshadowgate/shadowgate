//Coded by Diego//
//Updated by Circe 1/29/04
//Updated again by Circe 8/29/04

#include <std.h>
#include "../lusell.h"

inherit VAULT;

void create(){
   ::create();
	set_property("indoors",1);
	set_property("light",2);
      set_terrain(STONE_BUILDING);
      set_travel(PAVED_ROAD);
      set_name("sanctuary");
	set_short("sanctuary");
	set_long(
         "%^GREEN%^This alcove is immaculate in its appearance.  "+
         "There is no dust, no %^ORANGE%^dirt%^GREEN%^, no thing "+
         "out of place.  There is an altar on which rests a "+
         "%^RESET%^silver %^BOLD%^%^WHITE%^chalice%^RESET%^%^GREEN%^.  "+
         "It is filled with a liquid that glows %^BOLD%^%^GREEN%^green"+
         "%^RESET%^%^GREEN%^.  In front, there is a small padded "+
         "%^ORANGE%^kneeler %^GREEN%^for prayer.  A %^MAGENTA%^"+
         "tapestry %^GREEN%^fills the wall behind the altar.%^RESET%^\n"
      );
      set_items(([
         "altar" : "%^GREEN%^The altar is made from a solid piece of "+
            "%^BOLD%^%^BLACK%^onyx %^RESET%^%^GREEN%^and is magnificent. "+
            "Its surfaces have been worked by a professional but are not "+
            "smooth.  Fine lines and religious symbols relating to Bane "+
            "have been scripted throughout, filled with a %^BOLD%^"+
            "%^GREEN%^tinted %^RESET%^%^GREEN%^adamantium material.  "+
            "On the priest side has been carved a very small alcove "+
            "which holds a %^BOLD%^%^YELLOW%^ca%^GREEN%^n%^YELLOW%^dle"+
            "%^RESET%^%^GREEN%^.  There is a very small hole drilled "+
            "into the back of the alcove which leads to a dozen places "+
            "all over the altar.  When a candle has been lit, the room "+
            "gets bathed in an ominous but soothing %^BOLD%^%^GREEN%^li"+
            "%^YELLOW%^g%^GREEN%^ht%^RESET%^%^GREEN%^.  A %^BOLD%^"+
            "%^GREEN%^fist %^RESET%^%^GREEN%^holding a %^BOLD%^"+
            "%^GREEN%^lightning bolt %^RESET%^%^GREEN%^has been "+
            "jeweled into the front with raw, beautiful emeralds.  "+
            "On the top of the altar is drawn an outline of a %^BOLD%^"+
            "%^MAGENTA%^body %^RESET%^%^GREEN%^in cooled wax and "+
            "paraffin.  A %^BOLD%^%^YELLOW%^plaque %^RESET%^%^GREEN%^"+
            "adorns the very bottom and reads %^BOLD%^%^GREEN%^'"+
            "%^BLACK%^Fear Always the Black Hand!%^GREEN%^'%^RESET%^",
         ({"chalice","silver chalice"}) : "This %^BOLD%^%^WHITE%^silver "+
            "chalice %^RESET%^is plain but brilliant in its presence.  "+
            "It is filled with an unknown liquid that %^BOLD%^%^GREEN%^"+
            "glows %^RESET%^green.",
         "tapestry" : "%^GREEN%^This large tapestry fills the wall "+
            "behind the altar.  It depicts a very large %^BOLD%^"+
            "%^BLACK%^being %^RESET%^%^GREEN%^towering over a globe, "+
            "his arms spread wide.  In the palms of both hands are "+
            "green bolts of %^BOLD%^%^GREEN%^lightning %^RESET%^"+
            "%^GREEN%^and they appear aimed at the globe.  An almost "+
            "unnoticeable sneer is on the lips of the %^BOLD%^%^BLACK%^"+
            "being%^RESET%^%^GREEN%^.%^RESET%^"
      ]));
	set_smell("default","The room smells clean and sterile.");
	set_listen("default","The room is deafeningly silent.");
  	set_exits(([
		"east" : LROOMS+"hall3"
	]));
}
