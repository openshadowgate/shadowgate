#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("fur coat");
	set_id(({ "coat", "robe" }));
	set_short("%^BOLD%^%^BLACK%^Robe of the P%^RED%^r%^BLACK%^e%^RESET%^%^RED%^d%^BOLD%^a%^BLACK%^t%^RED%^o%^BLACK%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^fur robe lined with %^RED%^g%^BLACK%^o%^RESET%^%^RED%^r%^BOLD%^e%^RESET%^");
