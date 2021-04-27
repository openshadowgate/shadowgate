#include <std.h>
inherit ARMOUR;

int OWNED;
string owner;

void create() {
   ::create();
   set_name("cloak");
   set_id(({"cloak","hooded cloak","shadowy cloak","shadowy hooded cloak","shroud of twilight","Shroud of Twilight","shroud"}));
   set_short("%^BLACK%^%^BOLD%^Shroud of Twilight%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^shadowy hooded cloak%^RESET%^");
   set_long("%^ORANGE%^This long, hooded cloak is made of the most sheer cloth imaginable, nearly "
"transparent in its thin texture.  It holds the perfect, unbroken colour of %^BLACK%^%^BOLD%^gray charcoal"
"%^RESET%^%^ORANGE%^, like whisps of shadow that wrap around the wearer's shoulders.  They would make one "
"nearly invisible in darkness, except for the single slender line of %^RED%^crimson%^ORANGE%^ thread along "
"the hem of the garment, that adds a touch of expense to the cloak's appearance.  Several small metal hooks "
"would hold it together at the wearer's throat, small enough to be invisible when the garment is secured."
"%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Only whispers of gossip have ever been heard concerning this cloak.  Some "
"claim that it was formed by the power of the %^BLACK%^Shadowlord%^WHITE%^ himself, shaped from the shadows "
"themselves.  Others simply attribute its make to a particularly skilled human seamstress from the city of "
"Tharis.  Either way, the quality and appearance of the cloak are obviously exceptional.");
   set_property("lore difficulty",16);
   set_limbs(({"neck"}));
   set_weight(2);
   set_value(2200);
   set_size(2);
   set_ac(1);
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
   if(interactive(TP) && TP == environment(TO) && !OWNED) {
     owner = TPQN;
     OWNED = 1;
   }
}

int wear_fun() {
   if((string)TPQN == owner || avatarp(TP)) {
     tell_object(ETO,"%^BLACK%^%^BOLD%^The cloak shrouds you in a dark haze of shadow.");
     tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETO->QCN+" becomes shrouded in a shadowy haze by the whispy "
"cloak.",ETO);
     ETO->add_sight_bonus(-1);
     return 1;
   }
   tell_object(ETO,"%^BLACK%^%^BOLD%^The whispy cloak doesn't seem to fit you.");
   return 0;
}

int remove_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^You feel far more vulnerable without the concealment of the shadowy "
"cloak.");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETO->QCN+" glances around cautiously as "+ETO->QS+" removes the whispy "
"cloak.",ETO);
   ETO->add_sight_bonus(1);
   return 1;
}
