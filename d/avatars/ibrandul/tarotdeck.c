#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("tarot deck");
	set_id(({ "tarot", "cards", "tarot deck", "deck", "tarot cards" }));
	set_short("%^CYAN%^t%^MAGENTA%^a%^CYAN%^r%^BOLD%^o%^RESET%^%^CYAN%^t %^MAGENTA%^d%^RESET%^%^CYAN%^ec%^MAGENTA%^%^BOLD%^k%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^deck of %^CYAN%^str%^MAGENTA%^a%^RESET%^%^CYAN%^ng%^BOLD%^e%^RESET%^%^CYAN%^ly m%^MAGENTA%^a%^RESET%^%^CYAN%^rk%^MAGENTA%^%^BOLD%^e%^RESET%^%^CYAN%^d%^RESET%^%^ORANGE%^ cards%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^These cards, larger then normal playing cards, feel %^BOLD%^heavy%^RESET%^%^CYAN%^ in your hands. The back of all the cards is a design of %^RESET%^%^BOLD%^pair of female eyes surrounded by a circle of seven silver stars%^RESET%^%^CYAN%^, and the fronts, are handpainted with all manner of %^MAGENTA%^designs%^RESET%^%^CYAN%^ and %^ORANGE%^murals%^RESET%^%^CYAN%^. A great amount of care has been placed into the creation of each card, and you feel that each one has some meaning or revelance, but one would have to be trained well in order to discern anything about the cards.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(100);
}