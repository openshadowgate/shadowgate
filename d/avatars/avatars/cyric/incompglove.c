#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("glove");
	set_id(({ "glove", " blue glove", " odd glove" }));
	set_short("%^RESET%^%^BLUE%^Odd Glove%^RESET%^");
	set_long(
@AVATAR
This is an odd looking glove made from a blue leathery material.  There are several straps to secure the glove to the wearer's forearm, and a pair of metal strips on top of the glove running from the wrist to the knuckles.  There is also a small hole in the palm of the glove.  While you're not quite sure what this glove is good for, it certainly is unique.

AVATAR
	);
	set("read",
@AVATAR
You can't read that!!

AVATAR
	);
	set_weight(4);
	set_value(200);
	set_type("leather");
	set_limbs(({ "left hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
}


