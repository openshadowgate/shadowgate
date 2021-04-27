#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("wolfsbane");
	set_id(({ "wolfsbane", "plant", "plants", "flower", "flowers", "sheaf", "bundle" }));
	set_short("%^RESET%^%^GREEN%^sheaf of dried %^BLUE%^w%^GREEN%^o%^BLUE%^l%^GREEN%^fsbane%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^sheaf of dried %^BLUE%^w%^GREEN%^o%^BLUE%^l%^GREEN%^fsbane%^RESET%^");
	set_long(
@AVATAR
%^GREEN%^This is a bundle of dried plant matter.  The flowers are known locally as wolfsbane.  They are long stemmed, with a multitude of sharptoothed leaves sprouting throughout.  The top of the plant ends in display of %^BLUE%^vivid %^BOLD%^blue%^RESET%^%^BLUE%^ flowers%^GREEN%^ that droop heavily like the hood of a cloak.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(10);
	set_lore(
@AVATAR
Wolfsbane or monkshood is a member of the Aconitum family of plants.  It is a powerful deterrent to lycanthropes of all kinds.  The blue variety is quite common in the damp climes of Deku and Dagger Marsh.  Used as a medicine, it can be a powerful anasthetic and depressant, but overdoses are quite common and deadly.

AVATAR
	);
	set_property("lore difficulty",7);
}
