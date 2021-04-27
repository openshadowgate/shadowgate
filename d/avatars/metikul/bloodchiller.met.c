#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("frostcovered falchion");
	set_id(({ "falchion", " frosted falchion", " sword" }));
	set_short("%^BLUE%^Bloodchiller Falchion%^RESET%^");
	set_obvious_short("frostcovered falchion");
	set_long(
@AVATAR
%^BLUE%^This remarkably crafted falchion has a heavy, wide, curved blade covered in frost. The edge of the sword seems sheathed in a thin layer of ice as the air around it gives off an uneasy chill.  The hilt, made of %^BOLD%^%^CYAN%^pure ice%^RESET%^, is wrapped in scales that glisten like mirrors and run criss-cross along the hilt of the weapon. The pommel is a large %^WHITE%^%^BOLD%^diamond%^RESET%^ which eminates power. The guard of the falchion has %^BOLD%^%^CYAN%^streaks of frost%^RESET%^ intertwined with the steel.%^RESET%^

AVATAR
	);
	set_weight(25);
	set_value(2500);
	set_lore(
@AVATAR
%^BLUE%^ Bloodchiller%^RESET%^ was created by Metikul the artificer on a comission from an Auril follower.  This weapon was constructed from materials used by %^BLACK%^%^BOLD%^Drow of Underdark%^RESET%^ for their artefacts and heavily infused with cold based magics.  It is a somewhat dangerous weapon to use as the ammount of magical energies stored in the artefact has turned parts of the weapon into an extremely tough and cold ice, a substance not known to be kind to mortal flesh.

AVATAR
	);
	set_type("slashing");
	set_prof_type("bloodchiller");
	set_size(2);
	set_wc(5,2);
	set_large_wc(5,3);
	set_property("enchantment",3);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,"%^BOLD%^%^CYAN%^A chill spreads through the air as "+TP->query_cap_name()+" wields "+query_short()+".%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^CYAN%^Your body is shocked by cold on contact with the falchion.%^RESET%^");
	TP->do_damage("torso",random(4d10));
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^BOLD%^%^CYAN%^The air around you regains its appropriate temperature.%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^CYAN%^You release "+query_short()+" and your body heat quickly returns to normal.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+" scowls as "+query_short()+" slices deep into "+targ->query_cap_name()+"'s flesh.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^"+query_short()+" slices deep into "+targ->query_cap_name()+"'s flesh.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^CYAN%^An unbearable chill spreads through your body as "+query_short()+" slices deep into your flesh.%^RESET%^");
		return roll_dice(10,2)+0;	}
}