#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Sword of War");
	set_id(({ "sword" }));
	set_short("%^BLUE%^Sword of%^WHITE%^ War");
	set_obvious_short("%^BLUE%^Sword of%^WHITE%^ War");
	set_long(
@AVATAR
%^BLUE%^The Sword of %^WHITE%^War%^BLUE%^ was created by %^GREEN%^Gond%^BLUE%^ many decades ago, under orders from the great Warlord %^RED%^Tempus%^BLUE%^himself. The blade is a long sword, forged in Dark Admantinium covered with %^RED%^red runes.%^BLUE%^ The hilt has a small golden plaque with some writing on it.

AVATAR
	);
	set("read",
@AVATAR
%^RED%^"Through My will shall you conquer, through my strength they shall perish"

AVATAR
	);
	set_weight(5);
	set_value(5000);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(5,4);
	set_large_wc(5,5);
	set_property("enchantment",3);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,""+TP->query_cap_name()+" wields the "+query_short()+" and looks magically stronger",TP);
	tell_object(TP,"You wield the "+query_short()+" and feel magical strength run through you");
	TP->add_stat_bonus("strength",1);
	return 1;
}
int unwield_func(){
	tell_room(ETP,""+TP->query_cap_name()+" unwields the "+query_short()+" and doesnt look as strong anymore",TP);
	tell_object(TP,"You unwield the "+query_short()+" and feel the magic disappear");
	TP->add_stat_bonus("strength",-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),""+targ->query_cap_name()+" screams out in pain as "+ETO->query_cap_name()+" wielding "+query_short()+" hits hard",({ETO,targ}));
	tell_object(ETO,""+targ->query_cap_name()+" screams out in pain as you hit it with your "+query_short()+"");
	tell_object(targ,""+ETO->query_cap_name()+" swings his "+query_short()+" at you and hits you good");
		return roll_dice(3,4)+-1;	}
}
