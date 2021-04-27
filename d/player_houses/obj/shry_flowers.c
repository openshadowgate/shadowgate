//shry_flowers.c - wildflowers for Shrydelhi's meadow - coded by Circe 9/12/03
#include <std.h>
inherit OBJECT;

void create()
{
        ::create();
        set_name("wildflowers");
        set_id(({"wildflowers","flowers","bouquet"}));
        set_short("%^BOLD%^%^RED%^W%^YELLOW%^i%^BLUE%^l%^GREEN%^d%^MAGENTA%^flowers%^RESET%^");
        set_long(
           "%^BOLD%^%^YELLOW%^This beautiful bouquet of wildflowers contains "+
           "many different varieties of flowers ranging from sunny yellow daffodils "+
           "to stark %^WHITE%^white daisies %^YELLOW%^and %^BLUE%^deep indigo bluebells,"+
           "%^YELLOW%^with many different %^MAGENTA%^pink %^YELLOW%^and %^RED%^red "+
           "%^YELLOW%^blossoms thrown in.  They are all gathered together and tied around the stem with a "+
           "slender %^GREEN%^ivy vine.%^RESET%^"
        );
        set_weight(1);
        set_value(20);
        set_cointype("silver");
}
