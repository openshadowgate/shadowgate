#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("diamond helm");
	set_id(({ "helm", "helmet", "diamond helm" }));
	set_short("%^BOLD%^%^WHITE%^D%^CYAN%^i%^BOLD%^%^WHITE%^a%^CYAN%^m%BOLD%^%^WHITE%^o%^CYAN%^n%^BOLD%^%^WHITE%^d Helm%^RESET%^");
	set_obvious_short("helmet");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This helmet is made from a %^BLUE%^sky blue %^BOLD%^%^WHITE%^d%^CYAN%^i%^BOLD%^%^WHITE%^a%^CYAN%^m%BOLD%^%^WHITE%^o%^CYAN%^n%^BOLD%^%^WHITE%^d and has been fitted so as to leave the face of the wearer open to exposure.  Engraved into the sides of it is the insignia of the %^CYAN%^Dagger Royal Guard%^BOLD%^%^WHITE%^, two %^BOLD%^%^WHITE%^d%^CYAN%^i%^BOLD%^%^WHITE%^a%^CYAN%^m%BOLD%^%^WHITE%^o%^CYAN%^n%^BOLD%^%^WHITE%^d swords raised and crossed.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(1000);
	set_type("armor");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
}


