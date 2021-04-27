#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("bone armor");
	set_id(({ "armor", "leather", "bone armor", "bone" }));
	set_short("%^BOLD%^%^WHITE%^B%^BLACK%^o%^WHITE%^ne Arm%^BLACK%^o%^WHITE%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Leather and %^WHITE%^bone %^BLACK%^armor%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a suit of leather armor, reinforced in bone.  The leather shirt has long sleeves and a tall collar.  It is soft and pliable.  Where the leather would cover vital areas, whole %^WHITE%^bones%^BLACK%^ have been sewn into the armor.  %^WHITE%^Ribs%^BLACK%^ protect the torso, and larger, stronger %^WHITE%^bones%^BLACK%^ line the arms, wrists and chest plate.%^RESET%^ %^BOLD%^%^BLACK%^Large %^WHITE%^knuckle bones%^BLACK%^ form buttons to secure the armor along one's side.%^RESET%^

AVATAR
	);
	set_weight(25);
	set_value(1200);
	set_lore(
@AVATAR
Historical records indicate that bones have been used in armor like this for centuries, if not longer, but this suit represents a more modern manifestation of this process.  The bones probably come from cattle or another strong-framed beast of burden, are polished and carefully preserved before being affixed to the dark leather.  It is an intimidating item, and others like it have been used by the clergy of Kelemvor and Bane.

AVATAR
	);
	set_property("lore difficulty",7);
	set("chabonus",-1);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^As "+ETOQCN+" wears the bone armor, they begin to look scary.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You feel positively ghoulish in the bone armor.%^RESET%^");
	ETO->add_damage_bonus(1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^As "+ETOQCN+" removes the bone armor, they look less ghoulish.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You feel less frightening outside of the bone armor.%^RESET%^");
	ETO->add_damage_bonus(-1);
	return 1;
}
