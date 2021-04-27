inherit "/std/food.c";
#include <std.h>
void create(){
   ::create();
  set_name("cheese");
  set_id("cheese");
  set_short("%^YELLOW%^%^cheese%^RESET%^");
  set_long("The cheese has a flexible texture and smells wonderful.  Cut into cubes this "+
		"small bite will not be filling, but looks tasty.");
  set_destroy();
  set_strength(5);
  set_my_mess("You pop the yellow cube into your mouth and savor the taste.");
  set_your_mess("pops the yellow cube into their mouth.");
  }











