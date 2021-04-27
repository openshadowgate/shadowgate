#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("bladequill");
	set_id(({ "quill", "sharp quill", "bladequill" }));
	set_short("%^BOLD%^%^RED%^Bl%^WHITE%^a%^RED%^dequ%^WHITE%^i%^RED%^ll%^RESET%^");
	set_obvious_short("%^BOLD%^%^MAGENTA%^An odd looking quill%^RESET%^");
	set_long(
@AVATAR
This strange looking item appears to be a quill at first glance.  In reality it is an impeccably sharpened piece of thin adamantium shaped in the likeness of a writers quill.  While not the most effective of weapons, it could be easily concealed.

AVATAR
	);
	set_weight(5);
	set_value(250);
	set_property("lore difficulty",0);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",2);
}


