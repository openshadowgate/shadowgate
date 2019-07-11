#include <std.h>
#include <dirs.h>
#include <daemons.h>

inherit DAEMON;


void create() 
{ 
    ::create(); 
}

object base_class_ob(object ob)
{
    object class_ob;
    if(!objectp(ob) || !ob->query("immortal_defender_base_class")) { class_ob = find_object_or_load(DIR_CLASSES+"/fighter.c"); }
    else { class_ob = find_object_or_load(DIR_CLASSES+"/"+ob->query("immortal_defender_base_class")+".c"); }
    if(!objectp(class_ob)) { class_ob = find_object_or_load(DIR_CLASSES+"/fighter.c"); }
    return class_ob;
}


string *query_base_classes() { return ({ "fighter","paladin" }); }

int is_prestige_class() { return 1; }

string *search_paths(object ob) { return base_class_ob(ob)->search_paths(); }

int caster_class() { return 1; }

string *restricted_races(object ob) { return base_class_ob(ob)->restricted_races(); }

string *restricted_classes(object ob) { return base_class_ob(ob)->restricted_classes(); }

int *restricted_alignments(object ob) { return base_class_ob(ob)->restricted_alignments(); }

string *restricted_gods(object ob) { return base_class_ob(ob)->restricted_gods(); }

string requirements() // string version, maybe we'll need this, maybe not, can remove later if not
{
    string str;
    str = "Prerequisites:\n"
        "    Counter Feat (WeaponAndShield Tree)\n"
        "    20 Fighter or Paladin Levels (level adjustments considered part of required levels)\n"
        "    40 Character levels\n"
        "    20 Endurance Skill\n"
        "    20 Constitution stat, before equipment modifiers\n";
        
    return str;    
}


int prerequisites(object player)
{
    mapping skills;
    object race_ob;
    string race;
    int adj;
    if(!objectp(player)) { return 0; }
    
    race = player->query("subrace");
    if(!race) { race = player->query_race(); }
    race_ob = find_object_or_load(DIR_RACES+"/"+player->query_race()+".c");
    if(!objectp(race_ob)) { return 0; }
    adj = race_ob->level_adjustment(race);    
    skills = player->query_skills();
    
    if(!FEATS_D->usable_feat(player,"counter")) { return 0; }
    if(!skills["endurance"] || skills["endurance"] < 20) { return 0; }
    if(player->query_base_stats("constitution") < 20) { return 0; }
    if(player->is_class("fighter")) 
    { 
        if( (player->query_class_level("fighter") + adj) < 20) { return 0; }
        
        player->set("immortal_defender_base_class","fighter");
    }
    if(player->is_class("paladin")) 
    { 
        if( (player->query_class_level("paladin") + adj) < 20) { return 0; }
        player->set("immortal_defender_base_class","paladin");
    }
    if(player->query_level() < 40) { return 0; }
    return 1;    
}

mapping stat_requirements(object ob) 
{ 
    return ([ "constitution" : 20 ]);
}

int *saving_throws(object ob) { return base_class_ob(ob)->saving_throws(); }

string *combat_styles(object ob) { return base_class_ob(ob)->combat_styles(); }

string *class_feats(string myspec) { return base_class_ob(0)->class_feats(myspec); }

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "fighter":
            level = player->query_class_level("fighter");
            level += player->query_class_level("immortal_defender");            
            return level;
        case "paladin":
            level = player->query_class_level("paladin");
            level += player->query_class_level("immortal_defender");            
            return level;
        case "immortal_defender":
            level = player->query_class_level("immortal_defender");
            level += player->query_class_level("fighter");
            level += player->query_class_level("paladin");
            return level;
        
        default:
            return player->query_class_level(the_class);
    }
    return 0;    
}

mapping class_featmap(string myspec) {  
    return ([ 1 : ({ "defenders presence" }), 4 : ({ "shield charge" }), 7 : ({ "shield master" }), ]);
}

string *class_skills(object ob) { return base_class_ob(ob)->class_skills(); }

int skill_points(object ob) { return base_class_ob(ob)->skill_points(); }

string old_save_type(object ob) { return base_class_ob(ob)->old_save_type(); }

string new_save_type(object ob) { return base_class_ob(ob)->new_save_type(); }

// unsure on this one, will have to investigate
void advanced_func(object player) { return base_class_ob(player)->advance_func(player); }

int hit_dice(object ob) { return base_class_ob(ob)->hit_dice(); }  // hit dice rolled for hitpoints each level

int default_hitpoints(object ob) { return base_class_ob(ob)->default_hitpoints(); } // hitpoints per level above level 20

string armor_allowed(object ob) { return base_class_ob(ob)->armor_allowed(); }

string weapons_allowed(object ob) { return base_class_ob(ob)->weapons_allowed(); }

int max_stance_offensive(object ob) { return base_class_ob(ob)->max_stance_offensive(); }

int max_stance_defensive(object ob) { return base_class_ob(ob)->max_stance_defensive(); }

int attack_bonus(object player) { return 0; }

int number_of_attacks(object player) { return base_class_ob(player)->number_of_attacks(player); }

string newbie_choice(object ob) { return base_class_ob(ob)->newbie_choice(); }

string *query_newbie_stuff(object ob) { return base_class_ob(ob)->query_newbie_stuff(); }

void process_newbie_choice(object who, string str) { return base_class_ob(who)->process_newbie_choice(who,str); }

string query_casting_stat(object ob) { return base_class_ob(ob)->query_casting_stat(); }

mapping query_class_spells(object ob) { return base_class_ob(ob)->query_class_spells(); }