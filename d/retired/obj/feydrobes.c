#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Robes of the Shifting Sands");
	set_id(({ "robe", "robes", "sand robes", "sandy brown robes", "Robes of the Shifting Sand", "robes of the shifting sand" }));
	set_short("%^RESET%^%^ORANGE%^Robes of the %^YELLOW%^S%^RESET%^%^ORANGE%^h%^YELLOW%^i%^RESET%^%^ORANGE%^f%^YELLOW%^t%^RESET%^%^ORANGE%^i%^YELLOW%^n%^RESET%^%^ORANGE%^g %^YELLOW%^Sands%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^Sandy Brown Robes%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This simple robe is made of several layers of high quality linen.  The fabric if free-flowing and allows for complete freedom of movement, a quality usually prized among the desert-dwelling peoples.  The robe falls to just below the wearer's waist and may be gathered with a simple cloth belt.  The sleeves may be left loose, or bound with cloth at the wrists.

AVATAR
	);
	set_weight(6);
	set_value(675);
	set_lore(
@AVATAR
Robes such as this are often worn among the nomadic tribes found in the desert.  This particular robe has clearly been highly enchanted, although no reason for it seems apparent.  The sandy color of these robes and the flowing movement would allow the wearer to conceal himself easily in the desert, while the lightweight fabric would allow one to keep cool.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_item_bonus("attack bonus",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^You feel a faint breeze as "+ETOQCN+" slips into the robe.",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^A swift desert wind brings the scent of %^CYAN%^ozone %^ORANGE%^as you slip into the robe.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" slips out of the flowing robe.",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^The desert scent fades from your mind as you remove the robe.");
	return 1;
}
