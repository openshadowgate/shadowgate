#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Ancient Shield");
	set_id(({ "shield" }));
	set_short("%^YELLOW%^Sh%^WHITE%^ie%^YELLOW%^ld%^RESET%^ of the %^ORANGE%^Ancient %^YELLOW%^K%^WHITE%^i%^YELLOW%^n%^WHITE%^g%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^ancient %^YELLOW%^g%^WHITE%^i%^YELLOW%^ld%^WHITE%^e%^YELLOW%^d %^RESET%^%^ORANGE%^shield%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This is a mighty, highly formal battle shield of ancient design.  The arrow-shaped shield is flat along the top and tapers into a point.  At about three feet in length, it would provide superior defense when worn on the arm through the dual leather straps affixed to the back.  The shield is forged primarily of %^BOLD%^%^WHITE%^highly polished steel %^RESET%^%^ORANGE%^but has been gilded at its three points and centerpiece in %^YELLOW%^gold %^RESET%^%^ORANGE%^and %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^ORANGE%^. The central image depicts three fierce rampant lions in a vertical column. There appears to be something inscribed onto the back of the shield that you might %^RESET%^<read>%^ORANGE%^.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
----==========__________=========---------
___---------====____--------====----------

-----___======_-------------------------------=====
___---------========--------_____----------------=

AVATAR
	);
     set("langage","common");	set_weight(10);
	set_value(5100);
	set_lore(
@AVATAR
The heraldic image depicted on this shield is that of the Imperial family of Sallarim, a long dynasty that ruled the lands now known as the Tsarven Empire almost 900 years ago.  A shield like the one you are holding was described as a possession of Sallarim III, a legendary figure noted for his mighty crusades against evil.  It is said that his shield possessed powers granted by the sun. 

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("shield");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^The room warms slightly as "+ETOQCN+" wears the shield%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You feel warm all over as you don the shield%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^CYAN%^The room chills slightly as "+ETOQCN+" removes their shield%^RESET%^",ETO);
	tell_object(ETO,"%^CYAN%^You feel a mild chill as you remove the shield%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 250){
	tell_room(environment(query_worn()),"%^YELLOW%^The shield worn by "+ETOQCN+" releases a hot blast of light at "+who->QCN+"!",({ETO,who}));
	tell_object(ETO,"%^YELLOW%^Your shield releases a blast of hot light at your enemy!");
	tell_object(who,"%^YELLOW%^You are seared by hot light when you strike the shield worn by "+ETOQCN+"");
		who->do_damage("torso",roll_dice(1,6));
return damage;	}
}