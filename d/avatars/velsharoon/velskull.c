#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("skull");
	set_id(({ "velskull", "velsharoons skull", "velsharoon skull" }));
	set_short("%^RESET%^%^RED%^Velsharoon's %^BOLD%^%^WHITE%^Sk%^RESET%^u%^BOLD%^ll%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Sk%^RESET%^u%^BOLD%^ll%^RESET%^");
	set_long(
@AVATAR
%^RED%^Velsharoon appears as a %^BOLD%^%^GREEN%^giant%^RESET%^%^RED%^ disembodied %^BOLD%^%^WHITE%^sk%^RESET%^u%^BOLD%^ll %^RESET%^%^RED%^ that is perpetually %^CYAN%^flo%^RESET%^a%^CYAN%^ting%^RED%^. His %^ORANGE%^e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^es %^RED%^ and %^BOLD%^%^WHITE%^t%^RESET%^ee%^BOLD%^th%^RESET%^%^RED%^ are comprised of %^BOLD%^%^YELLOW%^m%^CYAN%^u%^MAGENTA%^l%^GREEN%^t%^BLUE%^i%^RED%^c%^YELLOW%^o%^CYAN%^l%^MAGENTA%^o%^GREEN%^r%^BLUE%^e%^RED%^d %^CYAN%^g%^RESET%^%^CYAN%^e%^BOLD%^ms%^RESET%^%^RED%^. The only adornment that can be seen is an %^BOLD%^%^BLACK%^aged%^RESET%^%^RED%^ and pitted %^BOLD%^%^YELLOW%^crown%^RESET%^%^RED%^ atop his head.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_max_internal_encumbrance(100);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",10);
	set_ac(10);
}



