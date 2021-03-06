#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("skinning knife");
	set_id(({ "knife", " skinning knife" }));
	set_short("%^RESET%^A sharp %^BOLD%^%^BLUE%^steel %^RESET%^skinning knife");
	set_obvious_short("%^RESET%^A sharp %^BOLD%^%^BLUE%^steel %^RESET%^skinning knife");
	set_long(
@AVATAR
This is a razor sharp %^BOLD%^%^BLUE%^steel %^RESET%^skinning knife.  Its blade is about six inches long and has a filet blade along one side and a serrated edge along the other.  The handle is made from sturdy %^BOLD%^%^RED%^cherry %^RESET%^and has been skillfully wrapped with a dull %^BOLD%^%^WHITE%^white %^RESET%^leather cord.

AVATAR
	);
	set_weight(3);
	set_value(150);
	set_property("lore difficulty",0);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",0);
}


