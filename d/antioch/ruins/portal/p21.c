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
   " The ridge turns to the southeast here, and you can see that it"+
   " turns again to the southwest after a little ways. There is also a"+
   " path to the north that quickly turns to the northeast."
   );
   set_exits(([
   "north" : PORTAL+"p20",
   "southeast" : PORTAL+"p22",
   ]));
}
