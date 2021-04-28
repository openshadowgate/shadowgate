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
	set_id(({ "tattoo", "tat", "ink", "bardbarian", "bardic", "red", "gold", "cards", "dice", "ballet", "colorful" }));
	set_short("a huge colorful Bardbarian complete arm-sleeve tattoo covering the right-arm");
	set_long(
@MYLONG
This large full-sleeve tattoo covers the whole right-arm.All the way from the top of the arm, to the hand. It even covers the hand, and the fingers.
Its primary colors are BURNT ORANGE,BLACK and RED, and GOLD. With colors like PURPLE, GREEN, and other such colors mixed into the scheme as well.
The motif of the artistic tattoo is dedicated to the Bardic lifestyle. In the work are musical-notes, a quill, ballet-shoes, and of course ?The Comedy and Tragedy? theatre masks are present as well.
Also in the artistic mix is WHITE dice, GREEN AND yellow playing-cards, and SILVER horse-shoes...

MYLONG
	);
	set_limbs(({"right arm"}));
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

