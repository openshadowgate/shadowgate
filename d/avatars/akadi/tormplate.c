#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^YELLOW%^suit of g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n full plate armor%^RESET%^");
	set_id(({ "plate", "full plate", "fullplate", "armor" }));
	set_short("%^BOLD%^%^YELLOW%^Plate of the G%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n Lion%^RESET%^");
	set_obvious_short("%^YELLOW%^suit of g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n full plate armor%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^Made from the finest %^RESET%^steel%^ORANGE%^ in the lands, this magnificent suit of armor could only have been crafted by highly skilled and careful hands. Impressive in design and detail, it would be the envy of any great knight. The highly polished, reflective sheen of the %^YELLOW%^golden plates%^RESET%^%^ORANGE%^ is near blinding when struck by %^YELLOW%^s%^RESET%^%^ORANGE%^unligh%^YELLOW%^t%^RESET%^%^ORANGE%^. Smoothly cut rivets on the shoulders, hips and knees allow for greater movement and decoration. Treated to a high shine, the series of four rivets vary in hue, from %^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^ar%^BOLD%^%^BLACK%^k%^RESET%^%^ORANGE%^ to %^YELLOW%^li%^RESET%^%^ORANGE%^g%^YELLOW%^ht %^RESET%^%^ORANGE%^g%^YELLOW%^ol%^RESET%^%^ORANGE%^d. A magnificent %^RESET%^si%^BOLD%^lv%^RESET%^er %^BOLD%^dr%^RESET%^ag%^BOLD%^on%^RESET%^%^ORANGE%^ is beautifully etched into the stomach plate. The intricate image is outlined with %^RESET%^%^BOLD%^s%^RESET%^h%^BOLD%^ini%^RESET%^n%^BOLD%^g si%^RESET%^lv%^BOLD%^er%^RESET%^%^ORANGE%^ that is so highly reflective it almost seems to glows with an inner light. For added protection, %^RESET%^white %^BOLD%^mi%^RESET%^th%^BOLD%^ril %^RESET%^chain%^RESET%^%^ORANGE%^ skirts around the hips, tucked beneath plates of %^YELLOW%^g%^RESET%^%^ORANGE%^ol%^BOLD%^d%^RESET%^%^ORANGE%^, and is similarly applied to areas where flexibility is required. Fluted to fit perfectly, the armor is aesthetically pleasing and not overly cumbersome.%^RESET%^

AVATAR
	);
	set_weight(55);
	set_value(10000);
	set_lore(
@AVATAR
The master smith who crafted this armor was often considered to be a very insane man. Those that bothered to listen to his ranting, however, would tell you that he claimed Torm, The Brave, came to him in a vision and charged him to create the finest suit of armor ever known to man. Whether this is true or not, the smith did manage to create this exquisite suit of armor, which was unlike anything anyone had seen before, and admired by those privileged enough to see it. After destroying the mold, he quietly passed on, content with his masterpiece.

AVATAR
	);
	set_property("lore difficulty",16);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(9);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^The %^RESET%^s%^BOLD%^h%^RESET%^i%^BOLD%^n%^RESET%^i%^BOLD%^n%^RESET%^g %^YELLOW%^armor is surprisingly comfortable.%^RESET%^");
	ETO->add_stat_bonus("charisma",2);
	ETO->set_property("magic resistance",30);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("charisma",-2);
	ETO->set_property("magic resistance",-30);
	return 1;
}
