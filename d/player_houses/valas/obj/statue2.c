#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id( ({"statue"}) );
    set_name("statue");
    set_short("a statue");
    set_weight(1000000);
    set_long("%^RESET%^%^ORANGE%^This is a %^BOLD%^%^WHITE%^m%^RESET%^%^WHITE%^a"
"%^BOLD%^%^CYAN%^g%^BOLD%^%^WHITE%^n%^RESET%^%^WHITE%^i%^BOLD%^%^CYAN%^f%^BOLD%^"
"%^WHITE%^i%^RESET%^%^WHITE%^c%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^n%^RESET%^%^WHITE%^t"
"%^RESET%^%^ORANGE%^ 20 feet high bronze statue. A h%^WHITE%^u%^ORANGE%^m%^WHITE%^a"
"%^ORANGE%^n%^WHITE%^o%^ORANGE%^i%^WHITE%^d%^ORANGE%^ resembling a cross between a "
"%^WHITE%^human%^ORANGE%^ and %^BOLD%^%^BLACK%^dwarf%^RESET%^%^ORANGE%^ stands "
"%^CYAN%^proudly%^ORANGE%^ before you holding a %^RED%^i%^WHITE%^m%^RED%^p%^WHITE%^r"
"%^RED%^e%^WHITE%^s%^RED%^s%^WHITE%^i%^RED%^v%^WHITE%^e%^BOLD%^%^BLACK%^ hammer"
"%^RESET%^%^ORANGE%^ in both of his large hands. He wears a %^BOLD%^%^WHITE%^beautiful"
"%^RESET%^%^WHITE%^ armor %^ORANGE%^consisting of %^BOLD%^%^BLACK%^th%^WHITE%^o"
"%^BLACK%^usands%^RESET%^%^ORANGE%^ of %^BOLD%^%^BLACK%^m%^WHITE%^i%^BOLD%^%^BLACK%^rr"
"%^WHITE%^o%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^ like pieces and a %^BOLD%^%^WHITE%^s"
"%^RESET%^%^WHITE%^h%^BOLD%^%^WHITE%^i%^RESET%^%^WHITE%^m%^BOLD%^%^WHITE%^m%^RESET%^"
"%^WHITE%^e%^BOLD%^%^WHITE%^r%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^n%^RESET%^%^WHITE%^g "
"%^BOLD%^%^BLACK%^vis%^GREEN%^o%^BLACK%^red%^ORANGE%^ helmet covers his head with the "
"%^BOLD%^%^BLACK%^vis%^GREEN%^o%^BLACK%^r%^RESET%^%^ORANGE%^ raised. He is %^RED%^stout"
"%^ORANGE%^ and muscles are clearly seen where he isn't armored. A %^CYAN%^symbol"
"%^ORANGE%^ is %^BOLD%^%^BLUE%^prominently%^RESET%^%^ORANGE%^ seen in a chain around "
"his neck, showing he is a follower of G%^RED%^ru%^RED%^m%^ORANGE%^b%^RED%^a%^ORANGE%^r"
". His large %^BOLD%^%^BLACK%^beard%^RESET%^%^ORANGE%^ is beautiful made and his eyes "
"almost %^BOLD%^%^CYAN%^shine%^RESET%^%^ORANGE%^ with %^YELLOW%^warmth%^RESET%^"
"%^ORANGE%^ and %^WHITE%^laughter%^RESET%^%^ORANGE%^.%^RESET%^");
    set_value(0);
    set_property("no animate", 1);
}
