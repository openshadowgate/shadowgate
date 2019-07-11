// shaundakul: travel domain, faithful mount. Nienne, 05/07.
#include <std.h>
inherit "/d/magic/mon/mounts/travelinherit.c";

void create(){
    ::create();
    set_name("gray stallion");
    set_short("%^BOLD%^%^BLACK%^A tall gray stallion%^RESET%^");
    set_id( ({"horse","stallion","gray stallion","tall stallion","faithful mount"}) );
    set_long("%^MAGENTA%^This stallion stands proud and tall, and is well "
"groomed and tended. Its hue is a %^RESET%^dusky gray %^MAGENTA%^shade, short "
"and glossy, and is accentuated by the horse's %^BOLD%^%^BLACK%^ebony "
"%^RESET%^%^MAGENTA%^mane, tail and hooves which strike an elegant match with "
"the %^RESET%^lighter coat%^MAGENTA%^. A fine bridle and saddle of %^BOLD%^"
"%^BLACK%^tanned black leather %^RESET%^%^MAGENTA%^mark it as a tame beast, "
"and the saddle has been embossed in %^BOLD%^%^WHITE%^si%^RESET%^lv%^BOLD%^er "
"%^RESET%^%^MAGENTA%^with the design of an upright hand.%^RESET%^");
    set_gender("male");
    set_enter_room("rides in on a tall stallion.");
    set_exit_room("leaves riding a tall stallion.");
    set_vehicle_short("%^BOLD%^%^BLACK%^A tall gray stallion%^RESET%^");
}
