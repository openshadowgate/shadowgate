#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Hawk Shield");
	set_id(({ "shield" }));
	set_short("%^YELLOW%^Shield of the W%^RED%^a%^YELLOW%^rh%^BLUE%^a%^YELLOW%^wk%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^Diamond-shaped %^YELLOW%^hawk %^RESET%^%^ORANGE%^shield%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^A burnished sheet of golden metal has been fitted over this diamond shaped shield.  Etched into the surface and outlined in a darker bronze metal is
the image of a %^YELLOW%^hawk%^RESET%^%^ORANGE%^ with its wings outstretched.  Each feather down to the breast is intricately detailed and brushed with a finish that causes the avian figure to appear lifelike and moving.  %^BOLD%^%^BLUE%^Sapphires%^RESET%^%^ORANGE%^ have been set in the eyes and %^BOLD%^%^BLACK%^black opals%^RESET%^%^ORANGE%^ have been used to create the beak and claws.  Clutched in the beak of the mighty bird is a jewel hilted saber, fashioned in %^BOLD%^%^WHITE%^silver%^RESET%^%^ORANGE%^ and sporting %^BOLD%^%^WHITE%^dia%^CYAN%^m%^WHITE%^onds%^RESET%^%^ORANGE%^, %^RED%^rubies%^ORANGE%^ and %^BOLD%^%^RED%^fire opals%^RESET%^%^ORANGE%^ across the
hilt.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(2100);
	set_type("shield");
	set_limbs(({ "right arm" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^ORANGE%^As "+ETOQCN+" dons the shield, they seem emboldened!%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^You hear the drums of war as you don the shield%^RESET%^");
	return 1;
}

