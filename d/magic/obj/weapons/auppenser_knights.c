//Bane Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^CYAN%^Blade of the %^RESET%^"+
		"%^ORANGE%^Mind's %^CYAN%^E%^BOLD%^%^CYAN%^y"+
		"%^RESET%^%^CYAN%^e%^RESET%^");
   	set_short("%^BOLD%^%^CYAN%^Blade of the %^RESET%^"+
		"%^ORANGE%^Mind's %^CYAN%^E%^BOLD%^%^CYAN%^y"+
		"%^RESET%^%^CYAN%^e%^RESET%^");
   	set_id(({"blade","blade of the mind's eye","sword","weapon"}));
   	set_long(
@CYTHERA
This smooth and uniform blade has been crafted out of a solid piece of %^BOLD%^%^CYAN%^blue quartz%^RESET%^ crystal.  The %^BOLD%^%^CYAN%^blue quartz%^RESET%^ blade has been sharpened to a fine edge.  The multiple facets of the quartz crystal reflect and refract the light around, causing the sword to %^BOLD%^glow%^RESET%^.  Twin eyes made of %^ORANGE%^bronze%^RESET%^ have been set on either side of the blade, at the base.  The pupils of the %^ORANGE%^bronze%^RESET%^ eyes have been left void, letting the %^BOLD%^%^CYAN%^blue quartz%^RESET%^ of the blade shine through.  Crafted out of %^ORANGE%^bronze%^RESET%^ the smooth and symmetrical pommel of the blade is left unadorned.
CYTHERA
);
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^BOLD%^%^CYAN%^A bright glow radiates outwards"+
			" from deep within the blade as you slash into"+
			" "+targ->QCN+".");
      	tell_object(targ,"%^BOLD%^%^CYAN%^A bright glow raidates "+
			"outwards from deep within "+ETO->QCN+"'s"+
			" blade as "+ETO->QS+" slashes into you.");
      	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^A bright glow raidates "+
			"outwards from deep within "+ETO->QCN+"'s"+
			" blade as "+ETO->QS+" slashes into"+
			" "+targ->QCN+".",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}