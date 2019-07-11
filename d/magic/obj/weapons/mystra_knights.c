//Mystra Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
   	set_name("%^RESET%^%^BLUE%^W%^BOLD%^e%^WHITE%^a%^BLUE%^v"+
		"%^RESET%^%^BLUE%^e%^BOLD%^%^WHITE%^-%^BLUE%^Touched"+
		" Blade%^RESET%^");
   	set_short("%^RESET%^%^BLUE%^W%^BOLD%^e%^WHITE%^a%^BLUE%^v"+
		"%^RESET%^%^BLUE%^e%^BOLD%^%^WHITE%^-%^BLUE%^Touched"+
		" Blade%^RESET%^");
   	set_id(({"blade","sword","weave-touched blade","weapon"}));
   	set_long(
@CYTHERA
%^RESET%^Fashioned out of pure %^BOLD%^%^WHITE%^silver%^RESET%^, this long sword shines with a %^BOLD%^%^BLUE%^b%^WHITE%^l%^BLUE%^u%^WHITE%^e%^BLUE%^-%^WHITE%^w%^BLUE%^h%^WHITE%^i%^BLUE%^t%^WHITE%^e%^RESET%^ glow.  An ethereal mesh of %^BOLD%^%^WHITE%^silver%^RESET%^ threads seems to wrap around the blade, as if infused with the silver metal.  The hilt of the blade is crafted to look like a pair of %^BLUE%^hands%^RESET%^, with the fingers spread open.  The hands' are joined together by their linked thumbs.  A smooth pommel made a coiled length of %^BOLD%^%^WHITE%^silver%^RESET%^ supports the %^BOLD%^%^BLUE%^st%^WHITE%^a%^BOLD%^%^BLUE%^r sap%^WHITE%^p%^BOLD%^%^BLUE%^hire set into the base of the sword.%^RESET%^.
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
      	tell_object(ETO,"%^BOLD%^%^WHITE%^%^The silver mesh around the"+
			" blade blazes with a bright glow as you slash into"+
			" "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^WHITE%^The silver mesh around"+
			""+ETO->QCN+"'s blade blazes with a bright glow as "+
			""+ETO->QS+" slashes into you!");
      	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The silver mesh around"+
			""+ETO->QCN+"'s blade blazes with a bright glow as "+
			""+ETO->QS+" slashes into "+targ->QCN+"!",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}