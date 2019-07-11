//Kelemvor Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^RESET%^S%^BOLD%^w%^RESET%^o%^BOLD%^r%^RESET%^d"+
		" of %^GREEN%^R%^RESET%^e%^GREEN%^p%^RESET%^o%^GREEN%^"+
		"s%^RESET%^e%^RESET%^");
   	set_short("%^RESET%^S%^BOLD%^w%^RESET%^o%^BOLD%^r%^RESET%^d"+
		" of %^GREEN%^R%^RESET%^e%^GREEN%^p%^RESET%^o%^GREEN%^"+
		"s%^RESET%^e%^RESET%^");
   	set_id(({"sword","sword of repose","blade","weapon"}));
   	set_long("This magnificent bastard sword shines with a "+
		"%^BLUE%^dim%^RESET%^ light.  The one handed bastard"+
		" sword has been created from pure %^BOLD%^silver%^RESET%^"+
		".  The sword retains an antiquated feel to it, looking "+
		"more like an ancient relic than anything modern.  The "+
		"hilt of the blade features a %^GREEN%^scarab beetle%^RESET%^"+
		" made from %^ORANGE%^tiger's eye%^RESET%^, with the wings"+
		" jutting out on each side of the blade.  The symmetrical "+
		"and orderly flow of the divine blade radiates a feeling of"+
		" strength.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^ORANGE%^The winged scarab beetle begins to "+
			"glow as you slash through "+targ->QCN+".");
      	tell_object(targ,"%^ORANGE%^The winged scarab beetle on "+
			""+ETO->QCN+"'s blade begins to glow as "+ETO->QS+""+
			" slashes through you!");
      	tell_room(environment(ETO),"%^ORANGE%^The winged scarab beetle on "+
			""+ETO->QCN+"'s blade begins to glow as "+ETO->QS+""+
			" slashes through "+targ->QCN+"!",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}