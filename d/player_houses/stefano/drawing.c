//drawing.c - Stefano's drawing room
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit VAULT;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("A lavish drawing room");
        set_short("A lavish drawing room");
        set_long("%^RED%^Rich red furnishings and decor give this room an "+
           "air of slightly ostentatious wealth. The drapes are e"+
           "%^YELLOW%^d%^RESET%^%^RED%^ged with go%^BOLD%^%^YELLOW%^l"+
           "%^RESET%^%^RED%^d. A pair of comfortable arm chairs sit by "+
           "the large open %^BOLD%^%^RED%^fire%^RESET%^%^RED%^.  These "+
           "look like they are most often used, but another couch and a "+
           "couple of other chairs would give enough seating for a half-dozen "+
           "or so visitors. There are large windows at either end of the room, "+
           "and a chess set sits below the one which looks out over the quiet "+
           "stream. The other window overlooks the gardens, and between them "+
           "they allow plenty of light into the room during the daylight hours.  "+
           "For other times, elegant brass lamps line the walls. They have "+
           "%^BOLD%^%^WHITE%^frosted g%^CYAN%^l%^WHITE%^ass%^RESET%^%^RED%^ "+
           "fronts to make them cast pleasant, diffused light.\n");
        set_smell("default","The room smells of rich fabrics and leather.");
        set_listen("default","There are the faint sounds of the gardens and the stream outside.");
        set_items(([
           (({"chair", "chairs"})) : "The armchairs sit by the fire, with a couple of more simple "+
              "chairs and a couch elsewhere in the room.", 
           (({"armchair", "armchairs"})) : "The two %^RED%^padded armchairs%^RESET%^ drawn up by "+
              "the fire look comfortable. They are clad in red leather to fit in with the rest of the room.", 
		"couch" : "%^RED%^The red leather couch is long enough for three people to sit on, "+
              "or two to lounge comfortably. It has a refined, gently curving shape, with well "+
              "padded arms at either end. It looks to be a solid, heavy piece of furniture.%^RESET%^",
		"chess set" : "The playing board is carved in solid mahogany and sits upon a low table.  "+
              "The white squares are marked out in ivory, and the whole surface polished to a high shine. "+
              "The finely carved pieces are arranged for the start of a game that has not yet begun.",
	      (({"lamp","lamps"})) : "The lamps sit discreetly on the walls, their fine brass fittings "+
               "adding to the air of luxuriant wealth in the room.  Strangely, there seems to be no "+
               "physical way to raise or lower the amount of light in the room.",
            "windows" : "You can look out of either the north or south window.",
            "north window" : "This window looks out ont the fabulous %^BOLD%^%^GREEN%^exotic gardens%^RESET%^ outside.",
            "south window" : "This window looks out over the %^BOLD%^%^CYAN%^crystal "+
               "blue stream%^RESET%^. Further up, you can see the squat grey tower and "+
               "the %^ORANGE%^water wheel%^RESET%^ turning in the stream."
        ]));
       set_exits(([
       "out" : SHOUSE"cottagemain",
       ]));
        set_door("drawing room door",SHOUSE"cottagemain","out",0);
        set_door_description("drawing room door", "A simple wooden door.");
}
void init(){
   ::init();
   add_action("wave_lamps","wave");
}

/*wave lamps should increase or decrease the amount of light in the room by 1 each time */
int wave_lamps(string str) {
   if(!str) {
      tell_object(TP,"Why are you waving?");
      tell_room(ETP,""+TPQCN+" waves "+TP->query_possessive()+" hand in the air strangely.",TP);
      return 1;
   }
   if(str == "up") {
      tell_object(TP,"You wave a hand at the lamps, and they brighten in response.");
      tell_room(ETP,""+TPQCN+" waves "+TP->query_possessive()+" hand at the lamps, and "+
         "they brighten in response.",TP);
      set_property("light",1);
      return 1;
   }
   if(str == "down") {
      tell_object(TP,"You wave a hand at the lamps, and they dim in response.");
      tell_room(ETP,""+TPQCN+" waves "+TP->query_possessive()+" hand at the lamps, and "+
         "they dim in response.",TP);
      set_property("light",-1);
      return 1;
   }
   else return 1;
}