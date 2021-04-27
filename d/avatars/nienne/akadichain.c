#include <std.h>
inherit "/d/common/obj/armour/chain";

int OWNED;
string owner;

void create() {
   ::create();
   set_name("chainmail");
   set_id(({"chain","akadi chain","cloudcover","cloud cover","cover","rippled chainmail","rippled chain"}));
   set_short("%^WHITE%^%^BOLD%^Cl%^CYAN%^o%^WHITE%^udc%^CYAN%^o%^WHITE%^ver%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^ri%^CYAN%^p%^WHITE%^pled ch%^CYAN%^a%^WHITE%^inma%^CYAN%^i%^WHITE%^l%^RESET%^");
   set_long("%^CYAN%^Fine links of metal form this suit of chainmail, that seems strangely light.  The armor "
"is lined underneath with a layer of smooth silk, dyed a swirling shade of%^WHITE%^ "
"cl%^BLACK%^%^BOLD%^o%^RESET%^%^WHITE%^udy whi%^BLACK%^%^BOLD%^t%^RESET%^%^WHITE%^e%^CYAN%^.  Over this rest "
"the multitude of small metal links, fine rings in rippling shades of %^WHITE%^silver%^CYAN%^ and "
"%^BLACK%^%^BOLD%^gray%^RESET%^%^CYAN%^.  The suit of chainmail is sleeveless and the rings are perfectly "
"fitted, allowing for a good deal more freedom of movement than most common armors.%^RESET%^\n");
   set_property("enchantment",1);
   set_weight(25);
   set_value(650);
   set_lore("%^WHITE%^%^BOLD%^Rumours abound concerning this armor and the clergy of the Queen of Air.  "
"The most common tells that the chain links are forged and imbued with the essence of the winds, to protect "
"a faithful wearer.");
   set_property("lore difficulty",7);
   set_wear((:TO,"wear_fun":));
   set_remove("%^CYAN%^You feel a little disappointed to remove the chainmail.");
}

void init() {
   ::init();
   if(!interactive(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !OWNED && !avatarp(TP)) {
     owner = TPQN;
     OWNED = 1;
     set_size(TP->query_size());
   }
}

int wear_fun() {
   if((string)TPQN != owner) {
     tell_object(ETO,"%^BOLD%^The armor doesn't fit you!");
     tell_room(EETO,"%^BOLD%^"+ETOQCN+" tries to force the armor on, but fails.",ETO);
     return 0;
   }
   tell_object(ETO,"%^CYAN%^The silken lining brushes gently over your skin as you slip into the chainmail.");
   tell_room(EETO,"%^CYAN%^"+ETOQCN+" slides into the chainmail with a smile.",ETO);
   return 1;
}
