#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit PATH_BASE;


void create() {
  ::create(); 
  set_exits((["north" : ROOMS + "hillside", "south" : ROOMS + "path2"]));
  set_pre_exit_functions(({"up"}), ({"GoUp"}));
  add_item( ({"hillside"}), "The hillside is %^BOLD%^%^GREEN%^lush%^RESET%^ and"
    +" %^GREEN%^green%^RESET%^, with a thick boundary of %^GREEN%^j%^BOLD%^"
    +"%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e"
    +" %^RESET%^at the top. Just beneath the jungle, a stone wall is built into"
    +" the side of the hillside, with a low doorway leading into a %^BOLD%^"
    +"%^BLACK%^dark chamber%^RESET%^.");  
}

void GoUp(){
  tell_object(TP, "You climb from the path up onto the %^BOLD%^%^GREEN%^hillside"
                 +" %^RESET%^above.");
  tell_room(TO, TPQCN + " climbs from the path onto the %^BOLD%^%^GREEN%^hillside"
                +" %^RESET%^above to the north.", TP);
  return 1;
}

long_desc(){
  string desc;
  desc =  ::long_desc();
  desc += "Above you to the north, a lush green %^BOLD%^%^GREEN%^hillside "
         +"%^RESET%^overlooks the ruined city.";
  return desc;
}