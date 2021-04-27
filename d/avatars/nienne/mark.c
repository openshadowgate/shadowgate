#include <std.h>
inherit ARMOUR;

string adj,race;
int activate_fun(string str);
int deactivate_fun(string str);

void create(){
   ::create();
   set_name("tattoo");
   set_id(({ "tattoo","mark","mark of the wild","swirling tattoo" }));
   set_short("%^RESET%^%^GREEN%^M%^BLUE%^ar%^GREEN%^k o%^BLUE%^f t%^GREEN%^he %^BLUE%^wi%^GREEN%^ld%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^a small swi%^GREEN%^r%^ORANGE%^ling tat%^RED%^t%^ORANGE%^oo%^RESET%^");
   set_long("%^ORANGE%^This is an odd little tattoo, about an inch in size.  It is painted with %^GREEN%^green "
"%^ORANGE%^and %^RED%^ochre %^ORANGE%^ink, in some form of a swirling glyph that you don't know the meaning "
"of.  Oddly enough, it seems to %^WHITE%^glow %^ORANGE%^just faintly.%^RESET%^\n");
   set_weight(0);
   set_value(0);
   set_lore("%^WHITE%^%^BOLD%^Mark of the Beast.%^RESET%^");
   set_property("lore difficulty",14);
   set_type("ring");
   set_limbs(({"neck"}));
   set_size(2);
   set_ac(0);
   set_remove((:TO,"remove_fun":));
}

void init() {
   ::init();
   if(!interactive(ETO)) return;
   if(interactive(TP) && TP == environment(TO)) set_size(TP->query_size());
   add_action("activate_fun","activate");
   add_action("deactivate_fun","deactivate");
}

int remove_fun() {
   if((string)ETO->query_race() == "lupine") {
     TO->deactivate_fun("mark");
   }
   return 1;
}

int activate_fun(string str) {
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(!userp(ETO)) return 0;
   if(!TO->query_worn()) return 0;
   if(!str) return 0;
   if(str != "mark") {
     tell_object(ETO,"What do you want to activate?");
     return 0;
   }
   if((string)ETO->query_race() == "lupine") {
     tell_object(ETO,"You are already shapeshifted.");
     return 0;
   }
   tell_object(ETO,"You turn into a wolf!");
   adj = ETO->getDescriptivePhrase();
   race = ETO->query_race();
   ETO->set_race("lupine");
   ETO->new_body();
   ETO->setDescriptivePhrase("%^BOLD%^%^BLACK%^dark-furred $R figure%^RESET%^");
   return 1;
}

int deactivate_fun(string str) {
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(!userp(ETO)) return 0;
   if(!TO->query_worn()) return 0;
   if(!str) return 0;
   if(str != "mark") {
     tell_object(ETO,"What do you want to activate?");
     return 0;
   }
   if((string)ETO->query_race() != "lupine") {
     tell_object(ETO,"You are not shapeshifted.");
     return 0;
   }
   tell_object(ETO,"You turn back into yourself!");
   ETO->setDescriptivePhrase(adj);
   ETO->set_race(race);
   ETO->new_body();
   return 1;
}
