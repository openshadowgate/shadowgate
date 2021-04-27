#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cloak");
	set_id(({ "hood", "cloak", "hooded cloak" }));
	set_short("%^BLUE%^Hooded Cloak of %^BOLD%^%^BLACK%^C%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^n%^RESET%^%^BLUE%^c%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^l%^RESET%^BLUE%^m%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^n%^BOLD%^%^BLACK%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a shadowy, hooded cloak%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is an overly long, black satin cloak designed with nothing in mind but concealing oneself from being recognized.  Style and function come together for this one of a kind attire perfect for todays assassins.  Sleek black satin flows down the wearers body all the way to the ground.  Light is completely absorbed into the fabric, probably making the wearer extremely hot inside it.  A black opal clasp hangs at the neck tying the cloak to the wearers body.  A large satin hood is attached to the back of the cloak and can be pulled over the head to further promote the mystery of the wearer.%^RESET%^

AVATAR
	);
	set_weight(8);
	set_value(1500);
	set_lore(
@AVATAR
%^BOLD%^%^RED%^This cloak was created by the assassin %^BLACK%^Monterey Gristle %^RED%^near 150 years ago out of necessity more than for it's usefullness.  %^BOLD%^%^BLACK%^Monterey %^RED%^was inept as an assassin and often found hinmself running and hiding for both the law, and those he failed to kill.  This cloak that saved him from recognition so many times was also his undoing however.  While hiding his identity wearing the cloak in the desert town of Rahami, the heat built up within the cloak became too much for him to bear and he died of a heat stroke.  The cloak has passed through many hands since and has become a thing of legend among many outlaws and thieves.  You assume you can %^WHITE%^<pulldown hood> %^RED%^to conceal your face or %^WHITE%^<pulloff hood> %^RED%^to be seen.  %^WHITE%^<close cloak> %^RED%^would pull the thing completely around you and in conjunction with the hood, hide everything about you.  But don't forget to %^WHITE%^<open cloak> %^RED%^or you might find out first hand what it felt like to be poor ol' %^BLACK%^Monterey%^RED%^.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",35);
	set_type("clothing");
	set_limbs(({ "neck", "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(2);
}



