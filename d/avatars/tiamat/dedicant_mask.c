#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("hawk mask");
	set_id(({ "mask", "headdress", "hawk mask" }));
	set_short("%^ORANGE%^M%^YELLOW%^a%^RESET%^%^ORANGE%^s%^YELLOW%^k%^RESET%^%^ORANGE%^ of the W%^RED%^a%^ORANGE%^r%^RED%^h%^ORANGE%^a%^RED%^w%^ORANGE%^k%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^pl%^BOLD%^ume%^RESET%^%^RED%^d %^YELLOW%^golden %^RESET%^%^ORANGE%^mask%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^The article before you is part mask, part headdress.  The majority of the band and face plate are crafted from copper, forming a disk on the wearers forehead.  Sprouting from the disk are three %^RED%^f%^BOLD%^ie%^RESET%^%^RED%^ry %^BOLD%^fe%^BLACK%^a%^RESET%^%^RED%^th%^BOLD%^ers%^RESET%^%^ORANGE%^ almost a foot in length each and fanned out in even intervals.  The most stunning feature to this headgear is the mask, attached to the band near the temples, forged from copper and highly decorated in %^YELLOW%^gold%^RESET%^%^ORANGE%^ into the shape of a bird of prey's face and beak.  The %^YELLOW%^golden mask%^RESET%^%^ORANGE%^ is worn in such a way that the wearer peers out of the birds eyes, while the beak cleverly protects the nose as well as hides the identity, leaving only the mouth and chin exposed.  There is a sense of archaic symbolism about the mask.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(400);
	set_lore(
@AVATAR
There is little record about an item of this description, except for a few vague references to a hawk-worshipping cult that supposedly originated in the Tsarven Empire before the time of Shadow's independence.  Rumors abound that the cult still exists as a secret society with unknown motives and in the service of alien gods.

AVATAR
	);
	set_property("lore difficulty",25);
	set_type("chain");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^As "+ETOQCN+" wears the mask, they flinch as though hearing a loud noise.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You hear a hawk calling out loudly in your ears!%^RESET%^");
	ETO->set_property("magic resistance",4);
	return 1;
}

