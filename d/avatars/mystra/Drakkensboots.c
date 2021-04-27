#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Bootsofthunder");
	set_id(({ "boots", "boot", "shoes" }));
	set_short("%^BOLD%^%^BLUE%^Mi%^YELLOW%^d%^BLUE%^nig%^BLACK%^ht %^BLUE%^B%^YELLOW%^o%^BLUE%^o%^BLACK%^ts %^BLUE%^o%^BLACK%^f %^BLUE%^Th%^YELLOW%^u%^BLUE%^nd%^BLACK%^er%^RESET%^");
	set_obvious_short("%^BOLD%^a small pair of %^BOLD%^%^BLACK%^grey %^WHITE%^boots %^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a pair of short reverse-folded boots made of a high grade of leather.  Judging from the intricacies of the stiching, you would believe only a master tanner could have produce the leather, dyed a %^BLUE%^deep shade of blue%^WHITE%^.  They are rather weather worn and well aged by now making them even sturdier to their owner.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(5000);
	set_lore(
@AVATAR
%^BOLD%^Not much at all is known about the creation of these spendid boots.  They are said to have appeared in a temple of Anhur, placed securely on the altar.  Rumors have said these boots belonged to Anhur himself, though that would be very hard to prove.  The rumors also state, with proof, that the boots hold within them the power of a thunderstorm.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("clothing");
	set_limbs(({ "right foot", "left foot" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETOQCN+" looks ready for action as he laces up his "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^You feel a slight charge as you put on your "+query_short()+"%^RESET%^");
	ETO->add_attack_bonus(1);
	ETO->set_property("magic resistance",2);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETOQCN+" seems more grounded as he pulls off his "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^The energy within "+query_short()+" fades as you pull them off.%^RESET%^");
	ETO->add_attack_bonus(-1);
	ETO->set_property("magic resistance",-2);
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 50){
	tell_room(environment(query_worn()),"%^BOLD%^%^YELLOW%^An earthshaking rumble sounds out as "+ETOQCN+" "+query_short()+" lashes out towards "+who->QCN+"%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^The "+query_short()+" crackles from within, and a resounding %^WHITE%^BOOM %^BLUE%^rings out towards "+who->QCN+"%^RESET%^");
	tell_object(who,"%^BOLD%^A %^YELLOW%^FLASH %^WHITE%^of light and the echo of thunder send you into a daze as your weapon strikes "+query_short()+".%^RESET%^");
		who->set_paralyzed(roll_dice(3,3));
return damage;	}

}

void init() {
   if(query_ac() != 0) set_ac(0);
   while(query_property("enchantment") != 1) {
     remove_property("enchantment");
     set_property("enchantment",1);
   }
}