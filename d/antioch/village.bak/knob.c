inherit "/std/room";
#include "/d/antioch/areadefs.h"

int blocked;
void init() {
     ::init();
add_action("twist", "twist");
}
void create() { 
     ::create();
     set_light(2);
     set_indoors(0);
     set_short("You are in the vanishing room.\n");
     set_long(
     "\n"
"You are at the magical %^BOLD%^Knob%^RESET%^.  The knob floats without any "
"help from a door.  It just sits there waiting to be twisted and turned.  "
"For some reason a shadow of a huge castle fills the clouds causing great "
"confusion.\n"
);
     set_exits(([
     "south": VIL+"fly4",
     ]));
     set_items(([
     ({ "door" }):
     "The door looms overhead.  Yet you think you might be able to open it."
     ]));
     }
void reset() {
     ::reset();    
  remove_exit("up");
     blocked = 0;
     }
int twist(string str) {
write("As you twist the magical knob a huge castle appears over you.\n");
say((string)this_player()->query_cap_name()+" Twists the knob.\n");
       add_exit(CASTLE+"castle1","up");
     blocked = 1;
     return 1;
     }
     string wall(string str) {
     if(blocked) return "It seems to be blocked by something";
else return "Okay!";
     }

