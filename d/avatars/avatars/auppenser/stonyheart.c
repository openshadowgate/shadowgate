#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Stony Heart");
	set_id(({ "necklace", "artifact", "Stony Heart" }));
	set_short("%^BOLD%^%^RED%^Stony Heart%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^Heart-shaped Garnet Necklace%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^This necklace is very pretty and alluring to behold.  It is a large %^RED%^garnet%^RESET%^%^BOLD%^ cut into the shape of a %^RED%^heart%^RESET%^%^BOLD%^.  The gem is flawless and is the color of fresh %^RESET%^%^RED%^blood%^RESET%^%^BOLD%^. It is set in an %^RESET%^ivory setting%^BOLD%^ and hangs on a %^RESET%^chain%^BOLD%^ also made from %^RESET%^ivory%^BOLD%^.  The chain is held by a %^YELLOW%^gold lobster-claw%^RESET%^%^BOLD%^ style clasp, the type of clasp which is known to be the most secure for necklaces and bracelets.  The necklace is unusal due to the %^RESET%^ivory setting %^BOLD%^and%^RESET%^ chain%^BOLD%^ but its overall appearence is quite lovely.

AVATAR
	);
	set_weight(3);
	set_value(15000);
	set_lore(
@AVATAR
%^BOLD%^This appears to be the artifact called The Stony Heart.  It was rumored to have been created by Loviatar's Arch-mage, Hollister. It's express purpose is to be worn by a beautiful woman chosen by Loviatar, binding her to Loviatar's will.  The necklace removes all free will from the wearer.  It is also rumored that this necklace is but one component used in a ritual making the woman so alluring that not man can resist her charms, thereby bending them to Loviatar's will.  This artifact went missing just recently from Loviatar's Temple's archives.  Its whereabouts are unknown.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",25);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" grimaces in %^RED%^pain%^RESET%^ as the necklace is put on.",ETO);
	tell_object(ETO,"You feel the sweet %^RED%^pain%^RESET%^ as you wear your necklace.");
	ETO->add_stat_bonus("charisma",5);
	ETO->add_stat_bonus("wisdom",-5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" looks relieved as the necklace is taken off.",ETO);
	tell_object(ETO,"You feel the %^RED%^pain%^RESET%^ leave you as you remove the necklace.");
	ETO->add_stat_bonus("charisma",-5);
	ETO->add_stat_bonus("wisdom",5);
	return 1;
}
