inherit "/std/food.c";
#include <std.h>

void create(){
  	::create();
  	set_name("a plate of calamari");
  	set_id(({"calamari","plate of calamari","food"}));
  	set_short("a plate of calamari");
  	set_long("The plate is covered in calamari and smothered in a creamy sauce.");
  	set_destroy();
  	set_strength(50);
  	set_my_mess("You savor the taste of the tender calamari until the plate is empty.");
  	set_your_mess("devours the calamari with gusto.");
}











