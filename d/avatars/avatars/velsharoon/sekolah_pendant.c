#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("pendant");
	set_id(({ "shark", "shark tooth", "pendant", "tooth", "shark tooth pendant", "shark pendant", "tooth pendant" }));
	set_short("%^BOLD%^%^BLUE%^Sekolah %^WHITE%^pendant%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^sh%^RESET%^a%^BOLD%^rk tooth pendant%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^MAGENTA%^This pendant has been fashioned from a single %^WHITE%^sh%^RESET%^a%^BOLD%^rk's tooth%^MAGENTA%^. The tooth is %^BLUE%^serrated%^MAGENTA%^ and has a single %^GREEN%^glyph%^MAGENTA%^ engraved upon it of unknown origins. The tooth is held on by braided %^RESET%^%^GREEN%^kelp%^BOLD%^%^MAGENTA%^ that feels as strong as steel. This pendant obviously serves as some sort of holy symbol of sorts.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(10);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
}



