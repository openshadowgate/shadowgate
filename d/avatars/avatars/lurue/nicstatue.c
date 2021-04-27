#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("clay statue");
	set_id(({ "statue", "clay statue" }));
	set_short("%^BOLD%^%^BLACK%^a small %^RESET%^%^ORANGE%^clay%^BOLD%^%^BLACK%^ statue%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a small %^RESET%^%^ORANGE%^clay %^BOLD%^%^BLACK%^statue%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^At first look this statue seems very strange.  Apparently made of clay, it seems very much to be a figure of a human with odd quill like spikes extending from its head.  Most of its skin is likewise normal looking, except for a few spots of patchy gray-green scales that look very strange and somewhat unsettling.  The figure has a few marks cut into its flesh, but they seem very faded and impossible to read or make out.  A look of pain fills the statue's features making it further unsettling and causing you to wonder why someone made it. %^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}