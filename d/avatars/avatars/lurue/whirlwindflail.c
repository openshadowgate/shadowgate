#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("ironwood flail");
	set_id(({ "flail", "flail of the whirling wind", "ironwood flail", "whirlingwind flail", "whirling wind flail" }));
	set_short("%^BOLD%^%^BLACK%^F%^CYAN%^l%^RESET%^%^CYAN%^a%^BOLD%^i%^BLACK%^l of the W%^CYAN%^h%^RESET%^%^CYAN%^i%^BOLD%^r%^BLACK%^li%^RESET%^%^CYAN%^n%^BOLD%^%^BLACK%^g W%^RESET%^%^CYAN%^i%^BOLD%^n%^BLACK%^d%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^an ironwood flail%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This flail is made of %^RESET%^%^CYAN%^dark ironwood %^BOLD%^%^BLACK%^and studded with sharpened spikes and chain-links of %^BOLD%^%^WHITE%^adamaintium%^BLACK%^.  The combination of which makes the weapon seem %^RESET%^%^CYAN%^sinister %^BOLD%^%^BLACK%^indeed.  Despite this, the weapon is exceptionally made.  The handle is wrapped in thick black leather that provides a firm, comfortable grip, while the %^WHITE%^chains %^BLACK%^are thick and strong to prevent the end spikes from being torn loose if they snag on something.  The spikes are slightly curved causing them to rip and tear when they catch armor, clothing or skin.  Added to this, as it spins about, the chains make a whirling sound as though a %^CYAN%^windstorm%^BLACK%^ is brewing.%^RESET%^

AVATAR
	);
	set_weight(15);
	set_value(1000);
	set_lore(
@AVATAR
These flails are said to have been made for the armies of Kraytus, a kingdom far to the west of the Shadow region that existed from -140 SG to 350 SG then fell to the attacks of storm giant clans that had moved in..  Though considered a soldier's weapon, some of the followers of the Whirling Wind found the weapons to be quiet comfortable in their hands and had them enchanted with several abilities that would serve them well. 

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("bludgeoning");
	set_prof_type("flail");
	set_size(2);
	set_wc(1,6);
	set_large_wc(2,4);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You can almost feel the %^RESET%^"+query_short()+"%^BOLD%^%^CYAN%^ tug at your hand as you take hold of its grip!%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You let go of the %^RESET%^"+query_short()+"%^BOLD%^%^CYAN%^ and feel your arm relax finally.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^"+ETOQCN+"'s %^RESET%^"+query_short()+" %^BOLD%^%^CYAN%^howls like a fierce storm as it flies forward sending a gust of %^BLACK%^debris%^CYAN%^ in a buffeting strike toward "+targ->QCN+"!  "+targ->QCN+" is blinded and confused for a moment as the wind blurs about "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^The %^RESET%^"+query_short()+" %^BOLD%^%^CYAN%^howls like a fierce storm as it flies forward sending a gust of %^BLACK%^debris%^CYAN%^ in a buffeting strike toward "+targ->QCN+"!  "+targ->QCN+" is blinded and confused for a moment as the wind blurs about "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s %^RESET%^"+query_short()+" %^BOLD%^%^CYAN%^howls like a fierce storm as it flies forward sending a gust of %^BLACK%^debris%^CYAN%^ in a buffeting strike toward you!  You are blinded and confused for a moment as the wind blurs about you!%^RESET%^");
		targ->set_paralyzed(roll_dice(8,0)+0);
return 0;	}
}