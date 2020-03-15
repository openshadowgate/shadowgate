#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit PATH_BASE;


void create() {
  ::create(); 
  set_exits(([ "east" : ROOMS + "path2", "west": ROOMS + "path11", 
               "southwest" : ROOMS + "path20" ]));
  add_item( ({"hillside"}), "The hillside is %^BOLD%^%^GREEN%^lush%^RESET%^ and"
    +" %^GREEN%^green%^RESET%^, with a thick boundary of %^GREEN%^j%^BOLD%^"
    +"%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e"
    +" %^RESET%^at the top. Just beneath the jungle, a stone wall is built into"
    +" the side of the hillside.");  
}

long_desc(){
  string desc;
  desc =  ::long_desc();
  desc += "Some way to the north and east, a lush green %^BOLD%^%^GREEN%^hillside "
         +"%^RESET%^overlooks the ruined city.";
  return desc;
}