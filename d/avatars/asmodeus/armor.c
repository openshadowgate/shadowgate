#include <std.h>
inherit "/d/common/obj/armour/studded";

void create(){
	::create();
	set_name("masterthief armor");
	set_id(({ "armor", "studded" }));
	set_short("%^BOLD%^%^BLACK%^Ma%^BLUE%^s%^BLACK%^ter R%^BLUE%^o%^BLACK%^gue's S%^BLUE%^u%^BLACK%^it%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Black studded leather armor%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This black suit has a streamline look to it.  The top and pants of this suit are sew in one continuous piece, offering a better fit to the outfit. Made from thin black leather it almo"
	"st looks like an iconic rogue's suit. The tapered legs of the suit are made to fit close to the wearer's body, to close one might think.  The top part of this garment is made to look like a sleeveless"
	" jerkin, and again fitting very close to the wearer's body.  A deep V down the front of the suit seems to be the only way into the garment, that sure looks like a tight fit.  A lightly embroidered pat"
	"tern of %^BLUE%^dag%^BLACK%^ge%^BLUE%^r%^BLACK%^s in d%^BLUE%^a%^BLACK%^rk %^BLUE%^blue%^BLACK%^ and black threads is sewn into the top of the suit, almost blending in with the dark black leather.%^RE"
	"SET%^
"	);
	set_value(15000);
	set_item_bonus("stealth",2);
	set_item_bonus("thievery",2);
	set_item_bonus("magic resistance",1);
	set_size(3);
	set_property("enchantment",4);
}



