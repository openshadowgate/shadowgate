inherit "/std/food.c";

void create(){
 	::create();
  	set_name("beer nuts");
  	set_id(({"nuts","beer nuts","food"}));
  	set_short("%^RESET%^%^ORANGE%^A handful of beer nuts%^RESET%^");
  	set_long("%^RESET%^This handful of beer nuts is just enough to snack on.  They look really crunchy and tasty.%^RESET%^\n");
  	set_destroy();
   set_poison(0);
  	set_strength(2);
  	set_my_mess("You pop the beer nuts into your mouth and enjoy the crunchy snack.");
  	set_your_mess("munches on the crunchy beer nuts.");
	set_weight(1);
	set_value(0);
}











