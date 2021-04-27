#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("stealthwhisper");
	set_id(({ "%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^tealth%^RESET%^%^MAGENTA%^%^w%^BOLD%^%^BLACK%^hisper%^RESET%^", "stealthwhisper", "sword", "longsword", "long sword", "black sword" }));
	set_short("%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^tealth%^RESET%^%^MAGENTA%^%^w%^BOLD%^%^BLACK%^hisper%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^black bladed longsword%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^The essense of shadow itself writhes around the blade of this dreadful sword.  The long, thin, black blade reflects no light, and is crafted of a strange metal that appears to actually bind the shadows to itself.  The crosspiece of the sword is made of the same metal, as is the hilt.  The hilt is truely a masterpiece, shaped so finely that it appears to have been molded perfectly to have bumps and valleys in just the right places to fit the intended wielder's hand.  At the blunt end of the

AVATAR
	);
	set_weight(7);
	set_value(0);
	set_lore(
@AVATAR
This blade's story is hard to recall, even when concentrating on it.  A constant dimness clouds the mind of the person trying to learn about it, but it finally becomes apparent that this blade is none other than Stealthwhisper, the sword of the Shadowlord himself.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("slashing");
	set_prof_type("stealthwhisper");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,10);
	set_property("enchantment",4);
	set_ac(0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
//   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^Wisps of shadow trace after "+ETOQCN+"'s black sword as it rips through "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^Wisps of shadow trace after your black sword as it rips through "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^Wisps of shadow from "+ETOQCN+"'s black sword send a horrid chill into your wound!%^RESET%^");
		return roll_dice(1,6)+4;	}
   return 0;
}
