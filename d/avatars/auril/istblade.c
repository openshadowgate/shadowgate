#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("iblade");
	set_id(({ "sword", "longsword", "long sword", "scimitar" }));
	set_short("%^BOLD%^%^CYAN%^Te%^BOLD%^%^BLUE%^mp%^BOLD%^%^CYAN%^es%^BOLD%^%^BLUE%^t B%^BOLD%^%^CYAN%^la%^BOLD%^%^BLUE%^de%^RESET%^");
	set_obvious_short("a blue scimitar");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This blade is absolutely beautiful in its crafting. The blade at about four feet in length is made from a bluish steel that seems to f%^BOLD%^%^YELLOW%^lo%^BOLD%^%^GREEN%^w %^BOLD%^%^CYAN%^up and down the blade like rolling %^BOLD%^%^BLUE%^waves%^BOLD%^%^CYAN%^. The handle is made out of a piece of magically hardened %^BOLD%^%^WHITE%^coral %^BOLD%^%^CYAN%^wrapped in a blue cloth tightly. The pommel, that of a %^BOLD%^%^YELLOW%^mermaid %^BOLD%^%^CYAN%^sits beautifully at the end of the hilt. %^BOLD%^%^YELLOW%^An inscription is etched into the blade.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLUE%^Istishia makes all things pure.

AVATAR
	);
     set("langage","str");	set_weight(10);
	set_value(1500);
	set_lore(
@AVATAR
Crafted 47 years ago, an istishian blacksmith by the named of Gardnol Reldansoth dedicated this blade to an istishian warrior by the name of Regliron. Regliron used the sword faithfully to spread the will of Istishia until he was ruthlessly murdered by a group of thieves. Where the sword went from there, no one knows for sure, but some say it was spotted on the pirate "left foot" on the southern sea. 

AVATAR
	);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,""+ETO->query_cap_name()+" wields the scimitar.",TP);
	tell_object(TP,"%^BOLD%^%^CYAN%^As you wield "+query_short()+" the song of the seas rages through your mind, invigorating you.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+ETO->query_cap_name()+" unwields the scimitar.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The storm in your mind calms as the waters calm and strength is renewed.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^Energy cackles within the blade, exploding forth into "+targ->query_cap_name()+".",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^Energy bursts from the sword, striking your foe!");
	tell_object(targ,"%^BOLD%^%^YELLOW%^The hair on your neck stand up as the energy builds up in the sword, striking you!");
		return roll_dice(2,6)+2;	}
}