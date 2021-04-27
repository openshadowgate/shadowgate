#include <std.h>
inherit ARMOUR;

int OWNED;
string owner;

void create() {
   ::create();
   set_name("sandals");
   set_id(({"sandals","akadi sandals","azure sandals","silk sandals","sky stride","skystride"}));
   set_short("%^CYAN%^%^BOLD%^S%^WHITE%^k%^CYAN%^ys%^WHITE%^t%^CYAN%^ri%^WHITE%^d%^CYAN%^e%^RESET%^");
   set_obvious_short("%^CYAN%^%^BOLD%^azure silk sandals%^RESET%^");
   set_long("%^CYAN%^These two sandals are extremely light and comfortable.  Thin soles are formed by "
"nothing more than a multi-layered piece of cloth, dyed a %^WHITE%^soft grey hue%^CYAN%^.  The foot "
"itself is left almost bare, aside from a few strands of silk that criss-cross over the feet and around "
"the ankles.  The silken strands are a mixture of %^WHITE%^%^BOLD%^white%^RESET%^%^CYAN%^ and%^BOLD%^ "
"azure%^RESET%^%^CYAN%^ shades, that encircle the feet so softly they could almost be whisps of "
"air.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Rumours abound concerning these sandals and the clergy of the Queen of Air. "
" The most prevalent tells that sandals such as these are plucked from the winds themselves, and shaped "
"into sandals by the most powerful of clerical magics.");
   set_property("lore difficulty",7);
   set_weight(2);
   set_value(0);
   set_ac(1);
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_wear((:TO,"wear_fun":));
   set_remove("%^WHITE%^%^BOLD%^You feel the touch of the winds dissipate as you remove the sandals.");
}

int wear_fun() {
   if((string)TPQN != owner) {
     tell_object(ETO,"%^WHITE%^%^BOLD%^The sandals refuse to fit your feet!");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" tries to force the sandals onto "+ETO->QP+" feet, but "
"fails.",ETO);
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel the touch of your god carried within the sandals.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" slides the sandals onto "+ETO->QP+" feet with a look of "
"pride.",ETO);
   return 1;
}

void init() {
   ::init();
   if(!interactive(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !OWNED) {
     owner = TPQN;
     OWNED = 1;
     set_size(TP->query_size());
   }
}