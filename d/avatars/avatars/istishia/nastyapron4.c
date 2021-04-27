#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("nasty apron");
	set_id(({ "apron", " nasty apron" }));
	set_short("%^ORANGE%^a n%^RED%^a%^ORANGE%^sty, s%^GREEN%^t%^ORANGE%^a%^RED%^i%^ORANGE%^n%^GREEN%^ed %^ORANGE%^apron%^RESET%^");
	set_obvious_short("%^ORANGE%^a n%^RED%^a%^ORANGE%^sty, s%^GREEN%^t%^ORANGE%^a%^RED%^i%^ORANGE%^n%^GREEN%^ed %^ORANGE%^apron%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This disgusting, ragged piece of cloth appears to have seen several generations worth of use. Its strings are frayed and the apron itself is covered with %^GREEN%^spl%^RED%^o%^GREEN%^tc%^ORANGE%^h%^RED%^e%^ORANGE%^s of unidentifiable matter.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
}


