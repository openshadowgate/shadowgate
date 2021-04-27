inherit "/std/drink.c";

#include <std.h>

void create(){
   ::create();
   set_name("wine");
   set_id(({"wine","glass of wine","chardonnay","chardonnay wine","glass of chardonnay","drink"}));
   set_strength(30);
   set_weight(1);
   set_type("alcoholic");
   set_empty_name("glass");
   set_short("A glass of %^BOLD%^%^WHITE%^chardonnay%^RESET%^");
   set_destroy();
   set_long("This delicate glass is filled with a %^BOLD%^crystalline "+
      "liquid%^RESET%^ that seems to gather the light. A slight hint of "+
      "green apple rises from the glass, mingling with the scent of "+
      "fragrant grapes.");
   set_my_mess("The light, crisp flavor of green apple lingers on your tongue.");
   set_your_mess("sips the wine with a smile.");
}
