#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Weapon Trophy");
	set_id(({ "trophy", "prize" }));
	set_short("%^YELLOW%^Trophy of %^WHITE%^A%^YELLOW%^rmed C%^BLUE%^o%^YELLOW%^mb%^RED%^a%^YELLOW%^t%^RESET%^");
	set_obvious_short("%^YELLOW%^Trophy of %^WHITE%^A%^YELLOW%^rmed C%^BLUE%^o%^YELLOW%^mb%^RED%^a%^YELLOW%^t%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This is an impressive trophy made primarily from %^YELLOW%^gold%^RESET%^%^ORANGE%^%^.  The figure rests atop a stand of rich %^RED%^mahogany wood%^ORANGE%^.  The polished golden figure represents a masculine hand wearing a %^RESET%^ring%^ORANGE%^.  The hand is gripping a formal broadsword blade of purest %^RESET%^f%^RED%^e%^WHITE%^v%^RED%^e%^WHITE%^r iron%^ORANGE%^, broken off several inches from the tip, making the trophy both portable and demonstrating the danger of armed combat.  The sword hilt is encrusted with flakes of %^BOLD%^%^RED%^ruby%^RESET%^%^ORANGE%^ and %^BLUE%^sa%^BOLD%^pp%^RESET%^%^BLUE%^hir%^BOLD%^e%^RESET%^%^ORANGE%^, with a single light %^BOLD%^%^WHITE%^o%^MAGENTA%^p%^WHITE%^al%^RESET%^%^ORANGE%^ comprising the pommel.  A small engraved %^YELLOW%^plaque%^RESET%^%^ORANGE%^ has been affixed to the wooden base, you could read it.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^CYAN%^Champion, Armed Combat!%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(2100);
}
