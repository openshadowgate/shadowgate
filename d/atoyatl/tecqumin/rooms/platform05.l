#include "../tecqumin.h"
inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "northeast" : ROOMS + "platform04",
                       "west" : ROOMS + "platform06"]) );
}
