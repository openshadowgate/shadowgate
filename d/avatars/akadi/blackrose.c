#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("black rose");
	set_id(({ "rose", "black rose", "flower", "glass rose" }));
	set_short("%^BOLD%^%^BLACK%^a black r%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^se%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^Crafted from %^RESET%^crystal%^BOLD%^%^WHITE%^, the details of this %^BOLD%^%^BLACK%^lovely rose%^BOLD%^%^WHITE%^ are extraordinarily exquisite. The %^BOLD%^%^BLACK%^onyx petals%^BOLD"
	"%^%^WHITE%^ are %^RESET%^cool%^BOLD%^%^WHITE%^ to the touch, their smooth surface polished to a shine. Delicate in appearance yet hardly fragile, the stem is long and colored a %^RESET%^%^GREEN%^p%^BO"
	"LD%^a%^RESET%^%^GREEN%^le gre%^BOLD%^e%^RESET%^%^GREEN%^n%^BOLD%^%^WHITE%^. A single leaf branches out from the length of it. While very %^RESET%^simple%^BOLD%^%^WHITE%^ the %^BOLD%^%^BLACK%^flower%^B"
	"OLD%^%^WHITE%^ is also quite pretty.%^RESET%^
"
	);
	set_value(7);
	set_weight(1);
	set_lore("%^RESET%^%^CYAN%^While studying the %^BOLD%^%^BLACK%^rose%^RESET%^%^CYAN%^ something stirs and tugs at your mind.... %^RESET%^A thought just beyond your reach, as if it was a dream you once had, but c"
	"annot quite recall...
"
	);
    set_property("lore difficulty",15);
}
