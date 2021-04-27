#include <std.h>
inherit ARMOUR;

void create(){
	::create();
        set_name("amulet");
	set_id(({ "amulet", "necklace", "peaceful rest" }));
        set_short("%^BLACK%^%^BOLD%^Peaceful Rest%^RESET%^");
        set_obvious_short("%^BLACK%^%^BOLD%^triangular amulet of ebony%^RESET%^");
	set_long(
@AVATAR
%^BLACK%^%^BOLD%^This amulet is a large charm of triangular shape.  It is metallic that has been polished to a high sheen.  It is a shiny shade of ebony.  In its center is a raised up right skeletal arm holding a %^YELLOW%^golden %^WHITE%^scales %^BLACK%^of justice.  The amulet is suspended on a fine link silver chain nearly 22" long.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(5000);
	set_lore(
@AVATAR
This is a powerful artifact called Restful Peace.  It is rumored to have been made for Kelemvor by Mystra herself.

AVATAR
	);
	set_property("lore difficulty",20);
        set_type("clothing");
        set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3);
        set_ac(0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" slips on the amulet and looks calm and peaceful.",ETO);
	tell_object(ETO,"You slip on the Amulet and feel a sense of peace and calm.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" removes the Amulet and looks a little less peaceful.",ETO);
	tell_object(ETO,"You remove the Amulet with a sense of sorrow.");
	return 1;
}
