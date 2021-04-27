//file 

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("statue");
    set_id(({"item","statue","item statue","%^RED%^Crimson Statue%^RESET%^",}));
    set_short("%^RED%^Crimson Statue%^RESET%^");
    set_long(
@ITEM
%^RED%^This is a simple red crimson statue... just serving as a test subject for silvanus..%^RESET%^
ITEM
        );
    set_weight(500);
    set_value(1000);
    set("read","");
}