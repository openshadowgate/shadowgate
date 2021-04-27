#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("wedding band");
	set_id(({ "band", "wedding band", "wedding ring" }));
	set_short("$&$korath$&$'s wedding band");
	set_obvious_short("$&$korath$&$'s wedding band");
	set_long(
@AVATAR
This is a simple wedding band that was once engraved, but has been worn down due to the passage of time and possibly other effects.

AVATAR
	);
	set("read",
@AVATAR
...with love...

AVATAR
	);
     set("langage","elven");	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
This is Korath's old wedding band that he wore when he was married to Schatten.**

AVATAR
	);
	set_type("ring");
	set_limbs(({ "left hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
}



init() {
  ::init();
  ETO->force_me("wear band");
}
