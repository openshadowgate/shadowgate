#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^RED%^blood-crusted ringmail%^RESET%^");
	set_id(({ "ringmail", "armor" }));
	set_short("%^BOLD%^%^RED%^H%^RESET%^%^RED%^o%^BOLD%^u%^RESET%^%^RED%^n%^BOLD%^d %^BOLD%^%^MAGENTA%^m%^RESET%^%^MAGENTA%^e%^BOLD%^r%^RESET%^%^MAGENTA%^c%^BOLD%^e%^RESET%^%^MAGENTA%^n%^BOLD%^a%^RESET%^%^MAGENTA%^r%^BOLD%^y%^RESET%^%^CYAN%^ r%^BOLD%^i%^RESET%^%^CYAN%^ngm%^BOLD%^a%^RESET%^%^CYAN%^il%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^b%^BOLD%^l%^RESET%^%^RED%^oo%^BOLD%^d%^RESET%^%^RED%^-c%^BOLD%^r%^RESET%^%^RED%^ust%^BOLD%^e%^RESET%^%^RED%^d %^CYAN%^r%^BOLD%^i%^RESET%^%^CYAN%^ng%^BOLD%^m%^RESET%^%^CYAN%^ail%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This armor is made of light metal %^BOLD%^rings%^RESET%^%^CYAN%^ woven into %^ORANGE%^leather padding%^CYAN%^. It is completely covered in %^ORANGE%^dried%^RED%^ blood stains%^CYAN%^. Despite the gore, it appears in good shape. The only decoration is the insignia of %^BOLD%^%^RED%^H%^RESET%^%^RED%^o%^BOLD%^u%^RESET%^%^RED%^n%^BOLD%^d %^BOLD%^%^MAGENTA%^M%^RESET%^%^MAGENTA%^e%^BOLD%^r%^RESET%^%^MAGENTA%^c%^BOLD%^e%^RESET%^%^MAGENTA%^n%^BOLD%^a%^RESET%^%^MAGENTA%^r%^BOLD%^y%^BLACK%^ company%^RESET%^%^CYAN%^: three slashes of %^BOLD%^%^RED%^bloody claw marks.%^RESET%^

AVATAR
	);
	set_weight(12);
	set_value(2000);
	set_lore(
@AVATAR
This is the armor worn by hired killers of the dreaded Hound Mercenary company. Renowned for their cruelty, and their willingness to do any deed no matter how low, these are the very "Dogs of War" Only a full fledged member of the company earns the right to wear this armor, and those foolish enough to wear it without being a member are hunted down mercilessly.

AVATAR
	);
	set_property("lore difficulty",10);
	set("conbonus",1);
	set_max_internal_encumbrance(10);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(5);
}



