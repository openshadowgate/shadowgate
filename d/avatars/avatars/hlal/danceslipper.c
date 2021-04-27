#include <std.h>
inherit "/d/common/obj/clothing/shoes";

void create(){
	::create();
	set_name("dance slippers");
	set_id(({ "slipper", "slippers", "shoes", "dance slippers" }));
	set_short("%^ORANGE%^d%^RED%^a%^ORANGE%^n%^BOLD%^c%^RESET%^%^ORANGE%^e s%^BOLD%^l%^RESET%^%^ORANGE%^i%^RED%^p%^BOLD%^%^ORANGE%^p%^RESET%^%^ORANGE%^ers%^RESET%^");
	set_obvious_short("%^ORANGE%^d%^RED%^a%^ORANGE%^n%^BOLD%^c%^RESET%^%^ORANGE%^e s%^BOLD%^l%^RESET%^%^ORANGE%^i%^RED%^p%^BOLD%^%^ORANGE%^p%^RESET%^%^ORANGE%^ers%^RESET%^");
	set_long("%^RED%^Designed to be both fashionable and lightweight, these slippers would be comfortable upon the feet of anyone who enjoys the art of dancing. The soft upper, trimmed with a rich %^ORANGE%^g%^BOLD"
	"%^o%^RESET%^%^ORANGE%^ld brocade, %^RED%^is made of a cotton and satin blend affording these slippers a %^WHITE%^gentle sheen %^RED%^which allows the deep color to shift through various hues as the we"
	"arer moves. %^BOLD%^%^BLACK%^Tiny g%^RED%^a%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^nets %^RESET%^%^RED%^affixed sporadically amongst the gilded brocade trim afford a luxurious, %^BOLD%^sparkling %^RESET%^%^"
	"RED%^quality to this demure accessory which is an absolute must-have for even the most demanding of dancers.%^RESET%^
"	);
	set_value(8500);
	set_item_bonus("damage resistance",2);
	set_item_bonus("endurance",2);
	set_item_bonus("stealth",-1);
	set_size(2);
	set_property("enchantment",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^RED%^"+ETOQCN+" %^RED%^can't seem to resist showing off a dance move or two as they wear the comfy looking "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^The mood to dance overcomes you as the comfy slippers sing as they are worn.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^RED%^"+ETOQCN+" %^RED%^carefully removes the "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^You carefully remove your "+query_short()+"%^RESET%^");
	return 1;
}

