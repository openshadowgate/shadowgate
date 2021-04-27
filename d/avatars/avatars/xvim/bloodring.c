#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Veziors bloodrings");
	set_id(({ "ring" }));
	set_short("%^YELLOW%^a %^BLACK%^s%^WHITE%^ilv%^BLACK%^er %^RED%^ring with a bloodr%^YELLOW%^e%^RED%^d gem%^RESET%^");
	set_obvious_short("%^RED%^a bloodred ring%^RESET%^");
	set_long(
@AVATAR
%^RED%^This is a %^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^ilv%^BOLD%^%^BLACK%^er %^RESET%^%^RED%^ring with a bloodr%^YELLOW%^e%^RED%^d gem. There are several notable marks from the tools that forged it. The gem is a shard of stone that seems to have been
crushed by a hammer, and forged into the ring. Whenever %^YELLOW%^l%^RED%^ig%^YELLOW%^h%^RED%^t strikes the gem, it glimmers faintly and emanates a weak red low. When you look closer you can see %^BLACK%^ancient runes %^RED%^carved inside the ring. You can feel a strong aura of evil flowing from this ring.

AVATAR
	);
	set_weight(2);
	set_value(5);
	set_type("ring");
	set_limbs(({ "left hand" }));
	set_property("enchantment",0);
}


