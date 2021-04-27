#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("kantlara");
	set_id(({ "vest", "kantlara" }));
	set_short("%^BOLD%^%^BLACK%^a %^YELLOW%^sigil %^BLACK%^and %^YELLOW%^rune %^BLACK%^covered kantlara%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a %^YELLOW%^sigil %^BLACK%^and %^YELLOW%^rune %^BLACK%^covered kantlara%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This extra long vest is made out of soft, black velvet embroidered with %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n th%^RESET%^%^ORANGE%^r%^YELLOW%^e%^RESET%^%^ORANGE%^a%^YELLOW%^d%^BLACK%^.  While designed to be worn open in the front, the kantlara has a pair of %^RESET%^%^ORANGE%^w%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^ln%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^t-w%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^od %^BLACK%^%^BOLD%^buttons that allow one to close it across the waist.  %^YELLOW%^G%^RESET%^%^ORANGE%^o%^YELLOW%^ld %^BLACK%^braided rope trims the hem, front panels and collar, accenting the %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n %^BLACK%^sigils, runes and symbols that cover the majority of the black surface.  Each insignia is different and judging by the different shades of gold thread they have been added over time.%^RESET%^  

AVATAR
	);
	set_weight(5);
	set_value(2000);
	set_lore(
@AVATAR
Kantlaras are personal creations made over time by the followers of Oghma.  Though many can look similar to those outside the faith, every one is unique and created by the one who wears it.  Some claim that the sigils and mystical symbols are brought to them by the Binder himself through dreams and meditation.  Others say that the images are just things they have learned along the way that were important or special to them in some way.  

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("ring");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
}


