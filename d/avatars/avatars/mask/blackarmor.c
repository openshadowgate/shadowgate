#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("Kezzilik's Skin");
	set_id(({ "skin", "black leather", "armor" }));
	set_short("%^BOLD%^%^BLACK%^K%^BOLD%^%^BLUE%^e%^BOLD%^%^BLACK%^zzil%^BOLD%^%^BLUE%^i%^BOLD%^%^BLACK%^k's Sk%^BOLD%^%^BLUE%^i%^BOLD%^%^BLACK%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^black leather armor%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a suit of strange, form fitting leather armor that is pure black, save for the random streaks of blue that shift through it.  It seems to be a wonderfully crafted suit, as no amount of movement ever makes it creak or make noise of any sort.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
This armor was made by the Shadowlord himself, from the skin of a shadow dragon named Kezzilik.  Noone knows why Mask saw fit to kill the dragon precisely, but the end result is certainly magnificent.

AVATAR
	);
	set_property("lore difficulty",30);
	set_max_internal_encumbrance(250);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",30);
	set_ac(10);
}


