#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("hawk mask");
	set_id(({ "mask", "hawk mask", "headdress" }));
	set_short("%^RESET%^%^YELLOW%^Mask %^RESET%^%^ORANGE%^of the %^YELLOW%^W%^RED%^a%^YELLOW%^rh%^RED%^a%^YELLOW%^w%^RED%^k%^RESET%^");
	set_obvious_short("%^RED%^pl%^BOLD%^ume%^RESET%^%^RED%^d %^YELLOW%^golden %^RESET%^%^ORANGE%^mask%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^The article before you is part mask, part headdress.  The majority of the
band and face plate are crafted from copper, forming a disk on the wearers
forehead.  Sprouting from the disk are three %^RED%^fi%^BOLD%^er%^RESET%^%^RED%^y %^BOLD%^fe%^BLACK%^a%^RESET%^%^RED%^th%^BOLD%^er%^RESET%^%^RED%^s %^ORANGE%^almost a foot
in length each and fanned out in even intervals.  The most stunning feature
to this headgear is the mask, attached to the band near the temples, forged
from copper and highly decorated in %^YELLOW%^gold%^RESET%^%^ORANGE%^ into the shape of a bird of prey's
face and beak.  The %^YELLOW%^golden mask%^RESET%^%^ORANGE%^ is worn in such a way that the wearer peers
out of the birds eyes, while the beak cleverly protects the nose as well as
hides the identity, leaving only the mouth and chin exposed.  There is a
sense of archaic symbolism about the mask.%^RESET%^


AVATAR
	);
	set_weight(2);
	set_value(400);
	set_lore(
@AVATAR
There is little record about an item of this description, except for a few
vague references to a hawk-worshipping cult that supposedly originated in
the Tsarven Empire before the time of Shadow's independence.  Rumors abound
that the cult still exists as a secret society with unknown motives and in
the service of alien gods.

AVATAR
	);
	set_property("lore difficulty",25);
	set_type("chain");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^As "+ETOQCN+" wears the mask, they flinch as though hearing a loud noise.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You hear the scream of a hawk loudly in your ears!%^RESET%^");
	ETO->set_property("magic resistance",3);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" removes the mask and rubs their ears.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You remove the mask and rub your ears.%^RESET%^");
	ETO->set_property("magic resistance",-3);
	return 1;
}
