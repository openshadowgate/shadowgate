#include <std.h>
#include "/realms/lujke/tecqumin/tecqumin.h"
#define WEMIC "/realms/lujke/wemic/rooms/"
inherit OBJ + "maze_builder3.c";

void create(){
  ::create();
  roompath = JUNG_ROOM2;
  start_x = 5; 
  start_y = 5;
  mazename = "j_maze";
  gridsize = 50;
  set_special_rooms( ({ }) );
  door_chance = 0;
  set_southroom(JUNG_ROOM + "j_link1a.c");
  set_northroom(JUNG_ROOM2 + "j_link2.c");
  set_eastroom(ROOMS + "step01.c");
}

void init(){
  ::init();
  add_action("make_maze", "create");
  add_action("clear_maze", "clear");
  add_action("place", "place");

}

int make_maze(string str){
  init_maze(start_x, start_y, mazename, gridsize);
  tell_object(TP,"Okay, you built a maze");
  return 1;
}
