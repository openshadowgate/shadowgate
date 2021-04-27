#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("peacefulrest");
	set_id(({ "amulet", "necklace", "peaceful rest" }));
	set_short("%^BOLD%^%^BLACK%^Peaceful Rest%^RESET%^");
	set_obvious_short("Amulet");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This amulet is a large charm of triangular shape.  It is metallic that has been polished to a high sheen.  It is a shiny shade of ebony.  In its center is a raised up right skeletal arm holding a %^RESET%^%^YELLOW%^golden%^RESET%^%^BOLD%^ scales %^RESET%^%^BOLD%^%^BLACK%^ of justice.  The amulet is suspended on a fine link silver chain nearly 22" long.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1500);
	set_lore(
@AVATAR
This is Restful Peace. A powerful artifact cherished by Kelemvor's followers.  It is speculated that the amulet was made for Kelemvor by Mystra herself.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" slips on the $0 and looks at peace.",ETO);
	tell_object(ETO,"You slip on the $0 and feel a sense of peace and calm.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" looks sorrowful as the $0 is removed.",ETO);
	tell_object(ETO,"You remove the $0 and feel a twinge of sorrow.");
	return 1;
}
