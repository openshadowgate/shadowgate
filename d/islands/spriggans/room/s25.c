//Shore around the island Leilani ~Circe~ 5/26/07
#include <std.h>
#include "../spriggan.h"
inherit SBEACH;

void create(){
   ::create();
   set_exits(([
      "northeast" : PATHEXIT"s24",
      "south" : PATHEXIT"s26"
   ]));
}
