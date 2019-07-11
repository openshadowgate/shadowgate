//Tyr Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^WHITE%^Hammer of %^BOLD%^%^BLUE%^"+
		"J%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLUE%^st%^RESET%^"+
		"%^MAGENTA%^i%^BOLD%^%^BLUE%^c%^RESET%^%^MAGENTA%^"+
		"e%^RESET%^");
   	set_short("%^BOLD%^%^WHITE%^Hammer of %^BOLD%^%^BLUE%^"+
		"J%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLUE%^st%^RESET%^"+
		"%^MAGENTA%^i%^BOLD%^%^BLUE%^c%^RESET%^%^MAGENTA%^"+
		"e%^RESET%^");
   	set_id(({"weapon","hammer of justice","hammer"}));
   	set_long("%^RESET%^This ancient looking hammer carries"+
		" a strong and solid feel to it.  The %^CYAN%^steel"+
		"%^RESET%^ hammer shows some minor signs of battle, "+
		"which do nothing to effect the %^BOLD%^bright%^RESET%^"+
		" glow of the metal.  Steady and uniform veins of "+
		"%^BOLD%^%^BLUE%^blue%^RESET%^ and %^MAGENTA%^violet"+
		" %^RESET%^reflect off the surface of the metal.  "+
		"A soft cushion grip around the thick handle of the "+
		"hammer helps in keeping a solid and firm hold of this"+
		" divine weapon.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^MAGENTA%^The hammer flashes as you"+
			" slam it into "+targ->QCN+".");
      	tell_object(targ,"%^MAGENTA%^%^"+ETO->QCN+"'s hammer"+
			" flashes as it comes slamming into you!");
      	tell_room(environment(ETO),"%^MAGENTA%^%^"+ETO->QCN+"'s "+
			"flashes as it comes slamming into "+targ->QCN+""+
			".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}