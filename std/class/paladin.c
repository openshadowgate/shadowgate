#include <std.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({  }); } // temporary

int caster_class() { return 1; }

string *restricted_races() {
    return ({ "beastman","bugbear","dwarf","elf","gnome","goblin","half-elf","half-orc","halfling",
        "hobgoblin","kobold","orc","drow","firbolg","gnoll","half-drow","half-ogre","ogre","ogre-mage",
        "voadkyn","wemic" });
}

string *restricted_classes() {
    return ({ });
}

int *restricted_alignments() {
    return ({7, 8, 9});
}

string *restricted_gods() {
    return ({ "akadi","anhur","beshaba","cyric","istishia","malar","mask","mielikki","oghma","shaundakul",
        "talos","tempus","tymora" });
}

string *combat_styles() {
    return ({});
}

mapping stat_requirements() {
    return ([ "strength" : 12, "wisdom" : 12, "charisma" : 12 ]);
}

// strong & weak saving throws. Fort, Ref, Will
int *saving_throws() { return ({ 1,0,0 }); }

int skill_points() { return 4; }

string *class_feats(string myspec) {
    return ({ "light armor proficiency", "medium armor proficiency", "heavy armor proficiency", "shield proficiency", "simple weapon proficiency", "martial weapon proficiency", "parry" });
}

mapping class_featmap(string myspec) {
    return ([ 1 : ({ "light armor proficiency", "medium armor proficiency", "heavy armor proficiency", "shield proficiency", "simple weapon proficiency", "martial weapon proficiency", "parry" }), 2 : ({ "smite" }), 3 : ({"divine health" }), 6 : ({ "layonhands" }), 7 : ({ "indomitable" }),14 : ({ "force of personality" }), 17 : ({ "leadership" }), ]);
}

string *class_skills()
{
    return ({ "academics","athletics","endurance","influence" });
}

string old_save_type() { return "paladin"; }

string new_save_type() { return "paladin"; }

void advanced_func(object player)
{
    int i,prof,level;
    if(!objectp(player)) { return; }

    level = (int)player->query_character_level();

    player->set_guild_level("paladin",(int)player->query_class_level("paladin"));

    prof = 100;

    if (level > 30)
    {
        prof += (level - 30)/2;
    }
    if (level > 20)
    {
        prof = prof + ((level>30)?10:level - 20);
    }
    prof = prof + 2 * (level>20?20:level);

    player->set("max lance", prof+20);
    player->set("max medium blades",prof);
    return;
}

int hit_dice() { return 12; }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return 4; } // hitpoints per level above level 20

string armor_allowed() { return "fighter"; }

string weapons_allowed() { return "fighter"; }

int max_stance_offensive() { return 5; }

int max_stance_defensive() { return 5; }

int attack_bonus(object player)
{
    int level;
    level = (int)player->query_prestige_level("paladin");
    return level;
}

int number_of_attacks(object player)
{
    int num;
    if(!objectp(player)) { return 0; }
    num = "/daemon/bonus_d.c"->attack_bonus("paladin",player->query_class_level("paladin"),player);
    num = num / 7;
    return num;
}

string query_casting_stat(){
   return "wisdom";
}

mapping query_class_spells()
{
    return (([
        1 : ({"bolster","create water","cure light wounds","detect chaos","detect poison","divine weapon","light","virtue" }),
        2 : ({"bonded steed","bulls strength","create food","divine shield","eagles splendor","orders oath","owls wisdom","remove paralysis","resist energy" }),
        3 : ({"break curse","cause blindness","cure moderate wounds","daylight","dispel magic","divine favor","heal mount","prevent stealing","remove blindness" }),
        4 : ({"cure serious wounds","deathward","dispel chaos","invisibility purge","mark of justice","neutralize poison","sanctify","seeking sword"}),
    ]));
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "paladin":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
