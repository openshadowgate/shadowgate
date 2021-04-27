#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create() {
   ::create();
   set_id(({"sacrificial dagger","ornate dagger","black dagger","ornate black dagger","dagger"}));
   set_name("black dagger");
   set_short("%^BOLD%^%^BLACK%^Sac%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ific%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^al Dag%^RESET%^%^MAGENTA%^g%^BOLD%^%^BLACK%^er");
   set_obvious_short("%^BOLD%^%^BLACK%^an orn%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^te black dagger%^RESET%^");
   set_long("%^BLUE%^You can imagine that this elaborate dagger wouldn't be "
"particularly useful in a fight - it is surprisingly heavy, and obviously not "
"weighted properly for combat.  The blade itself is a little too long, and "
"made of some flawless %^BOLD%^%^BLACK%^glossy black metal%^RESET%^%^BLUE%^. "
"Its razor-sharp edges spread from a narrow tip to the broader base, where it "
"has been inset into a hilt made entirely of %^BOLD%^%^BLACK%^on%^RESET%^%^WHITE%^y%^BOLD%^%^BLACK%^x%^RESET%^%^BLUE%^. "
"The precious stone has been carved into the shape of a spider, its eight "
"legs parted with two pairs resting forward to grip the blade, and the other "
"two curved around to protect the dagger's hilt. Tiny fragments of "
"%^MAGENTA%^pur%^WHITE%^p%^MAGENTA%^le jade %^BLUE%^mark out the features of "
"the arachnid in striking %^MAGENTA%^violet%^BLUE%^.%^RESET%^\n");
   set_property("enchantment",5);
   set_prof_type("magic weapons");
   set_value(11025);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
}

int wield_fun() {
   if((string)ETO->query_diety() != "shar") {
     tell_object(ETO,"%^BOLD%^%^BLACK%^You can't get a proper grip around the "
"stone carved legs of the spider.%^RESET%^");
     return 0;
   }
   tell_room(EETO,"%^MAGENTA%^The spider's legs seem to come alive, curling "
"around "+ETO->QCN+"'s hand as "+ETO->QS+" grasps the dagger!%^RESET%^",ETO);
   tell_object(ETO,"%^MAGENTA%^The spider's legs seem to come alive, curling "
"around your hand as you grasp the dagger's hilt!%^RESET%^");
   return 1;
}

int unwield_fun() {
   tell_room(EETO,"%^MAGENTA%^The spider's legs uncurl and return to their "
"lifeless state as "+ETOQCN+" releases the dagger%^RESET%^.",ETO);
   tell_object(ETO,"%^MAGENTA%^The spider's legs uncurl and return to their "
"lifeless state as you release the dagger.%^RESET%^");
   return 1;
}
