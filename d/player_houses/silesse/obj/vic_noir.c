inherit "/std/drink.c";

#include <std.h>

void create(){
   ::create();
   set_name("wine");
   set_id(({"wine","glass of wine","pinot noir","pinot noir wine","glass of pinot noir","drink"}));
   set_strength(30);
   set_weight(1);
   set_type("alcoholic");
   set_empty_name("glass");
   set_short("A glass of %^BOLD%^%^BLACK%^pinot noir%^RESET%^");
   set_destroy();
   set_long("This delicate glass is filled with a sultry %^RED%^dark red%^RESET%^ "+
      "fragrant wine that blooms with the fragrance of %^BOLD%^%^BLACK%^bl%^RED%^"+
      "a%^BLACK%^ck ch%^RED%^e%^BLACK%^rry%^RESET%^ and %^BOLD%^%^RED%^raspberry%^RESET%^.");
   set_my_mess("The fruity taste of the wine is subtly seductive.");
   set_your_mess("sips the wine and hums softly.");
}
