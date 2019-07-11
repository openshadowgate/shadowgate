// oghma: travel domain, faithful mount. Nienne, 05/07.
#include <std.h>
inherit "/d/magic/mon/mounts/travelinherit.c";

void create(){
    ::create();
    set_name("white stallion");
    set_short("%^BOLD%^%^WHITE%^A noble white stallion%^RESET%^");
    set_id( ({"horse","stallion","white stallion","noble stallion","faithful mount"}) );
    set_long("%^GREEN%^With proud bearing and impeccable grooming, this "
"stallion is a magnificent beast. His short fur is %^BOLD%^%^WHITE%^snowy-"
"white%^RESET%^%^GREEN%^, covering muscled flanks that are obviously "
"accustomed to exercise. A long mane and tail match the%^BOLD%^%^WHITE%^ "
"ivory hue %^RESET%^%^GREEN%^of his coat, and his hooves are clean and "
"polished. He bears a %^BOLD%^%^BLACK%^black bridle %^RESET%^%^GREEN%^and a "
"%^MAGENTA%^purple%^GREEN%^-and-%^BOLD%^%^BLACK%^black%^RESET%^%^GREEN%^ "
"saddle across his back, both trimmed with shining %^ORANGE%^go%^YELLOW%^ld"
"%^RESET%^%^ORANGE%^en %^GREEN%^braid.%^RESET%^");
    set_gender("male");
    set_enter_room("rides in on a proud stallion.");
    set_exit_room("leaves riding a proud stallion.");
    set_vehicle_short("%^BOLD%^%^WHITE%^A noble white stallion%^RESET%^");
}
