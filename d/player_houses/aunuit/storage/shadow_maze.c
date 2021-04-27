//Ryzan and Aunuit's House
//Coded by ~Circe~ 7/29/13

#include <std.h>
#include "../aunuit.h"

inherit VAULT;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(BUILT_TUNNEL);
   set_light(0);
   set_indoors(1);
   set_name("Shadow Maze");
   set_short("%^BOLD%^%^BLACK%^Shadow Maze%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^The darkness here is pervasive and all-"
      "consuming, swallowing any light in the area before it gets far "
      "from its source. No walls or ceiling can be seen, and even "
      "the floor underfoot is shrouded by a thick black fog that "
      "swirls and eddies about your legs. The cold air seems to chill "
      "your very soul, and the way the darkness roils, it almost seems "
      "alive. Surely there must be a way out of this cold void?%^RESET%^\n");
   set_listen("default","%^CYAN%^All sound seems muted here.%^RESET%^");
   set_smell("default","%^BOLD%^%^CYAN%^The cold air seems to have killed "
      "any scents that you might otherwise smell.%^RESET%^");
   set_property("no peer",1);
   set_peer_message("%^BOLD%^%^BLACK%^It is impossible to see anything "
      "in the thick, unyielding murk that surrounds you.%^RESET%^");
   set_property("distant_follow",1);
}