#include <std.h>
inherit MONSTER;
create() {
        ::create();
set_name("emph");
set_id( ({ "emph" }) );
set("race","emph");
        set_gender("male");
set("short","A flying emph.");
set_level(11);
set_long("He flies around making wonderful treasures with his magic.");
set_alignment(9);
set("aggressive", 5);
set_hd(8,4);
set_body_type("dragon");
}
