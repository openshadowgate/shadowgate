#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("starheart");
	set_id(({ "gem", "heart", "starheart" }));
	set_short("%^BOLD%^%^BLUE%^The Star%^WHITE%^heart%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^A large %^WHITE%^softly%^BLUE%^ glowing%^CYAN%^ gem%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This is a large, softly glowing gem. It's properties are lost to you. Light flickers and pulses from within it%^RESET%^

AVATAR
	);
	set_weight(15);
	set_value(0);
}