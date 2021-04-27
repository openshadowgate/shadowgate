#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("corpse");
	set_id(({ "corpse", "body", "limbs" }));
	set_short("%^RESET%^%^RED%^The mutilated corpse of a wandering guard%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^The mutilated corpse of a wandering guard%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^RED%^This seems to be the corpse of a wandering guard although he appears to have gone through a veritable mincer. His chain mail has been ripped asunder by great force and on what remains of his body you see several long deep scars, almost sickle-like in their nature. The stomach and most of the intestines have been removed as well as half of his face and several fingers. There is a very real and tangible stench of death here.


AVATAR
	);
	set_weight(110);
	set_value(0);
	set_lore(
@AVATAR
%^RESET%^%^RED%^You might almost believe that a cat would have caused these wounds were they not so long and deep.

AVATAR
	);
	set_property("lore difficulty",0);
}