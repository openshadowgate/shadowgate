//boat.c

#include <std.h>

#define SHADOW_SEA "/d/shadow/virtual/sea/"+
#define DAGGER_SEA "/d/dagger/virtual/sea/"+
#define DOCKS ([ "shadow":SHADOW_SEA "36,0.sea", "deku":SHADOW_SEA "16,20.sea", "laerad":SHADOW_SEA "36,20.sea",\
           "hmquest":SHADOW_SEA "16,45.sea", "attaya":SHADOW_SEA "43,28.sea", "eldebaro":SHADOW_SEA "51,7.sea",\
            "dallyh":SHADOW_SEA "13,22.sea",\
           "aramanth":SHADOW_SEA "58,23.sea", "tonerra":SHADOW_SEA "26,40.sea", "undead":SHADOW_SEA "16,8.sea",\
        "torm":DAGGER_SEA "5,1.sea",\
             "argentrock":SHADOW_SEA "10,34.sea", "dino":SHADOW_SEA "20,30.sea","raiders":DAGGER_SEA "20,19.sea", "pirate":SHADOW_SEA "55,0.sea" ])
inherit OBJECT;

object boat_room;
string owner;

void create() {
   set_name("small boat");
   set_property("no animate",1);
   set_short("Small boat");
   set_id(({"boat","small boat","ship","small ship"}));
   set_long("This is a small boat for transporting players and materials.");
   set_weight(100000);
   call_out("make_me",1);
   owner = "noone";
}

void init() {
   ::init();
   add_action("board","board");
}

void set_inside(object room) {
   boat_room = room;
}

object query_room() {return boat_room;}

int clean_up() {return 1;}

void make_me() {
   string file, place;
   int x,y;
   if(!objectp(ETO)) {
      call_out("make_me",1);
      return;
   }

   file = base_name(ETO);
   if(file[0..16] != "/d/shadow/virtual")
      TO->remove();
   seteuid(getuid(TO));
   if(!objectp(boat_room)) {
      boat_room = new("/d/shadow/virtual/sea/obj/boatroom");
      boat_room->set_boat(TO);
   }
   /*
   if((sscanf(file,"/d/shadow/virtual/%d,%d.sea",y,x)) ||
      (sscanf(file,"/d/shadow/virtual/sea/%d,%d.sea",x,y))) {
      boat_room->set_x(x);
      boat_room->set_y(y);
   }
   else
   */
   if(sscanf(file,"/d/shadow/virtual/sea/%s.dock",place)) {
      if(member_array(place, keys(DOCKS)) != -1) {
         //boat_room->set_x(DOCKS[place][1]);
         //boat_room->set_y(DOCKS[place][0]);
         boat_room->set_room(DOCKS[place]);
      }
      else {
         log_file("/d/shadow/virtual/sea/obj/new_docks",
                  "New dock found: "+place+"\n");
         remove();
      }

   }
   else {
      boat_room->set_room(file);
   }
}

int board(string str) {

   if(!id(str))
     if (TO != present(str,ETO))
       return 0;
   tell_room(ETP,"%^BOLD%^"+TPQCN+" boards a small boat.",TP);
   write("%^BOLD%^You board a boat.");
   TP->move_player(boat_room);
   return 1;
}

void remove() {
   if(objectp(boat_room)) {
      if(present("player",boat_room)) return;
   }
   if(boat_room && objectp(boat_room))
      boat_room->remove();
   return ::remove();
}

void set_owner(string str) {
   owner = str;
   add_id(str+"'s boat");

   boat_room->set_owner(str);
}

string query_owner() {
   return owner;
}

