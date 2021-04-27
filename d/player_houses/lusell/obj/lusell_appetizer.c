//lusell_appetizer.c - Food for Lusell's Keep.  Coded by Circe 1/29/04
inherit "/std/food.c";

void create(){
        ::create();
        set_name("appetizer");
        set_id(({"appetizer","appetizer plate","An appetizer plate","plate","food"}));
        set_short("%^GREEN%^An appetizer plate%^RESET%^");
        set_long(
           "This plate is full of fresh vegetables.  The smell of carrots, "+
           "celery, cauliflower, cherry tomatos and broccoli overwhelm your "+
           "senses as well as your plate."
        );
        set_destroy();
        set_poison(0);
        set_strength(15);
        set_my_mess("The crisp vegetables provide a lovely light appetizer.");
        set_your_mess("enjoys a light appetizer of vegetables.");
        set_weight(1);
        set_value(0);
}
