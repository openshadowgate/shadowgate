#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("shaynacorpse");
	set_id(({ "elf", "corpse", "shayna" }));
	set_short("Corpse of Shayna");
	set_obvious_short("Corpse of Shayna");
	set_long(
@AVATAR
This is a the nude corpse of the female elven mage named Shayna.  The body is badly bruised and there are numerous cuts all over the body.  Notable is the carving of a hand in the corpse's forehead.  It looks like the elf suffered a horrible and painful death.

AVATAR
	);
	set_weight(60);
	set_value(0);
