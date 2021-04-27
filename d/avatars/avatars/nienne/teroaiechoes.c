#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/races/genasifire";

void create() {
   ::create();
   set_heart_beat(1);
}

void heart_beat() {
    if(!objectp(ETO)) return;
    if(!userp(ETO)) return;
    if(!TO->query_worn()) return;
    if(ETO->query_invis()) return;

    if(random(1800) == 666) {
      switch(random(100)) {
        case 0..49:
          tell_room(EETO,"%^BOLD%^%^BLACK%^Tendrils of %^BOLD%^%^RED%^fl%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^me "
"%^BOLD%^%^BLACK%^leap about "+ETO->QCN+"'s head.%^RESET%^",ETO);
        break;
        default:
          tell_room(EETO,"%^BOLD%^%^BLACK%^For a moment,  "+ETO->QCN+"'s %^BOLD%^%^WHITE%^silver %^BOLD%^%^BLACK%^"
"eyes %^BOLD%^%^WHITE%^shimmer %^BOLD%^%^BLACK%^slightly.%^RESET%^",ETO);
        break;
      }
    }
}