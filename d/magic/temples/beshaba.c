#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("A ruined stone building");
   set_short("%^BOLD%^%^MAGENTA%^A ruined stone building%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Little more than crumbled stone remains of this temple. Debris lies scattered across the floor, and the fresh scent of the outdoors seeps in through the fallen "
"walls, entwining with a faint scent of %^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^s%^BOLD%^%^WHITE%^h %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^de%^GREEN%^c%^ORANGE%^ay%^BOLD%^%^BLACK%^. Black rats "
"scurry across the marble floor, which is partially covered with a stained %^RESET%^%^RED%^m%^MAGENTA%^a%^BOLD%^%^MAGENTA%^u%^RESET%^%^MAGENTA%^v%^RED%^e %^BOLD%^%^BLACK%^wool rug. Shattered "
"pillars have been abandoned where they have fallen. Placed upon the destroyed altar, held high on a pair of black horns, is a scorched %^RESET%^%^CYAN%^steel tablet %^BOLD%^%^BLACK%^defaced "
"by deep %^RESET%^%^RED%^claw marks%^BOLD%^%^BLACK%^. Above this, suspended on the tips of the horn rack is the headless, %^RESET%^skeletal %^BOLD%^%^BLACK%^remains of a corpse.  Old %^RESET%^"
"%^RED%^dried blood %^BOLD%^%^BLACK%^stains the horns, %^RESET%^%^CYAN%^tablet %^BOLD%^%^BLACK%^and the broken shards of a %^RESET%^mirror %^BOLD%^%^BLACK%^set under the horns.\n%^RESET%^");
   set_smell("default","The scent of ash and decay still lingers.");
   set_listen("default","The squeaking of rats can be heard as they scamper about.");
   set_exits(([
      "out":"/d/azha/theater/rooms/azp4"
   ]));
}