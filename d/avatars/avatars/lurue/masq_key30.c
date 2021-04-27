#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("key30");
	set_id(({ "key", "key30", "key 30" }));
	set_short("%^YELLOW%^key30%^RESET%^");
	set_obvious_short("%^YELLOW%^key30%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This small brass key has a single %^BLUE%^arcane rune %^YELLOW%^each side. As you look at it, you see the words forming before you, as though cast into your mind: %^WHITE%^This key opens the %^YELLOW%^Room 30 Door%^WHITE%^.  Once you are in that room and secure, you should put any costume items you want to use on the ground and then log out.  You will be able to log in through a specialized NPC character which will serve as your "masquerade self".  These NPC personas are temporary.  Once you've logged your main character out you should use the following information to log back in: %^BLUE%^LOG IN:%^YELLOW%^ masq30  %^BLUE%^PASSWORD:%^YELLOW%^ sni46t2nkd  %^WHITE%^Please keep in mind that these npcs will be rid after the masquerade is over and that you will loose any items you leave on them.  Further directions will be found on the key that the NPC has. %^YELLOW%^Do not leave this key on the ground or your main character will not be able to escape.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}
