// malar: travel domain, faithful mount. Nienne, 05/07.
#include <std.h>
inherit "/d/magic/mon/mounts/travelinherit.c";

void create(){
    ::create();
    set_name("black stallion");
    set_short("%^BOLD%^%^BLACK%^A rugged black stallion%^RESET%^");
    set_id( ({"horse","stallion","black stallion","rugged stallion","faithful mount"}) );
    set_long("%^ORANGE%^This horse appears to be strong and energetic, but "
"with a rough and uneasy temperament. Its coat is coarse and rugged, and of a "
"%^BOLD%^%^BLACK%^jet-black shade%^RESET%^%^ORANGE%^, the color mirrored in "
"its wild mane and tail. It seems barely tamed, if at all, constantly tossing "
"its head and rolling its %^RED%^bloodshot %^ORANGE%^eyes. No bridle "
"restrains the creature, only a mat and a simple saddle across its back, "
"marked with a symbol of a %^RESET%^bestial claw %^ORANGE%^with %^BOLD%^"
"%^RED%^bloodstained %^RESET%^%^ORANGE%^talons.%^RESET%^");
    set_gender("male");
    set_enter_room("rides in on a wild stallion.");
    set_exit_room("leaves riding a wild stallion.");
    set_vehicle_short("%^BOLD%^%^BLACK%^A rugged black stallion%^RESET%^");
}
