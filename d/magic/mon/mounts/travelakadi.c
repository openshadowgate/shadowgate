// akadi: travel domain, faithful mount. Nienne, 05/07.
#include <std.h>
inherit "/d/magic/mon/mounts/travelinherit.c";

void create(){
    ::create();
    set_name("gray mare");
    set_short("%^BOLD%^%^BLACK%^A da%^RESET%^%^WHITE%^p%^BOLD%^%^BLACK%^pled gray mare%^RESET%^");
    set_id( ({"horse","mare","gray mare","dappled mare","faithful mount"}) );
    set_long("%^CYAN%^A well-tended beast, this mare displays an energetic "
"and vigorous temperament. Its coat carries a unique dappled effect over "
"its base %^RESET%^gray color%^CYAN%^, leaving flecks of varied %^BOLD%^"
"%^BLACK%^darker gray %^RESET%^%^CYAN%^and %^BOLD%^%^WHITE%^lighter white "
"%^RESET%^%^CYAN%^shades throughout. A %^RESET%^dull white %^CYAN%^mane and "
"tail flow free to the winds as it tosses its head. No bridle restrains the "
"creature - it merely carries a primitive saddle across its back, resting "
"across a %^BOLD%^%^BLUE%^cobalt-blue mat %^RESET%^%^CYAN%^that is edged with "
"images of %^BOLD%^%^WHITE%^tiny clouds%^RESET%^%^CYAN%^.%^RESET%^");
    set_gender("male");
    set_enter_room("rides in on a gray mare.");
    set_exit_room("leaves riding a gray mare.");
    set_vehicle_short("%^BOLD%^%^BLACK%^A da%^RESET%^%^WHITE%^p%^BOLD%^%^BLACK%^pled gray mare%^RESET%^");
}
