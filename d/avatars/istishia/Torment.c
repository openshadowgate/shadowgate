#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Torment");
	set_id(({ "whip", "torment", "lash" }));
	set_short("%^BOLD%^%^BLACK%^T%^RESET%^%^RED%^o%^BLACK%^%^BOLD%^rm%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^nt%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^B%^RED%^a%^BLACK%^rb%^RED%^e%^BLACK%^d %^RED%^demonhide %^BLACK%^l%^RED%^a%^BLACK%^sh%^RESET%^");
	set_long(
@AVATAR

 %^RED%^This lash, braided of the scaly hide of demons is viciously interwoven with shards of %^BOLD%^%^BLACK%^obsidian%^RESET%^%^RED%^ and sharpened fragments of %^BOLD%^%^WHITE%^ivory%^RESET%^%^RED%^ that have been stained a bright %^BOLD%^crimson%^RESET%^%^RED%^ with blood. The length of the lash itself braids down into a handle of solid %^BOLD%^%^BLACK%^adamantite%^RESET%^%^RED%^ gilded with %^WHITE%^silver%^RED%^ and embossed on the base with the scourge whip, symbol of the lady of pain.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(100000);
	set_property("lore difficulty",0);
	set_type("bludgeoning");
	set_prof_type("medium whip");
	set_size(2);
	set_wc(4,6);
	set_large_wc(4,6);
	set_property("enchantment",6);
	set_ac(2);
}


