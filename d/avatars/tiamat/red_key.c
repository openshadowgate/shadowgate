#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("red key");
	set_id(({ "key", "red key" }));
	set_short("%^BOLD%^%^RED%^A red key%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A red key%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^A red key, probably used somewhere in this keep.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1);
}