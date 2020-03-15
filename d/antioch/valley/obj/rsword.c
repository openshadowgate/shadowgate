#include <std.h>
#include "../valley.h"
inherit WEAPON;

void create()
{
	::create();
	set_name("rusty sword");
	set_id(({"sword","rusty sword","blade","rusty blade"}));
	set_short("Rusty sword");
	set_long(
	"This is a rather rusty looking sword with several nicks"+
	" in the blade. It obviously has not been well cared for"+
	" and is not in the best of shape. There is a metal hilt"+
	" affixed to the blade and a cold handle that doesn't have"+
	" much grip to it."
	);
	set_size(2);
	set_type("slash");
	set_wc(1,8);
	set_large_wc(1,12);
	set_weight(10);
	set_value(10);
	set_cointype("copper");
}
