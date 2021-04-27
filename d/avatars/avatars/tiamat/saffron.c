#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Jar of saffron");
	set_id(({ "jar", "saffron" }));
	set_short("%^BOLD%^%^WHITE%^Jar %^RESET%^of %^ORANGE%^sa%^YELLOW%^ff%^RESET%^%^ORANGE%^ron%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Jar %^RESET%^of %^ORANGE%^sa%^YELLOW%^ff%^RESET%^%^ORANGE%^ron%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This is a small clay jar, lightly glazed with a dye derived from woad.  The lid of the jar is affixed via a small %^ORANGE%^leather loop%^CYAN%^.  Inside is a sheaf of %^YELLOW%^papyrus paper%^RESET%^%^CYAN%^, wrapped around a bundle of dried thread-like plant products.  The %^ORANGE%^threads%^CYAN%^ have a bold %^YELLOW%^yellowish%^RESET%^%^ %^RED%^red%^CYAN%^ hue and a pungent, bitter smell.  A label applied to the jar seems to have worn away from travel.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(2300);
	set_lore(
@AVATAR
Saffron is a spice derived from the flower saffron crocus, which grows only in the most distant reaches of the Tsarven Empire.  Each flower grows only three stamen, which are harvested by hand and dried to form the pungent spice which may be used for its aromatic properties and bold amber color it bestows on food products.  Saffron has, at times, been worth more than its weight in gold.

AVATAR
	);
	set_property("lore difficulty",5);
}
