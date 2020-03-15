#include <std.h>
// Created By DemonForce - Edited by Fire Dragon

inherit"/std/room";

#include "/d/antioch/areadefs.h"
void create() 
{
  ::create();
  set_light(2);
  set_indoors(3);
set_short("You are in a huge tower.");
set_long(
"%^BOLD%^You are in the Dark Tower of Antioch%^RESET%^.\n"
"A huge clock, many books; which look as to be spell related, a wand"
           "made out of black crystal, A pentagram in the center of the room "
           "with two swords, a dagger, and another wand that you can see "
           "through.");
  set_smell("default","You smell old brick.\n");
  set_exits(([
    "west":VIL+"t10"
  ]));
}

/*
void reset() {
object ob;
	::reset();
	if(!present("ignatius"))
{
             ob = new ("/d/antioch/mon/ignatius");
     ob->move(TO);
	     ob->die(TO);
	}
}
*/
