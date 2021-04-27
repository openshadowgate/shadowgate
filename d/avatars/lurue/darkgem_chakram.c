#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("chakram");
	set_id(({ "fang", "chakram", "dark metal chakram", "metal chakram", "darkness' fang", "darkness fang" }));
	set_short("%^BOLD%^%^BLACK%^D%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rk%^RESET%^%^BLUE%^n%^MAGENTA%^e%^BOLD%^%^BLACK%^ss' F%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^ng%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a d%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^rk m%^RESET%^%^MAGENTA%^et%^BOLD%^%^BLACK%^al c%^RESET%^%^BLUE%^ha%^BOLD%^%^BLACK%^kr%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^m%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This razor sharp circle of dark steel is as deadly as it is fascinating to look upon.  Though simple in design, a hoop of metal with a cross band through its hollow center, the entire piece is beset with the faintest glint of the light absorbing inset gems.  Slivers of %^RESET%^%^RED%^dark rubies%^BOLD%^%^BLACK%^, %^RESET%^%^BLUE%^black sapphires%^BOLD%^%^BLACK%^, %^RESET%^%^MAGENTA%^dusky amethysts %^BOLD%^%^BLACK%^and %^RESET%^%^GREEN%^deep green emeralds %^BOLD%^%^BLACK%^are all ornately affixed to the wide band of metal that thins to deadly, razor edges.  Gripped by the onyx laced cross-guard that cuts through the center, this chakram seems sharp enough to slice through even the toughest steel.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(3200);
	set_lore(
@AVATAR
Given only to those who have proven faithful amongst the darkest of houses, these specially forged chakrams are created in the most secret of enclaves amongst the drow houses.  Next to nothing is known of their creation or the reason the patterns of gems are so intricate, but those who have felt the bite of these weapons often claim they did not know their limb had been severed until they looked upon the missing part.  Such is the swift sharpness of these devastating blades.

AVATAR
	);
	set_property("lore difficulty",28);
	set_type("piercing");
	set_prof_type("chakram");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,4);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+"'s eyes grow dark and unfocused as they take hold of "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The darkness slides over your body and wraps around your heart as you take hold of "+query_short()+"%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" gasps as though surfacing for air as they set the "+query_short()+"%^BOLD%^%^BLACK%^ aside.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You release your hold on "+query_short()+"%^BOLD%^%^BLACK%^ and wonder just what you did while you wallowed in the abyss of your dark soul.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+targ->QCN+" screams in agony as the chakram wielded by "+ETOQCN+" slices through all of "+targ->QCN+"'s protections and draws %^RED%^blood%^BLACK%^!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^The volatile eruption of "+targ->QCN+"'s %^RED%^life's blood%^BOLD%^%^BLACK%^ covers you as "+query_short()+"%^BOLD%^%^BLACK%^ cuts deep into their flesh.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^You look down at where "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^BLACK%^ cut across your body and you see the bright flow of %^RED%^life's blood%^BLACK%^ spurting from the deep wound!%^RESET%^");
		return roll_dice(4,4)+1;	}
}