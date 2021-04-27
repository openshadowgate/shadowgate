#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("lollipop");
	set_id(({ "lollipop" }));
	set_short("%^YELLOW%^A %^BOLD%^%^MAGENTA%^Strawberry%^RESET%^%^GREEN%^-%^YELLOW%^Lemon lollipop.");
	set_obvious_short("%^YELLOW%^A %^BOLD%^%^MAGENTA%^Strawberry%^RESET%^%^GREEN%^-%^YELLOW%^Lemon lollipop.");
	set_long(
@AVATAR
%^YELLOW%^This is the great %^BOLD%^%^MAGENTA%^Strawberry%^RESET%^%^GREEN%^-%^YELLOW%^Lemon flavored lollipop of deviness. Only the most helpfull mortals in the realm ever see this tasty gift from %^WHITE%^Torm%^YELLOW%^. Hail all those who taste its sweetness, and get good protection from cavities.
%^RESET%^%^WHITE%^There seems to some writing along the stick of the lollipop.

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^WHITE%^This lollipop is brought to you by PepsoTorm, the deviner protection against cavities and other dental bacteria.

AVATAR
	);
     set("langage","str");	set_weight(0);
	set_value(1);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^Torm created this devine lollipop for holy protection against dental deseases and bacteria for the few mortals who have aided him over the centuries.

AVATAR
	);
}