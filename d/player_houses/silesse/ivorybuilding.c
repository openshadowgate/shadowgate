
#include <std.h>
#include "sil.h"

inherit ROOM;

void set_dead_guardian();
void set_guarded();
void set_sil_open();
void set_sil_closed();
void successful_rune(string str);
void redo_constellations();
void set_auto_closed();

int failure();

int GUARD,OPEN,step1,step2,step3;
string *owners = ({"silesse","vicdaerrysn","ryzan","aunuit","odin"});

void create(){
  ::create();
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_property("light",2);
  set_property("indoors",1);
  set_name("Inside an ivory building");
  set_short("Inside an ivory building");
  set_long("%^BOLD%^%^WHITE%^You find yourself inside a large, open-air ivory building."
"  The southern end of the building is %^BLACK%^shadowed %^WHITE%^by the base of a"
" %^BLACK%^large cliff%^WHITE%^, while the eastern end gives way to magnificent view of the"
" %^CYAN%^spa%^RESET%^%^CYAN%^rk%^BOLD%^ling s%^RESET%^%^CYAN%^e%^BOLD%^a%^WHITE%^.  The"
" western end of the building faces the %^RESET%^%^BLUE%^lagoon %^BOLD%^%^WHITE%^that"
" separates this beach from the %^RESET%^%^GREEN%^magestic forest %^BOLD%^%^WHITE%^across from"
" it.  At the northern end of the building, two large marble statues stand facing each other"
" and their joined hands create an arch over the stairs that lead out to the beach this"
" building seems designed to overlook.  All around you, carved ivory pillars line the edges"
" and support a high roof whose ceiling is decorated with the various %^BLUE%^constellations"
"%^WHITE%^ painted around the phases of the moon in a sidereal period.  There seems to be"
" nothing in this building except a large marble pedestal near its"
" center, atop which a %^BLACK%^marble statue %^WHITE%^of a %^BLACK%^coiled dragon %^WHITE%^rests"
".%^RESET%^\n");
  set_smell("default","%^BOLD%^%^CYAN%^The %^RESET%^%^CYAN%^salty scent %^BOLD%^%^CYAN%^of"
" the %^RESET%^%^CYAN%^ea%^BOLD%^ste%^RESET%^%^CYAN%^%^rn sea %^BOLD%^mingles with the"
" %^RESET%^%^CYAN%^scent %^BOLD%^of %^RESET%^%^GREEN%^fresh forest%^RESET%^.\n");
  set_listen("default","%^RESET%^%^GREEN%^Above the lulling sounds of gently lapping waves upon"
" the shore, the muted roar of falling water along with the occassional cry of a bird can be"
" heard in the distance.%^RESET%^");
  set_items(([
  ({"forest","lagoon"}):"%^RESET%^%^BLUE%^Looking past the %^WHITE%^ivory pillars"
" %^RESET%^%^BLUE%^to the west, the %^BOLD%^dark waters %^RESET%^%^BLUE%^of the lagoon"
" separating this part of the %^RESET%^beach %^BLUE%^from the %^GREEN%^pristine forests"
" %^BLUE%^ are nearly always covered in a %^RESET%^thick shroud %^BLUE%^of %^RESET%^mist.",
  "sea":"%^BOLD%^%^CYAN%^Light reflects on the eastern %^WHITE%^pillars %^CYAN%^from the"
" vast expanse of sparkling waters that disappear into the horizon%^RESET%^.",
  "beach":"%^BOLD%^%^WHITE%^Past the marble statues that stand on either side of the steps"
" you can see a pristine white beach to the north.%^RESET%^",
  ({"statues","marble statues"}):"%^BOLD%^%^WHITE%^The statue on the left is carved in the"
" image of a nude female elf standing on the balls of her feet, her slender calves flexed in"
" her effort to join hands with the male elf across from her.  The statue is incredibly life"
" like, with every sinewy, corded muscle and soft, feminine curve carved out in exquisite"
" detail.  She has wispy long hair that tumbles over  her shoulders towards the small of her"
" back.  She smiles across the entrance to the statue on the right, which depects a"
" nude male who also stands on the balls of his feet in his effort to reach her."
"  Carved in as much detail as the other, subtle traces of patterned"
" scarring and ritualistic branding cover much of his body, and his hair falls behind him in"
" a multitude of braids secured by carved marble beads.  This statue seems to smile back at"
" the female as well, but the smile upon this one is almost predatory in nature.  Where their"
" hands join beneath the roof, an inscription is carved above the entrance%^RESET%^.",
     ({"dragon","coiled dragon","chaos dragon"}):"%^BOLD%^%^BLACK%^Atop the pedestal sits this"
" four foot tall, lifelike depiction of a %^RESET%^co%^BOLD%^%^BLACK%^il%^RESET%^ed"
   " %^RED%^c%^RESET%^%^MAGENTA%^h"
       "%^GREEN%^a%^ORANGE%^o%^BOLD%^%^WHITE%^s %^BLACK%^dragon%^BOLD%^%^BLACK%^ carved from"
" black marble.  No matter how you move about the building, it seems as though its"
" %^RESET%^gl%^BOLD%^itt%^RESET%^e%^BOLD%^r%^RESET%^ing %^BOLD%^e%^RESET%^y%^BOLD%^es %^BLACK%^are"
" constantly upon you.%^RESET%^",
  ({"cliff", "outcropping", "rocky outcropping", "barrier"}):"%^BOLD%^%^BLACK%^To the south,"
" this rocky outcropping looms ominously over the %^WHITE%^ivory pillars %^BLACK%^and high roof."
" The cliff walls are not only sheer, but riddled with unstable shale and large rocks that"
" look impossible to climb.%^RESET%^",
  ({"ceiling","stars","constellations"}):"%^BOLD%^%^BLUE%^Painted on the ceiling are the various"
" constellations of the %^WHITE%^stars %^BLUE%^surrounding the different %^RESET%^phases"
" %^BOLD%^%^BLUE%^of the %^RESET%^moon%^BOLD%^%^BLUE%^.  Based on the position"
" of the %^WHITE%^stars %^BLUE%^around each of the %^RESET%^phases%^BOLD%^%^BLUE%^, one"
" versed in such things would discern that the painting is based on a %^RESET%^sidereal"
" period%^BOLD%^%^BLUE%^, as the %^WHITE%^moons %^RESET%^phases %^BOLD%^%^BLUE%^are painted"
" with respect to the %^WHITE%^stars%^BLUE%^, rather than with respect to the earth.  If you look"
" closely enough you could probably <observe> different constellations.%^RESET%^",
  "pedestal":"%^BOLD%^%^WHITE%^This smooth marble pedestal is oddly large.  Atop it sits a"
" %^BLACK%^marble statue %^WHITE%^of a %^BLACK%^coiled dragon%^WHITE%^.  In the front"
" of the pedestal, you can make out a single indentation.%^RESET%^",
  "indentation":"%^BOLD%^%^BLACK%^This small indentation looks like it is made to have"
" something inserted into it.%^RESET%^",
  ]));
  GUARD = 1;
  OPEN = 0;
  step1 = 0;
  step2 = 0;
  step3 = 0;
  set_exits(([
   "steps":SIL"beach2"
  ]));
}

void reset(){
   ::reset();
   GUARD = 1;
   OPEN = 0;
   step1 = 0;
   step2 = 0;
   step3 = 0;
   if((string)TO->query_exit("down") == "/d/player_houses/silesse/dungeon"){
      tell_room(TO,"%^BOLD%^%^BLACK%^The dragon's %^RESET%^%^ORANGE%^e%^YELLOW%^y%^RESET%^"
         "%^ORANGE%^es %^BOLD%^%^BLACK%^flash as the pedestal slides back into place.%^RESET%^");
      remove_exit("down");
   }
}

void init(){
   ::init();
   add_action("close_pedestal","slide");
   add_action("insert_key","insert");
   add_action("trace_constellation","trace");
   add_action("go_home","murmur");
   add_action("observe_stars","observe");
}

void redo_constellations(){
   GUARD = 1;
   OPEN = 0;
   step1 = 0;
   step2 = 0;
   step3 = 0;
   return;
}

void set_dead_guardian(){
   GUARD = 0;
   return;
}

void set_guarded(){
   GUARD = 1;
   return;
}

void set_sil_open(){
   OPEN = 1;
   add_exit(SIL"dungeon","down");
   tell_room(TO,"%^BOLD%^%^BLUE%^The %^WHITE%^pedestal %^BLUE%^slides back, "
      "revealing a stairway leading down.%^RESET%^");
   add_item("pedestal","The pedestal is currently out of place, "
      "revealing a stairway down.  If you wanted, you could <slide> it closed.");
   call_out("set_auto_closed",15);
   return;
}

void set_auto_closed(){
   tell_room(TO,"%^BOLD%^%^BLACK%^The dragon's %^RESET%^%^ORANGE%^e%^YELLOW%^y%^RESET%^"
      "%^ORANGE%^es %^BOLD%^%^BLACK%^flash as the pedestal slides back into place.%^RESET%^");
   set_sil_closed();
   return;
}

void set_sil_closed(){
   OPEN = 0;
   TO->remove_exit("down");
   redo_constellations();
   add_item("pedestal","%^BOLD%^%^WHITE%^This smooth marble pedestal is "
      "oddly large.  Atop it sits a %^BLACK%^marble statue %^WHITE%^of "
      "a %^BLACK%^coiled dragon%^WHITE%^.  In the front of the pedestal, "
      "you can make out a single indentation.%^RESET%^");
   return;
}

int close_pedestal(string str){
   if(!str) return 1;
   if(str != "pedestal" && str != "dragon" && str != "door" && str != "exit"){
      tell_object(TP,"If you are trying to slide the pedestal back in place, "
         "please <slide pedestal>.");
      return 1;
   }
   if((string)TO->query_exit("down") == "/d/player_houses/silesse/dungeon"){
      tell_room(TO,"%^BOLD%^%^BLACK%^The dragon's %^RESET%^%^ORANGE%^e%^YELLOW%^y%^RESET%^"
         "%^ORANGE%^es %^BOLD%^%^BLACK%^flash as the pedestal slides back into place.%^RESET%^");
      set_sil_closed();
      return 1;
   }
   tell_object(TP,"The pedestal is already covering the exit!");
   return 1;
}

int insert_key(string str){
   string key, statue;
   if(!str) return 0;
   if((sscanf(str, "%s into %s", key, statue)) !=2) return 0;
/*   if(key != "key" && str != "faerzress"){
      tell_object(TP,"That only works if you <insert key into pedestal>.");
      return 1;
   }
*/
   if(statue != "statue" && statue != "pedestal" && statue != "indentation"){
      tell_object(TP,"That only works if you <insert key into pedestal>.");
      return 1;
   }
   if(!(present(key,this_player())->is_faerzress_key())){
      tell_object(TP,"That "+key+" will not fit into the pedestal!");
      return 1;
   }
   tell_object(TP,"%^BOLD%^%^BLACK%^You insert your %^RESET%^%^MAGENTA%^faer"
      "%^BOLD%^z%^RESET%^%^MAGENTA%^ress %^BOLD%^%^BLACK%^into the hole "
      "in the scrollwork of the pedestal and step back.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" inserts a %^RESET%^%^MAGENTA%^"
      "pur%^BOLD%^p%^RESET%^%^MAGENTA%^le stone %^BOLD%^BLACK%^into a hole "
      "in the scrollwork of the pedestal and steps back.%^RESET%^",TP);
   tell_room(TO,"%^BOLD%^%^BLACK%^A puff of %^RESET%^%^sm%^BOLD%^o%^RESET%^ke "
      "%^BOLD%^%^BLACK%^emerges from the dragon's nostrils as the pedestal "
      "slides back smoothly, revealing an exit down.%^RESET%^");
   set_sil_open();
   return 1;
}


int go_home(string str){
   if(!objectp(TP)) return 1;
   if(member_array(TP->query_name(), owners) == -1){
      tell_object(TP,"You murmur something, but nothing happens.");
      return 1;
   }
   if(!str || str != "statue" && str != "pedestal" && str != "dragon"){
      tell_object(TP,"To get safely inside, you need to <murmur dragon>.");
      return 1;
   }
   tell_object(TP,"Looking directly at the statue, you murmur the "
      "ancient words of opening.");
   TP->force_me("say Pahntar cuass'ili!");
   tell_object(TP,"In response to your words, the dragon's %^ORANGE%^e"
      "%^YELLOW%^y%^RESET%^%^ORANGE%^es %^RESET%^flash and then grown "
      "dim before the pedestal slides back, revealing stairs leading below.");
   tell_room(TO,"In response to "+TPQCN+"'s words, the dragon's %^ORANGE%^e"
      "%^YELLOW%^y%^RESET%^%^ORANGE%^es %^RESET%^flash and then grown "
      "dim before the pedestal slides back, revealing stairs leading below.",TP);
   set_sil_open();
   return 1;
}

int observe_stars(string str){
   if(!str){
      tell_object(TP,"Try to <observe stars> here.");
      return 1;
   }
   if(str != "stars" && str != "sky" && str != "constellations"){
      tell_object(TP,"Try to <observe stars> here.");
      return 1;
   }
   if((object)TP->query_attackers() != ({})){
      notify_fail("You're too busy to do that right now!\n");
      return 1;
   }
   if((int)TP->query_level() < 20){
      tell_object(TP,"The stars seem to blur as you study them, and you "
         "can't make any sense of them.");
      return 1;
   }
   tell_object(TP,"%^BOLD%^%^BLUE%^You look up, studying the "
      "constellations closely until they resolve into the "
      "following:%^RESET%^\n");
   tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" peers up, studying the "
      "constellations intently.%^RESET%^",TP);
   TP->more(OBJ"constellations");
   tell_object(TP,"\n%^BOLD%^%^CYAN%^You feel a strange urge to reach "
      "into the air and trace the shape of the constellations with "
      "your finger - but which would you trace?%^RESET%^");
   return 1;
}

int failure(){
   tell_object(TP,"You trace the constellation in the sky with your finger, but nothing happens.");
   tell_room(TO,""+TPQCN+" traces a constellation in the sky with "+TP->QP+" fingertip.",TP);
   tell_object(TP,"%^%^BOLD%^BLACK%^Suddenly, the %^WHITE%^stars %^BLACK%^all "
      "shift, swirling and converging, growing brighter and brighter.  A bolt "
      "of %^CYAN%^energy %^BLACK%^shoots out, shocking you!");
   tell_room(TO,"%^%^BOLD%^BLACK%^Suddenly, the %^WHITE%^stars %^BLACK%^all "
      "shift, swirling and converging, growing brighter and brighter.  A bolt "
      "of %^CYAN%^energy %^BLACK%^shoots out, shocking "+TPQCN+"!",TP);
   TP->do_damage("head",((int)TP->query_hp()/4));
   step1 = 0;
   step2 = 0;
   step3 = 0;
   return 1;
}

int trace_constellation(string str){
   string seas = season(time());
   if((object)TP->query_attackers() != ({})){
      notify_fail("You're too busy to do that right now!\n");
      return 1;
   }
   if(!str){
      tell_object(TP,"You must choose a constellation to trace!");
      return 1;
   }
   if(!step1){
      switch(str){
         case "kite":
         case "kite constellation":  if(seas == "winter"){
                          successful_rune(str);
                          step1 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "ship":
         case "ship constellation":  if(seas == "spring"){
                          successful_rune(str);
                          step1 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "salamander":
         case "salamander constellation":  if(seas == "summer"){
                          successful_rune(str);
                          step1 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "spider":
         case "spider constellation":  if(seas == "autumn"){
                          successful_rune(str);
                          step1 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         default:  failure();
                   return 1;
                   break;
      }
   return 1;
   }
   if((step1) && (!step2)){
      switch(str){
         case "pegasus":
         case "pegasus constellation":  if(seas == "winter"){
                          successful_rune(str);
                          step2 = 1;
                          return 1;
                    }else{
                          failure();
                          return 1;
                       }
                       break;
         case "hydra":
         case "hydra constellation":  if(seas == "spring"){
                          successful_rune(str);
                          step2 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "rakshasa":
         case "rakshasa constellation":  if(seas == "summer"){
                          successful_rune(str);
                          step2 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "deer":
         case "deer constellation":  if(seas == "autumn"){
                          successful_rune(str);
                          step2 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         default:  failure();
                   return 1;
                   break;
      }
   return 1;
   }
   if((step1) && (step2) && (!step3)){
      switch(str){
         case "avariel":
         case "avariel constellation":  if(seas == "winter"){
                          successful_rune(str);
                          step3 = 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "naiad":
         case "naiad constellation":  if(seas == "spring"){
                          successful_rune(str);
                          step3 = 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "dragon":
         case "dragon constellation":  if(seas == "summer"){
                          successful_rune(str);
                          step3 = 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "boar":
         case "boar constellation":  if(seas == "autumn"){
                          successful_rune(str);
                          step3 = 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         default:  failure();
                   return 1;
                   break;
      }
   }
   if(GUARD){
      tell_object(TP,"%^BOLD%^%^BLUE%^As you trace the final constellation, "+
         "all the constellations begin to %^CYAN%^glow%^BLUE%^.  The "
         "%^BLACK%^dragon's %^BLUE%^wings creak as they spread and grow "
         "before the dragon springs to life!%^RESET%^");
      tell_room(TO,"%^BOLD%^%^BLUE%^As "+TPQCN+" traces the final constellation, "+
         "all the constellations begin to %^CYAN%^glow%^BLUE%^.  The "
         "%^BLACK%^dragon's %^BLUE%^wings creak as they spread and grow "
         "before the dragon springs to life!%^RESET%^",TP);
      new(OBJ"silesse_dragon")->move(TO);
      return 1;
   }else{
      tell_object(TP,"^%^BOLD%^%^BLUE%^As you trace the final constellation, all "+
         "the constellations begin to %^CYAN%^glow%^BLUE%^.");
      tell_room(TO,"^%^BOLD%^%^BLUE%^As "+TPQCN+" traces the final constellation, all "+
         "the constellations begin to %^CYAN%^glow%^BLUE%^.",TP);
      set_sil_open();
      return 1;
   }
   tell_object(TP,"You must choose the name of a constellation to trace!");
   return 1;
}

void successful_rune(string str){
   tell_object(TP,"%^BOLD%^%^BLUE%^As you trace your finger through the air, "
      "the %^CYAN%^"+str+" %^BLUE%^constellation flashes and then fades to "
      "a soft %^WHITE%^glow%^BLUE%^.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^BLUE%^"+TPQCN+" traces "+TP->QP+" through the "
      "air, and a constellation flashes and then fades to a soft %^WHITE%^"
      "glow%^BLUE%^.%^RESET%^",TP);
   tell_room(TO,"%^BOLD%^%^BLACK%^A puff of %^RESET%^sm%^BOLD%^o%^RESET%^ke "
      "%^BOLD%^%^BLACK%^pours from the dragon's nostrils as its %^RESET%^"
      "%^ORANGE%^e%^YELLOW%^y%^RESET%^%^ORANGE%^es %^BOLD%^%^BLACK%^smolder.%^RESET%^");
   tell_room(find_object_or_load("/d/player_houses/silesse/dungeon.c"),"%^BOLD%^A "
      "%^BLACK%^chime %^WHITE%^sounds throughout the room.%^RESET%^",TP);
   return;
}
