#include <std.h>
#include "../ruins.h"
inherit PLANE;

void create()
{
   ::create();
   set_long(
   "%^RED%^The sky is a dull red color and smoke hangs in the air,"+
   " preventing you from seeing too far in any direction. The air is hot"+
   " and humid, the ground beneath your feet is scorched and baked."+
   " The slender ridge you're on leads to the northwest, curving in the"+
   " near distance, but the trail becomes lost in the ever-present haze."+
   " Southeast you can see the ridge turns to the south and a section"+
   " branches off to the northeast as well."
   );
   set_exits(([
   "northwest" : PORTAL+"p5",
   "southeast" : PORTAL+"p3",
   ]));
}
