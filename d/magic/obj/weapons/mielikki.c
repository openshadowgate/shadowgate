//Mielikki Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
        set_name("%^BOLD%^%^WHITE%^Alicorn Blade%^RESET%^");
   	set_short("%^BOLD%^%^WHITE%^Alicorn Blade%^RESET%^");
   	set_id(({"blade","alicorn blade","sword","weapon"}));
   	set_long("%^RESET%^Crafted from %^BOLD%^ivory%^RESET%^"+
		" this spiraling blade looks like a larger version"+
		" of a unicorn's horn.  The straight horn starts "+
		"thick at the base and tapers to a fine, sharp, point."+
		"  Gleaming a brilliant %^BOLD%^white%^RESET%^ shade "+
		"the horn almost seems to glow with a magical aura.  "+
		"The horn has been grafted onto a hilt made up of "+
		"twisted %^GREEN%^i%^BOLD%^v%^RESET%^%^GREEN%^y%^RESET%^"+
		".  The %^GREEN%^i%^BOLD%^v%^RESET%^%^GREEN%^y%^RESET%^"+
		" oddly enough feels solid and secure, but soft and "+
		"comfortable as well.  This divine blade seems to "+
		"radiate a feeling of purity and vitality.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^GREEN%^The blade pulses with a green"+
			" aura as you puncture "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^GREEN%^"+ETO->QCN+"'s ivory blade"+
			" pulses a green aura as "+ETO->QS+" punctures you.");
      	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETO->QCN+"'s ivory blade"+
			" pulses a green aura as "+ETO->QS+" punctures"+
			" "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}
