#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("bearskin hood");
	set_id(({ "hood", "bearskin", "hat" }));
	set_short("%^RESET%^%^ORANGE%^Hood of the Bea%^ORANGE%^r%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a bearskin hood%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a thick hood, stitched together from the skin of a great brown bear.  The skin and upper skull of the bear's head has been left intact and fashioned into a protective hood.  The original %^WHITE%^fangs %^ORANGE%^of the bear remain, and when covering part of the face, would give the wearer a fierce appearance.  Part of the hide can be worn as a wrap over the shoulders, and fashions to the opposite end with a single, %^BOLD%^%^WHITE%^polished %^RESET%^claw%^ORANGE%^.  The fur is thick and dense, providing protection from attack as well as the elements.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(1200);
	set_lore(
@AVATAR
The brown bear is becoming rare in this part of the world.  In ages past, their skins were prized for protection, durability and beauty.  The hood in your hands must be an old and treasured item.  Rare specimens were enchanted by the druids of old.

AVATAR
	);
	set_property("lore difficulty",7);
	set_type("leather");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^ORANGE%^As "+ETOQCN+" wears the bear hood, they start to look like a savage beast!%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^You pull on the bear hood and feel the call of the wild!%^RESET%^");
	ETO->add_damage_bonus(1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^As "+ETOQCN+" remove their bear hood, they look much less savage.%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^The strength of the savage bear leaves you.%^RESET%^");
	ETO->add_damage_bonus(-1);
	return 1;
}
