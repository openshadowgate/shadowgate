inherit "/std/room";
#include <std.h>
#include "/d/antioch/areadefs.h"

void create() {
     ::create();
     set_light(2);
     set_indoors(1);
     set_search("default",
     "you find nothing."
);
set("short",
"quest room"
);
set("long",
@ANTIOCH
%^RED%^This room is filled with all sorts of creatures.  A man sits in the
corner on a huge throne with a worried look on his face.  Two demon guards
stand next to the man, guarding him with their lives.  The man seems to
want something very badly, yet he does not say a word.  The man in the
throne <%^CYAN%^nods%^RED%^> to you as the guards seem to vanish.
ANTIOCH
);
set_exits( ([
"west"  :"/d/antioch/village/1tower_4.c",
]) );
set_items( ([
({ "man" }):
"The man is sitting in a large throne.",
({ "guard", "guards" }):
"These two guards sit and watch the throne night and day."
]) );
}
void init() {
  ::init();
  add_action("nod","nod");
  add_action("give_wand","give");
}

int nod(string str) {
  if(member_array("Antioch Quest",TP->query_quests())!=-1){
    write("%^BLUE%^You have already solved the quest, "+TPQCN);
    return 1;
  }
write(
"%^MAGENTA%^The man says: %^RESET%^\n"
"%^ORANGE%^Hello, "+TPQCN+".  I must ask for your help in the fight for our village.\n"
"After many years of service to the village of Antioch, our great god\n"
"and protector, Ignatius, has gone completely mad.  In his fits of rage,\n"
"he cast a spell over the village, turning many of its inhabitants into\n"
"undead creatures.  There are some who escaped with their lives, and I am\n"
"sure they are nearby.  However, I have remained to entreat adventurers,\n"
"such as yourself, to help us in the fight to restore our village.  While\n"
"I fear there is little hope left for Ignatius, we may be able to defeat\n"
"him.  I ask you to find the ten elements of power that our god Ignatius\n"
"once had and return his magic wand to me.\n"
);
  tell_room(TO,TPQCN+" nods to the man in the throne.",TP);
return 1;
}

int give_wand(string str){
  object ob;
  if(!str||str!="wand to man")
    return 0;
  if(member_array("Antioch Quest",TP->query_quests())!=-1){
    tell_object(TP,"%^GREEN%^You have already solved the quest, "+TPQCN+"!");
    return 1;
  }
  if(!present("wand",TP)){
    tell_object(TP,"You do not have the wand!");
    return 0;
  }
  if(!(ob=present("assembled wand",TP))){
    tell_object(TP,"Please put the wand together before returning it.");
    return 0;
  }
  else{
    write(
      "The man rises from his throne to take the wand from you.\n"
      "%^MAGENTA%^The man says: %^RESET%^\n"
      "%^BOLD%^%^GREEN%^Thank you, brave "+TPQCN+"! "
      "You have now surely saved our city from complete destruction.  "
      "You shall be well rewarded for this brave accomplishment, my "
      "friend.  Any price is too low for the service you have done "
      "in restoring our hope that we may yet succeed in our fight "
      "for the village of Antioch!\n"
    );
    ob->remove();
    TP->add_exp(100000);
    tell_object(TP,"%^BOLD%^%^YELLOW%^Congratulations, "+TPQCN+"! You have now completed the Antioch Quest.");
    tell_room(environment(TP),"%^MAGENTA%^The man says: %^RESET%^Behold! The mighty "+TPQCN+" has restored our hopes for victory!",TP);
    tell_object(TP,"%^CYAN%^The guards quickly show you into another room.");
    tell_room(environment(TP),TPQCN+" is taken away by the guards.",TP);
    TP->set_property("antioch quest",1);
    TP->move_player(VIL+"library");
    TP->set_quest("Antioch Quest");
    return 1;
  }
}
