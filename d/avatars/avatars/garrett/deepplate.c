#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Plate of the Deep");
	set_id(({ "plate of the deep", " plate", " deepplate", " Plate of the Deep", " Plate", " DeepPlate", " Deepplate" }));
	set_short("%^BLUE%^Plate of the Deep%^RESET%^");
	set_obvious_short("%^BOLD%^BLUE%^Aqua coloured platemail%^RESET%^");
	set_long(
@AVATAR
This %^BLUE%^aqua blue%^RESET%^ platemail is covered in crests of waves and is is of the finest craftsmanship.

AVATAR
	);
	set_weight(75);
	set_value(12500);
	set_lore(
@AVATAR
This armor is rumored to allow the wearer to breathe underwater while it is worn.

AVATAR
	);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(8);
	set_wear((:TO,"wear_func":));
	set_unwield((:TO,"unwield_func":));
}
int wear_func(){
	tell_room(ETP,""+TP->query_cap_name()+" wears the "+query_short()+" and the blue waves ripple along the armor.",TP);
	tell_object(TP,"You don the "+query_short()+" and feel somewhat more secure.");
	return 1;
}
int remove_func(){
	tell_room(ETP,""+TP->query_cap_name()+" takes off the "+query_short()+" as the wave pattern on the armor stops and looks much more dry.",TP);
	tell_object(TP,"You remove the "+query_short()+" and the air tastes somewhat more dry.");
	return 1;
}
