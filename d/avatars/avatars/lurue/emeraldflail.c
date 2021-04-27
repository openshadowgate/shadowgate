#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("flail");
	set_id(({ "flail", "emerald flail", "ivory flail", "emerald coil", "coil" }));
	set_short("%^BOLD%^%^GREEN%^E%^RESET%^%^GREEN%^m%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^a%^GREEN%^l%^BOLD%^d C%^WHITE%^o%^RESET%^%^GREEN%^i%^BOLD%^l%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^an %^RESET%^ivory %^BOLD%^%^WHITE%^and %^GREEN%^emerald %^WHITE%^flail%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This flail appears to be made from highly polished bone.  The long grip is a %^RESET%^pale ivory color %^BOLD%^%^WHITE%^wrapped in a thin layer of %^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^m%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^a%^GREEN%^l%^BOLD%^d %^WHITE%^scales that gives it a secure, tight grip.  Each end is capped with mithril and from the top a length of mithril links extends to a ball of four razor sharp claws that have been fused together into a spiked ball.  Each of the claws gleams with an %^GREEN%^emerald glint %^WHITE%^though close inspection reveals a myriad of colorations from %^BLACK%^deep blacks %^WHITE%^to %^YELLOW%^rich golds %^WHITE%^and %^BLUE%^lustrous blues %^WHITE%^that all blend into the %^GREEN%^emerald %^WHITE%^coloring.  The fine weapon would serve well both as decoration and as an effective weapon. %^RESET%^

AVATAR
	);
	set_weight(15);
	set_value(10000);
	set_lore(
@AVATAR
Valas, Arch Mage of Mystra, was captured by Klauth when he bravely attempted to drive the giant red dragon away from the Shadow Deserts all alone.  His capture led several brave souls, among them Adderlash of Grumbar, Erieen of Kelemvor, Azalon of Lathander and Snog of Istishia to brave the dangers of Klauth's island in an attempt to free their friend.  The small mercury dragon Zhashabur, friend to Valas and Adderlash, risked his life to draw Klauth away.  Doing so nearly cost him his, but thanks to the efforts of these brave adventurers, not only was Valas saved but Zhashabur was returned from the dead.  In repayment, the little dragon gifted this flail to Snog in thanks. 

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("bludgeoning");
	set_prof_type("flail");
	set_size(2);
	set_wc(1,6);
	set_large_wc(2,4);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^GREEN%^You hand fits securely about the grip of this fine weapon.%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^GREEN%^You release your grip and already your hand aches for the fine weapon.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^A bright flash of emerald light catches off the claws of "+ETOQCN+"'s weapon.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^There is a flash of emerald, as light catches upon the claws of your flail and "+targ->QCN+" staggers backward, stunned.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^GREEN%^The bright flash of "+ETOQCN+"'s weapon catches your eyes and you are momentarily stunned by the brilliant emerald gleam.%^RESET%^");
		targ->set_paralyzed(roll_dice(20,0)+0);
return 0;	}

}
