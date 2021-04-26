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
	set_id(({ "tattoo", "tat", "ink", "pentadragon", "dragon", "pentagram", "red", "gold" }));
	set_short("a large RED and GOLD full-sleeve Pentadragon tat covering his left-arm");
