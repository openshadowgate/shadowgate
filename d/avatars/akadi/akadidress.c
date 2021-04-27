#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^WHITE%^Fl%^RESET%^ow%^BOLD%^%^WHITE%^ing white dre%^RESET%^s%^BOLD%^%^WHITE%^s%^RESET%^");
	set_id(({ "robe", "dress", "gown" }));
	set_short("%^RESET%^%^CYAN%^Fl%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^ng %^BOLD%^%^WHITE%^white %^BOLD%^%^WHITE%^g%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^wn%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^Fl%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^ng %^BOLD%^%^WHITE%^white %^BOLD%^%^WHITE%^g%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^wn%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This beautiful gown clings tightly to the wearer although it seems to take no true form of its own. Fl%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^wing white and pale %^BOLD%^%^BLUE%^blue%^BOLD%^%^WHITE%^ ten%^BLUE%^d%^WHITE%^r%^BLUE%^i%^WHITE%^ls twirl %^RESET%^%^CYAN%^ch%^BOLD%^%^CYAN%^ao%^BOLD%^%^WHITE%^tic%^BOLD%^%^CYAN%^al%^RESET%^%^CYAN%^ly%^BOLD%^%^WHITE%^ about the robe, as if caught in a perpetual %^BOLD%^%^BLUE%^b%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^ee%^RESET%^%^CYAN%^z%^BOLD%^%^BLUE%^e%^BOLD%^%^WHITE%^. Sheer long sleeves and low neckline add a touch of elegance to this %^CYAN%^wi%^BOLD%^%^WHITE%^s%^BOLD%^%^CYAN%^py%^BOLD%^%^WHITE%^ gown.%^RESET%^ 

AVATAR
	);
	set_weight(5);
	set_value(10000);
	set_max_internal_encumbrance(100000);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",10);
	set_ac(30);
}


