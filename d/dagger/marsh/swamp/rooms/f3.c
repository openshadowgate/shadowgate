#include <std.h>
#include "../marsh.h"

inherit FINH;

void create() 
{
    ::create();
    set_exits((["east"      : RPATH "f2",
	            "southwest" : RPATH "f4",
      ]));
}
