


#include <std.h>
#include <daemons.h>
#include "sil.h"

inherit CROOM;

void create() {
   ::create();
   set_pre_exit_functions(({"north","south","east","west","northeast","northwest","southeast","southwest"}),({"go_in","go_in","go_in","go_in","go_in","go_in","go_in","go_in"}));
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
   set_property("light",2);
   set_name("%^RESET%^%^GREEN%^A %^CYAN%^tra%^GREEN%^nq%^CYAN%^uil %^GREEN%^fo%^BOLD%^re%^RESET%^%^GREEN%^st%^RESET%^");
   set_short("%^RESET%^%^GREEN%^A %^CYAN%^tra%^GREEN%^nq%^CYAN%^uil %^GREEN%^fo%^BOLD%^re%^RESET%^%^GREEN%^st%^RESET%^");
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_smell("default","%^RESET%^%^GREEN%^The fresh scent of the forest is intoxicating.%^RESET%^");
   set_listen("default","%^RESET%^%^CYAN%^The steady hum of %^GREEN%^fo%^BOLD%^re%^RESET%^%^GREEN%^st"
" %^BOLD%^l%^RESET%^%^GREEN%^i%^BOLD%^fe %^RESET%^%^CYAN%^can be heard all around you.%^RESET%^");
set_items(([
"trees":"%^RESET%^%^GREEN%^Large trees tower above you in this ancient forest, casting %^BOLD%^%^BLACK%^shadow %^RESET%^%^GREEN%^over everything beneath.",
({"plants", "ferns"}):"%^BOLD%^%^GREEN%^All along the floor of this forest, various leafy ferns grow, along with a whole array of %^BLUE%^fl%^WHITE%^o%^BLUE%^W%^CYAN%^e%^BLUE%^r%^WHITE%^i%^CYAN%^n%^BLUE%^g %^GREEN%^plants, making this forest appear lush and in prime health.%^RESET%^",
"vines":"%^RESET%^%^GREEN%^Many leafy vines snake their way around the %^ORANGE%^trunks %^GREEN%^of the trees and allow their leafy tendrils of growth to add depth to the multiple layers of forest found here.  Some of the vines even find their way to the lowest hanging branches and cover them in a thick carpet of foliage, offering a multitude of hiding places for whatever animals might reside here.%^RESET%^",
"moss":"%^BOLD%^%^GREEN%^Whatever parts of the forest floor that can be seen through the foliage and ferns, is covered in a thick, lush carpet of moss.%^RESET%^",
"mist":"%^BOLD%^%^WHITE%^A thin layer of mist seems to cling to the forest floor, blanketing everything in an ethereal haze.%^RESET%^",
]));
}
string long_desc() {
   return("%^RESET%^%^GREEN%^Sweet %^BOLD%^nature %^RESET%^%^GREEN%^sings it's %^CYAN%^peaceful lullaby %^GREEN%^in this %^BOLD%^magestic"
" %^RESET%^%^GREEN%^and %^CYAN%^tra%^GREEN%^n%^CYAN%^quil %^BOLD%^%^GREEN%^fo%^RESET%^%^GREEN%^re%^BOLD%^st%^RESET%^%^GREEN%^, where the"
" %^BOLD%^t%^RESET%^%^GREEN%^r%^BOLD%^ees %^RESET%^%^GREEN%^grow to be hundreds of feet tall.  A few shifting patterns of"
" %^YELLOW%^su%^RESET%^%^ORANGE%^nl%^BOLD%^ight %^RESET%^%^GREEN%^manage to find their way through the %^BOLD%^ca%^RESET%^%^GREEN%^n%^BOLD%^opy"
" %^RESET%^%^GREEN%^to the thin layer of %^RESET%^m%^BOLD%^i%^RESET%^st %^GREEN%^coating the %^BOLD%^m%^RESET%^%^GREEN%^o%^BOLD%^ss"
" %^RESET%^%^GREEN%^covered %^BOLD%^fo%^RESET%^%^GREEN%^re%^BOLD%^st %^RESET%^%^GREEN%^floor, reflecting off of it in a"
" %^CYAN%^m%^BOLD%^a%^RESET%^%^CYAN%^g%^BOLD%^ic%^RESET%^%^CYAN%^al%^GREEN%^, %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en"
" h%^RESET%^%^ORANGE%^u%^YELLOW%^e %^RESET%^%^GREEN%^that %^YELLOW%^i%^RESET%^%^ORANGE%^ll%^YELLOW%^umin%^RESET%^%^ORANGE%^a%^YELLOW%^tes"
" %^RESET%^%^GREEN%^the %^BOLD%^ferns %^RESET%^%^GREEN%^and various"
" %^BOLD%^%^BLUE%^fl%^WHITE%^o%^BLUE%^w%^CYAN%^e%^BLUE%^r%^WHITE%^i%^CYAN%^n%^BLUE%^g %^GREEN%^pl%^RESET%^%^GREEN%^a%^BOLD%^nts"
" %^RESET%^%^GREEN%^scattered between the %^BOLD%^v%^RESET%^%^GREEN%^i%^BOLD%^ne %^RESET%^%^GREEN%^laden %^ORANGE%^trunks%^GREEN%^."
"  If one were not skilled in the %^BOLD%^f%^RESET%^%^GREEN%^or%^RESET%^%^GREEN%^e%^BOLD%^sts%^RESET%^%^GREEN%^, it would be easy to get lost here.\n");
}
string night_desc() {
   return("%^RESET%^%^GREEN%^Sweet %^BOLD%^nature %^RESET%^%^GREEN%^sings it's %^CYAN%^peaceful lullaby %^GREEN%^in this %^BOLD%^magestic"
" %^RESET%^%^GREEN%^and %^CYAN%^tra%^GREEN%^n%^CYAN%^quil %^BOLD%^%^GREEN%^fo%^RESET%^%^GREEN%^re%^BOLD%^st%^RESET%^%^GREEN%^, where the"
" %^BOLD%^t%^RESET%^%^GREEN%^r%^BOLD%^ees %^RESET%^%^GREEN%^grow to be hundreds of feet tall.  A few shifting patterns of"
" %^BOLD%^%^WHITE%^moonl%^RESET%^i%^BOLD%^ght %^RESET%^%^GREEN%^manage to find their way through the %^BOLD%^ca%^RESET%^%^GREEN%^n%^BOLD%^opy"
" %^RESET%^%^GREEN%^to the thin layer of %^RESET%^m%^BOLD%^i%^RESET%^st %^GREEN%^coating the %^BOLD%^m%^RESET%^%^GREEN%^o%^BOLD%^ss"
" %^RESET%^%^GREEN%^covered %^BOLD%^fo%^RESET%^%^GREEN%^re%^BOLD%^st %^RESET%^%^GREEN%^floor, reflecting off of it in a"
" %^CYAN%^m%^BOLD%^a%^RESET%^%^CYAN%^g%^BOLD%^ic%^RESET%^%^CYAN%^al%^GREEN%^,"
" %^BOLD%^%^WHITE%^si%^RESET%^lv%^BOLD%^ery h%^RESET%^u%^BOLD%^e %^RESET%^%^GREEN%^that"
" %^BOLD%^%^WHITE%^ill%^RESET%^um%^BOLD%^in%^RESET%^a%^BOLD%^tes %^RESET%^%^GREEN%^the %^BOLD%^ferns %^RESET%^%^GREEN%^and various"
" %^BOLD%^%^BLUE%^fl%^WHITE%^o%^BLUE%^w%^CYAN%^e%^BLUE%^r%^WHITE%^i%^CYAN%^n%^BLUE%^g %^GREEN%^pl%^RESET%^%^GREEN%^a%^BOLD%^nts"
" %^RESET%^%^GREEN%^scattered between the %^BOLD%^v%^RESET%^%^GREEN%^i%^BOLD%^ne %^RESET%^%^GREEN%^laden %^ORANGE%^trunks%^GREEN%^."
"  If one were not skilled in the %^BOLD%^f%^RESET%^%^GREEN%^or%^RESET%^%^GREEN%^e%^BOLD%^sts%^RESET%^%^GREEN%^, it would be easy to get lost here.\n");
}
void reset() {
   ::reset();
   switch(random(10)) {
     case 0..1:
     tell_room(TO,"%^RESET%^%^ORANGE%^The noisy chatter of squirrels breaks the %^RESET%^silence %^ORANGE%^as they scamper over the"
" %^GREEN%^l%^BOLD%^ea%^RESET%^%^GREEN%^fy branches %^ORANGE%^in their playful chase.");
     break;
     case 2:
     tell_room(TO,"%^RESET%^%^GREEN%^The sound of %^BOLD%^%^CYAN%^si%^RESET%^%^CYAN%^ng%^BOLD%^ing %^GREEN%^dryads %^RESET%^%^GREEN%^floats through"
" the %^RESET%^a%^BOLD%^i%^RESET%^r %^GREEN%^like an %^CYAN%^i%^BOLD%^nto%^RESET%^%^CYAN%^xi%^BOLD%^ca%^RESET%^%^CYAN%^t%^BOLD%^i%^RESET%^%^CYAN%^ng"
" %^BOLD%^d%^RESET%^%^CYAN%^r%^BOLD%^e%^RESET%^%^CYAN%^a%^BOLD%^m%^RESET%^%^GREEN%^.%^RESET%^");
     break;
     case 3:
     tell_room(TO,"%^RESET%^A faint %^BOLD%^br%^RESET%^ee%^BOLD%^ze %^RESET%^brushes past your face, carrying with it the"
" quiet %^BOLD%^whi%^RESET%^sp%^BOLD%^ers %^RESET%^of the %^GREEN%^t%^BOLD%^ree%^RESET%^%^GREEN%^s%^RESET%^.");
     break;
     case 4..5:
     tell_room(TO,"%^BOLD%^%^WHITE%^Tiny %^YELLOW%^bu%^RESET%^%^CYAN%^tte%^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^f%^MAGENTA%^l%^YELLOW%^ies %^WHITE%^flutter"
" around you in an elaborate, %^CYAN%^swi%^RESET%^%^CYAN%^rl%^BOLD%^ing dance %^WHITE%^before disappearing into the %^GREEN%^forests"
" %^RESET%^%^GREEN%^dense %^BOLD%^ca%^RESET%^%^GREEN%^no%^BOLD%^py%^YELLOW%^.%^RESET%^");
     break;
     case 6..7:
   tell_room(TO,"%^BOLD%^%^GREEN%^A brief flash of movement from a %^BLUE%^b%^WHITE%^i%^BLUE%^rd %^GREEN%^in the"
" %^RESET%^%^GREEN%^tre%^BOLD%^eto%^RESET%^%^GREEN%^ps %^BOLD%^catches your eyes, but disappears in a flash of"
" %^BOLD%^%^BLUE%^c%^YELLOW%^o%^RED%^lo%^YELLOW%^r%^BLUE%^f%^CYAN%^u%^BLUE%^l %^CYAN%^w%^BLUE%^i%^RESET%^%^CYAN%^n%^BOLD%^g%^BLUE%^s%^RESET%^%^GREEN%^.");
     break;
     case 8..9:
     if (season(time()) == "winter") {
       tell_room(TO,"%^RESET%^%^GREEN%^A few small %^BOLD%^%^WHITE%^sno%^RESET%^fl%^BOLD%^akes %^RESET%^%^GREEN%^fall lightly from the"
" %^BOLD%^tr%^RESET%^%^GREEN%^ee%^BOLD%^s %^RESET%^%^GREEN%^to %^RESET%^d%^BOLD%^u%^RESET%^st %^GREEN%^the forest floor.%^RESET%^");
     }
     else {
       tell_room(TO,"%^RESET%^%^GREEN%^A small %^BOLD%^%^WHITE%^rabbit%^RESET%^%^GREEN%^ rises on its hind legs, pausing to wiggle its"
" %^RESET%^whi%^BOLD%^%^BLACK%^sk%^RESET%^ers %^GREEN%^curiously at you before hopping off.");
     }
     break;
   }
}


int go_in(string str){
   if(!avatarp(TP) && (string)TP->query_name() != "vicdaerrysn") {
   
   tell_room(TP,"%^RESET%^%^GREEN%^A soft %^RESET%^br%^BOLD%^ee%^RESET%^ze %^GREEN%^blows through the %^BOLD%^tr%^RESET%^%^GREEN%^ee%^BOLD%^s%^RESET%^%^GREEN%^.",TO);
      if(!find_living("vicdaerrysn")){return 1;}
   if(present(find_player("vicdaerrysn"),(find_object_or_load("/d/player_houses/silesse/forest1.c")))){
         tell_room(find_player("vicdaerrysn"),"%^RESET%^%^GREEN%^A soft %^RESET%^br%^BOLD%^ee%^RESET%^ze %^GREEN%^rustles the %^BOLD%^forest canopy%^RESET%^%^GREEN%^, bringing with it the %^RESET%^whi%^BOLD%^sp%^RESET%^ers %^GREEN%^of the %^BOLD%^trees %^RESET%^%^GREEN%^that warn you "+TP->query_short()+" is wandering through.%^RESET%^");
      return 1;
      }
      if(present(find_player("vicdaerrysn"),(find_object_or_load("/d/player_houses/silesse/forest2.c")))){
         tell_room(find_player("vicdaerrysn"),"%^RESET%^%^GREEN%^A soft %^RESET%^br%^BOLD%^ee%^RESET%^ze %^GREEN%^rustles the %^BOLD%^forest canopy%^RESET%^%^GREEN%^, bringing with it the %^RESET%^whi%^BOLD%^sp%^RESET%^ers %^GREEN%^of the %^BOLD%^trees %^RESET%^%^GREEN%^that warn you "+TP->query_short()+" is wandering through.%^RESET%^");
      return 1;
      }
      if(present(find_player("vicdaerrysn"),(find_object_or_load("/d/player_houses/silesse/forest3.c")))){
         tell_room(find_player("vicdaerrysn"),"%^RESET%^%^GREEN%^A soft %^RESET%^br%^BOLD%^ee%^RESET%^ze %^GREEN%^rustles the %^BOLD%^forest canopy%^RESET%^%^GREEN%^, bringing with it the %^RESET%^whi%^BOLD%^sp%^RESET%^ers %^GREEN%^of the %^BOLD%^trees %^RESET%^%^GREEN%^that warn you "+TP->query_short()+" is wandering through.%^RESET%^");
      return 1;
      }
      if(present(find_player("vicdaerrysn"),(find_object_or_load("/d/player_houses/silesse/forest4.c")))){
         tell_room(find_player("vicdaerrysn"),"%^RESET%^%^GREEN%^A soft %^RESET%^br%^BOLD%^ee%^RESET%^ze %^GREEN%^rustles the %^BOLD%^forest canopy%^RESET%^%^GREEN%^, bringing with it the %^RESET%^whi%^BOLD%^sp%^RESET%^ers %^GREEN%^of the %^BOLD%^trees %^RESET%^%^GREEN%^that warn you "+TP->query_short()+" is wandering through.%^RESET%^");
      return 1;
      }
      if(present(find_player("vicdaerrysn"),(find_object_or_load("/d/player_houses/silesse/forest5.c")))){
         tell_room(find_player("vicdaerrysn"),"%^RESET%^%^GREEN%^A soft %^RESET%^br%^BOLD%^ee%^RESET%^ze %^GREEN%^rustles the %^BOLD%^forest canopy%^RESET%^%^GREEN%^, bringing with it the %^RESET%^whi%^BOLD%^sp%^RESET%^ers %^GREEN%^of the %^BOLD%^trees %^RESET%^%^GREEN%^that warn you "+TP->query_short()+" is wandering through.%^RESET%^");
      return 1;
      }
      if(present(find_player("vicdaerrysn"),(find_object_or_load("/d/player_houses/silesse/forest6.c")))){
         tell_room(find_player("vicdaerrysn"),"%^RESET%^%^GREEN%^A soft %^RESET%^br%^BOLD%^ee%^RESET%^ze %^GREEN%^rustles the %^BOLD%^forest canopy%^RESET%^%^GREEN%^, bringing with it the %^RESET%^whi%^BOLD%^sp%^RESET%^ers %^GREEN%^of the %^BOLD%^trees %^RESET%^%^GREEN%^that warn you "+TP->query_short()+" is wandering through.%^RESET%^");
      return 1;
      }
      if(present(find_player("vicdaerrysn"),(find_object_or_load("/d/player_houses/silesse/forest7.c")))){
         tell_room(find_player("vicdaerrysn"),"%^RESET%^%^GREEN%^A soft %^RESET%^br%^BOLD%^ee%^RESET%^ze %^GREEN%^rustles the %^BOLD%^forest canopy%^RESET%^%^GREEN%^, bringing with it the %^RESET%^whi%^BOLD%^sp%^RESET%^ers %^GREEN%^of the %^BOLD%^trees %^RESET%^%^GREEN%^that warn you "+TP->query_short()+" is wandering through.%^RESET%^");
      return 1;
      }
      if(present(find_player("vicdaerrysn"),(find_object_or_load("/d/player_houses/silesse/forest8.c")))){
         tell_room(find_player("vicdaerrysn"),"%^RESET%^%^GREEN%^A soft %^RESET%^br%^BOLD%^ee%^RESET%^ze %^GREEN%^rustles the %^BOLD%^forest canopy%^RESET%^%^GREEN%^, bringing with it the %^RESET%^whi%^BOLD%^sp%^RESET%^ers %^GREEN%^of the %^BOLD%^trees %^RESET%^%^GREEN%^that warn you "+TP->query_short()+" is wandering through.%^RESET%^");
      return 1;
      }
      if(present(find_player("vicdaerrysn"),(find_object_or_load("/d/player_houses/silesse/clearing.c")))){
         tell_room(find_player("vicdaerrysn"),"%^RESET%^%^GREEN%^A soft %^RESET%^br%^BOLD%^ee%^RESET%^ze %^GREEN%^rustles the %^BOLD%^forest canopy%^RESET%^%^GREEN%^, bringing with it the %^RESET%^whi%^BOLD%^sp%^RESET%^ers %^GREEN%^of the %^BOLD%^trees %^RESET%^%^GREEN%^that warn you "+TP->query_short()+" is wandering through.%^RESET%^");
      return 1;
   }
   return 1;
   }
return 1;
}
void init() {
   ::init();
   if(!avatarp(TP) && (string)TP->query_name() != "silesse" && (string)TP->query_name() != "vicdaerrysn") {
   add_action("peer","peer");
   }
}

int peer() {
   write("%^RESET%^%^GREEN%^You try to peer around but it all looks the same to you.");
        return 1;
}
