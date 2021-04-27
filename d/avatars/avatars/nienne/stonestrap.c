#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("leather strap");
   set_id(({"stone","marbled stone","leather strap","strap"}));
   set_short("%^RESET%^a %^BOLD%^%^BLACK%^ma%^CYAN%^r%^BLACK%^bled st%^MAGENTA%^o%^BLACK%^ne%^RESET%^ tied on a %^ORANGE%^leather strap%^RESET%^");
   set_long("This little stone is smooth to the touch and about the size of a "
"child's fist. %^BOLD%^%^BLACK%^Dark %^RESET%^in color, its surface is striated by "
"veins of %^BOLD%^%^WHITE%^gli%^CYAN%^t%^WHITE%^ter%^MAGENTA%^i%^WHITE%^ng "
"%^RESET%^gemstone that give a rather pretty appearance to the otherwise "
"%^RED%^mundane %^RESET%^stone. It has been bound onto a %^ORANGE%^leather strap "
"%^RESET%^that could probably be worn comfortably around the neck.\n");
   set_type("ring");
   set_limbs(({"neck"}));
   set_ac(0);
   set_size(2);
   set_weight(0);
   set_value(350);
   set_wear((:TO,"wear_fun":));
}

int wear_fun(){
   if((string)ETO->query_name() == "marika" || (string)ETO->query_name() == "marika") {
     tell_room(EETO,"%^ORANGE%^The feel of the cool stone against your skin brings "
"back fond memories.%^RESET%^",ETO);
   }
   return 1;
}
