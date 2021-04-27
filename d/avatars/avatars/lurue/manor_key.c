#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("manor key");
	set_id(({ "manor key", "key", "manorkey", "jewel key", "jeweled key" }));
	set_short("%^BOLD%^%^RED%^j%^WHITE%^e%^MAGENTA%^w%^RED%^el%^WHITE%^e%^RED%^d k%^MAGENTA%^e%^RED%^y%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^j%^WHITE%^e%^MAGENTA%^w%^RED%^el%^WHITE%^e%^RED%^d k%^MAGENTA%^e%^RED%^y%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This is a fancy j%^WHITE%^e%^MAGENTA%^w%^RED%^el%^WHITE%^e%^RED%^d k%^MAGENTA%^e%^RED%^y.  The long %^WHITE%^silver%^RED%^ length is studded at the top with a large %^RESET%^%^RED%^square cut ruby %^BOLD%^surrounded by several smaller %^MAGENTA%^amethyst %^RED%^slivers.  It's quite pretty and appears to be useful too.  If you could find a lock for it.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(400);
}