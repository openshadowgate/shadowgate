//Mask Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLACK%^Piercing Shadow%^RESET%^");
   	set_short("%^BOLD%^%^BLACK%^Piercing Shadow%^RESET%^");
   	set_id(({"dagger","piercing shadow","blade","weapon"}));
   	set_long("%^RESET%^Shaped from pure %^BOLD%^%^BLACK%^"+
		"shadows%^RESET%^, this long thin dagger seems "+
		"to soak up the surrounding light.  A shadowy haze"+
		" rolls off the dagger, making it hard to determine"+
		" the exact shape.  Swirling and churning about the"+
		" %^BOLD%^%^BLACK%^shadows%^RESET%^ are in a constant"+
		" flux, fading and deepening randomly.  The hilt of "+
		"the dagger is made from %^BOLD%^%^BLACK%^smokey quartz"+
		" %^RESET%^and smooth to the touch.  The edges of the hilt"+
		" are tinged in %^BOLD%^%^RED%^red%^RESET%^.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^BLACK%^The shadows around the "+
			"blade solidify for a moment, allowing you to viciously"+
			" stab "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+" viciously stabs"+
			" you with "+ETO->QP+" shadowy blade.");
      	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" viciously stabs"+
			" "+targ->QCN+" with "+ETO->QP+" shadowy blade.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}