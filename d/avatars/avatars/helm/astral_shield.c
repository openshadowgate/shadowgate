#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("device");
   set_id(({ "astral shield", "device", "polyhedron", "stone", "pyramid",
"pyramid-shape", "strange stone" }));
   set_short("%^RESET%^%^CYAN%^An astral shield device%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A strange pyramid-shaped stone%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This rough, pyramid-shaped device appears to be made out of a dark stone and it"
" is very cold to the touch. Shallow runes have been carved on the surface of this blood-stained polyhedron and"
" they glow as you let your fingertips brush over them. It fits comfortably in your hand though and appears to be"
" slightly heavier than its size alone would tell you.");
   set_weight(5);
   set_value(0);
   set_lore("The astral shield device is an age-old invention. When activated it surrounds the wearer"
" with a powerful wall of force, effectively shielding him and possibly another person from the contact of"
" beings from other planes of existence. The wall of force is held for as long as the device is active."
" But remember this: Devices like this seldom have more than one or two uses.");
   set_property("lore difficulty",30);
}
void init(){
    ::init();
    add_action("activate","activate");
}
int activate(string str){
   if(!str) notify_fail("Activate what?\n");
   if(str = "shield"||"astral shield"||"device"||"stone"||"pyramid"||"polyhedron"){
      call_out("message",1,ETO);
   return 1;
   }
}
void message(){
   tell_room(EETO,"%^RESET%^%^CYAN%^"+ETO->query_cap_name()+" holds out "+ETO->query_possessive()+" hand and displays a strange pyramid-shaped stone.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^CYAN%^You hold out your hand and display a strange pyramid-shaped stone.%^RESET%^");
   call_out("message2",3,ETO);
}
void message2(){
   tell_room(EETO,"%^RESET%^%^CYAN%^"+ETO->query_cap_name()+" utters a single word: %^BOLD%^Anassur!%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^CYAN%^You utter a single word: %^BOLD%^Anassur!%^RESET%^");
   call_out("message3",0,ETO);
}
void message3(){
   tell_room(EETO,"%^RESET%^%^CYAN%^With a sudden %^BOLD%^flash%^RESET%^%^CYAN%^ the runes on the pyramid-shaped stone light up and several faint lines become visible surrounding the polyhedron.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^CYAN%^With a sudden %^BOLD%^flash%^RESET%^%^CYAN%^ the runes on the pyramid-shaped stone light up and several faint lines become visible surrounding the polyhedron.%^RESET%^");
   call_out("message4",1,ETO);
}
void message4(){
   tell_room(EETO,"%^RESET%^%^CYAN%^As they expand they grow dimmer until they surround "+ETO->query_cap_name()+" completely.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^CYAN%^As they expand they grow dimmer until they surround you completely.%^RESET%^");
}




