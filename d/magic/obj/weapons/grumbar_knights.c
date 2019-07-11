//Loviatar Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
   	set_name("%^RESET%^%^ORANGE%^Sword of the %^MAGENTA%^Mountain's"+
		" %^RED%^Might%^RESET%^");
   	set_short("%^RESET%^%^ORANGE%^Sword of the %^MAGENTA%^Mountain's"+
		" %^RED%^Might%^RESET%^");
   	set_id(({"weapon","blade","sword","sword of the mountain's might"}));
   	set_long(
@CYTHERA
%^RESET%^This thick and solid sword is crafted out of %^CYAN%^steel%^RESET%^.  The thick blade creates a wide surface to cleave through armor and flesh.  Imbedded deep in the steel blade are a variety of %^RED%^p%^ORANGE%^r%^YELLOW%^e%^WHITE%^c%^BOLD%^%^BLACK%^i%^GREEN%^o%^BLUE%^u%^RESET%^%^MAGENTA%^s%^RESET%^ gems, most of them in their raw unpolished state.  A heavy straight hilt is attached to a %^CYAN%^steel%^RESET%^ pommel.  On either ends of the hilt a single %^ORANGE%^topaz%^RESET%^ gem has been set.  Inside the topazes the image of a %^MAGENTA%^mountain%^RESET%^ can be seen carved.  The steel pommel of the blade is thick and solid and left unadorned.
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
      	tell_object(ETO,"%^ORANGE%^You cleave your blade through"+
			" "+targ->QCN+", backed by the strength of the earth"+
			" itself!");
      	tell_object(targ,"%^ORANGE%^"+ETO->QCN+" cleaves "+ETO->QP+" "+
			"sword through you with a strong powerful blow.");
      	tell_room(environment(ETO),"%^ORANGE%^"+ETO->QCN+" cleaves "+ETO->QP+" "+
			"sword through "+targ->QCN+" with a strong powerful blow.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}