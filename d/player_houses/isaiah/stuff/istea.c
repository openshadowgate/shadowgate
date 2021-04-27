inherit "/std/drink.c";
#include <std.h>
void create(){
 	::create();
  	set_name("ice tea");
  	set_id(({"tea","ice tea","drink"}));
  	set_short("%^RESET%^%^ORANGE%^i%^YELLOW%^c%^RESET%^%^ORANGE%^e%^YELLOW%^ t%^RESET%^%^ORANGE%^e%^YELLOW%^a%^RESET%^");
  	set_long("%^BOLD%^%^YELLOW%^"+
  		"This is a glistening, %^RESET%^%^ORANGE%^amber%^BOLD%^ colored liquid "+
  		"that looks very enticing, cold, and refreshing.\n"+
  		"%^RESET%^");
  	set_destroy();
  	set_strength(1);
  	set_my_mess("You close your eyes and thoroughly enjoy the ice cold tea as it "+
  		"rolls over your tongue and down your throat chilling you slightly.");
  	set_your_mess("sips the tea, enjoys it immensely and shivers slightly.");
	set_type("soft drink");
	set_weight(2);
	set_empty_name("leaf cup");
}











