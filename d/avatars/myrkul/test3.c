#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("skullcleaver");
	set_id(({ "sword", "longsword", "long sword" }));
	set_short("%^BOLD%^%^RED%^S%^CYAN%^k%^RED%^ull%^YELLOW%^C%^RED%^lea%^BLACK%^v%^RED%^er%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^de%^BOLD%^r%^RESET%^%^RED%^ang%^BOLD%^e%^RESET%^%^RED%^d %^BOLD%^%^GREEN%^sa%^RED%^w%^GREEN%^to%^RED%^o%^GREEN%^th%^RED%^e%^GREEN%^d%^RESET%^%^RED%^ l%^BOLD%^o%^RESET%^%^RED%^ngsword%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^Some kind of deranged %^RESET%^%^MAGENTA%^moron%^BOLD%^%^GREEN%^ had the brilliant idea that a %^RED%^hack saw%^GREEN%^ might make a good longsword. The shape is generally that of a %^BLUE%^three foot%^GREEN%^ blade on a hilt. But the blade itself is one-sided, and lined with %^MAGENTA%^grizzly saw-teeth%^GREEN%^. Its ugly enough that it might just work, if held by someone strong enough.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1000);
	set_lore(
@AVATAR
This sword was made in SG 694 by a destitute dwarf with a passionate desire for revenge on bandits that put him in the grave. Rescued twenty hours after the fact by a cleric of Grumbar, it was only the blessings of stone that allowed this dwarf return to the land of the living. Unfortunately the whole sordid affair unhinged his mind, and he has grown increasingly brutal and obsessed.

AVATAR
	);
	set_property("lore difficulty",10);
	set("conbonus",2);
	set("strbonus",2);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"As you grip "+query_short()+" you feel violent %^RED%^urges%^RESET%^ for revenge!");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"As you release "+query_short()+", a feeling of calm returns to your senses.");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),""+query_short()+" %^BOLD%^%^RED%^SAWZ%^RESET%^ through the hapless %^CYAN%^"+targ->QCN+"%^RESET%^ like a saw, tossing chunks of %^RED%^flesh everywhere!",({ETO,targ}));
	tell_object(ETO,""+query_short()+" %^BOLD%^%^RED%^SAWZ%^RESET%^ through the hapless %^CYAN%^"+targ->QCN+"%^RESET%^ like a saw, tossing chunks of %^RED%^flesh everywhere!");
	tell_object(targ,""+query_short()+" %^BOLD%^%^RED%^SAWZ%^RESET%^ through the hapless %^CYAN%^$T%^RESET%^ like a saw, tossing chunks of %^RED%^flesh everywhere!");
		return roll_dice(0,0)+0;	}

}
