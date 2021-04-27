//file 

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("incense holder");
    set_id(({"item","incense holder","holder","%^CYAN%^Incense%^RESET%^ Holder%^RESET%^",}));
    set_short("%^CYAN%^Incense%^RESET%^ Holder%^RESET%^");
    set_long(
@ITEM
This is a small %^YELLOW%^copper%^RESET%^ dish set into a block of white %^BOLD%^%^BLACK%^marble%^RESET%^ and filled with sand. It appears to not have saw much use as the scent of nature fills the grove and it seems almost sacrilegious to bring any other scent into it, but perhaps there are times when it is needed.%^RESET%^
ITEM
        );
    set_weight(450);
    set_value(0);
    set("read","");
}