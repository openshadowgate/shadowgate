#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_short("Crescent Street");
    set_long(
        "You are on Crescent street.\n" +
        "%^WHITE%^To the northeast Crescent %^ORANGE%^street%^WHITE%^ continues to join with Cherry and Cedar outside of the large %^BOLD%^%^ORANGE%^chur%^WHITE%^c%^ORANGE%^h.%^RESET%^%^WHITE%^ It also continues to the southwest, meeting with %^GREEN%^Pine street%^RESET%^not far from the Antioch gates. On the southern side of the road there is a small %^ORANGE%^h%^ORANGE%^o%^BOLD%^%^BLACK%^use%^RESET%^%^WHITE%^ with a brown roof. There appears to be an entrance to it a little further down this street.
"
        );
    set_smell("default", "You smell the faint scent of dried" +
              " food.");
    if (query_night() == 1) {
        set_listen("default", "It's fairly quiet at this time of" +
                   " night.");
    }else {
        set_listen("default", "You can hear the sounds of a busy" +
                   " city.");
    }
    set_items(([
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The" +
                   " street is paved with cobblestones.",
                   "street sign" : "This is Crescent street.",
                   ({ "house", "building", "shop" }) : "It is a small little wooden" +
                   " house with a pretty brown roof. The entrance is a little" +
                   " southwest of here.",
                   "church" : "There is a very impressive stone church to the" +
                   " northeast.",
               ]));
    set_exits(([
                   "southwest" : ROOMS + "street17",
                   "northeast" : ROOMS + "street15",
               ]));
}

void reset()
{
    ::reset();
    if (!present("street_light")) {
        new(OBJ + "street_light")->move(TO);
    }
}
