//New rooms added by Circe 12/29/03 to fix mapping problems
#include <std.h>
#include "../pass.h"
inherit "/d/shadow/room/inherits/pass_parent";

void create(){
    ::create();
    set_long(desc_start + "%^ORANGE%^To the north stand the proud "+ desc_charu_mountains +
    "%^ORANGE%^ looming high against the sky. They cast their long shadows here over the " +
    desc_foothills + "%^ORANGE%^. Here the " + desc_dragon_pass_road + " %^ORANGE%^has " +
    "been carved from the rock and looks as though "
    "it is well-travelled. To the north, the land begins to rise %^BOLD%^%^CYAN%^steeply%^RESET%^%^ORANGE%^, " +
    "while the passage southward is a little easier.");


    set_exits(([
      "north" : PASSDIR+"passn1",
      "southeast" : PASSDIR+"passn3"
      ]));
}
