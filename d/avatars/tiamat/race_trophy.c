#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Trophy");
	set_id(({ "trophy", "prize" }));
	set_short("%^YELLOW%^Golden Racing T%^RED%^r%^YELLOW%^op%^CYAN%^h%^YELLOW%^y%^RESET%^");
	set_obvious_short("%^YELLOW%^Golden Racing T%^RED%^r%^YELLOW%^op%^CYAN%^h%^YELLOW%^y%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This is an impressive trophy made primarily from %^YELLOW%^gold%^RESET%^%^ORANGE%^.  The figure rests atop a stand of rich %^RED%^mahogany wood%^ORANGE%^.  The polished %^YELLOW%^golden figure%^RESET%^%^ORANGE%^ represents an old-fashioned sandal sporting majestic %^YELLOW%^ha%^RED%^w%^YELLOW%^k w%^RED%^i%^YELLOW%^ng%^RED%^s%^RESET%^%^ORANGE%^ and valuable %^BOLD%^%^WHITE%^pl%^CYAN%^a%^WHITE%^tinum b%^CYAN%^u%^WHITE%^ckles%^RESET%^%^ORANGE%^. The sandal is raised from the base where the ball of the foot would be, as though the footwear itself was rushing off in haste.  A small engraved %^YELLOW%^plaque%^RESET%^%^ORANGE%^ has been affixed to the wooden base, you could read it.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^CYAN%^Champion, Racing!%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(3000);
}
