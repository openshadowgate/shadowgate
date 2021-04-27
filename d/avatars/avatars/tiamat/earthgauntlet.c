#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int tracker;

void create() {
   ::create();
   set_name("gauntlet");
   set_id(({"gauntlet","gauntlet of the earth","gauntlet of metal and stone"}));
   set_short("%^RESET%^%^ORANGE%^Gauntlet of the E%^BOLD%^ar%^RESET%^%^RED%^t%^ORANGE%^h%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^a gauntlet of %^RESET%^metal %^ORANGE%^and st%^BOLD%^o%^RESET%^%^ORANGE%^n%^RED%^e%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is a gauntlet of unusual qualities. It at first appears to be little more "
"than a metal glove of wrought iron, weathered and covered in %^RED%^rust%^ORANGE%^ and %^RESET%^grime"
"%^ORANGE%^. On closer inspection, however, you note that the item is not rusted at all. Rather, the gauntlet "
"is a solid shape of metal, but various %^RED%^ores%^ORANGE%^ and semi-precious %^BOLD%^gems%^RESET%^"
"%^ORANGE%^ are growing from the iron itself. No blemish or deterioration marks the strange artifact, save a "
"short %^BOLD%^%^BLACK%^inscription%^RESET%^%^ORANGE%^ engraved on the inner portion.%^RESET%^\n");
   set_lore("The Gauntlet of the Earth is a rare artifact, usually bestowed only to those faithful of Grumbar "
"that prove their worth as a master crafter. It is said that the gauntlet is not made, but grown from the "
"earth many leagues below the surface. Few known how long this process takes, but their rarity is testament to "
"the ordeals necessary to create one.");
   set_property("lore difficulty",15);
   set("read","%^RESET%^%^RED%^Receive the blessing of the Grumbar once daily, and %^BOLD%^<thrust>%^RESET%^%^RED%^ the gauntlet into the Earth.%^RESET%^");
   set_language("wizish");
   set_limbs(({"left hand","right hand"}));
   set_weight(5);
   set_value(4200);
   set_size(2);
   set_ac(1);
   set_property("enchantment",2);
   while((int)TO->query_property("enchantment") != 2){
      remove_property("enchantment");
      set_property("enchantment",2);
   }
   set_type("armor");
   set_wear((:TO,"wear_fun":));
   tracker = 0;
}

void init() {
   ::init();
   add_action("metal_fun","thrust");
}

int wear_fun() {
    if((int)ETO->query_highest_level() < 28) {
      tell_object(ETO,"You may not wear this yet.");
      return 0;
    }
    if(!TP->is_class("cavalier") && !TP->is_class("paladin") && !TP->is_class("fighter") && !TP->is_class("cleric") && !TP->is_class("antipaladin")) {
      tell_object(ETO,"The magic of the gauntlet refuses to be worn by you.");
      return 0;
    }
    if((string)ETO->query_diety() != "grumbar") {
      tell_object(ETO,"Only those who earn this may don this gauntlet.");
      return 0;
    }
   tell_object(ETO,"%^ORANGE%^Power ripples through your forearm as you don the gauntlet.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^As "+ETO->QCN+" wears the gauntlet, "+ETO->QP+" forearm trembles with "
"power.%^RESET%^.",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^ORANGE%^You flex your fingers, now free of the earthen gauntlet.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" flexes "+ETO->QP+" fingers, now free of the earthen "
"gauntlet.%^RESET%^",ETO);
   return 1;
}

int metal_fun(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to be wearing the gauntlet.");
     return 1;
   }
   if(str) {
     tell_object(TP, "You must %^BOLD%^<thrust>%^RESET%^%^RED%^ the gauntlet into the Earth.%^RESET%^");
     return 1;
   }
   if(tracker > time()) {
     tell_object(TP,"You've already called upon the power of the Earthlord today.");
     return 1;
   }
   tracker = time() + 28800;
   tell_object(TP,"%^ORANGE%^%^ORANGE%^You drive your fist into the ground, producing still-hot ore from the "
"earth itself!%^RESET%^");
   tell_room(ETP,"%^ORANGE%^%^ORANGE%^"+ETO->QCN+" drives "+ETO->QP+" fist into the ground, producing still-"
"hot ore from the earth itself!%^RESET%^",TP);
   new("/std/obj/metal")->move(ETP);
   return 1;
}
