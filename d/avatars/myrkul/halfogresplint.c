#include <std.h>
inherit "/d/common/obj/armour/splint";

void create(){
	::create();
	set_name("%^RESET%^%^ORANGE%^s%^YELLOW%^p%^RESET%^%^ORANGE%^lint m%^YELLOW%^a%^RESET%^%^ORANGE%^il%^RESET%^");
	set_id(({ "armor", "splint", "splint mail" }));
	set_short("%^RESET%^%^ORANGE%^C%^YELLOW%^o%^RESET%^%^ORANGE%^pp%^YELLOW%^e%^RESET%^%^ORANGE%^r %^RESET%^%^ORANGE%^s%^YELLOW%^p%^RESET%^%^ORANGE%^lint m%^YELLOW%^a%^RESET%^%^ORANGE%^il%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^C%^YELLOW%^o%^RESET%^%^ORANGE%^pp%^YELLOW%^e%^RESET%^%^ORANGE%^r %^RESET%^%^ORANGE%^s%^YELLOW%^p%^RESET%^%^ORANGE%^lint m%^YELLOW%^a%^RESET%^%^ORANGE%^il%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This armor is made out of strips of beaten %^YELLOW%^c%^RESET%^%^ORANGE%^opp%^YELLOW%^e%^RESET%^%^ORANGE%^r attached to a leather backing. It is relatively light compared to iron, R"
	"iveting allows the metal strips to be attached to the leather. The metal splints run lengthwise down the torso and arms. This armor has been made for a giant, and looks like very good protection.%^RES"
	"ET%^
"
	);
	set_value(5000);
	set_lore("This armor was made for a band of mercenaries that work for the Temple of Tempus at the Island city of Graez. The mercenaries were ogres and half-ogres paid large sums to kill the undead battling all "
	"living creatures. It is well made and said to have excellent protective powers. Some armor sets have been smuggled off the island.
"
	);
    set_property("lore difficulty",10);
	set_size(3);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"You feel like the copper splints are very good protection.");
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	ETO->set_property("magic resistance",5);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"You feel less well protected without the copper splint mail.");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	ETO->set_property("magic resistance",-5);
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 500){
	tell_room(environment(query_worn()),"%^YELLOW%^The blow bounces off the %^RESET%^%^ORANGE%^copper%^YELLOW%^ splints!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^YELLOW%^The blow bounces off the %^RESET%^%^ORANGE%^copper%^YELLOW%^ splints!%^RESET%^");
	tell_object(who,"%^YELLOW%^The blow bounces off the %^RESET%^%^ORANGE%^copper%^YELLOW%^ splints!%^RESET%^");
return (damage*0)/100;	}

}
