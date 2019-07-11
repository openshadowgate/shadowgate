//Malar Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^RESET%^%^RED%^Claws%^ORANGE%^ of %^RED%^B"+
		"%^BOLD%^%^RED%^l%^RESET%^%^RED%^oo%^BOLD%^d"+
		"%^RESET%^%^RED%^l%^BOLD%^u%^RESET%^%^RED%^st%^RESET%^");
   	set_short("%^RESET%^%^RED%^Claws%^ORANGE%^ of %^RED%^B"+
		"%^BOLD%^%^RED%^l%^RESET%^%^RED%^oo%^BOLD%^d"+
		"%^RESET%^%^RED%^l%^BOLD%^u%^RESET%^%^RED%^st%^RESET%^");
   	set_id(({"claws","claws of bloodlust","weapon"}));
   	set_long("Four long curved %^BOLD%^%^BLACK%^talons%^RESET%^"+
		" have been attached to a %^ORANGE%^leather%^RESET%^"+
		" brace.  The rustic leather brace has been crated "+
		"from the hide of a %^ORANGE%^stag%^RESET%^.  Stained"+
		" with %^BOLD%^%^RED%^blood%^RESET%^, the thick "+
"%^BOLD%^%^BLACK%^black claws%^RESET%^ taper to a fine"+
		" point, perfect for piercing flesh.  Spots of fresh "+
		"%^BOLD%^%^RED%^blood%^RESET%^ stain the leather brace,"+
                " giving an untamed wild feel to this divine weapon.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^RED%^You rip the claws through"+
			" "+targ->QCN+"'s flesh.");
      	tell_object(targ,"%^BOLD%^%^RED%^"+ETO->QCN+" rips through"+
			" your flesh with "+ETO->QP+" claws.");
      	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+" rips through"+
			" "+targ->QCN+"'s flesh with "+ETO->QP+" claws.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}
