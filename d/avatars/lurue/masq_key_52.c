#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("masq_key_52");
	set_id(({ "key", "masq_key_52", "white key" }));
	set_short("%^RESET%^%^BOLD%^%^WHITE%^Key to Room Number 52%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^WHITE%^Key to Room Number 52%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^A piece of %^BOLD%^%^WHITE%^white crystal%^RESET%^%^CYAN%^ has been formed into the shape of a key with the number %^BOLD%^%^WHITE%^52%^RESET%^%^CYAN%^ emblazoned upon both sides.  As you gaze at it, the following information comes into your mind:%^BOLD%^ You must have this key to enter room 52.  Once you are in that room, put all costume items on the ground and log your main character out.  You will be logging in with a special NPC character whose log-in information is: %^RED%^LOGIN: %^RESET%^%^BOLD%^%^WHITE%^masqaa %^BOLD%^%^RED%^PSWD: %^RESET%^%^BOLD%^%^WHITE%^klgfu %^BOLD%^%^CYAN%^- They will be located in the same room you are in.  You will need to use this PC as your masquerade PC.  They will be rid after the masquerade so make sure you return to your room and drop equip so your main PC will be able to get it when they log in. More info is on your alt.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
}
