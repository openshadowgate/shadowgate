#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit PATH_BASE;


void create() {
  ::create(); 
  set_exits(([ "south" : ROOMS + "path13", "west": ROOMS + "path11" ]));
  add_item( ({"hillside"}), "The hillside is %^BOLD%^%^GREEN%^lush%^RESET%^ and"
    +" %^GREEN%^green%^RESET%^, with a thick boundary of %^GREEN%^j%^BOLD%^"
    +"%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e"
    +" %^RESET%^at the top. Just beneath the jungle, a stone wall is built into"
    +" the side of the hillside.");  
  add_item( ({"canals", "canal"}), "Just to the southwest of this path, there is the"
    +" beginning of one of the city's many canals. The banks are intact at this"
    +" point, but the water looks dark and stagnant, and a foul smell wafts up"
    +" from it.");  
}

long_desc(){
  string desc;
  desc =  ::long_desc();
  desc += "Some way to the north and east, a lush green %^BOLD%^%^GREEN%^hillside "
         +"%^RESET%^overlooks the ruined city. The beginning of one of the city's"
         +" %^CYAN%^canals%^RESET%^ lies to the southwest.";
  return desc;
}