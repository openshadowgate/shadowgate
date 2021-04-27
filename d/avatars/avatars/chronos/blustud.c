#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLUE%^Zarthaken's %^WHITE%^hide%^RESET%^");
	set_id(({ "studdedleather", "studded leather", "studded", "leather", "armor" }));
	set_short("%^BOLD%^%^BLUE%^Z%^CYAN%^a%^BLUE%^rth%^CYAN%^a%^BLUE%^k%^CYAN%^e%^BLUE%^n's%^WHITE%^ H%^RESET%^i%^BOLD%^d%^RESET%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^strange %^CYAN%^studded %^WHITE%^leather%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^Taking this into your hands the hairs along your arms stand on end. The leather is litterally pulsating with static %^YELLOW%^electricity%^BLUE%^. Along this unusual studded what appears to be thick %^CYAN%^sc%^BLUE%^a%^CYAN%^l%^BLUE%^e%^CYAN%^s%^BLUE%^ have been shaped and fitted to protect all of the wearer's most vital areas. The leather is inset with tough rivits of pure %^RESET%^%^CYAN%^mithril%^BOLD%^%^BLUE%^, to add both more defence and a sense of style. Upon the left shoulderguard 

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^Written under one of the scales ins the following ~ For Jeremiah, Hero of Shadow. Thanks again. Flugar ~%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(20);
	set_value(2500);
	set_lore(
@AVATAR
%^RESET%^%^ORANGE%^Crafted from the scales of the great dragon Zarthaken, this was awarded to one of the heroes of Shadow for bravery and selflessness above and beyond the call. It is said that some of the dragon's very essence remains within this and aides in the protection of it's wearer.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
     set_ac(3);
      //set_ac(5);  I am changing this to 3, because 6 is the max for leather AC - CYthera
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" tightens the straps of the armor, and looks ready for anything.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You strap the armor on and %^YELLOW%^Energy%^BLUE%^ courses through your body!%^RESET%^");
	ETO->set_property("magic resistance",15);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" can't help but yawn as they remove the armor%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You feel %^RED%^exhausted%^BLUE%^ as you pull the armor off%^RESET%^");
	ETO->set_property("magic resistance",-15);
	return 1;
}
