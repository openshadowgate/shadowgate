// tymora: travel domain, faithful mount. Nienne, 05/07.
#include <std.h>
inherit "/d/magic/mon/mounts/travelinherit.c";

void create(){
    ::create();
    set_name("golden-brown mare");
    set_short("%^RESET%^%^ORANGE%^A gol%^YELLOW%^d%^RESET%^%^ORANGE%^"
"en-brown mare%^RESET%^");
    set_id( ({"horse","mare","brown mare","golden-brown mare","golden brown mare","faithful mount"}) );
    set_long("%^CYAN%^A short, glossy %^ORANGE%^gol%^YELLOW%^d%^RESET%^"
"%^ORANGE%^en-brown %^RESET%^%^CYAN%^coat covers the muscled form of the mare "
"before you, obviously both well bred and well tended. She carries herself "
"well, with long %^WHITE%^ash-white %^CYAN%^hair and tail, and a matching "
"%^WHITE%^white blaze %^CYAN%^that runs down her nose. A bridle traced in "
"%^BOLD%^%^BLUE%^blue %^RESET%^%^CYAN%^and %^BOLD%^%^WHITE%^silver "
"%^RESET%^%^CYAN%^matches with the %^BOLD%^%^BLUE%^cobalt-blue %^RESET%^"
"%^CYAN%^saddle that rests over her back, marked at each corner with a "
"%^BOLD%^%^WHITE%^sil%^RESET%^ve%^BOLD%^%^WHITE%^ry shamrock%^RESET%^"
"%^CYAN%^.%^RESET%^");
    set_gender("female");
    set_enter_room("rides in on a gentle mare.");
    set_exit_room("leaves riding a gentle mare.");
    set_vehicle_short("%^RESET%^%^ORANGE%^A gol%^YELLOW%^d%^RESET%^%^ORANGE%^"
"en-brown mare%^RESET%^");
}
