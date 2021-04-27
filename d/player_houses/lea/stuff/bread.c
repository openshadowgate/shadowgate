inherit "/std/food.c";
#include <std.h>
void create(){
   ::create();
  set_name("bread");
  set_id("bread");
  set_short("bread");
  set_long("This is a small slice of toasted bread which would be a perfect "+
		"accompaniment to the cheeses on the tray.");
  set_destroy();
  set_strength(5);
  set_my_mess("You bite into the bread and are assaulted by an loud crunch and an "+
		"explosion of bread crumbs.");
  set_your_mess("crunches noisily on the bread.");
  }











