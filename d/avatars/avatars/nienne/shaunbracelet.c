#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("bracelet");
   set_id(({"bracelet","shaundakul bracelet","bracelet of the winds","bracelet of winds","jasper bracelet","silk-draped bracelet"}));
set_short("%^BLACK%^%^BOLD%^Br%^WHITE%^a%^BLACK%^c%^WHITE%^el%^CYAN%^e%^WHITE%^t o%^CYAN%^f %^WHITE%^t%^CYAN%^he %^RESET%^%^CYAN%^W%^BOLD%^i%^RESET%^%^MAGENTA%^n%^CYAN%^d%^BOLD%^s%^RESET%^");
 set_obvious_short("%^WHITE%^%^BOLD%^si%^BLACK%^l%^WHITE%^k-dr%^CYAN%^a%^WHITE%^ped %^RESET%^%^CYAN%^ja%^MAGENTA%^s%^CYAN%^per bra%^BLUE%^c%^CYAN%^elet%^RESET%^");
    set_long("%^CYAN%^Tiny beads of sparkling %^MAGENTA%^pu%^WHITE%^r%^MAGENTA%^ple "
"j%^BLUE%^a%^MAGENTA%^sp%^CYAN%^%^BOLD%^e%^RESET%^%^MAGENTA%^r%^CYAN%^ forms this loose-fitting "
"bracelet.  Slender, interwoven strands of %^WHITE%^white thread%^CYAN%^ link the beads together, allowing "
"it to be comfortably resized.  Between each bead, a long slender length of silk has been threaded, forming "
"draped threads that sway softly in the winds.  The soft, varied hues of the silken strands mimic all the "
"colours of the sky, from the %^BOLD%^so%^WHITE%^f%^CYAN%^t sp%^WHITE%^r%^CYAN%^ing%^RESET%^%^CYAN%^ morning "
"to the %^BLACK%^%^BOLD%^cl%^RESET%^%^WHITE%^o%^BLACK%^%^BOLD%^udy "
"%^RESET%^%^WHITE%^a%^BLACK%^%^BOLD%^utu%^RESET%^%^WHITE%^m%^BLACK%^%^BOLD%^n "
"%^RESET%^%^CYAN%^dusk.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Rumours abound concerning this jewelry and the clergy of Shaundakul.  "
"The most common tells that the strands from the anklet are crafted from the winds and the clouds "
"themselves, and are only ever found by what seems like chance, by the faithful of the church.");
   set_property("lore difficulty",7);
   set_weight(1);
   set_value(800);
   set_ac(0);
   set_type("ring");
   set_limbs(({"left arm"}));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

void init() {
   ::init();
   add_action("whirl_fun","whirl");
}

int wear_fun() {
   if((string)ETOQN != "ozymandias") {
     tell_object(ETO,"%^WHITE%^%^BOLD%^The jewelry refuses to let you wear it!");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" tries to wear the jewelry, but fails.",ETO);
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel the blessings of the winds as you wear the special jewelry.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" seems to become more confident as "+ETO->QS+" wears the "
"jewelry.",ETO);
   ETO->add_attack_bonus(1);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel the touch of the winds dissipate as you remove the bracelet.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^The strands of silk sway lightly as "+ETOQCN+" removes "+ETO->QP+
" bracelet.",ETO);
   ETO->add_attack_bonus(-1);
   return 1;
}

void whirl_fun(string str) {
   if(!objectp(TP)) return 0;
   if(!TP->is_class("ranger")) return 0;
   if(!TO->query_worn()) return 0;
   if(!sizeof(TP->query_attackers())) return 0;
   if(!sizeof(TP->query_wielded())) return 0;
   if(random(4)) return 0;

   tell_room(ETP,"%^CYAN%^The %^BOLD%^w%^WHITE%^i%^CYAN%^nds %^RESET%^%^CYAN%^pick up "
"around "+TP->QCN+" as "+TP->QS+" strikes, leading "+TP->QP+" weapons in%^MAGENTA%^ "
"graceful %^CYAN%^strokes!%^RESET%^",TP);
   tell_object(TP,"%^CYAN%^The %^BOLD%^w%^WHITE%^i%^CYAN%^nds %^RESET%^%^CYAN%^pick up "
"around you as you spin, leading your weapons in %^MAGENTA%^graceful "
"strokes!");
   return 0;
}
