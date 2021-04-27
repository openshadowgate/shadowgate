#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Rune of Knowldege");
	set_id(({ "rune", "rune of spheres", "rune of knowledge" }));
	set_short("%^BOLD%^%^BLUE%^Rune of Knowledge%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^Small Rune%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This is a circle of m%^BOLD%^%^BLACK%^i%^BLUE%^d%^BLACK%^n%^BLUE%^i%^BLACK%^g%^BLUE%^h%^BLACK%^t %^BLUE%^b%^BLACK%^l%^BLUE%^u%^BLACK%^e %^BLUE%^which shimmers slightly and looks strangely insubstantial.  It is impossible to see what it is made of, but it looks thinner than the finest gold leaf and more fragile than a butterfly's wing.  In the centre of the circle sits a prominent light grey %^BOLD%^%^WHITE%^Rune of Knowledge%^BLUE%^.  The calligraphy is delicate and quite beautiful, clearly the work of a master.  The lines of the rune come together in a form that is as aesthetically pleasing as it is symbolic.

AVATAR
	);
	set_weight(2);
	set_value(250);
	set_lore(
@AVATAR
%^RESET%^%^CYAN%^The material that the rune rests upon is a magical combination of obsidian, adamantium and silver.  It is not a metal that can be created in an ordinary forge.  It is remarkably light and hard wearing.  The Rune itself seems to have been inscribed by a master calligrapher.  This particular rune has been adopted as the emblem of the Spheres of the Arcane.

AVATAR
	);
	set_type("ring");
	set_limbs(({ "left hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^As you place the Rune over your left hand it adheres painlessly and securely to your skin%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You touch the Rune resting on your left hand and it comes away easily, with no resistance%^RESET%^");
	return 1;
}
