#include <std.h>
inherit "/d/common/obj/misc/pipe";

void create() {
    ::create();
    set_name("pipe");
    set_id( ({"pipe","slender pipe","long pipe","long slender pipe",}) );
    set_short("%^RESET%^%^ORANGE%^long %^BOLD%^%^BLACK%^slender %^RESET%^%^ORANGE%^pipe%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Carved from ebony wood, this long, %^RESET%^%^ORANGE%^slender %^BOLD%^%^BLACK%^smoking "
"pipe has a small bowl at one end that can be packed with tobacco. The rim of the bowl is etched in %^RESET%^s%^BOLD%^i"
"%^BLACK%^lv%^WHITE%^e%^RESET%^r %^BOLD%^%^BLACK%^so that the fine wood is not marred by flame. Not quite a foot in "
"length, the pipe is plain but elegant, and its mouthpiece is made from %^RESET%^sh%^BOLD%^ini%^RESET%^ng %^BOLD%^si"
"%^RESET%^lv%^BOLD%^er%^BLACK%^.%^RESET%^");
    set_value(150);
}
