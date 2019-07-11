//Helm Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^RESET%^%^CYAN%^Blade of %^BLUE%^V%^RESET%^i"+
		"%^BLUE%^g%^RESET%^i%^BLUE%^l%^RESET%^a%^BLUE%^n"+
		"%^RESET%^c%^BLUE%^e%^RESET%^");
   	set_short("%^RESET%^%^CYAN%^Blade of %^BLUE%^V%^RESET%^i"+
		"%^BLUE%^g%^RESET%^i%^BLUE%^l%^RESET%^a%^BLUE%^n"+
		"%^RESET%^c%^BLUE%^e%^RESET%^");
   	set_id(({"sword","blade of vigilance","blade","weapon"}));
   	set_long("This thick bastard sword was created from "+
		"%^CYAN%^steel%^RESET%^.  The steel has been "+
		"polished to a %^BOLD%^%^CYAN%^bright%^RESET%^"+
		" finish, giving it a well cared for feeling.  "+
		"Carved up the center of the blade are a series of"+
		" %^BLUE%^runes%^RESET%^ on either side.  "+
		"The pommel and hilt of the "+
		"blade have been fashioned to looks like a male figure"+
		" clad in %^CYAN%^platemail%^RESET%^, his arms crossed "+
		"over his chest.  The figure's face is hidden behind a "+
		"close faced helm, giving him an almost intimidating "+
		"appearance.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BLUE%^The runes of the blade light up in"+
			" an orderly fashion as you slash through "+targ->QCN+".");
      	tell_object(targ,"%^BLUE%^The runes on "+
			""+ETO->QCN+"'s blade light up in an orderly "+
			"fashion as "+ETO->QS+" slashes through you!");
      	tell_room(environment(ETO),"%^BLUE%^The runes on "+
			""+ETO->QCN+"'s blade light up in an orderly "+
			"fashion as "+ETO->QS+" slashes through"+
			" "+targ->QCN+"!",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}