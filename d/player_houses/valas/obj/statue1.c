#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id( ({"statue"}) );
    set_name("statue");
    set_short("a statue");
    set_weight(1000000);
    set_long("The statue before you is is %^BOLD%^%^RED%^disturbing%^RESET%^ "
"to look at; a %^BOLD%^%^GREEN%^w%^YELLOW%^a%^GREEN%^lking %^CYAN%^p%^YELLOW%^a"
"%^CYAN%^radox%^RESET%^ of %^BOLD%^%^GREEN%^n%^YELLOW%^a%^GREEN%^ture%^RESET%^. "
"The most striking feature, that immediately draws attention, are the %^BOLD%^"
"%^CYAN%^silver blue eyes%^RESET%^ that bear the %^BOLD%^%^BLACK%^c%^CYAN%^a"
"%^BLACK%^t-l%^CYAN%^i%^BLACK%^ke shape%^RESET%^ -- the %^BOLD%^%^YELLOW%^mark"
"%^RESET%^ of a %^BOLD%^%^RED%^Fiend%^RESET%^! The man is %^ORANGE%^tall and lean"
"%^RESET%^, with a %^MAGENTA%^tragic smile%^RESET%^ on his face. He has %^BOLD%^"
"%^BLACK%^ebony hair%^RESET%^, black like the %^BOLD%^%^BLACK%^a%^BLUE%^b%^BLACK%^yss"
"%^RESET%^. The man wears the trappings of a %^GREEN%^minor noble%^RESET%^, simple "
"but with appreciation for an %^BOLD%^%^RED%^e%^CYAN%^l%^BLUE%^e%^GREEN%^g%^GREEN%^a"
"%^BLUE%^n%^CYAN%^c%^RED%^e%^RESET%^ of a time %^BOLD%^%^CYAN%^long forgotten%^RESET%^"
". The %^BOLD%^%^YELLOW%^power%^RESET%^ exerted by this man's %^BOLD%^%^MAGENTA%^presence"
"%^RESET%^ is amazing, and he exerts the %^CYAN%^magnetic pull%^RESET%^ of the %^BOLD%^"
"%^YELLOW%^divine%^RESET%^. His %^BOLD%^%^BLACK%^in%^WHITE%^fl%^CYAN%^u%^WHITE%^en"
"%^BLACK%^ce%^RESET%^ is awe inspiring and spreads about him with the weightiness of "
"an %^BOLD%^%^BLUE%^app%^BOLD%^%^WHITE%^ro%^BLUE%^aching st%^BOLD%^%^WHITE%^o%^BLUE%^rm"
"%^RESET%^.");
    set_value(0);
    set_property("no animate", 1);
}