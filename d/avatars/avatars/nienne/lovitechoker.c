#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("gorget");
   set_id(({"gorget","choker","choker gorget","black gorget","black choker","black choker gorget","collar","torments collar","torment's collar"}));
   set_short("%^BLACK%^%^BOLD%^Tor%^RESET%^%^WHITE%^m%^BLACK%^%^BOLD%^ent's Col%^RESET%^%^WHITE%^l%^BLACK%^%^BOLD%^ar%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^black choker gorget%^RESET%^");
   set_long("%^CYAN%^This exotic jewelry item, known as a gorget, is designed to be worn tightly around the "
"throat, in a similar way to a collar.  It is crafted from %^BLACK%^%^BOLD%^black leather%^RESET%^%^CYAN%^, "
"and attaches at the back of the neck with a buckle of %^BLACK%^%^BOLD%^jet%^RESET%^%^CYAN%^.  Around the "
"circumference of the choker, inch-long spikes of %^BLACK%^%^BOLD%^jet%^RESET%^%^CYAN%^ extend in many "
"directions, making it dangerous for anyone's hands to come close, including those of the wearer.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Rumours abound concerning this jewelry and the clergy of the Maiden of Pain.  "
"The most common tells that the gorget is crafted by the priesthood of her church, and gifted only to the most "
"blessed of her order.  It is seen as a sign of her favour by Loviatar herself, as any unworthy that attempt "
"to wear such an item suffer such intense agony that only the Queen of Torment could grant. Thus, the "
"possession of it is regarded as an extremely high honour among the faithful.");
   set_property("lore difficulty",12);
   set_limbs(({"neck"}));
   set_weight(2);
   set_value(0);
   set_ac(1);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   if((string)ETO->query_name() != "etarena" && !avatarp(ETO)) {
     tell_object(ETO,"%^BLACK%^%^BOLD%^The choker sends a wave of %^RED%^pain %^BLACK%^through you as you try "
"to wear it!%^RESET%^");
     tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" winces in %^RED%^pain %^BLACK%^as "+ETO->QS+" tries to wear "
"the choker.%^RESET%^",ETO);
     return 0;
   }
   tell_object(ETO,"%^BLACK%^%^BOLD%^You feel the blessings of the %^RED%^Maiden of Pain %^BLACK%^as you clasp "
"the choker around your neck.%^RESET%^");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" smiles with a dark inner confidence as "+ETO->QS+" clasps the "
"choker around "+ETO->QP+" neck.",ETO);
   ETO->set_property("magic resistance",10);
   ETO->add_attack_bonus(1);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^You feel a shudder of %^RED%^agony %^BLACK%^through your body as you "
"remove the choker.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" shudders in pain as "+ETO->QS+" unclasps the "
"choker.%^RESET%^",ETO);
   ETO->set_property("magic resistance",10);
   ETO->add_attack_bonus(-1);
   return 1;
}
