#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("corpse");
	set_id(({ "corpse", "body", "deceased" }));
	set_short("Bloody corpse.");
	set_obvious_short("Bloody corpse of Krugar.");
	set_long(
@AVATAR
This is the dead body of Krugar. In life he would have looked like: %^RESET%^Krugar stands at an average height for a male human.  But his body type is well-built.  He has a barrel chest with broad shoulders and heavily muscled arms.  His skin is a deep shade of brown and has a worn leathered look as if he has spent a great deal of time in the sun.  He has sun-bleached blond hair and cold green eyes.  He is fully armored with well maintained equipment.  You see this man as nothing but a fierce looking warrior.

AVATAR
	);
	set_weight(150);
	set_value(0);
	set_property("lore difficulty",0);
}