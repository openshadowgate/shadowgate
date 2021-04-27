#include <std.h>
inherit PARMOUR;

int OWNED;
string owner;

void create() {
   ::create();
   set_name("%^RESET%^%^BLUE%^blue robes%^RESET%^");
   set_id(({"robe","robes","blue robes","soft robes","soft blue robes","Robes","linen robes","robes of the dweomerkeeper","robe of the dweomerkeeper"}));
   set_short("%^RESET%^%^BLUE%^Robes of the Dw%^BOLD%^e%^RESET%^%^BLUE%^ome%^BOLD%^r%^RESET%^%^BLUE%^kee%^BOLD%^p%^RESET%^%^BLUE%^er%^RESET%^");
   set_obvious_short("%^RESET%^%^BLUE%^s%^BOLD%^o%^RESET%^%^BLUE%^ft bl%^BOLD%^u%^RESET%^%^BLUE%^e ro%^BOLD%^b%^RESET%^%^BLUE%^es%^RESET%^");
   set_long("%^CYAN%^This small, simple garment looks quite old, though very well cared for.  Light linen "
"of a %^BLUE%^cob%^BOLD%^a%^RESET%^%^BLUE%^lt-b%^BOLD%^l%^RESET%^%^BLUE%^ue%^CYAN%^ shade has been "
"crafted in an archaic style of robe, complete with long billowing sleeves lined in%^WHITE%^%^BOLD%^ "
"white%^RESET%^%^CYAN%^, and identical lining around the curved neckline and hem.  Inside the cloth has "
"been stitched a carefully concealed pocket.  No other decoration marks the simple robes, save for a "
"single %^BOLD%^bl%^WHITE%^u%^CYAN%^e-wh%^WHITE%^i%^CYAN%^te%^RESET%^%^CYAN%^ star upon the back of the "
"garment.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^A long history follows these robes, since their creation for the well-known "
"gnomish illusionist Tasmar, nearly two centuries ago.  They were crafted and blessed by the Mother of "
"Magic, as a reward for Tasmar's efforts in both retrieving and scribing many precious writings concerning"
" spellcraft and the Weave.  The single blue-white star on the back represents the symbol of Mystra when "
"the garment was originally crafted; the symbol has since been changed to the seven stars commonly "
"depicted in most temples.");
   set_property("lore difficulty",16);
   set_limbs(({"torso"}));
   set_weight(8);
   set_value(5600);
   set_size(1);
   set_ac(1);
   set_property("enchantment",1);
   while(TO->query_property("enchantment")< 1){
     remove_property("enchantment");
     set_property("enchantment",1);
   }
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_max_internal_encumbrance(21);
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
     tell_object(ETO,"%^WHITE%^%^BOLD%^You feel Mystra's blessings as you wear the soft robes.");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" smiles and slips on the soft robes.",ETO);
     return 1;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^The robes refuse to fit you!");
   return 0;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel the magic within the robes recede as you remove them.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" looks disappointed to remove the soft robes.",ETO);
   return 1;
}