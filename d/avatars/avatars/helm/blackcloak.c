#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cloak");
	set_id(({ "cloak", "black cloak" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^a black cloak%^RESET%^");
	set_obvious_short("a black cloak");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a pitch-black cloak held together by a simple %^RESET%^%^BOLD%^si%^RESET%^lver cl%^BOLD%^asp%^BLACK%^. It flows off the wearers back as smooth as darkness and as softly as the night itself. The inside is lined with plush %^RESET%^%^RED%^c%^BOLD%^rims%^RESET%^%^RED%^on %^BOLD%^%^BLACK%^velvet that seems to shift in hue and color as the cloak moves.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(752);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
}


