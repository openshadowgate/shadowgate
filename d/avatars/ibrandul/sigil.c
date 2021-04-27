#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BLACK%^%^BOLD%^black necklace%^RESET%^");
	set_id(({ "necklace", " black necklace", "black necklace" }));
	set_short("%^RESET%^%^BOLD%^%^BLACK%^bla%^RESET%^%^WHITE%^c%^RESET%^%^BOLD%^%^BLACK%^k n%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^BLACK%^ckl%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^ce%^RESET%^%^WHITE%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^bla%^RESET%^%^WHITE%^c%^RESET%^%^BOLD%^%^BLACK%^k n%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^BLACK%^ckl%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^ce%^RESET%^%^WHITE%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^made of an unknown black metal, this necklace is heavy, the chain thick and the medallion heavy. The medallion is a%^RESET%^%^WHITE%^ sickle %^RESET%^%^BOLD%^%^BLACK%^over a %^RESET%^%^WHITE%^clenched fist%^RESET%^%^BOLD%^%^BLACK%^. There are flecks of %^RESET%^%^RED%^b%^RESET%^%^BOLD%^%^RED%^lo%^RESET%^%^RED%^od %^RESET%^%^BOLD%^%^BLACK%^on it%^RESET%^%^WHITE%^

AVATAR
	);
	set_weight(3);
	set_value(10);
}