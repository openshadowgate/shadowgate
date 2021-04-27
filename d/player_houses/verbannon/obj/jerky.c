inherit "/std/food";

void create(){
   ::create();
   set_name("jerky");
   set_id(({"jerky","food"}));
   set_short("%^RESET%^strip of %^ORANGE%^jer%^RESET%^%^BOLD%^%^BLACK%^k%^RESET%^%^ORANGE%^y%^RESET%^");
   set_long("It's a strip of dried, salted and rubbery grayish meat. Probably best not to question where the meat is from. It's military grade which means it probably can double as a weapon.");
   set_my_mess("As you chew the meat, its pleasant, spicy, salty rubbery gray flavor runs down your throat. Then that flavor vanishes and you find yourself still chewing and chewing until your jaw feels numb. You end up with no choice but to swallow the whole thing.\n");
   set_your_mess("chews the jerky, gives up and just swallows it.\n");
   set_destroy();
   set_value(0);
   set_weight(0);
   set_strength(10);
}