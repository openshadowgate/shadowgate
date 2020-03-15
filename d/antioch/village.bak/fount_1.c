//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Fountain Area

#include <std.h>
#include "/d/antioch/areadefs.h"
#define ANTIOCH_OBJECT ({ "cheeks" })
inherit ROOM;

void init() {
     ::init();
add_action("squish_cheeks", "squish");
}

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_smell("default","Your nose twitches as it catches the scent of fresh blood.");
  set_listen("default","Blood splashes in a fountain here."  );
  set_search("default",    "You cry out in frustration, for nothing is here!"  );
  set_short("Fountain near the gate");
  set_long(
@ANTIOCH
You stand just inside the entrance of Antioch.  Directly in 
front of you is a large stone fountain filled with %^RED%^blood%^RESET%^. 
In the middle of the fountain is a great statue of %^BLUE%^Ignatius%^RESET%^,
former god of Antioch.  The head is spouting a steady stream
of blood from it's mouth.
ANTIOCH
  );
  set_exits( ([
    "south": VIL+"gate_1",
    "west": VIL+"tower_4",
    "east": VIL+"tower_5",
    "north": VIL+"main_st1"
    ]) );
  set_items( ([
  ({"fountain", "stone fountain", "large fountain", "large stone fountain"}):
"The fountain is filled with %^RED%^BLOOD.",
    ({"ignatius","statue"}):
    "This is a large marble statue of Ignatius, former god of Antioch."
  ]));
}

int squish_cheeks(string str) {
if(!str) {
notify_fail("Squish What?\n");
return 0;
}
if(member_array(str,ANTIOCH_OBJECT) != -1)
new("/d/antioch/obj/cheek.c")->move(TO);
else {
notify_fail("No!\n");
return 0;
}
write("You push the heads cheeks and out comes a huge green object.\n");
return 1;
}
