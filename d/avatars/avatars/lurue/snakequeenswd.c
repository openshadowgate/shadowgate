#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("long sword");
	set_id(({ "sword", "royal sword", "longsword", "long sword" }));
	set_short("%^BOLD%^%^GREEN%^R%^BLACK%^o%^RESET%^%^ORANGE%^y%^GREEN%^a%^BOLD%^l B%^BLACK%^l%^RESET%^%^ORANGE%^a%^GREEN%^d%^BOLD%^e of the S%^BLACK%^n%^RESET%^%^ORANGE%^a%^GREEN%^k%^BOLD%^e Q%^BLACK%^u%^RESET%^%^ORANGE%^e%^GREEN%^e%^BOLD%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^A green hued longsword%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^This longsword is made from a single piece of green hued metal, unknown in these lands.  From the pommel to the tip, the smith who made this weapon bent and folded and shaped the metal so that it resembles a the body of a snake coiling about itself.  The blade of the weapon is long and ends with a diamond shape where two small %^RED%^rubies %^GREEN%^glint.  Along the blood groove, tiny shards of %^BOLD%^%^BLACK%^onyx %^RESET%^%^GREEN%^and %^ORANGE%^amber %^GREEN%^have been laid to create the pattern seen on many forest dwelling snakes.  The cross-guard and grip continue this pattern, flowing around itself in order to create the body of the snake and ending at the pommel with an %^ORANGE%^t%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^ge%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^s-e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^e%^GREEN%^ rattle.%^RESET%^

AVATAR
	);
	set_weight(7);
	set_value(1000);
	set_lore(
@AVATAR
Rumor tells of a human man named Sumondra who had been taken captive by the Yaun-ti and was held as a slave for many years.  A smith by trade, he was forced to create weapons for his snake masters, churning out fine pieces that were in turn used to harm other humans and bring them under captivity.  After ten years, he could bare it no longer and he set about making the finest of weapons he had ever created.  It took him a year and a half to create it but the finished product impressed the Yuan-ti so much that Sumondra was allowed to present it to their queen. Knowing he had but this one chance, Sumondra approached the queen as though to offer her the weapon.  At the last moment, he thrust it forward, cutting her head clean off.  Sumondra was killed moments later by her loyal followers, but the Queen was dead.  The sword was banished into the wilds never to be seen again.

AVATAR
	);
	set_property("lore difficulty",16);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,10);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^GREEN%^The %^ORANGE%^t%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^ge%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^s-e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^e%^GREEN%^ pommel on "+ETOQCN+"'s sword rattles just like a snake!%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^The %^ORANGE%^t%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^ge%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^s-e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^e%^GREEN%^ pommel on your sword rattles just like a snake!%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^GREEN%^The %^ORANGE%^t%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^ge%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^s-e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^e%^GREEN%^ pommel on "+ETOQCN+"'s sword rattles just like a snake!%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^The %^ORANGE%^t%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^ge%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^s-e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^e%^GREEN%^ pommel on your sword rattles just like a snake!%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^The %^RED%^rubies%^GREEN%^ at the end of "+ETOQCN+"'s sword glow and suddenly the "+query_short()+" %^BOLD%^%^GREEN%^comes to life!  With a %^BLACK%^violent%^GREEN%^ movement, the snake snaps out and sinks its %^WHITE%^fangs %^GREEN%^deep into "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^GREEN%^The %^RED%^rubies%^GREEN%^ at the end of your sword glow and suddenly the "+query_short()+" %^BOLD%^%^GREEN%^comes to life!  With a %^BLACK%^violent%^GREEN%^ movement, the snake snaps out and sinks its %^WHITE%^fangs %^GREEN%^deep into "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^GREEN%^The %^RED%^rubies%^GREEN%^ at the end of "+ETOQCN+"'s sword glow and suddenly the "+query_short()+" %^BOLD%^%^GREEN%^comes to life!  With a %^BLACK%^violent%^GREEN%^ movement, the snake snaps out and sinks its %^WHITE%^fangs %^GREEN%^deep into $T!  You feel yourself %^RED%^paralyzed%^GREEN%^ by the %^WHITE%^poison!%^RESET%^");
		targ->set_paralyzed(roll_dice(0,0)+0);
return 0;	}
}