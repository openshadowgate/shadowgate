#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^ORANGE%^Shriveled head%^RESET%^");
	set_id(({ "head", " vecna head", " vecna's head", " undead head", " trophy" }));
	set_short("%^RESET%^%^ORANGE%^shriveled head%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^shriveled head%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This ancient shriveled thing is the bodyless head of some %^BLACK%^%^BOLD%^undead%^RESET%^%^ORANGE%^. Its face is twisted into a visage of unholy %^RED%^anger%^RESET%^%^ORANGE%^ and %^RED%^rage%^RESET%^%^ORANGE%^. It has been quite beaten up and scarred, both through nicks and cuts, and through magical fire. It would make a nice addition to any macabre mantelpiece. %^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(1);
	set_lore(
@AVATAR
That sorta looks like Vecna... But Vecna had a body too

AVATAR
	);
	set_property("lore difficulty",10);
}