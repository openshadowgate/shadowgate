inherit "/std/food.c";
#include <std.h>

void create(){
  	::create();
  	set_name("a bowl of cold gruel");
  	set_id(({"cold gruel","gruel","bowl of cold gruel","food"}));
  	set_short("a bowl of cold gruel");
  	set_long("This is a bowl of thin watery porridge.  The "+
  		"porridge is cold and will keep you from starving to "+
  		"death, but living on this staple for a long period of "+
  		"time would not be healthy.");
  	set_destroy();
  	set_strength(50);
  	set_my_mess("You eat the gruel slowly and with great effort you "+
  		"keep it down.");
  	set_your_mess("eats the cold gruel with great effort choking it "+
  		"all down finally.");
}











