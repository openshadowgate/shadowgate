#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Vial of Blood");
	set_id(({ "vial" }));
	set_short("%^RED%^Vial of Blood");
	set_obvious_short("%^RED%^Vial of Blood");
	set_long(
@AVATAR
%^RED%^This is a small vial full of blood. Its red liquid swirling within the small tube. One can wonder why someone would fill a vial with blood.

AVATAR
	);
	set_weight(1);
	set_value(0);
}