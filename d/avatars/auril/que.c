#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("box");
	set_id(({ "box" }));
	set_short("%^BOLD%^%^GREEN%^Box of %^BOLD%^%^CYAN%^Eternity%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A small %^BOLD%^%^YELLOW%^golden %^RESET%^%^ORANGE%^box%^RESET%^");
	set_long(
@AVATAR
This small indescript box looks like it has no lid. A small circular groove is placed on each of the six faces of the cube. Each has a symbol: %^BOLD%^%^RED%^Star%^RESET%^,%^BOLD%^%^RED%^Moon%^RESET%^, %^BOLD%^%^RED%^Wolf%^RESET%^, %^BOLD%^%^RED%^Scimitar%^RESET%^, %^BOLD%^%^RED%^Shrine%^RESET%^, %^BOLD%^%^RED%^Coin%^RESET%^. The symbols are all in the direct center of the faces.

AVATAR
	);
	set_weight(5);
	set_value(25000);
}