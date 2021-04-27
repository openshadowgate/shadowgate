#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("earrings");
   set_id(({"earrings","silver earrings","hoops","silver hoops","small silver earrings","hoop earrings"}));
   set_short("%^BOLD%^%^WHITE%^small s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r hoop earrings%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This set of %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lve%^RESET%^r%^BOLD%^"
"%^WHITE%^y %^RESET%^%^GREEN%^hoops have been designed to be worn in the ears, and have been polished to a "
"%^YELLOW%^bright %^RESET%^%^GREEN%^sheen.  Each is set with a small %^RESET%^clasp %^GREEN%^that can be "
"secured to hold the jewelry in place.  While all of the hoops are small, some recede even smaller again from "
"the others.  They are most likely designed to be worn in a series up the side of the ear, as an %^RED%^"
"unusual %^GREEN%^accessory.%^RESET%^\n");
   set_type("ring");
   set_limbs(({"head"}));
   set_ac(0);
   set_size(2);
   set_weight(1);
   set_value(80);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun(){
   tell_object(ETO,"%^BOLD%^%^WHITE%^You carefully hook the hoops through your ears, one by one.%^RESET%^");
   ETO->set_property("magic resistance",5);
   return 1;
}

int remove_fun(){
   tell_object(ETO,"%^BOLD%^%^WHITE%^You unclasp each of the hoops from your ear.%^RESET%^");
   ETO->set_property("magic resistance",-5);
   return 1;
}