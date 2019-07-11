//Talos Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLACK%^L%^WHITE%^i%^BLACK%^g%^YELLOW%^h"+
		"%^BLACK%^tn%^WHITE%^i%^BLACK%^ng Sp%^YELLOW%^e"+
		"%^BLACK%^a%^WHITE%^r%^RESET%^");
   	set_short("%^BOLD%^%^BLACK%^L%^WHITE%^i%^BLACK%^g%^YELLOW%^h"+
		"%^BLACK%^tn%^WHITE%^i%^BLACK%^ng Sp%^YELLOW%^e"+
		"%^BLACK%^a%^WHITE%^r%^RESET%^");
   	set_id(({"spear","small spear","lightning spear","weapon"}));
   	set_long("%^BOLD%^%^BLACK%^Blackened%^RESET%^ charred wood makes"+
		" up the shaft of this spear.  Scorched into the surface of"+
		" the wood are %^BOLD%^chaotic%^RESET%^ arching patterns, "+
		"traveling in random directions.  The tip of the spear is "+
		"made up of cracking %^BOLD%^%^RED%^fire%^RESET%^ infused "+
		"%^YELLOW%^lightning%^RESET%^.  The mystical spear head "+
		"randomly changes shapes, never seeming to settle on one "+
		"form for long.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^YELLOW%^The spear head flashes and bursts into "+targ->QCN+".");
      	tell_object(targ,"%^YELLOW%^The crackling lightning tip of "+ETO->QCN+"'s"+
      		" spear flashes and bursts into you!");
      	tell_room(environment(ETO),"%^YELLOW%^The crackling lightning tip"+
			" of "+ETO->QCN+"'s spear flashes and bursts into"+
			" "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}