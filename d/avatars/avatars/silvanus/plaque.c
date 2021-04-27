//file 

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("Plaque");
    set_id(({"item","Plaque","plaque","%^YELLOW%^Plaque%^RESET%^",}));
    set_short("%^YELLOW%^Plaque%^RESET%^");
    set_long(
@ITEM
%^YELLOW%^This is a sheat of copper metal that is tinged slightly %^RESET%^%^GREEN%^green%^YELLOW%^ and appears to almost be %^RESET%^%^CYAN%^alive%^YELLOW%^. It seems a larger form of the small holy symbols that the members of %^RESET%^%^GREEN%^Silvanus'%^YELLOW%^ clergy carry. There is a dark %^RESET%^%^GREEN%^green%^YELLOW%^ writing etched across its surface, serving as the charge %^RESET%^%^GREEN%^silvanus%^YELLOW%^ holds his followers to. Perhaps you can read it.%^RESET%^
ITEM
        );
    set_weight(500);
    set_value(0);
    set("read","");
}