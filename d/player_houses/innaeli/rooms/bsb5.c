#include <std.h> 
#include "../defs.h" 
inherit VAULT; 

// The Bloody Scourage Inn (Innaeli & Anson's HM 'home')
// Design Work Written by Innaeli 
// Put into game December 2008 :: Nienne 
// Wizard assisted by Lurue 

void fail_step(object theplayer);
void pass_step(object theplayer);

void create(){ 
   ::create(); 
   set_property("light",1); 
   set_property("indoors",1); 
   set_terrain(STONE_BUILDING); 
   set_travel(PAVED_ROAD); 
   set_name("Second Floor Landing"); 
   set_short("%^RESET%^%^MAGENTA%^Second Floor Landing%^RESET%^"); 
   set_long("%^RESET%^You find yourself standing on the landing of "+
"the second floor of the %^BOLD%^%^RED%^B%^RESET%^%^RED%^lo%^BOLD%^"+
"%^RED%^od%^RESET%^%^RED%^y %^BOLD%^%^BLACK%^S%^RESET%^%^RED%^c"+
"%^BOLD%^%^BLACK%^ou%^RESET%^%^RED%^rg%^BOLD%^%^BLACK%^e Inn"+
"%^RESET%^. Small alcoves in the %^BOLD%^%^BLACK%^s%^RESET%^t"+
"%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e walls%^RESET%^ "+
"hold %^BOLD%^candles%^RESET%^ that provide f%^BOLD%^%^WHITE%^li"+
"%^RESET%^c%^BOLD%^%^WHITE%^k%^RESET%^in%^BOLD%^%^WHITE%^g%^RESET%^ "+
"dim light to the wide corridor. The floor is %^BOLD%^%^BLACK%^"+
"black%^RESET%^, and a %^BOLD%^%^RED%^cr%^RESET%^%^RED%^im%^BOLD%^"+
"%^RED%^s%^RESET%^%^RED%^on r%^BOLD%^%^RED%^u%^RESET%^%^RED%^nn"+
"%^BOLD%^%^RED%^er%^RESET%^ muffles the sound of footsteps. There "+
"are three doors here, and two are %^RESET%^%^ORANGE%^wooden"+
"%^RESET%^ with %^YELLOW%^b%^RESET%^%^ORANGE%^ras%^YELLOW%^s "+
"k%^RESET%^%^ORANGE%^nob%^YELLOW%^s%^RESET%^. The door to the north "+
"is arched and made from %^BOLD%^%^BLACK%^blackened ir%^RESET%^o"+
"%^BOLD%^%^BLACK%^n%^RESET%^.");

   set_smell("default","%^BOLD%^%^WHITE%^A light aroma lingers "+
"from the candles, and it smells vaguely of smoke and ash.%^RESET%^"); 
   set_listen("default","%^RESET%^%^CYAN%^Sounds from the bar are "+
"quieter here.%^RESET%^"); 

   set_items(([ 
({"alcoves"}):"%^RESET%^Carved into the thick %^BOLD%^%^BLACK%^"+
"stone walls%^RESET%^, the alcoves each hold a set of %^RESET%^"+
"%^ORANGE%^ornate %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld"+
"%^RESET%^%^ORANGE%^e%^YELLOW%^n ca%^RESET%^%^ORANGE%^nd%^YELLOW%^"+
"leh%^RESET%^%^ORANGE%^ol%^RESET%^%^ORANGE%^de%^YELLOW%^rs%^RESET%^"+
", and %^BOLD%^%^BLACK%^black%^RESET%^ and %^BOLD%^%^RED%^cr"+
"%^RESET%^ims%^BOLD%^%^RED%^o%^RESET%^%^RED%^n%^BOLD%^%^WHITE%^ "+
"candles%^RESET%^ burn day and night, never appearing to deplete. "+
"%^RESET%^%^RED%^Crimson silk%^RESET%^ lines the alcoves. The "+
"cloth spills over the edges and is rather %^BOLD%^%^BLACK%^ta"+
"%^RESET%^t%^BOLD%^%^BLACK%^ter%^RESET%^e%^BOLD%^%^BLACK%^d%^RESET%^ "+
"and %^BOLD%^%^BLACK%^f%^RESET%^ra%^BOLD%^%^BLACK%^y%^RESET%^e"+
"%^BOLD%^%^BLACK%^d%^RESET%^.",

({"runner"}):"%^BOLD%^%^RED%^C%^RESET%^%^RED%^ri%^BOLD%^%^RED%^m"+
"%^RESET%^%^RED%^so%^BOLD%^%^RED%^n%^RESET%^ and thin, it appears "+
"this at one time might have been a very plush accessory. However, "+
"its surface is now worn and %^BOLD%^%^BLACK%^tattered%^RESET%^ "+
"from use. A fading pattern is evident, and upon closer inspection "+
"you find the image is hundreds of small, %^BOLD%^%^RED%^b%^RESET%^"+
"%^RED%^lo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d-r%^BOLD%^%^RED%^e"+
"%^RESET%^%^RED%^d %^BOLD%^%^RED%^e%^RESET%^%^RED%^ye%^BOLD%^"+
"%^RED%^s%^RESET%^, staring back at you.%^RESET%^",

({"iron door","north door","door"}):"%^RESET%^This door "+
"certainly stands out, being different than the others. It "+
"is shaped into an arch, and the doorframe is thick, %^BOLD%^"+
"%^WHITE%^s%^RESET%^h%^BOLD%^%^BLACK%^ini%^RESET%^n%^BOLD%^"+
"%^WHITE%^g iron%^RESET%^. The door itself is heavy and "+
"%^BOLD%^%^BLACK%^darker%^RESET%^ in color, almost as if it "+
"has been %^RESET%^%^RED%^scorched%^RESET%^ by %^BOLD%^%^RED%^"+
"f%^RESET%^%^RED%^l%^MAGENTA%^a%^ORANGE%^m%^RED%^e%^BOLD%^"+
"%^RED%^s%^RESET%^. As you approach it, it seems to grow oddly "+
"translucent, like you could walk right through it.%^RESET%^"
   ])); 
   set_exits(([ 
"down":ROOMS"bsb1", 
"north":ROOMS"bsb8", //iron door
"south":ROOMS"bsb6", //ebony door
"west":ROOMS"bsb7",  //mahogany door
   ]));    
   set_pre_exit_functions(({"north"}),({"pass_door"}));

   set_door("ebony door",ROOMS"bsb6","south",0);
   set_locked("ebony door", 0);
   lock_difficulty("ebony door", "/daemon/player_housing"->get_phouse_lock_dc("poor"), "lock");
   set_door_description("ebony door","%^RESET%^This is a simple "+
"%^BOLD%^%^BLACK%^ebony door%^RESET%^ with %^YELLOW%^b"+
"%^RESET%^%^ORANGE%^ras%^YELLOW%^s k%^RESET%^%^ORANGE%^nob"+
"%^YELLOW%^s%^RESET%^. A %^RESET%^%^MAGENTA%^grotesque%^RESET%^ "+
"face, its mouth wide in an anguished scream leaps out from the "+
"center of each door. A small handle indicates that this "+
"%^BOLD%^interesting%^RESET%^ ornament is probably a knocker. ");
   set_string("ebony door", "open", "The door swings open.");
   set_string("ebony door", "close", "The door swings shut.");

   set_door("mahogany door",ROOMS"bsb7","west",0);
   set_locked("mahogany door", 0);
   lock_difficulty("mahogany door", "/daemon/player_housing"->get_phouse_lock_dc("poor"), "lock");
   set_door_description("mahogany door","%^RESET%^This is a simple "+
"%^RESET%^%^RED%^mahogany door%^RESET%^ with %^YELLOW%^b"+
"%^RESET%^%^ORANGE%^ras%^YELLOW%^s k%^RESET%^%^ORANGE%^nob"+
"%^YELLOW%^s%^RESET%^. A %^RESET%^%^MAGENTA%^grotesque%^RESET%^ "+
"face, its mouth wide in an anguished scream leaps out from the "+
"center of each door. A small handle indicates that this "+
"%^BOLD%^interesting%^RESET%^ ornament is probably a knocker. ");
   set_string("mahogany door", "open", "The door swings open.");
   set_string("mahogany door", "close", "The door swings shut.");
} 

void init() {
   ::init();
   add_action("peer_fun","peer");
   add_action("say_fun","say");
   add_action("sneak_fun","sneak");
}

int pass_door() {
   if(TP->query_true_invis()) return 1;
   tell_object(TP,"%^RESET%^You walk up to the door, but it certainly seems solid enough when you bump into it.");
   tell_room(TO,"%^RESET%^"+TP->QCN+" walks up to the heavy iron doorframe, and bumps right into it.",TP);
   return 0;
}

int peer_fun(string str){
   string mystring, mystring2;
   if(TP->query_true_invis()) return 0;
   if(!str) return 0;
   if(sscanf(str,"%s %s", mystring, mystring2) != 2) mystring = str;
   if(mystring != "north" && mystring != "n") return 0;
   tell_object(TP,"%^BOLD%^%^WHITE%^The heavy doorway, while somewhat translucent, is too thick to see through.%^RESET%^");
   return 1;
}

int say_fun(string str){
   object myring;
   if(TP->query_true_invis()) return 0;
   if(!str) return 0;
   str = lower_case(str);
   if(strsrch(str,"mal'rak lu' tu'jol") == -1) return 0;
   myring = present("bsbrubyring",TP);
   if(!myring || !myring->query_worn()) {
     call_out("fail_step",1,TP);
     return 0;
   }
   call_out("pass_step",1,TP);
   return 0;
}

void fail_step(object theplayer) {
   tell_object(theplayer,"%^BOLD%^%^WHITE%^As the words leave your lips you feel a light tugging at your body, but then it fades.%^RESET%^");
}

void pass_step(object theplayer) {
   tell_object(theplayer,"%^BOLD%^%^WHITE%^As the words leave your lips you feel a light compulsion, and before you realise it you have stepped forward, straight through the iron doorway!%^RESET%^");
   tell_room(TO,"%^BOLD%^%^WHITE%^As the words leave "+TP->QCN+"'s lips, "+TP->QS+" gets a strange look on "+TP->QP+" face and abruptly steps forward, straight through the iron doorway!%^RESET%^",theplayer);
   TP->move_player(ROOMS"bsb8");
}

int sneak_fun(string str){
   if(TP->query_true_invis()) return 0;
   if(!str) return 0;
   if(str != "north" && str != "n") return 0;
   tell_object(TP,"You can tell the translucent doorway is still too solid to sneak through.");
   return 1;
}
