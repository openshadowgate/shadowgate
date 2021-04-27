#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("ruby");
	set_id(({ "ruby", "soulgem", "gem", "soul ruby", " soul gem", "ruby eye" }));
	set_short("%^BOLD%^%^RED%^Red Ruby%^RESET%^");
	set_obvious_short("medium ruby");
	set_long(
@AVATAR
This is a medium to large sized perfectly cut ruby.  It is about one and a half inches in diameter, and perfectly cut so that light refracts through it, giving it the illusion that it is much larger on the inside than it would appear.  It would probably fetch quite a nice price.

AVATAR
	);
	set_weight(1);
	set_value(650);
}