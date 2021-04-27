#include <std.h>
inherit "/d/magic/obj/mirror.c";

create() {
   ::create();
   set_name("smoke");
   set_id(({"mirror","smoke", "smokescreen","smokescreen-obj"}));
   set_short("%^BOLD%^%^BLACK%^hazy smokescreen%^RESET%^");
   set_property("no animate", 1);
   set_long((:TO,"smoke_desc":));
   set("value", 1001);
   set_weight(100000);
   set_no_clean(1);
}

int get() { return 0; }
int drop() { return 1; }

string smoke_desc(){
   if(TO->query_property("magic mirror")) {
     return("%^RESET%^Thick %^BOLD%^%^BLACK%^smo%^RESET%^k%^BOLD%^%^BLACK%^e%^RESET%^ rises from the fire, "
"cast this way and that as it dissipates on the %^CYAN%^br%^BOLD%^e%^RESET%^%^CYAN%^eze%^RESET%^.  A faint, "
"ethereal %^BOLD%^%^WHITE%^sh%^RESET%^i%^BOLD%^%^WHITE%^mm%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^ runs through "
"the dark haze, as though you can almost see the outline of shapes moving within.");
   }
   return("%^RESET%^Thick %^BOLD%^%^BLACK%^smo%^RESET%^k%^BOLD%^%^BLACK%^e%^RESET%^ rises from the fire, "
"cast this way and that as it dissipates on the %^CYAN%^br%^BOLD%^e%^RESET%^%^CYAN%^eze%^RESET%^.");
}
