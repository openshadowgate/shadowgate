#include <std.h>
inherit "/d/common/obj/clothing/shoes";

void create(){
	::create();
	set_name("checkerboard dress shoes");
	set_id(({ "shoes", "dress shoes", "checkerboard shoes", "checkerboard dress shoes", "filantra's folly", "filantras folly", "slippers" }));
	set_short("%^CYAN%^F%^WHITE%^i%^BOLD%^%^BLUE%^l%^BOLD%^a%^WHITE%^n%^CYAN%^t%^RESET%^r%^BOLD%^%^WHITE%^a's %^RESET%^%^CYAN%^F%^WHITE%^o%^BOLD%^lly%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a pair of silver slippers%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^These handmade slippers are high quality dress shoes that would add flair to anyone's wardrobe. Metallic strips of silver and white leather are carefully woven together to create a ch"
	"ess-board effect. The sole of the shoe has been padded for extra comfort. The slippers have a half inch heel.%^RESET%^
"	);
	set_value(12000);
	set_lore("%^CYAN%^Filantra Lockeheart was famous for her foolish ways. It is said she was even able to charm a king or two. One such king hired a shoemaker to create anything her feet could desire. Rumor says e"
	"ven the shoemaker fell deeply in love with the woman and was eventually beheaded by the jealous king.%^RESET%^
"	);
	set_property("lore difficulty",20);
	set_item_bonus("strength",-1);
	set_item_bonus("charisma",2);
	set_size(2);
	set_property("enchantment",3);
}



