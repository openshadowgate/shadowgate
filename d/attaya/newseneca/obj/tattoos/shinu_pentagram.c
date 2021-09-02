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
	set_id(({ "tattoo", "tat", "ink", "pentagram", " character", " anger" }));
	set_short("a huge Pentagram tattooed in BLOOD on his chest");
	set_long(
@MYLONG
This is a huge tattoo on his large chest. its a huge pentagram...tatted using virgin pixie blood. The Pentagram is sloppyand there is a big angry BLACK senzokuan character tatted in the middle of the bloody pentagram.
(ask him what the character means)

MYLONG
	);
	set_limbs(({"torso"}));
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

