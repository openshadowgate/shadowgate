#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_6,5",
        "east"      :DES+"desert_7,6",
        "south"     :DES+"desert_8,5",
        "west"      :DES+"desert_7,4"
             ]));
}