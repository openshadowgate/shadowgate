#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFO;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^RESET%^%^GREEN%^The road continues to the north and south.%^RESET%^");
    set_exits( ([ "north" : FFOR"12", "south" : FFOR"10"]) );
}
