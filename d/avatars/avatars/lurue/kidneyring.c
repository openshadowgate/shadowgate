#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("ring");
	set_id(({ "ring", "hematite ring" }));
	set_short("%^BOLD%^%^BLACK%^P%^WHITE%^u%^RESET%^r%^BOLD%^%^WHITE%^g%^BLACK%^ing Stone%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a %^BLACK%^hematite%^WHITE%^ ring%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This simple ring is made from a smoothed piece of hematite that wraps all the way around a finger in a circular band.  The dark stone has a %^WHITE%^silvery%^BLACK%^ gloss to its otherwise black surface, and you can see the occasional fleck of %^YELLOW%^amber%^BLACK%^ sparkle deep within.  A pretty item, it seems like it might just be jewelry made out of a lovely piece of stone.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(100);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^Hematite has been long associated with purification and cleansing.  Said to draw the toxins from the body, the stone is often worn by those wishing to purge themselves both mentally and physically.  Most Hematite though doesn't have %^YELLOW%^amber flecks%^BLACK%^ within it, so something must have been done to change its makeup or it has another crystal growing within its matrix.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",0);
}



