#include <std.h>
inherit "/d/common/mounts/war_horse";
/*inherit "/std/riding_animal.c";

private static int healingStuff;

void create(){
  ::create();
  set_id(({"war horse","horse","warhorse"}));
  set_name("horse");
  set_short("war horse");
  set_long("This is a war horse");
  set_level(10);
  set_value(1000);
  set_race("horse");
  set_gender("male");
  set_body_type("equine");
  set_size(3);
  set_max_hp(10000);
  set_hd(10,2);
  set_hp(100);
  set_overall_ac(6);
  set_exp(1);
  set_max_distance(20);
  set_enter_room("rides in");
  set_exit_room("leaves riding a war horse.");
  set_vehicle_short("War horse");
  set_attack_limbs(({"right forehoof","left forehoof"}));
  set_attacks_num(2);
  set_damage(2,10);
   set_riding_level(5);
  healingStuff = 1;
}

int enter(string str){
  string class;
  int lev, temp;
  
  class = TP->query_class();
  lev = TP->query_level();

  if(class=="paladin" || class=="antipaladin"){
  	temp = query_hp();
   	set_level(lev);
   	set_hp(temp);
    set_damage(2,lev/2);
    if(lev>10 )
      	set_max_hp(10*lev); 
   	if(healingStuff || query_max_hp() < query_hp()){
   		set_hp(query_max_hp());
   		healingStuff = 0;
   	}
  }
  if(class!="paladin" && class!="antipaladin" && class!="ranger" && class!="druid")
    return notify_fail("The horse will not let you mount it!\n");
  else 
    return ::enter(str);
  return 1;
}
*/