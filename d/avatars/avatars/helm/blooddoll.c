#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("doll");
	set_id(({ "doll", "toy", "ragged doll", "ragdoll" }));
	set_short("%^RESET%^%^ORANGE%^A ragged blood-stained doll%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A ragged blood-stained doll%^RESET%^");
	set_long(
@AVATAR
This is a small ragged doll made out of straw and wool with a simple white cloth used as a dress. It appears to have seen much use and is probably a young girl's most favoured toy, or was. Most of the straw and wool are now a deep red color and the cloth is sputtered with red stains.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_property("lore difficulty",0);
}