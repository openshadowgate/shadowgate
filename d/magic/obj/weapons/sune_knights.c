//Sune Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^RED%^F%^RESET%^%^RED%^l%^BOLD%^"+
		"%^RED%^a%^RESET%^%^RED%^m%^BOLD%^%^RED%^i"+
		"%^RESET%^%^RED%^n%^BOLD%^%^RED%^g Rose"+
		" %^RESET%^%^RED%^Rapier%^RESET%^");
   	set_short("%^BOLD%^%^RED%^F%^RESET%^%^RED%^l%^BOLD%^"+
		"%^RED%^a%^RESET%^%^RED%^m%^BOLD%^%^RED%^i"+
		"%^RESET%^%^RED%^n%^BOLD%^%^RED%^g Rose"+
		" %^RESET%^%^RED%^Rapier%^RESET%^");
   	set_id(({"rapier","blade","sword","flaming rose rapier","weapon"}));
   	set_long(
@CYTHERA
%^RESET%^Crafted out of %^BOLD%^%^WHITE%^ivory%^RESET%^, this slender rapier has an aesthetically appealing quality to it.  The slender blade of the rapier has been polished smooth, letting the %^BOLD%^%^WHITE%^brilliant white%^RESET%^ of the ivory shine forth.  Etched around the base of the blade are intertwined %^RED%^roses%^RESET%^ that appear to be made of %^BOLD%^%^RED%^f%^RESET%^%^RED%^l%^BOLD%^%^RED%^a%^RESET%^%^RED%^m%^BOLD%^%^RED%^e%^RESET%^%^RED%^s%^RESET%^.  The hand guard of the rapier is crafted from gracefully curved lines of %^BOLD%^%^RED%^rose%^RESET%^ and %^BOLD%^%^WHITE%^white%^RESET%^ gold, offering protection to the wielder's hand.  The pommel of the blade has been wrapped with %^RED%^deep crimson silk%^RESET%^, adding to the beauty of this divine rapier.%^RESET%^.
CYTHERA
	);
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^RED%^A burst of flames covers the"+
			" ivory rapier and burns "+targ->QCN+".");
      	tell_object(targ,"%^RED%^A burst of flames covers "+ETO->QCN+"'s"+
			" ivory rapier and burns you.");
      	tell_room(environment(ETO),"%^RED%^A burst of "+
			"flames covers "+ETO->QCN+"'s"+
			" ivory rapier and burns "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}