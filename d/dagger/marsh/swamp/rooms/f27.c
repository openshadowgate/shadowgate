#include <std.h>
#include "../marsh.h"

inherit FINH;

void create() 
{
    ::create();

    set_exits((["west"      : RPATH "f23",
	            "northeast" : RPATH "f28",
      ]));
}
