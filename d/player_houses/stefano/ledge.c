//ledge.c - The added ledge for Stefano's tower - Coded by Circe 9/13/03
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit VAULT;
//int FLAG = 0;  //not needed anymore
int dead_mat = 0;

void create(){
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(VILLAGE);
   set_travel(FOOT_PATH);
   set_name("A narrow ledge");
   set_short("A narrow ledge");
   set_long(
      "This narrow ledge is only about three feet wide.  It "+
      "juts out from the side of the tower about halfway up, "+
      "and is completely devoid of decoration save for a simple "+
      "doormat and a door leading into the tower."+
      "\n"
   );
   set_smell("default","You can smell the sweet perfume of the %^BOLD%^%^BLUE%^f%^WHITE%^l%^MAGENTA%^o%^WHITE%^w%^BLUE%^e%^WHITE%^r%^MAGENTA%^s%^RESET%^%^ORANGE%^, and the scent of the %^BOLD%^%^GREEN%^fresh cut grass%^RESET%^.");
   set_listen("default","You can hear the babble of the stream flowing by and the creak of the slowly turning water wheel.");
   set_items(([
      ({"doormat","mat","door mat"}) : "Burned into the coarse bristles is the legend:\n"+
         "\n"+
         "      %^BOLD%^%^BLACK%^Welcome%^RESET%^\n"+
         "\n"+
         "  %^BOLD%^%^BLACK%^Wipe Your Feet.%^RESET%^",
      "face" : "The face in the door is minimal in detail, just a mouth, nose, eyes and "+
         "eyebrows carved into the wood. The features are artfully done, though and its "+
         "expression manages to almost look pleased to see you without quite being sincere.",
      ({"garden","gardens","below","ground"}) : "The ground below seems very far away, and "+
         "there doesn't seem to be a ready way down, unless you can levitate or climb.  Hrm..."+
         "you could perhaps jump, but that seems risky."
   ]));
   set_exits(([
      "tower" : SHOUSE"tower_lounge",
   ]));
   set_climb_exits(([
      "descend" : ({SHOUSE"garden1",20,3,100})
   ]));
   set_door("door",SHOUSE"tower_lounge","tower",0);
   set_door_description("door","The blackened oak door sits in an archway. It is banded "+
      "with iron reinforcing and has a large iron knocker. There is a face carved into the "+
      "wood at about eye level for a human. It has a slightly sardonic expression.");
   set_pre_exit_functions(({"tower"}),({"GoThroughDoor"}));
}

void init(){
   ::init();
   add_action("wipe_feet","wipe");
   add_action("push","push");
   add_action("shove","shove");
   add_action("force","force");
   add_action("hit_face","hit");
   add_action("touch","touch");
   add_action("poke","poke");
   add_action("knock_em","knock");
   add_action("levitate","levitate");
   add_action("jump","jump");
}

/*%^BOLD%^%^WHITE%^This should call a door mat that has been enchanted to protect the tower.  There is no lock on the door - the mat is the major means of protection.  The mat can be deactivated by wiping your feet on it (see below)%^RESET%^*/

int GoThroughDoor()
{
object guard;
   if(TP->query_invis()) return 1;
   if(TP->query_property("wiped")){
      TP->remove_property("wiped");
      return 1;
   }
   if(dead_mat){
      if(present("door mat")) {
         tell_room(ETP,"%^ORANGE%^The door mat is blocking the entrance!");
         return 0;
      }
      return 1;
   }
   else{
      if(present("door mat")) {
         tell_room(ETP,"%^ORANGE%^The door mat is blocking the entrance!");
         return 0;
      }
      tell_room(ETP,"%^ORANGE%^The coarse brown doormat comes to life and begins to struggle!");
      guard = new(MON"door_mat");
      guard->move(TO);
      guard->force_me("block tower");
      dead_mat = 1;
      return 0;
   }
}

int wipe_feet(string str){
   if(str != "feet"){
      tell_object(TP,"You might want to try wiping your feet.");
      return 1;
   }
   else{
      tell_object(TP,"You wipe your feet carefully on the doormat.");
      tell_room(ETP,""+TPQCN+" wipes "+TP->query_possessive()+" feet on the doormat.",TP);
      TP->set_property("wiped",1);
      return 1;
   }
}

int push(string str) {
   if(!str){
      tell_object(TP,"What are you trying to push?");
      return 1;
   }
   if(str == "door") {
      tell_object(TP,"You push hard against the door, but it doesn't move.");
      tell_room(ETP,""+TPQCN+" pushes hard against the door, but it doesn't move.",TP);
      return 1;
   }
   if(str == "face"){
      tell_object(TP,"The face regards you woodenly.");
      tell_room(ETP,""+TPQCN+" pokes the face with "+TP->query_possessive()+" finger, "+
         "but the face regards "+TP->query_objective()+" woodenly.",TP);
      return 1;
   }
   else return 0;
}

int shove(string str) {
   if(!str) {
      tell_object(TP,"What are you trying to shove?");
      return 1;
   }
   if(str == "door") {
      tell_object(TP,"You push hard against the door, but it doesn't move.");
      tell_room(ETP,""+TPQCN+" pushes hard against the door, but it doesn't move.",TP);
      return 1;
   }
   else return 0;
}

int force(string str) {
   if(!str) {
      tell_object(TP,"What are you trying to force?");
      return 1;
   }
   if(str == "door") {
      tell_object(TP,"You push hard against the door, but it doesn't move.");
      tell_room(ETP,""+TPQCN+" pushes hard against the door, but it doesn't move.",TP);
      return 1;
   }
   else return 0;
}

int hit_face(string str) {
   if(!str) {
      tell_object(TP,"What are you trying to hit?");
      return 1;
   }
   if(str == "face"){
      tell_object(TP,"The face regards you woodenly.");
      tell_room(ETP,""+TPQCN+" hits the face with "+TP->query_possessive()+" hand, "+
         "but the face regards "+TP->query_objective()+" woodenly.",TP);
      return 1;
   }
   else return 0;
}

int touch(string str) {
   if(!str) {
      tell_object(TP,"What are you trying to touch?");
      return 1;
   }
   if(str == "face"){
      tell_object(TP,"The face regards you woodenly.");
      tell_room(ETP,""+TPQCN+" touches the face with "+TP->query_possessive()+" finger, "+
         "but the face regards "+TP->query_objective()+" woodenly.",TP);
      return 1;
   }
   else return 0;
}

int poke(string str) {
   if(!str) {
      tell_object(TP,"What are you trying to poke?");
      return 1;
   }
   if(str == "face"){
      tell_object(TP,"The face regards you woodenly.");
      tell_room(ETP,""+TPQCN+" pokes the face with "+TP->query_possessive()+" finger, "+
         "but the face regards "+TP->query_objective()+" woodenly.",TP);
      return 1;
   }
   else return 0;
}

int knock_em(string str) {
   if(str != "on door" && str != "door" && str != "on the door") {
      tell_object(TP,"Maybe you should try to knock on the door?");
      return 1;
   }
   tell_object(TP,"You raise the iron knocker and let it fall against the door with a heavy thud.");
   if(!present("door knocker")){
      new(MON"door_knocker")->move(TO);
   }
   return 1;
}

int levitate(string str) {
   if(!str){
      if(TP->is_class("mage") || TP->is_class("bard")) {
         tell_object(TP,"As you set your mind to the task of lowering your body downwards, "+
            "the air currents eddying around the tower suddenly come together and lift you "+
            "up, then lower you gently to the ground below.");
         tell_room(ETP,""+TPQCN+" frowns in concentration and takes a deep breath, then begins "+
            "to lower through the air, landing gently on the ground below!",TP);
         TP->move(SHOUSE"garden1");
         TP->force_me("look");
         return 1;
      }
      else{
         tell_object(TP,"Scowling with concentration, you set your mind to try to lower your body, "+
            "and give a little hop to help it get the idea. Sadly, nothing happens and you drop "+
            "back to the floor feeling slightly foolish.");
         tell_room(ETP,""+TPQCN+" scowls deeply and hops a few times with "+TP->query_possessive()+" "+
            "eyes set on the garden below, then stops and glances around with a slight blush.",TP);
         return 1;
      }
   }
   else{
      tell_object(TP,"You can't levitate that!");
      return 1;
   }
}

int jump(string str){
   if(!str){
      tell_object(TP,"You decide to take a flying leap off the ledge, landing in a painful heap "+
         "on the ground below!");
      tell_room(ETP,""+TPQCN+" gets a mad look in "+TP->query_possessive()+" eyes and suddenly "+
         "leaps off the ledge!",TP);
      TP->do_damage("torso",random(25)+20);
      TP->add_attacker(TO);
      TP->continue_attack();
      if(!objectp(TP)) return 1;
      TP->remove_attacker(TO);
      TP->move(SHOUSE"garden1");
      TP->force_me("look");
      return 1;
   }
   return 0;
}
