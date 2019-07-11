#include <std.h>
inherit "/std/temple";

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_temple("mystra");
        set_name("Temple of Mystra");
        set_short("Temple of Mystra");
        set_long("%^RESET%^%^MAGENTA%^This circular temple must once have been an exquisite contrast to the plain countryside around it, but if so those days "
"have passed.  Most of it now lies as a charred pile of %^RESET%^white marble%^MAGENTA%^, pocked and burnt with signs of extreme force.  In the centre stands "
"a %^BOLD%^%^BLACK%^melted marble lump %^RESET%^%^MAGENTA%^that may once have been the altar.  Scattered fragments of glass and wood, cloth and carpet suggest "
"the %^BOLD%^%^RED%^fine %^RESET%^%^MAGENTA%^quality of artwork it must once have held, but to the last they are now shredded and ruined by weather.%^RESET%^");
        set_smell("default","A faint residue of smoke lingers about these ruins.");
        set_listen("default","Silence hangs heavily upon this place.");
  set_exits( ([
	       "out" : "/d/shadow/room/village/mainroad3"
  ]) );

}
