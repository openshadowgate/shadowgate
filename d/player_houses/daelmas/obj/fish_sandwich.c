inherit "/std/food.c";
#include <std.h>

void create(){
  	::create();
  	set_name("a fried fish sandwich");
  	set_id(({"fried fish sandwich","fish sandwich","sandwich","food"}));
  	set_short("a fried fish sandwich");
  	set_long("This is a sandwich of fresh fried fish placed between "+
  		"to slices of bread.  The fish is topped with lettuce, tomato, "+
  		"and a sauce of some kind.");
  	set_destroy();
  	set_strength(50);
  	set_my_mess("You dig into the sandwich and find it very good and filling.");
  	set_your_mess("eats the sandwich messily leaving a bit of sauce on the "+
  		"corner of "+TP->query_possessive()+" mouth");
}











