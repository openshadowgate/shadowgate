#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("meteoric mithril");
	set_id(({ "billet", "mithril", "meteoric mithril" }));
	set_short("%^RESET%^A billet of %^BOLD%^%^BLACK%^meteoric %^WHITE%^mithril%^RESET%^");
	set_obvious_short("%^RESET%^A billet of %^BOLD%^%^BLACK%^meteoric %^WHITE%^mithril%^RESET%^");
	set_long(
@AVATAR
This is a billet of mithril harvested from a fallen meteor.  It is twice as strong as earthbound mithril and a bit lighter.  There appears to be quite a bit here, perhaps enough for a set of armor.

AVATAR
	);
	set_weight(25);
	set_value(1000000);
	set_property("lore difficulty",0);
}