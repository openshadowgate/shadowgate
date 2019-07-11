#include <std.h>
#include <daemons.h>
inherit OBJECT;

string spell, args;
//object empowered;
int prof;

//void set_empowered(object obj) { empowered = obj;}
//object query_empowered(object obj) { return empowered; }

void create() {
    ::create();
    set_name("contingency");
    set("id", ({ "remotexoli"}) );
    set("short", "");
    set("long", "");
    set_property("no animate", 1);
    set_weight(0);
}

int clean_up()
{
    if(!objectp(TO)) { return 1; }
    if(objectp(ETO)) { return 1; }
    destruct(TO);
    return 1;
}

void init() {
    ::init();
    add_action("now","now");
}

set_prof(int i) {
    prof = i;
}

int get_prof() {
    return prof;
}

set_spell(string xxx) {
    spell = xxx;
}

set_args(string arg) {
    args = arg;
}


int save_me(string str) {
    return 1;
}
int flag =0;
int now() {
    object spellobj;
    object *armor;
    int level;
    if(!spell) return 0;
    if(flag) return 0;
    flag = 1;
    if(TP->is_class("bard")) {
        if(!TP->is_ok_armour("bard")) {
            write("The spell conflicts with your armor and dies");
            call_out("remove",1);
            return 1;
        }
   }

   armor = TP->all_armour();
    armor = filter_array(armor,"armor_filter",find_object_or_load("/cmds/mortal/_cast.c"));
        if(FEATS_D->usable_feat(TP,"armored caster")) armor =
filter_array(armor,"light_armor_filter",find_object_or_load("/cmds/mortal/_cast.c"));

      if(sizeof(armor) && !avatarp(TP)) {tell_object(TP,"The spell conflicts with your armor and dies!");
       call_out("remove",1);
      return 1;
    }
     //if(TP->is_class("mage")) {
    //if(!TP->is_ok_armour("mage")) {
    //write("The spell conflicts with your armor and dies");
    //call_out("remove",1);
    //return 1;
   //}
 //}

    if(!deep_present("statue of "+capitalize(TP->query_name()),TP)){
	write("The image of yourself is missing, the contingency fails.\n");
      remove();
       return 1;
    }
    if(TP->is_class("bard"))
        level = TP->query_guild_level("bard");
    else
        level = TP->query_guild_level("mage");

    if((string)TP->query_name() == "tristan") {
        tell_object(TO,"prof = "+prof);
    }
    spellobj = new(spell);
    if(prof >= 100) {
        if(!stringp(args)) {
            spellobj->use_spell(TP,TP->query_name(),level, prof);
        }
        else {
            spellobj->use_spell(TP,args,level, prof);
        }
    }
    else if(prof < random(100)) {
        if(!stringp(args)) {
            spellobj->use_spell(TP,TP->query_name(),level, prof);
        }
        else {
            spellobj->use_spell(TP,args,level, prof);
        }
    }
    else {
        if(!stringp(args)) {
            spellobj->use_spell(TP,TP->query_name(),level, prof);
        }
        else {
            spellobj->use_spell(TP,args,level, prof);
        }
    }

    call_out("remove",1);
    return 1;
}

int drop() {
   return 1;
}

int is_detectable() { return 0; }
int query_invis() { return 1; }

