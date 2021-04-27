#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Lock of hair");
	set_id(({ "lock", "hair" }));
	set_short("A lock of hair");
	set_obvious_short("lock of hair");
	set_long(
@AVATAR
This is a lock of gray hair. It is not in a good condition.

AVATAR
	);
	set_weight(1);
	set_value(0);
}