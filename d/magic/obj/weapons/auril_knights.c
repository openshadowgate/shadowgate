//Auril Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights.c";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^WHITE%^Pi%^CYAN%^e%^WHITE%^rc"+
		"%^CYAN%^i%^WHITE%^ng %^CYAN%^Ch%^WHITE%^i%^CYAN%^"+
		"ll%^RESET%^");
   	set_short("%^BOLD%^%^WHITE%^Pi%^CYAN%^e%^WHITE%^rc"+
		"%^CYAN%^i%^WHITE%^ng %^CYAN%^Ch%^WHITE%^i%^CYAN%^"+
		"ll%^RESET%^");
   	set_id(({"rapier","piercing chill","blade","sword","weapon"}));
   	set_long("%^RESET%^This rapier is created from a single "+
		"%^BOLD%^icicle%^RESET%^, made from the purest"+
		" %^BOLD%^%^CYAN%^water%^RESET%^.  The icicle "+
		"tapers from a wide base to a sharp tip.  "+
		"%^BOLD%^Frost%^RESET%^ cakes the surface of the"+
		" icicle,  giving it an opaque appearance.  Frozen"+
		" %^BOLD%^vapors%^RESET%^ roll off the surface of "+
		"the blade, though it never seems to melt.  A deep"+
		" hemisphere has been carved out of the base of the"+
		" icicle, creating a protective hilt.  The pommel of"+
		" this divine rapier is fashioned from the ice itself.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^CYAN%^You pierce the tip of the "+
			"blade deep into "+targ->QCN+", spreading the frigid"+
			" gifts of Auril.");
      	tell_object(targ,"%^BOLD%^%^CYAN%^"+ETO->QCN+" rams the tip of"+
			" "+ETO->QP+" rapier deep into you, piercing your body with"+
			" a frigid chill.");
      	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+" rams the"+
			" tip of "+ETO->QP+" rapier deep into "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}