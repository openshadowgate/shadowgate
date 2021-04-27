#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("bottle");
	set_id(({ "bottle", "shanker", "barman shanker" }));
	set_short("%^RESET%^%^GREEN%^Ba%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^man Sha%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^ker%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^bro%^BOLD%^%^GREEN%^k%^RESET%^%^GREEN%^en bot%^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^le%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^This is a beer bottle which has had the bottom broken off, leaving a horribly jagged circular edge, a few points dripping old %^BOLD%^%^RED%^bl%^RESET%^%^ORANGE%^o%^BOLD%^%^RED%^od%^RESET%^%^GREEN%^.  It looks devastating, and could probably be quite dangerous if gripped by someone skilled enough.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
Yeungling Lager

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(0);
	set_type("piercing");
	set_prof_type("bottle");
	set_size(1);
	set_wc(100,4);
	set_large_wc(100,4);
	set_property("enchantment",30);
	set_ac(0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 333){
	tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^"+ETOQCN+" twists the "+query_obvious_short()+"%^BOLD%^%^GREEN%^, and a shard of glass rips into "+targ->QCN+"!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^You twist the "+query_obvious_short()+"%^BOLD%^%^GREEN%^, and a shard of glass shears into "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^GREEN%^"+ETOQCN+" twists the "+query_obvious_short()+" %^BOLD%^%^GREEN%^into you, shredding your flesh!%^RESET%^");
		return roll_dice(50,4)+0;	}
}