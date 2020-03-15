#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit PATH_BASE;


void create() {
  ::create(); 
  set_exits(([ "north" : ROOMS + "jungle4", "south": ROOMS + "path9", 
                    "west" : ROOMS + "jungle7", "east" : ROOMS + "swamp4" ]));
  set_pre_exit_functions(({"north", "west", "east"}), ({"GoJungle", "GoJungle", "GoSwamp"}));
  add_item( ({"jungle", "trees", "tree"}), "The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u"
    +"%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e %^RESET%^to the north and"
    +" west is thick with trees, but there are gaps enough for you to make your way through."
    +" The trees are draped with vines and creepers, and the floor is thick with"
    +" undergrowth.");  
  add_item( ({"swamp", "swampy", "swampy land"}), "The land to the east appears%^GREEN%^"
    +" swampy%^RESET%^ and %^BLUE%^waterlogged%^RESET%^, with small areas of drier"
    +" %^ORANGE%^ground%^RESET%^ and surface sitting %^GREEN%^grasses%^RESET%^. It seems to"
    +" connect up with one of the %^CYAN%^canals%^RESET%^ whose banks have collapsed.");  
  add_item( ({"canal", "canals", "banks"}), "The %^CYAN%^canals%^RESET%^ were obviously an"
    +" important form of transport and communication in the city once, though they are now"
    +" ruined and in states of %^GREEN%^stagnant%^RESET%^ disrepair.");  
}



long_desc(){
  string desc;
  desc =  ::long_desc();
  desc += "To the north and west, the path is overgrown with %^BOLD%^%^GREEN%^j%^RESET%^"
     +"%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^. Gaps"
     +" between the trees allow you to make your way in those directions. To the east,"
     +" the land appears %^GREEN%^swampy%^RESET%^, where one of the %^CYAN%^canals"
     +" %^RESET%^has overrun its banks. The great pyramid lies a little way to the south"
     +" of here.";
  return desc;
}