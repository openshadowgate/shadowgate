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
	set_value(25000);
	set_id(({ "tattoo", "tat", "ink", "gutterboy", "hieroglyphics" }));
	set_short("a large RED and GOLD tat of hieroglyphics on his leg");
	set_long(
@MYLONG
This is a strange tattoo on his leg.  Its a series of red and gold Hieroglyphics.  You can just get a hint of what they mean.  Put together they spell out ?GUTTERBOY?.

MYLONG
	);
	set_limbs(({"right leg"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "large"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

