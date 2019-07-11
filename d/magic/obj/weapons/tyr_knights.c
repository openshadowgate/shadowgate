//Tyr Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^WHITE%^Sword of %^BOLD%^%^BLUE%^"+
		"J%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLUE%^st%^RESET%^"+
		"%^MAGENTA%^i%^BOLD%^%^BLUE%^c%^RESET%^%^MAGENTA%^"+
		"e%^RESET%^");
   	set_short("%^BOLD%^%^WHITE%^Sword of %^BOLD%^%^BLUE%^"+
		"J%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLUE%^st%^RESET%^"+
		"%^MAGENTA%^i%^BOLD%^%^BLUE%^c%^RESET%^%^MAGENTA%^"+
		"e%^RESET%^");
   	set_id(({"weapon","sword of justice","sword"}));
   	set_long("%^RESET%^This ancient looking sword carries"+
		" a strong and solid feel to it.  The %^CYAN%^steel"+
		"%^RESET%^ sword shows some minor signs of battle, "+
		"which do nothing to effect the %^BOLD%^bright%^RESET%^"+
		" glow of the metal.  Steady and uniform veins of "+
		"%^BOLD%^%^BLUE%^blue%^RESET%^ and %^MAGENTA%^violet"+
		" %^RESET%^reflect off the surface of the metal.  "+
		"A soft cushion grip around the thick handle of the "+
		"sword helps in keeping a solid and firm hold of this"+
		" divine weapon.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^MAGENTA%^The sword flashes as you"+
			" slash it into "+targ->QCN+".");
      	tell_object(targ,"%^MAGENTA%^%^"+ETO->QCN+"'s sword"+
			" flashes as it comes slashing into you!");
      	tell_room(environment(ETO),"%^MAGENTA%^%^"+ETO->QCN+"'s "+
			"sword flashes as it comes slashing into "+targ->QCN+""+
			".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}