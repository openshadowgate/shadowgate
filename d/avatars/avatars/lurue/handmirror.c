#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("hand mirror");
	set_id(({ "mirror", "hand mirror", "polished mirror", "framed hand mirror" }));
	set_short("%^YELLOW%^a %^RESET%^%^ORANGE%^g%^YELLOW%^o%^BLACK%^l%^RESET%^%^ORANGE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^n f%^YELLOW%^r%^BLACK%^a%^RESET%^%^ORANGE%^m%^YELLOW%^e%^RESET%^%^ORANGE%^d %^YELLOW%^hand mirrror%^RESET%^");
	set_obvious_short("%^YELLOW%^a %^RESET%^%^ORANGE%^g%^YELLOW%^o%^BLACK%^l%^RESET%^%^ORANGE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^n f%^YELLOW%^r%^BLACK%^a%^RESET%^%^ORANGE%^m%^YELLOW%^e%^RESET%^%^ORANGE%^d %^YELLOW%^hand mirrror%^RESET%^");
	set_long(
@AVATAR

%^YELLOW%^This fine hand held mirror looks to be an heirloom piece.  Its polished %^RESET%^%^ORANGE%^g%^YELLOW%^o%^BLACK%^l%^RESET%^%^ORANGE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^n f%^YELLOW%^r%^BLACK%^a%^RESET%^%^ORANGE%^me %^YELLOW%^is aged and is darker then a newly made piece might be.  A narrow handle widens into an oval frame that is only about the width of a hand, but within it a sheet of %^BLACK%^s%^WHITE%^i%^RESET%^l%^BOLD%^%^WHITE%^v%^BLACK%^er %^YELLOW%^treated glass has been set.  The glass reflects all that is about it, making for a fine mirror to check or admire oneself in.  Six small %^RED%^r%^RESET%^%^MAGENTA%^u%^BOLD%^%^RED%^bi%^BLACK%^e%^RESET%^%^RED%^s %^YELLOW%^encircle the back of the frame adding a hint of finery to the otherwise simple design. %^RESET%^


AVATAR
	);
	set_weight(1);
	set_value(200);
}
