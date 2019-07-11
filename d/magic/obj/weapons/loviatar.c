//Loviatar Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLACK%^S%^RESET%^c%^BOLD%^%^BLACK%^o"+
		"%^RESET%^u%^BOLD%^%^BLACK%^r%^RESET%^g%^BOLD%^%^BLACK%^"+
		"e of %^BOLD%^RED%^P%^BLACK%^a%^RED%^i%^BLACK%^n%^RESET%^");
   	set_short("%^BOLD%^%^BLACK%^S%^RESET%^c%^BOLD%^%^BLACK%^o"+
		"%^RESET%^u%^BOLD%^%^BLACK%^r%^RESET%^g%^BOLD%^%^BLACK%^"+
		"e of %^BOLD%^RED%^P%^BLACK%^a%^RED%^i%^BLACK%^n%^RESET%^");
   	set_id(({"scourge","scourge of pain","whip","weapon"}));
   	set_long("Nine thin, narrow, %^BOLD%^%^BLACK%^black leather"+
		"%^RESET%^ lashes have been secured to a wooden base, "+
		" creating this scourge.  Braided into each lash are a"+
		" multitude of %^BOLD%^%^WHITE%^metal barbs%^RESET%^, "+
		"each one razor sharp.  The wooden handle of the scourge"+
		" has been wrapped with %^BOLD%^%^BLACK%^black leather%^RESET%^"+
		" and pierced with round %^BOLD%^metal%^RESET%^ studs.  "+
		"There is a sadistic quality to this divine weapon.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^RED%^The lashes of your scourge slice open"+
			" "+targ->QCN+"'s flesh, bringing "+targ->QO+" the sweet pain of Loviatar.");
      	tell_object(targ,"%^BOLD%^%^RED%^"+ETO->QCN+" slices open"+
			" your flesh with "+ETO->QP+" scourge.");
      	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+" slices open"+
			" "+targ->QCN+"'s flesh with "+ETO->QP+" scourge.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}