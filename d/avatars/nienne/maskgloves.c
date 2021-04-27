#include <std.h>
inherit ARMOUR;

int OWNED;
string owner;

void create() {
   ::create();
   set_name("gloves");
   set_id(({"gloves","gray gloves","shadowy gloves","shadowy gray gloves","hands of shadow"}));
   set_short("%^BLACK%^%^BOLD%^Hands of Shadow%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^shadowy gray gloves%^RESET%^");
   set_long("%^CYAN%^These gloves seem to be made of the most sheer cloth, nearly transparent in their thin "
"texture.  They hold the perfect, unbroken colour of %^BLACK%^%^BOLD%^gray charcoal%^RESET%^%^CYAN%^, like "
"traces of shadow that wrap the hands in a perfect fit.  They would make the hands nearly invisible in "
"darkness, except for the single slender line of %^RED%^red%^CYAN%^ embroidery that adds a touch of expense "
"to the gloves' appearance.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Only whispers of gossip have ever been heard concerning these gloves.  Some "
"claim that they were formed by the power of the %^BLACK%^Shadowlord%^WHITE%^ himself, shaped from the "
"shadows to conceal the hands of the wearer.");
   set_property("lore difficulty",13);
   set_limbs(({"right hand","left hand"}));
   set_weight(2);
   set_value(0);
   set_size(2);
   set_ac(0);
   set_property("enchantment",1);
   while(TO->query_property("enchantment")< 1){
      remove_property("enchantment");
      set_property("enchantment",1);
   }
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

void init() {
   ::init();
   if(!interactive(ETO) || avatarp(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !OWNED && !avatarp(TP)) {
     owner = TPQN;
     OWNED = 1;
   }
}

int wear_fun() {
   if((string)TPQN == owner || avatarp(TP)) {
     tell_object(ETO,"%^WHITE%^%^BOLD%^The gloves seem to come alive with %^BLACK%^shadows%^WHITE%^ as you "
"slide them over your hands.");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+"'s hands become shrouded by the %^BLACK%^shadowy%^WHITE%^ "
"gloves.",ETO);
     ETO->set_property("magic resistance",5);
     return 1;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^The gloves refuse to fit your hands!");
   return 0;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel the protection of the %^BLACK%^shadows%^WHITE%^ recede as "
"you remove the gloves.");
   ETO->set_property("magic resistance",-5);
   return 1;
}
