#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BOLD%^%^CYAN%^G%^BLUE%^n%^CYAN%^omi%^BLUE%^s%^CYAN%^h C%^BLUE%^a%^CYAN%^n%^BLUE%^d%^CYAN%^y K%^BLUE%^e%^CYAN%^tt%^BLUE%^l%^CYAN%^e");
	set_id(({ "kettle", "candy kettle" }));
	set_short("%^BOLD%^%^CYAN%^G%^BLUE%^n%^CYAN%^omi%^BLUE%^s%^CYAN%^h C%^BLUE%^a%^CYAN%^n%^BLUE%^d%^CYAN%^y K%^BLUE%^e%^CYAN%^tt%^BLUE%^l%^CYAN%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^B%^BLUE%^l%^CYAN%^u%^BLUE%^e%^CYAN%^-%^BLUE%^S%^CYAN%^t%^BLUE%^e%^CYAN%^e%^BLUE%^l %^RESET%^%^ORANGE%^kettle%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^The kettle is a %^RESET%^%^ORANGE%^round-bottomed pot%^BOLD%^%^CYAN%^ with an open top and a firm metal handle. It is made out of some %^RESET%^%^CYAN%^b%^BOLD%^%^BLUE%^l%^CYAN%^u%^WHITE%^e %^RESET%^%^CYAN%^S%^BOLD%^%^BLUE%^t%^CYAN%^e%^WHITE%^e%^RESET%^%^BLUE%^l%^BOLD%^%^CYAN%^ of unknown origin. The pot has the twin marks of the %^WHITE%^theatre%^CYAN%^ upon it -- a %^BOLD%^%^MAGENTA%^l%^GREEN%^a%^MAGENTA%^ug%^GREEN%^h%^MAGENTA%^ing%^WHITE%^ mask%^CYAN%^ on one side and a %^BLUE%^c%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLUE%^yi%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLUE%^g%^WHITE%^ mask%^CYAN%^ on the other.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(10000);
	set_lore(
@AVATAR
The Candy Kettle has  %^RESET%^%^CYAN%^m%^MAGENTA%^y%^CYAN%^ster%^MAGENTA%^i%^CYAN%^ous%^RESET%^ origins. A %^BLUE%^gnomish inventor%^RESET%^ once tried to %^CYAN%^distill %^RESET%^liquid happiness%^RESET%^ in a drinkable form in this pot. But try as he might, no matter how %^BOLD%^%^GREEN%^powerful%^RESET%^ his intelligence and magic, he was unable to separate %^YELLOW%^liquid happiness%^RESET%^ from %^MAGENTA%^liquid sadness%^RESET%^. After a trip to the theatre of Azha, he decided that in fact they were one and the same liquid. This pot is all that remains of his research. It is said that the candy made from this pot are both %^BOLD%^%^GREEN%^joy%^RESET%^ and %^RESET%^%^CYAN%^sorrow%^RESET%^ in the same bite -- and the effects of which are completely unpredictable.

AVATAR
	);
	set_property("lore difficulty",15);
}
