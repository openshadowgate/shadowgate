#include <std.h>
#include "../defs.h"
inherit INH+"street";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^City street%^RESET%^\n"
"%^BLUE%^This large street is obviously a major thoroughfare, part of the one that circuits the city's outer limits.  "
"Smooth %^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^e %^BLUE%^forms the ground "
"beneath your feet, allowing for ease in walking.  Only %^MAGENTA%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^MAGENTA%^kn%^BOLD%^"
"%^BLACK%^es%^RESET%^%^MAGENTA%^s%^BLUE%^ fills the air above you, the ceiling too high up to be seen by any form of "
"normal vision.  At short intervals along the length of the street are slender carved posts of %^BLACK%^%^BOLD%^ob"
"%^RESET%^si%^BOLD%^%^BLACK%^dian%^RESET%^%^BLUE%^, each supporting a globe of pale %^MAGENTA%^fae%^BOLD%^r%^RESET%^"
"%^MAGENTA%^ie fire%^BLUE%^ that sheds faint light around it.  Rising up on the eastern side of the road are the walls of "
"the cavern, dotted with the occasional mid- or lower-class drow house carved into the dull surface of the rock itself.  "
"Before these, right at the road's edge, stands a small, %^CYAN%^de%^GREEN%^l%^CYAN%^i%^GREEN%^ca%^CYAN%^te %^BLUE%^"
"building with an open door.  The road continues north through what must be the upper-class section of the city, while "
"further south it intersects with another street.%^RESET%^\n");

   add_item(({"houses","buildings","building"}),"%^BLUE%^Upon the western side of the road rise the buildings of the upper-class.  "
"The closest one obviously belong to very high-ranked house, by its sheer size alone.  It is a grand enclosure with high "
"stone walls allows no ability to see within, although you can often hear shouts of %^RED%^c%^BOLD%^o%^RESET%^%^RED%^mbat "
"%^BLUE%^floating above the wall.  Opposite the enclosure stands a small, delicate building that %^BOLD%^%^WHITE%^g"
"%^BOLD%^%^MAGENTA%^l%^BOLD%^%^WHITE%^e%^BOLD%^%^CYAN%^a%^BOLD%^%^GREEN%^m%^BOLD%^%^WHITE%^s %^RESET%^%^BLUE%^with arcane "
"lighting.%^RESET%^");
   add_item(({"wall","walls"}),"%^BLUE%^The eastern side of the road is bordered by the walls of the cavern, which rise "
"up and disappear into the %^MAGENTA%^da%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^ke%^BOLD%^%^BLACK%^ne%^RESET%^%^MAGENTA%^d "
"%^BLUE%^limits of your vision above.  The occasional signs of a mid- or lower-class drow house are dotted across its "
"stony surface, carved into the face of the rock itself.  If anything, there seem far more living spaces situated within "
"this vast cavern's walls than upon its floor, sign perhaps that only the most prestigious of lineages are afforded the "
"central space.%^RESET%^");
   set_exits(([
     "north":ROOMS"outer23",
     "south":ROOMS"outer21",
     "east":ROOMS"arcanist",
   ]));
}