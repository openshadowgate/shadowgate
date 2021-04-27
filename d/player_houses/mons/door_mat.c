//door_mat.c - Crazy door mat for Stefano's house.  Coded by Circe 9/14/03
#include <std.h>
#include "/d/player_houses/stefano/stefano.h"
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("door mat");
   set_short("A brown door mat");
   set_id(({"monster","mat","door mat","brown mat"}));
   set_long(
      "This coarse brown door mat is normally used to wipe one's "+
      "feet upon.  It has somehow been animated and hovers in the "+
      "air."
   );
   set_gender("neuter");
   set_race("mat");
   set_body_type("snake");
   remove_limb("head");
   remove_limb("mouth");
   remove_limb("tail");
   set_attack_limbs(({"torso"}));
   set_size(1);
   set_alignment(5);
   set_overall_ac(-4);
   set_hd(15,6);
   set_level(15);
   set_class("fighter");
   set_mlevel("fighter",15);
   set_hp(random(75)+300);
   set_max_hp(query_hp());
   set_damage(1,6);
   set_attacks_num(2);
   set_base_damage_type("slashing");
   set_property("swarm",1);
   set("aggressive",19);
   set_exp(1500);
   set_funcs(({"strangle"}));
   set_func_chance(50);
}


void init(){
   ::init();
        if(avatarp(TP) && TP->query_invis()) return;
   if(!userp(TP)) return;
        else {
                force_me("kill "+TP->query_name()+"");
        }
}

void strangle(object targ){
   tell_object(targ,"The mat wraps itself around your face, cutting off your air supply!");
   tell_room(environment(targ),"The mat constricts around "+targ->query_cap_name()+"'s face!",targ);
   targ->do_damage("torso",random(50)+30);
   return 1;
}