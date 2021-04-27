#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("robes of the alchemist");
	set_id(({ "robe", "robes" }));
	set_short("%^RED%^Robes of the%^WHITE%^ A%^RED%^lch%^WHITE%^e%^RED%^m%^WHITE%^i%^RED%^st%^RESET%^");
	set_obvious_short("%^RED%^embroidered r%^WHITE%^o%^RED%^b%^WHITE%^e%^RED%^s%^RESET%^");
	set_long(
@AVATAR
%^RED%^This is a pair of long robes, made of linen but trimmed in high quality silk.  It is dyed a warm blood red color but it has been trimmed with %^WHITE%^silver%^RED%^.  The lining is a fine quality silk, a deep %^BLUE%^blue %^RED%^color.  The most outstanding feature of decor is a symbol drawn in %^WHITE%^silver thread%^RED%^ along the back.  It appears to be a %^BOLD%^%^WHITE%^circle with horns atop a cross%^RESET%^%^RED%^, and reminds you of an alchemical symbol.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1100);
	set_lore(
@AVATAR
Although this robe is not unlike many worn by mages, it has been highly personalized.  The symbol on the back is the alchemical sign for mercury, also known as quicksilver.  It is a potent symbol for protection and magical changes in general.

AVATAR
	);
	set_property("lore difficulty",8);
	set_max_internal_encumbrance(20);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
}


