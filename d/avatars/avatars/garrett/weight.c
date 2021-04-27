//file 

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("weight");
    set_id(({"item","weight","weight","weight, 777 pounds",}));
    set_short("weight, 777 pounds");
    set_long(
@ITEM
777 pounds of weight.
ITEM
        );
    set_weight(777);
    set_value(0);
    set("read","");
}