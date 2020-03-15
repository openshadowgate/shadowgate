#include "../tecqumin.h"

inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "platform01",
                       "southeast" : ROOMS + "platform03"]) );
}

