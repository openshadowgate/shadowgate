#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("venom sack");
	set_id(({ "venom", "snake venom", " venom sack" }));
	set_short("%^RESET%^%^GREEN%^venom sack%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^venom sack%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^This sack, ripped from the body of something strong and venomous, holds a good amount of %^BLACK%^%^BOLD%^strong poison%^RESET%^%^GREEN%^. It has to be handled carefully, as the thin membrane that protects it is close to tearing. There is enough poison contained within to %^RED%^kill%^RESET%^%^GREEN%^ even the strongest of beasts.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(10000);
}