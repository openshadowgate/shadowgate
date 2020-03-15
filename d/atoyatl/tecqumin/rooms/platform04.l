#include "../tecqumin.h"

inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "platform03",
                       "southwest" : ROOMS + "platform05"]) );
}
