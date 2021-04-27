#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("katana");
	set_id(({ "katana", "sword" }));
	set_short("%^BOLD%^%^WHITE%^Swan Clan Katana%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Swan Clan Katana%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a shortened version of a katana used by Shogun Takeda Yuki's Swan Clan. The blade has no hilt, and extends about three feet in a gentle arc. The blade has been made with two kinds of steel. A soft steel on the back of the blade absorbs shock, while the the hardened steel of the edge is %^CYAN%^exceedingly sharp%^WHITE%^. The difference in steel qualities causes the blade to curve just so. The hilt is wrapped in an embroidered pattern of a %^BLACK%^black feather.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1000);
	set_lore(
@AVATAR
It is said that these blades were brought in by the Swan Clan to battle the Maskarran attempt to control the Shadow Thieves guild in 694 SG. The blades are of good quality, and the Swan Clan has gained some influence in the lands. 

AVATAR
	);
	set_property("lore difficulty",5);
	set_type("slashing");
	set_prof_type("medium blades");
      set_weapon_prof("exotic");
//added by ~Circe~ 5/12/11
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",2);
}



