#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Trophy");
	set_id(({ "trophy", "prize" }));
	set_short("%^YELLOW%^Gold%^BLUE%^e%^YELLOW%^n Mug T%^RED%^r%^YELLOW%^ophy%^RESET%^");
	set_obvious_short("%^YELLOW%^Gold%^BLUE%^e%^YELLOW%^n Mug T%^RED%^r%^YELLOW%^ophy%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^Gilded in gold and set with gems, this drinking horn is fit for a king. The dark, rich, %^YELLOW%^amber hue %^RESET%^%^ORANGE%^of the horn blends beautifully with the wide golden bands that wrap rim and tip. Rings of %^RED%^fever iron %^ORANGE%^extend from each of these bands and are affixed with a leather strap that allows the horn to be carried over the shoulder as needed. Tied with colorful ribbons of %^YELLOW%^topaz%^RESET%^%^ORANGE%^, %^BOLD%^%^BLUE%^sapphire%^RESET%^%^ORANGE%^ and %^RED%^ruby%^RESET%^%^ORANGE%^, gems of the same name are inset into a third golden band that circles the middle of the horn. Upon the jeweled band, words have been set in a %^CYAN%^runic fashion %^ORANGE%^that wraps all the way around the top and bottom of the band. Inside, the horn has been hollowed all the way down to where the tip begins to curve away, making a cup that can hold liquids. A thin layer of clear lacquer has been applied to the interior making it smooth, safe for drinking from and bringing out the pale %^BOLD%^%^WHITE%^moonstone %^RESET%^%^ORANGE%^quality of inner horn.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^CYAN%^Champion, Drinking!%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(3000);
}
