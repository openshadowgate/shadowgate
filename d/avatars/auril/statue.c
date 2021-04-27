#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("statue");
	set_id(({ "statue", "oak statue" }));
	set_short("%^RESET%^%^ORANGE%^An oak crafted statue of five elves.%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^An oak crafted statue of five elves.%^RESET%^");
	set_long(
@AVATAR
A female elf with long hair and dressed in a flowing gown stands predominately in the center of this beautifully carved %^RESET%^%^ORANGE%^oak %^RESET%^statue. Her hand outstretched defiantly showing the symbol of %^BOLD%^%^YELLOW%^Torm %^RESET%^to her unseen enemy. To her left is a male elf in %^BOLD%^%^BLACK%^leather armor %^RESET%^weilding scimitars, standing poised and ready for action. A symbol of %^BOLD%^%^CYAN%^Istishia %^RESET%^is worn loosely around his neck, and a wolf sits obediantly at his feet. Behind and slightly to the right of the central figure is a female elf with long hair wearing %^BOLD%^%^GREEN%^platemail%^RESET%^, her hands are clasping a symbol of %^BOLD%^%^YELLOW%^Selune %^RESET%^and she stands firmly in prayer. Immediately right of the center figure a male elf covered in %^BOLD%^%^BLUE%^ta%^BOLD%^%^CYAN%^tt%^BOLD%^%^BLUE%^oos %^RESET%^is slightly crouched and peering into the distance, holding a bow in his hands that has an arrow notched and ready to fire. Kneeling in front protectively is a male elf with long hair, wearing what appears to be plate mail, holding a symbol of %^BOLD%^%^YELLOW%^Torm %^RESET%^in one hand and a mace in the other, the head of which rests on the ground.

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLUE%^Shuko, Aramel, Shrydelhi, Alveric, and Iaido. 
	%^BOLD%^%^RED%^"%^BOLD%^%^YELLOW%^ Together in faith we unite.%^BOLD%^%^RED%^"

AVATAR
	);
     set("langage","str");	set_weight(300);
	set_value(0);
}