#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("daedinblade");
	set_id(({ "sword", "longsword", "long sword", "family sword" }));
	set_short("%^BOLD%^%^WHITE%^A silver bladed longsword%^RESET%^");
