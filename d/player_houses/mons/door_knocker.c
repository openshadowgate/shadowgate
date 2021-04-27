//door_knocker.c - For Stefano's tower.  Coded by Circe 9/13/03
#include <std.h>
#include "/d/player_houses/stefano/stefano.h"
inherit NPC;

void create()
{
   ::create();
   set_name("door knocker");
   set_id(({"door knocker","knocker","iron knocker","iron ring"}));
   set_short("A door knocker");
   set_long(
      "The face in the door is minimal in detail, just a mouth, nose, eyes and "+
      "eyebrows carved into the wood. The features are artfully done, though and its "+
      "expression manages to almost look pleased to see you without quite being sincere.  "+
      "An iron ring is set within the wooden door just below the face and may be used "+
      "to knock on the door and possibly gain entrance."
      );
   set_gender("neuter");
   set_race("door knocker");
   set_body_type("snake");
   remove_limb("mouth");
   remove_limb("head");
   remove_limb("tail");
   remove_limb("torso");
   set_hd(1,1);
   set_size(1);
   set_alignment(5);
   set_overall_ac(6);
   set_max_hp(random(20)+20);
   set_hp(query_max_hp());
   set_level(1);
   set_stats("intelligence",16);
   set_exp(1);
}   
void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void init(){
   ::init();
   if(TP->query_true_invis())
   return;
   force_me("emote comes to life and gives an attempt at a friendly smile.");
   force_me("say Would you like to come in?");
}

void reply_func(string msg, object who){
      if(!msg || !objectp(who)) return;
   if(strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"yea") != -1 || strsrch(msg,"ure") != -1) {
      force_me("say Right this way.");
//      who->move(SHOUSE"tower_lounge");  //Taken out by Stefano's request.  Circe 1/2/04
//      who->force_me("look");
      tell_room(ETO,"The door swings open.");
      "/d/player_houses/stefano/ledge"->set_open("door",1);
      tell_room("/d/player_houses/stefano/tower_lounge","The door swings open.");
      "/d/player_houses/stefano/tower_lounge"->set_open("door",1);
      return;
   }
   if(strsrch(msg,"no") != -1 || strsrch(msg,"No") != -1 || strsrch(msg,"nah") != -1 || strsrch(msg,"Nah") != -1) {
      force_me("emote 's smile stays in place, but its tone goes cold as it speaks.");
      force_me("say Would you mind getting off the ledge, then? You're spoiling my view.");
      return;
   }
   else return;
}