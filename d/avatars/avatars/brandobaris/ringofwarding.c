#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("ivory ring");
   set_id(({"ivory ring","ring","ring of warding","Ring of Warding"}));
   set_short("%^BOLD%^%^WHITE%^Ring of %^BOLD%^%^CYAN%^W%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^d%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^g%^RESET%^");
   set_obvious_short("%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^d %^BOLD%^%^WHITE%^ivo%^YELLOW%^r%^BOLD%^%^WHITE%^y ring%^RESET%^");
   set_long("%^RESET%^This trinket is small and light of weight, cut from a single piece of dull %^BOLD%^%^WHITE%^ivo%^YELLOW%^r%^BOLD%^%^WHITE%^y%^RESET%^ to form a perfect circle.  "
"Smooth on either side, the upper surface bears a series of %^BOLD%^%^CYAN%^g%^RESET%^%^CYAN%^l%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^m%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^n"
"%^RESET%^%^CYAN%^g %^RESET%^runes that have been etched into the ring in some unknown tongue.  A faint %^CYAN%^aura %^RESET%^glows around the trinket.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Such trinkets are commonly crafted by the Mystran faith, given to their faithful clergy to serve as a powerful protection when travelling in the "
"field.  The minor abjuration placed upon them draws upon the strength of the wearer, which allows them to become more effective when worn by a powerful being.%^RESET%^\n");
   set_property("lore difficulty",25);
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_weight(1);
   set_size(-1);
   set_value(13500);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   int mylevel, mradded, aradded;
   tell_object(ETO,"%^BLACK%^%^BOLD%^A protective %^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^a %^BLACK%^%^BOLD%^flickers into being around you as you place the ring on.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^A protective %^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^a %^BLACK%^%^BOLD%^flickers into being around "+ETO->QCN+" as "+ETO->QS+" places the ring on.%^RESET%^",ETO);
   ETO->set_property("added short",({" %^RESET%^%^CYAN%^(protected by a faint aura)%^RESET%^"}));
   mylevel = (int)ETO->query_level();
   mradded = (mylevel*3)/4;
   aradded = ((mylevel-1)/10)+1;
   TO->set_item_bonus("magic resistance",mradded);
   TO->set_item_bonus("armor bonus",aradded);
   return 1;
}

int remove_fun(){
   tell_object(ETO,"%^BLACK%^%^BOLD%^You remove the ring and the %^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^a %^BLACK%^%^BOLD%^fades.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETO->QCN+" removes the ring and "+ETO->QP+" %^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^a %^BLACK%^%^BOLD%^fades.%^RESET%^",ETO);
   ETO->remove_property("added short",({" %^RESET%^%^CYAN%^(protected by a faint aura)%^RESET%^"}));
   return 1;
}

int isMagic(){ return 1; }