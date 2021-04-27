#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BOLD%^%^WHITE%^A vial of %^RESET%^%^RED%^blood%^RESET%^");
	set_id(({ "bottle", "vial", "vial of blood", "bottle of blood", "blood" }));
	set_short("%^BOLD%^%^WHITE%^A vial of %^RESET%^%^RED%^blood%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a small vial generally used for healing vials, this one contains a %^RESET%^%^RED%^dark red %^BOLD%^%^WHITE%^liquid that resembles %^RED%^blood%^WHITE%^.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}