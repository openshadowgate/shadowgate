#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("pile of bones");
	set_id(({ "pile of bones", "bones", "remains" }));
	set_short("%^RESET%^a pile of %^BOLD%^%^WHITE%^bones%^RESET%^");
	set_obvious_short("%^RESET%^a pile of %^BOLD%^%^WHITE%^bones%^RESET%^");
	set_long(
@AVATAR
This looks like the remains of what was likely a small to medium sized animal.  The bones are stripped clean of flesh and even the marrow has been drained, leaving only the off white bones themselves.  Odder still, the bones look to have been snapped or crushed, but not chewed upon, leaving you to wonder just what sort of creature did this.

AVATAR
	);
	set_weight(5);
	set_value(0);
}