#include <std.h> 
#include "../defs.h" 
#define SAVE_D "/daemon/save_d"
inherit "/std/library.c";

// The Bloody Scourage Inn (Innaeli & Anson's HM 'home')
// Design Work Written by Innaeli 
// Put into game December 2008 :: Nienne 
// Wizard assisted by Lurue 

void create(){ 
   ::create(); 
   set_public_library(0);
   set_library_name("innaeli_library");
   set_deposit(0);
   set_property("light",1); 
   set_property("indoors",1); 
   set_terrain(STONE_BUILDING); 
   set_travel(PAVED_ROAD); 
   set_name("A relaxing library"); 
   set_short("%^BOLD%^%^WHITE%^A relaxing library%^RESET%^"); 
   set_long("%^BOLD%^%^WHITE%^The high walls of the library are "+
"covered with hundreds of books that tower over your head, some "+
"quite out of reach. Small %^BOLD%^%^CYAN%^g%^RESET%^%^CYAN%^lo"+
"%^BOLD%^%^CYAN%^wi%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^g g%^RESET%^"+
"%^CYAN%^e%^BOLD%^%^CYAN%^ms%^BOLD%^%^WHITE%^ hang from the "+
"ceiling, s%^RESET%^hi%^BOLD%^m%^RESET%^me%^BOLD%^ri%^RESET%^n"+
"%^BOLD%^g%^BOLD%^%^WHITE%^ like %^RESET%^stars%^BOLD%^%^WHITE%^. "+
"In the middle of the room sits a small round %^BOLD%^%^BLACK%^"+
"table%^BOLD%^%^WHITE%^, draped in a silk %^BOLD%^%^MAGENTA%^a"+
"%^RESET%^%^MAGENTA%^me%^BOLD%^%^MAGENTA%^th%^RESET%^%^MAGENTA%^"+
"ys%^BOLD%^%^MAGENTA%^t cl%^RESET%^%^MAGENTA%^ot%^BOLD%^"+
"%^MAGENTA%^h%^BOLD%^%^WHITE%^, and atop that hovers a %^BOLD%^"+
"%^CYAN%^c%^RESET%^%^CYAN%^ry%^BOLD%^%^CYAN%^st%^RESET%^%^CYAN%^"+
"a%^BOLD%^%^CYAN%^l b%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^ll%^BOLD%^"+
"%^WHITE%^. Comfortable %^BOLD%^%^BLACK%^chairs%^BOLD%^%^WHITE%^ "+
"are scattered around the room, and there are even a few "+
"%^BOLD%^%^BLACK%^cushions%^BOLD%^%^WHITE%^ for sitting on the "+
"floor. A rectangular table along one wall holds a small %^BOLD%^"+
"%^CYAN%^c%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^y%^RESET%^%^BLUE%^s"+
"%^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^a%^BOLD%^%^CYAN%^l%^RESET%^"+
"%^CYAN%^l%^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^n%^BOLD%^%^GREEN%^e"+
"%^BOLD%^%^WHITE%^ fountain, the constant trickle of %^BOLD%^"+
"%^BLUE%^water%^BOLD%^%^WHITE%^ creating a %^RESET%^soothing"+
"%^BOLD%^%^WHITE%^ sound while blocking out noises from outside. "+
"On the wall above the fountain is an %^BOLD%^%^BLACK%^eerie"+
"%^BOLD%^%^WHITE%^, %^BOLD%^%^RED%^gl%^RESET%^%^RED%^o%^BOLD%^"+
"%^RED%^w%^RESET%^%^RED%^in%^BOLD%^%^RED%^g r%^RESET%^%^RED%^e"+
"%^BOLD%^%^RED%^d e%^RESET%^%^RED%^y%^BOLD%^%^RED%^e%^BOLD%^"+
"%^WHITE%^. There is a small door on the eastern wall.%^RESET%^");

   set_smell("default","%^BOLD%^%^BLACK%^The smell of paper and "+
"ink mingle with a light musky scent.%^RESET%^"); 
   set_listen("default","%^BOLD%^%^BLUE%^Gently flowing water "+
"provides a pleasant backdrop.%^RESET%^"); 

   set_items(([ 
({"globes","lights","gems"}):"%^RESET%^Small %^BOLD%^gems%^RESET%^, "+
"roughly cut, hang from %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^"+
"ld%^RESET%^%^ORANGE%^e%^YELLOW%^n c%^RESET%^%^ORANGE%^h%^YELLOW%^"+
"ai%^RESET%^%^ORANGE%^n%^YELLOW%^s%^RESET%^ from the ceiling. "+
"Most provide a gentle %^BOLD%^%^WHITE%^white light%^RESET%^, "+
"while others %^BOLD%^%^RED%^t%^RESET%^%^RED%^w%^YELLOW%^i"+
"%^RESET%^%^ORANGE%^n%^BOLD%^%^MAGENTA%^k%^RESET%^%^MAGENTA%^l"+
"%^BOLD%^%^GREEN%^e%^RESET%^ in an array of colors.",

({"shelves","bookshelves","books"}):"%^RESET%^Hundreds of %^BOLD%^"+
"%^BLACK%^books%^RESET%^ covering almost every topic imaginable "+
"line the walls. Some appear quite old and worn, while others are "+
"new and have likely never been touched. Theres an entire "+
"section related to the psionic arts, quite a bit on devils, "+
"anatomy, art, general lore, and even a few essays on arcane "+
"topics. This is an %^BOLD%^%^WHITE%^impressive%^RESET%^ "+
"collection, and probably took someone a lot of time and resources "+
"to gather.",

({"chairs","cushions"}):"%^RESET%^There is a %^RED%^red chair"+
"%^RESET%^, a %^MAGENTA%^violet chair%^RESET%^ and a %^BOLD%^"+
"%^BLACK%^black chair%^RESET%^ here, their surfaces %^BOLD%^"+
"velvety%^RESET%^ and soft. Large cushions in similar colors are "+
"tossed around the room.",

({"fountain"}):"%^BOLD%^%^BLACK%^J%^RESET%^ag%^BOLD%^%^BLACK%^"+
"g%^RESET%^e%^BOLD%^%^BLACK%^d%^BOLD%^%^WHITE%^ %^BOLD%^%^WHITE%^"+
"crystals%^RESET%^ appear to have been melded together, %^BOLD%^"+
"%^RED%^s%^RESET%^%^RED%^p%^ORANGE%^a%^BOLD%^%^GREEN%^r%^RESET%^"+
"%^GREEN%^k%^BOLD%^%^BLUE%^l%^RESET%^%^BLUE%^i%^BOLD%^%^CYAN%^n"+
"%^RESET%^%^CYAN%^g%^RESET%^ in an array of colors as %^BOLD%^"+
"%^BLUE%^water%^RESET%^ trickles over their surface, into a "+
"small %^CYAN%^pool%^RESET%^. The flowing water provides a "+
"soothing backdrop and blocks out most noises from the hectic "+
"world outside.",

({"eye"}):"%^RESET%^This is a %^BOLD%^strange%^RESET%^ fixture "+
"to any room. The %^BOLD%^glowing%^RESET%^, %^BOLD%^%^RED%^cr"+
"%^RESET%^%^RED%^yst%^BOLD%^%^RED%^a%^RESET%^%^RED%^lli%^BOLD%^"+
"%^RED%^ne e%^RESET%^%^RED%^y%^BOLD%^%^RED%^e%^RESET%^ appears "+
"to be embedded into the wall, and it %^BOLD%^p%^RESET%^u%^BOLD%^"+
"l%^RESET%^s%^BOLD%^a%^RESET%^te%^BOLD%^s%^RESET%^ in time to "+
"the beating of your heart. You can feel its %^BOLD%^%^RED%^ga"+
"%^RESET%^%^RED%^z%^BOLD%^%^RED%^e%^RESET%^ upon you no matter "+
"where you stand in the room.",
   ])); 
   set_exits(([ 
"east":ROOMS"bsb8", 
   ])); 
   set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
} 

int GoThroughDoor() {
   object theroom;
   theroom = find_object_or_load(ROOMS"bsb8");
   if(TP->query_true_invis()) return 1;
   if(member_array("west",theroom->query_exits()) == -1)
   tell_room(ROOMS"bsb8","%^BOLD%^%^WHITE%^One of the paintings "+
"swings aside just long enough to permit someone through!%^RESET%^",TP);
   return 1;
}

void reset() {
   object mycrystal;
   ::reset();
   if(!present("crystal ball")) {
     mycrystal = new("/d/magic/obj/crystal_ball");
     mycrystal->move(TO);
     mycrystal->set_long("%^RESET%^The small, circular table "+
"sits atop a %^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^o%^BOLD%^"+
"%^BLUE%^l%^RESET%^%^BLUE%^o%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^"+
"f%^BOLD%^%^ORANGE%^u%^RESET%^%^ORANGE%^l%^RESET%^ throw rug. "+
"The table itself is draped in a silken %^RESET%^%^MAGENTA%^a"+
"%^BOLD%^%^MAGENTA%^me%^RESET%^%^MAGENTA%^th%^BOLD%^%^MAGENTA%^y"+
"%^RESET%^%^MAGENTA%^st cl%^BOLD%^%^MAGENTA%^ot%^RESET%^"+
"%^MAGENTA%^h%^RESET%^ with %^BOLD%^%^BLACK%^frayed%^RESET%^ "+
"and %^BOLD%^%^BLACK%^tattered%^RESET%^ ends. A %^BOLD%^%^CYAN%^"+
"c%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^yst%^RESET%^%^CYAN%^a"+
"%^BOLD%^%^CYAN%^l b%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^ll%^RESET%^ "+
"hovers about the table, its surface clear. A strange %^BOLD%^"+
"mist %^BOLD%^%^BLACK%^s%^RESET%^%^CYAN%^w%^BOLD%^%^BLACK%^irl"+
"%^BOLD%^%^BLUE%^s%^RESET%^ around inside the ball, occasionally "+
"changing %^BOLD%^%^WHITE%^c%^RESET%^%^RED%^o%^BOLD%^%^WHITE%^lo"+
"%^RESET%^%^MAGENTA%^r%^BOLD%^%^WHITE%^s%^RESET%^.");
   }
}

void init() {
   string myname,myadj;
   ::init();
   add_action("observe_it","list");
   add_action("purge_it","purge");
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

int not_allowed_func(object player) {
   tell_object(player,"A wall of force seems to pull your hand up short, before you can touch the bookshelf!");
   return 0;
}
