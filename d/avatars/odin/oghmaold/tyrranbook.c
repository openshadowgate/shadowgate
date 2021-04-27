#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("leather book");
	set_id(({ "book", "leather book" }));
	set_short("%^RESET%^%^ORANGE%^A book bound in %^RESET%^%^RED%^red leather%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A book bound in %^RESET%^%^RED%^red leather%^RESET%^");
	set_long(
@AVATAR
This is a large book bound in deep %^RESET%^%^RED%^red leather%^RESET%^.  The numerous pages are made of decent quality paper that looks as if it would withstand a lot of abuse.  Set into the cover is a %^BOLD%^%^YELLOW%^golden ornament %^RESET%^depicting a %^BOLD%^%^BLUE%^scale %^RESET%^atop a %^BOLD%^%^RED%^hammer%^RESET%^.

AVATAR
	);
	set_weight(5);
	set_value(250);
	set_lore(
@AVATAR
This is a Tyrran Book of Judgement.  It is given to followers who have proven themselves within the faith as dedicated deliverers of Just Vengeance.

AVATAR
	);
	set_property("lore difficulty",10);
}