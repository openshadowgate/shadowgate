#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("parchment");
	set_id(({ "parchment", "sheet" }));
	set_short("%^BOLD%^%^WHITE%^A sheet of the finest quality parchment%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A sheet of the finest quality parchment%^RESET%^");
	set_long(
@AVATAR
This is a sheet of the finest quality parchment available.  It is obviously old, but has mysteriously escaped the telltale yellowing that is common with age.  Inscribed upon it are intricate %^BOLD%^%^RED%^Dwarven runes %^RESET%^that literally pulse and glow with a %^RESET%^%^RED%^deep red light%^RESET%^.

AVATAR
	);
	set_weight(2);
	set_value(0);
	set_property("lore difficulty",0);
}