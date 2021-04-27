#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("finest brandy");
	set_id(({ "bottle", "brandy" }));
	set_short("%^RESET%^%^CYAN%^Cove's finest %^RED%^br%^MAGENTA%^a%^RED%^ndy%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^Cove's finest %^RED%^br%^MAGENTA%^a%^RED%^ndy%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This is a well crafted bottle with a long neck and a tight fitting %^ORANGE%^cork %^CYAN%^stopper.  The blown glass is semi-opaque and %^ORANGE%^brown%^CYAN%^ in shade, providing protection from light for any liquid contained therein.  Although the stopper is secure, you detect the sticky sweet aroma of %^RED%^brandy%^CYAN%^, or concentrated wine, near its top.  A hand-written label has been applied to the bottle's outer surface, written in Common.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
Finest Brandy o' the Cove!

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(2100);
	set_lore(
@AVATAR
Brandy and its derivatives first arrived in the Realm via the Pirate's Cove where the art of its manufacture was perfected.  Originally brewed as a means to concentrate and later dilute full-flavored wine, brandy is liquor made by distilling grape wine and fruits.  The pirates of the Cove have secured a steady underground trade of their brandy, which is flavored with fermented wild cherries.

AVATAR
	);
	set_property("lore difficulty",5);
}
