#include <std.h>
inherit "/d/common/obj/jewelry/bracelet";

void create(){
	::create();
	set_name("moonstone bracelet");
	set_id(({ "moonstone bracelet", "moonstone", "bracelet" }));
	set_short("%^BOLD%^%^WHITE%^m%^MAGENTA%^o%^WHITE%^o%^RESET%^n%^BOLD%^stone ch%^CYAN%^a%^WHITE%^r%^RESET%^m %^BOLD%^b%^RESET%^r%^BOLD%^acel%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^m%^MAGENTA%^o%^WHITE%^o%^RESET%^n%^BOLD%^stone ch%^CYAN%^a%^WHITE%^r%^RESET%^m %^BOLD%^b%^RESET%^r%^BOLD%^acel%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^t%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^Rounded beads of moonstone s%^CYAN%^h%^WHITE%^immer with their milky background against the tiny %^RESET%^silver moon %^BOLD%^charms that dangle from this bracelet. The piece of jewel"
	"ry has been carefully designed to adjust from a small child size to an average adult size. A %^RESET%^%^CYAN%^soothing energy %^BOLD%^%^WHITE%^is given off from the visual essence of the bracelet.%^RE"
	"SET%^ 
"	);
	set_value(4000);
	set_lore("%^CYAN%^Bracelets like these are popular among old and young alike. It is said that moonstones bring calm and balance into one's life. Whether or not that is true, many are fond of the shimmering ston"
	"e, especially those who seek the moon's guidance. %^RESET%^
"	);
	set_property("lore difficulty",5);
	set_item_bonus("magic resistance",1);
	set_size(2);
	set_property("enchantment",1);
}



