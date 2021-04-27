#include <std.h>
#include "../yuki.h"

inherit STORAGE"hallway.c";

void init(){
   ::init();
   add_action("push","push");
}
void create(){
   ::create();
   set_long(::query_long()+"%^BLACK%^%^BOLD%^The hallway ends here "+
   "with a %^RESET%^%^ORANGE%^door%^BLACK%^%^BOLD%^ The volcanic bricks "+
   "here are smoother then the rest of the hallway, as if more care was "+
   "taken. On the south wall a large painting hangs.\n");
   set_exits(([
      "west" : ROOMS"h1",
      "east" : ROOMS"priv1",
		  
   ]));
       add_item(({"painting","south painting"}),"%^RESET%^%^RED%^A foggy red "+
	   "mist overtakes a still %^BLUE%^lake. %^RED%^In the water, swims "+
	   "a %^MAGENTA%^magnificent %^BOLD%^%^BLACK%^black swan. %^RESET%^%^RED%^T"+
	   "here are other %^CYAN%^smaller swans %^RED%^and wildlife sharing the "+
	   "lake but each %^WHITE%^pales %^RED%^in comparison to the %^BOLD%^%^BLACK%^"+
	   "dark ruler %^RESET%^%^RED%^of the %^BLUE%^water. %^RED%^Near the bank of "+
	   "the %^CYAN%^lake %^RED%^is a group of various %^BLUE%^men %^RED%^an"+
	   "d %^MAGENTA%^women %^RED%^all holding a %^BOLD%^%^BLACK%^b%^WHITE%^"+
	   "e%^BLACK%^a%^WHITE%^u%^BLACK%^t%^WHITE%^i%^RESET%^f%^WHITE%^u%^BOLD%^%^BLACK%^"+
	   "l dark feather%^RESET%^%^RED%^A the bottom of the painting are the "+
	   "initials A. K%^RESET%^");
	   add_item(({"bricks","volcanic bricks"}),"%^BLACK%^%^BOLD%^The bricks here are "+
	   "smoother, and much more care has been placed in their arrangement. "+
	   "Perhaps because of the locked door. Only one is rough.%^RESET%^");
	   add_item(({"rough brick"}),"%^BLACK%^%^BOLD%^One brick near the door is "+
	   "rough, and seems loose%^RESET%^");
	   
	set_door("wooden door",ROOMS"priv1","east","yuki_key");
        set_locked("wooden door",1);

    set_door_description("wooden door","%^ORANGE%^This heavy oak door looks very sturdy.%^RESET%^");
    set_string("wooden door", "open", "%^ORANGE%^The heavy door opens quietly.%^RESET%^");
    set_string("wooden door", "close", "%^ORANGE%^The heavy door closes without a sound.%^RESET%^");

}


int push(string str){

   if(!str || str != "rough brick") return notify_fail("push what?\n");

   write("%^BLACK%^%^BOLD%^You push the rough brick and hear a soft click.%^RESET%^");
   tell_room(TO,"%^BLACK%^%^BOLD%^A section of the wall to the north slides open.%^RESET%^");

   add_exit(ROOMS"sec1","north");
   return 1;
}


void reset(){
   ::reset();
   remove_exit("north");
}

