#include <std.h>
inherit ARMOUR;

int tracker;

void create() {
   ::create();
   set_name("brow-gem");
   set_id(({"bane gem","browgem","brow-gem","mark of the dreadmaster","black gem","mark","dreadmaster mark","black brow-gem","flawless black brow-gem"}));
   set_short("%^BLACK%^%^BOLD%^Mark of the Dr%^GREEN%^e%^BLACK%^ad Tal%^GREEN%^o%^BLACK%^n%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^flawless black brow-gem%^RESET%^");
   set_long("%^CYAN%^This single, perfect gem is commonly known as a %^BLACK%^%^BOLD%^black "
"sapphire%^RESET%^%^CYAN%^.  It has been shaped with step-cut facets, to clearly show the deep black hue "
"of the stone, reflecting only %^BLACK%^%^BOLD%^darkness%^RESET%^%^CYAN%^ from any light.  A fine border "
"of %^WHITE%^silver%^CYAN%^ metal outlines the gem, with a flat surface upon the underside.  Such gems "
"are commonly worn upon the brow, attached only by magical means and displayed as a sign of the wearer's "
"status.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Very few rumours circulate about this gem and the clergy of the Black Lord.  The "
"only one of any real truth, says that it is the marking of the members of a semi-secret guild within the "
"Banite order, known as the Talons of Darkness.  They are said to operate as the eyes, ears and hands of the "
"clergy, at times and in places where they would not otherwise be able to go.  It is considered an extremely "
"high honour within the faith to be accepted into the group, as only the most faithful and zealous of the "
"Tyrant's followers are ever offered the chance.");
   set_property("lore difficulty",7);
   set_limbs(({"head"}));
   set_weight(1);
   set_value(10000);
   set_ac(2);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   tracker = 1;
}

int drop(){ return 1; }

int wear_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^You feel the %^RESET%^%^GREEN%^dr%^BOLD%^ea%^WHITE%^d "
"m%^GREEN%^ig%^RESET%^%^GREEN%^ht%^BLACK%^%^BOLD%^ of the Tyrant as the gem adheres to your "
"forehead.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" smiles %^RESET%^%^GREEN%^co%^BOLD%^nf%^WHITE%^ide%^GREEN%^nt"
"%^RESET%^%^GREEN%^ly %^BLACK%^%^BOLD%^as the gem adheres to "+ETO->QP+" forehead.%^RESET%^",ETO);
   while ((int)TO->query_property("enchantment") != (-1)) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",(-1));
   }
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^You feel the power of the Black Hand recede as you remove the "
"brow-gem.%^RESET%^");
   return 1;
}

void init() {
   ::init();
   add_action("stab_fun","stab");
   add_action("wopme_fun","twop");
}

int stab_fun(string str) {
   if(!TP->is_class("thief")) return 0;
   if(!str) return 0;
   if(!TO->query_worn()) return 0;
   if(sizeof(TP->query_attackers()) > 0) return 0;
   if(!random(4)) return 0;

   if (present(str,EETO) && sizeof(TP->query_wielded())) {
     tell_room(ETP,"%^BLACK%^%^BOLD%^"+TP->QCN+"'s weapons take on a %^RESET%^%^GREEN%^dull glow %^BLACK%^"
"%^BOLD%^as "+TP->QS+" strikes!%^RESET%^",TP);
     tell_object(TP,"%^BLACK%^%^BOLD%^Your weapons take on a %^RESET%^%^GREEN%^dull glow %^BLACK%^%^BOLD%^as "
"you strike!%^RESET%^");
   }
   return 0;
}

int wopme_fun() {
   if(!objectp(TO)) return 0;
   if(!objectp(TP)) return 0;
   if(!avatarp(TP)) return 0;
   if(!TO->query_worn()) return 0;
   if(ETP->is_temple() && (string)ETP->query_diety() == "bane"){
      tell_object(TP,"You are already in your temple!");
      return 1;
   }
   tell_object(TP,"%^BOLD%^%^BLACK%^You step back into a whirl of "
"%^RESET%^%^MAGENTA%^sil%^BOLD%^k%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^, "
"calling upon your shadowdance to carry you safely away!%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+TPQCN+" steps back "
"gracefully and draws the %^RESET%^%^MAGENTA%^sil%^BOLD%^k%^RESET%^"
"%^MAGENTA%^s%^BOLD%^%^BLACK%^ of her garments about her in a whirl. "
+capitalize(TP->QP)+" eyes %^RESET%^%^RED%^gl%^MAGENTA%^i%^RED%^tt%^MAGENTA%^e"
"%^RED%^r %^BOLD%^%^BLACK%^%^as a smirk crosses "+TP->QP+" lips, and "
+TP->QS+" disappears!%^RESET%^",TP);
   tell_room(find_object_or_load("/d/magic/temples/bane"),"%^BOLD%^"
"%^BLACK%^A whirling shade of %^RESET%^%^MAGENTA%^sil%^BOLD%^k%^RESET%^"
"%^MAGENTA%^s%^BOLD%^%^BLACK%^ solidifies before you into "+TPQCN+"%^BOLD%^%^BLACK%^!%^RESET%^",TP);
   TP->move_player("/d/magic/temples/bane");
   return 1;
}
