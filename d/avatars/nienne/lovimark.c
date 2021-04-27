#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("mark");
   set_id(({"mark","lovite mark","burn","burnt marking","marking"}));
   set_short((:TO,"short_fun":));
   set_long("%^BOLD%^%^WHITE%^Upon her brow is a%^RESET%^%^RED%^ dull red mark %^BOLD%^%^WHITE%^that looks as "
"though it were burnt there somehow.  It depicts a %^BOLD%^%^BLACK%^nine-stranded barbed whip %^BOLD%^%^WHITE%^"
"in surprising detail - the holy symbol of Loviatar.%^RESET%^\n");
   set_limbs(({"head"}));
   set_weight(0);
   set_value(0);
   set_ac(1);
   set_property("enchantment",-1);
   set_type("ring");
   set_wear("%^RED%^%^BOLD%^A faint twinge of pain reminds you of the Maiden's own mark upon your forehead.%^RESET%^");
}

int drop(){ return 1; }

int short_fun() {
   if (!userp(ETO)) return("");
   if ((string)TP->query_diety() == "loviatar") return("%^RESET%^%^RED%^a burnt marking%^RESET%^");
   else return ("");
}
