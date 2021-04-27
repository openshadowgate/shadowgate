#include <std.h>
inherit OBJECT;

void create(){
        ::create();
        set_name("stone");
        set_id(({"stone","rock","marbled stone"}));
        set_short("%^BOLD%^%^BLACK%^a ma%^CYAN%^r%^BLACK%^bled "
"st%^MAGENTA%^o%^BLACK%^ne%^RESET%^");
        set_long("This little stone is smooth to the touch and about the size "
"of a child's fist. %^BOLD%^%^BLACK%^Dark %^RESET%^in color, its surface is "
"striated by veins of %^BOLD%^%^WHITE%^gli%^CYAN%^t%^WHITE%^ter%^MAGENTA%^"
"i%^WHITE%^ng %^RESET%^gemstone that give a rather pretty appearance to the "
"otherwise %^ORANGE%^mundane %^RESET%^stone.\n");
        set_value(5);
        set_weight(1);
        set_lore("Nothing particularly remarkable about the stone itself - it is merely a piece of rock striated with traces of quartz. Not particularly valuable, but pretty.");
        set_property("lore difficulty",1);
}
