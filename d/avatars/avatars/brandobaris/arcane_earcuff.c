#include <std.h>
inherit "/d/common/obj/jewelry/circlet";

void create(){
	::create();
	set_name("Arcane Earcuff");
	set_id(({ "earcuff", "cuff", "arcane earcuff" }));
	set_short("%^RESET%^%^BOLD%^%^CYAN%^A%^RESET%^%^CYAN%^r%^BOLD%^c%^RESET%^a%^CYAN%^n%^BOLD%^e E%^RESET%^%^CYAN%^a%^BOLD%^r%^RESET%^%^CYAN%^c%^BOLD%^u%^RESET%^f%^BOLD%^%^CYAN%^f%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^a simple e%^RESET%^a%^BOLD%^r%^RESET%^c%^BOLD%^u%^RESET%^f%^BOLD%^f of %^RESET%^%^CYAN%^a%^WHITE%^z%^BOLD%^u%^CYAN%^r%^RESET%^%^CYAN%^e-h%^BOLD%^u%^RESET%^e%^CYAN%^d %^BOLD%^%^WHITE%^m%^CYAN%^e%^WHITE%^t%^RESET%^a%^BOLD%^l%^RESET%^");
	set_long("%^CYAN%^This is a simple earcuff, cast from a single piece of a%^BOLD%^z%^WHITE%^u%^CYAN%^r%^RESET%^%^CYAN%^e-h%^BOLD%^u%^WHITE%^e%^RESET%^%^CYAN%^d metal. Small and unobtrusive, it is fashioned so as"
	" to sit comfortably on the wearer's ear, and it bears no ornamentation save for several small %^BOLD%^r%^WHITE%^u%^CYAN%^n%^WHITE%^e%^CYAN%^s %^RESET%^%^CYAN%^etched into its surface. The metal it is "
	"made from is odd, seeming to %^BOLD%^%^BLUE%^r%^RESET%^%^CYAN%^i%^BOLD%^%^BLUE%^p%^RESET%^%^CYAN%^p%^BOLD%^l%^BLUE%^e %^RESET%^%^CYAN%^and %^BOLD%^r%^WHITE%^e%^RESET%^f%^BOLD%^l%^RESET%^e%^BOLD%^c%^CY"
	"AN%^t %^RESET%^%^CYAN%^light apparently at random.%^WHITE%^
"	);
	set_value(10000);
	set_lore("%^CYAN%^The metal this earcuff is made from has been the subject of much debate amongst metallurgists over the past several centuries, after it first came into common use amongst Mystran enchanters. R"
	"eportedly impossible to study or break down (it is said to rust away in an instant upon close examination), the metal holds a curious property that allows enchanters with the proper training to imbue "
	"it with spells with far less effort than they would normally expend on other materials. Jewelry such as this is often used as a matter of convenience amongst Mystrans who may have need to hold certain"
	" spells in reserve.%^RESET%^
"	);
	set_property("lore difficulty",20);
	set_size(2);
	set_property("enchantment",0);
}



