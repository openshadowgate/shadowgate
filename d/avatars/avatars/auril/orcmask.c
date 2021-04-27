#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("orc mask");
	set_id(({ "mask", "orc mask" }));
	set_short("%^RESET%^%^ORANGE%^An orc mask%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^An orc mask%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is the most detailed mask of an orc face you have ever seen. Everytime the wearer would make any facial expressions, the mask mimics it perfectly. You can no longer recognize the face under the mask...if there is a mask at all. The face of the orc has a large snound and %^RESET%^%^RED%^dark red %^RESET%^%^ORANGE%^eyes. There are two large %^BOLD%^%^WHITE%^tusks %^RESET%^%^ORANGE%^coming up out of the mouth, and two smaller ones protruding down. The mask is a %^RESET%^%^GREEN%^sickly green %^RESET%^%^ORANGE%^and %^BOLD%^%^WHITE%^pale %^RESET%^%^ORANGE%^in color. Only from behind can the illusion of the mask truly be told. The mask straps in tightly with %^BOLD%^%^BLACK%^leather %^RESET%^%^ORANGE%^straps.

AVATAR
	);
	set_weight(5);
	set_value(500);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETO->query_cap_name()+" snarls violently as the mask is worn.",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^You snort as you wear the hideous mask.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETO->query_cap_name()+" calms down greatly when the mask is removed.",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^You feel far more normal when you remove the mask.");
	return 1;
}
