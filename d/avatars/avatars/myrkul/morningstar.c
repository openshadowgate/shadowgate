#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("morningstar");
	set_id(({ "morning star", "star", "morning star" }));
	set_short("%^BOLD%^%^YELLOW%^Lathanderite %^RED%^morning%^YELLOW%^ star%^RESET%^");
	set_obvious_short("%^BOLD%^%^YELLOW%^Lathanderite %^RED%^morning%^YELLOW%^ star%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^YELLOW%^This morning star is used by the heavy infantry of Lathander's church. It look like a giant spiked ball on a stick. It aught to leave one hell of a mess! It takes a lot of strength to use these morning stars, and this one looks to be no exception.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(100);
	set_lore(
@AVATAR
This morning star was used by the Lathanderite forces in the battle against the Maskarrans in the town of Shadow. The Maskarrans attempted to take over the thieves guild in 694 SG. The leader of the Lathanderites named Azalon led many warriors into battle, and his forces used these weapons. 

AVATAR
	);
	set_property("lore difficulty",5);
	set_type("bludgeoning");
	set_prof_type("mace");
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",2);
}



