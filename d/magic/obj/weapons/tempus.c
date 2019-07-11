//Tempus Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^RESET%^B%^BOLD%^a%^RESET%^t%^BOLD%^t"+
		"%^RESET%^l%^BOLD%^e%^RESET%^'%^BOLD%^s "+
		"%^RED%^Fury%^RESET%^");
   	set_short("%^RESET%^%^B%^BOLD%^a%^RESET%^t%^BOLD%^t"+
		"%^RESET%^l%^BOLD%^e%^RESET%^'%^BOLD%^s "+
		"%^RED%^Fury%^RESET%^");
   	set_id(({"axe","battle's fury","battleaxe","battle axe", "weapon"}));
   	set_long("This seasoned and battleworn axe has been"+
		" created from %^BOLD%^%^RED%^fever iron%^RESET%^."+
		"  The %^RED%^reddish%^RESET%^ tint of the metal"+
		" highlights the numerous nicks and scratches across"+
		" the blades of the battle axe.  Unlike typical axes,"+
		" this one is fashioned all from metal, giving it a "+
		"martial feeling.  The axe head has been shaped to look"+
		" like a %^YELLOW%^fierce eagle%^RESET%^ with its wings"+
		" spread and ready to strike.  The eagle's feathers create"+
		" a %^BOLD%^serrated%^RESET%^ edge to the axe, perfect for"+
		" cleaving through armor, bone, and flesh.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^RED%^You cleave the battle axe "+
			"through "+targ->QCN+"'s armor with ease.");
      	tell_object(targ,"%^RED%^"+ETO->QCN+" cleaves "+ETO->QP+" "+
			"battle axe through your flesh!");
      	tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" cleaves"+
			" "+ETO->QP+" battle axe through "+
			" "+targ->QCN+"'s flesh!",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}