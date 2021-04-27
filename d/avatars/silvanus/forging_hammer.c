#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Forging Hammer");
	set_id(({ "hammer", "forging hammer", "dwarven forging hammer", "dwarven hammer" }));
	set_short("%^RED%^Forging Hammer%^RESET%^");
	set_obvious_short("hammer");
	set_long(
@AVATAR
%^RED%^This hammer is only about three feet long and made from a stout %^BLUE%^mithril%^RESET%^%^RED%^.  Engraved into the shaft of the hammer are %^BLUE%^ancient%^RESET%^%^RED%^ dwarven %^BLUE%^runes%^RESET%^%^RED%^.  Engraved into the head of the hammer are the symbols of the ancient dwarven Gods.%^RESET%^

AVATAR
	);
	set_weight(25);
	set_value(1000);
	set_type("bludgeoning");
	set_prof_type("forging hammer");
	set_size(1);
	set_wc(2,4);
	set_large_wc(1,8);
	set_property("enchantment",3);
}


