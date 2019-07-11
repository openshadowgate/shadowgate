//Kossuth Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^RED%^F%^RESET%^ORANGE%^l"+
		"%^YELLOW%^a%^RESET%^%^ORANGE%^m%^BOLD%^"+
		"%^RED%^e Blade%^RESET%^");
   	set_short("%^BOLD%^%^RED%^F%^RESET%^ORANGE%^l"+
		"%^YELLOW%^a%^RESET%^%^ORANGE%^m%^BOLD%^"+
		"%^RED%^e Blade%^RESET%^");
   	set_id(({"weapon","flame blade","blade","sword"}));
   	set_long("%^RESET%^Shaped out of pure %^BOLD%^%^RED%^"+
		"fire%^RESET%^, this long sword blazes with the "+
		"heat of an %^RED%^inferno%^RESET%^.  The crackling"+
		" blade %^ORANGE%^blazes%^RESET%^ and %^YELLOW%^"+
		"dances%^RESET%^ wildly, never seeming to hold any "+
		"true shape.  The core of the sword burns %^BOLD%^white"+
		"%^RESET%^ hot.  Licks of %^BOLD%^%^RED%^flame%^RESET%^"+
		" radiate outwards from the core, creating deadly "+
		"wisps that burn with intensity.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^RED%^The flames of the sword burst"+
			" outwards, burning "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^RED%^%^"+ETO->QCN+"'s flaming blade"+
			" bursts, burning you deeply!");
      	tell_room(environment(ETO),"%^BOLD%^%^RED%^%^"+ETO->QCN+"'s "+
			"flaming sword bursts as it strikes "+targ->QCN+","+
			" burning "+targ->QO+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}