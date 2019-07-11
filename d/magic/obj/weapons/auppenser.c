//Auppenser Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^CYAN%^M%^BLUE%^i%^RESET%^%^CYAN%^n"+
		"%^BLUE%^d%^BOLD%^ C%^CYAN%^r%^RESET%^%^CYAN%^u"+
		"%^BLUE%^s%^BOLD%^h%^RESET%^%^CYAN%^e%^BLUE%^r%^RESET%^");
   	set_short("%^BOLD%^%^CYAN%^M%^BLUE%^i%^RESET%^%^CYAN%^n"+
		"%^BLUE%^d%^BOLD%^ C%^CYAN%^r%^RESET%^%^CYAN%^u"+
		"%^BLUE%^s%^BOLD%^h%^RESET%^%^CYAN%^e%^BLUE%^r%^RESET%^");
   	set_id(({"mace","mind crusher","crusher","weapon"}));
   	set_long("%^BOLD%^%^WHITE%^Though crafted only of light and "+ 
		"psychic energy, this sceptre looks utterly "+
            "real.  The sceptre is formed of %^CYAN%^c%^BLUE%^o"+
            "%^RESET%^%^CYAN%^r%^BLUE%^u%^BOLD%^s%^CYAN%^c"+
		"%^RESET%^%^CYAN%^a%^BLUE%^t%^BOLD%^i%^CYAN%^n"+
		"%^RESET%^%^CYAN%^g %^BLUE%^b%^BOLD%^l%^RESET%^"+
		"%^BLUE%^u%^BOLD%^e%^WHITE%^ and %^BOLD%^%^CYAN%^"+
		"c%^RESET%^%^CYAN%^y%^BOLD%^a%^RESET%^%^CYAN%^n"+
		"%^BOLD%^%^WHITE%^ light that seems to hold a solid"+
		" mass.  The handle is composed of %^RESET%^"+
		"%^BLUE%^deeper blue%^BOLD%^%^WHITE%^ light that molds "+
            "to the wielder's hand.  The sceptre moves with "+
            "an amazing quickness, as though it can sense the "+
            "wielder's every thought.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^CYAN%^A bright glow radiates outwards"+
			" from deep within the sceptre as you slash into"+
			" "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^CYAN%^A bright glow radiates "+
			"outwards from deep within "+ETO->QCN+"'s"+
			" sceptre as "+ETO->QS+" slashes into you.");
      	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^A bright glow radiates "+
			"outwards from deep within "+ETO->QCN+"'s"+
			" sceptre as "+ETO->QS+" slashes into"+
			" "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}