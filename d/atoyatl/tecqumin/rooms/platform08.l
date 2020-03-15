#include "../tecqumin.h"
inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "platform07",
                       "northeast" : ROOMS + "platform01"]) );
}
