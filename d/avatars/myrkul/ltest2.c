#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("lance");
	set_id(({ "lance" }));
	set_short("%^BOLD%^%^RED%^A r%^MAGENTA%^o%^RED%^se l%^MAGENTA%^a%^RED%^nce%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A r%^MAGENTA%^o%^RED%^se l%^MAGENTA%^a%^RED%^nce%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This is a heavy lance made of %^MAGENTA%^cherry%^RED%^ wood. It has a heavy %^BLACK%^iron point%^RED%^ mounted at the end. Many %^RESET%^%^RED%^e%^BOLD%^%^MAGENTA%^n%^RESET%^%^RED%^graved %^BOLD%^r%^MAGENTA%^o%^RED%^ses line the lance from tip to guard. Overall it is a beautiful piece of craftsmanship, and would serve any young knight well at %^BLUE%^court%^RED%^ or on the %^GREEN%^field.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^MAGENTA%^Courtesy if the %^RED%^flower%^MAGENTA%^ of Chivalry%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(5);
	set_value(1000);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^In 694 SG, this lance was fashioned by the skilled crafter and blind poet of Sune, %^GREEN%^Clausius%^WHITE%^. He said that the finery of the lance was not his own design but that which was the %^BLUE%^will%^WHITE%^ of the tree. It was cut and fashioned out of a single %^RED%^cherry%^WHITE%^ tree from the Temple. Clausius meant for the lance to be for a knight who appreciated the values of %^YELLOW%^Chivalry%^WHITE%^ in addition to prowess in battle.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set("chabonus",2);
	set_heart_beat(1);
	set_type("piercing");
	set_prof_type("lance");
	set_property("lance",1);
	set_size(1);
	set_wc(2,10);
	set_large_wc(2,10);
	set_property("enchantment",2);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^MAGENTA%^"+ETOQCN+"'s "+query_short()+" strikes %^RED%^true%^MAGENTA%^ as it pierces "+targ->QCN+" to the quick!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^Your "+query_short()+" strikes %^RED%^true%^MAGENTA%^ as it pierces "+targ->QCN+" to the quick!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^MAGENTA%^"+ETOQCN+" strikes through your defenses like %^YELLOW%^butter%^MAGENTA%^ with "+ETOQCN+"%^RESET%^");
		return roll_dice(2,10)+0;	}

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
		switch(random(1)) 
		{
			case 0:
				tell_object(ETO, "");
				tell_room(EETO, "", ({ETO}));
				break;
		}
	}
}