#include <std.h>
inherit "/d/common/obj/clothing/robe";

void create(){
	::create();
	set_name("surcoat of the conquerer");
	set_id(({ "surcoat", "coat", "sapphire-hued surcoat", "surcoat of the conquerer" }));
	set_short("%^RESET%^%^BOLD%^%^BLUE%^Surcoat of the %^CYAN%^C%^WHITE%^o%^CYAN%^n%^RESET%^q%^BOLD%^%^CYAN%^u%^WHITE%^e%^CYAN%^r%^RESET%^e%^BOLD%^%^CYAN%^r%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a %^BOLD%^%^BLUE%^s%^RESET%^%^CYAN%^a%^BOLD%^%^BLUE%^p%^RESET%^%^CYAN%^p%^BOLD%^%^WHITE%^h%^BLUE%^i%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^e-h%^RESET%^u%^CYAN%^e%^BOLD%^%^BLUE%^d %^RESET%^%^CYAN%^surcoat%^WHITE%^");
	set_long("%^BOLD%^%^BLUE%^This cotton, s%^RESET%^%^CYAN%^a%^BOLD%^%^BLUE%^p%^RESET%^%^CYAN%^p%^BOLD%^h%^BLUE%^i%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^e-h%^RESET%^%^CYAN%^u%^BOLD%^e%^BLUE%^d surcoat looks designed to"
	" fit over a suit of %^BLACK%^heavy armor%^BLUE%^. It falls just slightly past the wearer's knees, and bears long slits up other side to facilitate the wearer's stride. It has a thin, %^RESET%^s%^BOLD%"
	"^%^BLACK%^u%^RESET%^b%^CYAN%^d%^WHITE%^u%^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^%^BLUE%^trim of %^WHITE%^sil%^CYAN%^v%^WHITE%^er %^BLUE%^upon its hems, and little by way of markings otherwise, though if "
	"one looks closely they can just make out the form of a single %^RESET%^%^ORANGE%^pentagon%^BOLD%^%^BLUE%^, e%^BLACK%^m%^BLUE%^b%^BLACK%^o%^BLUE%^s%^RESET%^s%^BOLD%^%^BLACK%^e%^BLUE%^d upon its right b"
	"reast.%^RESET%^
"	);
	set_value(5000);
	set_lore("%^CYAN%^The pentagon upon the breast of this surcoat is said to have once been the crest of a great warlord who lived far to the north. At once a skilled commander and a terrible bully, the warlord se"
	"t his armies against all other settlements within his reach, attacking and conquering their lands at the flimsiest of pretenses. However, although the warlord's domain grew vast, his own aggression wa"
	"s to be his downfall. Upon one campaign to destroy a tribe of Aesatri barbarians, he found his forces quickly routed and broken by the 'primitive' people, and their enraged retribution tore his domain"
	" apart. Thus, the warlord's name was lost to history, and the northern tribe claimed many of the surcoats once worn by his forces as trophies, imbuing them with the blessings of fortitude that had sus"
	"tained their tribe for so many centuries.%^WHITE%^
"	);
	set_property("lore difficulty",20);
	set_item_bonus("constitution",2);
	set_item_bonus("endurance",2);
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The s%^RESET%^%^CYAN%^a%^BOLD%^%^BLUE%^p%^CYAN%^p%^RESET%^%^CYAN%^h%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^e surcoat s%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^t%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^s lightly over "+ETOQCN+"'s shoulders.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^The s%^RESET%^%^CYAN%^a%^BOLD%^%^BLUE%^p%^CYAN%^p%^RESET%^%^CYAN%^h%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^e surcoat s%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^t%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^s lightly over your shoulders. You feel oddly ready to meet any challenge ahead of you.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The s%^RESET%^%^CYAN%^a%^BOLD%^%^BLUE%^p%^CYAN%^p%^RESET%^%^CYAN%^h%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^e surcoat s%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^p%^BOLD%^%^BLUE%^s from "+ETOQCN+"'s shoulders.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^The s%^RESET%^%^CYAN%^a%^BOLD%^%^BLUE%^p%^CYAN%^p%^RESET%^%^CYAN%^h%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^e surcoat s%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^i%^RESET%^%^CYAN%^p%^BOLD%^%^BLUE%^s from your shoulders, leaving you feeling somewhat more exposed.%^RESET%^");
	return 1;
}

