#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("clasp");
	set_id(({ "claps" }));
	set_short("%^YELLOW%^The Magistrae's Cloak Clasp%^RESET%^");
	set_obvious_short("cloak clasp");
	set_long(
@AVATAR
%^YELLOW%^A brilliant yellow gold clasp fashioned into the image of a triangle.  Within the triangle three interlocking rings made from %^WHITE%^platinum%^YELLOW%^, %^CYAN%^electrum%^WHITE%^ and %^RESET%^%^ORANGE%^copper%^YELLOW%^ are attached to the triangle.  The clasp features a long gold pin that slips into the cloak and a locking device.

AVATAR
	);
	set_weight(1);
	set_value(5000);
	set_lore(
@AVATAR
The Magistrate's Cloak Clasp what an artifact left over from the rule of the previous Lord of Shadow, before the Empire Invaded and his highness left for unknown lands.

AVATAR
	);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^You slip the pin through your cloak and secure it in place.");
	ETO->add_stat_bonus("constitution",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^You unfasten the pin and slip out the clasp, but keep it close to you.");
	ETO->add_stat_bonus("constitution",-1);
	return 1;
}
