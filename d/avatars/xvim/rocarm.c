#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("archer arm for roc");
	set_id(({ "arm" }));
	set_short("%^RED%^a severed arm from a imperial archer");
	set_obvious_short("%^RED%^a severed arm from a imperial archer");
	set_long(
@AVATAR
This is the arm of a now former imperial archer

AVATAR
	);
	set_weight(20);
	set_value(0);
}