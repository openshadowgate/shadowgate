#include <std.h>
inherit "/d/common/obj/armour/shield";

void create(){
	::create();
	set_name("Turtle Shield");
	set_id(({ "shield", "turtle shield", "turtle-shell shield" }));
	set_short("%^RESET%^%^CYAN%^T%^GREEN%^u%^BOLD%^r%^CYAN%^t%^BLACK%^l%^RESET%^%^CYAN%^e S%^GREEN%^h%^BOLD%^i%^CYAN%^e%^RESET%^%^GREEN%^l%^CYAN%^d%^WHITE%^");
	set_obvious_short("%^RESET%^%^CYAN%^an oddly shaped t%^GREEN%^u%^BOLD%^r%^CYAN%^t%^RESET%^l%^CYAN%^e-s%^WHITE%^h%^GREEN%^e%^BOLD%^l%^RESET%^%^CYAN%^l s%^BOLD%^%^GREEN%^h%^WHITE%^i%^RESET%^e%^BOLD%^%^GREEN%^l%^RESET%^%^CYAN%^d%^WHITE%^");
	set_long("%^CYAN%^This large %^WHITE%^steel shield %^CYAN%^has a strange, semi-ovular design that looks to be inspired by a %^GREEN%^t%^CYAN%^u%^BOLD%^r%^RESET%^%^GREEN%^t%^WHITE%^l%^GREEN%^e's s%^WHITE%^h%^ORA"
	"NGE%^e%^GREEN%^ll%^CYAN%^, and indeed it bears a segmented, %^GREEN%^g%^ORANGE%^r%^GREEN%^e%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^n%^GREEN%^-%^ORANGE%^b%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^ow%^ORANGE%^n "
	"%^CYAN%^patterning on its surface. Its odd surface, curving inward, makes it awkward to hold as one would a standard shield, and several different %^BOLD%^%^BLACK%^h%^RESET%^a%^BOLD%^n%^BLACK%^dl%^RES"
	"ET%^e%^BOLD%^%^BLACK%^s %^RESET%^%^CYAN%^are set behind it, allowing it to be gripped in various positions. It would take an esoteric kind of training, plus a great deal of practice to use this with a"
	"ny kind of proficiency in battle.%^WHITE%^
"	);
	set_value(0);
	set_lore("%^BOLD%^Plate armor bearing the traits of turtles is traditionally worn by the captain of the Fruss Mercenary Company, a band of principled, if often luckless, mercenaries. Looking much like the weare"
	"r bears a large tortoise shell on their back, this plate is often pointed to a source of ridicule, but the Fruss family, a line notable for producing many exceptional swordsmen and warriors, sees the "
	"tortoise's image of unbreakable resolve as an ideal to take pride in. The steel used in this armor's creation is utterly flawless, and was said to have been a gift from the gold dwarves of the Tsarven"
	" Empire to Jericho Fruss I, the first-generation captain of the company. This matching shield bears a similarly esoteric design, and requires special training to use effectively.
"	);
	set_property("lore difficulty",10);
	set_item_bonus("spell damage resistance",20);
	set_item_bonus("magic resistance",2);
	set_item_bonus("fortitude",3);
	set_size(2);
	set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" takes up the strange shield, gripping it in an odd fashion.",ETO);
	tell_object(ETO,"%^CYAN%^You take up the turtle-shell shield, gripping it deliberately.");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" sets aside the strange shield.",ETO);
	tell_object(ETO,"%^CYAN%^You set aside the turtle-shell shield.");
	return 1;
}

