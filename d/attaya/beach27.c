#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(BEACH);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^.");
    set_long("%^YELLOW%^S%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^y %^RESET%^%^ORANGE%^b%^BOLD%^eac%^RESET%^%^ORANGE%^h on %^BOLD%^t%^RESET%^%^ORANGE%^h%^BOLD%^e %^MAGENTA%^Is%^ORANGE%^l%^WHITE%^e %^ORANGE%^of %^MAGENTA%^Atta%^ORANGE%^y%^WHITE%^a%^RESET%^
%^RESET%^%^ORANGE%^The %^WHITE%^b%^BOLD%^%^WHITE%^e%^RESET%^%^BOLD%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^c%^RESET%^%^WHITE%^h%^ORANGE%^ extends to the north and south as far as you can see. It is quite lonely. The ocean crashes against a barrier of tar covered natural %^WHITE%^ro%^BOLD%^%^WHITE%^c%^RESET%^%^BOLD%^%^WHITE%^k%^RESET%^%^BOLD%^%^WHITE%^s%^RESET%^%^ORANGE%^ to the east. To the west, the jungle towers above you, %^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^e%^RESET%^%^BOLD%^%^GREEN%^e%^RESET%^%^BOLD%^%^GREEN%^s%^RESET%^%^ORANGE%^ casting shadows over the beach. It is nearly impenetrable.%^RESET%^
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "north" : "/d/attaya/beach31",
       "south" : "/d/attaya/beach26",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
         "rocks" : "They form a natural reef around the eastern side of the island.  They are black with oil or tar.",
    ] ));
}
