#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^YELLOW%^A g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n lotus %^RESET%^%^ORANGE%^b%^YELLOW%^losso%^RESET%^%^ORANGE%^m%^RESET%^");
	set_id(({ "lotus", "blossom", "flower", "lotus blossom", "lotus flower" }));
	set_short("%^YELLOW%^A g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n lotus %^RESET%^%^ORANGE%^b%^YELLOW%^losso%^RESET%^%^ORANGE%^m%^RESET%^");
	set_obvious_short("%^YELLOW%^A g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n lotus %^RESET%^%^ORANGE%^b%^YELLOW%^losso%^RESET%^%^ORANGE%^m%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^The stunning g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n petals of this exquisite flower seem to glow from a light all their own. Each large petal is lightly trimmed with %^RESET%^%^RED%^red%^YELLOW%^. The center of the flower is %^WHITE%^p%^RESET%^u%^BOLD%^re white%^YELLOW%^. A wonderfully %^RESET%^%^MAGENTA%^so%^BOLD%^o%^RESET%^%^MAGENTA%^thi%^BOLD%^n%^RESET%^%^MAGENTA%^g%^YELLOW%^ fragrance rises from the flower. %^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(10);
	set_lore(
@AVATAR
This rare flower is rumored to aid in healing and ward off disease. It is highly sought after by healers and sorcerers alike for its interesting properties.

AVATAR
	);
	set_property("lore difficulty",5);
}