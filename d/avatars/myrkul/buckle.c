#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("buckle");
	set_id(({ "buckle" }));
	set_short("%^BOLD%^%^RED%^G%^BLUE%^o%^RED%^b%^BLUE%^l%^RED%^i%^BLUE%^n%^RESET%^%^MAGENTA%^ Belt %^BOLD%^%^RED%^Buckle%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^G%^BLUE%^o%^RED%^b%^BLUE%^l%^RED%^i%^BLUE%^n%^RESET%^%^MAGENTA%^ Belt %^BOLD%^%^RED%^Buckle%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^G%^BLUE%^o%^RED%^b%^BLUE%^l%^RED%^i%^BLUE%^n%^RESET%^%^MAGENTA%^ Belt %^BOLD%^%^RED%^Buckle%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1000);
	set("strbonus",8);
	set_type("clothing");
	set_limbs(({ "waist" }));
	set_size(1);
	set_property("enchantment",1);
	set_ac(30);
}



