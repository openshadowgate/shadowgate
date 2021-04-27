#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("A Doll");
	set_id(({ "doll" }));
	set_short("%^YELLOW%^A child's doll%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This is a small doll.  It is made of wood and a face has been painted on.  Several strands of wool have been plaited together and glued on as hair and a minature %^MAGENTA%^fl%^CYAN%^ow%^BLUE%^er%^RED%^y d%^MAGENTA%^re%^CYAN%^ss %^YELLOW%^has been made for the doll to wear.  It is the sort of doll that any little girl would love to play with%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(14);
	set_lore(
@AVATAR
This is a hand carved doll.  It has been made from white oak and has been painted and dressed in a flowery fabric.

AVATAR
	);
}