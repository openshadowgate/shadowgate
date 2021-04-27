#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("doll");
	set_id(({ "sune", "doll", "sune doll" }));
	set_short("%^BOLD%^%^MAGENTA%^Rubber %^RED%^Sune%^RESET%^%^ORANGE%^ doll%^RESET%^");
	set_obvious_short("%^BOLD%^%^MAGENTA%^rubber %^RESET%^%^ORANGE%^doll%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This is an exact replica of %^RED%^Sune%^CYAN%^, down to every....ahem....detail. She even comes complete with a set of %^RESET%^%^BLUE%^gothic %^MAGENTA%^nipple %^YELLOW%^rings %^CYAN%^ connected by %^WHITE%^silver c%^BLACK%^h%^WHITE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^s%^CYAN%^.%^RESET%^

%^RESET%^%^MAGENTA%^Wink.....wink.....%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^RED%^Spank me! SPANK ME!!!!%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(0);
}
