#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("jar of spices");
	set_id(({ "jar", "jar of spice", "spice jar", " spices", "jar of spices", "spices", "spice" }));
	set_short("%^RESET%^%^CYAN%^a small %^RED%^s%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^i%^RED%^c%^BOLD%^%^BLACK%^e %^RESET%^%^CYAN%^jar made of glass%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a small glass jar%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This small jar is made with thick walls of blown glass.  The base of it is large and square, while the top narrows to about half the size of the bottom.  The glass is tinged a semi-opaque %^BLUE%^blue%^CYAN%^, but inside you can make out the dark colors of some sort of %^RED%^s%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^c%^RESET%^%^RED%^e %^CYAN%^mixture. Capping the jar is a tin lid which can be screwed on or off.  Over this is a half shield, also made of tin, has been affixed.  This can be rotated back and forth to reveal small holes in the lid on one side.  The holes appear to be designed to let the contents inside out, while the shield can be rotated to keep them in.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR

%^RED%^Made in Azha%^RESET%^
Contains red bell pepers, onion, sundried tomatoes, leeks, garlic, carrots, spinach, salt, black pepper, spices.


AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(100);
}