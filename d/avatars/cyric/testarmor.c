#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cloak");
	set_id(({ "cloak", " fur cloak" }));
	set_short("%^BOLD%^%^BLACK%^Fur Cloak%^RESET%^");
	set_obvious_short("cloak");
	set_long(
@AVATAR
This is a fine cloak made of the fur of some dead animal.  It has a dark color, almost black, and looks to be able to keep you warm in cold weather.

AVATAR
	);
	set("read",
@AVATAR
You can't read this.

AVATAR
	);
	set_weight(4);
	set_value(100);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_unwield((:TO,"unwield_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(ETP,""+TP->query_cap_name()+" wears a "+query_short()+"",TP);
	tell_object(TP,"You wear the "+query_short()+"");
	return 1;
}
int remove_func(){
	tell_room(ETP,"",TP);
	tell_object(TP,"");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < ){
	tell_room(environment(query_worn()),"",({ETO,who}));
	tell_object(ETO,"");
	tell_object(who,"");
	}
}