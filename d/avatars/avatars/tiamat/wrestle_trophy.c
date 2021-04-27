#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Trophy");
	set_id(({ "trophy", "prize" }));
	set_short("%^YELLOW%^Wrestling T%^WHITE%^r%^YELLOW%^oph%^RED%^y%^RESET%^");
	set_obvious_short("%^YELLOW%^Wrestling T%^WHITE%^r%^YELLOW%^oph%^RED%^y%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is an impressive trophy made primarily from %^YELLOW%^gold%^RESET%^%^ORANGE%^. A powerful stocky figure stands astride the top of a %^RED%^mahogany stand %^ORANGE%^with his muscular arms lifted upward, supporting another, similar figure. Both are %^BOLD%^%^BLACK%^bearded %^RESET%^%^ORANGE%^and represented as being dressed in loose clothing, rather then traditional %^WHITE%^plate armor %^ORANGE%^one might expect on dwarves. The clothing is depicted clinging to their bodies as though soaked with sweat as they wrestle. Bits of %^YELLOW%^topaz %^RESET%^%^ORANGE%^and %^BOLD%^%^WHITE%^o%^MAGENTA%^p%^WHITE%^al%^RESET%^ %^ORANGE%^in the shape of beads and clasps, decorate their damp braids which are depicted caught in mid-motion as though the first figure is %^RED%^hurling%^ORANGE%^ the second over his head. Below their feet, a engraved %^YELLOW%^plaque %^RESET%^%^ORANGE%^is set into the wood.%^RESET%^ 

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^CYAN%^Champion, Wrestling!%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(2300);
}
