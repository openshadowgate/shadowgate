#include <std.h>
inherit ARMOUR;

int OWNED;
string owner;

void create() {
   ::create();
   set_name("necklace");
   set_id(({"necklace","auril necklace","blossom","blizzard blossom","blizzard's blossom"}));
   set_short("%^CYAN%^%^BOLD%^Bl%^WHITE%^i%^CYAN%^zza%^WHITE%^r%^CYAN%^d's Blo%^WHITE%^s%^CYAN%^som%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^snowflake charm necklace%^RESET%^");
   set_long("%^CYAN%^Small, perfectly-formed links of %^WHITE%^%^BOLD%^silver%^RESET%^%^CYAN%^ form the "
"necklace of this piece of jewelry.  The highly-polished chain is linked behind the neck with a delicate "
"clasp, and falls down in the centre to support an ornate pendant in the shape of a snowflake.  "
"Finely-wrought %^WHITE%^%^BOLD%^silver%^RESET%^%^CYAN%^ filigree forms the base of the pendant, which is "
"set with tiny flecks of %^WHITE%^diamond%^CYAN%^, giving it a glittering quality as though it were "
"actually made of %^BOLD%^i%^WHITE%^c%^CYAN%^e%^RESET%^%^CYAN%^.%^RESET%^\n");
   set_limbs(({"neck"}));
   set_weight(2);
   set_value(0);
   set_size(2);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
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

int wear_fun() {
   if((string)TPQN != owner) {
     tell_object(ETO,"%^WHITE%^%^BOLD%^The jewelry refuses to let you wear it!");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" tries to wear the jewelry, but fails.",ETO);
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel the Frostmaiden's blessings as you wear the necklace.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^A chill breeze brushes past you as "+ETOQCN+" wears the "
"necklace.",ETO);
   ETO->set_property("magic resistance",5);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel the frost's chill recede as you remove the necklace.");
   ETO->set_property("magic resistance",-5);
   return 1;
}
