#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^Bracelet%^RESET%^ of %^BOLD%^%^BLACK%^Control%^RESET%^");
	set_id(({ "bracelet", "bracelet of control" }));
	set_short("%^BOLD%^Bracelet%^RESET%^ of %^BOLD%^%^BLACK%^Control%^RESET%^");
	set_obvious_short("bracelet");
	set_long(
@AVATAR
This bracelet is of a simple design. It is perfectly circular and made of smooth polished %^BOLD%^%^BLACK%^onyx%^RESET%^.  Carved in the center is a %^BOLD%^nine-tailed scourge%^RESET%^.  It is beautiful it its simplicity and looking at this bracelet you realize you just have to wear it.

AVATAR
	);
	set_weight(1);
	set_value(300);
	set_lore(
@AVATAR
This bracelet is rumored to have been commissioned by the royal House of Kaleshour. It is made by an archmage in their employ. Wearing this bracelet supposedly puts the wearer under their full control.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
}


