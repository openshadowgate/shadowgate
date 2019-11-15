#include <std.h>
inherit DAEMON;

int is_prestige_class() { return 1; } // temporary to block in rolling

void create() { ::create(); }

string *search_paths() { return ({  }); }

int caster_class() { return 1; }

string *restricted_races() {
    return ({ "beastkin", "dwarf", "firbolg", "gnome", "halfling", "centaur", "ogre-mage", "satyr", "voadkyn", "elf", "wemic", "bugbear", "gnoll", "hobgoblin", "kobold", "minotaur", "ogre", "orc" });
}

string *restricted_classes() { return ({ }); }

int *restricted_alignments()
{
    return ({ 7, 8, 9, });
}

string *restricted_gods() { return ({}); }

mapping stat_requirements() {
    return ([ "charisma" : 13, "wisdom" : 13, "strength" : 13 ]);
}

int *saving_throws() { return ({ 1,0,1 }); }

string *combat_styles() {
    return ({});
}

string *class_feats(string myspec)
{
    return ({ "simple weapon proficiency",
                "martial weapon proficiency",
                "exotic weapon proficiency",
                "light armor proficiency",
                "medium armor proficiency",
                "spell focus",
                "shield proficiency"});
}

mapping class_featmap(string myspec) {
    return ([ 1 : class_feats()+({"judgment"}),3:({"solo tactics","force of personality"}), 5: ({"bane"}), 6: ({"leadership"}), 8: ({"second judgment"}), 11: ({"stalwart defense"}), 16 : ({"third judgment"}), 17 : ({"slayer"}), 20 : ({"true judgment"})]);
}

string *class_skills()
{
    return ({ "preception","survival","athletics","academics","influence" });
}

int skill_points() { return 5; }

string old_save_type() { return "bard"; }

string new_save_type() { return "bard"; }

void advanced_func(object player)
{
    player->set_guild_level("inquisitor",(int)player->query_class_level("inquisitor"));
    player->set_advanced((int)player->query_advanced() + 1);
    return;
}

int hit_dice() { return 8; }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return 3; } // hitpoints per level above level 20

string armor_allowed() { return "fighter"; }

string weapons_allowed() { return "fighter"; }

int max_stance_offensive() { return 5; }

int max_stance_defensive() { return 5; }

int attack_bonus(object player)
{
    int level,bonus;
    level = player->query_prestige_level("inquisitor");
    bonus = (level*3) / 4; // boosted
    return bonus;
}

int number_of_attacks(object player)
{
    int num;
    if(!objectp(player)) { return 0; }
    num = "/daemon/bonus_d.c"->attack_bonus("inquisitor",player->query_class_level("inquisitor"),player);
    num = num / 7;
    return num;
}

string query_casting_stat(){
   return "charisma";
}

mapping query_class_spells()
{
    return(([]));
}

void newbie_func(object who)
{
    object ob;
    if(!objectp(who)) return;
    return 1;
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "inquisitor":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
