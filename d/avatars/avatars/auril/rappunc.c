#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("rapier of puncturing");
	set_id(({ "rapier", "rapier of puncturing" }));
	set_short("%^BOLD%^%^CYAN%^Rapier of %^BOLD%^%^RED%^Pu%^BOLD%^%^CYAN%^ncturing%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A %^BOLD%^%^BLACK%^darkened %^RESET%^%^BLUE%^steel %^BOLD%^%^WHITE%^rapier%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^YELLOW%^This %^BOLD%^%^BLACK%^darkened %^RESET%^%^BLUE%^steel %^BOLD%^%^YELLOW%^rapier is exquisitely made. The length of the weapon has tiny barbs, which look to tear a little more when the rapier is pulled out of it's %^RESET%^%^RED%^victim%^BOLD%^%^YELLOW%^. The hilt is made out of %^RESET%^%^BLUE%^steel %^BOLD%^%^YELLOW%^and wrapped in a %^BOLD%^%^RED%^red cloth%^BOLD%^%^YELLOW%^.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(20000);
	set_lore(
@AVATAR
Once used by the famous sword fighter, Alagon the quick, this sword was rumored by many to be the bane of the duel. It's prowess for making its wielder more deadly in combat made it saught by many, until its disappearance nearly fourty years ago.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("piercing");
	set_prof_type("rapier");
	set_size(1);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",3);
	set_ac(1);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
   if(random(1000) < 50){
   tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^"+ETOQCN+" deftly thrusts "+ETO->query_possessive()+" rapier into "+targ->QCN+"!",({ETO,targ}));
   tell_object(ETO,"%^BOLD%^%^GREEN%^You deftly thrust your rapier into "+targ->QCN+"!");
   tell_object(targ,"%^BOLD%^%^GREEN%^"+ETOQCN+" deftly thrusts "+ETO->query_possessive()+" rapier into you!");
   new("/d/avatars/auril/rapierdam.c")->move(targ);	
   return roll_dice(1,6);
   }
}