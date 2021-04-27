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
	set_id(({ "tattoo", "tat", "ink", "M", "neck" }));
	set_short("a small BOLD BLACK ?M? tattooed on his neck");
	set_long(
@MYLONG
This is just a small BOLD BLACK letter M.  Its just a simple neck tattoo.  Well, there is a bit of magic involved...magic ink.  Its really a Gnomish-character that is used to stand for the common-language letter M.  But that Gnomish-character that can also mean full out words in the gnomish language.  It sets on the left side of the neck, on the other side of the Adam?s-apple.

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

