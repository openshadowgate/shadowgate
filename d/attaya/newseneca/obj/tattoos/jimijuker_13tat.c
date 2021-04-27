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
	set_value(15000);
	set_id(({ "tattoo", "tat", "ink", "13", "number", "thirteen" }));
	set_short("a small BLACK #13 tattooed on his neck");
	set_long(
@MYLONG
This is just a small BOLD BLACK  neck-tattoo...of the number 13.  Its on the right side of his neck, near the Adam?s-apple....#13!

MYLONG
	);
	set_limbs(({"neck"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "small"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

