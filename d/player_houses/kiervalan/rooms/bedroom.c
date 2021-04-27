#include <std.h>
#include "../kier.h"
inherit VAULT;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("A Bedroom");
   set_short("%^RESET%^%^ORANGE%^A Bedroom%^RESET%^");
   set_long("%^CYAN%^The stairs continue up and down, and you stand in what "
"looks like a bedroom. The walls are devoid of any decoration, instead small "
"windows sit at regular intervals along the bare stone walls. A large bed "
"sits on one side of the room, as well as a fireplace, a couch, a table, and "
"a small bookcase. The south wall is is set in, obviously there is another "
"room there. A small door is set in the wall.%^RESET%^");
   set_smell("default","The fresh smell of the sea drifts through the room.");
   set_listen("default","You can hear the sound of crashing waves on the "
"beach below and the crackling fire.");

   set_items(([
     ({"bed"}) : "%^ORANGE%^This is a large bed, made of stout oak. The "
"headboard is carved with a relief of trees and animals. A heavy quilt in "
"%^GREEN%^gr%^BOLD%^e%^GREEN%^en%^BOLD%^s%^RESET%^%^ORANGE%^ and "
"%^BLUE%^bl%^BOLD%^u%^RESET%^%^BLUE%^es%^ORANGE%^ covers the bed and four "
"%^RESET%^%^BOLD%^large pillows%^RESET%^%^ORANGE%^ sit at the head. It doesnt "
"look like the bed is used very often at all.%^RESET%^",
     ({"windows"}) : "%^ORANGE%^These small windows are open, and look out on "
"the beach and sea below. You can see the coastal city of Torm to the north, "
"a small temple nestled in the mountains to the west, and the seemingly never "
"ending sea to the east.%^RESET%^",
     ({"fireplace"}) : "%^BLACK%^%^BOLD%^Formed out of the same stone as the "
"tower walls, this fireplace is faces the bed. A small "
"%^RED%^%^BOLD%^f%^RESET%^%^RED%^i%^YELLOW%^r%^ORANGE%^e "
"%^BLACK%^%^BOLD%^burns, basking the room in a %^YELLOW%^golden "
"light%^BLACK%^%^BOLD%^.%^RESET%^",
     ({"couch"}) : "%^RED%^This is a very comfortable looking couch. It could "
"easily sit four people, and is wide enough so that someone could sleep on "
"it. A %^RESET%^%^BOLD%^pillow%^RESET%^%^RED%^ like the ones from the bed and "
"a %^ORANGE%^soft wool blanket%^RESET%^%^RED%^ are placed on the couch, as if "
"waiting for someone.%^RESET%^",
     ({"table"}) : "%^ORANGE%^This simple table sitting in front of the "
"couch. Several sheets of parchment sit on the table, sketches of armor "
"designs.%^RESET%^",
     ({"stairs"}) : "%^BLACK%^%^BOLD%^Formed out of black wrought iron, these "
"stairs spiral upwards to the next floor of the tower and back down again. "
"The handrail is formed into a shooting star, and the railings are filled "
"with designs of "
"%^RESET%^%^BOLD%^m%^RESET%^o%^BOLD%^o%^RESET%^ns%^BLACK%^%^BOLD%^ and "
"%^RESET%^%^BOLD%^st%^CYAN%^a%^RESET%^r%^BOLD%^s%^BLACK%^%^BOLD%^. The stairs "
"are a work of beauty.%^RESET%^",
   ]));

   set_exits(([
     "up" : ROOMS+"rooftop",
     "down" : ROOMS+"lobby",
     "south" : ROOMS+"bathroom",
   ]));
   set_door("door",ROOMS+"bathroom","south",0);
}
