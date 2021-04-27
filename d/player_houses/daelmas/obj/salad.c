inherit "/std/food.c";
#include <std.h>

void create(){
  	::create();
  	set_name("a large salad");
  	set_id(({"salad","large salad","food"}));
  	set_short("a large salad");
  	set_long("The salad is in a large bowl.  There are chopped "+
  		"mushroom, lettuce, tomatoes, cauliflower, broccoli, croutons, and "+
  		"pieces of cheese topped with a dressing.");
  	set_destroy();
  	set_strength(50);
  	set_my_mess("You slowly dig your way through the salad feeling "+
  		"very satisfied when finished.");
  	set_your_mess("grazes the salad chewing throughly and looking pleased.");
}











