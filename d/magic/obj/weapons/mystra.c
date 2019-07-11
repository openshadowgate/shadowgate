//Mystra Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLUE%^S%^WHITE%^t%^BLUE%^a%^WHITE%^"+
		"r%^BLUE%^f%^WHITE%^i%^BLUE%^r%^WHITE%^e "+
		"%^WHITE%^Ch%^RED%^a%^WHITE%^in%^RESET%^");
   	set_short("%^BOLD%^%^BLUE%^S%^WHITE%^t%^BLUE%^a%^WHITE%^"+
		"r%^BLUE%^f%^WHITE%^i%^BLUE%^r%^WHITE%^e "+
		"%^WHITE%^Ch%^RED%^a%^WHITE%^in%^RESET%^");
   	set_id(({"chain","starfire chain","weapon"}));
   	set_long("%^RESET%^Links made of pure "+
		"%^BOLD%^%^CYAN%^crystal%^RESET%^ are strung "+
		"together to create this chain.  The slender "+
		"chain appears to be on the short side, about two"+
		" feet long at most.  Within each %^BOLD%^%^CYAN%^"+
		"crystal%^RESET%^ link a whirling mass of %^BLUE%^"+
		"midnight blue%^RESET%^ can be seen.  Motes of "+
		"%^BLUE%^b%^BOLD%^l%^RESET%^%^BLUE%^u%^BOLD%^e%^RESET%^"+
		"-%^BOLD%^wh%^CYAN%^i%^WHITE%^te%^RESET%^ light wink"+
		" in and out of existence within the %^BLUE%^dark blue"+
		"%^RESET%^ mist, each one looking like a miniature star."+
		"  This divine chain radiate an aura of %^RED%^raw magic%^RESET%^.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^WHITE%^%^The motes of light begin to spin"+
			" faster within each link, releasing a fiery burst"+
			" into "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^WHITE%^Motes of light within "+
			""+ETO->QCN+"'s crystal chain begin to spin faster"+
			" before releasing a fiery burst into you!");
      	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^Motes of light within "+
			""+ETO->QCN+"'s crystal chain begin to spin faster"+
			" before releasing a fiery burst into"+
			" "+targ->QCN+"!",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}