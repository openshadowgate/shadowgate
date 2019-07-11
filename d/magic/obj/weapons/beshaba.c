//Beshaba Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLACK%^Scourge of %^BOLD%^%^RED%^M"+
		"%^BOLD%^%^MAGENTA%^i%^BOLD%^%^BLACK%^s%^BOLD%^"+
		"%^RED%^f%^BOLD%^%^MAGENTA%^o%^BOLD%^%^BLACK%^r"+
		"%^BOLD%^%^RED%^t%^BOLD%^%^MAGENTA%^u%^BOLD%^"+
		"%^BLACK%^n%^BOLD%^%^RED%^e%^RESET%^");
   	set_short("%^BOLD%^%^BLACK%^Scourge of %^BOLD%^%^RED%^M"+
		"%^BOLD%^%^MAGENTA%^i%^BOLD%^%^BLACK%^s%^BOLD%^"+
		"%^RED%^f%^BOLD%^%^MAGENTA%^o%^BOLD%^%^BLACK%^r"+
		"%^BOLD%^%^RED%^t%^BOLD%^%^MAGENTA%^u%^BOLD%^"+
		"%^BLACK%^n%^BOLD%^%^RED%^e%^RESET%^");
   	set_id(({"scourge","scourge of misfortune","whip","weapon"}));
   	set_long("%^RESET%^Crafted from %^BOLD%^%^BLACK%^black"+
		" leather%^RESET%^, this scourge has a wild and "+
		"wicked appearance to it.  Interwoven into the each"+
		" of the thirteen lashes are alternative bands of "+
		"%^BOLD%^%^MAGENTA%^mauve%^RESET%^ and %^BOLD%^%^RED%^"+
		"bright red%^RESET%^.  %^BOLD%^%^BLACK%^Black horn%^RESET%^"+
		" barbs jut out of each of the thirteen lashes, giving the"+
		" scourge a painful sting.  The scourge is thought to be"+
		" modeled after the Maid of Misfortune's own sacred "+
		"weapon.%^RESET%^.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^RED%^Several of the lashes "+
			"wrap around "+targ->QCN+"'s arm, piercing"+
			" "+targ->QP+" flesh.");
      	tell_object(targ,"%^BOLD%^%^RED%^Several of the "+
			"lashes from "+ETO->QCN+"'s scourge wraps "+
			"around your arm, the black horn barbs piercing "+
			"your flesh.");
      	tell_room(environment(ETO),"%^BOLD%^%^RED%^Several of the "+
			"lashes from "+ETO->QCN+"'s scourge wraps "+
			"around "+targ->QCN+"'s arm, the black horn barbs"+
			" piercing "+targ->QP+" flesh.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}