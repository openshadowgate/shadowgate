#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("item_name");
	set_id(({ "ID" }));
	set_short("short_describe");
	set_obvious_short("obvious_short");
	set_long(
@AVATAR
long_describe

AVATAR
	);
	set("read",
@AVATAR

Read

AVATAR
	);
     set("langage","common");	set_weight(10);
	set_value(100);
	set_lore(
@AVATAR
Lore

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"The wield message the room gets",ETO);
	tell_object(ETO,"The wield message you get");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"The room unwielded",ETO);
	tell_object(ETO,"You unwielded");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 10){
	tell_room(environment(query_wielded()),"He hit",({ETO,targ}));
	tell_object(ETO,"You hit");
	tell_object(targ,"he hit you");
		return roll_dice(0,0)+0;	}
}