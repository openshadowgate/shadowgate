#include <std.h>
inherit "/d/common/obj/armour/leather_gauntlets";

void create(){
	::create();
	set_name("elbow length leather gloves");
	set_id(({ "gauntlets", "gloves", "elbow length gloves", "leather gloves", "elbow length leather gloves" }));
	set_short("%^CYAN%^scrunched elbow length gloves%^RESET%^");
	set_obvious_short("%^CYAN%^scrunched elbow length gloves%^RESET%^");
	set_long("%^CYAN%^These lambskin gloves are %^WHITE%^bone white %^CYAN%^and meant to be worn scrunched from the elbow to fingertip. Real working buttons of %^BLUE%^sapphire %^CYAN%^attach the fingers to allow t"
	"hem to be worn fingerless as well. The is a strange diamond pattern stitched into the leather though it is hard to see unless up close. The style was as popular in the year 600 as it is today.%^RESET%"
	"^ 
"	);
	set_value(12000);
	set_item_bonus("stealth",2);
	set_size(2);
	set_property("enchantment",0);
}



