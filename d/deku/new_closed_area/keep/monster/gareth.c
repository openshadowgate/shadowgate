 
#include "/d/shadow/mon/melnmarn.h"
inherit "/std/vendor.c";
int build;
void create() {
    ::create();
   set_name("gareth");
   set_id(({"gareth","Gareth","clerk"}));
set_short("Gareth, the Alchemist");
   set_level(19);
   set("long","Gareth will sell you magical bottles, scrolls, and artifacts.");
   set_gender("male");
   set("race", "human");
   set_body_type("human");
   set_class("mage");
   set_alignment(5);
   set_mp(300);
   set_hd(19,1);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_items_allowed("potion");
   set_storage_room("/d/deku/keep/magic_storage");
   build = 0;
   }
void start_heart(){
        set_heart_beat(1);
}
void heart_beat(){
        if(!build) return;
        build ++;
        if(build == 5){
                command("say What can i get you "+this_player()->query_race()+"!");
        }
   }
