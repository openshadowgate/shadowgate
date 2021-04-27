#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("ring");
	set_id(({ "ring", "ring of dexterity", "ring of dexterity +1", "dexterity ring" }));
	set_short("%^BOLD%^%^WHITE%^Ring of Dexterity%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a silver ring%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This %^BOLD%^%^WHITE%^silver ring %^BOLD%^%^BLACK%^appears quite shiny, even coming from one as filthy as a %^RESET%^%^GREEN%^goblin%^BOLD%^%^BLACK%^. It has a sparkle that catches your eye slightly. Perhaps, there is something written inside the band if you wish to look more closely.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RED%^Blood of the Assassins%^RESET%^

AVATAR
	);
     set("langage","goblin");	set_weight(1);
	set_value(750);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^You recall hearing that this ring is passed down by the goblin assassin, Harthugg, to those that he wishes to recruit into his entourage. Only those with enough skill and competence can receive such a ring. Apparently, he bribed one of the goblin sorcerers to %^RESET%^%^YELLOW%^enchant %^BOLD%^%^WHITE%^the ring with some power of importance.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set("dexbonus",1);
	set_type("ring");
	set_limbs(({ "left hand", "right hand" }));
	set_size(1);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" %^RESET%^%^BOLD%^%^WHITE%^receives a %^RESET%^%^YELLOW%^burst of energy %^RESET%^%^BOLD%^%^WHITE%^as they put on the "+query_short()+" %^RESET%^%^BOLD%^%^WHITE%^quickly.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You feel more agile as you slide on the "+query_short()+" %^RESET%^%^BOLD%^%^WHITE%^onto one of your fingers.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^ You notice that "+ETOQCN+" %^RESET%^%^BOLD%^%^WHITE%^seems lethargic after removing the "+query_short()+" %^RESET%^%^BOLD%^%^WHITE%^momentarily.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You feel lethargic as you slip off the "+query_short()+" %^RESET%^%^BOLD%^%^WHITE%^slowly.%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}

