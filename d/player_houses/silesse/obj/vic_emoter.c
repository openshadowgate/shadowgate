//Fireplace and faerie fire emotes for Vic's room
//Based on my Seneca wave maker
//~Circe~ 8/3/13
#include <std.h>

inherit MONSTER;

int count;

void create(){
   ::create();
   set_name("fireplace emoter");
   set_property("no detect",1);
   set_id(({"fireplace_emoter"}));
   set_short(0);
   set_invis();
   add_limb("body","",0,0,0);
   count = 0;
}

void die(object ob){
}

void heart_beat(){
   ::heart_beat();
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   count++;
   if(count == 25){
//was 15 - turning down spam ~Circe~ 6/21/14
      switch(random(6)){
         case 0: tell_room(ETO,"%^BOLD%^%^BLACK%^The lights of the "
                 "%^MAGENTA%^f%^RESET%^%^MAGENTA%^a%^BOLD%^er%^YELLOW%^i%^MAGENTA%^e "
                 "f%^RED%^i%^MAGENTA%^re %^BLACK%^dim, blanketing the room in "
                 "%^RESET%^darkness %^BOLD%^%^BLACK%^for a moment.%^RESET%^");
                 break;
         case 1: tell_room(ETO,"%^RESET%^%^MAGENTA%^The %^BOLD%^%^MAGENTA%^f"
                 "%^RESET%^%^MAGENTA%^a%^BOLD%^er%^YELLOW%^i%^MAGENTA%^e "
                 "f%^RED%^i%^MAGENTA%^re %^RESET%^%^MAGENTA%^dances across "
                 "the %^BOLD%^%^BLACK%^ob%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^idi"+
                 "%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^n ceiling%^RESET%^%^MAGENTA%^, "
                 "creating a %^RESET%^d%^MAGENTA%^a%^BOLD%^z%^RESET%^%^MAGENTA%^z"
                 "%^YELLOW%^l%^MAGENTA%^i%^RESET%^%^MAGENTA%^ng %^MAGENTA%^display.%^RESET%^");
                 break;
         case 2: tell_room(ETO,"%^RESET%^%^ORANGE%^The %^RED%^fi%^BOLD%^r%^RESET%^"
                 "%^RED%^e c%^BOLD%^r%^RESET%^%^RED%^ac%^ORANGE%^k%^RED%^l%^RESET%^"
                 "e%^RED%^s %^ORANGE%^along the hearth, making the %^BOLD%^%^BLACK%^s"
                 "%^RESET%^h%^BOLD%^a%^BLACK%^do%^RESET%^w%^BOLD%^%^BLACK%^s %^RESET%^"
                 "%^ORANGE%^dance.%^RESET%^");
                 break;
         case 3: tell_room(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^RED%^fl%^YELLOW%^"
                 "a%^RESET%^%^RED%^m%^BOLD%^e%^RESET%^%^RED%^s%^RESET%^%^ORANGE%^ %^BOLD%^"
                 "%^BLACK%^damper slightly before a %^RESET%^%^ORANGE%^log "
                 "%^BOLD%^%^BLACK%^cracks, sending up a %^RED%^sp%^YELLOW%^a"
                 "%^RED%^rk%^BLACK%^.%^RESET%^");
                 break;
         case 4: tell_room(ETO,"%^RESET%^%^RED%^The fi%^BOLD%^r%^RESET%^%^RED%^e "
                 "draws your attention, its %^BOLD%^%^RED%^fl%^YELLOW%^"
                 "a%^RESET%^%^RED%^m%^BOLD%^e%^RESET%^%^RED%^s seeming to tug "
                 "at your soul.%^RESET%^");
                 break;
         default: tell_room(ETO,"%^RESET%^%^MAGENTA%^The %^BOLD%^%^MAGENTA%^f%^RESET%^"
                 "%^MAGENTA%^a%^BOLD%^er%^YELLOW%^i%^MAGENTA%^e "
                 "f%^RED%^i%^MAGENTA%^re %^RESET%^%^MAGENTA%^flickers almost playfully in a "
                 "display that looks like countless %^BOLD%^fa%^YELLOW%^i%^MAGENTA%^"
                 "ri%^RESET%^%^MAGENTA%^e%^BOLD%^s%^RESET%^%^MAGENTA%^.%^RESET%^");
                 break;
      }
      count = 0;
   }
}

int do_damage(string str, int i){
    return 0;
}

int is_invincible(){ return 1;}
int is_detectable(){ return 0;}

int id(string str){
   if(objectp(TP) && !avatarp(TP)) return 0;
   else return ::id(str);
}

void set_invis(){
   if(TO->query_invis()) return;
   else ::set_invis();
   return;
}