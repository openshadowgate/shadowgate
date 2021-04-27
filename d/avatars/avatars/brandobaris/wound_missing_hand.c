#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
	::create();
	set_name("missing hand");
	set_id(({ "hand", "missing hand", "stump", "wound" }));
	set_short("%^RESET%^%^RED%^a %^BOLD%^missing %^RESET%^%^RED%^right hand%^WHITE%^");
	set_obvious_short("%^RESET%^%^RED%^a %^BOLD%^missing %^RESET%^%^RED%^right hand%^WHITE%^");
	set_long("%^RED%^A person's right hand would normally go here, if something had not removed it. Instead, all that is left is a c%^BOLD%^a%^RESET%^%^ORANGE%^u%^BOLD%^%^RED%^t%^BLACK%^e%^RESET%^%^ORANGE%^r%^BOLD%"
	"^%^RED%^i%^WHITE%^z%^RED%^e%^RESET%^%^RED%^d %^ORANGE%^s%^MAGENTA%^t%^ORANGE%^u%^WHITE%^m%^ORANGE%^p%^RED%^.%^WHITE%^

"	);
	set_value(0);
	set_lore("Once upon a time, someone cut your hand off.

Ouch.

The End
");
	set_property("lore difficulty",0);
	set_item_bonus("caster level",-3);
	set_item_bonus("dexterity",-2);
	set_size(2);
	set_property("enchantment",0);
}



