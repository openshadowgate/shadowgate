#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("kylix");
	set_id(({ "kylix", "goblet", "drinking vessel", "glass" }));
	set_short("%^RESET%^%^CYAN%^Castor's Enchanting Kylix");
	set_obvious_short("%^RESET%^%^CYAN%^A fine pottery goblet%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^This graceful and elegantly designed pottery goblet is known as a kylix.  A dramatic, sweeping bowl is accented with large handles to make pouring or drinking from the goblet a simple task. The wide but shallow bowl is supported by a single foot hold that adds to its unique appearance.  The outside of the goblet has been stained muted shades of the sea, the colors fading from %^BOLD%^aquamarine%^RESET%^%^CYAN%^ to%^BLUE%^ azure%^CYAN%^ and teal in random patches.  Thin ribbons of%^BOLD%^%^WHITE%^ white%^RESET%^%^CYAN%^ glaze have been streaked over the outside, to further add to the watery feeling.  Metallic %^BOLD%^%^WHITE%^silver%^RESET%^%^CYAN%^ glaze adds bands of contrast to the base of the goblet and the rim.  The clay interior of the goblet takes on a different scene than the outside.  Inside images of comely (and scantily clad) %^BOLD%^%^BLUE%^mermaids%^RESET%^%^CYAN%^, %^BOLD%^%^GREEN%^sea elves%^RESET%^%^CYAN%^, %^MAGENTA%^sirens%^CYAN%^ and %^BOLD%^nerieds%^RESET%^%^CYAN%^ have been painted on a sea green background, giving the drinker tantalizing views of feminine water sprits.  

AVATAR
	);
	set("read",
@AVATAR
%^CYAN%^Around the base of the cup in the silver the following words are carved
%^BOLD%^%^CYAN%^Wine-dark Sea
%^BOLD%^%^BLUE%^Ebbs and flows about me
%^BOLD%^%^CYAN%^Istishia hear my silly rhyme
%^BOLD%^%^BLUE%^And please fill this goblet with wine

AVATAR
	);
     set("langage","common");	set_weight(4);
	set_value(400);
	set_lore(
@AVATAR
Castor Argupus was a lyre player and singer devoted to Istishia.  The bard favored epic poems and bawdy tales.  Castor was a favorite passenger on many sailing vessels, as the sailors enjoyed his rowdy natures and the captains enjoy the entertainment on their boats, the fact that Castor was a famous Istishia did little to hurt his fame.  It was said that Castor had a magical drinking vessel that he carried with him.  When he chanted a little rhyme the drinking vessel was filled with a flavorful wine, which did not bear the intoxication qualities as most alcoholic beverages do.  

AVATAR
	);
}