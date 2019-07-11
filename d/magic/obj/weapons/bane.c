//Bane Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLACK%^Tyrant's %^BOLD%^%^GREEN%^"+
		"F%^RESET%^%^GREEN%^i%^BOLD%^s%^RESET%^%^GREEN%^t%^RESET%^");
   	set_short("%^BOLD%^%^BLACK%^Tyrant's %^BOLD%^%^GREEN%^"+
		"F%^RESET%^%^GREEN%^i%^BOLD%^s%^RESET%^%^GREEN%^t%^RESET%^");
   	set_id(({"morning star","tyrant's fist","mace","weapon"}));
   	set_long("%^RESET%^This wicked looking morning star takes"+
		" on an intimidating appearance.  Crafted from a "+
		"solid piece of %^BOLD%^%^BLACK%^black onyx%^RESET%^"+
		", the head of the morning star is made to resemble "+
		"a clenched fist with long talons.  Spikes of "+
		"%^BOLD%^%^GREEN%^emerald green%^RESET%^ crystal"+
		" burst out of the fist, creating an effective means"+
		" to rend flesh, armor, and bone.  The %^BOLD%^%^BLACK%^"+
		"black hand%^RESET%^ has been grafted to a %^BOLD%^%^BLACK%^"+
		"black onyx%^RESET%^ base, looking seamless and uniform.  "+
		"%^RED%^Scarlet red%^RESET%^ leather strips have been "+
		"braided with %^BOLD%^%^BLACK%^black satin%^RESET%^ to "+
		"create the hand hold of the morning star.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^GREEN%^The emerald spikes flash as "+
			"your rend your morning star into "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^GREEN%^The spikes on "+ETO->QCN+"'s"+
			" morning star flash as "+ETO->QS+" rends into you.");
      	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^The spikes on "+ETO->QCN+"'s"+
			" morning star flash as "+ETO->QS+" rends into "+
			" "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}