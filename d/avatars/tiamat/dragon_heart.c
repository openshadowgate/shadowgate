#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("crystal heart");
	set_id(({ "heart", "crystal" }));
	set_short("%^BOLD%^%^CYAN%^ic%^BLUE%^y %^WHITE%^cr%^MAGENTA%^y%^BLUE%^s%^CYAN%^t%^WHITE%^a%^CYAN%^l %^BLUE%^h%^CYAN%^e%^WHITE%^a%^CYAN%^r%^BLUE%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^ic%^BLUE%^y %^WHITE%^cr%^MAGENTA%^y%^BLUE%^s%^CYAN%^t%^WHITE%^a%^CYAN%^l %^BLUE%^h%^CYAN%^e%^WHITE%^a%^CYAN%^r%^BLUE%^t%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^The object you observe appears to be pure, flawless %^WHITE%^crystal%^BLUE%^, artfully crafted into the shape of an organic heart.  Though perfect in detail, the heart would be far larger than a humanoid's - it is nearly the size of your head.  Facets have been worked into the crystal, giving it an inner %^CYAN%^icy glow%^BLUE%^.  Inspecting it closely, you can even feel a chill coming from the crystal.%^RESET%^

AVATAR
	);
	set_weight(6);
	set_value(9000);
	set_lore(
@AVATAR
%^CYAN%^Although pictures vary, you believe this could actually be a dragon's egg.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",35);
}
