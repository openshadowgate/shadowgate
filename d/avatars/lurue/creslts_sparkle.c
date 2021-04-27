#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("short sword");
	set_id(({ "short sword", "shortsword", "sword", "creslt's sparkle" }));
	set_short("%^BOLD%^%^WHITE%^C%^GREEN%^r%^MAGENTA%^e%^YELLOW%^s%^WHITE%^lt's S%^GREEN%^p%^MAGENTA%^a%^YELLOW%^r%^WHITE%^kle%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a %^MAGENTA%^j%^GREEN%^e%^YELLOW%^w%^GREEN%^e%^MAGENTA%^l%^WHITE%^ hilted shortsword%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This gold hilted shortsword looks almost like a fancy prop, studded in small semi-precious gemstones as it is.  But upon testing the short blade, you find it to be sharp and quite capable of being used as a weapon.  %^BOLD%^%^WHITE%^Ivory bars %^RESET%^%^ORANGE%^are fitted into place with bands of %^YELLOW%^copper %^RESET%^%^ORANGE%^to provide a secure grip, while underneath, the gold metal sparkles brightly.  Small %^GREEN%^peridots%^ORANGE%^, %^MAGENTA%^amethysts %^ORANGE%^and %^WHITE%^moonstones %^ORANGE%^dot the hilt and pommel giving off a bright sparkle as they catch the light. %^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(1500);
	set_lore(
@AVATAR
Darren Creslt was a well known performer during the late fourth century SG.  Known for his portrayal as a dashing rogue who often saved the damsel at the last possible moment from the evil Vladmere Vongoth, his arch nemesis.  Creslt's trademark was his golden sword which sparkled under the bright candle lights of the stage and which he often used to 'blind' Vladmere during their epic fights.  Creslt died at the age of 49 when he was thrown from his mount and broke his neck.  No one ever found his trademark sword. 

AVATAR
	);
	set_property("lore difficulty",23);
	set_type("slashing");
	set_prof_type("short blades");
	set_size(1);
	set_wc(2,3);
	set_large_wc(2,4);
	set_property("enchantment",3);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" turns their shortsword just so, the gems catching the %^CYAN%^light%^WHITE%^ and causing "+targ->QCN+" to be stunned and blinded for a moment!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^Just like Creslt, you turn your shortsword so that it %^YELLOW%^flashes %^WHITE%^and %^CYAN%^sparkles%^WHITE%^, catching the light and shining it into "+targ->QCN+"'s eyes!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" turns their shortsword just so, the gems catching the %^CYAN%^light%^WHITE%^ and causing you to be stunned and blinded for a moment!%^RESET%^");
		targ->set_paralyzed(roll_dice(10,0)+0);
return 0;	}
}