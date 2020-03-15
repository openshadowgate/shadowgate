#include "../tecqumin.h"

inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "platform05",
                       "northwest" : ROOMS + "platform07"]) );
}
