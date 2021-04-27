//lusell_dinner.c - Food for Lusell's Keep.  Coded by Circe 1/29/04
inherit "/std/food.c";

void create(){
        ::create();
        set_name("formal dinner");
        set_id(({"dinner","formal dinner","elegant formal dinner","food"}));
        set_short("%^MAGENTA%^An elegant formal dinner%^RESET%^");
        set_long(
           "The table setting in front of you is massive.  You have a huge "+
           "helping of some game meat, three different servings of "+
           "fresh vegetables, a bowl of soup, a plate of bread and some creamy dessert."
        );
        set_destroy();
        set_poison(0);
        set_strength(40);
        set_my_mess("You eat satisfying meal and enjoy the creamy dessert");
        set_your_mess("seems satisfied by the delicious meal.");
        set_weight(1);
        set_value(0);
}
