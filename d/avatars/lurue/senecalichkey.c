#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("key");
	set_id(({ "key", "mithril key" }));
	set_short("%^BOLD%^%^WHITE%^A mithril key%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A mithril key%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This key doesn't look all that important except that it is made of mithril which makes it a bit different, as well as stronger, than your usual brass and copper keys.  Otherwise, there are no markings or similar distinguishing marks that set it apart.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1000);
}
