#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Robe of Glass");
	set_id(({ "robe" }));
	set_short("%^BOLD%^%^WHITE%^Robe of Glass");
	set_obvious_short("%^BOLD%^%^WHITE%^Robes made of glass");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^These beautiful robes seem to be forged with devine power and glass. Totaly see through they are like looking through a wavy glass window. The only part you cannot see through is the %^RESET%^%^WHITE%^silver%^BOLD%^%^WHITE%^ shield placed on the back. Attached to the wearers shoulder by two %^YELLOW%^gold %^WHITE%^clasps, round in form. Flowing down to the top of the wearers boots. It shifts shape in the wind like any other robe, except for the fact that they are made of glass.
%^BOLD%^%^BLUE%^Upon the shield, there is writing that appears when the light hits it right.

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLUE%^Protect and Serve all that is good. Guard it with your life and thou shall be rewarded in for eternity. 

AVATAR
	);
	set_weight(10);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(10);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^As "+ETO->query_cap_name()+" clasps the "+query_short()+" to his %^BLUE%^armor %^WHITE%^the shield upon the back lights up briefly.",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^As you clasp on the "+query_short()+" to your %^BLUE%^armor %^WHITE%^the shield upon the back lights up briefly.");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^BOLD%^WHITE%^As "+ETO->query_cap_name()+" removes his "+query_short()+" the shield upon the back flashes.",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^The shield upon the "+query_short()+" flashes slightly as you remove it.");
	ETO->set_property("magic resistance",5);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 95){
	tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^The "+query_short()+" hardens upon the point of impact as "+who->query_cap_name()+" strikes it.",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The "+query_short()+" hardens upon the point of impact.");
	tell_object(who,"%^BOLD%^%^WHITE%^As you strike "+ETO->query_cap_name()+" his "+query_short()+" hardens upon inpact.");
		return (damage*50)/100;
	}
}