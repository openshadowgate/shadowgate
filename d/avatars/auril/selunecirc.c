#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("circlet");
	set_id(({ "circlet" }));
	set_short("%^CYAN%^Circlet of the %^BOLD%^%^WHITE%^m%^WHITE%^o%^BLUE%^o%^BOLD%^%^BLUE%^n%^RESET%^");
	set_obvious_short("a platinum circlet");
	set_long(
@AVATAR
%^CYAN%^This beautifully crafted circlet is shaped to fit around the wearer's forehead with no discomfort. In the center is a %^BOLD%^%^BLUE%^sapphire moon %^CYAN%^that draws attention to it not because of it's focal point, but because if you look closely you can see %^BOLD%^%^WHITE%^stars %^CYAN%^within the gem, moving slowly in a rythmic pattern. The band is made of finely crafted %^BOLD%^%^WHITE%^platinum %^CYAN%^, and is exceptionally made.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","str");	set_weight(7);
	set_value(2000);
	set_type("armor");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,""+ETO->query_cap_name()+" slips on the circlet.",TP);
	tell_object(TP,"%^BOLD%^%^YELLOW%^You slip on the circlet and feel the presence of Selune.");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,""+ETO->query_cap_name()+" removes the circlet.",TP);
	tell_object(TP,"%^BOLD%^%^YELLOW%^You slip off the circlet, already missing the presence it brought.");
	ETO->set_property("magic resistance",-5);
	return 1;
}
