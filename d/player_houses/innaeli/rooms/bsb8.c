#include <std.h> 
#include "../defs.h" 
#define SAVE_D "/daemon/save_d"
inherit VAULT; 

// The Bloody Scourage Inn (Innaeli & Anson's HM 'home')
// Design Work Written by Innaeli 
// Put into game December 2008 :: Nienne 
// Wizard assisted by Lurue 

void create(){ 
   ::create(); 
   set_property("light",1); 
   set_property("indoors",1); 
   set_terrain(STONE_BUILDING); 
   set_travel(PAVED_ROAD); 
   set_name("A bedroom"); 
   set_short("%^BOLD%^%^BLACK%^A bedroom%^RESET%^"); 
   set_long("%^BOLD%^%^WHITE%^The walls of this room are made from "+
"smooth bricks in varying hues from %^RESET%^w%^BOLD%^%^WHITE%^h"+
"%^RESET%^i%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^ "+
"to %^BOLD%^%^BLACK%^b%^RESET%^l%^BOLD%^%^WHITE%^a%^RESET%^c"+
"%^BOLD%^%^BLACK%^k%^BOLD%^%^WHITE%^. The colors provide a "+
"pleasant contrast to the thick %^BOLD%^%^RED%^c%^RESET%^%^RED%^"+
"rim%^BOLD%^%^RED%^so%^RESET%^%^RED%^n c%^BOLD%^%^RED%^ar%^RESET%^"+
"%^RED%^pe%^BOLD%^%^RED%^t%^RESET%^%^RED%^in%^BOLD%^%^RED%^g"+
"%^BOLD%^%^WHITE%^. The walls are almost bare except for a "+
"single %^RESET%^%^CYAN%^painting%^BOLD%^%^WHITE%^ that stretches "+
"from the floor to the ceiling. A cozy %^BOLD%^%^RED%^f%^RESET%^"+
"%^RED%^ir%^BOLD%^%^RED%^e%^BOLD%^%^WHITE%^ burns in the "+
"fireplace, and an %^BOLD%^%^BLACK%^armchair%^BOLD%^%^WHITE%^ "+
"sits in front of it. Above it %^RESET%^glows%^BOLD%^%^WHITE%^ "+
"the image of a large, %^BOLD%^%^BLACK%^e%^RESET%^%^RED%^e"+
"%^BOLD%^%^BLACK%^ri%^RESET%^%^RED%^e %^BOLD%^%^RED%^r%^RESET%^"+
"%^RED%^e%^BOLD%^%^RED%^d e%^RESET%^%^RED%^y%^BOLD%^%^RED%^e"+
"%^BOLD%^%^WHITE%^. A comfortable %^BOLD%^%^BLACK%^sofa%^BOLD%^"+
"%^WHITE%^ sits adjacent to a massive %^RESET%^%^MAGENTA%^bed"+
"%^BOLD%^%^WHITE%^, which is the focal point of the room. There "+
"is a %^BOLD%^%^BLACK%^black ir%^RESET%^o%^BOLD%^%^BLACK%^n door"+
"frame%^BOLD%^%^WHITE%^ on the southern wall, but, oddly, there "+
"is no door.%^RESET%^ ");

   set_smell("default","%^BOLD%^%^CYAN%^The room smells of scented "+
"candles.%^RESET%^"); 
   set_listen("default","%^BOLD%^%^BLUE%^Some soft music drifts in "+
"from below.%^RESET%^"); 

   set_items(([ 
({"walls"}):"%^RESET%^The smooth bricks of the walls are "+
"%^BOLD%^%^BLACK%^black%^RESET%^, %^BOLD%^%^WHITE%^white"+
"%^RESET%^, and every %^BOLD%^%^BLACK%^s%^RESET%^h%^BOLD%^"+
"%^WHITE%^a%^RESET%^d%^BOLD%^%^BLACK%^e%^RESET%^ between.",

({"floor","carpet","carpeting"}):"%^RESET%^The %^BOLD%^%^RED%^c%^RESET%^%^RED%^ri"+
"%^BOLD%^%^RED%^m%^RESET%^%^RED%^so%^BOLD%^%^RED%^n%^RESET%^ "+
"carpeting is soft beneath your feet.",

({"painting"}):"%^RESET%^A %^BOLD%^%^WHITE%^crystalline%^RESET%^ "+
"ground is the foundation for a circle of %^BOLD%^%^GREEN%^gl"+
"%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^wi%^RESET%^%^GREEN%^n"+
"%^BOLD%^%^GREEN%^g%^BOLD%^%^WHITE%^ pillars%^RESET%^. Oddly, "+
"in the middle of the pillars stands a %^BOLD%^%^BLACK%^single "+
"%^RESET%^%^ORANGE%^wooden%^BOLD%^%^BLACK%^ door%^RESET%^, "+
"looking quite out of place in this otherwise %^BOLD%^%^CYAN%^"+
"e%^RESET%^%^CYAN%^th%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^re"+
"%^BOLD%^%^CYAN%^al%^RESET%^ scene. The %^BOLD%^%^BLACK%^black "+
"sky%^RESET%^ in the background is streaked with a dozen other "+
"%^BOLD%^%^BLUE%^c%^CYAN%^o%^GREEN%^l%^MAGENTA%^o%^RED%^r"+
"%^BLUE%^s%^RESET%^, and is really quite mystifying%^RESET%^.",

({"fireplace","mantle"}):"%^BOLD%^%^BLACK%^J%^RESET%^a%^BOLD%^"+
"%^BLACK%^gg%^RESET%^e%^BOLD%^%^BLACK%^d%^RESET%^ cuts of "+
"%^BOLD%^%^BLACK%^onyx%^RESET%^ and %^RESET%^%^MAGENTA%^a"+
"%^BOLD%^%^MAGENTA%^m%^RESET%^%^MAGENTA%^eth%^BOLD%^%^MAGENTA%^"+
"ys%^RESET%^%^MAGENTA%^t%^RESET%^ frame the fireplace. A "+
"%^BOLD%^%^BLACK%^metal screen%^RESET%^ covers the hearth, and "+
"is worked into the design of an %^BOLD%^%^WHITE%^intricate "+
"%^BOLD%^%^BLACK%^s%^RESET%^p%^BOLD%^%^BLACK%^id%^RESET%^e"+
"%^BOLD%^%^BLACK%^r web%^RESET%^. An %^BOLD%^%^BLACK%^onyx "+
"spider%^RESET%^ waits in the corner with %^BOLD%^%^WHITE%^"+
"sparkling %^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^me%^BOLD%^"+
"%^MAGENTA%^th%^RESET%^%^MAGENTA%^ys%^BOLD%^%^MAGENTA%^t e"+
"%^RESET%^%^MAGENTA%^ye%^BOLD%^%^MAGENTA%^s%^RESET%^.",

({"armchair","chair"}):"%^RESET%^This is a simple, %^BOLD%^"+
"%^BLACK%^black leather armchair%^RESET%^. You can probably sit "+
"on it to relax in front of the %^RESET%^%^RED%^fire%^RESET%^, "+
"or curl up with a good book.",

({"bed"}):"%^RESET%^A %^BOLD%^%^RED%^c%^RESET%^%^RED%^h%^BOLD%^"+
"%^MAGENTA%^e%^RESET%^%^MAGENTA%^c%^BOLD%^%^RED%^k%^RESET%^"+
"%^RED%^e%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^e%^BOLD%^%^RED%^"+
"d%^RESET%^ blanket spreads across the massive bed in hues of "+
"%^RESET%^%^RED%^red%^RESET%^ and %^MAGENTA%^violet%^RESET%^. "+
"Matching pillows line the %^BOLD%^%^BLACK%^iron cast headboard"+
"%^RESET%^. The headboard is a dark, intricate design of %^BOLD%^"+
"%^BLACK%^ivy leaves%^RESET%^, %^BOLD%^%^BLACK%^blossoms%^RESET%^ "+
"and even a couple %^BOLD%^%^BLACK%^butterflies%^RESET%^. It "+
"looks quite %^BOLD%^worn%^RESET%^ in a couple spots.",

({"eye"}):"%^RESET%^This is a %^BOLD%^strange%^RESET%^ fixture "+
"to any room. The %^BOLD%^glowing%^RESET%^, %^BOLD%^%^RED%^cr"+
"%^RESET%^%^RED%^yst%^BOLD%^%^RED%^a%^RESET%^%^RED%^lli%^BOLD%^"+
"%^RED%^ne e%^RESET%^%^RED%^y%^BOLD%^%^RED%^e%^RESET%^ appears "+
"to be embedded into the wall, and it %^BOLD%^p%^RESET%^u"+
"%^BOLD%^l%^RESET%^s%^BOLD%^a%^RESET%^te%^BOLD%^s%^RESET%^ in "+
"time to the beating of your heart. You can feel its %^BOLD%^"+
"%^RED%^ga%^RESET%^%^RED%^z%^BOLD%^%^RED%^e%^RESET%^ upon you "+
"no matter where you stand in the room.",

({"frame","doorframe"}):"%^BOLD%^%^BLACK%^Black ir%^RESET%^o"+
"%^BOLD%^%^BLACK%^n%^RESET%^ forms the shape of a door on the "+
"southern wall. As you approach it, it seems to grow oddly "+
"translucent, like you could walk right through it.",

({"couch","sofa"}):"%^BOLD%^%^BLACK%^The couch is covered with plush black "+
"cushions and looks very cozy.%^RESET%^",
   ])); 

   set_exits(([
"south":ROOMS"bsb5",
   ])); 
   set_pre_exit_functions(({"south"}),({"GoThroughDoor"}));
} 

void init() {
   string myname,myadj;
   ::init();
   add_action("peer_fun","peer");
   add_action("observe_it","list");
   add_action("purge_it","purge");
   add_action("push_it","push");
   if(!objectp(TP)) return;
   if(!userp(TP)) return;
   if(TP->query_invis()) return;
   if(sscanf((string)TP->query_short(),"%s, %s", myname, myadj) != 2)
     myadj = (string)TP->query_short();
   if(member_array(myadj,(string *)SAVE_D->query_array("innaeli_eye")) == -1) {
     if((string)TP->query_name() != "innaeli" && (string)TP->query_name() != "anson")
       SAVE_D->set_value("innaeli_eye",myadj);
   }
}

int GoThroughDoor() {
   if(TP->query_invis()) return 1;
   tell_object(TP,"%^RESET%^You walk up to the door and step straight through it.");
   tell_room(TO,"%^RESET%^"+TP->QCN+" walks up to the heavy iron doorframe and steps straight through it.",TP);
   tell_room(ROOMS"bsb5","%^RESET%^"+TP->QCN+" suddenly steps through the iron doorframe and onto the landing.");
   return 1;
}

int peer_fun(string str){
   string mystring, mystring2;
   if(TP->query_true_invis()) return 0;
   if(!str) return 0;
   if(sscanf(str,"%s %s", mystring, mystring2) != 2) mystring = str;
   if(mystring != "south" && mystring != "s") return 0;
   tell_object(TP,"%^BOLD%^%^WHITE%^The heavy doorway, while somewhat translucent, is too thick to see through.%^RESET%^");
   return 1;
}

int observe_it(string str) {
   string *observed, mymessage;
   int i;
   if(!str) return 0;
   if(str != "trespassers") return 0;
   if(!avatarp(TP) && (string)TP->query_name() != "innaeli" && (string)TP->query_name() != "anson") {
     tell_object(TP,"You try to observe something unusual about the eye, but it just stares back at you.");
     tell_room(TO,""+TP->QCN+" observes the eye closely.",TP);
     return 1;
   }
   observed = ({});
   observed += (string *)SAVE_D->query_array("innaeli_eye");
   if(!sizeof(observed)) {
     tell_object(TP,"You observe the eye closely, but it projects you no images.");
     tell_room(TO,""+TP->QCN+" observes the eye closely.",TP);
     return 1;
   }
   mymessage = observed[i];
   for(i = 1;i<sizeof(observed);i++) {
     mymessage += ", ";
     mymessage += observed[i];
   }
   tell_object(TP,"You observe the eye closely, and images are projected into your mind. It has seen "+mymessage+".");
   tell_room(TO,""+TP->QCN+" observes the eye closely.",TP);
   return 1;
}

int purge_it(string str) {
   if(!str) return 0;
   if(str != "trespassers") return 0;
   if(!avatarp(TP) && (string)TP->query_name() != "innaeli" && (string)TP->query_name() != "anson") {
     tell_object(TP,"You focus your concentration on the eye, but nothing happens.");
     tell_room(TO,""+TP->QCN+" concentrates on the eye.",TP);
     return 1;
   }
   if(!sizeof((string *)SAVE_D->query_array("innaeli_eye"))) {
     tell_object(TP,"You focus your concentration on the eye, but it has already been purged.");
     tell_room(TO,""+TP->QCN+" concentrates on the eye.",TP);
     return 1;
   }
   tell_object(TP,"You concentrate on the eye, and feel its recollections fading.");
   tell_room(TO,""+TP->QCN+" concentrates on the eye.",TP);
   SAVE_D->remove_array("innaeli_eye");
   return 1;
}

int push_it(string str) {
   if(!str) return 0;
   if(str != "the painting" && str != "painting") return 0;
   if(sizeof(TP->query_attackers())) {
     tell_object(TP,"You can't do that while you are in combat!");
     return 1;
   }
   if(member_array("west",TO->query_exits()) != -1) {
     tell_object(TP,"%^BOLD%^%^WHITE%^You push the painting back into place.%^RESET%^");
     tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" pushes the painting back into place.%^RESET%^",TP);
     tell_room(ROOMS"bsb9","%^BOLD%^%^WHITE%^The door swings shut.%^RESET%^");
     TO->remove_exit("west");
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^WHITE%^The painting pushes inward, opening into a library.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" pushes the painting inward, opening into a library.%^RESET%^",TP);
   tell_room(ROOMS"bsb9","%^BOLD%^%^WHITE%^The door swings open.%^RESET%^");
   TO->add_exit(ROOMS"bsb9","west");
   return 1;
}
