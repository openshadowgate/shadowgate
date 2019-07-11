// selune: travel domain, faithful mount. Nienne, 05/07.
#include <std.h>
inherit "/d/magic/mon/mounts/travelinherit.c";

void create(){
    ::create();
    set_name("gray mare");
    set_short("%^BOLD%^%^BLACK%^A gentle gray mare%^RESET%^");
    set_id( ({"horse","mare","gray mare","gentle mare","gentle gray mare","faithful mount"}) );
    set_long("%^ORANGE%^This mare is covered by a short coat of a pale "
"%^BOLD%^%^BLACK%^gray hue%^RESET%^%^ORANGE%^, with a glossy sheen that makes "
"it seem almost %^RESET%^si%^BOLD%^lve%^RESET%^ry %^ORANGE%^in places. She "
"looks gentle and rather docile, and has a %^RESET%^white star %^ORANGE%^"
"marked above her soft eyes. Her pale %^RESET%^si%^BOLD%^%^BLACK%^l%^RESET%^"
"ver-gr%^BOLD%^%^BLACK%^a%^RESET%^y %^ORANGE%^mane and tail hang loose, and "
"her hooves are carefully tended. A simple bridle and saddle of "
"%^BOLD%^%^BLACK%^jet-black leather %^RESET%^%^ORANGE%^mark her as a trained "
"beast, the latter of which is marked all around the edges with little "
"%^BOLD%^%^WHITE%^gl%^CYAN%^i%^WHITE%^tte%^CYAN%^r%^WHITE%^ing "
"%^RESET%^%^ORANGE%^stars.%^RESET%^");
    set_gender("female");
    set_enter_room("rides in on a gentle mare.");
    set_exit_room("leaves riding a gentle mare.");
    set_vehicle_short("%^BOLD%^%^BLACK%^A gentle gray mare%^RESET%^");
}
