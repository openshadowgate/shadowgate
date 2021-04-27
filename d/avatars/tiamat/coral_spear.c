#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("coral spear");
	set_id(({ "spear", "coral", "coral spear" }));
	set_short("%^RESET%^%^BOLD%^%^MAGENTA%^C%^WHITE%^o%^CYAN%^r%^MAGENTA%^al Spear%^RESET%^");
	set_obvious_short("%^BOLD%^%^MAGENTA%^c%^BOLD%^%^WHITE%^o%^MAGENTA%^ral%^RESET%^-tipped spear%^RESET%^");
	set_long(
@AVATAR
%^MAGENTA%^ This is a short spear, its shaft is crafted from lightweight and rust resistant %^BOLD%^%^WHITE%^adamantium%^RESET%^%^MAGENTA%^.  The shaft is only slightly decorated in a sea-shell motif designed into the shaft where the wielder grips the spear.  The spear head is made from a cluster of %^BOLD%^%^MAGENTA%^coral %^RESET%^%^MAGENTA%^that has barely been modified from its natural state.  Sharp, jagged edges run the entire length of the deadly spear tip.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(2100);
	set_lore(
@AVATAR
%^RESET%^Coral spears are the favored weapon of many mer-folk and aquatic elves.  They are designed to be nearly invulnerable to rust or deterioration while still preserving the natural, and dangerous elegance of native coral.  They are usually wielded in one hand, so that they can be easily thrown or used while still swimming.   Though a relatively common weapon of the deep, only rarely are they magical.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",12);
	set_type("piercing");
	set_prof_type("spear");
	set_size(2);
	set_wc(1,7);
	set_large_wc(1,8);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" wields a spear, and looks over the coral tip.%^RESET%^",ETO);
	tell_object(ETO,"%^MAGENTA%^You wield the spear, admiring the coral tip.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" puts down their coral spear.%^RESET%^",ETO);
	tell_object(ETO,"%^MAGENTA%^You put down the spear, ready to hunt another day.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^MAGENTA%^The coral spear wielded by "+query_short()+" sinks deep into "+targ->QCN+"!!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^The jagged coral tip of the spear sinks deep into "+targ->QCN+"!!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^MAGENTA%^The coral spear wielded by "+ETOQCN+" sinks deep and twisting into you!!%^RESET%^");
		return roll_dice(1,6)+2;	}
}