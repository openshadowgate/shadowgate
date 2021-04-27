#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("drow skin hat");
	set_id(({ "hat", "drow skin hat", "mage hat", "drow skin mage hat", "drow hat" }));
	set_short("%^BOLD%^%^BLUE%^A %^BLACK%^drow skin %^BLUE%^mage's hat%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A %^BLACK%^drow skin %^BLUE%^mage's hat%^RESET%^");
	set_long(
@AVATAR
This hat is obviously made to the taste of a human mage, and perhaps a sadistic one at that.  It has a tall conical crown and a wide, flat brim that looks as if it would keep %^YELLOW%^sun %^RESET%^and %^BOLD%^%^BLUE%^rain %^RESET%^out of the wearer's eyes.  A soft snakeskin band runs along the base of the crown of the hat and has a traditional %^BOLD%^%^YELLOW%^brazen buckle %^RESET%^along the front.  The skin of some unfortunate %^BOLD%^%^BLACK%^drow %^RESET%^has been used to fashion the outside of the hat and has been stitched together with fanciful, metallic %^BOLD%^%^YELLOW%^gold thread%^RESET%^.  Despite the odd material, the skin has been %^RESET%^%^ORANGE%^well-tanned %^RESET%^and looks as if it would keep the weather out and warmth in.  The inside of the hat has been lined with soft, %^BOLD%^%^WHITE%^white silk %^RESET%^along with a %^RESET%^%^ORANGE%^leather sweatband%^RESET%^.  Inside the hat is a small tag with a name stitched on it.

AVATAR
	);
	set("read",
@AVATAR
Stefano Esposair

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(1000);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
}


