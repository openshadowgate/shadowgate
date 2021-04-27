#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("nose ring");
   set_id(({"nosering","nose ring","golden nosering","golden nose ring","ring"}));
   set_short("%^YELLOW%^large golden nosering%^RESET%^");
   set_long("This simple hoop of metal is unadorned, and rather large and heavy as far as such jewelry items "
"go.  %^YELLOW%^Solid gold%^RESET%^ forms the band, unmarked by engravings, and slightly narrowed upon one "
"side where it is obviously designed to pass through a piercing of some kind.%^RESET%^\n");
   set_weight(1);
   set_value(50);
   set_ac(0);
   set_size(3);
   set_type("ring");
   set_limbs(({"head"}));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You slip the ring through the piercing in your nose.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" slips the ring through the piercing in "+ETO->QP+" nose.",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You remove the large ring from your nose.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" removes the large ring from "+ETO->QP+" nose.",ETO);
   return 1;
}