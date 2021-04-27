#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("dark mask");
	set_id(({ "mask", " dark mask", " adamantium mask", " dark adamantium mask", " adamantium dark mask", " adamantite mask" }));
	set_short("%^BLACK%^%^BOLD%^Dark %^BLUE%^Mask%^RESET%^");
	set_obvious_short("Dark mask");
	set_long(
@AVATAR
%^BLACK%^%^BOLD%^This mask is forged from a thin sheet of adamantium, covering all details of the face in entirety.  A thin %^RESET%^%^ORANGE%^leather %^BLACK%^%^BOLD%^strap allows the mask to fit snugly to the wearer.  The mask itself is covered in a disturbing mass of s%^CYAN%^wi%^BLACK%^r%^GREEN%^l%^BLACK%^s that move and distort the reflection of the onlooker making them feel as though they are staring into a dark reflection of their inner %^MAGENTA%^s%^RESET%^%^BOLD%^o%^MAGENTA%^ul%^BLACK%^.

AVATAR
	);
	set_weight(1);
	set_value(300);
	set_property("lore difficulty",0);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
}


