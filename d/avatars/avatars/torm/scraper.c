#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("skinning knife");
	set_id(({ "knife", "skinning knife", "scraper" }));
	set_short("%^RESET%^%^ORANGE%^Skinning %^RESET%^Knife");
	set_obvious_short("%^RESET%^a scraper");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a small knife.  It has one sharpened edge which is slightly curved.  This type of knife is commonly used in the wilderness as %^RED%^a tool for paring away the skin from prey%^ORANGE%^ in order to preserve it so that it can be used for a variety of other things.  This one has a short wooden handle that has been %^BOLD%^%^BLACK%^bound by a dark cord %^RESET%^%^ORANGE%^in order to provide a firm grip.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(150);
	set_lore(
@AVATAR
%^RED%^Knives like this are used by people skilled in the art of skinning.  The slightly curved blade helps to separate the skin from the layer of muscle underneath.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",0);
	set_type("piercing");
	set_prof_type("tool");
	set_size(1);
	set_wc(2,3);
	set_large_wc(2,3);
	set_property("enchantment",0);
}


