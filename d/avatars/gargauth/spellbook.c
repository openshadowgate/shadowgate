#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BOLD%^%^WHITE%^A %^BOLD%^%^BLACK%^spellbook %^BOLD%^%^WHITE%^covered in %^RED%^blood%^RESET%^");
	set_id(({ "book", " spellbook" }));
	set_short("%^RESET%^A %^BOLD%^%^BLACK%^spellbook %^RESET%^covered in %^RED%^blood%^RESET%^");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(0);
	set_value(0);
}