#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("silk armguards");
	set_id(({ "armguards", "guards", "arm guards", "bracers" }));
	set_short("%^BOLD%^%^BLACK%^K%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^sen%^RESET%^%^ORANGE%^j%^BOLD%^%^BLACK%^ou%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^'s %^RESET%^%^ORANGE%^S%^BOLD%^%^BLACK%^tr%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ps %^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^f P%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^ote%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^ti%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a set of %^RESET%^%^ORANGE%^w%^MAGENTA%^o%^ORANGE%^v%^MAGENTA%^e%^ORANGE%^n %^BOLD%^%^BLACK%^armguards");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Woven from two thick strands of alternating %^RESET%^%^ORANGE%^gold %^BOLD%^%^BLACK%^and %^RESET%^%^MAGENTA%^purple %^BOLD%^%^BLACK%^silk, this intricate set of armguards extends from the middle of the biceps down to the wrist.  At each end a %^RESET%^%^ORANGE%^b%^MAGENTA%^r%^ORANGE%^a%^MAGENTA%^i%^ORANGE%^d%^MAGENTA%^e%^ORANGE%^d %^BOLD%^%^BLACK%^band of the same material creates a wide foundation to keep the otherwise loose and flexible weave fixed in place.  Buttons of polished %^RESET%^%^MAGENTA%^amethyst %^BOLD%^%^BLACK%^allow these two bands to be secured, blending well with the leather's bejeweled tones.  Surprisingly protective, the woven straps are strong enough to turn and keep blows from landing, but the light fabric allows the arms to move and bend with their natural inclination.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(4000);
	set_lore(
@AVATAR
Kesenjour Armardstron was a prominent weaver of silk for most of his life.  Hailing from the island of Graez, he was known for creating exceptionally beautiful garments that were both strong and flexible.  Belonging to the Oriaum clan, he journeyed to Attaya with Kalimex and his warriors, remaining back at the dock to repair and tend to the items that the warriors needed.  When Kalimex failed to return after several months, Kesenjour sailed back to Graez with the bad news, that their great warrior had fallen.  A year later, Kesenjour returned and led a smaller party clad in darkly died silks into the tower.  Only to return a week later to say that Kalimex was indeed lost to them, but would never fully leave this world until it was free of the darkness that swept the Attaya island. 

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("bracer");
	set_limbs(({ "right arm", "left arm" }));
	set_size(2);
	set_property("enchantment",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You can barely feel the silk straps as you slip them over your arms and button them closed.  You wonder if they really are as protective as they are rumored to be.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You unbutton the two arm guards and roll them down your arms and off.  Amazed they worked as well as they did.%^RESET%^");
	return 1;
}

