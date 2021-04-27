#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("token");
	set_id(({ "token", "prize token" }));
	set_short("%^BLUE%^%^BOLD%^a small electrum token%^RESET%^");
	set_obvious_short("%^BLUE%^%^BOLD%^a small electrum token%^RESET%^");
	set_long(
@AVATAR

%^BLUE%^%^BOLD%^This is a small electrum token about the size of a gold coin but tinged blue.  Marked upon one side is an intricate stamp of a %^WHITE%^many sailed ship%^BLUE%^ before a busy %^RESET%^%^ORANGE%^harbor%^BOLD%^%^BLUE%^.  On the reverse side is a tiny amount of printing that could be read.%^RESET%^


AVATAR
	);
	set("read",
@AVATAR

%^BOLD%^%^BLUE%^         City of Torm
%^RESET%^%^CYAN%^       Good for one size  
%^RESET%^%^CYAN%^    or appearance alteration
%^RESET%^%^CYAN%^       to a single item.
%^RESET%^%^CYAN%^    Restrictions may apply.%^RESET%^


AVATAR
	);
     set("langage","common");	set_weight(0);
	set_value(0);
	set_lore(
@AVATAR

Provided by the City of Torm as rewards for Storytelling Contests.  May be redemed at any shop in Torm by the holder of the token.  One size adjustment or appearance alteration to one item per token. Contact your local Immortal staff to redeem.

AVATAR
	);
	set_property("lore difficulty",0);
}