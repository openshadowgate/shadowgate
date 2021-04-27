#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("red brocade robe");
	set_id(({ "robe", "brocade robe", " red robe", " robes", " red brocade robe", " speaker's robe", " robe of the speaker" }));
	set_short("%^BOLD%^%^BLACK%^Robe %^RED%^of the %^BLACK%^S%^RED%^p%^BLACK%^e%^RED%^a%^BLACK%^k%^RED%^e%^BLACK%^r%^RESET%^");
	set_obvious_short("%^RED%^red brocade robe%^RESET%^");
	set_long(
@AVATAR
%^RED%^This exquisite robe is made of superior red brocade with %^BOLD%^%^BLACK%^black %^RESET%^%^RED%^and %^YELLOW%^gold %^RESET%^%^RED%^threads.  The threads are worked into flowing scrollwork designs that seem to be vines.  Looking closer, you can see that the vines have tiny thorns growing upon them and seem to shift of their own accord.  The robes are tailored to fit close to the body, and a wide %^BOLD%^%^BLACK%^leather belt %^RESET%^%^RED%^gathers the material at the waist.  The robes reach all the way to the wearer's ankles, and the sleeves are wide, draping below the wearer's hands in a deep point.

AVATAR
	);
	set_weight(8);
	set_value(325);
	set_lore(
@AVATAR
The Robe of the Speaker has been lost to the world for some time.  It is said that an ancient god once granted robes such as this to his most dedicated follower but that god, along with his people, have fallen out of memory.  Strange that a robe such as this should be found now...

AVATAR
	);
	set_max_internal_encumbrance(21);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
}


