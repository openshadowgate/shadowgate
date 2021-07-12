#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(30000);
	set_id(({ "tat", "tattoo", "rune", "leg" }));
	set_short("a huge RED and BLACK Rune sleeve tat on lower left-leg");
	set_long(
@MYLONG
its a large sleeve tattoo on his left leg. Its a motley motif of RED and BLACK gnomish runes. if you know, then you are in the know...so you know that the Runes make ?NMRP?.
And it is what it is.

emoteat jimijuker grinning at the parrot...$M chomps on his stogie like a goon
Simple pride.

MYLONG
	);
	set_limbs(({"left leg"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "huge"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

