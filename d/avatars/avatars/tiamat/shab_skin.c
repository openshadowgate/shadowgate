#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("hide of beholder");
	set_id(({ "hide", "armor", "skin" }));
	set_short("%^RESET%^%^RED%^beholder hide%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^beholder hide%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^RED%^beholder hide is not a normal item.  It is for immortal use only.  If you find this item and you are a player or high mortal, please offer the item or ask for an immortal to take the item away.  Thank you ---Tiamat.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(8);
}



