//lusell_wench.c - Serving wench for Lusell's keep.  Coded by Circe 1/29/04
#include <std.h>
#include "../lusell.h"
inherit MONSTER;

void create(){
   ::create();
   set_name("wench");
   set_id(({"wench","serving wench","maid","waitress"}));
   set_short("A serving wench");
   set_long("This human female is very young, looking as if she has just "+
      "become a woman.  She is clothed in all black and white "+
      "attire and the only skin that shows is that of her hands "+
      "and head.  She never makes eye contact with anyone, her "+
      "gaze is constantly on the floor.  Tattooed into her left and "+
      "right forearms are red and yellow flames.  She carries an "+
      "elegant black-bordered menu that lists the items available at "+
      "the moment."
   );
   set_gender("female");
   set_race("human");
   set_hd(15,5);
   set_alignment(3);
   set_max_hp(150+random(50));
   set_hp(query_max_hp());
   set_overall_ac(-6);
   set_class("fighter");
   set_mlevel("fighter",15);
   set_level(15);
   set_stats("wisdom",12);
   set_stats("strength",12);
   set_stats("constitution",12);
   set_stats("intelligence",14);
   set_stats("charisma",14);
   set_stats("dexterity",18);
   set_exp(1000);
   set("aggressive",0);
}

void init(){
   ::init();
   add_action("wave_em","wave");
}

int wave_em(string str){
   string mname=TP->query_name();
   if(str != "hand" && str != "hand dismissively"){
      tell_object(TP,"You could probably wave your hand?");
      return 1;
   }
   if((wizardp(TP)) || (mname == "lusell")){
      if(present("serving wench")){
         tell_object(TP,"You wave your hand, and the serving wench bows low "+
            "and backs out of the room, keeping her gaze to the floor until she is gone.");
         tell_room(ETP,"As "+TPQCN+" waves "+TP->QP+" hand dismissively, the serving "+
            "wench bows low and backs out of the room, keeping her gaze to the floor "+
            "until she is gone.",TP);
         TO->move("/d/shadowgate/void");
         destruct(TO);
         return 1;
      }
      tell_object(TP,"As you start to lift your hand, you realize the "+
         "serving wench is already gone and disguise the gesture by brushing "+
         "back your hair.");
      tell_room(ETP,""+TPQCN+" brushes back "+TP->QP+" hair.",TP);
      return 1;
   }
   tell_object(TP,"You wave your hand.");
   tell_room(ETP,""+TPQCN+" waves "+TP->QP+" hand.",TP);
   return 1;
}
