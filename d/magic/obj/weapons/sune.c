//Sune Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^RESET%^%^RED%^S%^BOLD%^i%^RESET%^%^RED%^l"+
		"%^BOLD%^k%^RESET%^%^RED%^e%^BOLD%^n%^RESET%^"+
		"%^RED%^ S%^YELLOW%^a%^RESET%^%^RED%^sh%^RESET%^");
   	set_short("%^RESET%^%^RED%^S%^BOLD%^i%^RESET%^%^RED%^l"+
		"%^BOLD%^k%^RESET%^%^RED%^e%^BOLD%^n%^RESET%^"+
		"%^RED%^ S%^YELLOW%^a%^RESET%^%^RED%^sh%^RESET%^");
   	set_id(({"sash","whip","silken sash","weapon"}));
   	set_long("%^RESET%^This five foot length of %^RED%^"+
		"deep crimson%^RESET%^ silk is about five feet "+
		"in length.  The ends of the sash are fringed with"+
		" %^RED%^deep crimson%^RESET%^ tassels and hemmed "+
		"with threads of pure %^YELLOW%^gold%^RESET%^. The "+
		"sash has an unassuming harmless appearance to it. "+
		" Across the surface of the sash, the silk flashes "+
		"and flares, as if infused with a dancing %^BOLD%^"+
		"%^RED%^f%^RESET%^%^RED%^l%^BOLD%^%^RED%^a%^RESET%^"+
		"%^RED%^m%^BOLD%^%^RED%^e%^RESET%^.  Modeled after "+
		"the sacred '%^RED%^Sash of Sune%^RESET%^', an ancient"+
		" relic of the faith, the silken sash is said to be "+
		"infused with fire.  The faithful of Sune Firehair use"+
		" the sash as a whip when they must fight to defend "+
		"themselves.%^RESET%^.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^RED%^A burst of flames covers the"+
			" silken sash and burns "+targ->QCN+".");
      	tell_object(targ,"%^RED%^A burst of flames covers "+ETO->QCN+"'s"+
			" silken sash and burns you.");
      	tell_room(environment(ETO),"%^RED%^A burst of "+
			"flames covers "+ETO->QCN+"'s"+
			" silken sash and burns "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}