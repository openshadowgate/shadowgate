#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("documents");
	set_id(({ "documents" }));
	set_short("A few documents");
	set_obvious_short("A few documents");
	set_long(
@AVATAR
This is a few love letters that are VERY telling. Damn these could be damning.

AVATAR
	);
	set_weight(1);
	set_value(1);
}