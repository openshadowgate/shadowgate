#include <std.h>
inherit OBJECT;

void create(){
        ::create();
        set_name("statue");
        set_id(({"statue","toy","unicorn toy","carved toy","carved unicorn","unicorn"}));
        set_short("%^RESET%^%^ORANGE%^a little carved %^RESET%^un%^BOLD%^"
"i%^RESET%^co%^BOLD%^r%^RESET%^n %^ORANGE%^toy%^RESET%^");
        set_long("%^ORANGE%^Carved from gra%^RED%^i%^ORANGE%^ny wood, this "
"small toy is a bit %^RED%^rough %^ORANGE%^and %^BOLD%^%^BLACK%^rustic"
"%^RESET%^%^ORANGE%^, obviously handmade and not particularly elegant in "
"design. It forms the shape of an equine figure, complete with a tiny horn, "
"obviously to symbolise a %^RESET%^un%^BOLD%^i%^RESET%^co%^BOLD%^r%^RESET%^n"
"%^ORANGE%^. Its surface is long-worn, probably from much handling of a "
"%^MAGENTA%^well-loved %^ORANGE%^toy.%^RESET%^\n");
        set_value(5);
        set_weight(1);
        set_lore("Common among elven kind are tiny carved toys in the shapes "
"of various animals, made for their children to play with among themselves. "
"This is one such toy, obviously well-used and much loved by how worn it is.");
        set_property("lore difficulty",1);
}
