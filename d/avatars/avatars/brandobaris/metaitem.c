#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("metaitem");
	set_id(({ "metaitem" }));
	set_short("a metaitem");
	set_obvious_short("a metaitem");
	set_long("This object is -basically- whatever.
");
	set_value(0);
	set_weight(0);
}
