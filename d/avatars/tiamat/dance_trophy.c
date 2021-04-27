#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Trophy");
	set_id(({ "trophy", "prize" }));
	set_short("%^YELLOW%^Dancing T%^RED%^r%^YELLOW%^op%^CYAN%^h%^YELLOW%^y%^RESET%^");
	set_obvious_short("%^YELLOW%^Dancing T%^RED%^r%^YELLOW%^op%^CYAN%^h%^YELLOW%^y%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is an impressive trophy made primarily from %^YELLOW%^gold%^RESET%^%^ORANGE%^. Two figures rest atop a stand of polished %^RED%^mahogany %^ORANGE%^that slopes gently downward to form a slight dome. The figures, while featureless, are clearly %^BOLD%^%^BLACK%^male %^RESET%^%^ORANGE%^and %^MAGENTA%^female%^RESET%^%^ORANGE%^. The sweep of the woman's gown flares out around her feet, one of which is %^CYAN%^poised %^ORANGE%^extended, mid-step. Her back bows and arches away from the man, though her delicate hand rests firmly upon his shoulder. For his part, the man bows forward, his arm %^BOLD%^%^BLACK%^protectively %^RESET%^%^ORANGE%^encircling her waist, keeping her close, while the other is extended from the body and lightly holds her other hand just above their heads. Tiny pieces of %^RED%^ruby%^ORANGE%^, %^BOLD%^%^BLUE%^sapphire%^RESET%^%^ORANGE%^ and %^WHITE%^%^BOLD%^o%^MAGENTA%^p%^WHITE%^al %^RESET%^%^ORANGE%^have been set into key spots to add the luster of jewelry upon both figures, but the majority of the statue is formed of polished gold.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^CYAN%^Champion, Dancing!%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(2000);
}
