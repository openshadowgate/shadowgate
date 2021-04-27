#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("robe");
	set_id(({ "robe", "robes" }));
	set_short("%^BOLD%^%^BLACK%^Auppenser's %^YELLOW%^Robe%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Auppenser's %^YELLOW%^Robe%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This robe is made of the lightest weight %^RESET%^%^BOLD%^silk.%^BLACK%^  Its base color is black with a %^YELLOW%^bronze satin interior%^BLACK%^ and round satin patches of %^YELLOW%^bronze.%^BLACK%^  The %^YELLOW%^patches%^BLACK%^ are somewhat %^RESET%^slick%^BOLD%^%^BLACK%^ looking due to their material.  Sewn into the patches are %^RESET%^%^CYAN%^cyan eyes%^BOLD%^%^BLACK%^ made from %^CYAN%^g%^RESET%^%^CYAN%^e%^BOLD%^ms%^RESET%^ %^BOLD%^%^BLACK%^making them %^RESET%^glitter%^BOLD%^%^BLACK%^ in the %^RESET%^light.%^BOLD%^%^BLACK%^  The sleeves of this robe are full-length down to the wearer's wrists and have a %^YELLOW%^bronze satin hem%^BLACK%^.  They are loose, like those of a %^ORANGE%^monk's robe.%^BOLD%^%^BLACK%^  The robe is a sraight line from the shoulders down to the hem, which ends at the wearer's ankles.  The robe is secured by a %^YELLOW%^bronze-colored hemp sash.%^BLACK%^ There are several pockets sewn inside the robe making storing books and components and other goodies easier.  Overall, the appearance of this robe is beautiful although a tiny bit %^RESET%^%^%^CYAN%^gawdy.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(150000);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^In distant days of yore, their was a male human born with extraordinary gifts of the mind.  The gods found favor with him yet mortals were jealous.  As a result, he was killed
but the gods took mercy and brought him back as a diety without a physical form.  This robe was a gift from the gods before his murder and is now worn by him even though he is a great spirit due to its great magic.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_max_internal_encumbrance(50);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",40);
	set_ac(500);
	set_wear((:TO,"wear_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" looks very smart as $G puts on the robe.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^looks very smart as $G puts on the robe.");
	return 1;
}

