#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("clay jar");
	set_id(({ "jar", "clay jar", "healing paste", "paste" }));
	set_short("%^BOLD%^%^WHITE%^a %^RESET%^%^CYAN%^c%^YELLOW%^o%^RESET%^%^ORANGE%^lo%^CYAN%^rf%^BOLD%^%^BLUE%^ul%^RESET%^%^CYAN%^ly %^ORANGE%^gl%^YELLOW%^az%^RESET%^%^CYAN%^ed %^WHITE%^%^BOLD%^clay jar%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a %^RESET%^%^CYAN%^c%^YELLOW%^o%^RESET%^%^ORANGE%^lo%^CYAN%^rf%^BOLD%^%^BLUE%^ul%^RESET%^%^CYAN%^ly %^ORANGE%^gl%^YELLOW%^az%^RESET%^%^CYAN%^ed %^WHITE%^%^BOLD%^clay jar%^RESET%^");
	set_long(
@AVATAR

%^BOLD%^%^WHITE%^This %^RESET%^%^CYAN%^c%^YELLOW%^o%^RESET%^%^ORANGE%^lo%^CYAN%^rf%^BOLD%^%^BLUE%^ul%^RESET%^%^CYAN%^ly %^ORANGE%^gl%^YELLOW%^az%^RESET%^%^CYAN%^ed %^BOLD%^%^WHITE%^jar is made of clay and features a tightly sealing lid that keeps the contents safe.  Fitting easily within the palm of one's hand, there is a faint smell of rose and spice that lingers about it.  Inside, a %^RESET%^chalky white paste%^BOLD%^%^WHITE%^ can be found.  Smooth to the touch, the paste could be worked onto the skin as a type of soothing balm.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR

Apply to wounded skin and work in completely.  Wrap in fresh bandages and do not expose to air.  For extreme damage, apply daily for up to three weeks.


AVATAR
	);
     set("langage","common");	set_weight(3);
	set_value(300);
	set_lore(
@AVATAR

Created by a priest of Torm named Metrin for the mage James, this mixture combines the purity of the unicorn, the beauty of the rose and the protections of rare herbs.  It is said that James petitioned The Lady of Beauty herself to obtain the rose and faced the dangers of an overrun forest for the Unicorn in order to obtain two of the components for this mixture.  All after suffering great injury at the hands of the despicable psion named Anson.

AVATAR
	);
	set_property("lore difficulty",10);
}
