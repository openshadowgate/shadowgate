#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("an item");
	set_id(({ "item" }));
	set_short("An item");
	set_obvious_short("An item");
	set_long("An item of generic shape and form.
");
	set_value(0);
	set_weight(1);
}
