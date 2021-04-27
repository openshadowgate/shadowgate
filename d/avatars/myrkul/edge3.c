#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^E%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^ge of %^RESET%^%^RED%^D%^BOLD%^i%^RESET%^%^RED%^s%^BOLD%^c%^RESET%^%^RED%^o%^BOLD%^r%^RESET%^%^RED%^d%^RESET%^");
	set_id(({ "edge", "sword", "edge of discord" }));
	set_short("%^BOLD%^%^BLACK%^E%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^ge of %^RESET%^%^RED%^D%^BOLD%^i%^RESET%^%^RED%^s%^BOLD%^c%^RESET%^%^RED%^o%^BOLD%^r%^RESET%^%^RED%^d%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^twisted blacksteel blade%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This long twisted blade is made from a black, unknown metal, both light-weight and durable. The double-edged blade is %^RED%^razor-sharp%^BLACK%^, barbed and serrated in some parts, smooth and fine edged in others - a blade of %^GREEN%^chaos%^BLACK%^. A deep %^RED%^blood%^BLACK%^ groove travels along the length of the blade, flanked on either side by jagged %^CYAN%^runes%^BLACK%^. There is a sense of wrongness about the %^CYAN%^runes%^BLACK%^, to look on them is to feel uneasy. The hilt is carved from soft black stone, wrapped in supple leather of some unknown beast. A thick %^RED%^blood-ruby%^BLACK%^ has been set into the end of the hilt, secured firmly by a set of black claws.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLACK%^...h%^CYAN%^e%^BLACK%^ed m%^RESET%^%^MAGENTA%^y%^BOLD%^%^BLACK%^ c%^CYAN%^a%^BLACK%^ll...%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(5);
	set_value(10000);
	set_lore(
@AVATAR
%^RESET%^%^MAGENTA%^...borne of the plane of %^CYAN%^L%^BOLD%^i%^RESET%^%^CYAN%^m%^BOLD%^b%^RESET%^%^CYAN%^o%^MAGENTA%^ this twisted blade is %^BOLD%^%^RED%^i%^MAGENTA%^n%^RED%^s%^MAGENTA%^a%^RED%^n%^MAGENTA%^i%^RED%^t%^MAGENTA%^y%^RESET%^%^MAGENTA%^ incarnate... %^BOLD%^%^BLACK%^powerful%^RESET%^%^MAGENTA%^ beyond measure, it nevertheless %^BOLD%^%^BLUE%^c%^RESET%^%^BLUE%^o%^BOLD%^r%^RESET%^%^BLUE%^r%^BOLD%^u%^RESET%^%^BLUE%^p%^BOLD%^t%^RESET%^%^BLUE%^s%^MAGENTA%^ the hand that wields it... The longer it is %^RED%^held%^MAGENTA%^ the deeper into the %^BOLD%^%^BLACK%^depths%^MAGENTA%^ of %^GREEN%^m%^BOLD%^a%^RESET%^%^GREEN%^d%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^s%^MAGENTA%^ the wielder is lured...

AVATAR
	);
	set_property("lore difficulty",20);
	set("conbonus",1);
	set("wisbonus",-1);
	set_heart_beat(1);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" looks worried holding the "+query_short()+"",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^...you hear %^BOLD%^%^BLACK%^whispers%^RESET%^%^MAGENTA%^ of %^RED%^i%^BOLD%^n%^RESET%^%^RED%^s%^BOLD%^a%^RESET%^%^RED%^n%^BOLD%^i%^RESET%^%^RED%^t%^BOLD%^y%^RESET%^%^MAGENTA%^ inside your mind...%^RESET%^");
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" looks relieved and a bit calmer after releasing the "+query_short()+"",ETO);
	tell_object(ETO,"You feel relieved as you let go of the hilt.");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 350){
	tell_room(environment(query_wielded()),""+query_short()+" %^BOLD%^%^BLACK%^ glows %^YELLOW%^brightly%^BLACK%^ as "+ETOQCN+" %^BOLD%^%^BLACK%^buries the sword deeply into "+targ->QCN+"!!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^CYAN%^runes%^BLACK%^ on your blade come to life, the smell of %^RED%^blood%^BLACK%^ overwhelms your senses as you impale "+targ->QCN+"!%^RESET%^");
	tell_object(targ,""+query_short()+" %^BOLD%^%^BLACK%^gives off a %^YELLOW%^bright%^BLACK%^ glow and before you can react the sword is buried deep in your chest spilling %^RED%^blood%^BLACK%^ everywhere!!!%^RESET%^");
		return roll_dice(2,10)+15;	}

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
	 if(random(500) > 497) 
	 {
		switch(random(3)) 
		{
			case 0:
				tell_object(ETO, ""+query_short()+" %^RESET%^calls to you with whispers of %^RESET%^%^MAGENTA%^m%^RED%^a%^MAGENTA%^d%^RED%^n%^MAGENTA%^e%^RED%^s%^MAGENTA%^s...%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" seems to clutch at "+query_short()+" with %^BOLD%^%^BLACK%^w%^RED%^i%^BLACK%^l%^RED%^d%^BLACK%^ e%^RED%^y%^BLACK%^e%^RED%^s%^RESET%^!", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "You suddenly notice that Someone has moved and your back is exposed.       Someone stabs you in the back!                                                    %^BOLD%^%^RED%^Hp:%^WHITE%^ -666    -121%");
				tell_room(EETO, ""+ETOQCN+" %^RED%^looks around wildly as if attacked by an %^BOLD%^%^BLACK%^unseen assailant%^RESET%^!!", ({ETO}));
				break;
			case 2:
				tell_object(ETO, "%^BOLD%^%^GREEN%^Someone takes in a deep breath and screams the words, GRIMMUS MORRTES!!!%^RESET%^         You reel backward in utter agony, and the world around you goes black!            %^BOLD%^%^RED%^Hp:%^WHITE%^ -666    -117%^RESET%^");
				tell_room(EETO, ""+ETOQCN+" goes %^BOLD%^%^WHITE%^pasty white%^RESET%^ with a face full of %^BOLD%^%^BLACK%^fear%^RESET%^ as if "+ETO->QS+" faced %^BOLD%^%^BLACK%^death itself!%^RESET%^", ({ETO}));
				break;
		}
	}
}