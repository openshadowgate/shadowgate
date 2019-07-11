#include <std.h>
#include <daemons.h>

inherit DAEMON;

int check_climb(int climb_info, object ob){
    int skill, total,die_roll,inc,temp;
    string *armor;
    if(present("climbing tool",ob)) return 1; // tools = instant success for now.
    if(ob->query_property("spider climb")) return 1; // spell property for 100% climbing skill
    skill = ob->query_skill("athletics") + roll_dice(1,20);
    if(sizeof(ob->query_armour("torso"))) skill += ob->skill_armor_mod(ob->query_armor("torso"));

    if(skill < climb_info) {
      if((skill+10) < climb_info) return -1; // fall if failed by more than 10
      else return 0; // can't get started if general fail
    }
    return 1; // climb if pass
}