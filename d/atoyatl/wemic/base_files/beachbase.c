#include <std.h>
#include <move.h>
#include "../wemic.h"

inherit ROOM;

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(ROCKY);
  set_travel(DIRT_ROAD);
  set_name("pebble beach");
  set_short("%^ORANGE%^p%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^b%^CYAN%^"
      +"b%^RESET%^l%^ORANGE%^e b%^RESET%^e%^ORANGE%^a%^CYAN%^c%^ORANGE%^"
      +"h%^RESET%^");
  set_long( "This %^ORANGE%^p%^BOLD%^%^WHITE%^e"
      +"%^RESET%^%^ORANGE%^b%^CYAN%^b%^RESET%^l%^ORANGE%^e"
      +" b%^RESET%^e%^ORANGE%^a%^CYAN%^c%^ORANGE%^h%^RESET%^ sits at the"
      +" side of a mighty ocean. A short walk  from the sea, a"
      +" dense %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
      +"%^GREEN%^l%^BOLD%^e %^RESET%^ crowds up to the edge of the"
      +" beach. Mighty %^BOLD%^%^BLUE%^ocean br%^BOLD%^%^WHITE%^ea"
      +"%^BLUE%^k%^BOLD%^%^WHITE%^e%^CYAN%^rs%^RESET%^ crash against"
      +" the beach constantly. The churning %^GREEN%^w%^BLUE%^a%^GREEN%^t%^BLUE%^er"
      +" %^RESET%^near the shore is dark in colour, but it brightens up further"
      +" out to sea." );
    set_items(([
      ({"pebble", "pebbles", "pebbled beach", "beach"}) : "The %^ORANGE%^p%^BOLD%^%^WHITE%^e"
      +"%^RESET%^%^ORANGE%^b%^CYAN%^b%^RESET%^l%^ORANGE%^e%^RESET%^s seem to be formed of a"
      +" variety of rocks, giving the beach its variegated colours. They are rough on bare"
      +" feet, but it seems to have weathered the beating of the surf for many an age.",

      ({"path", "trail"}) : "There is no path into the jungle here, but you can easily walk along the beach.",
   
      ({"jungle", "tree", "trees"}) : "The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u"
        +"%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e%^RESET%^ is a dense tangle of"
        +" %^BOLD%^%^BLACK%^ancient %^RESET%^%^GREEN%^trees%^RESET%^ and%^GREEN%^"
        +" thick %^ORANGE%^u%^GREEN%^nd%^ORANGE%^e%^GREEN%^rgr%^ORANGE%^o"
        +"%^GREEN%^wth%^RESET%^, unpassable unless a %^ORANGE%^path%^RESET%^ has"
        +" been cut through it.",

      ({"dock", "quay"}) : "You can see an old quay built on the middle of the beach from here." 
    ] ));
  set_listen("default","The rolling waves beat against the beach, and you"
    +" can hear the cries of birds and animals in the distance");
  set_smell("default","The brine of the ocean mingles with the humid"
    +" earthy smell of the jungle.");
}
void init() {
   ::init();
}
