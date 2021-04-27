#include <std.h>
inherit "/d/common/obj/clothing/cloak";

void create(){
	::create();
	set_name("Cloak of Madness");
	set_id(({ "cloak", "cloak of madness", "madness cloak" }));
	set_short("%^BOLD%^%^BLACK%^Cl%^MAGENTA%^oa%^BLACK%^k of the L%^WHITE%^au%^BLACK%^gh%^WHITE%^i%^BLACK%^ng Sk%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^ll%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Bl%^RESET%^a%^BOLD%^%^BLACK%^ck b%^WHITE%^i%^BLACK%^ll%^WHITE%^o%^BLACK%^w%^WHITE%^i%^BLACK%^ng cl%^RESET%^%^MAGENTA%^oa%^BOLD%^%^BLACK%^k%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This is a b%^WHITE%^i%^BLACK%^ll%^WHITE%^o%^BLACK%^w%^WHITE%^i%^BLACK%^ng bl%^RESET%^a%^BOLD%^%^BLACK%^ck cl%^RESET%^%^MAGENTA%^oa%^BOLD%^%^BLACK%^k made of the finest %^MAGENTA%^silk"
	"%^BLACK%^. Fine %^RESET%^stitches %^BOLD%^%^BLACK%^with %^RESET%^%^MAGENTA%^purple %^BOLD%^%^BLACK%^thread binds the %^MAGENTA%^silken %^BLACK%^pieces together and the %^RESET%^%^CYAN%^hems %^BOLD%^%^"
	"BLACK%^are clad with %^RESET%^%^MAGENTA%^purple %^BOLD%^%^CYAN%^velour%^BLACK%^. The cl%^RESET%^%^MAGENTA%^oa%^BOLD%^%^BLACK%^k is large with extra materials so it will billow around the wearers shoul"
	"ders and make it seems like s%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^o%^RESET%^w%^BOLD%^%^BLACK%^s curl around the wearer. A large %^GREEN%^grinning %^WHITE%^skull %^BLACK%^have been ma"
	"de with %^WHITE%^si%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r%^RESET%^y %^BOLD%^white %^BLACK%^wires, and with such %^ORANGE%^skill %^BLACK%^the %^WHITE%^skull %^BLACK%^would seem to be %^MAGENTA%^laughin"
	"g %^BLACK%^when the cloak b%^WHITE%^i%^BLACK%^ll%^WHITE%^o%^BLACK%^ws around the wearer.%^RESET%^
"	);
	set_value(2000);
	set_lore("%^BOLD%^%^BLACK%^Legends have it that Cyric the Mad Lord, came to the realm in mortal form and ordered five cloaks made for his clergy by a master tailor living in Torm. When the cloak had been create"
	"d he imbued each with a little of his own powers and the cloaks would be given to the Chosen one of each generation. It is said the last cloak given was to Alzar, High Priest of Cyric.
"	);
	set_property("lore difficulty",14);
	set_item_bonus("magic resistance",1);
	set_item_bonus("damage resistance",1);
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" wears the "+query_short()+" and you hear a mad laughter",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You drape the "+query_short()+" around your shoulders and you hear a mad laughter");
	return 1;
}


