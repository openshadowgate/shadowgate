#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^CYAN%^vial of s%^RESET%^%^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^irli%^RESET%^%^BOLD%^%^BLUE%^n%^RESET%^%^CYAN%^g w%^RESET%^%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^ter%^RESET%^%^WHITE%^");
	set_id(({ "vial", "water", "vial of water" }));
	set_short("%^RESET%^%^CYAN%^vial of s%^RESET%^%^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^irli%^RESET%^%^BOLD%^%^BLUE%^n%^RESET%^%^CYAN%^g w%^RESET%^%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^ter%^RESET%^%^WHITE%^");
	set_obvious_short("%^RESET%^%^CYAN%^vial of s%^RESET%^%^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^irli%^RESET%^%^BOLD%^%^BLUE%^n%^RESET%^%^CYAN%^g w%^RESET%^%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^ter%^RESET%^%^WHITE%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^this small %^RESET%^%^WHITE%^glass vial %^RESET%^%^CYAN%^contains a neasure of water that seems to swir%^RESET%^%^BLUE%^l%^RESET%^%^CYAN%^ and d%^RESET%^%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^n%^RESET%^%^BOLD%^%^BLUE%^c%^RESET%^%^CYAN%^e in the confines of its container. The stopper is a %^RESET%^%^BOLD%^%^WHITE%^silver statue %^RESET%^%^CYAN%^of a dragon in mid flight%^RESET%^%^WHITE%^

AVATAR
	);
	set("read",
@AVATAR
Velkala, Ishar, Beckonim, the light of Kerof lights, the path of Berof guides, the way of all is set upon the altar

AVATAR
	);
     set("langage","ogre-magi");	set_weight(1);
	set_value(1000);
}