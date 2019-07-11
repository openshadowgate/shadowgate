//Torm Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
   	set_name("%^YELLOW%^Blade of %^WHITE%^B%^YELLOW%^r"+
		"%^WHITE%^ave%^YELLOW%^r%^WHITE%^y%^");
   	set_short("%^YELLOW%^Blade of %^WHITE%^B%^YELLOW%^r"+
		"%^WHITE%^ave%^YELLOW%^r%^WHITE%^y%^");
   	set_id(({"blade","blade of bravery","sword", "weapon"}));
   	set_long("%^RESET%^This gleaming %^BOLD%^white%^RESET%^"+
		" blade is shaped from pure %^BOLD%^titanium%^RESET%^."+
		"  The one handed bastard sword is neither slender or "+
		"thick, but somehow a perfect balance between the two.  "+
		"A %^YELLOW%^yellow gold%^RESET%^ figurine forms the pommel"+
		" and handle of this divine blade.  The figurine is shaped to"+
		" look like a noble and proud seated %^ORANGE%^lion%^RESET%^."+
		"  The head of the lion rest upon the blade, with its mane "+
		"curling outwards.  %^BOLD%^%^BLUE%^Blue sapphire%^RESET%^ "+
		"gems have been inlaid into the eyes of the lion.  The white"+
		" blade shines brightly in the light, almost as it was a beacon.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^WHITE%^You slash the blade through"+
			" "+targ->QCN+", with a steady and true hand.");
      	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+" slashes"+
			" "+ETO->QP+" through your with a steady and true hand.");
      	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->QCN+" slashes"+
			" "+ETO->QP+" through "+targ->QCN+" with a steady"+
			" and true hand.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}
