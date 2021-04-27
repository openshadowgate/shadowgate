#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Soul Extractor");
	set_id(({ "apparatus", "magical apparatus", "magic apparatus" }));
	set_short("%^BOLD%^%^BLACK%^Magical Apparatus%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a curious piece of magical apparatus.  It is formed primarily of %^WHITE%^a large %^CYAN%^g%^WHITE%^lass sphere %^BOLD%^%^BLACK%^from which %^WHITE%^a thin %^CYAN%^g%^WHITE%^lass tube %^BOLD%^%^BLACK%^leads down to %^RESET%^%^ORANGE%^a minature set of bellows%^BOLD%^%^BLACK%^.  Just below the sphere is %^RED%^a small valve %^BOLD%^%^BLACK%^which seems to close the sphere off and would prevent any contents escaping accidentally.  Below the bellows is an odd looking %^BLUE%^mouthpiece%^BOLD%^%^BLACK%^.  A %^RESET%^%^CYAN%^small manuscript%^BOLD%^%^BLACK%^ is fastened to the thin glass tube.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^ORANGE%^With the final dying breath the soul escapes the mortal form completely.   But what of the point just before death?%^RESET%^

AVATAR
	);
     set("langage","str");	set_weight(10);
	set_value(1500);
	set_lore(
@AVATAR
Used to extract the essence of a persons soul whilst they are on the brink of death.

AVATAR
	);
}