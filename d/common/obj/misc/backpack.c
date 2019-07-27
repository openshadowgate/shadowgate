#include <std.h>

inherit PARMOUR;

void create() {
	::create();
    set_id( ({"backpack","pack","bag"}) );
    set_name("backpack");
    set("short", "%^RESET%^%^ORANGE%^A leather backpack%^RESET%^");
    set_weight(5);
    set("long", "This is a simple leather backpack that you could put things in. It has rope stripes to wear.\n");
    set_value(2);
    set_max_internal_encumbrance(25);
    set_type("ring");
    set_limbs(({"torso"}));    
    set_value(250);
    set_property("repairtype",({ "leatherwork", "tailor" }));
}

