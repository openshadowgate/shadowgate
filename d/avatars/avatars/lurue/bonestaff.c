#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("bone staff");
	set_id(({ "staff", "bonestaff", "bone staff", "staff of bones" }));
	set_short("%^BOLD%^%^BLACK%^Staff of %^WHITE%^B%^BLACK%^o%^RESET%^n%^BOLD%^%^WHITE%^e%^BLACK%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a bone staff%^RESET%^");
	set_long(
@AVATAR

%^BOLD%^%^BLACK%^This long staff holds a core of hard %^RESET%^%^CYAN%^iron wood%^BOLD%^%^BLACK%^ but over its surface have been affixed slivers of polished %^WHITE%^B%^BLACK%^o%^RESET%^n%^BOLD%^%^WHITE%^e%^BLACK%^.  Each bone has been fitted till the entire length of the quarterstaff is covered.  Around each tip a %^RESET%^%^CYAN%^steel cap%^BOLD%^%^BLACK%^ has been affixed, making this a strong fighting weapon. Covering the center, where the hands would grasp is a wide swath of black leather that forms a secure grip.%^RESET%^


AVATAR
	);
	set_weight(4);
	set_value(1000);
	set_lore(
@AVATAR

It is said that the Staff of Bones was created from the bones of saints and martyrs.  That the weapon, when faced with difficult odds, will grant the wielder insight and prowess in the battle they fight.  So long as the battle is a just one that follows the dictates of the Lord of the Dead.

AVATAR
	);
	set_property("lore difficulty",8);
	set_type("bludgeoning");
	set_prof_type("staff");
	set_size(3);
	set_wc(2,4);
	set_large_wc(2,5);
	set_property("enchantment",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You grip the %^WHITE%^B%^BLACK%^o%^RESET%^n%^BOLD%^%^WHITE%^e%^BLACK%^ Staff securely and prepare for battle!%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You rest for now, but look forward to the day when you can stop your enemies once more.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+" seems to see an opening in "+targ->QCN+"'s defenses and strikes foward, sending a %^WHITE%^ghostly %^BLACK%^wave of energy into "+targ->QCN+"'s body!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^WHITE%^b%^BLACK%^o%^RESET%^n%^BOLD%^%^WHITE%^e%^BLACK%^s of your staff begin to glow with a brilliant %^WHITE%^ghostly%^BLACK%^ aura.  Suddenly, you see an opening in "+targ->QCN+"'s defenses and strike out, sending a wave of %^WHITE%^power%^BLACK%^ through them.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" seems to see an opening in your defenses and strikes foward, sending a %^WHITE%^ghostly %^BLACK%^wave of energy into your body!%^RESET%^");
		return roll_dice(2,4)+3;	}

}
