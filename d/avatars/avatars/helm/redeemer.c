#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("two-handed sword");
	set_id(({ "two-handed sword", "twohander", "sword", "blade", "two handed sword", "redeemer", "weapon" }));
	set_short("%^RESET%^%^BOLD%^The Redeemer%^RESET%^");
	set_obvious_short("An old two-handed sword");
	set_long(
@AVATAR
This is an old two-handed sword, not really sharp but that's not exactly the point either.

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^CYAN%^areth u'thua meng' er nae%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(7);
	set_value(125);
	set_lore(
@AVATAR
The writing on the hilt of the sword seems strangely familiar although you are not quite sure what it means.

AVATAR
	);
	set_property("lore difficulty",5);
	set_type("slashing");
	set_prof_type("large blades");
	set_size(3);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",2);
}


