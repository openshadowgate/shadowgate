//Bane Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLACK%^Tyrant's %^BOLD%^%^GREEN%^"+
		"B%^RESET%^%^GREEN%^l%^BOLD%^a%^RESET%^%^GREEN%^"+
		"d%^BOLD%^e%^RESET%^");
   	set_short("%^BOLD%^%^BLACK%^Tyrant's %^BOLD%^%^GREEN%^"+
		"B%^RESET%^%^GREEN%^l%^BOLD%^a%^RESET%^%^GREEN%^"+
		"d%^BOLD%^e%^RESET%^");
   	set_id(({"blade","tyrant's sword","sword","weapon"}));
   	set_long("%^RESET%^This wicked looking sword takes"+
		" on an intimidating appearance.  Crafted from a "+
		"solid piece of %^BOLD%^%^BLACK%^black onyx%^RESET%^"+
		", the pommel is made to resemble "+
		"a clenched fist with long talons.  Spikes of "+
		"%^BOLD%^%^GREEN%^emerald green%^RESET%^ crystal"+
		" burst out of the fist. The %^BOLD%^%^BLACK%^"+
		"black hand%^RESET%^ has been grafted to a %^BOLD%^%^BLACK%^"+
		"black onyx%^RESET%^ blade, looking seamless and uniform.  "+
		"%^RED%^Scarlet red%^RESET%^ run up the lenght"+
		" of the blade.%^RESET%^");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^GREEN%^The emerald spikes flash as "+
			"you tear your blade into "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^GREEN%^The spikes on "+ETO->QCN+"'s"+
			" blade flash as "+ETO->QS+" tear into you.");
      	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^The spikes on "+ETO->QCN+"'s"+
			" blade flash as "+ETO->QS+" tears into "+
			" "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}