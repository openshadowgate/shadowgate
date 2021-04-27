#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("rubberboot");
	set_id(({ "Rubber boot", "boot" }));
	set_short("Rubber boot");
	set_obvious_short("Rubber boot");
	set_long(
@AVATAR
This is a small rubber boot. It looks as if it would fit a small being, like a gnome or halfling.  There is a fancy buckle on the boot.  Written on it is the word 'Fixel.'  The boot looks slick and wet...from blood.

AVATAR
	);
	set("read",
@AVATAR
The buckle reads, Fixel.

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(0);
}