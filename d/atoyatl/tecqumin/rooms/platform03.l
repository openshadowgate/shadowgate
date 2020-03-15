#include "../tecqumin.h"

inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "northwest" : ROOMS + "platform02",
                       "south" : ROOMS + "platform04"]) );
}
