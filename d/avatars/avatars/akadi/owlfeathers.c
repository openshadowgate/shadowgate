#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^Plu%^RESET%^ck%^BOLD%^%^BLACK%^ed owlbear fe%^RESET%^a%^BOLD%^%^BLACK%^th%^RESET%^e%^BOLD%^%^BLACK%^rs%^RESET%^");
	set_id(({ "feathers", "feather", "owlbear feathers", "owlbear feather" }));
	set_short("%^BOLD%^%^BLACK%^A %^RESET%^han%^BOLD%^%^BLACK%^d%^RESET%^ful %^BOLD%^%^BLACK%^of %^RESET%^f%^BOLD%^%^BLACK%^ea%^RESET%^th%^BOLD%^%^BLACK%^er%^RESET%^s");
	set_obvious_short("%^BOLD%^%^BLACK%^A %^RESET%^han%^BOLD%^%^BLACK%^d%^RESET%^ful %^BOLD%^%^BLACK%^of %^RESET%^f%^BOLD%^%^BLACK%^ea%^RESET%^th%^BOLD%^%^BLACK%^er%^RESET%^s");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Taken from a recently perished %^RESET%^owlbear%^BOLD%^%^BLACK%^, these feathers are soft to the touch but %^RESET%^%^ORANGE%^not%^BOLD%^%^BLACK%^ very attractive. In fact, little %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ splotches coating the surface of the feathers could only be %^RESET%^%^RED%^bl%^BOLD%^o%^RESET%^%^RED%^od%^BOLD%^%^BLACK%^, a hint of the %^RESET%^%^GREEN%^vi%^BOLD%^%^BLACK%^ole%^RESET%^%^GREEN%^nt%^BOLD%^%^BLACK%^ death this creature suffered.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(2);
	set_lore(
@AVATAR
These feathers are easily identified as that of an owlbear, a violent creature that is known mostly for terrorizing the island of Deku.

AVATAR
	);
	set_property("lore difficulty",2);
}