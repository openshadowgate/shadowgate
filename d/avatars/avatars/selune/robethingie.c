#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("lunar robe");
	set_id(({ "robe", "lunar robe" }));
	set_short("%^BLUE%^Lunar%^RESET%^ %^CYAN%^Robe%^RESET%^");
	set_obvious_short("%^BLUE%^Lunar%^RESET%^ %^CYAN%^Robe%^RESET%^");
	set_long(
@AVATAR
%^BLUE%^This robe is made of the finest velvet which has been dyed a royal blue color.  The sleeves and collar have been embroidered with golden thread in an intricate design.  The robe is long, ending just at the wearer's ankles.  A golden cord wraps around the wearer's waist allowing them to keep the robe tied around their body.
%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^CYAN%^You wear your robe and suddenly feel a sense of serenity.%^RESET%^

AVATAR
	);
     set("langage","str");	set_weight(20);
	set_value(500);
	set_type("clothing");
	set_limbs(({ "right arm", "left arm" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
}


