#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
   ::create();
   set_name("leather bracers");
   set_id(({"bracers","leather bracers","cuffs of the forest shadows","cuffs","mottled bracers","mottled leather bracers"}));
   set_short("%^RESET%^%^GREEN%^Cu%^ORANGE%^f%^GREEN%^fs of the F%^ORANGE%^o%^GREEN%^rest Shad%^ORANGE%^o%^GREEN%^ws%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^m%^GREEN%^o%^ORANGE%^ttl%^GREEN%^e%^ORANGE%^d leather bracers%^RESET%^");
   set_long("%^CYAN%^These bracers are obviously designed to last, with sturdy layers of thickened%^ORANGE%^"
" leather%^CYAN%^, obviously treated and weatherproofed.  Short, woven laces would hold them secure around the "
"wearer's forearm, running along the underside of each cuff.  Small, nearly unnoticable markings in %^GREEN%^"
"dull green%^CYAN%^ trace light patterns across their surface, giving them a mottled appearance like leaves "
"upon a forest floor.  Despite their thickness, they seem so well treated as to allow a great deal of movement "
"and freedom even when they are worn.%^RESET%^\n");
   set_ac(2);
   set_size(2);
   set_property("enchantment",5);
   set_value(350);
   set_lore("%^WHITE%^%^BOLD%^This artifact is one of many that were crafted within the now-lost elven city of "
"El'kannor, lost many decades past in the ogre raids that destroyed the city in the year 634SG, common "
"reckoning.  Some were said to have been retained by Ellanora, a ranger of their people, as one of the few "
"surviving relics of the lost civilization, but even here whereabouts are a matter of rumour and mystery."
"%^RESET%^\n");
   set_property("lore difficulty",10);
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
}

int check(){
   ::check();
   if(!avatarp(ETO)) {
     tell_object(ETO,"The bracers don't seem to fit you.");
     tell_room(EETO,"The bracers don't seem to fit "+ETO->QCN+".%^RESET%^",ETO);
     return 0;
   }
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" slides the mottled bracers over "+ETO->QP+" forearms.%^RESET%^",ETO);
   tell_object(ETO,"%^ORANGE%^The mottled bracers meld easily to fit around your forearms.%^RESET%^");
   ETO->add_attack_bonus(3);
   ETO->add_damage_bonus(3);
   return 1;
}

int remove_fun(){
  tell_room(EETO,"%^ORANGE%^"+ETOQCN+" gently removes the mottled bracers.%^RESET%^",ETO);
  tell_object(ETO,"%^ORANGE%^You slide your forearms free of the comfortable bracers.%^RESET%^");
   ETO->add_attack_bonus(-3);
   ETO->add_damage_bonus(-3);
  return 1;
}
