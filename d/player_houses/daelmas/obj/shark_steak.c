inherit "/std/food.c";
#include <std.h>

void create(){
  	::create();
  	set_name("a shark steak");
  	set_id(({"shark steak","steak","food"}));
  	set_short("a shark steak");
  	set_long("This is a think portion of shark steak.  The steak "+
  		"is juicy and steaming and has a helping of peas and carrots on the side.");
  	set_destroy();
  	set_strength(50);
  	set_my_mess("You eat the shark steak and savor its flavor and seasonings.");
  	set_your_mess("eats the shark steak with relish.");
}











