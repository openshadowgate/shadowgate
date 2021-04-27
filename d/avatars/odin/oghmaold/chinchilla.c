#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("chinchilla");
	set_id(({ "chinchilla" }));
	set_short("%^RESET%^A %^GREEN%^chinchilla %^RESET%^with %^BOLD%^fluffy %^RESET%^%^CYAN%^gray fur%^RESET%^");
	set_obvious_short("%^RESET%^A %^GREEN%^chinchilla %^RESET%^with %^BOLD%^fluffy %^RESET%^%^CYAN%^gray fur%^RESET%^");
	set_long(
@AVATAR
This odd looking rodent at first appears to be a cross between a large %^RESET%^%^RED%^rat %^RESET%^and a %^YELLOW%^squirrel%^RESET%^.  It posses a set of large, round ears and a chubby, rodent face.  It's fluffy %^RESET%^%^CYAN%^gray hair %^RESET%^is smooth and silky, but tends to get a little spikey near its rear.  It has a longish tail that ends in a bunch of brissley hair that reminds you of a flag or some such.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(0);
	set_property("lore difficulty",0);
}