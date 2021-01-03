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
    set_short("Cherry Street");
    set_long(
        "%^ORANGE%^You are on %^MAGENTA%^Cherry street%^RESET%^\n" +
        "%^ORANGE%^Directly west is the intersection of Cherry with Pine and Apple. The stables are also right there, and you can still smell the horses that are kept inside. Pine street runs southeast, heading back towards the Antioch gates. Apple street travels to the northeast to intersect with Oak shortly before the palace. Cherry street runs straight east and west. In the center of the street is a large %^BOLD%^%^CYAN%^foun%^RESET%^%^CYAN%^t%^BOLD%^%^CYAN%^ain.%^RESET%^%^ORANGE%^ At the far end is a very large stone church. There are many shops all along this street, including a bank just south of the fountain.
"
        );
    set_smell("default", "The breeze blows in the faint scent of" +
              " horses from the stables.");
    if (query_night() == 1) {
        set_listen("default", "You can hear the horses stomping" +
                   " about in their stalls.");
    }else {
        set_listen("default", "The street is alive with busy shoppers.");
    }
    set_items(([
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The" +
                   " street is paved with cobblestones.",
                   "street sign" : "This is %^MAGENTA%^Cherry street%^RESET%^",
                   "fountain" : "There is a large fountain in the center of" +
                   " the street.",
                   "shops" : "There are many shops along this street.",
                   ]));
    set_exits(([
                   "west" : ROOMS + "street6",
                   "east" : ROOMS + "street19",
               ]));
    if (!find_object("/d/antioch/antioch2/mons/minstrel")) {
        find_object_or_load("/d/antioch/antioch2/mons/minstrel")->move(TO);
    }
//      new(MONS+"minstrel")->move(TO);
// the check above only works for the master object, we'll load the master *Styx* 8/21/03
}
