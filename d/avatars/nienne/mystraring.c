#include <std.h>
inherit ARMOUR;
int tracker;

void create(){
   ::create();
   set_name("ring");
   set_id(({"ring of protection","band","ring","plain ring","translucent
ring",""}));
   set_short("%^RESET%^a plain translucent ring");
   set_obvious_short("%^RESET%^a plain translucent ring");
   set_long("%^CYAN%^This simple ring seems rather plain compared to most. It "
"consists of a %^WHITE%^transparent band %^CYAN%^of some translucent gemstone "
"- perhaps chalcedony or quartz. No scratches mar its surface, and no "
"shattered flaws mark the inner surface of the gem - the jewelry is perfectly "
"flawless, if not remarkable in any other way.%^RESET%^\n");
   set_lore("This ring was crafted many, many centuries ago, by elven high "
"magic, in the years before the drow ever descended from the surface. It was "
"a great gift to the high priestess of the Mystran temple of Elus'dore, for "
"their combined aid in the crafting of a mighty warding spell, to protect the "
"great elven civilization. The ring was said to be imbued with the very "
"energies of the night skies, but would only respond to one truly blessed by "
"the faith.\n");
   set_property("lore difficulty",19);
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_weight(2);
   set_size(2);
   set_ac(0);
   set_value(2500);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   tracker = 0;
}

void init() {
   ::init();
//   add_action("stab_fun","stab");
}

int wear_fun(){
   object *stuff;
   int i,j, flag;
   if((string)ETO->query_diety() != "mystra" && !avatarp(ETO)) return 1;

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
     tell_object(ETO,"Conflicting magic within another of your items prevents you from wearing this.");
     return 0;
   }
/*   if((int)ETO->query_highest_level() < 35) {
     tell_object(ETO,"The ring doesn't fit your finger.");
     return 0;
   } */

   tell_room(EETO,"%^BOLD%^%^CYAN%^Br%^WHITE%^i%^CYAN%^llia%^WHITE%^n%^CYAN%^t"
" %^RESET%^%^CYAN%^flecks of light sparkle across the ring's surface, as it "
"darkens to a deep %^BLUE%^midnight blue%^CYAN%^.%^RESET%^");
   TO->set_property("enchantment",4);
   while ((int)TO->query_property("enchantment") != 4) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",4);
   }
   TO->set_short("%^RESET%^%^BLUE%^Band of the %^BOLD%^%^CYAN%^N%^WHITE%^i%^CYAN%^ght S%^WHITE%^k%^CYAN%^y%^RESET%^");
   TO->set_obvious_short("%^RESET%^%^BLUE%^a %^BOLD%^%^CYAN%^s%^WHITE%^p%^CYAN%^arkl%^WHITE%^i%^CYAN%^ng %^RESET%^%^BLUE%^cobalt ring%^RESET%^");
   TO->set_long("%^CYAN%^This gorgeous ring seems to have been shaped from a "
"solid piece of some %^BLUE%^deep cobalt gemstone%^CYAN%^, though it's beyond "
"you to imagine what kind. No flaw marks the clear surface either within or "
"without, but glittering%^BOLD%^%^WHITE%^ "
"whi%^CYAN%^t%^WHITE%^e%^RESET%^%^CYAN%^ and "
"%^WHITE%^s%^BOLD%^i%^RESET%^lv%^BOLD%^e%^RESET%^r %^CYAN%^motes have been "
"somehow threaded through its depths, giving the impression of%^YELLOW%^ "
"lights %^RESET%^%^CYAN%^or %^BOLD%^%^WHITE%^stars %^RESET%^%^CYAN%^embedded "
"within the gemstone itself.%^RESET%^\n");
   tracker = 1;
   return 1;
}

int remove_fun(){
   if(tracker) {
     TO->remove_property("enchantment");
     set_short("%^RESET%^a plain translucent ring");
     set_obvious_short("%^RESET%^a plain translucent ring");
     set_long("%^CYAN%^This simple ring seems rather plain compared to most. "
"It consists of a %^WHITE%^transparent band %^CYAN%^of some translucent "
"gemstone - perhaps chalcedony or quartz. No scratches mar its surface, and "
"no shattered flaws mark the inner surface of the gem - the jewelry is "
"perfectly flawless, if not remarkable in any other way.%^RESET%^\n");
     tell_room(EETO,"%^CYAN%^The ring dulls and becomes nothing more than "
"%^WHITE%^transparent gemstone%^CYAN%^.%^RESET%^");
     tracker = 0;
   }
   return 1;
}

int stab_fun(string str) {
   if(!TP->is_class("thief")) return 0;
   if((string)TP->query_deity() != "mystra") return 0;
   if(!str) return 0;
   if(!TO->query_worn()) return 0;
   if(sizeof(TP->query_attackers()) > 0) return 0;
   if(random(5)) return 0;

   if (present(str,EETO) && sizeof(TP->query_wielded())) {
     tell_room(ETP,"%^CYAN%^A pale luminescence appears around "+TP->QCN+"'s "
"weapon as "+TP->QS+" strikes!%^RESET%^",TP);
     tell_object(TP,"%^CYAN%^A pale emerald luminescence appears around your "
"weapon as you strike!%^RESET%^");
   }
   return 0;
}
