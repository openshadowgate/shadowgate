#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword";

void create(){
	::create();
	set_name("sword of the brave");
	set_id(({ "sword" }));
	set_short("%^BOLD%^%^BLACK%^Sword %^WHITE%^of %^BOLD%^%^BLACK%^the %^CYAN%^brave%^RESET%^");
	set_obvious_short("%^BOLD%^RED%^A %^BOLD%^%^BLACK%^massive %^GREEN%^emerald %^BOLD%^%^WHITE%^two-handed %^BOLD%^%^BLACK%^sword%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This magnificent weapon is a double-edged broadsword made of shimmering white mithril.  Archaic %^CYAN%^runes %^BOLD%^%^WHITE%^are etched in a flowing script along the length of the b"
	"lade, filled with molten %^CYAN%^platinum %^BOLD%^%^WHITE%^that echoes the finely crafted %^CYAN%^platinum crossguard.  %^BOLD%^%^WHITE%^The crossguard is made into an iron cross studded with five sma"
	"ll colorless gems set into the cross pattern.  Around the gems is an exquisitely detailed pattern of geometric runes against a %^RESET%^%^BOLD%^%^BLACK%^darkened backdrop%^RESET%^ %^BOLD%^%^WHITE%^tha"
	"t brings them even more into focus.  The hilt of the sword is wrapped in ageless white leather that never seems to stain or show any sign of wear - the very %^RED%^blood %^BOLD%^%^WHITE%^of an enemy s"
	"eems to fall away, leaving it pristine once again.  The weapon is completed by the rounded %^CYAN%^platinum pommel %^BOLD%^%^WHITE%^that houses a large, spherical colorless gem.%^RESET%^
"	);
	set_value(2000);
	set_item_bonus("healing",5);
	set_item_bonus("strength",2);
	set_item_bonus("damage bonus",5);
	set_property("enchantment",3);
}



