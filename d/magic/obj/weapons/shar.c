//Shar Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^RESET%^%^MAGENTA%^Tend%^BOLD%^%^BLACK%^r"+
		"%^RESET%^%^MAGENTA%^il of %^BOLD%^%^BLACK%^Darkness%^RESET%^");
   	set_short("%^RESET%^%^MAGENTA%^Tend%^BOLD%^%^BLACK%^r"+
		"%^RESET%^%^MAGENTA%^il of %^BOLD%^%^BLACK%^Darkness%^RESET%^");
   	set_id(({"whip","tendril of darkness","tendril","weapon"}));
   	set_long("%^RESET%^Shaped from pure %^BOLD%^%^BLACK%^darkness"+
		"%^RESET%^, this tendril takes on a whip-like shape.  "+
		"The inky black darkness is opaque and thick.  It appears"+
		" to drink in the surrounding light, as if wishing to quench it."+
		"  Staring at the inky %^BOLD%^%^BLACK%^darkness%^RESET%^"+
		" of the whip long enough, one could see minute %^MAGENTA%^"+
		"amethyst purple%^RESET%^ disks briefly before the darkness "+
		"absorbs each one.  A %^BOLD%^%^BLACK%^black%^RESET%^ aura"+
		" radiates around this divine whip.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^BLACK%^Dark flames flare up off the"+
			" surface of the tendril and burn "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^BLACK%^Dark flames flare up off the "+
			"surface of "+ETO->QCN+"'s tendril and burn you!");
      	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^Dark flames flare up off the "+
			"surface of "+ETO->QCN+"'s tendril and burn"+
			" "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}