#include <std.h>
#include "../inherits/area_stuff.h"
#include "../inherits/door_stuff.h"
inherit HHROOM;

void create() 
{
    sexit = "south";
    dest = FFROOMS+"iw15";
    ::create();
}
