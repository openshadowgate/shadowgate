#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit LAKEBASE;

void create() {
  ::create();
  set_exits( ([  "west" : ROOMS + "lake09",
                 "northeast" : ROOMS + "lake07" ]) );
}
