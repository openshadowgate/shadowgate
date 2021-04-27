#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Gem of Reasoning");
	set_id(({ "gem", "jewel", "gem of reasoning" }));
	set_short("Gem of Reasoning");
	set_obvious_short("Gem of Reasoning");
	set_long(
@AVATAR
%^CYAN%^This fabulous multi-facted gem is a bright, flawless shade of light blue.  Blue diamonds are rare but not unheard of.  The gem is not only flawless, it seems to have a preternatural glow.  It almost looks alive!

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","common");	set_weight(5);
	set_value(140);
	set_lore(
@AVATAR
This gem is rumored to have been mined from the mines near Offestry a hundred years ago. A jeweler fashioned it for an archmage who then magicked the jewel somehow.  It's true purpose is not known.

AVATAR
	);
	set_property("lore difficulty",15);
}