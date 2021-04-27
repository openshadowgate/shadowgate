#include <std.h>
inherit "/d/common/obj/weapon/quarter_staff.c";

void create() {
    ::create();
    set_name("walking staff");
    set_id(({"staff","walking staff","gnarled staff","gnarled walking staff"}));
    set_short("%^RESET%^%^ORANGE%^gnarled walking staff%^RESET%^");
    set_long("%^GREEN%^This staff seems relatively harmless by appearance, and is made of what looks like "
"%^ORANGE%^oaken wood%^GREEN%^.  Rather than being smoothed as a combat weapon, it has been left in a more "
"natural shape, slightly gnarled and twisted back upon itself.  It seems particularly sturdy though, and "
"would rest quite comfortably in the hand, probably designed as a walking aid for a traveller.%^RESET%^");
   set_property("enchantment",1);
   set_value(150);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun(){
    tell_object(ETO,"%^ORANGE%^The gnarled staff fits smoothly into your grip.%^RESET%^");
    return 1;
}

int unwield_fun() {
   tell_object(ETO,"%^ORANGE%^You release your hold on the gnarled staff.%^RESET%^",ETO);
   return 1;
}

int isMagic() { return 0; }
