#include <std.h>
inherit MONSTER;
create() {
        ::create();
        set_name("dog");
set_id( ({ "pit bull"}) );
        set("race", "dog");
        set_gender("male");
set("short","A mean pit bull.");
set_level(10);
set("long","He is one of the most deadly dogs around.");
set_wielding_limbs( ({ "right foot", "left foot", "right paw", "left paw", "mouth" }) );
set_alignment(9);
set("aggressive", 5);
set_hd(5,4);
set_body_type("quadruped");
}
