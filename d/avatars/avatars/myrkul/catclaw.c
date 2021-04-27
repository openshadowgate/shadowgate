#include <std.h>
inherit "/d/common/obj/weapon/claw";

void create(){
	::create();
	set_name("claws");
	set_id(({ "claws" }));
	set_short("%^BOLD%^%^WHITE%^Cat claws%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Cat claws%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^Cat claws, they are very short, very sharp, and licked clean regularly.%^RESET%^
");
	set_value(0);
	set_property("enchantment",1);
}



