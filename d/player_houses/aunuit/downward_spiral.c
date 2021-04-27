//Ryzan and Aunuit's House
//Coded by ~Circe~ 7/24/13

#include <std.h>
#include "aunuit.h"

inherit AUNUIT;

void create(){
   ::create();
   set_name("Downward spiral");
   set_short("%^BOLD%^%^BLACK%^Downward spiral%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Cut directly from the rough "
      "eb%^RESET%^o%^BOLD%^%^BLACK%^n bed rock this stairwell "
      "curves round like the interior of a snail's shell, "
      "descending steeply as it does. Fl%^WHITE%^e%^BLACK%^cks "
      "of sm%^RESET%^o%^BOLD%^%^BLACK%^ky qu%^RESET%^a%^BOLD%^"
      "%^WHITE%^r%^BLACK%^tz are present in the dark st%^RESET%^o"
      "%^BOLD%^%^BLACK%^ne and patches of %^CYAN%^flu%^GREEN%^o"
      "%^CYAN%^r%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^sc%^GREEN%^e%^CYAN%^nt "
      "l%^WHITE%^i%^CYAN%^ch%^GREEN%^e%^CYAN%^n %^BLACK%^provide "
      "faint %^WHITE%^illumination %^BLACK%^for navigating the "
      "precipitous m%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^rble steps.%^RESET%^\n");
   set_smell("default","%^RESET%^%^CYAN%^Cool and still the air "
      "is tinged with incense.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^The solid stone surfaces "
      "and foreboding silence augment any external sounds.%^RESET%^");
   set_items(([
      ({"ceiling","walls","wall"}) : "%^BOLD%^%^BLACK%^In stark "
         "contrast to the smooth, glo%^WHITE%^s%^RESET%^s%^BOLD%^"
         "%^BLACK%^y stairs are the %^RESET%^%^ORANGE%^rough %^BOLD%^"
         "%^BLACK%^surfaces of the walls and vaulted ceiling. Sm%^RESET%^"
         "o%^BOLD%^%^BLACK%^ky qu%^RESET%^a%^BOLD%^%^WHITE%^r%^BLACK%^tz "
         "%^RESET%^cr%^BOLD%^%^BLACK%^y%^RESET%^st%^BOLD%^%^WHITE%^a"
         "%^RESET%^ls %^BOLD%^%^BLACK%^dot their dark rock like "
         "%^WHITE%^stars %^BLACK%^in the %^RESET%^%^BLUE%^midnight "
         "sky %^BOLD%^%^BLACK%^and patches of %^CYAN%^flu%^GREEN%^o"
         "%^CYAN%^r%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^sc%^GREEN%^e"
         "%^CYAN%^nt l%^WHITE%^i%^CYAN%^ch%^GREEN%^e%^CYAN%^n "
         "%^BLACK%^provide faint %^WHITE%^illumination%^BOLD%^%^BLACK%^.%^RESET%^"
   ]));
   set_exits(([
      "down" : ROOMS"downward_spiral_2",
      "up" : ROOMS"maw"
   ]));
}

void reset(){
   ::reset();
   switch(random(3)){
      case 0: tell_room(TO,"%^BOLD%^%^BLACK%^A soft hiss issues from deep "
              "within the darkness.%^RESET%^");
              break;
      case 1: tell_room(TO,"%^RESET%^%^MAGENTA%^A playful giggle erupts "
              "from somewhere nearby, echoing off the stone walls.%^RESET%^");
              break;
      default: tell_room(TO,"%^RESET%^%^RED%^Within the darkness, a sweet "
               "voice hums a haunting melody, swelling until it seems right "
               "beside you before fading.%^RESET%^");
               break;
   }
}