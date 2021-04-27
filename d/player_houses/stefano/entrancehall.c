//entrancehall.c - Entry hall to Stefano's cottage
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit VAULT;
int aside;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("A Cottage Entrance Hall");
        set_short("A Cottage Entrance Hall");
        set_long("%^BOLD%^%^WHITE%^Two large bay windows sit either side of the front "+
           "door to the cottage, looking out onto the garden. The hallway is bright and "+
           "air with white walls and a %^RESET%^%^CYAN%^lavendar carpet%^BOLD%^%^WHITE%^.  "+
           "A painting decorates the east wall, and some %^BOLD%^%^YELLOW%^yellow roses"+
           "%^BOLD%^%^WHITE%^ sit in a vase on a small table by the door. There is a brown "+
           "mat by the door, for wiping your feet on. An elegantly dressed footman stands by "+
           "the southern entrance which leads further into the cottage."+
           "\n"
        );
        set_smell("default","You can smell the perfume of the %^BOLD%^%^YELLOW%^roses.%^RESET%^");
        set_listen("default","The sounds of the %^BOLD%^%^GREEN%^garden%^RESET%^%^GREEN%^ filter in from outside");
        set_items(([
            (({"window", "windows"})) : "The windows are large, and made with leaded glass. On "+
               "a sunny day, they allow a great deal of light and warmth into the entrance hall.  "+
               "Outside, you can see the %^BOLD%^%^GREEN%^beautifully kept gardens%^RESET%^, and the "+
               "strange square stone building to the north.", 
           "roses" : "the %^BOLD%^%^YELLOW%^gorgeous yellow roses%^RESET%^ are in full bloom and smell "+
               "wonderful. They are displayed in a beautiful vase of fine cut crystal.",
           "table" : "A simple round table with a single carved leg at the center, above a circular base.  "+
               "There is a vase of %^BOLD%^%^YELLOW%^flowers%^RESET%^ displayed on it.",
           "painting" : "The large oil painting is a mass of %^CYAN%^blues%^RESET%^, "+
               "%^BOLD%^%^WHITE%^whites%^RESET%^, greys and %^YELLOW%^browns%^RESET%^.  "+
               "It depicts a busy trading harbour with ships and boats from tiny caravels "+
               "through to large, triple-masted barques. To one side of the foreground, an "+
               "auction is underway at a fish market. The artist must havehad some talent as "+
               "the rough, dabbing strokes of the brush manage to give a real feeling of the "+
               "hectic, blustery nature of the scene, even though very little fine detail is actually "+
               "depicted.",
            ({"doormat","mat","door mat"}) : "A high quality, durable doormat with the word 'welcome' cut into it."
        ]));
        set_exits(([
           "south" : SHOUSE"cottagemain", 
           "out" : SHOUSE"garden2"
   ]));
        set_pre_exit_functions(({"south"}),({"go_south"}));
        set_door("cottage door",SHOUSE"garden2","out",0);
        set_door_description("cottage door", "A simple arched oak door leading back out to the garden.");
   aside = 0;
}

void init() {
   ::init();
   if(!present("raphael")) {
      new(MON"raphael")->move(TO);
   }
   add_action("wave_aside","wave");
}

/*This should allow Stefano and Immortals to pass.  Anyone else has to have Stefano tell Raphael to stand aside, which allows one person only to pass.*/

int go_south() {
   string mname=TP->query_name();
   if(!present("raphael")){
      return 1;
   }
//   if((wizardp(TP)) || (mname == "stefano")){
   if(avatarp(TP) || member_array(mname,PGUESTS) != -1 || member_array(mname,POWNERS) != -1){
      return 1;
   }
   if(aside){
   tell_object(TP,"The footman smiles and steps aside, allowing you to pass.");
   aside = 0;
   return 1;
   }
   tell_object(TP,"The footman blocks your way, refusing to let you enter the house.");
   tell_room(ETP,"The footman steps in the doorway, refusing to let "+TPQCN+" pass.",TP);
   return 0;
}

int wave_aside(string str){
   string mname=TP->query_name();
   if(str != "aside"){
      return 0;
   }
//   if((wizardp(TP)) || (mname == "stefano")){
   if(avatarp(TP) || member_array(mname,PGUESTS) != -1 || member_array(mname,POWNERS) != -1){
      tell_object(TP,"You wave the footman aside, and he allows your companion to pass.");
      tell_room(ETP,""+TPQCN+" waves "+TP->query_possessive()+" hand, and the footman stands aside.",TP);
      aside = 1;
      return 1;
   }
   return 0;
}
