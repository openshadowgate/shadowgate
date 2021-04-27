#include <std.h>
inherit "/d/common/obj/armour/fullplate";

void create(){
	::create();
	set_name("Mithril Fullplate");
	set_id(({ "plate", "dwarven plate", "fullplate", "full plate" }));
	set_short("%^BOLD%^%^RED%^S%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^u%^RESET%^%^RED%^l%^BOLD%^%^YELLOW%^f%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^r%^RESET%^%^ORANGE%^g%^BOLD%^%^YELLOW%^e%^RESET%^%^ORANGE%^r%^BOLD%^%^YELLOW%^s %^BOLD%^%^BLACK%^M%^WHITE%^i%^RESET%^t%^BOLD%^%^BLACK%^h%^WHITE%^r%^RESET%^i%^BOLD%^%^BLACK%^l%^WHITE%^ Full%^RESET%^p%^BOLD%^l%^RESET%^a%^BOLD%^t%^RESET%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Massive %^BOLD%^%^BLACK%^M%^WHITE%^i%^RESET%^t%^BOLD%^%^BLACK%^h%^WHITE%^r%^RESET%^i%^BOLD%^%^BLACK%^l%^WHITE%^ Full%^RESET%^p%^BOLD%^l%^RESET%^a%^BOLD%^t%^RESET%^e%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This %^RESET%^p%^BOLD%^l%^RESET%^a%^BOLD%^t%^RESET%^e%^BOLD%^ is made of the purest %^BOLD%^%^BLACK%^m%^WHITE%^i%^RESET%^t%^BOLD%^%^BLACK%^h%^WHITE%^r%^RESET%^i%^BOLD%^%^BLACK%^l%^WHI"
	"TE%^. The %^RESET%^p%^BOLD%^l%^RESET%^a%^BOLD%^t%^RESET%^e%^BOLD%^ have been made of a single flawless piece of %^BOLD%^%^BLACK%^m%^WHITE%^i%^RESET%^t%^BOLD%^%^BLACK%^h%^WHITE%^r%^RESET%^i%^BOLD%^%^BL"
	"ACK%^l%^WHITE%^ and seemingly bend around the wearers body. No joint or rivets is visible and the plate shines with %^CYAN%^p%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^f%^BOLD%^%^CYAN%^e%^RES"
	"ET%^%^CYAN%^c%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^. The front of the breast%^RESET%^p%^BOLD%^l%^RESET%^a%^BOLD%^t%^RESET%^e%^BOLD%^ have been chiseled"
	" into showing a long flowing %^YELLOW%^b%^RESET%^%^ORANGE%^e%^YELLOW%^a%^RESET%^%^ORANGE%^r%^YELLOW%^d%^WHITE%^ with perfect curves and immense details.%^RESET%^

"	);
	set_value(100000);
	set_lore("%^BOLD%^%^WHITE%^This plate was forged by Moradin himself, and is his own plate. Imbued with his divine power it protects the Lord of the dwarves against all harm

");
	set_property("lore difficulty",25);
	set_item_bonus("strength",5);
	set_item_bonus("magic resistance",3);
	set_item_bonus("damage resistance",100);
	set_size(2);
	set_property("enchantment",10);
	set_wear((:TO,"wear_func":));
}

int wear_func(){
	tell_room(environment(ETO),"Molten mithril folds itself around "+ETOQCN+" and hardens into "+query_short()+"",ETO);
	tell_object(ETO,"Molted mithril forms itself around your body and hardening into "+query_short()+"");
	return 1;
}


