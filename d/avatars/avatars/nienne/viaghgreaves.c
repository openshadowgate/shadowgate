#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("adamantium greaves");
   set_short("%^BOLD%^%^BLACK%^Steadfast Guards%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^dark adamantium greaves%^RESET%^");
   set_id(({"greaves","adamantite greaves","dark greaves","guards","steadfast guards"}));
   set_long("%^BLUE%^This armor consists of a twin pair of greaves, each "
"designed to protect the lower legs from harm. Heavy plates have been beaten "
"from %^BOLD%^%^BLACK%^dark adamantium metal%^RESET%^%^BLUE%^, and layered "
"in order to deflect blows from all angles. %^ORANGE%^Sturdy leather straps "
"%^BLUE%^ with solid buckles hold them at the back of the legs, and even the "
"straps themselves are protected by more cleverly-angled metal "
"plates.%^RESET%^\n");
   set_weight(3);
   set_value(1025);
   set_ac(1);
   set_size(2);
   set_type("armor");
   set_limbs(({ "left leg", "right leg" }));
   while((int)TO->query_property("enchantment") < 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_item_bonus("damage resistance",2);
}

int wear_fun() {
    if(!ETO->is_class("fighter")) {
      tell_object(ETO,"You're not quite sure how to make use of these.");
      return 0;
    }
   tell_object(ETO,"%^BLUE%^You buckle the greaves securely.%^RESET%^");
   tell_room(EETO,"%^BLUE%^"+ETO->QCN+" buckles the greaves securely.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
     tell_object(ETO,"%^BLUE%^You unbuckle the sturdy greaves.%^RESET%^");
     tell_room(EETO,"%^BLUE%^"+ETO->QCN+" unbuckles "+ETO->QP+" greaves.%^RESET%^",ETO);
   return 1;
}
