#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RED%^mang%^ORANGE%^le%^RED%^d%^ORANGE%^ teddy%^RED%^be%^ORANGE%^ar%^RESET%^");
	set_id(({ "teddy", "teddybear", "corpse of teddybear" }));
	set_short("%^RED%^mang%^ORANGE%^le%^RED%^d%^ORANGE%^ teddy%^RED%^be%^ORANGE%^ar%^RESET%^");
	set_obvious_short("%^RED%^mang%^ORANGE%^le%^RED%^d%^ORANGE%^ teddy%^RED%^be%^ORANGE%^ar%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^this is the mangled corpse of a small bear, about the size of a human baby, is very cute... It has been patched together however from several different teddybears, sewed together. Whats odd is the fact that the children's toy is moving on its %^RESET%^%^BOLD%^%^RED%^own accord%^RESET%^%^ORANGE%^. Each eye is a large %^RESET%^%^BOLD%^%^BLACK%^black button%^RESET%^%^ORANGE%^. An aura of %^RESET%^%^BOLD%^%^BLACK%^shadows %^RESET%^%^ORANGE%^seems to follow the cute little toy.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(0);
}