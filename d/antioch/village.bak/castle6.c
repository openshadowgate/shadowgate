// /d/antioch/castle/castle6.c

inherit "/std/room";
#include <std.h>
#include "/d/antioch/areadefs.h"

int done;

void create() {
     ::create();
     set_light(2);
     set_indoors(3);
     set_short("castle.\n");
     set_long(
     " \n"
"%^BOLD%^You are in the Castle of Antioch!%^RESET%^\n"
"You are in what looks to be a hall.  Many deceiving paintings hang from "
"the walls which seem to be looking at you.  The ground here is made out of "
"stone, which has been hand carved with some sort of tool.  The walls here " 
"are also made out of that same type of stone causing the castle to be very "
"warm in the day time and very cold at night.\n"
);
     set("night long",
     "\n"
"%^BOLD%^You are in the Castle of Antioch!%^RESET%^\n"
"%^CYAN%^It is very cold.\n"
"You are in what looks to be a hall.  Many deceiving paintings hang from "
"the walls which seem to be look straight at you.  The ground here is made "
"out of stone, which has been hand carved with some sort of magical tool. "
"The walls here are also made out of that same type of stone causing the "
"castle to be very warm in the day, and very cold at night.\n"
);
     set_smell("default", "You can smell the stones.\n");
  set_exits(([
    "west":CASTLE+"castle5",
    "north":CASTLE+"castle7"
  ]));
  set_items(([
    "paintings":"One of the paintings is a little crooked.  Perhaps you should straighten it."
  ]));
}

void init() {
  ::init();
  done=0;
  do_random_encounters(({
    MON+"zombie",
    MON+"painting"
  }),50, 1);
  add_action("go_north","north");
  add_action("straighten_painting","straighten");
}

void reset(){
  ::reset();
  done=0;
}

int go_north(string str){
  if(present("zombie")){
    write("The zombie blocks your way north.\n");
    return 1;
  }
  if(present("guard")){
    write("The guard blocks your way north.\n");
    return 1;
  }
}

int straighten_painting(string str){
  if(!str){
    tell_object(TP,"Straighten what?");
    return 1;
  }
  if(str!="painting"){
    tell_object("You can't straighten that.");
    return 1;
  }
  if(!done){
    tell_object(TP,"As you straighten the painting, a small object falls to the ground.\n");
    tell_room(TO,"As "+TPQCN+" straightens the painting, a small object falls to the ground.\n",TP);
    new(OBJT+"yellow")->move(TO);
    done = 1;
    return 1;
  }
  else{
    tell_object(TP,"You straighten the painting.\n");
    tell_room(TO,TPQCN+" straightens a painting.\n",TP);
    return 1;
  }
}
