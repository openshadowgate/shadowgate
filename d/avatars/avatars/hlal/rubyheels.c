#include <std.h>
inherit "/d/common/obj/clothing/shoes";

void create(){
	::create();
	set_name("ruby red high heels");
	set_id(({ "heels", "high heels", "ruby heels", "ruby red heels", "ruby red high heels", "red high heels" }));
	set_short("%^RESET%^%^RED%^a pair of %^RESET%^%^RED%^cuffed %^BOLD%^%^RED%^mesh %^RESET%^%^RED%^high heels%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^a pair of %^RESET%^%^RED%^cuffed %^BOLD%^%^RED%^mesh %^RESET%^%^RED%^high heels%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This adventurous style is a must have for those looking to make a bold statement with their wardrobe. The shoes feature a %^RESET%^%^RED%^r%^BOLD%^u%^RESET%^%^RED%^by r%^BOLD%^e%^RESE"
	"T%^%^RED%^d %^BOLD%^floral %^RESET%^%^RED%^mesh %^BOLD%^%^BLACK%^that clings to the wearer's feet in a divine show of s%^WHITE%^e%^BLACK%^nsuality. The four inch heel rises into a flared %^RED%^seashe"
	"ll cuff %^BLACK%^that is trimmed with chiffon ruffles. Completing the look is a scoop vamp peep toe and lightly cushioned foot-bed with s%^WHITE%^i%^RESET%^l%^BOLD%^%^BLACK%^ver buckled straps.%^RESET"
	"%^
"	);
	set_value(5000);
	set_item_bonus("charisma",1);
	set_item_bonus("sight bonus",3);
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^RED%^As "+ETOQCN+" %^RED%^slips into "+query_short()+", %^RED%^they look like their confidence rises.%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^As you slip into "+query_short()+", %^RED%^you feel like a new %^BOLD%^woman.");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^RED%^As "+ETOQCN+" removes the heels, they almost almost seem to regret it.%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^You almost hate to remove "+query_short()+".%^RESET%^");
	return 1;
}

