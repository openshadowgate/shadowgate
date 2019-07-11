//Sune Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^RESET%^%^GREEN%^L%^RESET%^i%^GREEN%^vi%^ORANGE%^n"
		"%^GREEN%^g Sw%^BOLD%^o%^RESET%^%^GREEN%^rd%^RESET%^");
   	set_short("%^RESET%^%^GREEN%^L%^RESET%^i%^GREEN%^vi%^ORANGE%^n"
		"%^GREEN%^g Sw%^BOLD%^o%^RESET%^%^GREEN%^rd%^RESET%^");
   	set_id(({"sword","living sword","wooden sword","weapon"}));
   	set_long("%^RESET%^%^ORANGE%^This slender sword is made from a "
		"thin %^BOLD%^%^BLACK%^ironwood %^RESET%^%^ORANGE%^blade "
		"fitted to a car%^YELLOW%^v%^RESET%^%^ORANGE%^ed woo%^YELLOW%^"
		"d%^RESET%^%^ORANGE%^en hilt.  Living %^GREEN%^vi%^BOLD%^n"
		"%^RESET%^%^GREEN%^es %^ORANGE%^covered with t%^YELLOW%^h"
		"%^RESET%^%^ORANGE%^or%^GREEN%^n%^ORANGE%^s climb and encircle the blade, "
		"seeming to shift even as you watch.  The faithful of the "
		"%^BOLD%^%^GREEN%^O%^RESET%^%^GREEN%^a%^BOLD%^k %^RESET%^"
		"%^GREEN%^F%^ORANGE%^a%^GREEN%^t%^BOLD%^h%^RESET%^%^GREEN%^"
		"er%^ORANGE%^ prize these blades, which are granted by "
		"%^BOLD%^%^GREEN%^Silvanus %^RESET%^%^ORANGE%^himself.  "
		"This divine blade seems to radiate a sense of balance and harmony.%^RESET%^");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^RESET%^%^GREEN%^The thorns on the vines wrapped "
			"around your sword snag "+targ->QCN+", scoring "+targ->QP+" flesh!%^RESET%^");
      	tell_object(targ,"%^RESET%^%^GREEN%^The thorns on the sword wielded by "+ETO->QCN+""+
			"tear your flesh!%^RESET%^");
      	tell_room(EETO,"%^RESET%^%^GREEN%^The thorns on the sword wielded by "+ETO->QCN+""+
			"tear "+targ->QCN+"'s flesh!%^RESET%^",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}