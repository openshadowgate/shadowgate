#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("stone");
	set_id(({ "stone" }));
	set_short("%^RESET%^%^ORANGE%^A %^BOLD%^%^RED%^ward %^RESET%^%^ORANGE%^stone%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A %^BOLD%^%^RED%^ward %^RESET%^%^ORANGE%^stone%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This stone has a %^BOLD%^%^RED%^glyph %^RESET%^%^ORANGE%^inscribed on it. Small %^BOLD%^%^YELLOW%^magical %^RESET%^%^ORANGE%^energies charge over the glyph slowly. The stone is fairly heavy for its size.

AVATAR
	);
	set_weight(1);
	set_value(0);
}