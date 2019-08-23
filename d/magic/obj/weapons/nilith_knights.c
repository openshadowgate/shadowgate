//Loviatar Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLACK%^Ba%^RED%^r%^BOLD%^%^BLACK%^bed"+
		" Blade of %^BOLD%^%^RED%^To%^BOLD%^%^BLACK%^r%^BOLD%^"+
		"%^RED%^me%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^t%^RESET%^");
   	set_short("%^BOLD%^%^BLACK%^Ba%^RED%^r%^BOLD%^%^BLACK%^bed"+
		" Blade of %^BOLD%^%^RED%^To%^BOLD%^%^BLACK%^r%^BOLD%^"+
		"%^RED%^me%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^t%^RESET%^");
   	set_id(({"weapon","blade","sword","barbed blade of torment"}));
   	set_long(
@CYTHERA
%^RESET%^This vicious and cruel looking blade is crafted out of %^BLUE%^cold steel%^RESET%^.  Serrated barbs jut out of the %^BLUE%^steel%^RESET%^ blade, allowing it to slice through armor and flesh with ease.  %^RED%^Reddish %^ORANGE%^brown%^RESET%^ stains coat the barbs.  Twin %^BOLD%^%^WHITE%^spikes%^RESET%^ are mounted perpendicularly to the steel blade, adding to the cruel image of the blade.  The twisted %^BOLD%^%^BLACK%^iron%^RESET%^ pommel has an uneven pebbly texture to it, aiding the wearer to maintain their grasp on the blade.
CYTHERA
	);
	set_value(0);
	set_hit((:TO,"hit_func":));
    set_property("able to cast",1);
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^RED%^The serrated barbs of your sword slice open "+
			""+targ->QCN+"'s flesh, brining them the sweet pain of Loviatar.");
      	tell_object(targ,"%^BOLD%^%^RED%^"+ETO->QCN+" slices open"+
			" your flesh with the serrated barbs of "+ETO->QP+" sword.");
      	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+" slices open"+
			" "+targ->QCN+"'s flesh with the serrated barbs of"+
			" "+ETO->QP+" sword.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}
