#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("felroot");
	set_id(({ "felroot", "root", "common felroot" }));
	set_short("%^YELLOW%^A long felroot%^RESET%^");
	set_obvious_short("%^YELLOW%^A long felroot%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This long root is a deep orange in color.  It is continually wet, even after lacking any water, and strangely heavy.  Its said to grow in thin and light forest and some say it has magical attributes.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(100);
}