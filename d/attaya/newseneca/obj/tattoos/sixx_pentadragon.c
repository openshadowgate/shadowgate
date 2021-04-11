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
	set_value(20000);
	set_id(({ "tattoo", "tat", "crue", "pentagram", "dragon" }));
	set_short("a medium pentadragon tattoo");
	set_long(
@MYLONG
This is a tattoo of a pentagram.  The pentagram is done in blood-black ink.  In the center of the pentagram is a RED dragoN?s head.  Over the top of the pentagram circle is a rocker with the word ?CRUE? on it.

MYLONG
	);
	set_limbs(({"right arm"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "medium"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

