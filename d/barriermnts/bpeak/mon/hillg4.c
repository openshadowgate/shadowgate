#include <std.h>
#include "../bpeak.h"
#include <daemons.h>
inherit MONSTER;

object obj;
    


void create (){

::create ();
   set_name("Hill giant");
   set_id(({"giant","hill giant","Hill Giant","Hill giant"}));
   set_short("%^RESET%^%^ORANGE%^A hill giant%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This giant stands nearly ten and a half feet tall"
" and constantly seems to be frowning.  He looks brutish and uncivilized with"
" a smashed face that is ruddy in appearance at best.  His large nose is squashed"
" against his face and his forehead is overly large.  His dark brown hair is cut in"
" a shaggy mess and looks like it wasn't done with anything sharp.  His muscular"
" body is simply huge and disporportioned with large arms that hang low, giving"
" him an almost ape-like, primitive appearance.%^RESET%^");
   set_race("giant");
   set_gender("male");
   set_body_type("humanoid");
   set_overall_ac(-5);
   set_hd(18,2);
   set_size(3);
   set_stats("intelligence",6);
   set_stats("strength",19);
   set_stats("wisdom",10);
   set_stats("dexterity",18);
   set_stats("constitution",18);
   set_stats("charisma",7);
   set_exp(4500);
   set_alignment(9);
   set_hp(random(250)+150);
   set_max_hp(query_hp()); 
   set_max_level(45);
   add_search_path("/cmds/fighter");
   set_funcs(({"rush","parry","flash"}));
   set_func_chance(30);
   set_property("full attacks",1);
   set_money("gold",random(500));
   set_money("silver",random(50));
   set_money("copper",random(50));
   set_money("electrum",random(500));
   obj=new(OBJD+"basicc");
   obj->move(TO);
   obj->set_property("monsterweapon",1);
   command("wield club");
   //obj=new("/d/common/obj/potion/healing");
   //obj->move(TO);
   //obj->set_uses(15);
   set_property("add kits",10);
   set("aggressive",19);
   set_moving(1);
   set_speed(35); 
   set_nogo(({INRMS+"bridge"}));
} 
void rush(object target) {
   force_me("rush "+target->query_name()+"");
   return 1;
} 
void parry(object target) {
   force_me("parry");
   return 1;
}  
void flash(object target) {
   force_me("flash "+target->query_name()+"");
   return 1;
}                
void heart_beat(){
   ::heart_beat();
   if (!objectp(TO)) return;
   if (!objectp(ETO)) return;
   /*if(query_hp()<100  && present("vial",TO)){
   command("open vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   }*/
}
