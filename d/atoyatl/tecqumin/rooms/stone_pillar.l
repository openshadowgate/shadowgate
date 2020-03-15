#include <std.h>
#include "../tecqumin.h"

#define NOT_CLEARED 0
#define PARTLY_CLEARED 1
#define CLEARED 2
inherit ROOM;
int cleared;

void create(){
  ::create();
  set_long( (: TO, "long_desc" :) );
  set_items(([  ({"pillar", "stone pillar", "stone", "carvings", "designs"}) : 
     "The carvings on the pillar appear to show a mixture of humans, exotic creatures"
        +" and themes of the jungle. Plants and vines curl around it, framing creatures"
        +" including jaguars, feathered serpents and crocodiles. The human faces are wild"
        +" and exotic looking; round in shape, with prominent cheekbones and decorated with"
        +" bone and metal piercings." ,
    ({"wall", "foliage", "south wall", "wall of foliage"}) : 
                   "%^GREEN%^ The wall of %^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^o%^BOLD%^"
       +"%^GREEN%^li%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^ge %^RESET%^%^GREEN%^behind the"
       +" pillar is mostly composed of vines, creepers and moss. It looks a bit too square"
       +" to be entirely natural. Perhaps you could %^RESET%^<clear>%^GREEN%^ some of it?"
     ]));
  set_exits( ([      "north" : "/realms/lujke/workroom" ])  );
  cleared = 0;
}

void init(){
  ::init();
   add_action("clear_foliage", "clear");
   add_action("reveal_wall", "reveal");
}

void reset(){
  ::reset();
  cleared = 0;
}

int query_cleared(){
  return cleared;
}

void set_cleared(int cl){
  cleared = cl;
}

string long_desc(){
  switch (cleared){
  case NOT_CLEARED:
    return "%^GREEN%^A break in the dense jungle here reveals a single, moss-covered"
        +" %^RESET%^stone pillar%^GREEN%^. About three metres in height, it is carved"
        +" with intricate designs that are badly faded with age. Behind it, a tangled"
        +" wall of %^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^l"
        +"%^RESET%^%^GREEN%^ia%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^e blocks any further"
        +" passage to the south.";
    break;
  case PARTLY_CLEARED:
    return "%^GREEN%^A break in the dense jungle here reveals a single, moss-covered"
        +" %^RESET%^stone pillar%^GREEN%^. About three metres in height, it is carved"
        +" with intricate designs that are badly faded with age. Behind it, a tangled"
        +" wall of %^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^l"
        +"%^RESET%^%^GREEN%^ia%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^e blocks any further"
        +" passage to the south. A small patch of %^RESET%^stone%^GREEN%^ has been"
        +" revealed under the folaige.";
    break;
  case CLEARED:
    return "%^GREEN%^A break in the dense jungle here reveals a single, moss-covered"
        +" %^RESET%^stone pillar%^GREEN%^. About three metres in height, it is carved"
        +" with intricate designs that are badly faded with age. Behind it, an ancient"
        +" %^RESET%^st%^ORANGE%^o%^RESET%^ne wa%^ORANGE%^l%^RESET%^l %^GREEN%^has been"
        +" revealed from under an overgrowth of %^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^o"
        +"%^BOLD%^%^GREEN%^lia%^RESET%^%^GREEN%^ge. A low, square doorway topped with"
        +" a heavy stone lintel leads into a %^BOLD%^%^BLACK%^dark chamber%^RESET%^"
        +"%^GREEN%^ to the south.";
    break;
  }
}

int clear_foliage(string str){
  str = lower_case(str);
  if (str != "foliage" && str != "wall" && str != "south wall" && str != "wall of foliage"){
    return notify_fail("What is it you are trying to clear?");
  }
  if (cleared != NOT_CLEARED){
    tell_object(TP, "The foliage has already been cleared");
    return -1;
  }
  tell_object(TP, "You clear away a small section of the %^BOLD%^%^GREEN%^f%^RESET%^"
      +"%^GREEN%^o%^BOLD%^%^GREEN%^li%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^ge%^RESET%^,"
      +" revealing a patch of a%^ORANGE%^g%^RESET%^ed st%^ORANGE%^o%^RESET%^ne underneath.");
  tell_room(TO, TPQCN + " clears away a small section of the %^BOLD%^%^GREEN%^f%^RESET%^"
      +"%^GREEN%^o%^BOLD%^%^GREEN%^li%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^ge%^RESET%^,"
      +" revealing a patch of a%^ORANGE%^g%^RESET%^ed st%^ORANGE%^o%^RESET%^ne underneath."
        , TP);
    add_item( ({"wall", "foliage", "south wall", "wall of foliage"}) ,
              "%^GREEN%^Part of the wall of %^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^o%^BOLD%^"
       +"%^GREEN%^li%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^ge %^RESET%^%^GREEN%^has been"
       +" cleared%^GREEN%^, revealing an area of%^RESET%^ a%^ORANGE%^g%^RESET%^ed"
       +" s%^ORANGE%^t%^RESET%^on%^ORANGE%^e%^RESET%^ %^GREEN%^. Perhaps you could"
       +" %^RESET%^<reveal>%^GREEN%^ it all.");
  cleared = PARTLY_CLEARED;
  return 1;
}

int reveal_wall(string str){
  str = lower_case(str);
  if (str != "wall" && str != "south wall" && str != "aged wall"){
    return notify_fail("What is it you are trying to reveal?");
  }
  if (cleared == NOT_CLEARED){
    return notify_fail("Perhaps you would need to clear some of the foliage first?");
  }
  if (cleared != PARTLY_CLEARED){
    tell_object(TP, "The foliage has already been cleared");
    return -1;
  }
  tell_object(TP, "You clear away a swathe of foliage, completely revealing an aged"
                 +" st%^ORANGE%^o%^RESET%^ne w%^ORANGE%^a%^RESET%^ll underneath, with a low"
                 +" doorway in the centre");
  tell_room(TO, TPQCN + " clears away a swathe of foliage, completely revealing an aged"
                 +" st%^ORANGE%^o%^RESET%^ne w%^ORANGE%^a%^RESET%^ll underneath, with a low"
                 +" doorway in the centre", TP);
  cleared = CLEARED;
  add_item(({"wall", "foliage", "south wall", "wall of foliage"}) ,
          "The %^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^li%^RESET%^%^GREEN%^"
      +"a%^BOLD%^%^GREEN%^ge%^RESET%^ has been completely cleared, revealing an ancient"
      +" s%^ORANGE%^t%^RESET%^one wa%^ORANGE%^l%^RESET%^l beneath. It is crumbling with age"
      +" and has been damaged by the ingress of the jungle. A low doorway, topped with a"
      +" heavy stone lintel appears to lead into a %^BOLD%^%^BLACK%^dark chamber%^RESET%^"
      +" to the south."
       );
  add_exit(ROOMS + "entry_chamber", "south");
  return 1;
}