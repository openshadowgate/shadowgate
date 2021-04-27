#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("flail");
	set_id(({ "flail", "charmed flail" }));
	set_short("%^YELLOW%^C%^RESET%^%^ORANGE%^h%^WHITE%^a%^ORANGE%^r%^YELLOW%^med F%^RESET%^%^ORANGE%^l%^WHITE%^a%^YELLOW%^il%^RESET%^");
	set_obvious_short("%^RESET%^a %^YELLOW%^gold %^RESET%^and %^BOLD%^%^WHITE%^silver %^RESET%^flail");
	set_long(
@AVATAR
%^BOLD%^%^YELLOW%^The shaft of this white willow flail is wrapped neatly in bands of alternating %^WHITE%^white %^YELLOW%^and %^RESET%^%^ORANGE%^golden %^YELLOW%^leather that provide the weapon with a sure and firm grip.  Extending off the tip of the flail are a series of six %^WHITE%^silver chains%^YELLOW%^, each ending in a %^RESET%^%^ORANGE%^golden tip %^YELLOW%^shaped in the form of a celestial object.  Suns, moons, clouds and stars, each sparkling in the light and weighted to provide an efficient weapon.%^RESET%^

AVATAR
	);
	set_weight(15);
	set_value(100);
	set_lore(
@AVATAR
Weapons such as this are often considered more of a decoration piece then a truly useful weapon.  The mock flails feature tin or thin copper charms, but those meant to also serve as weapons are made from led cores that are then plated with more expensive metals to give them a rich appearance.  In the later half of the second century, weapons with symbols became popular for a time, especially amongst the young nobility.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("bludgeoning");
	set_prof_type("flail");
	set_size(2);
	set_wc(1,6);
	set_large_wc(2,4);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^YELLOW%^The charms of "+ETOQCN+"'s "+query_short()+"%^YELLOW%^ glitter in the light as they strike "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^The charms of your "+query_short()+"%^YELLOW%^ glitter in the light as they strike "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^YELLOW%^The charms of "+ETOQCN+"'s "+query_short()+"%^YELLOW%^ glitter in the light as they strike you!%^RESET%^");
		return roll_dice(1,4)+0;	}
}