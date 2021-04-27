//soul storage room for Vicdaerrysn during Loki's plot. 
//Going to make an inherit for other such rooms. ~Circe~ 6/8/14

#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(BARREN);
   set_travel(RUTTED_TRACK);
   set_light(0);
   set_indoors(0);
   set_property("no teleport",1);
   set_property("no scry",1);
   set_name("On a ruined battlefield");
   set_short("%^RESET%^%^RED%^On a ruined battlefield%^RESET%^");
   set_long("Spreading out in every direction are the ruins of a "
      "%^RED%^bat%^BOLD%^t%^RESET%^%^RED%^lef%^RESET%^i%^RED%^eld%^RESET%^. "
      "Corpses in various stages of decay dot the landscape, and some "
      "sort of %^BOLD%^%^BLACK%^ash %^RESET%^or %^BOLD%^%^BLACK%^sm%^RESET%^"
      "o%^BOLD%^%^BLACK%^ke %^RESET%^rises into the air, choking the sky. "
      "A %^RED%^red sun %^RESET%^rises, bathing the land in the color of "
      "the last dying %^RED%^em%^BOLD%^b%^RESET%^%^RED%^er%^RESET%^.\n");
   set_listen("default","The wind whips around your ears, obscuring other sounds.");
   set_smell("default","The air is acrid with the smell of fire and "
      "brimstone tempered by the sweetness of decay.");
   set_search("default","Looking around, you realize you can <gaze> "
      "a target or <sustain> yourself.");
}

void init(){
   ::init();
   add_action("sustain","sustain");
   if(!present("soul window")){
      new("/d/player_houses/death/obj/soul_scry_orb.c")->move(TO);
   }
}

int sustain(){
   tell_object(TP,"You inhale deeply, taking in the fragrance "
      "of smoke and decay and feeling it bolster your soul.");
    if ((int)TP->query_stuffed() < ((int)TP->query_formula()/1) )
	TP->add_stuffed(((int)TP->query_formula()/250));
    if ((int)TP->query_quenched() < ((int)TP->query_formula()/1) )
	TP->add_quenched(((int)TP->query_formula()/250));
   return 1;
}
