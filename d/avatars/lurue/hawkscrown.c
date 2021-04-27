#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("helm");
	set_id(({ "helm", "crown", "hawk crown", "hawks crown" }));
	set_short("%^YELLOW%^H%^RESET%^%^ORANGE%^a%^RESET%^w%^YELLOW%^ks C%^RESET%^%^ORANGE%^r%^RESET%^o%^YELLOW%^wn%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a winged helm%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This finely made helm is designed to fit around the head but leaves the face open for clear sight.  The meaning of which is clear considering a keen eyed hawk's head has been crafted into the crown. Two small %^RED%^rubies %^ORANGE%^have been set into the eyes of the head.  The way the gems are cut, the eyes seem to %^RED%^flash %^ORANGE%^back and forth, constantly watching its surroundings.  The hawk's beak curves out over the brow of the wearer, while the bird's wings curve upward and toward the back of the helm. Though made of steel, the metal has been treated with a bronze coating which gives it a warm color. %^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(1500);
	set_lore(
@AVATAR
The crown of the hawk is said to have been created deep in the Tsarven Empire several centuries ago.  Though the reason is unclear, rumors tell of a hawk cult who spent their life perfecting themselves and protecting the surrounding villages.  Though there are several stories about this cult, every one of them speaks of three things: The cult member's unwavering dedication to the people of the region.   The cult member's unwavering determination that could not be thwarted.  And finally the cult member's loyalty to his brothers and sisters.

AVATAR
	);
	set_property("lore difficulty",8);
	set_type("armor");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^You draw the helm over your head and feel empowered with conviction.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^The sense of conviction doesn't leave you, even as you take your helm off.%^RESET%^");
	return 1;
}

