// tempus: travel domain, faithful mount. Nienne, 05/07.
#include <std.h>
inherit "/d/magic/mon/mounts/travelinherit.c";

void create(){
    ::create();
    set_name("chestnut stallion");
    set_short("%^RESET%^%^RED%^A proud chestnut stallion%^RESET%^");
    set_id( ({"horse","stallion","chestnut stallion","proud stallion","faithful mount"}) );
    set_long("%^RESET%^%^ORANGE%^This noble beast has the appearance of being "
"well bred and trained. Its %^RED%^chestnut coat %^ORANGE%^is cut short and "
"well groomed, as is its mane, which rises in a short ridge along its neck, "
"at a little over two inches high. Its tail flows smoothly from its powerful "
"rump, and its %^BOLD%^%^BLACK%^ebon hooves %^RESET%^%^ORANGE%^are well "
"polished. The bridle and saddle upon its back mark it further as a trained "
"beast, the latter of which is emblazoned with the symbol of a %^BOLD%^"
"%^WHITE%^blazing silver sword %^RESET%^%^ORANGE%^on a %^BOLD%^%^RED%^blood-"
"red shield%^RESET%^%^ORANGE%^.%^RESET%^");
    set_gender("male");
    set_enter_room("rides in on a proud stallion.");
    set_exit_room("leaves riding a proud stallion.");
    set_vehicle_short("%^RESET%^%^RED%^A proud chestnut stallion%^RESET%^");
}