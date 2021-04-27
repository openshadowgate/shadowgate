#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("hamster");
	set_id(({ "hamster", "small hamster" }));
	set_short("%^RESET%^%^RED%^A %^BLUE%^small %^RESET%^%^ORANGE%^g%^YELLOW%^o%^RESET%^%^ORANGE%^l%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n%^RESET%^%^ORANGE%^-h%^RESET%^%^ORANGE%^a%^YELLOW%^i%^RESET%^%^ORANGE%^r%^YELLOW%^e%^RESET%^%^ORANGE%^d %^RED%^hamster%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^A %^BLUE%^small %^RESET%^%^ORANGE%^g%^YELLOW%^o%^RESET%^%^ORANGE%^l%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n%^RESET%^%^ORANGE%^-h%^RESET%^%^ORANGE%^a%^YELLOW%^i%^RESET%^%^ORANGE%^r%^YELLOW%^e%^RESET%^%^ORANGE%^d %^RED%^hamster%^RESET%^");
	set_long(
@AVATAR
This is a regular sized hamster with %^RESET%^%^ORANGE%^g%^YELLOW%^o%^RESET%^%^ORANGE%^l%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n%^RESET%^%^ORANGE%^-%^YELLOW%^b%^RESET%^%^ORANGE%^r%^YELLOW%^o%^RESET%^%^ORANGE%^w%^YELLOW%^n %^RESET%^hair.  It is a fat little thing and its body wiggles when it walks across something.  It's ears are somewhat large and are a dull %^BOLD%^%^MAGENTA%^pink %^RESET%^on the inside.  It's little bittle tail is almost constantly wagging as it sniffs acround.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_property("lore difficulty",0);
}