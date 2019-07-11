#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_short("Temple of Selune");
   set_long("%^RESET%^Chunks of %^BOLD%^%^CYAN%^pale blue-veined %^BOLD%^%^WHITE%^white "
"marble %^RESET%^lie strewn in rubble across the temple floor, still glowing with a gentle "
"radiance as if bathed in moonlight. Columned archways lead into the shrine from each "
"direction, but two are partly fallen, and a third looks precarious at best, destroying "
"the delicate symmetry they might once have held. The transparent ceiling above, interestingly "
"enough, seems fairly intact, and still seems fairly secure upon the remaining pillars. "
"Shredded, burnt remnants of two %^BLUE%^tapestries %^RESET%^drape forgotten upon their "
"respective walls, and another lies crumpled in a corner opposite. In the centre of the "
"room, a %^BOLD%^%^BLUE%^circular pillar made of deep blue marble %^RESET%^stands relatively "
"unscathed, but whatever it might once have held is long gone. Any other ornamentation to "
"this once ethereal dedication to the divine, seem to have been similarly removed.");
   set_exits(([
        "out": "/d/dagger/road/road15"
   ]));
   set_smell("default","All you hear is the distant crash of the ocean.");
   set_listen("default","It is very quiet here.");
}
