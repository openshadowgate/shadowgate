#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create(){
	::create();
	set_name("sheriffbadgetonovi2");
	set_id(({ "badge" }));
	set_short("%^BOLD%^%^RED%^S%^RESET%^%^RED%^h%^BOLD%^eriffs%^YELLOW%^ Badge%^RESET%^%^RED%^ o%^BOLD%^f %^BOLD%^%^BLACK%^Tonovi%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^S%^RESET%^%^RED%^h%^BOLD%^eriffs%^YELLOW%^ Badge%^RESET%^%^RED%^ o%^BOLD%^f %^BOLD%^%^BLACK%^Tonovi%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This badge is made of %^YELLOW%^gold%^RESET%^%^CYAN%^, and shaped into the symbol of %^YELLOW%^Tonovi%^RESET%^%^CYAN%^. The image is of image of a %^RESET%^%^MAGENTA%^r%^BOLD%^a%^RESE"
	"T%^%^MAGENTA%^ven%^CYAN%^ perched atop a %^BOLD%^%^WHITE%^closed %^BLACK%^iron%^WHITE%^ gate%^RESET%^%^CYAN%^. Small %^RESET%^%^MAGENTA%^gemstones%^CYAN%^ complete this puzzle adding colors in the rig"
	"ht places.%^RESET%^
"	);
	set_value(50000);
	set_lore("%^YELLOW%^This %^MAGENTA%^badge%^YELLOW%^ is the symbol of power of the %^BOLD%^%^RED%^S%^RESET%^%^RED%^h%^BOLD%^eriff%^YELLOW%^ of %^BLACK%^Tonovi%^YELLOW%^. It grants the power of the %^RESET%^%^MAG"
	"ENTA%^D%^BOLD%^u%^RESET%^%^MAGENTA%^chess%^YELLOW%^ to make any arrest in the name of the law in the city.%^RESET%^
"	);
	set_property("lore difficulty",10);
	set_size(2);
	set_property("enchantment",0);
}



