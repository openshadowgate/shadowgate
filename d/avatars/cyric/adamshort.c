#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("adamantite shortsword");
	set_id(({ "sword", "shortsword", "short sword", "adamantite short", "adamantite shortsword", "adamantite short sword", "weapon", "magic sword", "magical sword" }));
	set_short("%^RESET%^%^BOLD%^Adamantite Shortsword%^RESET%^");
	set_obvious_short("Shortsword");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^This is an incredibly sharp shortsword.  The blade is not steel, but adamantite, the hardest substance known.  Engraved on the blade are magical runes of some sort, and the pommel bears a skull within starburst symbol.  

AVATAR
	);
	set("read",
@AVATAR
Try as you might, you cannot decipher the runes.

AVATAR
	);
	set_weight(5);
	set_value(3000);
	set_lore(
@AVATAR
It is said that this weapon is a gift from Cyric to those warriors among his faithful who have distinguished themselves above their peers in furthering the causes of the Dark Sun.  

AVATAR
	);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(2,4);
	set_large_wc(2,6);
	set_property("enchantment",3);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 500){
	tell_room(environment(query_wielded()),"%^RED%^The "+query_short()+" held by "+ETO->query_cap_name()+" glows bright!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RED%^The runes on your "+query_short()+" glow bright as you strike "+targ->query_cap_name()+"%^RESET%^");
	tell_object(targ,"");
		return roll_dice(1,6)+-1;	}
}