//Written by Longman.
//Please ask for permission before copying this file to your area!
//The number of ponds needs to be regulated.

#include <std.h>
#include <objects.h>

inherit "std/pier";

void init() {
  ::init();
  add_action("push_button", "push");
}

void create() {
    ::create();
    set_light(2);
    set_short("A Longman Pond");
    set_long(
@ONLINE09G
%^CYAN%^A small pond, which appears to be filled with fish stands
before you. The shore of the pond is surrounded by steep rock, except for
where you are standing. A large sign reads:

	   %^GREEN%^Another successful pond by the

           %^YELLOW%^LONGMAN POND CO.%^RESET%^

      Placed here for your convience. Push the button for immediate
     delivery of an official LPC pole. Remember-- patience and time!
ONLINE09G
    );
set_smell("default","You smell moisture from the water.");
set_listen("default","You hear a %^CYAN%^**SPLOOSH**%^GREEN%^ as a fish jumps!");
    set_exits(([
"east" : "/d/shadow/room/grassland/grass1.c",
    ] ));
    set_items(([
"pond" : "An official Longman Pond Company (LPC) pond!",
       "fish" : "You hope there are some in there!",
	   "rock" : "Rock that is along the shore of the pond. There is a button placed in it.",
	  "button" : "A small button placed in the rock. Small writing above it reads 'Push for fishing poles.'",
	   "sign" : "The sign reads-
	   %^CYAN%^To all fishermen:
	   Please only fish with official fishing poles!
	   No twigs allowed! You may push the button
	   for a standard pole or goto the shop and
	   and buy a professional fishing rod.
		-Thank You%^RESET%^"
    ] ));
set_max_fishing(4);
set_chance(17);
set_max_catch(6);
set_fish( ([ "Issaquah Trout": 3, "Big Kahuna": 10 ]) );
}

int push_button(string str) {
 if(!str) {
   notify_fail("What do you want to push?\n");
   return 0;
 }
write("You press the button. A stick modified for fishing comes out of the dispensing chute.");
  say(this_player()->query_cap_name()+" gets a fishing stick from the dispenser!", this_player());
  new("/d/shadow/obj/misc/fishing_pole.c")->move(this_object());
return 1;
}
