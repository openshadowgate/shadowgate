#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("bottle of vinegar");
	set_id(({ "bottle", "vinegar" }));
	set_short("%^RESET%^%^CYAN%^Bottle of %^ORANGE%^Tharis Vinegar%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^Bottle of %^ORANGE%^Tharis Vinegar%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This is a well crafted bottle with a long neck and a tight fitting %^ORANGE%^cork %^CYAN%^stopper.  The blown glass is semi-opaque and %^ORANGE%^brown%^CYAN%^ in shade, providing protection from light for any liquid contained therein.  Although the cork is tightly sealed, you can still smell a lingering scent of %^MAGENTA%^vinegar%^CYAN%^ around the stopper.  A %^YELLOW%^col%^MAGENTA%^orf%^YELLOW%^ul%^RESET%^%^CYAN%^ %^RESET%^label%^CYAN%^ is applied to bottle, with something written in Common.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
Tharis 50-Year Balsamic Vinegar.  Bottled under the Authority of the Duke.

AVATAR
	);
     set("langage","common");	set_weight(3);
	set_value(1900);
	set_lore(
@AVATAR
Vinegar from Tharis is highly prized not only for its culinary uses, but is also valuable in medicine and cleaning due to its highly acidic nature.  Only the finest wines are age aged and allowed to sour to make this pricey liquid.  The vinegar is then aged in barrels until it takes on a rich amber hue.

AVATAR
	);
	set_property("lore difficulty",5);
}
