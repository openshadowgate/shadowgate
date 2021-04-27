#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("ivory cane");
	set_id(({ "cane", "ivory cane", "cane of the vigilant" }));
	set_short("%^BOLD%^%^WHITE%^C%^BLUE%^a%^WHITE%^ne of the V%^BLUE%^i%^WHITE%^gilant%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^an ivory cane%^RESET%^");
	set_long(
@AVATAR
%^RESET%^Created from %^BOLD%^%^WHITE%^ivory%^RESET%^, this cane looks %^ORANGE%^f%^YELLOW%^l%^BLACK%^a%^RESET%^%^ORANGE%^wl%^YELLOW%^e%^BLACK%^s%^RESET%^%^ORANGE%^s%^RESET%^. It has a %^BOLD%^%^WHITE%^r%^BLUE%^i%^WHITE%^ght-h%^BLUE%^a%^WHITE%^nded g%^BLUE%^a%^WHITE%^ultlet %^RESET%^held upright with the palm facing forward for the handle on the top. The %^BOLD%^%^WHITE%^ivory %^RESET%^continues to the bottom in a spiral, accented with %^ORANGE%^g%^YELLOW%^o%^BLACK%^l%^RESET%^%^ORANGE%^den h%^YELLOW%^i%^BLACK%^g%^RESET%^%^ORANGE%^hlig%^YELLOW%^h%^BLACK%^t%^RESET%^%^ORANGE%^s%^RESET%^.  Protecting the base of the %^BOLD%^%^WHITE%^c%^BLUE%^a%^WHITE%^ne %^RESET%^from damage, a %^ORANGE%^leather cap %^RESET%^has been affixed and could be easily changed when worn out.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(500);
	set_lore(
@AVATAR
A gift from his father, this cane was specially commissioned as a birthday gift, somewhat as a joke for youthful teasing that Valadrix did as a youth, but mostly as a note of status.  Such items, while not uncomon, are rarely made with such fine detail and clear gift for detail.  Clearly someone of note had the cane made.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("bludgeoning");
	set_prof_type("staff");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",0);
}



