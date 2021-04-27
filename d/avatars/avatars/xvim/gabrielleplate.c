#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Armour of Pain");
	set_id(({ "plate", "fullplate", "full plate" }));
	set_short("%^BOLD%^%^BLACK%^Armor of %^RED%^Blood%^RESET%^");
	set_obvious_short("a red fullplate");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This Black plate is obviously made to fit the female body, with round curves, to heave up the bosom, and shape the female figure. A bit unusually it has large sharp iron spikes pointing outwards from several places, enabling the wearer to hurt an opponent by ramming into them, at the abdomen of the armor, there is a huge %^WHITE%^white symbol of Loviatar%^BLACK%^ on it%^RESET%^

AVATAR
	);
	set_weight(65);
	set_value(20000);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(7);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"%^BOLD%^%^BLACK%^You buckle up the plate, and feel a strange energy run through your body.");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"%^BOLD%^%^BLACK%^You remove the heavy plate, and stretches in relief");
	ETO->set_property("magic resistance",5);
	return 1;
}
