//Oghma Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^YELLOW%^Sharp %^BOLD%^%^WHITE%^W%^BLACK%^"+
		"i%^WHITE%^t%^RESET%^");
   	set_short("%^YELLOW%^Sharp %^BOLD%^%^WHITE%^W%^BLACK%^"+
		"i%^WHITE%^t%^RESET%^");
   	set_id(({"sword","sharp wit","rapier","blade","weapon"}));
   	set_long("%^RESET%^This slender and graceful rapier has been "+
		"crafted out of %^BOLD%^white gold%^RESET%^.  The"+
		" narrow blade tapers off to a fine point, making"+
		" it a perfect thrusting weapon.  The pommel of this"+
		" divine rapier takes the shape of a slender serpentine"+
		" %^YELLOW%^dragon%^RESET%^, carved from a solid piece "+
		"of %^BOLD%^%^GREEN%^jade%^RESET%^. The slender dragon's"+
		" face is carved with a wise and knowledgeable look. The "+
		"%^GREEN%^wings%^RESET%^ of the dragon create a basket hilt,"+
		" offering protection to the hand when wielded.  This divine"+
		" rapier looks far to fragile and ornate to look like it "+
		"would be effective in combat.  Perhaps, though, that is "+
		"the point.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^YELLOW%^You feel your hand being guided "+
			"to a vulnerable spot in "+targ->QCN+"'s defense.");
      	tell_object(targ,"%^YELLOW%^"+ETO->QCN+" finds a vulnerable "+
			"spot in your defense and thrusts "+ETO->QP+" rapier "+
			"deep into you!");
      	tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+" finds a vulnerable "+
			"spot in "+targ->QCN+"'s defense and thrusts "+ETO->QP+" rapier "+
			"deep into "+targ->QO+"!",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}