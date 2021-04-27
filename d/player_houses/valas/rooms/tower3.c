#include <std.h>
#include <magic.h>
#include <daemons.h>
#include "../defs.h"
inherit "/std/lab";

int triggered, stopped;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(STAIRWAY);
    set_name("Wizard's lab");
    set_short("Wizard's lab");
    set_long("This round onyx room appears to be some kind of a lab.  There are many bookcases against the wall and tables set up with various stages of experiments.  Crates with raw materials are lined up in one end of the room some of them open, others closed.  There are windows about the room that seem to flicker independently. There is a list on the wall.");
    set_smell("default","It smells of chemicals here.");
    set_listen("default","Bubbling and hissing of chemicals come from experiments.");

    set_items(([
        ({"bookcases","bookcase"}) : "They are filled with strange books.",
        "tables" : "Covered with notes and experiments in progress.  A lone list sits on one of them.",
        ({"window","windows"}) : "They tend to flicker oddly."
    ]));
    set_exits(([
        "window1" : "/d/shadow/room/city/adventure",
        "window2" : "/d/darkwood/tabor/room/cnchall",
        "window3" : "/d/darkwood/room/rhapsody",
        "window4" : "/d/shadow/juran/city/inn",
        "down" : ROOMS"tower2",
    ]));
   set_pre_exit_functions(({"window1","window2","window3","window4"}),({"GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor"}));
   setOwner("valas");
   setLabId("Valashouse");
   new("/d/magic/obj/mirror")->move(TO);
   set_search("default",(:TO,"search_me":));
   triggered = 0;
   stopped = 0;
   set_property("magic",1);
}

int GoThroughDoor() {
   if(TP->query_true_invis()) return 1;
   tell_object(TP,"You couldn't fit through that window!");
   return 0;
}

void reset() {
   ::reset();
   triggered = 0;
   stopped = 0;
   if(!present("blade golem")) new("/d/player_houses/valas/mon/bgolem")->move(TO);
}

void init() {
   ::init();
   add_action("twist_me","twist");
   add_action("hatelist","list");
}

int search_me(string str) {
   if(!triggered) {
     tell_object(TP,"As you search around, you hear a soft click.");
     tell_room(TO,""+TPQCN+" searches around the room, and you hear a soft click.",TP);
     tell_room(TO,"A shimmering wave passes over the doors and windows, which suddenly transmutes into solid stone, "
"indistinguishable from the walls.");
     tell_room(TO,"A low hiss heralds the feeling of the air being sucked out of the room.");
     set_exits(([]));
     triggered = 1;
     call_out("choke_me",ROUND_LENGTH);
     return 1;
   }
   if(!stopped) {
     tell_object(TP,"You search around, quickly, and find a small knob on the wall where the doorway once was.  Maybe "
"you could twist it?");
     tell_room(ETP,""+TPQCN+" searches quickly around the room.",TP);
     add_item("knob","There is a small knob on the wall where the doorway once was. Maybe you could twist it?");
     return 1;
   }
   tell_object(TP,"You search carefully around, but find nothing of interest.");
   tell_room(ETP,""+TPQCN+" searches around the room, but finds nothing of interest.",TP);
   return 1;
}

int twist_me(string str) {
   if(triggered && !stopped) {
     if(str != "knob") {
       tell_object(TP,"You can't twist that!");
       return 0;
     }
     tell_object(TP,"You twist the knob, and the hiss of air abruptly stops.  Openings grow within the solid stone walls, "
"reforming the windows and doorway.");
     tell_room(TO,""+TP->QCN+" twists a small knob where the doorway once was, and the hiss of air abruptly stops.  "
"Openings grow within the solid stone walls, reforming the windows and doorway.",TP);
     set_exits(([
       "window1" : "/d/shadow/room/city/adventure",
       "window2" : "/d/darkwood/tabor/room/cnchall",
       "window3" : "/d/darkwood/room/rhapsody",
       "window4" : "/d/shadow/juran/city/inn",
       "down" : ROOMS"tower2",
     ]));
     remove_item("knob");
     stopped = 1;
     return 1;
   }
   return 0;
}

void choke_me() {
   object *myvictims;
   int i;
   if(stopped) return;
   myvictims = all_living(TO);
   myvictims = filter_array(myvictims,"is_non_immortal_player",FILTERS_D);
   if(!sizeof(myvictims)) {
     triggered = 0;
     tell_room(TO,"The hiss of air abruptly stops as the trap resets itself.  Openings grow within the solid stone walls, "
"reforming the windows and doorway.");
     set_exits(([
       "window1" : "/d/shadow/room/city/adventure",
       "window2" : "/d/darkwood/tabor/room/cnchall",
       "window3" : "/d/darkwood/room/rhapsody",
       "window4" : "/d/shadow/juran/city/inn",
       "down" : ROOMS"tower2",
     ]));
     remove_item("knob");
     return;
   }
   tell_room(TO,"The lack of air makes your head spin.");
   for(i=0;i<sizeof(myvictims);i++) myvictims[i]->do_damage("torso",random(20)+20);
   call_out("choke_me",ROUND_LENGTH);
}

int hatelist(string str) {
   object *listed;
   string mymessage, myname;
   int i;
   if(!avatarp(TP) && (string)TP->query_name() != "valas") {
     tell_object(TP,"The list of writing is just garbled characters.  It means nothing to you.");
     tell_room(TO,""+TP->QCN+" glances over the list, but doesn't seem to understand it.",TP);
     return 1;
   }
   if(!str) {
     listed = ({});
     listed += (string *)SAVE_D->query_array("valas_house");
     if(!sizeof(listed)) {
       tell_object(TP,"The list is blank.");
       tell_room(TO,""+TP->QCN+" looks over a blank list on the table.",TP);
       return 1;
     }
     mymessage = listed[i];
     for(i = 1;i<sizeof(listed);i++) {
       mymessage += ", ";
       mymessage += listed[i];
     }
     tell_object(TP,"You read over the list: "+mymessage+".");
     tell_room(TO,""+TP->QCN+" reads over the list.",TP);
     return 1;
   }
   if(str == "purge") {
     if(!sizeof((string *)SAVE_D->query_array("valas_house"))) {
       tell_object(TP,"The list is blank.");
       tell_room(TO,""+TP->QCN+" looks over a blank list on the table.",TP);
       return 1;
     }
     tell_object(TP,"You pass a hand over the list upon the desk, and all the writing fades from it.");
     tell_room(TO,""+TP->QCN+" passes a hand over a scribed list upon the desk, and all the writing fades from it.",TP);
     SAVE_D->remove_array("valas_house");
     return 1;
   }
   if(sscanf(str,"add %s", myname) == 1) {
     if(member_array(myname,(string *)SAVE_D->query_array("valas_house")) != -1) {
       tell_object(TP,"That name is already on the list.");
       tell_room(TO,""+TP->QCN+" reads over the list.",TP);
       return 1;
     }
     SAVE_D->set_value("valas_house",myname);
     tell_object(TP,"You pause to add another name to your list.");
     tell_room(TO,""+TP->QCN+" adds a line of script to the list.",TP);
     return 1;
   }
   tell_object(TP,"Syntax: list, list purge, list add name.");
   return 1;
}