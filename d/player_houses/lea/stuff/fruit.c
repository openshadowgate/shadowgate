inherit "/std/food.c";
#include <std.h>
void create(){
   ::create();
  set_name("fruit");
  set_id("fruit");
  set_short("%^BOLD%^%^GREEN%^fruit%^RESET%^");
  set_long("An exotic and as of yet unidentified piece of fruit is before you.  It "+
  		"feels fleshy and juicy.");
  set_destroy();
  set_strength(20);
  set_my_mess("Biting into the fruit sweet juices burst out and run down your chin.  "+
  		"The sweet flavor of the fruit rolls through your mouth and invigorates you.");
  set_your_mess("eats unidentified fruit messily as juices roll down their chin..");
 }











