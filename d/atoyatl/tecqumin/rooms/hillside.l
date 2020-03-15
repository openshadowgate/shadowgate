#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 0);
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("A hillside");
  set_short("%^BOLD%^%^GREEN%^On a %^RESET%^%^GREEN%^lush %^BOLD%^%^GREEN%^green"
           +" hillside.");
  set_long( "%^BOLD%^%^GREEN%^This hillside sits above a remarkable vista. The"
          +" %^RESET%^%^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^"
          +"%^GREEN%^l%^RESET%^%^GREEN%^e %^BOLD%^%^GREEN%^is relatively clear"
          +" here, giving way to ruined %^RESET%^st%^ORANGE%^o%^RESET%^ne"
          +" bu%^ORANGE%^i%^RESET%^ldings%^BOLD%^%^GREEN%^, dirt and gravel"
          +" paths, overgrown canals and other traces of a long lost civilisation."
          +" In the far distance to the south, a massive stone stepped pyramid"
          +" rises into the skyline. Somewhat to the west of the pyramid is strange"
          +" looking structure in what might be the shape of some kind of cat's"
          +" head. Just to the north of you, a stone wall is built into the"
          +" hillside. A low doorway in the wall leads in to a seemingly %^BOLD%^"
          +"%^BLACK%^darkened chamber%^BOLD%^%^GREEN%^. Beyond that, a dense"
          +" %^RESET%^%^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^"
          +"%^GREEN%^l%^RESET%^%^GREEN%^e %^BOLD%^%^GREEN%^blocks any further"
          +" passage to the north. " );
  set_items(([ ({"pyramid", "stone pyramid", "stepped pyramid", 
                                                    "stepped stone pyramid"}) :
     "The pyramid rises in a series of steps, giving it a jagged outline. There"
    +" appears to be a stairway leading up the centre.",
    ({"structure", "cat", "cat's head"}) : "The strange structure appears to be a"
    +" cat's head and forequarters rising out of the earth, in the manner of a"
    +" zombie crawling from the grave. The cat's mouth is open wide, as if in a"
    +" snarl.",
    ({"vista", "view"}):"The vista laid out below you has all the appearance of a"
    +" lost and ruined city. The canals and pathways would have formed effective"
    +" transport links, but are largely disrupted now by patches of jungle growth"
    +" and general ruined condition. Through the hazy air, faint shapes of"
    +" translucent %^CYAN%^blue%^RESET%^ and %^BOLD%^%^WHITE%^white%^RESET%^ can"
    +" be made out, moving on the paths and open areas." ,
    ({"canals", "canal"}):"There appears to have been a system of %^CYAN%^canals"
    +" %^RESET%^here in the past, though their once long, straight lines are"
    +" interrupted now, filled in in some places and overgrown or swampy in others."
    +" Bridges cross the canals in some places, though some of them appear ruined."
      ]));
  set_smell("default","The air is %^CYAN%^fresh%^RESET%^%^ORANGE%^ and scented"
   +" with %^GREEN%^plants%^RESET%^ %^ORANGE%^and %^BOLD%^%^CYAN%^f%^MAGENTA%^l"
   +"%^WHITE%^o%^RED%^w%^YELLOW%^e%^WHITE%^r%^MAGENTA%^s%^RESET%^");
  set_listen("default","A few bird and insect calls drift across the air");
  set_exits( ([      "north" : ROOMS + "entry_chamber", "south" : ROOMS + "path1" ])  );
 set_pre_exit_functions(({"enter", "down"}), ({"GoEnter", "GoDown"}));
}

void GoEnter(){
  tell_object(TP, "You duck through the low doorway, into a %^BOLD%^%^BLACK%^dark"
          +" chamber%^RESET%^ in the %^BOLD%^%^GREEN%^hillside%^RESET%^.");
  tell_room(TO, TPQCN + "ducks through the low doorway to the north, into a"
         +" %^BOLD%^%^BLACK%^dark chamber%^RESET%^ in the %^BOLD%^%^GREEN%^hillside"
         +"%^RESET%^.", TP);
  return 1;
}

void GoDown(){
  tell_object(TP, "You descend from the hillside, onto a dirt path in a serious"
         +" state of ill repair.");
  tell_room(TO, TPQCN + " descends from the hillside onto a dirt path below", TP);
  return 1;
}