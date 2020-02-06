#include <std.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({ "/cmds/mage" }); } // temporary

int caster_class() { return 1; }

string *restricted_races() {
    return ({ "beastman","bugbear","dwarf","goblin","half-orc","halfling","hobgoblin","orc",
        "firbolg","gnoll","half-ogre","ogre","wemic","kobold","voadkyn" }); //voadkyn and kobold moved to sorcerer
}

string *restricted_classes() { return ({ "sorcerer","psion"}); }

int *restricted_alignments() { return ({}); }

string *restricted_gods() { return ({}); }

mapping stat_requirements() {
    return (["intelligence" : 15 ]);
}

// strong & weak saving throws. Fort, Ref, Will
int *saving_throws() { return ({ 0,0,1 }); }

string *combat_styles() {
    return ({});
}

string *class_feats(string myspec)
{
    return ({ "simple weapon proficiency",
              "spell focus" });
}

mapping class_featmap(string myspec) {
    return ([ 1 : ({ "simple weapon proficiency", "spell focus", "magic school"}), 6 : ({ "scribe", }), 9 : ({ "brew potion" }), 11 : ({ "enchant" }), 17 : ({ "craft magical equipment" }), ]);
}

string *class_skills()
{
    return ({ "academics","dungeoneering","healing","spellcraft" });
}

int skill_points() { return 4; }

string old_save_type() { return "mage"; }

string new_save_type() { return "mage"; }

void advanced_func(object player)
{
    player->set_guild_level("mage",(int)player->query_class_level("mage"));
    return;
}

int hit_dice() { return 4; }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return 2; } // hitpoints per level above level 20

int max_con_bonus() { return 2; } // max amount of the con bonus that can be added to hitpoints each level

string armor_allowed() { return "mage"; }

string weapons_allowed() { return "mage"; }

int max_stance_offensive() { return 1; }

int max_stance_defensive() { return 1; }

int attack_bonus(object player)
{
    int level,bonus;
    level = (int)player->query_prestige_level("mage");
//    if(level > 20) { bonus = (level - 20) + 6; }
//    else(bonus = level / 3);
    bonus = level / 2; // boosted to tabletop equiv
    return bonus;
}

int number_of_attacks(object player)
{
    int num;
    if(!objectp(player)) { return 0; }
    num = "/daemon/bonus_d.c"->attack_bonus("mage",player->query_class_level("mage"),player);
    num = num / 7;
    return num;
}

string query_casting_stat(){
   return "intelligence";
}

mapping query_class_spells()
{
    return(([ ]));
}

void process_newbie_choice(object who, string str)
{
    if(!objectp(who) || !stringp(str)) return;
    who->set_school(str);
    //tell_object(who, "CYAN%^Ok, Thou hast chosen to study "+capitalize(str)+".");
}

void newbie_func(object who)
{
    object ob, ob2;
    int i;
    if(!objectp(who)) return;

    ob = new("/d/magic/magic_book");
    ob->move(who);
    ob->set_spellbook("magic missile");
    ob = new("/d/magic/comp_bag");
    ob->move(who);
    ob = new("/d/common/obj/misc/sack");
    for(i=0;i<15;i++)
    {
        ob2 = new("/d/magic/safe_scroll");
        ob2->move(ob);
    }
    ob->move(who);
    tell_object(who, "%^BOLD%^%^WHITE%^You are given a spell tome, a bag for components, and a sack of scrolls "+
    "to help you out in the world of ShadowGate.%^RESET%^");
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "mage":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
