#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("gauntlets");
	set_id(({ "gauntlets", "plated mesh", "plated mesh gauntlets", "mesh gauntlets" }));
	set_short("%^RESET%^P%^BOLD%^%^BLUE%^l%^RESET%^a%^CYAN%^t%^BOLD%^%^BLUE%^e%^RESET%^d M%^BOLD%^%^BLUE%^e%^RESET%^%^CYAN%^s%^RESET%^h G%^BOLD%^%^BLUE%^a%^RESET%^u%^CYAN%^n%^BOLD%^%^BLUE%^t%^RESET%^le%^CYAN%^t%^RESET%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^a set of %^RESET%^b%^BOLD%^%^BLUE%^l%^RESET%^u%^CYAN%^i%^BOLD%^%^BLUE%^s%^RESET%^h s%^BOLD%^%^BLUE%^i%^RESET%^l%^CYAN%^v%^BOLD%^%^BLUE%^e%^RESET%^r %^BOLD%^%^BLUE%^gauntlets%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^Tiny diamond shaped links form a lightweight mesh of strong %^RESET%^mithril chain %^CYAN%^under the series of interlocking, %^BOLD%^%^BLUE%^titanium plates %^RESET%^%^CYAN%^that make up this pair of gauntlets.  Working together, the mesh catches and counters stabs and jabs, while the plates deflect cutting slices.  A %^RESET%^b%^BOLD%^%^BLUE%^l%^RESET%^u%^CYAN%^i%^BOLD%^%^BLUE%^s%^RESET%^h s%^BOLD%^%^BLUE%^i%^RESET%^l%^CYAN%^v%^BOLD%^%^BLUE%^e%^RESET%^r %^CYAN%^in color, the gauntlets are lined with a soft %^BOLD%^%^BLACK%^black cotton %^RESET%^%^CYAN%^padding to give a bit of added comfort and grip, while the plates are etched in %^RESET%^silver scrollwork %^CYAN%^and riveted with %^BOLD%^%^BLUE%^sapphire studs%^RESET%^%^CYAN%^.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(3000);
	set_lore(
@AVATAR
Anstrong Berkus is credited with creating these mesh and plate gauntlets. Anstrong served in the dwarven army of Barak Morndin during the mindflayer wars.  Many of his fellow warriors complained that the large, heavy gauntlets they wore were cumbersome and heavy, especially in light of how their enemy favored the stab-and-jab methods of fighting with small, lightweight weapons.  In response to this, Anstrong spent many of his off hours perfecting a gauntlet that combined the protectiveness of the thick plated gauntlets the dwarves were used to, with a finer layer of chain mesh, similar to the breastplate and mesh combinations that many wore to protect their bodies.  The gauntlets proved to be a popular success resulting in Anstrong's promotion off the front lines and into the smithies to create more of his plated mesh gauntlets.

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("chain");
	set_limbs(({ "right hand", "left hand" }));
	set_size(1);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The soft cotton lining makes these gauntlets quite comfortable actually.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slide the gauntlets off and stretch your fingers a bit.%^RESET%^");
	return 1;
}

