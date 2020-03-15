inherit "std/room";
#include "/d/antioch/areadefs.h"
#include <std.h>

void create(){
  ::create();
  set_light(2);
  set_indoors(1);
    set_property("no teleport",1);
  set_short("A library");
  set_long(
@ANTIOCH
You look around in stunned silence.  Guards surround the edges of the room
and you get the feeling that something very important must be kept here.
You have entered a room filled with books.  There is a small pile of
books on a table in the center of the room that draws your attention.
ANTIOCH
  );
  set_exits(([
  ]));
  set_items(([
    "guards":"They are watching you very closely.",
    "table":"There is a pile of six books on the table.",
    "tome of understanding":"You notice helpful hints on improving your wisdom here.",
    "tome of leadership and influence":"This book would greatly help your charisma.",
    "tome of clear thought":"You would feel more intelligent after reading this book.",
    "manual of bodily health":"Your constitution would benefit from reading this.",
    "manual of gainful exercise":"You see strength-improving ideas as you flip through.",
    "manual of quickness in action":"This could help your dexterity immensely."
  ]));
}

void reset(){
  ::reset();
  TO->remove_exit("out");
}

void init(){
  ::init();
  add_action("look_books","look");
  add_action("take_book","take");
}

int look_books(string str){
  if(str!="books"){
    return 0;
  }
  else{
   tell_object(TP,"%^BOLD%^%^YELLOW%^You see the following books: ");
    tell_object(TP,"  %^BOLD%^Tome of Understanding");
    tell_object(TP,"  %^BOLD%^Tome of Leadership and Influence");
    tell_object(TP,"  %^BOLD%^Tome of Clear Thought");
    tell_object(TP,"  %^BOLD%^Manual of Bodily Health");
    tell_object(TP,"  %^BOLD%^Manual of Gainful Exercise");
    tell_object(TP,"  %^BOLD%^Manual of Quickness in Action\n");
    tell_object(TP,"%^RED%^You may choose only one book to study, "+TPQCN+".");
    tell_object(TP,"%^RED%^Please look at the books to see what they are about.");
    tell_object(TP,"%^RED%^When you have made your selection, please <take> the book.\n");
  return 1;
  }
}

int take_book(string str){
  int estr;
  if(!str){
    notify_fail("Take what?\n");
    return 0;
  }
  if(!TP->query_property("antioch quest")){
    tell_object(TP,"You are not able to do that now.");
    return 1;
  }
  if(str=="tome of understanding"){
    new(OBJT+"wis_manual")->move(TP);
    tell_object(TP,"You take the Tome of Understanding.");
    TP->set_property("antioch quest",0);
    tell_object(TP,"The guards quickly lead you out of the room.");
    TP->move_player(VIL+"quest1");
    return 1;
  }
  if(str=="tome of leadership and influence"){
    new(OBJT+"cha_manual")->move(TP);
    tell_object(TP,"You take the Tome of Leadership and Influence.");
    TP->set_property("antioch quest",0);
    tell_object(TP,"The guards quickly lead you out of the room.");
    TP->move_player(VIL+"quest1");
    return 1;
  }
  if(str=="tome of clear thought"){
    new(OBJT+"int_manual")->move(TP);
    tell_object(TP,"You take the Tome of Clear Thought.");
    TP->set_property("antioch quest",0);
    tell_object(TP,"The guards quickly lead you out of the room.");
    TP->move_player(VIL+"quest1");
    return 1;
  }
  if(str=="manual of bodily health"){
    new(OBJT+"con_manual")->move(TP);
    tell_object(TP,"You take the Manual of Bodily Health.");
    TP->set_property("antioch quest",0);
    tell_object(TP,"The guards quickly lead you out of the room.");
    TP->move_player(VIL+"quest1");
    return 1;
  }
  if(str=="manual of quickness in action"){
    new(OBJT+"dex_manual")->move(TP);
    tell_object(TP,"You take the Manual of Quickness in Action.");
    TP->set_property("antioch quest",0);
    tell_object(TP,"The guards quickly lead you out of the room.");
    TP->move_player(VIL+"quest1");
    return 1;
  }
  if(str=="manual of gainful exercise"){
      new(OBJT+"str_manual")->move(TP);
      tell_object(TP,"You take the Manual of Gainful Exercise.");
    TP->set_property("antioch quest",0);
    tell_object(TP,"The guards quickly lead you out of the room.");
    TP->move_player(VIL+"quest1");
    return 1;
  }

}
