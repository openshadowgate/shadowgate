//Selune Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
   	set_name("%^RESET%^%^BOLD%^Moo%^CYAN%^n%^WHITE%^bl"+
		"%^CYAN%^a%^WHITE%^de%^RESET%^");
   	set_short("%^RESET%^%^BOLD%^Moo%^CYAN%^n%^WHITE%^bl"+
		"%^CYAN%^a%^WHITE%^de%^RESET%^");
   	set_id(({"weapon","moonblade","blade"}));
   	set_long("%^RESET%^Fashioned out of pure %^BOLD%^"+
		"moonlight%^RESET%^, this slender blade has a"+
		" slight curve to it.  The %^BOLD%^%^WHITE%^milky"+
		" white%^RESET%^ moonlight has a semi-ethereal "+
		"quality to it.  The swirling mass of moonlight "+
		"pulsates with a soft %^BOLD%^s%^RESET%^i%^BOLD%^"+
		"l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^y%^RESET%^"+
		" glow.  The glow seems to move through a cycle, "+
		"%^BOLD%^%^CYAN%^waxing%^RESET%^ and %^CYAN%^waning"+
		"%^RESET%^ from dim to intense.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^WHITE%^The moonblade flashes as "+
			"it slices through "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^WHITE%^%^"+ETO->QCN+"'s moonblade"+
			" flashes as it slices through you!");
      	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^%^"+ETO->QCN+"'s "+
			"moonblade flashes as it slices through "+
			""+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}