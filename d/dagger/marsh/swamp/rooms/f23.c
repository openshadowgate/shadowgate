#include <std.h>
#include "../marsh.h"

inherit FINH;

void create() 
{
    ::create();
    set_exits((["northwest" : RPATH "f14",
	            "east"      : RPATH "f27",
	            "southeast" : RPATH "f24",
      ]));
}
