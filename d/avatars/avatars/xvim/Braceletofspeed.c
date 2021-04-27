#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Bracelet of Speed");
	set_id(({ "bracelet" }));
	set_short("%^B_BLUE%^Bracelet of Speed");
	set_obvious_short("a old bracelet");
	set_long(
@AVATAR
%^RED%^This magical bracelet offers the wearer the speed of a running horse, the agility of a pixie and endurance of a thri-kreen

AVATAR
	);
	set_weight(5);
	set_value(500);
	set_lore(
@AVATAR
The ancients speak of the Mighty Bracelet of speed, it is foretold to bring great glory to its wearer.

AVATAR
	);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_unwield((:TO,"unwield_func":));
}
int wear_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"%^B_BLUE%^You wear the Bracelet and feel %^WHITE%^Lighting fast");
	TP->add_stat_bonus("dexterity",2);
	return 1;
}
int remove_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"%^B_BLUE%^You remove the braclet and feel yourself slowing down");
	TP->add_stat_bonus("dexterity",2);
	return 1;
}
