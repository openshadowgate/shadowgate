#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("holly leaf");
	set_id(({ "pin" }));
	set_short("%^BOLD%^%^RED%^h%^YELLOW%^o%^GREEN%^l%^RED%^i%^GREEN%^d%^YELLOW%^a%^GREEN%^y %^BLUE%^p%^RED%^i%^GREEN%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^h%^YELLOW%^o%^GREEN%^l%^RED%^i%^GREEN%^d%^YELLOW%^a%^GREEN%^y %^BLUE%^p%^RED%^i%^GREEN%^n%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a %^RED%^h%^YELLOW%^o%^GREEN%^l%^RED%^i%^GREEN%^d%^YELLOW%^a%^GREEN%^y %^BLUE%^p%^RED%^i%^GREEN%^n%^WHITE%^ in the shape of a set of %^GREEN%^holly leaves%^WHITE%^ with three tiny red %^RED%^holly berries%^WHITE%^.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^RED%^Ha%^YELLOW%^pp%^RESET%^%^ORANGE%^y H%^GREEN%^%^BOLD%^ol%^CYAN%^id%^BLUE%^ay%^RESET%^%^MAGENTA%^s%^WHITE%^, whatever you celebrate! - %^RESET%^%^MAGENTA%^(%^WHITE%^%^BOLD%^Lurue%^RESET%^%^CYAN%^)%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(0);
	set_value(0);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(1);
	set_property("enchantment",0);
}


