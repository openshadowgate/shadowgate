#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLUE%^blue s%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^d%^BOLD%^%^BLUE%^e shoes%^RESET%^");
	set_id(({ "slippers", "shoes" }));
	set_short("%^BOLD%^%^BLUE%^blue s%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^d%^BOLD%^%^BLUE%^e shoes%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^blue s%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^d%^BOLD%^%^BLUE%^e shoes%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^Tailored from soft b%^RESET%^%^BLUE%^lu%^BOLD%^%^BLUE%^e suede, these lovely slippers would be a nice complement to any lady's wardrobe. The tips are softly rounded to curve comfortably around the wearer's toes. The insides have been lined with a delicate %^BOLD%^%^WHITE%^si%^RESET%^%^WHITE%^lv%^BOLD%^%^WHITE%^er %^BOLD%^%^BLUE%^cloth that would feel splendid to walk upon. %^RESET%^%^BLUE%^S%^CYAN%^i%^BLUE%^lk%^CYAN%^e%^BLUE%^n%^BOLD%^%^BLUE%^ blue %^RESET%^%^BLUE%^r%^CYAN%^ib%^RESET%^%^BLUE%^b%^CYAN%^on%^BLUE%^s%^BOLD%^%^BLUE%^ can be tied around the ankles and calves to assure the slipper stays securely in place. Seamless and exquisitely crafted, the sandals offer protection while not hindering comfort or mobility.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(500);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^Long ago, a group of divine dancers performed across the land, offering shows everywhere, from quaint inns to grand castles. Eventually the group vanished without a trace. It is thought that their dances were so graceful and beautiful, that they were called away from this plane to perform for the Gods forevermore. These shoes were a prized adornment of the ladies of the group.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",9);
	set_type("clothing");
	set_limbs(({ "right foot", "left foot" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^Your feet feel %^RESET%^%^MAGENTA%^fabulous%^BOLD%^%^MAGENTA%^ in these shoes!%^RESET%^");
	ETO->add_stat_bonus("dexterity",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^You slip off the sandals and miss their %^BOLD%^%^MAGENTA%^softness%^RESET%^%^MAGENTA%^ under your feet.%^RESET%^");
	ETO->add_stat_bonus("dexterity",-1);
	return 1;
}
