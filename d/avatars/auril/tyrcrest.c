#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("crest of tyr");
	set_id(({ "crest" }));
	set_short("%^BOLD%^%^YELLOW%^Crest of the %^BOLD%^%^RED%^E%^BOLD%^%^YELLOW%^v%^BOLD%^%^RED%^e%^BOLD%^%^YELLOW%^n%^BOLD%^%^RED%^-%^BOLD%^%^YELLOW%^h%^BOLD%^%^RED%^a%^BOLD%^%^YELLOW%^n%^BOLD%^%^RED%^d%^BOLD%^%^YELLOW%^e%^BOLD%^%^RED%^d%^RESET%^");
	set_obvious_short("%^BOLD%^%^YELLOW%^A gold encrusted crest%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^YELLOW%^The crest is a beautifully sculped piece of art. Upon the crest there is a noble warrior missing his right hand, lost to Kezef the Chaos Hound in proving his resilience and strength of spirit. The symbol shows the man's nature, that of %^BOLD%^%^RED%^Tyr%^BOLD%^%^YELLOW%^: justice through benevolent force and armed vigilance. %^BOLD%^%^BLUE%^" %^BOLD%^%^RED%^He opposes all who deal in trickery, rule-breaking, and unjust destruction and misdeeds%^BOLD%^%^BLUE%^" %^BOLD%^%^YELLOW%^is enscribed on the bottom within a finely crafted banner. 

AVATAR
	);
	set_weight(5);
	set_value(1000);
	set_lore(
@AVATAR
Created by the priests of Tyr, these are given to those worthy of followers.

AVATAR
	);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETO->query_cap_name()+" lifts his head proudly as they wear the crest.",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^You feel proud as you wear the crest.");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETO->query_cap_name()+" frowns slightly as they remove the crest.",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^You do not really want to remove it, but you do.");
	ETO->set_property("magic resistance",-5);
	return 1;
}
