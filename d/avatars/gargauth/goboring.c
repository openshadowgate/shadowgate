#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("ring");
	set_id(({ "ring", "silver ring", "assassin ring", "blood of the assassins ring" }));
	set_short("%^BOLD%^%^WHITE%^Ring of the Assassins%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^shiny silver ring%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This %^BOLD%^%^WHITE%^silver ring %^RESET%^%^CYAN%^shines and has a magical glow upon it, perhaps from some type of %^YELLOW%^magical enchantment%^RESET%^%^CYAN%^. This ring maintains a sparkle that is almost blinding to the naked eye. Strangely, a %^RESET%^%^RED%^red inscription %^RESET%^%^CYAN%^can be seen engraved inside the band of the ring itself.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RED%^Blood of the Assassins%^RESET%^

AVATAR
	);
     set("langage","goblin");	set_weight(2);
	set_value(250);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^It is said that this ring is passed down by the goblin assassin, Harthugg, himself to those he feels worthy of taking his place and sharing his abilities in due time. This is a treasured item among the %^BOLD%^%^BLACK%^goblin assassins%^BOLD%^%^WHITE%^. It is so sacred, that supposedly, even the %^RESET%^%^YELLOW%^goblin king %^BOLD%^%^WHITE%^does not know that they exist. Apparently, one of the %^RESET%^%^RED%^goblin sorcerers %^BOLD%^%^WHITE%^placed a small %^RESET%^%^CYAN%^enchantment %^BOLD%^%^WHITE%^upon the ring to give the wearer added protection.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",20);
	set("dexbonus",1);
	set_type("ring");
	set_limbs(({ "left hand", "right hand" }));
	set_size(1);
	set_property("enchantment",0);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^It seems that "+ETOQCN+" appears quicker than usual as they slip on the "+query_short()+" %^BOLD%^%^WHITE%^onto their finger.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You seem more agile as you slip on the "+query_short()+" %^BOLD%^%^WHITE%^quickly.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^You notice that "+ETOQCN+" looks sluggish after removing the "+query_short()+" %^BOLD%^%^WHITE%^from their finger.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You feel very lethargic as you slip off the "+query_short()+" %^BOLD%^%^WHITE%^from your finger.%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}

