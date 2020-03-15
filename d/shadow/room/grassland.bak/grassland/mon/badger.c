#include <std.h>
inherit MONSTER;
create() {
        ::create();
        set_name("badger");
set_id( ({"badger"}) );
        set("race", "badger");
        set_gender("male");
set_short("A badger");
set_level(12);
set_long("This is the dreaded badger.  You don't want to make him mad");
set_wielding_limbs( ({ "right foot", "left foot", "right paw", "left paw", "mouth" }) );
set_alignment(9);
set("aggressive", 10);
set_hd(6,4);
set_body_type("quadruped");
}
