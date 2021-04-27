#include <std.h>
inherit "/d/common/obj/weapon/fan";

void create(){
	::create();
	set_name("Fan of the Dragon");
	set_id(({ "fan", "fan of the dragon", "dragon fan" }));
	set_short("%^BOLD%^%^WHITE%^F%^CYAN%^a%^WHITE%^n %^CYAN%^o%^WHITE%^f %^CYAN%^t%^WHITE%^h%^CYAN%^e %^WHITE%^D%^CYAN%^r%^WHITE%^a%^CYAN%^g%^WHITE%^o%^CYAN%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^an ornamental fan%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^MAGENTA%^This is a very elegant weapon both in design and artistry.  Closed, it resembles a thickly curved dagger, plated with %^WHITE%^silver %^MAGENTA%^and strung at the end with two %^YELLOW%^golden %^MAGENTA%^tassels.  But it is when you open the fan to it's full girth that an sudden awe fills your eyes and mind.  Each of the fan's fifteen segments flare out wildly, looking almost as individual blades tied together for a common weapon.  The frames holding it together tie together close to the base with an extremely tight twist of %^YELLOW%^golden %^MAGENTA%^twine.  When opened close together, the fan depicts two ancient %^GREEN%^dragons %^MAGENTA%^facing each other with their bodies appearing to slither across the blades as you move the weapon.  In the center, the symbol of %^CYAN%^Istishia%^MAGENTA%^ prevails between the %^WHITE%^silver %^MAGENTA%^and %^YELLOW%^golden %^MAGENTA%^wyrms.%^RESET%^ 

AVATAR
	);
	set_value(500);
	set_lore(
@AVATAR
%^BOLD%^In 322 SG, a young, devote mage of %^CYAN%^Istishia%^WHITE%^ named Sylma Morrow departed from her homeland on the island of Deku to explore the vast reaches of the sea.  Her desires to see as much of what of waters had to offer kept her busy for many years.  Once per year, during the moon month of her birth, she would return and share in her exploits with friends and family she left behind.  In the seventh year of her journey however, she failed to return and was not seen or heard from ever again.  Rumors from travelers who sailed the oceans as she did spoke of a boat similar to hers adrift on the ocean with only a bag of clothing and a shining fan.  Knowing the fan to be a weapon Sylma excelled in and carried with her, her friends and family feared the worst.  It still remains a mystery what happened to the young woman, and the fan which was left with her family has long since disappeared.  Legends say the fan can come to life and aid one in battle.  But none ever knew how to make it work by she that disappeared.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",25);
	set("chabonus",1);
	set("dexbonus",1);
	set_heart_beat(1);
	set_property("enchantment",4);
	set_ac(-1);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 40){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^"+ETOQCN+" throws forth a wave of water from her "+query_short()+" and watches it slam into "+targ->QCN+".%^RESET%^ ",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^A rushing wave of water blasts "+targ->QCN+" from the symbol on "+query_short()+".%^RESET%^ ");
	tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+" "+query_short()+" emits a forecful tidal wave against you, knocking you backwards.%^RESET%^ ");
		return roll_dice(4,4)+0;	}

}

void heart_beat()
{
	 if(!objectp(TO)) { return; }
	 if(!objectp(ETO)) { return; }
	 if(TO->is_weapon()) 
	 { 
		if(!TO->query_wielded()) { return; } 
	 } 
	 if(TO->is_armor())
	 { 
		if(!TO->query_worn()) { return; } 
	 } 
	 if(!interactive(ETO)) { return; } 
	 if(random(500) > 495) 
	 {
		switch(random(3)) 
		{
			case 0:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A voice from within the "+query_short()+" calls out to "+ETOQCN+" %^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^A mysterious voice seems to call for aid, where does it come from? %^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^BOLD%^A voice exclaims: %^YELLOW%^We are one.  Our passion for beauty will be unmatched.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^YELLOW%^You can hear someone talking about unmatched beauty, but aren't sure who.%^RESET%^", ({ETO}));
				break;
			case 2:
				tell_object(ETO, "%^BOLD%^%^BLUE%^Let us sail away on the ocean together.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^BLUE%^The "+query_short()+" wishes to go for a sail?%^RESET%^", ({ETO}));
				break;
		}
	}
}