//Akadi Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^CYAN%^W%^BLUE%^h%^CYAN%^i%^BLUE%^"+
		"p%^CYAN%^p%^BLUE%^i%^CYAN%^n%^WHITE%^g %^BLUE%^"+
		"W%^WHITE%^i%^BLUE%^n%^CYAN%^d%^RESET%^");
   	set_short("%^BOLD%^%^CYAN%^W%^BLUE%^h%^CYAN%^i%^BLUE%^"+
		"p%^CYAN%^p%^BLUE%^i%^CYAN%^n%^WHITE%^g %^BLUE%^"+
		"W%^WHITE%^i%^BLUE%^n%^CYAN%^d%^RESET%^");
   	set_id(({"whip","whipping wind","weapon"}));
   	set_long("%^RESET%^Thin and slender, this whirling mass"+
		" of %^BOLD%^%^BLUE%^air%^RESET%^ and %^BOLD%^wind"+
		"%^RESET%^ has been magically shaped into a lash.  "+
		"The lash is in a constant state of movement, as if "+
		"propelled by the winds within.  A faint %^BOLD%^%^CYAN%^"+
		"light blue%^RESET%^ aura radiates around the transparent"+
		" whip, providing the only means of identify this divine "+
		"weapon.  The ribbon like lash tapers off at the tip, "+
		"providing an effective means of slashing into flesh.  "+
		"By holding the lash, one could feel the fickle winds "+
		"inside moving from %^BOLD%^%^BLUE%^gentle breezes%^RESET%^"+
		" to %^BOLD%^%^WHITE%^fierce gales%^RESET%^.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^CYAN%^The force around the lash"+
			" opens up and releases a gale force gust at "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^CYAN%^A concentrated stream of gale"+
			" force winds slams into you.");
      	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^A concentrated stream"+
			" of gale force winds slames into"+
			" "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}