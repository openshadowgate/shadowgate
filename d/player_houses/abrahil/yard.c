//Coded by Styx for Abrahil
//search flower to get key

#include <std.h>

inherit VAULT;
int searched;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_name("forest clearing");
    set_short("A forest clearing");
    set_long("Having pushed your way through the brush, you find an "
"%^ORANGE%^unusual earthen mound %^RESET%^with a simple wooden door closing "
"off an opening in the front.  The area flourishes with wildlife and that seems "
"to be thriving in the lush surroundings.  You feel a great sense of "
"tranquility in this secluded place.  %^RED%^F%^YELLOW%^l%^GREEN%^o"
"%^MAGENTA%^w%^BOLD%^%^WHITE%^e%^BLUE%^r%^RED%^s %^RESET%^with "
"vibrant colors and various small plants dot the mound and the landscape "
"surrounding it, allowing what is likely someone's abode to blend in "
"unobtrusively with the natural surroundings.  A few earthen dug windows "
"surround the dwelling and you see light from within."
   );
   set_items(([
     "windows" : "These windows are hard to see through although you do catch "
       "a glimpse of light from the inside.",
     "mound" : "A large earthen mound, covered with beautiful vegetation.",
     ({"flowers", "plants"}) : "%^GREEN%^Lush green foliage %^RESET%^and vibrant "
        "colors on the flowers' blooms indicate they thrive here.",
   ] ));
   set_exits(([
       "enter" : "/d/player_houses/abrahil/main",
       "brush" : "/d/antioch/wild/forest/trail6"
   ] ));
   set_search("flower", (: TO, "search_it" :) );
   set_door("door","/d/player_houses/abrahil/main","enter","Abrahil house key");
   set_door_description("door","This is a strong oak door that is hinged well."
      "  It has a small knocker upon the door.");
   set_locked("door",1,"lock");
   lock_difficulty("door", "/daemon/player_housing"->get_phouse_lock_dc("epic"),"lock");
   set_smell("default","The flowers exude an almost intoxicating fragrance.");
   set_listen("default","You hear small animals scurrying through the undergrowth.");
}

void init() {
   ::init();
   add_action("get_key","pull");
}

void reset() {
   ::reset();
   searched = 0;
}

int get_key(string str) {
   if(str != "key from flower")                    return 1;
   if( (string)TPQN != "abrahil" && !avatarp(TP) ) return 1;
   if(searched > 1) {
      tell_object(TP,"The key is missing.");
      return 1;
   }
   new("/d/player_houses/obj/abrahil_key")->move(TP);
   tell_room(ETP,TPQCN+" reaches down and pull something from one of the "
      "flowers.", TP);
   tell_object(TP,"You reach down and pull your hidden key from the flower.");
   searched++;
   return 1;
}

void search_it(string str) {
   if(searched) {
     write("It looks like someone searched those recently.");
     return;
   }
   write("You search the flower and find a key.");
   tell_room(ETP,TPQCN+" searches around and pulls something from a flower.", TP);
   new("/d/player_houses/obj/abrahil_key")->move(TP);
   searched = 1;
   return;
} 