#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword";

void create(){
	::create();
	set_name("tusk");
	set_id(({ "tusk" }));
	set_short("%^BOLD%^%^WHITE%^Massive Mammoth Tusk%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Massive Mammoth Tusk%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This is an enormous ivory tusk of a Forest Mammoth. It grows to be about as long as a lance, and is solid ivory. These things would be worth a fortune to the unscrupulous merchants wh"
	"o would traffic in such a thing. To be struck by such a tusk would most likely result in complete dismemberment!%^RESET%^
"
	);
	set_value(10000);
	set_property("enchantment",2);
}



