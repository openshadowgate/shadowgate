#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Glittering moon stone necklace");
	set_id(({ "necklace", "Necklace" }));
	set_short("%^BOLD%^%^WHITE%^G%^CYAN%^l%^WHITE%^i%^CYAN%^t%^WHITE%^t%^CYAN%^e%^WHITE%^r%^CYAN%^i%^WHITE%^n%^CYAN%^g %^BOLD%^%^CYAN%^moon stone %^RESET%^%^CYAN%^necklace%^RESET%^");
	set_obvious_short("a necklace");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a beautifully crafted necklace, Using white gold to house and connect all of the %^CYAN%^moon stones. %^WHITE%^Because it is a %^CYAN%^thin %^WHITE%^and %^RESET%^%^CYAN%^slender %^BOLD%^%^WHITE%^necklace it looks like it would be rather %^CYAN%^delicate%^WHITE%^. The necklace is a basic loop with short tendrills, about an inch apart, hanging down off the front side of the loop, the longest tendrill in the center. Going around the loop are small %^CYAN%^moon stones%^WHITE%^, switching back and worth between white and a %^CYAN%^light cyan %^WHITE%^to %^BLUE%^blue %^CYAN%^moon stones%^WHITE%^. Each stone is about an inch apart and line the top of each tendrill leg. All of the short tendrills are about an inch in length with one %^CYAN%^moon stone %^WHITE%^along the tendrill and one at the end. The longer tendrill is about three inches in length as has two small %^CYAN%^blue moon stones %^WHITE%^along it with one slightly larger white %^CYAN%^moon stone %^WHITE%^at the end.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^CYAN%^A beautiful necklace for a beautiful lady.%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(0);
	set_value(10000);
	set_lore(
@AVATAR
Said to have been crafted by a god, for a god, which gods is unknown but that is the rumor behind its creation. It is thought that what ever god created this actually went to the moon to get the stones for this necklace. Why the god did this is also yet to have been discovered, perhaps as a present or peace offering? This magnificant necklace is rumored to be more than just a pretty object to be worn aswell, holding some great power within it said to enhance the beauty of its wearer beyond anything a mere mortal could comprehend.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^After "+ETOQCN+" puts on the %^RESET%^%^CYAN%^necklace %^BOLD%^%^WHITE%^you feel rather unworthy around them.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You clasp the %^RESET%^%^CYAN%^necklace %^BOLD%^%^WHITE%^around your neck and feel %^CYAN%^pretty!%^RESET%^");
	ETO->add_stat_bonus("charisma",2);
	ETO->add_attack_bonus(1);
	//ETO->add_damage_bonus(1);
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^You no longer feel so in awe of "+ETOQCN+" after the %^RESET%^%^CYAN%^necklace %^BOLD%^%^CYAN%^is removed.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^As you unclasp the %^RESET%^%^CYAN%^necklace %^BOLD%^%^CYAN%^you dont feel as pretty.%^RESET%^");
	ETO->add_stat_bonus("charisma",-2);
	ETO->add_attack_bonus(-1);
	//ETO->add_damage_bonus(-1);
	ETO->set_property("magic resistance",-5);
	return 1;
}
