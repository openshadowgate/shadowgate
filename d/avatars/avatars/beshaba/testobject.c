#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("bobble");
	set_id(({ "bobble", "green bobble" }));
	set_short("%^RED%^Green Bobble of Testing%^RESET%^");
	set_obvious_short("a small %^GREEN%^round %^RESET%^bobble");
	set_long("This is a small round bobble about the size of a walnut. It is %^GREEN%^bright green %^RESET%^and sort of %^ORANGE%^lumpy%^RESET%^. It doesn't seem to have much of a purpose but is being used to show "
	"how to make an item that is an 'object'.
"
	);
	set_value(100);
	set_weight(2);
	set_lore("This item is said to be very rare and only made when an Avatar first starts to create items. Usually only seen for a few minutes after it is created, the %^GREEN%^green bobble%^RESET%^ is a magical de"
	"vice for training.
"
	);
    set_property("lore difficulty",10);
}
