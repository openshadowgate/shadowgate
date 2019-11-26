#include <std.h>
#include <dirs.h>
#include <daemons.h>

inherit DAEMON;

#define BASE_CLASS find_object_or_load(DIR_CLASSES+"/barbarian.c")

void create()
{
    ::create();
}

object base_class_ob(object ob)
{
    object class_ob;
    if(!objectp(ob) || !ob->query("rage_prophet_base_class")) { class_ob = find_object_or_load(DIR_CLASSES+"/fighter.c"); }
    else { class_ob = find_object_or_load(DIR_CLASSES+"/"+ob->query("rage_prophet_base_class")+".c"); }
    if(!objectp(class_ob)) { class_ob = find_object_or_load(DIR_CLASSES+"/fighter.c"); }
    return class_ob;
}

string *query_base_classes() { return ({ "barbarian" }); }

int is_prestige_class() { return 1; }

string *search_paths() { return BASE_CLASS->search_paths(); } // temporary

int caster_class() { return BASE_CLASS->caster_class(); }

string *restricted_races() { return BASE_CLASS->restricted_races(); }

string *restricted_classes() { return BASE_CLASS->restricted_classes(); }

int *restricted_alignments() { return BASE_CLASS->restricted_alignments(); }

string *restricted_gods() { return BASE_CLASS->restricted_gods(); }

string requirements() // string version, maybe we'll need this, maybe not, can remove later if not
{
    string str;
    str = "Prerequisites:\n"
        "    20 Barbarian Levels\n"
        "    Spell focus\n";

    return str;
}

int prerequisites(object player)
{
    mapping skills;
    object race_ob;
    string race, base;
    int adj;
    if(!objectp(player)) { return 0; }

    race = player->query("subrace");
    if(!race) { race = player->query_race(); }
    race_ob = find_object_or_load(DIR_RACES+"/"+player->query_race()+".c");
    if(!objectp(race_ob)) { return 0; }
    adj = race_ob->level_adjustment(race);
    skills = player->query_skills();

    if((player->query_class_level("barbarian") + adj) < 10) { return 0; }
    if(!FEATS_D->usable_feat(player,"spell focus")) { return 0; }
    return 1;
}

mapping stat_requirements(object ob) { return BASE_CLASS->stat_requirements(); }

int *saving_throws(object ob) { return BASE_CLASS->saving_throws(); }

string *combat_styles(object ob) { return BASE_CLASS->combat_styles(ob); }

string *class_feats(string myspec) { return BASE_CLASS->class_feats(myspec); }

int caster_level_calcs(object player, string the_class)
{
    int level;
    string base;
    if(!objectp(player)) { return 0; }
        switch(the_class)
    {
        case "barbarian":
        case "rage_prophet":
            level = player->query_class_level("barbarian");
            level += player->query_class_level("rage_prophet");
            return level;
        default:
            return player->query_class_level(the_class);
    }

    return level;
}

mapping class_featmap(string myspec) {
    return ([ 1 : ({ "raging healer" }), 4 : ({ "ragecaster" }), 7 : ({ "spirit warrior" }), ]);
}

string *class_skills()
{
    return BASE_CLASS->class_skills();
}

int skill_points() { return BASE_CLASS->skill_points(); }

string old_save_type() { return BASE_CLASS->old_save_type(); }

string new_save_type() { return BASE_CLASS->new_save_type(); }

// unsure on this one, will have to investigate
void advanced_func(object player) { return BASE_CLASS->advance_func(player); }

int hit_dice() { return BASE_CLASS->hit_dice(); }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return BASE_CLASS->default_hitpoints(); } // hitpoints per level above level 20

string armor_allowed() { return BASE_CLASS->armor_allowed(); }

string weapons_allowed() { return BASE_CLASS->weapons_allowed(); }

int max_stance_offensive() { return BASE_CLASS->max_stance_offensive(); }

int max_stance_defensive() { return BASE_CLASS->max_stance_defensive(); }

int attack_bonus(object player) { return 0; }

int number_of_attacks(object player) { return BASE_CLASS->number_of_attacks(player); }

string newbie_choice() { return BASE_CLASS->newbie_choice(); }

string *query_newbie_stuff() { return BASE_CLASS->query_newbie_stuff(); }

void process_newbie_choice(object who, string str) { return BASE_CLASS->process_newbie_choice(who,str); }

string query_casting_stat() { return BASE_CLASS->query_casting_stat(); }

mapping query_class_spells() { return BASE_CLASS->query_class_spells(); }
