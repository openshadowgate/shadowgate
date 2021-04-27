// beastmen in Charu
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(LEDGE);
    set_property("indoors",0);
    set_property("light",2);
    set_name("A valley clearing in the Charu Mountains");
    set_short("%^RESET%^%^ORANGE%^A valley clearing in the Charu Mountains%^RESET%^");
    set_long("%^RESET%^%^GREEN%^This is only a tiny clearing, sandwiched between mountains on either side that rise "
"up to grasp at the %^CYAN%^sky%^GREEN%^.  %^ORANGE%^Tall trees %^GREEN%^line either slope, leaving only a narrow way "
"through which is often impeded by smaller saplings.  The ground is fairly rocky beneath your feet, rather than dense "
"with grass and undergrowth, so it's at least not too troublesome to get past.  A small number of rough habitations "
"appear to be further northwards.%^RESET%^\n");
    set_smell("default","The clean, fresh smell of mountain air reaches your nose.");
    set_listen("default","The gentle trills and chirps of birds and insects can be heard all around.");

    set_exits(([
      "north" : "/d/avatars/nienne/dragonlair/beastmen",
    ]));
}
