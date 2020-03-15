#include "../tecqumin.h"
inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "southeast" : ROOMS + "platform06",
                       "north" : ROOMS + "platform08"]) );
}
