//stef_brandy.c - Drink for Stefano's lounge.  Coded by Circe 9/27/03
inherit "/std/drink.c";
#include <std.h>
void create(){
        ::create();
        set_name("brandy");
        set_id(({"brandy","old deku brandy","old brandy","drink"}));
        set_short("%^YELLOW%^Old Deku Brandy%^RESET%^");
        set_long(
           "The rich, amber brandy is served in a large glass, ideally suited "+
           "to hold its full aroma, ready to savour before you drink it."
        );
        set_destroy();
        set_strength(25);
        set_my_mess("You take a couple of moments to savour the aroma of the fine brandy before drinking. The liquor is strong, but mellow, warming your throat without burning.  The same feeling of warmth and relaxation spreads slowly through your body, making the world feel like a better place than it did before drinking.");
        set_your_mess("smiles with a look of peace while sipping the brandy.");
        set_type("alcoholic");
        set_weight(2);
        set_empty_name("glass");
}
