inherit "/std/drink.c";

#include <std.h>

void create(){
   ::create();
   set_name("wine");
   set_id(({"wine","glass of wine","shiraz","shiraz wine","glass of shiraz","drink"}));
   set_strength(35);
   set_weight(1);
   set_type("alcoholic");
   set_empty_name("glass");
   set_short("A glass of %^RED%^shiraz%^RESET%^");
   set_destroy();
   set_long("This delicate glass is filled with a %^RED%^dark red%^RESET%^ "+
      "fragrant wine that gives off hints of %^MAGENTA%^violets %^RESET%^"+
      "and %^ORANGE%^chocolate%^RESET%^.");
   set_my_mess("A surprising hint of pepper brightens the flavor of the full-bodied wine.");
   set_your_mess("sips the wine, looking momentarily surprised.");
}
