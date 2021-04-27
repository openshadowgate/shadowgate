#include <std.h>
inherit PARMOUR;

void create() {
   ::create();
   set_name("%^RESET%^%^BLUE%^long silken robes%^RESET%^");
   set_id(({"robe","robes","silken robes","long robes","long silken robes","white robes","mantle of the tempest","tempest mantle","mantle"}));
   set_short("%^BOLD%^%^WHITE%^Man%^BOLD%^%^CYAN%^t%^RESET%^%^WHITE%^le of t%^BOLD%^%^BLACK%^h%^BOLD%^%^WHITE%^e Temp%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^st%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^lo%^RESET%^%^WHITE%^n%^BOLD%^%^WHITE%^g si%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^ken rob%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^s%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This beautiful garment looks somehow as though it were %^RESET%^%^CYAN%^brand new"
"%^BOLD%^%^BLACK%^, and perfectly clean - all dirt just seems to slide from it with ease.  Fine layers of "
"%^BOLD%^%^WHITE%^snowy-white silk %^BOLD%^%^BLACK%^have been laid across each other in an archaic style, "
"forming a robe that is complete with long billowing sleeves lined in %^RESET%^%^WHITE%^stormy gray%^BOLD%^"
"%^BLACK%^, and identical lining around the curved neckline and hem.  Inside the cloth has been stitched a "
"carefully concealed pocket.  No other decoration marks their austere design, but this only seems to enhance "
"the simple beauty and elegance of the garment itself.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^These robes were once known to be the possession of Angmeth, a human mage known "
"as Akadi's Whirlwind.  They were a prized belonging of his, which he jealously guarded, so much so that many "
"rumours circulated that perhaps they held some divine blessing from his own goddess.  Or perhaps it was only "
"a mage's way of guarding his magical items.  Either way, it was said that he met his downfall within the "
"caverns of the earth, so far away from his beloved skies above, and the robes disappeared from knowledge "
"along with the rest of his possessions.");
   set_property("lore difficulty",16);
   set_limbs(({"torso"}));
   set_weight(8);
   set_value(5600);
   set_size(2);
   set_ac(1);
   set_property("enchantment",2);
   while(TO->query_property("enchantment")< 2){
     remove_property("enchantment");
     set_property("enchantment",2);
   }
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_max_internal_encumbrance(21);
}

int wear_fun() {
   if((string)TP->query_diety() != "akadi") {
     tell_object(ETO,"%^WHITE%^%^BOLD%^The robes don't seem to fit you.");
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^The robes seem to shift and slide around you, brushing easily against "
"your skin.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" smiles and slips into the soft robes.",ETO);
   ETO->add_stat_bonus("charisma",1);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^It's almost disappointing to remove such comfortable robes.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" looks disappointed to remove the soft robes.",ETO);
   ETO->add_stat_bonus("charisma",-1);
   return 1;
}
