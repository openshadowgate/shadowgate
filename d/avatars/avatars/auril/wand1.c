#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("wand");
	set_id(({ "wand" }));
	set_short("%^BOLD%^%^WHITE%^A g%^RESET%^%^WHITE%^ran%^BOLD%^%^WHITE%^ite wand%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A g%^RESET%^%^WHITE%^ran%^BOLD%^%^WHITE%^ite wand%^RESET%^");
	set_long(
@AVATAR
This is a long %^BOLD%^%^WHITE%^granite %^RESET%^wand.

AVATAR
	);
	set_weight(1);
	set_value(0);
}