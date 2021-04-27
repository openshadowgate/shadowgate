#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("corpse");
	set_id(({ "corpse", "body", "farmer" }));
	set_short("%^RESET%^%^RED%^the half-eaten corpse of a farmer.%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^the half-eaten corpse of a farmer.%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^RED%^This is the upper part of the body of what appears to be one of the farmers in this area. A strong smell of sulphur lingers over the corpse where the chest has been visciously ripped open by something large and very sharp. Entrails are spilled in a heap on the ground at the side of the corpse the scene is gross and unexplainable.%^RESET%^

AVATAR
	);
	set_weight(67);
	set_value(0);
}