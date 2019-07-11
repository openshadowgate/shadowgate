//eldath.c - eldathyn grove redesigned by selve. Nienne, 12/06.
#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
   set_name("A quiet grove");
   set_short("%^RESET%^%^GREEN%^A quiet grove%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","The air is filled with the scents of the forest.");
   set_listen("default","The spring bubbles in a soothing manner.");
   set_property("fill waterskin",1);
   if(base_name(TO) == "/d/magic/temples/eldath") {
     set_items(([
       ({"spring"}) : "%^GREEN%^The %^BOLD%^%^CYAN%^spring%^RESET%^%^GREEN%^ bubbles to life here, trickling into a quiet stream that winds its way through the grove.%^RESET%^",
     ]));
   }
   set_exits( ([
     "north" : "/d/antioch/vale/forest/aash_trail1",
     "out" : "/d/antioch/wild/forest/trail6"
   ]) );
/*   set_items(([
      "wall":"You see Eldath's charge to her followers on the wall.",
      "charge":"Maybe you should read it.",
   ]));
*/
}

void reset() {
   if(base_name(TO) == "/d/magic/temples/eldath") {
     if(!present("statue")) new("/d/magic/obj/eldathstatue")->move(TO);
   }
}

string ldesc() {
   if(base_name(TO) == "/d/magic/temples/eldath") {
     return("%^BOLD%^%^CYAN%^Grove of Tranquility\n%^RESET%^"
"%^GREEN%^Pushing through the forest, you come upon a %^BOLD%^verdant green "
"%^RESET%^%^GREEN%^paradise.  Lush foliage and grass thrive with a healthy "
"radiance here.  A %^BOLD%^%^CYAN%^spring %^RESET%^%^GREEN%^bubbles to life, "
"trickling out to become a stream that meanders through the grove.  Resting "
"at the base of the spring is a %^BOLD%^%^WHITE%^crystalline "
"statue%^RESET%^%^GREEN%^.  Hugging close to the stream are delicate "
"%^CYAN%^ferns %^GREEN%^that sway softly.  The canopy of trees provides shade "
"to the grove, with streams of "
"%^YELLOW%^l%^WHITE%^i%^YELLOW%^g%^WHITE%^h%^YELLOW%^t "
"%^RESET%^%^GREEN%^filtering in.  All about you a peaceful "
"%^BOLD%^%^CYAN%^tranquility %^RESET%^%^GREEN%^hangs in the air.%^RESET%^");
   }
   else {
     return("%^BOLD%^%^GREEN%^A Quiet Grove\n%^RESET%^"
"You are standing in a peaceful grove, surrounded by trees. A stream borders "
"the grove, surrounded by tall trees.  The bubbling stream is a crystalline "
"blue that dances over the rocks, and the banks of the stream are grassy and "
"soft.  Strangely, a somber feeling hangs in the air here, despite the quiet "
"serenity and beauty of the grove.");
   }
}

void init(){
   ::init();
   //add_action("read_charge","read");
//   add_action("buy_em","bw");
}

int buy_em(int x){
   if(!x) return 0;
   tell_object(TP,"There is no longer any holy water for Eldath here.");
   return 1;
}

/*
int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
Eldath charges her followers with this message:

Peace cannot be taught or imposed, it must come from within and can only 
be reached through thought and meditation. Seek stillness and thereby find 
peace. Plant trees and green-leaved things and tend such things when they 
need it. Nurture and aid, do not restrict or punish. Work violence only to 
defend, and slay no thing of the forest save to prevent it from slaying 
yourself or another under your protection. Aid fellow Eldathyn and clergy 
of Silvanus and Mielikki whenever possible, and give assistance, support, 
and shelter to displaced forest dwellers. Share with all beings the 
beneficial things that grow in or come from running water that all may  
know of and praise Eldath.
CHARGE
   );
   if((string)TP->query_diety() == "eldath" || avatarp(TP))
   write(
@EXTRA
===========================================================================

As a follower of Eldath ...
  allied deities are: Mielikki, Silvanus, Selune, Lathander
  enemy deities are: Malar, Loviatar, Talos

This is information only followers of Eldath should know.
EXTRA
   );
   return 1;
}
*/
