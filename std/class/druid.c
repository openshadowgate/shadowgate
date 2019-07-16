#include <std.h>
#include <daemons.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({ "/cmds/druids" }); } // temporary

int caster_class() { return 1; }


string *restricted_races() { 
    return ({ "ogre","ogre-mage","goblin","bugbear","dwarf","gnoll","half-ogre","half-orc","halfling","hobgoblin","wemic","drow","goblin","kobold","orc" });
}

string *restricted_classes() { return ({ }); }

int *restricted_alignments() { return ({ }); }

string *restricted_gods() { return ({}); }

mapping stat_requirements() {
    return ([ "wisdom" : 15 ]);
}

int *saving_throws() { return ({ 1,0,1 }); }

string *combat_styles() {
    return ({});
}

string *class_feats(string myspec) 
{  
    return ({ 
        "light armor proficiency", 
        "simple weapon proficiency" 
    });
}

// Time for a redo! Nienne, 9/15.
mapping class_featmap(string myspec) {  
    return ([ 
        1: ({ "light armor proficiency", "medium armor proficiency", "simple weapon proficiency", "shield proficiency", "spell focus" }), 
        3 : ({ "tracklessstep" }), 
        4: ({ "shapeshift" }), 
        9: ({ "venom immunity" }),
        11: ({ "wild speech" }), 
        16: ({ "wild knowledge" }),
        17: ({ "timeless body" }), 
    ]);
}

string *class_skills()
{  
// disguise temporarily disabled, please restore the first line when the command is installed. N, 1/14.
//    return ({ "healing","perception","disguise","survival" });
    return ({ "healing","perception","endurance","survival" });
}


int skill_points() { return 4; } // should be 4 as non-rogue, not sure why someone moved it to 5. N, 4/15.

string old_save_type() { return "cleric"; }

string new_save_type() { return "cleric"; }

void advanced_func(object player) 
{ 
    player->set_guild_level("druid",(int)player->query_class_level("druid"));    
    return; 
}

int hit_dice() { return 10; }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return 3; } // hitpoints per level above level 20

string armor_allowed() { return "fighter"; }

string weapons_allowed() { return "fighter"; }

int max_stance_offensive() { return 5; }

int max_stance_defensive() { return 5; }

int attack_bonus(object player)
{
    int level,bonus;
    level = (int)player->query_prestige_level("druid");       
//    if(level > 20) { bonus = (level - 20) + 12; }
//    else(bonus = to_int(to_float(level) / 1.6));// 12 at level 20
    bonus = (level*3) / 4; // boosted to tabletop equiv
    return bonus;
}

int number_of_attacks(object player)
{
    object shape;
    string shape_race;
    int num;
    if(!objectp(player)) { return 0; }
    // same number of attacks as cleric
    num = "/daemon/bonus_d.c"->attack_bonus("cleric",player->query_class_level("druid"),player);
    num = num / 7;
    
    if(FEATS_D->usable_feat(player,"natural fighting"))
    {
        shape = player->query_property("shapeshifted");
        if(objectp(shape))
        {
            shape_race = shape->query_shape_race();
            switch(shape_race)
            {
                case "wolf":
                case "dragon":
                    num += 2;
                    break;
                case "cat":
                    num += 3;
                    break;
                case "bear":
                    num += 1;
                    break;
                default:
                    break;
            }
        }        
    }
    
    return num;
}

string query_casting_stat(){
   return "wisdom";
}

mapping query_class_spells()
{
    return(([
        //1 : ({"bless","blight","cause light wounds","create water","cure light wounds","death watch","detect chaos","detect law","detect magic","detect poison","entangle","light","minor creation","whispering wind" }),
        //2 : ({"bears endurance","body blades","bulls strength","cause moderate wounds","cloudburst","conceal alignment","cure moderate wounds","darkness","divine shield","divine weapon","eagles splendor","faerie fire","ghost step","hold person","know alignment","lightning touch","limb attack","meld into stone","oppression","orders oath","owls wisdom","righteous might","shatter","sound burst","true seeing"}),
        //3 : ({"animate dead","armor of darkness","auspicious bolt","call lightning","cause blindness","cause serious wounds","comprehend languages","create food","cure serious wounds","daylight","dispel magic","displacement","faithful mount","fire shield","good hope","ice shield","insight","nimbus of light","phantom steed","rejuvenation","remove blindness","remove paralysis","seeking sword","spectral steed","strength of stone","water breathing" }),
        //4 : ({"cause critical wounds","cure critical wounds","glyph of warding","hold monster","magic vestments","meld into nature","neutralize poison","prevent stealing","sanctify","snakebite","sticks into snakes" }),
        //5 : ({"airbolt","befuddle","bliss","bolt of force","darkbolt","earth reaver","fear","flame strike","freedom of movement","frost breath","frozen breath","handfire","holy orb","insect plague","invisibility purge","kiss of torment","mark of justice","mass cause light wounds","mass cure light wounds","maw of stone","mist of the goddess","moonbeam","mystic bolt","offensive summoning","raise dead","resilience","searing light","slay living","spectral touch","stormwinds","tremor","unholy orb",
// "wieldskill" }),
        //6 : ({"aegis of fate","animate object","dispel chaos","dispel evil","dispel good","dispel law","greater dispel magic","heal","heroes feast","mass cause moderate wounds","mass cure moderate wounds","pass portal","screen","word of power" }),
        //7 : ({"aura of healing","berserker","blade barrier","blasphemy","charm monster","cometfall","confusion","flameburst","forgotten melody","holy word","hypothermia","mass cause serious wounds","mass cure serious wounds","rage","regeneration","sols searing orb","telepathy","thorn spray","wave of pain" }),
        //8 : ({"break curse","create portal","crushing hand","disintegrate","divine precision","earthquake","fire storm","forbiddance","fortune fate","ghostform","gods favor","inner eye","listening shadow","mass cause critical wounds","mass cure critical wounds","monsoon","phantasmal killer","rebirth","silver sight","stone body","stormrage","sunburst","teleportation ward","tidal surge","weighed in the balance","windstorm"}),
        //9 : ({"mass heal","mindnet","resurrection","speak with dead","succor" }),
    ]));
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "druid":
        default:
            return player->query_class_level(the_class);
    }
    return 0;    
}
