#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("Black drow mage robe");
	set_id(({ "robe" }));
	set_short("%^BLUE%^Black drow mage robe");
	set_obvious_short("a black robe");
	set_long(
@AVATAR
%^BLUE%^This black robe looks like a pretty normal mage robe, except for a few design differences that give it the common drow look, it shields the wearer of blows. %^RED%^Strange red drow symbols flows through the inside of the fabric, and you are able to decypher some of it as pertaining to Lloth.

AVATAR
	);
	set("read",
@AVATAR
%^RED%^The wearer of this item will receive Lloth's blessing.
AVATAR
	);
	set_weight(10);
	set_value(500);
	set_lore(
@AVATAR


AVATAR
	);
	set_max_internal_encumbrance(25);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"%^BLUE%^ You wear the dark robe and feel protected "
	   "by Lloth's blessing on it.");
	TP->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"",TP);
	tell_object(TP," %^BLUE%^You remove the robe and feel the light burn your skin");
	TP->set_property("magic resistance",-5);
	return 1;
}
