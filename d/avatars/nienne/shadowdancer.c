#include <std.h>
inherit "/d/common/obj/armour/studded";

void create(){
   ::create();
   set_id(({"leather","studded","studded leather","mottled studded","mottled leather","mantle","mantle of the shadowdancer"}));
   set_short("%^BOLD%^%^BLACK%^Ma%^RESET%^%^ORANGE%^nt%^BOLD%^%^BLACK%^le of the Sh%^RESET%^a%^BOLD%^%^BLACK%^dowd%^RESET%^a%^BOLD%^%^BLACK%^ncer%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^dar%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^ly m%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^tt%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^ed studded leather%^RESET%^");
   set_long("From a distance, this leather suit looks rather %^CYAN%^mu"
"%^GREEN%^n%^CYAN%^da%^GREEN%^n%^CYAN%^e%^RESET%^, colored as it is in "
"%^BOLD%^%^BLACK%^dar%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^ly m%^RESET%^"
"%^ORANGE%^o%^BOLD%^%^BLACK%^tt%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^ed "
"%^RESET%^shades of %^BOLD%^%^BLACK%^gray %^RESET%^and %^ORANGE%^brown"
"%^RESET%^. %^BLUE%^Pale metal studs %^RESET%^have been placed at even "
"intervals across its surface, dulled so as not to reflect any %^BOLD%^"
"%^WHITE%^lig%^YELLOW%^h%^WHITE%^t%^RESET%^. A closer look reveals it to be "
"deliberately patterned in these dark shades, to perfectly %^GREEN%^b%^BOLD%^l"
"%^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^%^GREEN%^d %^RESET%^into any %^BOLD%^"
"%^BLACK%^shadow %^RESET%^or %^BLUE%^darkened corner%^RESET%^. The suit "
"itself is quite sturdy, and would protect a wearer well, although it seems a "
"little %^MAGENTA%^lighter %^RESET%^in weight than its appearance would "
"suggest.\n");
   set_lore("A similar item as this is recorded in ancient high elven lore, "
"as a precious magical item gifted to Ellarion Darmyr. As leader of a "
"specialized unit of elven scouts, he often led these skilled elves in "
"dangerous missions to protect his home city. For many decades he was "
"renowned to be unmatched in skill at blades, though the tales say that he "
"was lost to underdark on one such mission, and never returned.");
   set_property("lore difficulty",24);
   set_size(2);
   set_weight(20);
   set_value(6500);
   set_property("enchantment",4);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun() {
   if(!ETO->is_class("thief") && !ETO->is_class("ranger")) {
     notify_fail("The mottled leather seems not to fit you!\n");
     return 0;
   }
   if(ETO->query_highest_level() < 30) {
     notify_fail("The mottled leather seems not to fit you!\n");
     return 0;
   }
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" slips the suit of l%^RESET%^"
"%^ORANGE%^e%^BOLD%^%^BLACK%^ath%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r on "
"with a look of confidence.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^You slip the suit of l%^RESET%^%^ORANGE%^"
"e%^BOLD%^%^BLACK%^ath%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r on, already "
"feeling more secure in its concealments.%^RESET%^");
   ETO->setenv("MINVIS","%^BOLD%^%^BLACK%^$N disappears into the shadows "
"right before your eyes.%^RESET%^");
   ETO->setenv("MVIS","%^BOLD%^%^BLACK%^$N suddenly appears beside "
"you.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" removes the l%^RESET%^"
"%^ORANGE%^e%^BOLD%^%^BLACK%^ath%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r armor "
"and looks around cautiously.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^You remove the l%^RESET%^%^ORANGE%^"
"e%^BOLD%^%^BLACK%^ath%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r armor, already "
"feeling revealed and vulnerable without it.%^RESET%^");
   ETO->setenv("MINVIS","$N seems to disappear.");
   ETO->setenv("MVIS","$N appears out of the corner of your eye.");
   return 1;
}

void init() {
   ::init();
   add_action("stab_fun","stab");
}

int stab_fun(string str) {
   if(!TP->is_class("thief")) return 0;
   if(!str) return 0;
   if(sizeof(TP->query_attackers())) return 0;
   if(!TO->query_worn()) return 0;
   if(!random(3)) return 0;

   if (present(str,EETO) && sizeof(TP->query_wielded())) {
     tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" appears without warning "
"from the %^RESET%^sh%^BOLD%^%^BLACK%^ado%^RESET%^ws %^BOLD%^%^BLACK%^to "
"strike!%^RESET%^",TP);
     tell_object(TP,"%^BOLD%^%^BLACK%^You slip through the %^RESET%^sh"
"%^BOLD%^%^BLACK%^ado%^RESET%^ws %^BOLD%^%^BLACK%^to strike without warning "
"at your foe!%^RESET%^");
   }
   return 0;
}

int struck_fun(int damage,object what,object who){
   if(!random(4)){
     tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" seems to %^RESET%^%^CYAN%^ "
"va%^RESET%^n%^CYAN%^ish %^BOLD%^%^BLACK%^as "+who->QCN+" strikes at "
+ETO->QO+", only to reappear beside "+who->QO+" and launch another "
"attack!%^RESET%^",({ETO,who}));
     tell_object(ETO,"%^BOLD%^%^BLACK%^You slip into the shadows to %^RESET%^"
"%^CYAN%^va%^RESET%^n%^CYAN%^ish %^BOLD%^%^BLACK%^from view as "+who->QCN+
" strikes at you, and launch another surprise attack!%^RESET%^");
     tell_object(who,"%^BOLD%^%^BLACK%^"+ETOQCN+" seems to %^RESET%^%^CYAN%^"
"va%^RESET%^n%^CYAN%^ish %^BOLD%^%^BLACK%^as you strike at "+ETO->QO+", only "
"to reappear beside you and launch another attack!%^RESET%^");
     ETO->execute_attack();
   }
}
