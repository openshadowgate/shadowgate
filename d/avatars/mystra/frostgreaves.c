#include <std.h>
inherit "/d/common/obj/armour/greaves";

void create(){
	::create();
	set_name("greaves");
	set_id(({ "frost greaves", "greaves", "greaves of frost" }));
	set_short("%^BOLD%^%^CYAN%^G%^WHITE%^r%^CYAN%^e%^WHITE%^a%^CYAN%^v%^WHITE%^e%^CYAN%^s %^WHITE%^o%^CYAN%^f %^WHITE%^F%^CYAN%^r%^WHITE%^o%^CYAN%^s%^WHITE%^t%^RESET%^");
	set_obvious_short("%^BLUE%^a cold pair of greaves%^RESET%^");
	set_long("%^BLUE%^%^BOLD%^This is a sleek looking pair of greaves made for someone of normal size.  They a crafted very smoothly to guard the wearers knees and shins to a bluish shine.  They are cold to the tou"
	"ch on the outside, but the insides of them are protected from the cold by a thin layer of wool to insulate and guard from bruising.  There appears to be some kind of magic keeping the outer shell nice"
	" and cold.%^RESET%^
"
	);
	set_value(1000);
	set_lore("%^BOLD%^%^WHITE%^Crafted by the elves of Winter Isle, the %^BOLD%^%^CYAN%^G%^WHITE%^r%^CYAN%^e%^WHITE%^a%^CYAN%^v%^WHITE%^e%^CYAN%^s %^WHITE%^o%^CYAN%^f %^WHITE%^F%^CYAN%^r%^WHITE%^o%^CYAN%^s%^WHITE%^"
	"t are embued with the magic of the snowy caps of %^BLUE%^Mt. Crescent%^WHITE%^, where the hottest fire fails to melt even the first snowflake.  Many pairs of these were forged for the elven army as th"
	"ey prepared themselves for war against the %^RED%^f%^RESET%^%^RED%^i%^BOLD%^e%^RESET%^%^RED%^r%^BOLD%^y %^RESET%^%^RED%^e%^BOLD%^l%^RESET%^%^RED%^e%^BOLD%^m%^RESET%^%^RED%^e%^BOLD%^n%^RESET%^%^RED%^t%"
	"^BOLD%^a%^RESET%^%^RED%^l%^BOLD%^s %^WHITE%^that threatened to penetrate and burn their forest surrounding the ancient peak.  It is said an proficient user of magical items will know how to activate t"
	"hese greaves and use their power to their aid, though it is also said the magic fades after a time.%^RESET%^
"
	);
    set_property("lore difficulty",15);
	set_size(2);
	set_property("enchantment",2);
}



