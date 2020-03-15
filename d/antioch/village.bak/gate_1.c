//  Created by Ignatius, for ShadowGate
//  Coded 16 February, 1995
//  Village of Antioch
//  Gates

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
  object ob;
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no castle", 1);
  set_smell( "default","The scent of undead creatures fills the air.\n"  );
  set_listen( "default","A fountain can be heard from here.\n"  );
  set_search( "default",     "You scan the area, but find nothing of value.\n"  );
  set("short",    "Gates of Antioch"     );
  set("long",
      " \n"
    "  You are standing in front of thick stone walls, approximately "
    "twenty feet high, which surround the village of Antioch.  Directly "
    "ahead of you are huge steel and wooden gates allowing the only "
"entry to the village.  Unwanted smells of undead creatures cause a sudden "
"feeling of rage to enter your body.  There is a large stone with an inscription on it here. "
      );
  set_exits( ([
    "east": FOREST+"east_big_road1",
     "enter": VIL+"fount_1",
//    "west": FOREST+"trail7",
    "south":MOUNT+"pass_6"
    ]) );
  set_pre_exit_functions(    ({"enter"}), ({"GoThroughDoor"})  );
  set_items( ([
    ({"walls", "stone walls", "thick walls", "thick stone walls"}):
      "These walls border the impressive gate.  Two towers loom overhead.  "
      "You can just make out movement in the towers.",
    ({"gates", "huge gates", "huge steel and wooden gates"}):
      "The gates stand open, and are nearly twenty feet high.  You see two "
      "towers bordering the gate.",
    ({"village", "Antioch", "village of Antioch"}):
      "The village lies ahead.  You need to enter, though...",
    ({"sign", "golden sign"}):
      "The sign has some writing on it.",
    ({"tower", "towers"}):
      "The towers stand to either side of the gate, offering protection for "
      "the village."
    ]) );
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({ "board", "antioch board"}));
ob->set_board_id("antiochboard");
  ob->set_max_posts(30);
  ob->set_location("/d/antioch/village.bak/gate_1");
  ob->set_short("Antioch Village Board");
  ob->set_long("This board is here for question, comments, errors, typos... pretty much whatever you feel like putting on it.\n\n");
}


int GoThroughDoor() {
  int LEVEL = TP->query_level();
  if(LEVEL < 8) {
    write("%^BLUE%^You must be level 8 or higher to enter the village of Antioch.\n");
    TP->move_player(VIL+"gate_1");
    return 0;
  }
write("%^MAGENTA%^An evil voice yells:%^RESET%^ YOU WILL DIE.\n");
return 1;
}
void init() {
  ::init();
add_action("read_inscriptions", "read");
}

int read_inscriptions(string str) {
write("%^MAGENTA%^A evil voice whispers:%^RESET%^ Enter my village and relive the nightmare that the great god Ignatius once felt as I destroyed him and his army of %^RED%^DEATH!\n");
tell_room(TO,TPQCN+" looks over the stone.\n", TP);
write("The voice morphs into a huge shadow and sucks some energy from you.\n");
tell_room(TO,"A huge shadow forms around "+TPQCN+".",TP);
  TP->do_damage("torso",random(20));
return 1;
}
