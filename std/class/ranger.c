#include <std.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({ "/cmds/ranger" }); } // temporary

int caster_class() { return 1; }

string *restricted_races() {
    return ({ "bugbear","dwarf","gnome","goblin","half-orc","halfling","hobgoblin","kobold","orc",
                "firbolg","gnoll","half-ogre","ogre","ogre-mage" });
}

string *restricted_classes() { return ({}); }

int *restricted_alignments() { return ({}); }

// removing deity restrictions from ranger & druid. N, 3/17.
/*string *restricted_gods() { return ({ "auppenser","bane","beshaba","cyric","helm","mask","mystra","oghma","sune","torm","tymora" });
}*/
string *restricted_gods() { return ({}); }

// strong & weak saving throws. Fort, Ref, Will
int *saving_throws() { return ({ 1,1,0 }); }

mapping stat_requirements()
{
    return ([ "dexterity" : 13, "wisdom" : 13 ]);
}

string *combat_styles() {
    return ({ "dual wield", "archery" });
}

string *class_feats(string myspec) {
    return ({ "ambidexterity",
              "light armor proficiency",
              "simple weapon proficiency",
              "martial weapon proficiency",
              "track",
              "evasion"});
}

mapping class_featmap(string myspec) { // "dual wield" is default setting
    if(!myspec || myspec == "")
        return ([ 1 : ({ "ambidexterity", "light armor proficiency", "simple weapon proficiency", "martial weapon proficiency", "track" }), 5 : ({ "whirl" }), 9 : ({ "two weapon fighting", "evasion" }), 13 : ({ "improved two weapon fighting" }), 17 : ({ "unassailable parry" }),  ]);

    switch(myspec) {
      case "archery":
          return ([ 1 : ({ "point blank shot", "light armor proficiency", "simple weapon proficiency", "martial weapon proficiency", "track" }), 5 : ({ "manyshot" }), 9 : ({ "deadeye", "evasion" }), 13 : ({ "preciseshot" }), 17 : ({ "shot on the run" }),  ]);
      break;
      default:
          return ([ 1 : ({ "ambidexterity", "light armor proficiency", "simple weapon proficiency", "martial weapon proficiency", "track" }), 5 : ({ "whirl" }), 9 : ({ "two weapon fighting", "evasion" }), 13 : ({ "improved two weapon fighting" }), 17 : ({ "unassailable parry" }),  ]);
      break;
    }
}

string *class_skills()
{
    return ({ "athletics","endurance","stealth","survival" });
}

int skill_points() { return 4; }

string old_save_type() { return "ranger"; }

string new_save_type() { return "ranger"; }

void advanced_func(object player)
{
    player->set_guild_level("ranger",(int)player->query_class_level("ranger"));
}

int hit_dice() { return 8; }  // down to cleric equiv. with the new ranger spells in!

int default_hitpoints() { return 3; } // hitpoints per level above level 20

string armor_allowed() { return "fighter"; }

string weapons_allowed() { return "fighter"; }

int max_stance_offensive() { return 5; }

int max_stance_defensive() { return 5; }

int attack_bonus(object player)
{
    int level;
    level = (int)player->query_prestige_level("ranger");
    return level;
}

int number_of_attacks(object player)
{
    int num;
    if(!objectp(player)) { return 0; }
    num = "/daemon/bonus_d.c"->attack_bonus("ranger",player->query_class_level("ranger"),player);
    num = num / 7;
    return num;
}

string query_casting_stat(){
   return "wisdom";
}

mapping query_class_spells()
{
    return(([
        1 : ({"animal messenger","calm animal","detect poison","detect snares and pits","entangle","ghost step","magic fang","resist energy","summon natures ally 1" }),
        2 : ({"barkskin","bears endurance","cats grace","cure light wounds","hold animal","owls wisdom","snare","summon natures ally 2" }),
        3 : ({"cure moderate wounds","darkvision","greater magic fang","neutralize poison","snakebite","summon natures ally 3","treeshape" }),
        4 : ({"commune with nature","cure serious wounds","freedom of movement","heart of the wild","meld into nature","summon natures ally 4","treestride" }),
    ]));
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "ranger":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
