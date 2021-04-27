inherit "/std/food.c";

void create(){
 	::create();
  	set_name("dried fruit");
  	set_id(({"dried fruit","fruit","food"}));
  	set_short("%^RESET%^%^ORANGE%^A handful of dried fruit bits%^RESET%^");
  	set_long("%^ORANGE%^This handful of bits of dried fruit and nuts is just "
  	  "enough to snack on.  The fruit looks soft enough to be chewy and the "
     "nuts still look crisp.");
  	set_destroy();
   set_poison(0);
  	set_strength(5);
  	set_my_mess("The nuts crunch slightly and the fruit nearly melts in your mouth.");
  	set_your_mess("munches contentedly on the handful of nuts and fruit bits.");
	set_weight(1);
	set_value(0);
}