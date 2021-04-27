#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("corpseshayna");
	set_id(({ "corpse", "elf", "shayna" }));
	set_short("Corpse of Shayna");
	set_obvious_short("Corpse of Shayna");
	set_long(
@AVATAR
This is the badly beaten and wounded body of the elven mage named Shayna.  Her body is nude and heavily bruised all over.  There are numerous cuts all over as welll. Most notable is the carving of a hand in her forehead.  From the looks, this was a painful and humiliating death.

AVATAR
	);
	set_weight(60);
	set_value(0);
	set_lore(
@AVATAR
This is the body of the elven mage known as Shayna.

AVATAR
	);
	set_property("lore difficulty",15);
}