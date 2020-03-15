#include <std.h>
inherit MONSTER;
create() {
        ::create();
set_name("rattle snake");
set_id( ({ "snake", "rattle snake" }) );
set("race","snake");
        set_gender("male");
set_short("A rattle snake");
set_level(11);
set_long("He is a very fast snake, who would probably out-maneuver you.");
set_alignment(9);
set("aggressive", 5);
set_hd(7,4);
set_body_type("snake");
}
