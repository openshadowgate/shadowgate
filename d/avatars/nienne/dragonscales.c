#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("silvery dragon scales");
   set_id(({"scales","dragon scales","silvery scales","silvery dragon scales"}));
   set_short("%^BOLD%^%^WHITE%^si%^CYAN%^l%^WHITE%^very dragon sca%^BLUE%^l%^WHITE%^es%^RESET%^");
   set_long("%^RESET%^This hide consists of a large portion of shimmering "
"%^BOLD%^%^WHITE%^si%^CYAN%^l%^WHITE%^very-b%^BLUE%^l%^WHITE%^ue %^RESET%^"
"scales, the color giving them the appearance of overlapping segments of metal. "
"Their brilliant sheen reflects surroundings like a polished "
"%^BOLD%^%^BLACK%^mirror%^RESET%^, gleaming as they catch the light. They must "
"have come from a creature easily bigger than a warhorse, to yield such a large "
"hide. While sinuous like %^GREEN%^snakes%^CYAN%^ki%^GREEN%^n%^RESET%^, they "
"hold a startling strength within them, making it very hard even to cut or "
"shape the hide for use.\n");
   set_lore("This could only be the hide of a silver dragon, judging by the color of its scales and the strength of the hide.  Given the color and the contours of the hide, it would have come from a dragon not quite yet adult, but close to it.");
   set_property("lore difficulty",20);
   set_weight(50);
   set_value(15000);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_size(3);
   set_ac(40);
   set_property("enchantment",5);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   if(!avatarp(TP)) {
     tell_object(ETO,"How on earth would you wear those?");
     return 0;
   }
   tell_room(EETO,"%^BOLD%^%^WHITE%^The scales gleam brightly.%^RESET%^");
   ETO->add_saving_bonus("all",3);
   ETO->set_property("magic resistance",35);
   return 1;
}

int remove_fun() {
   ETO->add_saving_bonus("all",(-3));
   ETO->set_property("magic resistance",-35);
   return 1;
}
