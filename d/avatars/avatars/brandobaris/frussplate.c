#include <std.h>
inherit "/d/common/obj/armour/fullplate";

void create(){
	::create();
	set_name("turtle plate");
	set_id(({ "plate", "turtle plate", "turtle armor", "plate of the tortoise" }));
	set_short("%^RESET%^%^CYAN%^Plate of the T%^BOLD%^%^GREEN%^o%^RESET%^r%^BOLD%^%^BLACK%^t%^GREEN%^o%^WHITE%^i%^GREEN%^s%^RESET%^%^CYAN%^e%^WHITE%^");
	set_obvious_short("%^RESET%^%^CYAN%^a suit of %^GREEN%^t%^CYAN%^u%^WHITE%^r%^CYAN%^t%^WHITE%^l%^GREEN%^e-l%^WHITE%^i%^GREEN%^ke %^CYAN%^platemail%^WHITE%^");
	set_long("%^GREEN%^This unique set of %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^e%^RESET%^e%^BOLD%^l p%^RESET%^l%^BOLD%^a%^RESET%^t%^BOLD%^e a%^RESET%^r%^BOLD%^m%^RESET%^o%^BOLD%^r %^RESET%^%^GREEN%^looks almost orna"
	"mental, and just a bit ridiculous at first glance. Given a dark, o%^BOLD%^l%^RESET%^%^CYAN%^i%^ORANGE%^v%^GREEN%^e-g%^CYAN%^r%^ORANGE%^e%^CYAN%^e%^GREEN%^n %^BOLD%^tinge%^RESET%^%^GREEN%^, with a %^OR"
	"ANGE%^l%^WHITE%^i%^YELLOW%^g%^RESET%^ht%^YELLOW%^e%^RESET%^%^ORANGE%^r %^GREEN%^colored pattern on its chest, the armor lends the impression that a great t%^BOLD%^%^BLACK%^o%^GREEN%^r%^BLACK%^t%^GREEN"
	"%^o%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^s%^RESET%^%^GREEN%^e s%^BOLD%^h%^WHITE%^e%^GREEN%^l%^RESET%^%^GREEN%^l has been affixed to the wearer's back. Despite its clunky-looking appearance, the armor see"
	"ms to be expertly crafted, and easy enough to move around in. Judging by the %^WHITE%^sc%^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^t%^RESET%^c%^BOLD%^%^BLACK%^h%^RESET%^es %^GREEN%^and %^ORA"
	"NGE%^d%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^ngs %^GREEN%^already on the armor, it more than fulfills its purpose of protecting the wearer, at that.%^WHITE%^
"	);
	set_value(15000);
	set_lore("%^BOLD%^This plate armor is traditionally worn by the captain of the Fruss Mercenary Company, a band of principled, if often luckless, mercenaries. Looking much like the wearer bears a large tortoise "
	"shell on their back, this plate is often pointed to a source of ridicule, but the Fruss family, a line notable for producing many exceptional swordsmen and warriors, sees the tortoise's image of unbre"
	"akable resolve as an ideal to take pride in. The steel used in this armor's creation is utterly flawless, and was said to have been a gift from the gold dwarves of the Tsarven Empire to Jericho Fruss "
	"I, the first-generation captain of the company.%^RESET%^
"	);
	set_property("lore difficulty",20);
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" straps on the tortoise-like armor, looking self-assured and just a bit silly.%^WHITE%^",ETO);
	tell_object(ETO,"%^CYAN%^You strap on the armor, feeling the %^GREEN%^t%^BOLD%^o%^RESET%^%^GREEN%^r%^CYAN%^t%^BOLD%^%^GREEN%^o%^RESET%^i%^BOLD%^s%^RESET%^%^GREEN%^e's %^CYAN%^fortitude fill you with %^YELLOW%^r%^WHITE%^e%^ORANGE%^s%^WHITE%^o%^ORANGE%^l%^WHITE%^v%^ORANGE%^e%^RESET%^%^CYAN%^.%^WHITE%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" removes the tortoise-like armor, looking more than a little vulnerable.%^WHITE%^",ETO);
	tell_object(ETO,"%^CYAN%^You take off the armor, feeling the %^GREEN%^t%^BOLD%^o%^RESET%^%^GREEN%^r%^CYAN%^t%^BOLD%^%^GREEN%^o%^RESET%^i%^BOLD%^s%^RESET%^%^GREEN%^e's %^YELLOW%^u%^WHITE%^n%^ORANGE%^y%^WHITE%^i%^ORANGE%^e%^WHITE%^l%^ORANGE%^d%^WHITE%^i%^ORANGE%^ng s%^WHITE%^p%^ORANGE%^ir%^WHITE%^i%^ORANGE%^t %^RESET%^%^CYAN%^leave you for now.%^WHITE%^");
	return 1;
}

