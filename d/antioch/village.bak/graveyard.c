#include "/d/antioch/areadefs.h"
#include <std.h>
#define NEWBIE_MONSTER ({ "ruby" })
inherit "/std/room";

void create() {
  ::create();
  set_light(2);
  set_indoors(0);
  set_short("graveyard");
  set_long(
@ANTIOCH
%^RED%^This seems to be the growing village graveyard.  Large hills of black dirt
cover the bodies of the recently deceased.  A single flower sits on top of
a small hill.  The flower seems to be somewhat alive.  Hands of zombies
spring up from the hills.
ANTIOCH
  );
  set_smell("default","You smell a flower");
  set_exits(([
    "exit":VIL+"fran_3"
  ]));
  set_items(([
    "flower":"A large ruby sits in the mouth of this living flower."
  ]));
}

void init() {
  ::init();
  add_action("get_ruby","get");
}

int get_ruby(string str) {
  if(!str){
    notify_fail("Get what?\n");
    return 0;
  }
  if(member_array(str,NEWBIE_MONSTER) != -1)
    new("/d/antioch/obj/"+str)->move(TO);
  else {
    notify_fail("You can't get that!\n");
    return 0;
  }
  write("The ruby falls from the mouth of the flower.\n");
  write("You notice that this is the %^RED%^red%^RESET%^ element.\n");
  return 1;
}
