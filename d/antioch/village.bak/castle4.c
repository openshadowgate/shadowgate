inherit "/std/room";
#include "/d/antioch/areadefs.h"

void init() {
     ::init();
do_random_encounters(({"/d/antioch/mon/poet.c"}),50, 0);
add_action("pull_hand", "pull");
}
void create() {
     ::create();
     set_light(2);
     set_indoors(3);
     set_short("castle.\n");
     set_long(
     " \n"
"%^BOLD%^You are in the Castle of Antioch!%^RESET%^\n"
"A huge hole is here.  Through it you can see clouds of all sorts. "
"A poet is here singing and saying a lovely poem.  Also, out of the hole you "   
"see a hand of some sort holding on for dear life.  It would be nice if you "
"pull it up.\n"
);
     set_smell("default", "You smell dust from the statue.\n");
     set_listen("default", "You hear poetry to the east.\n");
     set_exits( ([
       "east": CASTLE+"castle5",
       "west": CASTLE+"castle3"
]));
     set_items(([
({"hole"}):
"You can see many clouds.  A hand sits here holding on to the hole."
]));
}                                           
     int pull_hand(string str) {
write("As you pull on the a hand a finger rips off.  You notice, as the 
creature falls, that it was a zombie.\n");
say((string)this_player()->query_cap_name()+ "pulls on the hand.\n");
write("%^MAGENTA%^WOOOA, the finger is alive.\n");
this_player()->add_hp(-(random(50)));
write("The finger runs up your arm and slashes your neck!\n");
write("Another hand grabs on to the hole.\n");
write("It is probably not a good idea to grab it again!\n");
say((string)this_player()->query_cap_name()+" glances down at the hole as 
another hand grabs the hole.\n");
return 1;
}

