inherit "/std/drink.c";
#include <std.h>
void create(){
        ::create();
        set_name("feywine");
        set_id(({"feywine","wine","drink"}));
        set_short("A glass of feywine");
        set_long(
           "This drink is served in a beautiful %^BOLD%^%^WHITE%^c%^RESET%^r%^BOLD%^%^WHITE%^ys%^RESET%^t%^BOLD%^%^WHITE%^al wineglass.  %^RESET%^The stem of the glass is made to resemble"
" twisted %^BOLD%^%^GREEN%^v%^WHITE%^i%^RESET%^n%^BOLD%^%^GREEN%^e%^WHITE%^s %^RESET%^that split into a set of four beautifully designed %^BOLD%^%^WHITE%^c%^RESET%^r%^BOLD%^%^WHITE%^ys%^RESET%^t%^BOLD%^%^WHITE%^al l%^GREEN%^e%^RESET%^a%^BOLD%^%^GREEN%^v%^RESET%^e%^BOLD%^%^WHITE%^s.  %^RESET%^The l%^GREEN%^e%^RESET%^a%^BOLD%^%^GREEN%^v%^RESET%^e%^BOLD%^%^WHITE%^s %^RESET%^spread out in four directions, each arcing down to a flattened edge at the tip to provide"
" excellent stability to the glass.  The %^BOLD%^%^MAGENTA%^feywine %^RESET%^itself is a magical"
" looking drink that comes up to the halfway mark on the glass."
        );
        set_destroy();
        set_strength(25);
        set_my_mess("You drink the feywine and feel an almost magical, blissful peace wash over you as"
" your skin starts to tingle all over. The glass almost slips from your hands as you hear a faerie"
" giggling in your ear. You set the glass down, letting the wine take full effect");
        set_your_mess("is overcome with an expression of peace and smiles softly.");
        set_type("alcoholic");
        set_weight(2);
        set_empty_name("crystal wineglass");
}