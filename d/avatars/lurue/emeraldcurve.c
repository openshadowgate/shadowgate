#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("long sword");
	set_id(({ "sword", "longsword", "long sword", "emerald curve", "curve", "blade" }));
	set_short("%^BOLD%^%^GREEN%^E%^WHITE%^m%^RESET%^%^GREEN%^e%^BOLD%^ra%^RESET%^%^GREEN%^l%^BOLD%^d C%^WHITE%^u%^RESET%^%^GREEN%^r%^BOLD%^ve%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^an %^BOLD%^e%^WHITE%^m%^RESET%^%^GREEN%^e%^BOLD%^ra%^RESET%^%^GREEN%^l%^BOLD%^d %^RESET%^%^GREEN%^longsword%^RESET%^");
	set_long(
@AVATAR

%^RESET%^%^GREEN%^At first glance, this long, curved blade looks to be made out of a solid piece of %^BOLD%^emerald%^RESET%^%^GREEN%^. The appearance is further enhanced by the exquisite craftsmanship.  Starting with the spiral, unicorn horn shaped %^BOLD%^%^WHITE%^ivory hilt%^RESET%^%^GREEN%^, to the arching dove-wing curves of the %^BOLD%^%^WHITE%^ivory crossguard%^RESET%^%^GREEN%^, to the perfect, unmarred surface of the gleaming %^BOLD%^blade%^RESET%^%^GREEN%^.  It is only when one looks very close that they can see the many tiny nuances that tell of its true nature.  Small slivers of %^BOLD%^%^BLACK%^black%^RESET%^%^GREEN%^, %^YELLOW%^yellow%^RESET%^%^GREEN%^, %^WHITE%^%^BOLD%^silver%^RESET%^%^GREEN%^, %^BOLD%^green%^RESET%^%^GREEN%^, %^CYAN%^blue %^GREEN%^and other less noticeable colors swirl together into a strong, metal-like material that shimmers with bejeweled tones. There is little doubt that this can be only one thing, a dragon's claw.%^RESET%^


AVATAR
	);
	set_weight(7);
	set_value(12000);
	set_lore(
@AVATAR
Valas, Arch Mage of Mystra, was captured by Klauth when he bravely attempted to drive the giant red dragon away from the Shadow Deserts all alone.  His capture led several brave souls, among them Adderlash of Grumbar, Erieen of Kelemvor, Azalon of Lathander and Snog of Istishia to brave the dangers of Klauth's island in an attempt to free their friend.  The small mercury dragon Zhashabur, friend to Valas and Adderlash, risked his life to draw Klauth away.  Doing so nearly cost him his, but thanks to the efforts of these brave adventurers, not only was Valas saved but Zhashabur was returned from the dead.  In repayment, the little dragon gifted this weapon to Azalon in thanks. 

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,10);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The sword feels light in your hand, cutting through the air easily.%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^Your fingers tingle as you set aside the magical sword.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" moves lightning fast, weaving, dodging, striking with their %^GREEN%^%^BOLD%^e%^WHITE%^m%^RESET%^%^GREEN%^e%^BOLD%^ra%^RESET%^%^GREEN%^l%^BOLD%^d %^WHITE%^blade!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The %^GREEN%^%^BOLD%^e%^WHITE%^m%^RESET%^%^GREEN%^e%^BOLD%^ra%^RESET%^%^GREEN%^l%^BOLD%^d %^WHITE%^blade flashes through "+targ->QCN+"'s defenses creating a spray of %^RED%^crimson%^WHITE%^!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" moves lightning fast, weaving, dodging, striking you with their %^GREEN%^%^BOLD%^e%^WHITE%^m%^RESET%^%^GREEN%^e%^BOLD%^ra%^RESET%^%^GREEN%^l%^BOLD%^d %^WHITE%^blade!%^RESET%^");
		return roll_dice(1,4)+15;	}

}
