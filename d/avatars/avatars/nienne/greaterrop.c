#include <std.h>
inherit ARMOUR;

int morphflag, OWNED;
string owner;

void create() {
   ::create();
   set_name("adamantite ring");
   set_id(({"greater ring of protection","ring","rop","adamantite ring","ring of protection","ring of adamantite","glittering ring"}));
   set_short("%^BOLD%^%^WHITE%^Gre%^CYAN%^a%^WHITE%^ter Ring of "
"Prote%^CYAN%^c%^WHITE%^tion%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^gl%^RESET%^i%^BOLD%^%^WHITE%^tte"
"%^RESET%^r%^BOLD%^%^WHITE%^ing ring of adaman%^CYAN%^t%^WHITE%^ite%^RESET%^");
   set_long("Crafted from what appears to be pure %^BOLD%^%^WHITE%^adaman"
"%^CYAN%^t%^WHITE%^ite%^RESET%^, this ring seems utterly immune to "
"%^RED%^he%^MAGENTA%^a%^RED%^t %^RESET%^or %^GREEN%^damage%^RESET%^, making "
"you wonder how anyone managed to craft it into shape in the first place. It "
"forms a narrow circle with a flawless surface that has been polished to a "
"%^YELLOW%^br%^RESET%^%^ORANGE%^i%^YELLOW%^lli%^RESET%^%^ORANGE%^a%^YELLOW%^"
"nt %^RESET%^sheen. Upon the underside, invisible when the ring is worn, "
"small %^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^u%^BOLD%^n%^RESET%^%^CYAN%^e"
"%^BOLD%^s %^RESET%^have been etched into the underside in smooth lines.");
   set_lore("Such a ring as this is known to be an ancient artifact, crafted "
"by high elven magic before the time of the crown wars. Among the myriad of "
"magical creations attributed to their skill is this one, said to be a far "
"more powerful version of the ring of protection, which are common throughout "
"the realm. The magic needed to create such a powerful variant were long lost "
"following the crown wars and the resulting division of the elves.\n");
   set_property("lore difficulty",18);
   set_type("ring");
   set_ac(0);
   set_weight(2);
   set_value(25000);
   set_limbs(({"right hand","left hand"}));
   set_property("enchantment",6);
   set_wear((:TO,"do_wear":));
   set_remove((:TO,"do_remove":));
   morphflag = 0;
}

void init() {
   ::init();
   if(!interactive(ETO) || avatarp(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !OWNED && !avatarp(TP)) {
     owner = TPQN;
     OWNED = 1;
   }
}

int do_wear() {
   object *stuff;
   int i,j, flag;

   stuff = ETO->all_armour();
   j = sizeof(stuff);
   for(i=0;i<j;i++) {
     if(!objectp(stuff[i])) continue;
     if((string)stuff[i]->query_type() == "ring") {
       if(member_array("ring of protection",stuff[i]->query_id()) != -1) {
         flag = 1;
         break;
       }
     }
   }
   if(flag) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^The magic of the ring already worn prevents you from wearing this one!%^RESET%^");
     return 0;
   }
   if(ETO->query_property("amorpha")) {
     tell_object(ETO,"%^YELLOW%^The runes upon the ring's underside take on a "
"%^RESET%^%^CYAN%^dim glow %^YELLOW%^as you slip the ring on.%^RESET%^");
     tell_room(EETO,"%^YELLOW%^The runes upon the ring's underside take on a "
"%^RESET%^%^CYAN%^dim glow %^YELLOW%^as "+ETO->QCN+" slips the ring "
"on.%^RESET%^",ETO);
   }
   else {
     tell_object(ETO,"%^YELLOW%^The runes upon the ring's underside take on a "
"%^RESET%^%^CYAN%^br%^BOLD%^i%^RESET%^%^CYAN%^ght gl%^BOLD%^o%^RESET%^%^CYAN%^"
"w %^YELLOW%^as you slip the ring on.%^RESET%^");
     tell_room(EETO,"%^YELLOW%^The runes upon the ring's underside take on a "
"%^RESET%^%^CYAN%^br%^BOLD%^i%^RESET%^%^CYAN%^ght gl%^BOLD%^o%^RESET%^%^CYAN%^"
"w %^YELLOW%^as "+ETO->QCN+" slips the ring on.%^RESET%^",ETO);
     ETO->set_missChance(10);
     ETO->set_property("amorpha",1);
     morphflag = 1;
   }
   ETO->set_property("magic resistance",10);
   return 1;
}

int do_remove() {
   if(morphflag) {
     tell_object(ETO,"%^YELLOW%^The runes beneath the ring lose their "
"%^RESET%^%^CYAN%^br%^BOLD%^i%^RESET%^%^CYAN%^ght gl%^BOLD%^o%^RESET%^%^CYAN%^"
"w%^YELLOW%^.%^RESET%^");
     tell_room(EETO,"%^YELLOW%^The runes beneath the ring lose their "
"%^RESET%^%^CYAN%^br%^BOLD%^i%^RESET%^%^CYAN%^ght gl%^BOLD%^o%^RESET%^%^CYAN%^"
"w %^YELLOW%^as "+ETO->QCN+" removes it.%^RESET%^",ETO);
     ETO->set_missChance(0);
     ETO->remove_property("amorpha");
     morphflag = 0;
   }
   else {
     tell_object(ETO,"%^YELLOW%^The runes beneath the ring lose their "
"%^RESET%^%^CYAN%^dim glow%^YELLOW%^.%^RESET%^");
     tell_room(EETO,"%^YELLOW%^The runes beneath the ring lose their "
"%^RESET%^%^CYAN%^dim glow%^YELLOW%^ as "+ETO->QCN+" removes "
"it.%^RESET%^",ETO);
   }
   ETO->set_property("magic resistance",-10);
   return 1;
}
