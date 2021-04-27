#include <std.h>
#include <daemons.h>

inherit VAULT;
#define OWNERS ({"slore", "mystra"})
string *killers;
string *allowed;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("A backroom");
    set_long(
"Entering this room you might have expected to find a storeroom, but instead "
"it looks more like an entry room to a house.  On either side of the southern "
"door is a large golem statue and there is a large rug covering the floor."
    );
    set_listen("default","You hear muffled sounds from outside.");
    set_smell("default","The smell that's been haunting you is terribly close.");
    set_items(([
      "rug" : "This rug is hand woven and very large.  A scene very similar to "
         "that on the outside door is woven into the rug.  It depicts an old "
         "wizard, stave in one hand and book in the other, looking up at a "
         "%^YELLOW%^waning moon%^RESET%^.  He appears to be reciting something."
    ] ));
    set_exits(([
       "south" : "/d/player_houses/slore/library",
       "west" : "/d/player_houses/slore/comp_store",
    ] ));
   set_door("door","/d/player_houses/slore/comp_store","west",0,"ornate lock");
   set_door_description("door","This is a normal looking door with "
     "locks that allow you to go out without a key but will lock behind "
     "you after if the lock is set.");
//  set_lock_description("door","ornate lock","This is an ornate lock.  "
//       "At first glance it looks mostly ornamental.");
   set_locked("door",1,"ornate lock");
   set_door("heavy door","/d/player_houses/slore/library","south","slore key",
       "steel lock");
   set_door_description("heavy door","This is a heavy panel door.  There are "
     "several glyphs scratched on this side in some sort of arcane code.");
   set_lock_description("heavy door","steel lock","This is a heavy, complex "
       "steel lock with at least four tumblers.");
   set_locked("heavy door",1,"steel lock");
   lock_difficulty("heavy door", "/daemon/player_housing"->get_phouse_lock_dc("epic"),"steel lock");
   set_pre_exit_functions( ({"south"}), ({"GoThroughDoor"}) );
   
}

void init() {
   ::init();
   add_action("unlock_me","waves");
   add_action("record","record");
    add_action("pardon_em", "pardon");
    add_action("check_attackers", "check");
}

void unlock_me(string str) {
   if(str != "hands" && str != "hands twice") return 0;
   if( (member_array((string)TPQN,OWNERS) == -1) && !avatarp(TP)) return 0;
   tell_object(TP,"You wave your hands over your eyes, leaving them a "
        "bright-silver color momentarily and you hear the lock click.");
   tell_room(ETP,""+TPQCN+" waves her hands over her eyes, leaving them a "
        "bright-silver color momentarily as you hear a soft click.",TP);
   if(str == "hands") {
     find_object_or_load("/d/player_houses/slore/comp_store");
     if(!query_locked("door","ornate lock")) {
       TO->set_open("door",0);
       TO->set_locked("door",1,"ornate lock");
       "/d/player_houses/slore/comp_store"->set_locked("door",1,"ornate lock");
       "/d/player_houses/slore/comp_store"->set_open("door",0);
       return 1;
     }
     TO->set_locked("door",0, "ornate lock");
     "/d/player_houses/slore/comp_store"->set_locked("door",0,"ornate lock");
     return 1;
   }
   if(str == "hands twice") {
     find_object_or_load("/d/player_houses/slore/library");
     if(!query_locked("heavy door","steel lock")) {
       TO->set_open("heavy door",0);
       TO->set_locked("heavy door",1,"steel lock");
       "/d/player_houses/slore/library"->set_locked("heavy door",1,"steel lock");
       "/d/player_houses/slore/library"->set_open("heavy door",0);
       return 1;
     }
     TO->set_locked("heavy door",0,"steel lock");
     "/d/player_houses/slore/library"->set_locked("heavy door",0,"steel lock");
     return 1;
   }
}

void reset() {
   ::reset();
   if(!present("clay golem"))  
      new("/d/player_houses/slore/misc/sgolem")->move(TO);
   if(!present("clay golem 2"))  
      new("/d/player_houses/slore/misc/sgolem")->move(TO);
}

int GoThroughDoor() {
   allowed = SAVE_D->query_array("slore_backroom_ok");
   if(query_verb() == "west")                 
       return ::GoThroughDoor();
   if(avatarp(TP) && TP->query_true_invis())  return 1;
   if(member_array(TPQN,allowed) != -1)       return 1;
	if(!present("clay golem"))                 return 1;
	tell_object(TP,"The golem steps in front of the door and blocks your way!");
	tell_room(ETO,"The golem steps in front of the door and "
	   "blocks "+TPQCN+"'s way!",TP);
	return 0;   
}
   
int __Read(string str){
   if(str == "glyphs" && ((member_array(TPQN,OWNERS) != -1) || avatarp(TP))) {
     write("Actions include:  \n'check' to check the list of attackers\n"
           "'pardon <name>' to pardon someone who attacked Dean\n"
           "   (presumably after extracting some sort of payment naturally)\n"
           "'waves hands' locks/unlocks the door for the owner(s) or wizzes\n"
           "'waves hands twice' locks/unlocks the heavy door\n"
           "'record -l' lists names of people allowed to pass south freely\n"
           "'record -a | -r <name>' add/remove names of allowed");
     return 1;
   }        
   return ::__Read(str);
}

int record(string str){
   string *allowed,arg,name;
   int i;
   if ((member_array(TPQN,OWNERS) == -1) && (!avatarp(TP)) )   return 0;
   if(!str) return notify_fail("Syntax: record -l(ist)|a(dd)|r(emove)
[name]\n");
   allowed = SAVE_D->query_array("slore_backroom_ok");
   if(str == "-l"){
      write("The list reads:");
      for(i = 0;i<sizeof(allowed);i++) write(allowed[i]);
      return 1;
   }
   else if(sscanf(str,"-%s %s",arg,name) != 2){
      return notify_fail("Syntax: record -l(ist)|a(dd)|r(emove) [name]\n");
   }
   else if(arg == "a"){
      SAVE_D->set_value("slore_backroom_ok",name);
      write("You added "+name+" to the allowed list.");
      return 1;
   }
   else if(arg == "r"){
      if(member_array(name,allowed) == -1){
         write("That name is not on the list.");
         return 1;
      }
      else{
         SAVE_D->remove_name_from_array("slore_backroom_ok",name);
         write("You removed "+name+" from the allowed list.");
         return 1;
      }
   }
}

int check_attackers(){
   string *killers;
   int i;
   if ( !TP->query_name("slore") && !avatarp(TP) )return 0;
   killers = SAVE_D->query_array("slore_shop_killers");
      write("The list reads:");
      for(i = 0;i<sizeof(killers);i++) write(killers[i]);
      return 1;
}

int pardon_em() {
   killers = SAVE_D->query_array("slore_shop_killers");
   if(!TP->query_name("slore") && !avatarp(TP))   return 0;
	if(member_array(TPQN,killers) != -1) {
     SAVE_D->remove_name_from_array("slore_shop_killers", TPQN);
   tell_object(TP,"You have pardoned "+TPQCN+" for the attacks.");
	  return 1;
	}
	notify_fail("You don't need to pardon that person, they aren't on the list of troublemakers.\n");
}