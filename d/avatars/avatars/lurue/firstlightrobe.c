#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("golden robe");
	set_id(({ "robe", "golden robe", "robe of the first light", "dawn robe", "sun robe" }));
	set_short("%^YELLOW%^R%^MAGENTA%^o%^RESET%^%^MAGENTA%^b%^YELLOW%^e o%^RESET%^f %^BOLD%^%^MAGENTA%^t%^RESET%^%^MAGENTA%^h%^YELLOW%^e F%^MAGENTA%^i%^RESET%^r%^MAGENTA%^s%^YELLOW%^t L%^MAGENTA%^i%^RESET%^g%^MAGENTA%^h%^YELLOW%^t%^RESET%^");
	set_obvious_short("%^YELLOW%^elegant g%^BLACK%^o%^WHITE%^l%^RESET%^%^ORANGE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^n %^YELLOW%^robe%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^The softest velvet has been used to create this stylish robe.  A pale %^RESET%^%^ORANGE%^golden %^YELLOW%^color at the top that gives way to a richer %^BLUE%^deep blue %^YELLOW%^at the base, the fabric falls in a long swath of material to nearly brush the top of the wearer's feet.  The long sleeves are bell shaped, opening to wide cuffs rimmed in pale %^RESET%^%^MAGENTA%^lavender %^YELLOW%^and %^MAGENTA%^pink %^YELLOW%^threads.  This delicate stitch work can be found at the collar as well dripping in pale swirls down along the front to add a lace like applique studded with tiny %^RESET%^%^ORANGE%^topaz %^YELLOW%^beads.  At the back, the collar lengthens and is turned up through a stiffening process to create a sunrise like effect behind the wearer's head, complete with a ribbon of %^MAGENTA%^rose quartz %^YELLOW%^and %^RED%^ruby %^YELLOW%^beads along the rim.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(3000);
	set_lore(
@AVATAR
It is common to find within the Temple of the Morninglord, those dedicated to fine craftsmanship.  And few rival the tailors and seamstresses who create ceremonial robes for the priests.  Working with only the richest of fabrics and finest of threads, they create masterpieces of beauty that exemplify the glory of Lathander.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
}



