#include <std.h>
#include "../marsh.h"

inherit FINH;

void create() 
{
    ::create();
    set_exits((["southeast": RPATH "f5",
	            "west": RPATH "f7",
      ]));
}
