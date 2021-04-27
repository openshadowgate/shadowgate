#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("armor of Earthlord");
	set_id(({ "armor", "plate", "fullplate", "full plate", "armor of earthlord" }));
	set_short("%^RESET%^%^ORANGE%^Armor of the E%^RED%^a%^ORANGE%^rthl%^RED%^o%^ORANGE%^rd%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^Stone fullplate%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a suit of fullplate armor designed in an older, romantic style than most modern plate, but no less useful for protection.  The breastplate and all other larger components of the armor are covered in a sort of rough stone riddled with %^RED%^minerals%^ORANGE%^ and off-colored %^BOLD%^%^BLACK%^gravel%^RESET%^%^ORANGE%^.  How the stone was permanently fused to the armor is a mystery, but it clearly offers extra protection as well as adding quite a bit of mass to the armor.%^RESET%^

AVATAR
	);
	set_weight(60);
	set_value(4200);
	set_lore(
@AVATAR
The Armor of the Earthlord is a special gift bestowed by Grumbar's servants to new members of the Sardonyx Knights.  It is said that the armor has the capacity to turn powerful blows into light bruises by harnessing the power of the earth.  Most suits are priceless and have been handed down for generations of holy and unholy warriors.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(8);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^The armor worn by "+ETOQCN+" %^RESET%^%^ORANGE%^covers itself in a layer of protective stone!%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^The stone on the armor spreads to form a fine crust around you, sealing you from harm!%^RESET%^");
	ETO->set_property("magic resistance",2);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^As "+ETOQCN+" %^RESET%^%^ORANGE%^removes the armor, grainy dust falls to the ground.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^The protective crust around you crumbles, freeing you from the armor.%^RESET%^");
	ETO->set_property("magic resistance",-2);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 150){
	tell_room(environment(query_worn()),"%^RESET%^%^ORANGE%^The rocky layer surrounding "+ETOQCN+" %^RESET%^%^ORANGE%^absorbs most of that attack!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^ORANGE%^The attack from "+who->QCN+" is mostly absorbed by the stone covered armor.%^RESET%^");
	tell_object(who,"%^RESET%^%^ORANGE%^The rocky layer surrounding "+ETOQCN+" %^RESET%^%^ORANGE%^absorbs most of that attack!%^RESET%^");
//return (damage*15)/100;	}
      return (damage*-85)/100;      } // Garrett fixes the armor.
}
