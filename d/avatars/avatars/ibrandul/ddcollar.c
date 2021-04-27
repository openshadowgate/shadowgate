#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BLACK%^%^BOLD%^me%^RESET%^m%^BLACK%^%^BOLD%^ori%^MAGENTA%^e%^BLACK%^%^BOLD%^s of f%^RESET%^l%^BLACK%^%^BOLD%^ig%^MAGENTA%^h%^BLACK%^%^BOLD%^t%^RESET%^");
	set_id(({ "collar", "memories of flight" }));
	set_short("%^BLACK%^%^BOLD%^me%^RESET%^m%^BLACK%^%^BOLD%^ori%^MAGENTA%^e%^BLACK%^%^BOLD%^s of f%^RESET%^l%^BLACK%^%^BOLD%^ig%^MAGENTA%^h%^BLACK%^%^BOLD%^t%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^ag%^BLACK%^%^BOLD%^e%^RESET%^%^ORANGE%^d le%^RESET%^a%^ORANGE%^the%^BLACK%^%^BOLD%^r%^RESET%^%^ORANGE%^ col%^BLACK%^%^BOLD%^l%^RESET%^%^ORANGE%^ar%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^created from %^BLACK%^%^BOLD%^dark leather%^RESET%^%^ORANGE%^ that has been cured and dyed, this collar looks very old. Yet it has held up very well to the ravages of time. It is studded with small %^RESET%^raw d%^BOLD%^i%^RESET%^amo%^BOLD%^n%^RESET%^ds%^RESET%^%^ORANGE%^ that catch the %^RESET%^%^BOLD%^light%^RESET%^%^ORANGE%^ and hold it, almost as if they refuse to shine. The collar attaches with a small %^RESET%^%^BOLD%^silver clasp%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(10000);
	set_lore(
@AVATAR
crafted by a magus centuries ago, the collar was blessed by a dying copper dragon who bequethed a portion of her memories to it. There is power in it, but it is untapped, as if she hid it somehow. 

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",1);
     set_ac(-1);
      set("wisbonus",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+"%^BLACK%^%^BOLD%^ clasps on the collar, blinking a few times%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^As you clasp on the collar, your vision swims for a moment, then clears as your mind grasps the vastness around you%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+"%^BLACK%^%^BOLD%^ slips off the collar, blinking a few times%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^As you remove the collar, you feel small and insignificant%^RESET%^");
	return 1;
}
