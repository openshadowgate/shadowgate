inherit "/std/drink.c";
#include <std.h>
void create(){
        ::create();
        set_name("raspberry tea");
        set_id(({"raspberry tea","tea","drink"}));
        set_short("A cup of tea");
        set_long(
           "%^RESET%^This is an %^GREEN%^oak leaf cup %^RESET%^filled with a %^MAGENTA%^d%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^rk %^RESET%^looking %^MAGENTA%^tea.  %^RESET%^The smell of %^MAGENTA%^r%^RED%^a%^BOLD%^%^RED%^sp%^RESET%^%^RED%^b%^MAGENTA%^e%^BOLD%^%^MAGENTA%^r%^RED%^ri%^RESET%^%^RED%^e%^MAGENTA%^s %^RESET%^wafts up from the liquid held by the folded %^GREEN%^leaves, %^RESET%^making it a tempting treat indeed."
        );
        set_destroy();
        set_strength(1);
        set_my_mess("%^RESET%^%^MAGENTA%^The smooth raspberry flavor of the drink slides down your throat leaving you feeling relaxed and happy.");
        set_your_mess("slowly sips the tea and is overcome with a look of pure bliss.");
        set_weight(2);
        set_empty_name("oak leaf cup");
        set_type("soft drink");
}