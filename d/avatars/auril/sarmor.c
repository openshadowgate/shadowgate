#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("spiked armor");
	set_id(({ "armor", "spiked armor", "unhallowed" }));
	set_short("%^BOLD%^%^BLACK%^Unhallowed Soul%^RESET%^");
	set_obvious_short("A suit of spiked full plate");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Exquisite and carefully made, this suit of %^RESET%^%^CYAN%^full plate %^BOLD%^%^BLACK%^is something to behold. The entire body is covered with this heavy, powerful armor. Across the entire area of the armor, %^RESET%^%^RED%^bloody %^BOLD%^%^BLACK%^spikes protrude omniously. The full plate is connected by small latches along the sides, which seem to magically hold secure. The workmanship is absolutely flawless and there are no scratches or dents in the strangely beautiful armor. A true masterpiece, you have not seen it's equal.%^RESET%^

AVATAR
	);
	set_weight(50);
	set_value(20000);
	set_lore(
@AVATAR
Worn by the nefarious general, Sestalk Broalk, leader of the City of Tonovi during it's conquests and expansion as a city state nearly a century ago, it is said to carry the souls of its victim with it.

AVATAR
	);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(9);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Strapping the armor on, you can hear the screams of tormented souls in your mind.");
	ETO->set_property("magic resistance",10);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The voices leave, fading back into the oblivious torment for which they must spend eternity.");
	ETO->set_property("magic resistance",-10);
	return 1;
}
