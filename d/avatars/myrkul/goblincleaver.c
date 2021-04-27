#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("goblincleaver");
	set_id(({ "axe", "goblin cleaver", "cleaver", "kateri's goblin cleaver" }));
	set_short("%^BOLD%^%^WHITE%^K%^CYAN%^a%^WHITE%^teri's %^RESET%^%^ORANGE%^G%^MAGENTA%^o%^ORANGE%^blin %^BOLD%^%^WHITE%^C%^RED%^l%^WHITE%^eaver%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^N%^CYAN%^o%^WHITE%^tched A%^RED%^x%^WHITE%^e%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This axe has seen better days. It is a long handled axe that has been recently p%^CYAN%^o%^WHITE%^lish%^CYAN%^e%^WHITE%^d. However its been through a nasty battle, and the middle of the axe blade has been n%^RED%^o%^WHITE%^tched. Nonetheless, you feel this axe is rather %^GREEN%^lucky%^RESET%^.

AVATAR
	);
	set_weight(5);
	set_value(1000);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^Originally this axe once belonged to a noble family of Offestry that fell into hard times. More recently it has come into the hands of one adventurer named %^WHITE%^Kateri%^BLACK%^. Blessed by the %^CYAN%^goddess of good fortune%^BLACK%^, she was able to fight a battle with Goblin Headhunters intent on bringing home her %^RED%^scalp%^BLACK%^. Kateri turned the tables on them and won despite the %^GREEN%^long odds.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("slashing");
	set_prof_type("axe");
	set_size(medium);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",1);
	set_ac(1);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" lands a %^BOLD%^%^GREEN%^lucky%^WHITE%^ shot on "+targ->QCN+"'s neck%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^You lash out with the a%^RED%^x%^WHITE%^e, landing a %^BOLD%^%^GREEN%^lucky%^WHITE%^ shot on "+targ->QCN+"'s neck%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" lands a %^BOLD%^%^GREEN%^lucky%^WHITE%^ shot, cutting %^RESET%^%^MAGENTA%^deeply%^BOLD%^%^WHITE%^ into your neck%^RESET%^");
		return roll_dice(1,50)+0;	}

}
