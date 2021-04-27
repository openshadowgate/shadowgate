#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("a %^BLUE%^soiled%^RESET%^ loincloth");
	set_id(({ "loin", "loincloth", "soiled loincloth" }));
	set_short("a %^BLUE%^soiled%^RESET%^ loincloth");
	set_long(
@AVATAR
This is a raggedy loincloth that seems to have been %^BLUE%^soiled%^RESET%^ in some manner that you care not to find out about. It's made out of some sort of crude %^ORANGE%^hide%^RESET%^ and secures around the waist to hide one's nether regions from view.

AVATAR
	);
	set_weight(2);
	set_value(0);
	set_type("ring");
	set_limbs(({ "left leg", "right leg" }));
	set_size(1);
	set_property("enchantment",0);
}


