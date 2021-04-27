inherit "/std/drink.c";
#include <std.h>

void create(){
	::create();
  	set_name("tepid water");
  	set_id(({"water","tepid water","drink"}));
  	set_short("tepid water");
  	set_long("%^BOLD%^%^CYAN%^"+
  		"This is room temperature water sitting open in a tin cup.");
  	set_destroy();
  	set_my_mess("You drink the water and it removes your thirst.");
  	set_your_mess("drinks the water to assauge thirst.");
	set_type("water");
	set_strength(50);
	set_weight(2);
	set_empty_name("tin cup");
}






