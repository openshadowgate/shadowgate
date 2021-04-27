#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("small rod");
	set_id(({ "rod", "shocking rod", "metal rod" }));
	set_short("%^YELLOW%^s%^WHITE%^h%^BLACK%^o%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^k%^WHITE%^i%^YELLOW%^ng r%^BLACK%^o%^YELLOW%^d%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a small metal rod%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^Made of a deep %^BLUE%^b%^BOLD%^%^BLACK%^l%^BLUE%^u%^RESET%^%^BLUE%^e-b%^BOLD%^%^BLACK%^l%^BLUE%^a%^RESET%^%^BLUE%^ck %^CYAN%^metal, this rod is clearly a weapon of some type.  Designed to be held one handed, it features a grip at one end and a round knob at the other end.  The knob's metal is %^BLUE%^darker %^CYAN%^then the rest of the rod, looking %^BOLD%^%^BLACK%^scorched %^RESET%^%^CYAN%^and slightly %^RED%^melted %^CYAN%^as though something very hot touched it recently.  The %^BOLD%^%^BLACK%^leather wrap %^RESET%^%^CYAN%^is thick and just a little %^BLUE%^spongy%^CYAN%^, almost as if something is trapped under its coarse material.  Though what it might be is anyone's guess.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(4000);
	set_lore(
@AVATAR
Harnessing the element of lightning was one of Theodore LasRadis' many projects.  Though he didn't particularly care for the element itself, he did have interest in learning how to bind the raw energy within it into a usable power.  Though he made several items over the course of his life, these rods were some of his first attempts at capturing and retaining the power.  Unfortunately, most melted after several uses, though there is a rumor he made a few that actually held up to the constant use. - From the "Storm Master - The Madness of LasRadis", by Tabin Runiel

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("bludgeoning");
	set_prof_type("mace");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The smell of %^WHITE%^ozone%^BLACK%^ lifts into the air.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^As you take a firm grip on the rod, you feel something under the grip depress.  Suddenly a %^YELLOW%^crackling energy %^BLACK%^rushes about the knob at the other end and the crisp scent of %^WHITE%^ozone %^BLACK%^fills the air.%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The faint humming buzz fades away as "+ETOQCN+" puts their "+query_short()+" %^BOLD%^%^BLACK%^away.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel the hair on the back of your arms settle down as you put the "+query_short()+" %^BOLD%^%^BLACK%^away.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^There is a blinding flash of %^YELLOW%^lightning%^WHITE%^ from the tip of "+ETOQCN+"'s "+query_short()+"%^BOLD%^%^WHITE%^ followed quickly by a %^BLACK%^thundering boom %^WHITE%^as they strike "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^There is a crackle of %^YELLOW%^lightning %^WHITE%^and a loud boom of %^BLACK%^thunder %^WHITE%^as your "+query_short()+" %^BOLD%^%^WHITE%^strikes "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" strikes out with their "+query_short()+"%^WHITE%^ and your body shakes as a bolt of %^YELLOW%^lightning%^WHITE%^ and pulse of %^BLACK%^thunder%^WHITE%^ burn through you on contact!%^RESET%^");
		return roll_dice(4,4)+1;	}

}
