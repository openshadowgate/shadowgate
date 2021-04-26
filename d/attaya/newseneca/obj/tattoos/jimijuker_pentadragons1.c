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
	set_id(({ "tattoo", "tat", "ink", "pentadragon", "pentagram", "dragon", "red", "gold" }));
	set_short("a large RED and GOLD Pentadragon full-sleeve tat covering his left-arm");
	set_long(
@MYLONG
This is a large full-sleeve tattoo. It covers his left arm (from shoulder to wrist). The name of the design is called ?Pentadragon?. The color scheme is of red, gold and black. And the motif of the tattoo is of different artistic styles of ?pentagrams, and dragons? (each being of either red, gold or black).

MYLONG
	);
	set_limbs(({"left arm"}));
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

