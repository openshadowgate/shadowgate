#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("boots");
   set_id(({"boots","kossuth boots","salamander's steps","steps","salamanders steps","scaled boots","crimson boots"}));
   set_short("%^RESET%^%^RED%^Sa%^BOLD%^l%^RESET%^%^RED%^ama%^ORANGE%^n%^RED%^der's St%^RED%^%^BOLD%^e%^RESET%^%^RED%^ps%^RESET%^");
   set_obvious_short("%^RESET%^%^RED%^scaled crimson boots%^RESET%^");
   set_long("%^CYAN%^These boots have an incredibly tough exterior, made of what appear to be multiple "
"overlapping scales, like the skin of some reptile.  They are permanently warm to touch, and are of a%^RED%^ "
"deep red%^CYAN%^ hue, that glints with %^RED%^%^BOLD%^crimson%^RESET%^%^CYAN%^ highlights when moved.  No "
"gaps are left between the scales, effectively water-proofing them.  While there are no laces or buckles to "
"hold them closed, they seem to shape themselves around the foot of their own accord.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Rumours abound concerning these boots and the clergy of the Flamelord.  "
"The most prevalent tells that boots such as these are made from the skin of a Salamanders, and gifted only "
"to the most blessed of Kossuth's clergy, shielding their feet from even the most intense flame.");
   set_property("lore difficulty",7);
   set_weight(2);
   set_value(0);
   set_ac(0);
   set_size(2);
   set_property("enchantment",3);
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   if((string)ETO->query_diety() != "kossuth") {
     tell_object(ETO,"%^RED%^%^BOLD%^The boots are far too hot to wear!");
     tell_room(EETO,"%^RED%^%^BOLD%^"+ETOQCN+" tries to force the boots onto "+ETO->QP+" feet, but "
"fails.",ETO);
     return 0;
   }
   tell_object(ETO,"%^RED%^%^BOLD%^You feel the warmth of the Flamelord carried within the boots.");
   tell_room(EETO,"%^RED%^%^BOLD%^"+ETOQCN+" slides the boots onto "+ETO->QP+" feet with a look of "
"pride.",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^RED%^%^BOLD%^You feel the warmth of the Flamelord carried within the boots.");
   tell_room(EETO,"%^RED%^%^BOLD%^"+ETOQCN+" slides the boots onto "+ETO->QP+" feet with a look of "
"pride.",ETO);
   return 1;
}
