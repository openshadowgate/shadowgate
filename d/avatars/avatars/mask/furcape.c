#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^Fur C%^RESET%^%^WHITE%^l%^BOLD%^%^BLACK%^oak%^RESET%^");
	set_id(({ "cloak", "fur cloak" }));
	set_short("%^BOLD%^%^BLACK%^Hag%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^ath's Warm%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^h%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Fur C%^RESET%^%^WHITE%^l%^BOLD%^%^BLACK%^oak%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a small cloak crafted from a single, magnificent wolfskin.  The fur remains on the hide, mostly black, but with pat%^RESET%^%^WHITE%^ch%^BOLD%^%^BLACK%^es and s%^RESET%^%^WHITE%^t%^BOLD%^%^BLACK%^rea%^RESET%^%^WHITE%^k%^BOLD%^%^BLACK%^s of grey, as if it might have belonged to an old wolf.  The cloak is held in place by a short %^BOLD%^%^WHITE%^mit%^RESET%^%^WHITE%^h%^BOLD%^%^WHITE%^ril c%^RESET%^%^WHITE%^h%^BOLD%^%^WHITE%^a%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^n %^BOLD%^%^BLACK%^that attaches to two sturdy clasps fashioned after a wolf's paw.  The cloak is somewhat roomy and wide, almost as if it was meant to be worn over armor, and falls to the ankles, providing ample protection from the elements.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(250);
	set_lore(
@AVATAR
%^BOLD%^%^RED%^Hagrath was a dwarven hunter and trapper well known among the dwarven communities in frozen parts of the world, always providing only the best quality furs to his fellows.  One story however is recorded that states that one wolf, old, wily, and strong beyond compare had eluded capture for many years, and had been responsible for the deaths of many invaluable farm beasts.  The old hunter heard of the wolf when taking shelter one night, and set out the next day, only to return with a fine black and silver pelt.  He never related exactly what he'd done, but that it only involved a bit of string, a rabbit, and a very large tree.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(1);
	set_property("enchantment",2);
}


