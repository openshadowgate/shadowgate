#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^RESET%^%^BOLD%^White of the Paingiver%^RESET%^");
	set_id(({ "whip", "scourge whip", "paingiver" }));
	set_short("%^BOLD%^%^BLACK%^Wh%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^p %^RESET%^of the %^RESET%^%^RED%^P%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^ing%^BOLD%^%^RED%^i%^RESET%^%^RED%^ver%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^nine-tailed scourge%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^One would have to be truly %^RESET%^%^RED%^depraved%^BOLD%^%^BLACK%^ to even consider wielding this weapon. The handle is wrapped in hard leather, dyed black, red and white. The %^RESET%^c%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^o%^RED%^p%^BOLD%^%^BLACK%^h%^RESET%^o%^RED%^n%^BOLD%^%^BLACK%^y of colors mingles together in a chaotic pattern. Sharp and uneven %^RESET%^metal spikes%^BOLD%^%^BLACK%^ protrude from the tip of the handle, making this weapon effective at not only lashing but bludgeoning.  Most menacing are the nine %^RESET%^%^RED%^lashes%^BOLD%^%^BLACK%^ of the whip, which are a foot or two longer than a typical scourge whip. Each strand is tipped with a small, sharpened %^RESET%^talon%^BOLD%^%^BLACK%^. Metal %^RESET%^%^RED%^thorns%^BOLD%^%^BLACK%^ line the strands, too small to see but %^RESET%^sharp%^BOLD%^%^BLACK%^ enough to cause a great deal of %^BOLD%^%^WHITE%^pain%^BLACK%^.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(3000);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^Gifted to the Paingiver.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",3);
	set_type("bludgeoning");
	set_prof_type("whip");
	set_size(2);
	set_wc(4,24);
	set_large_wc(4,24);
	set_property("enchantment",3);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETOQCN+" grins %^RESET%^sadistically%^RESET%^%^RED%^.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Glorius %^RESET%^%^RED%^pain %^BOLD%^%^BLACK%^courses through your veins as you wield the whip.");
	ETO->do_damage("torso",random(1));
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" looks longingly at the "+query_short()+" as it's placed aside.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^RED%^Releasing the weapon, you are filled with a sense of longing.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+targ->QCN+" cries out %^RED%^miserably %^BOLD%^%^BLACK%^as "+ETOQCN+" strikes.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^"+targ->QCN+" %^BOLD%^%^BLACK%^screams in %^RED%^pain %^BOLD%^%^BLACK%^as the lashes of the "+query_short()+" tear across exposed flesh.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^You scream out in %^RESET%^d%^BOLD%^%^BLACK%^i%^RESET%^z%^BOLD%^%^RED%^z%^BOLD%^%^BLACK%^y%^RESET%^i%^RED%^n%^BOLD%^%^BLACK%^g %^BOLD%^%^RED%^pain and fear as "+ETOQCN+" lashes you with the "+query_short()+".%^RESET%^");
		targ->set_paralyzed(roll_dice(3,6)+1);
return 0;	}
}