//stefano_food.c - Food for Stefano's house.  Coded by Circe 9/20/03
inherit "/std/food.c";

void create(){
        ::create();
        set_name("hearty meal");
        set_id(({"hearty meal","meal","platter","food"}));
        set_short("%^ORANGE%^A wonderful platter of food%^RESET%^");
        set_long(
           "Slices of juicy roast beef are piled on this platter, surrounded "+
           "by steamed vegetables and a light brown gravy.  The meal seems quite "+
           "filling and smells delicious."
        );
        set_destroy();
        set_poison(0);
        set_strength(40);
        set_my_mess("You eat the delicious roast beef complemented perfectly by fresh vegetables.");
        set_your_mess("seems satisfied by the wonderful roast beef and vegetables.");
        set_weight(1);
        set_value(0);
}
