#include <std.h>
inherit OBJECT;

void create(){
        ::create();
        set_name("statue");
        set_id(({"statue","obsidian statue"}));
        set_short("%^BOLD%^%^BLACK%^obsidian statue%^RESET%^");
        set_long("%^RESET%^This is a statue of a %^BOLD%^%^RED%^totally awesome %^BLACK%^shadow assassin of "
"the wheel%^RESET%^. He is striking a pose, complete with his %^BOLD%^%^CYAN%^78 AC %^RESET%^that is way "
"better than even Corellon on the prime. He has %^BOLD%^%^MAGENTA%^immunities %^RESET%^to heaps of crap, "
"%^BOLD%^%^GREEN%^spell resistance %^RESET%^to everything, and he can EVEN get out of the positive energy "
"plane after taking only %^BOLD%^%^BLUE%^72 hitpoints of damage%^RESET%^! You know you totally want to be in a "
"tabletop campaign with this guy because he is so awesomely cool, it must've been the most %^BOLD%^%^WHITE%^"
"wicked GM ever %^RESET%^to have thought him up. Don't worry, he might sound like he's impossible by the "
"rules, but someone read it in a book somewhere so we know it's ok.\n\n%^YELLOW%^Oh, and he's wielding a "
"katana.%^RESET%^\n");
        set_value(76302);
        set_weight(0);
}
