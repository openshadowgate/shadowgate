//Tymora Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLUE%^Gambler's %^WHITE%^Spirit%^RESET%^");
   	set_short("%^BOLD%^%^BLUE%^Gambler's %^WHITE%^Spirit%^RESET%^");
   	set_id(({"sword","gambler's spirit","blade","weapon"}));
   	set_long("%^RESET%^Larger than a dagger but smaller than"+
		" a short sword, this strange blade has been made of"+
		" pure %^BOLD%^silver%^RESET%^.  The thin silver blade"+
		" has been crafted with a rippling wave-like appearance "+
		"to it, making it very suitable for piercing flesh or armor."+
		"  Fashioned from %^BOLD%^silver%^RESET%^ as well, the "+
		"hilt is shaped to look like a spread of %^BOLD%^%^CYAN%^"+
		"cards%^RESET%^.  A %^BOLD%^%^CYAN%^blue topaz%^RESET%^ pommel"+
		" provides a comfortable hand hold.  This divine blade seems "+
		"rather strange and peculiar.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^WHITE%^%^The spread of cards that "+
			"make up the hilt appear to shuffle right before you "+
			"thrust the blade into "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^WHITE%^The sound of cards shuffling"+
			" can be heard right before  "+
			""+ETO->QCN+"'s thrusts "+ETO->QP+" blade into your flesh.");
      	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The sound of cards "+
			"shuffling can be heard right before "+ETO->QCN+" "+
			" thrusts "+ETO->QP+" blade into"+
			" "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}