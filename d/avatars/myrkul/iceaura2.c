#include <std.h>
inherit "/d/common/obj/jewelry/necklace";
//updated to new item bonus and removed enchant cause benny hates
void create(){
	::create();
	set_name("%^BOLD%^%^BLUE%^A%^RESET%^%^CYAN%^u%^BOLD%^r%^WHITE%^a%^BOLD%^%^BLUE%^ o%^RESET%^%^CYAN%^f %^BOLD%^I%^WHITE%^c%^BLUE%^e%^RESET%^");
	set_id(({ "aura" }));
	set_short("%^BOLD%^%^BLUE%^A%^RESET%^%^CYAN%^u%^BOLD%^r%^WHITE%^a%^BOLD%^%^BLUE%^ o%^RESET%^%^CYAN%^f %^BOLD%^I%^WHITE%^c%^BLUE%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A%^RESET%^%^CYAN%^u%^BOLD%^r%^WHITE%^a%^BOLD%^%^BLUE%^ o%^RESET%^%^CYAN%^f %^BOLD%^I%^WHITE%^c%^BLUE%^e%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^This %^RESET%^%^CYAN%^hazy%^BOLD%^%^BLUE%^ pocket of air seems to %^WHITE%^freeze%^BLUE%^ everything that passes under its chilly domain. A perpetual %^BOLD%^%^CYAN%^cold spot%^BLUE%^ "
	"the presence sucks the heat out of everything around it. At times faint showers of snow pass through it as excess %^BOLD%^%^CYAN%^water%^BLUE%^ is frozen out of the air. The %^BOLD%^%^BLUE%^ A%^RESET%"
	"^%^CYAN%^u%^BOLD%^r%^WHITE%^a%^BOLD%^%^BLUE%^ o%^RESET%^%^CYAN%^f %^BOLD%^I%^WHITE%^c%^BLUE%^e%^BOLD%^%^BLUE%^ is centered on a single shard of ice and might be worn around the neck. %^RESET%^"
	);
	set_value(0);
	set_lore("%^BOLD%^%^CYAN%^This %^BOLD%^%^BLUE%^ A%^RESET%^%^CYAN%^u%^BOLD%^r%^WHITE%^a%^BOLD%^%^BLUE%^ o%^RESET%^%^CYAN%^f %^BOLD%^I%^WHITE%^c%^BLUE%^e%^RESET%^%^BOLD%^%^CYAN%^ is a gift of %^BOLD%^%^WHITE%^Aur"
	"il%^CYAN%^ herself and it is an eternal cold which blesses its bearer with a chilly embrace. Only a %^RESET%^%^MAGENTA%^madman%^BOLD%^%^CYAN%^ or a %^BOLD%^%^BLUE%^creature of ice%^CYAN%^ could stand "
	"wearing such a thing.%^RESET%^
"
	);
    set_property("lore difficulty",10);
	set_heart_beat(1);
	set_size(2);
	//set_property("enchantment",1); bent no want
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
	set_item_bonus("endurance",2);
    set_item_bonus("fire resistance", 16);
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+"%^BOLD%^%^CYAN%^ looks chilled with "+query_short()+"%^BOLD%^%^CYAN%^ on. %^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel an icy chill as you wear "+query_short()+".%^RESET%^");
	ETO->do_damage("torso",random(20));

	return 1;
}

int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" looks much less chilled without the "+query_short()+" on.",ETO);
	tell_object(ETO,"You feel warmer as you remove "+query_short()+".");
	ETO->do_damage("torso",random(20));

	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 1000){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLUE%^"+who->QCN+"%^BOLD%^%^BLUE%^ is coated in %^WHITE%^frost%^BLUE%^ by "+query_short()+"%^BOLD%^%^BLUE%^ worn by "+ETOQCN+"!!!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^"+who->QCN+"%^BOLD%^%^BLUE%^ is coated in %^WHITE%^frost%^BLUE%^ by "+query_short()+"!!!%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLUE%^As you try to strike "+ETOQCN+"%^BOLD%^%^BLUE%^ you are %^WHITE%^frozen%^BOLD%^%^BLUE%^ by the "+query_short()+"!!!%^RESET%^");
		who->do_damage("torso",roll_dice(25,2));
return damage;	}

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
     if(random(1000) > 975)
     {
         if((int)ETO->query_hp() < ((int)ETO->query_max_hp()/2))
         {
             tell_object(ETO, "%^BOLD%^%^WHITE%^A chilling aura swirls around you chaotically and you are %^BOLD%^%^CYAN%^soothed"+
             " by it!%^RESET%^");
             tell_room(EETO, "%^BOLD%^%^WHITE%^A chilling aura swirls around "+ETOQCN+"%^BOLD%^%^WHITE%^ chaotically!%^RESET%^", ETO);
             ETO->heal(roll_dice(4,6));
         }
     }
	 if(random(1000) > 998) 
	 {
		switch(random(3)) 
		{
			case 0:
				tell_object(ETO, "%^BOLD%^%^CYAN%^"+query_short()+"%^BOLD%^%^BLUE%^ freezes%^CYAN%^ everything around it, leaving "+ETOQCN+"%^BOLD%^%^CYAN%^ with frosty breath.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^"+query_short()+"%^BOLD%^%^BLUE%^ freezes%^CYAN%^ everything around it, leaving "+ETOQCN+"%^BOLD%^%^CYAN%^ with frosty breath.%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A light %^WHITE%^snow%^CYAN%^ falls across "+ETOQCN+"%^BOLD%^%^CYAN%^ as "+ETO->QP+" "+ETOQCN+"%^BOLD%^%^BLUE%^ freezes%^CYAN%^ everything around it.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^A light %^WHITE%^snow%^CYAN%^ falls across "+ETOQCN+"%^BOLD%^%^CYAN%^ as "+ETO->QP+" "+query_short()+"%^BOLD%^%^BLUE%^ freezes%^CYAN%^ everything around it.%^RESET%^", ({ETO}));
				break;
			case 2:
				tell_object(ETO, "%^BOLD%^%^CYAN%^"+query_short()+"%^BOLD%^%^CYAN%^ worn by "+ETOQCN+"%^BOLD%^%^CYAN%^ seems to suck the very %^RED%^heat%^CYAN%^ out of the air.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^"+query_short()+"%^BOLD%^%^CYAN%^ worn by "+ETOQCN+"%^BOLD%^%^CYAN%^ seems to suck the very %^RED%^heat%^CYAN%^ out of the air.%^RESET%^", ({ETO}));
				break;
		}
	}
}