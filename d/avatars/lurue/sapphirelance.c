#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("sapphire lance");
	set_id(({ "sapphire lance", "lance", "lance of the stars", "star lance" }));
	set_short("%^BOLD%^%^BLUE%^L%^CYAN%^a%^RESET%^%^CYAN%^n%^BLUE%^c%^BOLD%^e %^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^f t%^CYAN%^h%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^ S%^RESET%^%^BLUE%^t%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^s%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^p%^BLUE%^p%^BOLD%^hi%^CYAN%^r%^RESET%^%^BLUE%^e %^BOLD%^l%^RESET%^%^CYAN%^a%^BLUE%^n%^BOLD%^%^CYAN%^c%^BLUE%^e%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^The wood used to make this lance is of such a deep and dark %^RESET%^%^BLUE%^blue%^BOLD%^, that when polished it gleams as though it were a pure piece of dark blue s%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^p%^BLUE%^p%^BOLD%^hi%^CYAN%^r%^RESET%^%^BLUE%^e%^BOLD%^.  The grip is wrapped in %^CYAN%^bright blue leather%^BLUE%^, trimmed in %^WHITE%^silver braid%^BLUE%^.  The hand guard is made of %^RESET%^titanium %^BOLD%^%^BLUE%^that glitters with hundreds of tiny facetted s%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^p%^BLUE%^p%^BOLD%^hi%^CYAN%^r%^RESET%^%^BLUE%^e%^CYAN%^s%^BOLD%^%^BLUE%^.  At the end of the lance the tip has also been capped with a sharp %^RESET%^titanium tip%^BOLD%^%^BLUE%^, making it a dangerous weapon.%^RESET%^

AVATAR
	);
	set_weight(15);
	set_value(4000);
	set_lore(
@AVATAR
The sapphire lance is said to have been created when a lightning bolt from the sky stuck an ancient blue cedar during a very powerful and raging storm. The trunk of the tree was severed and within the core, a perfect sliver of straight and perfect wood was found.  As the wood was treated the deep blue coloring became obvious and the weaponsmith who worked on the weapon night and day, soon discovered that the wood had also been touched with something else.  A gift from the stars!

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("piercing");
	set_prof_type("lance");
	set_property("lance",1);	set_size(3);
	set_wc(1,12);
	set_large_wc(1,12);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The "+query_short()+" %^BOLD%^%^CYAN%^settles into your hand as though it were an extension of your arm.%^RESET%^");
	ETO->add_attack_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^With a bit of reluctance you set the "+query_short()+" %^BOLD%^%^CYAN%^aside.%^RESET%^");
	ETO->add_attack_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^The wood of "+ETOQCN+"'s lance begins to %^BOLD%^%^BLUE%^glow brilliantly%^CYAN%^ just before they strike!  Like a %^BLUE%^blue star%^CYAN%^ bursting to life as it drives into "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^The wood of the lance begins to %^BOLD%^%^BLUE%^glow brilliantly%^CYAN%^ just before you strike!  Like a %^BLUE%^blue star%^CYAN%^ bursting to life as it drives into "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^CYAN%^The wood of "+ETOQCN+"'s lance begins to %^BOLD%^%^BLUE%^glow brilliantly%^CYAN%^ just before they strike!  Like a %^BLUE%^blue star%^CYAN%^ bursting to life as it drives into you!%^RESET%^");
		return roll_dice(2,6)+0;	}
}