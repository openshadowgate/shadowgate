//Cyric Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLACK%^Sword of %^BOLD%^%^WHITE%^Mad"+
		"%^RESET%^%^MAGENTA%^n%^BOLD%^%^WHITE%^ess%^RESET%^");
   	set_short("%^BOLD%^%^BLACK%^Sword of %^BOLD%^%^WHITE%^Mad"+
		"%^RESET%^%^MAGENTA%^n%^BOLD%^%^WHITE%^ess%^RESET%^");
   	set_id(({"sword","sword of madness","blade","weapon"}));
   	set_long("%^RESET%^This stylized long sword is crafted "+
		"from pure %^BOLD%^silver%^RESET%^.  The slender "+
		"blade of the sword is left unadorned on one side."+
		"  The opposite side of the blade bears a horrific "+
		"relief image of numerous %^MAGENTA%^twisted%^RESET%^"+
		" faces that appear to be screaming and howling.  "+
		"Shaped out of %^BOLD%^bone%^RESET%^, the pommel and "+
		"hilt of the blade is carved with wicked %^BOLD%^%^BLACK%^"+
		"spikes%^RESET%^ and %^RED%^demonic looking shapes%^RESET%^."+
		"  A miniature jawless skull, in %^BOLD%^silver%^RESET%^, "+
		"is attached to the bottom of the pommel.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^BLACK%^The blade releases a maddening"+
			" howl as you slash into "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s blade releases a"+
			" maddening howl as "+ETO->QS+" slashes into you.");
      	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s blade releases a"+
			" maddening howl as "+ETO->QS+" slashes into"+
			" "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}