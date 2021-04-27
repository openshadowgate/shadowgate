#include <std.h>
inherit "/d/common/obj/armour/leather_greaves";

void create(){
	::create();
	set_name("Foolish Feelings");
	set_id(({ "stockings", "hose", "leggings", "foolish feelings" }));
	set_short("%^WHITE%^F%^BOLD%^o%^RESET%^o%^BOLD%^l%^RESET%^i%^BOLD%^s%^RESET%^h %^BOLD%^F%^RESET%^e%^BOLD%^e%^RESET%^l%^BOLD%^i%^RESET%^n%^BOLD%^g%^RESET%^s%^RESET%^");
	set_obvious_short("%^WHITE%^A s%^CYAN%^h%^WHITE%^i%^BOLD%^m%^RESET%^m%^CYAN%^e%^BOLD%^r%^WHITE%^ing pair of stockings%^RESET%^");
	set_long("%^CYAN%^Sewn from a %^BOLD%^otherworldly fabric, %^RESET%^%^CYAN%^this pair of feminine stockings are meant to cling to the wearer's legs. The material has a diamond-like sheen anytime the light catch"
	"es it. There is strange magic here, and you get the feeling they will not tear very easy. Either way, something so pretty so be treated with care.%^RESET%^
"	);
	set_value(20000);
	set_lore("%^BOLD%^%^CYAN%^Miles Magnusu was man who had it all...except for the one thing he wanted most. As the tale goes he searched high and low for gifts to woo his one true love who was known to be an ente"
	"rtainer of some kind. Alas the woman was in love with someone else but that did not stop the lovestruck man from giving her gifts like these stockings. Some say they come from another plane.%^RESET%^
"	);
	set_property("lore difficulty",20);
	set_item_bonus("damage resistance",2);
	set_item_bonus("spell damage resistance",2);
	set_size(2);
	set_property("enchantment",0);
}



