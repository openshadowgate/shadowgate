#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("eyestalks");
	set_id(({ "eyestalks", "eye", "eyes" }));
	set_short("%^BOLD%^%^RED%^Shabranigdo's eyestalks%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^Shabranigdo's eyestalks%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^Shabranigdo's eyestalks are not intended for players to have.  If you are holding this item, please offer them or have ask an immortal to take them away.  Thank you.. <Tiamat>%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_type("lash");
	set_prof_type("whip");
	set_size(4);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",2);
}



