//  Created by Ignatius, for ShadowGate
//  Coded foo February, 1995
//  Village of Antioch
//  Town Square Entry

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

int blocked;
void init() {
     ::init();
add_action("ram_crack", "ram");
}
void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 0);
  set_property("no castle", 1);
  set_search("default",
    "You gaze at all the stalls in the bazaar, but find little unusual.\n"
    "There is a steeple far off in the west though."
  );
  set_smell("default",
    "The town square smells of fresh meats and fruits."
  );
  set_listen("default",
    "Little can be heard here.  The bustle is too great."
  );
  set("short",
    "Town Square Entry"
     );
  set("long",
      " \n"
" You enter the town prison.  There are many guards standing around "
"doing nothing at all.  You see many types of skulls, animal, dragon "
"demon, every skull you could imagine.  This prison seems to be made "
"of stone, two rooms, and small stone windows which lets the guards "
"watch after you day and night.\n"
    );
  set_exits( ([
    ]) );
  set_items( ([
({"windows", "window", "stone windows", "stone window"}):
"You notice a little crack in the window maybe you could push it open,you start thinking about goats and what they do to get through things."
    ]) );
}

void reset() {
     ::reset();
remove_exit("north");
blocked = 0;
}
int ram_crack(string str) {
write("%^MAGENTA%^An evil voice whispers:%^RESET%^ Good job mortal.\n");
write("%^CYAN%^The wall falls to the ground.\n");
tell_room(TO,TPQCN+" pushes the wall down.",TP);
add_exit("/d/antioch/village/jail2.c", "north");
blocked = 1;
return 1;
}
string wall(string str) {
if(blocked) return "%^MAGENA%^A voice yells:%^RESET%^ Whimp!!!";
else return "The wall seems to be cracked even more then before.";
}
