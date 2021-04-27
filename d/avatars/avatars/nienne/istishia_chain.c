#include <std.h>
inherit "/d/common/obj/armour/chain";

void create() {
   ::create();
   set_name("mesh");
   set_id(({"chain","istishia chain","precipitation mesh","shroud","precipitation shroud","mesh","mesh armor"}));
   set_short("%^RESET%^%^CYAN%^P%^BLUE%^r%^CYAN%^eci%^WHITE%^p%^CYAN%^ita%^BLUE%^t%^CYAN%^ion %^WHITE%^S%^CYAN%^hro%^BLUE%^u%^CYAN%^d%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^flu%^WHITE%^i%^CYAN%^d mesh a%^BLUE%^r%^CYAN%^mor%^RESET%^");
   set_long("%^CYAN%^This supple suit of armor might, at a distance, be mistaken for an odd form of "
"chainmail.  At a closer look, however, it's quite obvious that it is actually formed of many long, thick "
"metal wires, all interlinked into a mesh that allows for uncharacteristic ease of movement.  The metal "
"itself appears to be %^WHITE%^%^BOLD%^mithril%^RESET%^%^CYAN%^, though somehow the metal has been tinted "
"throughout in a striking pattern of %^BOLD%^%^BLUE%^r%^CYAN%^ip%^WHITE%^p%^CYAN%^le%^BLUE%^s%^RESET%^"
"%^CYAN%^.  A fine lining of %^BLUE%^d%^CYAN%^y%^BLUE%^ed%^CYAN%^ cloth lies beneath the layer of metal, "
"softening the impact of the armor upon the wearer's skin.  The metal itself is cool to the touch, and "
"leaves a strangely %^BLUE%^damp%^CYAN%^ feeling upon anything that touches it, though no liquid is visibly "
"present.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Rumours abound concerning this armor and the clergy of the Mother of Water.  "
"The most common tells that the mesh is drawn forth by powerful rituals from springs sacred to Istishia, and "
"carries within it the pure essence of water itself.");
   set_property("lore difficulty",7);
   set_remove("%^WHITE%^%^BOLD%^You feel the protection of the waters recede as you remove the armor.");
   set_size(2);
   set_property("enchantment",2);
}

int wear_fun() {
   if((string)TP->query_diety() != "istishia") {
     tell_object(ETO,"%^WHITE%^%^BOLD%^The armor refuses to fit you!");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" tries to force the armor on, but fails.",ETO);
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^You are filled with confidence as you slide into the armor.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" slides into the armor with an air of assurance.",ETO);
   return 1;
}