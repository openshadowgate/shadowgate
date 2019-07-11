//Shaundakul Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLACK%^Sh%^RESET%^%^CYAN%^a"+
		"%^BOLD%^%^BLACK%^dow Sw%^RESET%^%^MAGENTA%^"+
		"o%^BOLD%^%^BLACK%^rd%^RESET%^");
   	set_short("%^BOLD%^%^BLACK%^Sh%^RESET%^%^CYAN%^a"+
		"%^BOLD%^%^BLACK%^dow Sw%^RESET%^%^MAGENTA%^"+
		"o%^BOLD%^%^BLACK%^rd%^RESET%^");
   	set_id(({"long sword","shadow sword","blade","sword","weapon"}));
   	set_long("%^RESET%^Shaped out of %^BOLD%^%^BLACK%^shadows, "+
		"this long sword is constantly shifting in "+
		"%^BOLD%^%^BLACK%^h%^RESET%^u%^BOLD%^%^BLACK%^e"+
		"%^RESET%^s.  Fashioned to mirror the Shadow Sword "+
		"that %^CYAN%^Shaundakul%^RESET%^ is said to wield"+
		" in his battles against undead, giants, ogres, "+
		"trolls and goblinkin this sword is seen as a sacred"+
		" gift to his faithful.  The edges of the sword are "+
		"%^MAGENTA%^blurred%^RESET%^, making it difficult to"+
		" see the outline of the blade.  The %^BOLD%^%^BLACK%^"+
		"shadows%^RESET%^ of the blade churn and move about as "+
		"if propelled by %^CYAN%^winds%^RESET%^.");
	set_value(0);
	set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;

	if(!random(10)) {
      	tell_object(ETO,"%^CYAN%^You slice the blade deep into"+
			" "+targ->QCN+", as a gust of wind fuels your attack.");
      	tell_object(targ,"%^CYAN%^"+ETO->QCN+" slices "+ETO->QP+" "+
			"blade deep into you, as a gust of wind fuels"+
			" "+ETO->QP+" attack.");
      	tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+" slices"+
			" "+ETO->QP+" blade deep into "+targ->QCN+", as a "+
			"gust of wind fuels "+ETO->QP+" attack.",({ETO,targ}));
      		targ->do_damage("torso",random(4)+4);
      	return 1;
   }
}