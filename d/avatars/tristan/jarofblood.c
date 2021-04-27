#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("jar");
	set_id(({ "jar", " jar of blood", " blood", " elf blood" }));
	set_short("%^BOLD%^%^RED%^Jar of blood");
	set_obvious_short("%^BOLD%^%^RED%^Jar of Blood");
	set_long(
@AVATAR
This is a small jar of blood. The consistency is thick, and the bottle is somewhat warm. The blood has the characteristics of elf blood.

AVATAR
	);
	set_weight(5);
	set_value(10);
	set_property("lore difficulty",0);
}