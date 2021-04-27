inherit "/std/food.c";
#include <std.h>

void create(){
  	::create();
  	set_name("a bowl of fish stew");
  	set_id(({"fish stew","stew","bowl of fish stew","food"}));
  	set_short("a bowl of fish stew");
  	set_long("This is a bowl of fish stew, the aroma is actually "+
  		"quite good and the portions looks ample.");
  	set_destroy();
  	set_strength(50);
  	set_my_mess("You eat the fish stew slowly and enjoy the blend of spices.");
  	set_your_mess("eats the fish stew slowly and cleans the bowl.");
}











