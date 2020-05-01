// note - magical crafting is not yet active at date of installation; deceive item is relevant to the class but
// at this point I haven't worried about adding craft magical (or making their own feat). Should be considered
// at such time as the feat is actually active, as it is highly relevant to this class. N, 11/15.
#include <std.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({ "/cmds/warlock" }); } // temporary

int caster_class() { return 1; }

string *restricted_races() { // irrelevant, this is handled in the race files
    return ({  });
}

string *restricted_classes() { return ({ "psion","psywarrior",}); }

int *restricted_alignments() { return ({ 1,2,4,5 }); }

string *restricted_gods() { return ({}); }

mapping stat_requirements() {
    return (["charisma" : 15 ]);
}

// strong & weak saving throws. Fort, Ref, Will
int *saving_throws() { return ({ 0,0,1 }); }

string *combat_styles() {
    return ({});
}

string *class_feats(string myspec) {
    return ({ "simple weapon proficiency","spell focus","light armor proficiency" });
}

mapping class_featmap(string myspec) {
    return ([ 1 : ({ "simple weapon proficiency", "spell focus", "light armor proficiency" }), 7 : ({ "damage resistance", }), 9 : ({ "energy resistance" }), 12: ({ "craft magical equipment" }), 14 : ({ "improved damage resistance" }), 17 : ({ "regeneration" }) ]);
}

string *class_skills() {
    return ({ "academics","athletics","influence","spellcraft" });
}

int skill_points() { return 4; }

string old_save_type() { return "mage"; }

string new_save_type() { return "mage"; }

void advanced_func(object player) {
    player->set_guild_level("warlock",(int)player->query_class_level("warlock"));
    return;
}

// Using occult classes to set standard hit die: kineticist
int hit_dice() { return 8; }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return 3; } // hitpoints per level above level 20

string armor_allowed() { return "fighter"; }

string weapons_allowed() { return "fighter"; }

int max_stance_offensive() { return 1; }

int max_stance_defensive() { return 1; }

int attack_bonus(object player)
{
    int level,bonus;
    level = (int)player->query_prestige_level("warlock");
//    if(level > 20) { bonus = (level - 20) + 15; }
//    else bonus = (level*3) / 4;
    bonus = (level*3) / 4;
    return bonus;
}

int number_of_attacks(object player)
{
    int num;
    if(!objectp(player)) { return 0; }
    num = "/daemon/bonus_d.c"->attack_bonus("warlock",player->query_class_level("warlock"),player);
    num = num / 7;
    return num;
}

string query_casting_stat(){
   return "charisma";
}

mapping query_class_spells()
{
    return(([
        1 : ({"eldritch blast","eldritch claws","frightful blast","detect magic","beguiling influence","breath of the night","dark ones own luck","entropic warding","leaps and bounds","otherworldly whispers","see the unseen","spiderwalk","swimming the styx","voice of madness" }),
        2 : ({"eldritch chain","glacial blast","brimstone blast","charm","curse of despair","flee the scene","hungry darkness","ignore the pyre","the dead walk","voracious dispelling","walk unseen","witchwood step" }),
        3 : ({"eldritch glaive","eldritch scimitar","vitriolic blast","beshadowed blast","enervating shadow","heart of darkness","nightmares made real","phantasmal killer","wall of perilous fire","warlocks call" }),
        4 : ({"eldritch burst","binding blast","utterdark blast","casters lament","cloak of shadows","cunning insight","dark discorporation","devour magic","path of shadows" }),
    ]));
}

string newbie_choice() { return "Warlock Heritage"; }
string *query_newbie_stuff(int align)
{
    if(!intp(align)) return ({});
    switch(align)
    {
        case 7: return ({ "celestial", "fey" }); break;
        case 8: return ({ "celestial", "fey", "abyssal" }); break;
        case 9: return ({ "fey", "abyssal", "gloom" }); break;
        case 6: return ({ "abyssal", "gloom", "infernal" }); break;
        case 3: return ({ "gloom", "infernal" }); break;
    }
}
void process_newbie_choice(object who, string str)
{
    if(!objectp(who) || !stringp(str)) return;
    who->set("warlock heritage",str);
    //tell_object(who, "%^CYAN%^Ok, Thou hast chosen your heritage to be "+capitalize(str)+".");
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "warlock":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
