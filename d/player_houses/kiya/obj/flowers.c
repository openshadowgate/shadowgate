#include <std.h>
#include <daemons.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("moonflowers");
   set_id(({"moonflowers","flowers","bunch"}));
   set_short("%^WHITE%^%^BOLD%^m%^RESET%^%^WHITE%^oo%^BOLD%^nf%^RESET%^%^WHITE%^lo%^BOLD%^we%^RESET%^%^WHITE%^rs%^RESET%^");
   set_long((:TO,"long_desc":));
   set_weight(1);
   set_value(50);
   set_cointype("silver");
}

void init(){ 
  ::init(); 
  set_long((:TO, "long_desc":)); 
}

string long_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^This is a small bunch of %^WHITE%^soft white flowers%^GREEN%^, wrapped in slender "
"vines.  The large, five-petaled blossoms lay open, releasing a %^MAGENTA%^sweet%^GREEN%^ fragrance into "
"the air around you.%^RESET%^");
   }
   return("%^GREEN%^This is a small bunch of %^WHITE%^soft white flowers%^GREEN%^, wrapped in slender "
"vines.  The large blossoms are all closed.%^RESET%^");
}
