#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("golden necklace");
	set_id(({ "necklace", "golden necklace" }));
	set_short("%^YELLOW%^a golden necklace%^RESET%^");
	set_obvious_short("%^YELLOW%^a golden necklace%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This necklace is made of fine golden links.  At the center of these links is a tear-drop shaped %^WHITE%^diamond %^YELLOW%^that is %^CYAN%^pale blue %^YELLOW%^in color. Clearly meant for someone of %^RESET%^%^MAGENTA%^regal%^YELLOW%^ tastes, it would fetch a sizable price if sold.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(5000);
	set_lore(
@AVATAR
Said to have been made for the Princess of Torm on her 12th birthday as a gift from her father.  It was the only thing ever found of her after the shipwreck that is reported to have taken her life less then a year later.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
}


