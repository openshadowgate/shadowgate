//cottagemain.c - Main hall of Stefano's cottage
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit VAULT;
int items;
int hidden;

void create() {
items = 1;
hidden = 1;
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("The main hall of a cottage");
        set_short("The main hall of a cottage");
        set_long("This narrower hallway continues south from the entry hall. It is "+
           "brightly lit with lanterns hanging on the white walls. The same "+
           "%^CYAN%^lavendar carpet%^RESET%^ runs through from the entry way, and "+
           "continues up the %^YELLOW%^broad staircase%^RESET%^ at the far end of the "+
           "hall. There are three doors here, two on the western side of the hallway, "+
           "and one opposite them."+
           "\n");
        set_smell("default","You can smell the perfume of the%^BOLD%^%^YELLOW%^ roses.%^RESET%^");
        set_listen("default","The sounds of the %^BOLD%^%^GREEN%^garden%^RESET%^%^GREEN%^ filter in from outside.");
        set_items(([
            (({"staircase", "stairs"})) : "A broad, solid staircase with a sturdy bannister.", 
           "bannister" : "The bannister is a simple, sturdy handrail suppoted by a series of "+
               "upright poles from the stairs.", 
		"poles" : "A series of upright poles supporting the bannister handrail.",
		"painting" : "The large oil painting is a mass of %^CYAN%^blues%^RESET%^, "+
               "%^BOLD%^%^WHITE%^whites%^RESET%^, greys and %^YELLOW%^browns%^RESET%^.  It "+
               "depicts a busy trading harbour with ships and boats from tiny caravels through "+
               "to large, triple-masted barques. To one side of the foreground, an auction is "+
               "underway at a fish market. The artist must havehad some talent as the rough, dabbing "+
               "strokes of the brush manage to give a real feeling of the hectic, blustery nature of "+
               "the scene, even though very little fine detail is actually depicted.",
        ]));
        set_exits(([
       "north" : SHOUSE"entrancehall", 
       "up" : SHOUSE"landing",
       "kitchen" : SHOUSE"kitchen",
       "dining" : SHOUSE"dining",
       "drawing" : SHOUSE"drawing"
   ]));
        set_door("kitchen door",SHOUSE"kitchen","kitchen",0);
        set_door_description("kitchen door", "A simple wooden door.");
        set_door("door",SHOUSE"dining","dining",0);
        set_door_description("door", "A simple wooden door.");
        set_door("drawing room door",SHOUSE"drawing","drawing",0);
        set_door_description("drawing room door", "A simple wooden door.");
   set_search("poles","Looking closely, you see that one of the poles looks very slightly loosened.  "+
      "You might be able to twist it.");
   set_search("stairs", (: TO, "search_stairs" :) );
   set_search("staircase", (: TO, "search_stairs" :) );
}

void init() {
   ::init();
   add_action("twist","twist");
}

/* Twisting the pole should allow you to find a key to open the stairs */
int twist(string str) {
   if(str != "pole" && str != "poles") {
      tell_object(TP,"What are you trying to twist?");
      return 1;
   }
   if((items > 0)) {
      tell_object(TP,"Twisting the pole a half turn reveals a small hidden compartment.  "+
         "An iron key drops into your hand.");
      tell_room(ETP,"You watch as "+TPQCN+" twists a pole in the bannister and retrives an iron key.",TP);
      new(OBJ"rune_key")->move(TP);
      items = 0;
      return 1;
   }
   else{
      tell_object(TP,"Twisting the pole a half turn reveals a small hidden compartment.  "+
        "Unfortunately, nothing is hidden there.");
      tell_room(ETP,"You watch as "+TPQCN+" twists a pole in the bannister.",TP);
      return 1;
   }
}
/* STEFANO HAS PLANS TO MAKE THE CUPBOARD UNDER THE STAIRS CONNECT VIA TUNNEL TO THE TOWER BUT THIS IS NOT TO BE PUT IN RIGHT AWAY - 

int search_stairs(){
   if(member_array("cupboard",ETP->query_exits()) != -1) {
      tell_object(TP,"The hidden door leading to the cupboard is already clearly visible!");
      return 1;
   }
   else{
   tell_object(TP,"After carefully running your fingers along the wall beneath the stairs, "+
      "you find a cleverly concealed doorway.");
   tell_room(ETP,""+TPQCN+" leans close to the wall and seems to be running "+TP->query_possessive()+" "+
      "fingers along it.",TP);
   add_exit(SHOUSE"cupboard","cupboard");
   return 1;
   }
}
int cupboard(){
   if(present("iron_key",TP)){
      tell_object(TP,"You carefully use the iron key to first lock, then unlock the door

search staircase/search stairs: Careful examination of the staircase reveals a hidden door in the side (new exit, stair door, leading to CUPBOARD UNDER THE STAIRS appears. The stair door is locked, and trapped with a very nasty poisoned needle trap. It can be unlocked by the iron key hidden in the bannister, but to avoid setting the trap, you must first turn the key in the reverse direction by typing <lock stair door with iron key> before trying to <unlock stair door with iron key> doing this in the wrong order, or using any other key will set off the trap.)*/
