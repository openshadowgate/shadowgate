//shry_fruit_platter.c - Food for Shrydelhi's house.  Coded by Circe 9/14/03
inherit "/std/food.c";

void create(){
        ::create();
        set_name("fruit platter");
        set_id(({"fruit platter","fruit","platter of fruit","leaf platter","food","platter"}));
        set_short("%^BOLD%^%^GREEN%^A leaf platter of %^RED%^fruit slices%^RESET%^");
        set_long(
          "Slices of fresh fruit have been arranged on a platter made of an oak leaf.  "+
          "Apples, peaches, strawberries, and kiwi provide a very colorful presentation, "+
          "while fresh blueberries, blackberries, and raspberries form a soft bed for the "+
          "fruit slices.  Altogether, the fruit would probably be a filling meal."
        );
        set_destroy();
        set_poison(0);
        set_strength(5);
        set_my_mess("You eat the sweet fruit and enjoy the mixture of berries.");
        set_your_mess("seems to enjoy the fresh fruit and mixture of berries.");
        set_weight(1);
        set_value(0);
}
