// Bonuses in lib:
// genasi: +1 to caster level, /std/Object.c; all planetouched: 10MR, /std/Object.c
// all the rest of planetouched details are in this file. Human ethnicities as follows:
// all non-planetouched humans; +4 skills at L1, see /std/skills.c
// PLEASE NOTE in setting ethnicities to players, that spelling including ' and no caps is integral.

// heartlander: +1 influence (here), +1 saves vs spells (spell.c)
// zin'charu: +1 spellcraft (here), det magic x3 (here)
// aesatri: +1 fort (saving_throw_d), +1 dodge bonus to ac (here)
// attayan: +1 academics (here), immune to fear (/cmds/spells/fear; other IC applications?)
// tsarven: +1 stealth/percept in urban (skills.c), +1 init (combat.c)
// morinnen: +1 survival (here), +1 BAB when mounted (combat.c)
// tonaz'tlacar: +1 stealth/percept in wilderness (skills.c), +10 hp (/adm/daemon/advance_d)
// senzokuan: +1 reflex (saving_throw_d), +1 L1 spell slot (spellcaster.c & /cmds/mortal/_recall)
// maalish: +1 will (saving_throw_d), +5 SR (Object.c)

#include <std.h>
#include <objects.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 18, 45, 60, 90 }); }

int *restricted_alignments(string subrace) {
    if(!subrace || subrace == "") return ({});
    switch(subrace) {
    case "tiefling": return ({ 1, 4, 7 }); break;
    case "aasimar": return ({ 3, 6, 9 }); break;
    case "feytouched": return ({ 1,2,3,5 }); break;
    default: return ({}); break;
    }
}

string *restricted_classes(string subrace) {
    switch(subrace) {
      case "tiefling": return ({ "druid" });
      case "aasimar": return ({ "druid" });
      case "air genasi": case "earth genasi": case "fire genasi": case "water genasi":  return ({ "warlock" });
    }
    return ({});
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) { return ({}); }

int *stat_mods(string subrace) { // stats in order: str, dex, con, int, wis, cha
    if(!subrace || subrace == "") return ({ 0, 0, 0, 0, 0, 0 });
    switch(subrace) {
      case "aasimar": return ({ 0, 0, 0, -2, 2, 2 }); break;
      case "air genasi": return ({ 0, 2, 0, 2, -2, -2 }); break;
      case "earth genasi": return ({ 2, 0, 2, -2, 0, -2 }); break;
      case "feytouched": return ({ 0, 2, -2, 0, 0, 2 }); break;
      case "fire genasi": return ({ 0, 0, 0, 2, 0, -2 }); break;
      case "tiefling": return ({ 0, 2, 0, 2, 0, -2 }); break;
      case "water genasi": return ({ 0, 0, 2, 0, 0, -2 }); break;
      default: return ({ 0, 0, 0, 0, 0, 0 }); break;
    }
}

mapping skill_mods(string subrace) {
    if(!subrace || subrace == "") return ([]);
    switch(subrace) {
      case "tiefling": return ([ "stealth" : 2, "disguise" : 2 ]); break;
      case "aasimar": return ([ "perception" : 2, "influence" : 2 ]); break;
      case "feytouched": return ([ "perception" : 2, "influence" : 2 ]); break;
      case "heartlander": return ([ "influence" : 1 ]); break;
      case "zin'charu": case "zincharu": return ([ "spellcraft" : 1 ]); break;
      case "attayan": return ([ "academics" : 1]); break;
      case "morinnen": return ([ "survival" : 1]); break;
      default: return ([]); break;
    }
}

int level_adjustment(string subrace) {
    if(!subrace || subrace == "") return 0;
    if(subrace == "tiefling" ||
       subrace == "aasimar" ||
       subrace == "air genasi" ||
       subrace == "feytouched" ||
       subrace == "earth genasi" ||
       subrace == "fire genasi" ||
       subrace == "water genasi")
        return 1;
    return 0;
}

int natural_AC(string subrace) {
    if(!subrace || subrace == "") return 0;
    switch(subrace) {
      case "aesatri": return 1; break; // in place for +1 dodge bonus to AC
      default: return 0; break;
    }
}

int sight_bonus(string subrace) {
    if(!subrace || subrace == "") return 0;
    if(subrace == "tiefling" ||
       subrace == "aasimar" ||
       subrace == "air genasi" ||
       subrace == "earth genasi" ||
       subrace == "fire genasi" ||
       subrace == "water genasi" ||
       subrace == "feytouched")
        return 2;
    return 0;
}

mapping daily_uses(string subrace) {
    if(!subrace || subrace == "") return ([]);
    switch(subrace) {
      case "aasimar": return ([ "light" : 1 ]); break;
      case "air genasi": return ([ "levitate" : 1 ]); break;
      case "earth genasi": return ([ "ghost step" : 1 ]); break;
      case "fire genasi": return ([ "handfire" : 1 ]); break;
      case "feytouched": return ([ "faerie fire" : 1 ]); break;
      case "tiefling": return ([ "darkness" : 1 ]); break;
      case "water genasi": return ([ "water breathing" : 1 ]); break;
      case "zin'charu": case "zincharu": return ([ "detect magic" : 3 ]); break;
      default: return ([]); break;
    }
}

mapping query_racial_innate(string subrace)
{
	if(!subrace || subrace == "") return 0;
	switch(subrace)
	{
		case "tiefling":
				return (["darkness" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		case "aasimar":
				return (["light" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		case "feytouched":
				return (["faerie fire" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		case "air genasi":
                                return (["levitate" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		case "earth genasi":
				return (["ghost step" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		case "fire genasi":
				return (["handfire" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		case "water genasi":
				return (["water breathing" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 1, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		case "zin'charu": case "zincharu":
				return (["detect magic" : (["type" : "spell", "casting level" : 0.5,
				"daily uses" : 3, "delay" : 1, "uses left" : 1,
				"refresh time" : -1, "level required" : 0,
				"class specific" : 0])]);
				break;
		default:
			return 0;
			break;
	}
	return 0;
}

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 3, 3, 3, 3, 3, 3 }); }
int *max_stats() { return ({ 18, 18, 18, 18, 18, 18 }); }
int *stat_adj()  { return ({ 0, 0, 0, 0, 0, 0 }); }

int is_restricted() { return 0; } // restricted races by approval

// Stuff needed to replace what was in the old race database

string race_name() { return "human"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 9999; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 0, "con" : 0, "int" : 0, "wis" : 0, "dex" : 0, "cha" : 0 ]); }

int size() { return 2; }

string *limbs() {
    return ({  "head",
               "right arm",
               "right hand",
               "left arm",
               "left hand",
               "left leg",
               "left foot",
               "right leg",
               "right foot",
               "waist",
               "neck" });
}

// minimum height for the race = base, max height for the race = base + mod
int height_base(string gender) {
    if(gender == "male") return 60;
    return 55;
}

int height_mod(string gender) {
    return 20;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 120;
    return 85;
}

int weight_mod(string gender) {
    return 8;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 8;

    switch(gender)
    {
    case "male":
        map["base"] = 150;
        switch(height)
        {
        case 60..65: map["adjust"] = -40; map["die"] = 15; break;
        case 66..74: map["adjust"] = -10; map["die"] = 10; break;
        case 75..80: map["adjust"] = 20;  map["die"] = 15; break;
        case 81..86: map["adjust"] = 30;  map["die"] = 25; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 110;
        switch(height)
        {
        case 55..60: map["adjust"] = -10; map["die"] = 14; break;
        case 61..69: map["adjust"] = -5;  map["die"] = 10; break;
        case 70..75: map["adjust"] = 0;   map["die"] = 15; break;
        case 76..81: map["adjust"] = 15;  map["die"] = 15; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string *query_hair_colors(object who) {
    int cha;
    string *choices = ({}), subrace;
    subrace = (string)who->query("subrace");
    cha = (int)who->query_stats("charisma");
    if(subrace == "tiefling" ||
       subrace == "air genasi" ||
       subrace == "earth genasi" ||
       subrace == "fire genasi" ||
       subrace == "water genasi")
        cha -= 2;
    if(subrace == "aasimar"||
       subrace == "feytouched")
        cha += 2;

    if(!stringp(subrace) ||
       member_array(subrace,({"aasimar", "feytouched","tiefling","air genasi","earth genasi","fire genasi","water genasi","heartlander"})) != -1) {
        switch(cha) {
            case 18..40:
                choices += ({"ebony", "golden", "silver"});
            case 14..17:
                choices += ({"sable", "auburn", "scarlet", "crimson"});
            case 0..13:
                choices += ({"black", "brown", "blonde", "red", "white", "gray", "bald"});
                break;
        }
    }
    if(subrace == "air genasi") { // extras for specific planetouched subtypes
      choices += ({ "light blue" });
    }
    if(subrace == "water genasi") { // extras for specific planetouched subtypes
      if(cha > 13) choices += ({ "blue-green" });
      choices += ({ "green" });
    }
    if(subrace == "senzokuan" || subrace == "maalish" || subrace == "zin'charu" || subrace == "tonaz'tlacar") {
        switch(cha) {
            case 18..40:
                choices += ({"ebony"});
            case 14..17:
                choices += ({"sable"});
            case 0..13:
                choices += ({"black", "brown", "white", "gray", "bald"});
                break;
        }
    }
    if(subrace == "attayan" || subrace == "morinnen" || subrace == "tsarven") {
        switch(cha) {
            case 18..40:
                choices += ({"ebony"});
            case 14..17:
                choices += ({"sable", "auburn", "scarlet", "crimson"});
            case 0..13:
                choices += ({"black", "brown", "red", "white", "gray", "bald"});
                break;
        }
    }
    if(subrace == "aesatri") {
        switch(cha) {
            case 18..40:
                choices += ({"golden", "silver"});
            case 14..17:
                choices += ({"auburn", "scarlet", "crimson"});
            case 0..13:
                choices += ({"blonde", "red", "white", "gray", "bald"});
                break;
        }
    }
    return choices;
}

string *query_eye_colors(object who) {
    int cha;
    string *choices = ({}), subrace;
    subrace = (string)who->query("subrace");
    cha = (int)who->query_stats("charisma");
    if(subrace == "tiefling" ||
       subrace == "air genasi" ||
       subrace == "earth genasi" ||
       subrace == "fire genasi" ||
       subrace == "water genasi")
        cha -= 2;
    if(subrace == "aasimar" ||
        subrace == "feytouched")
        cha += 2;

    if(!stringp(subrace) ||
       member_array(subrace,({"aasimar","feytouched","tiefling","air genasi","earth genasi","fire genasi","water genasi","heartlander","attayan"})) != -1) {
        switch(cha) {
            case 18..40:
                choices += ({"violet", "purple", "silver"});
            case 16..17:
                choices += ({"emerald", "sapphire", "yellow", "amber"});
            case 14..15:
                choices += ({"azure", "cyan", "sable", "chocolate", "coffee"});
            case 10..13:
                choices += ({"green", "hazel"});
            case 0..9:
                choices += ({"brown", "blue", "gray"});
                break;
        }
    }
    if(subrace == "water genasi") { // extras for specific planetouched subtypes
      if(cha > 15) choices += ({ "aquamarine" });
      choices += ({ "blue-green" });
    }
    if(subrace == "earth genasi") { // extras for specific planetouched subtypes
      choices += ({ "black" });
    }
    if(subrace == "tiefling") { // extras for specific planetouched subtypes
      choices += ({ "red" });
    }
    if(subrace == "aasimar" ||
        subrace == "feytouched") { // extras for specific planetouched subtypes
      if(cha > 17) choices += ({ "golden" });
      if(cha > 15) choices += ({ "topaz" });
    }
    if(subrace == "senzokuan" || subrace == "maalish" || subrace == "morinnen" || subrace == "tsarven") {
        switch(cha) {
            case 18..40:
                choices += ({"yellow", "amber"});
            case 14..17:
                choices += ({"sable", "chocolate", "coffee"});
            case 10..13:
                choices += ({"hazel"});
            case 0..9:
                choices += ({"brown", "gray"});
                break;
        }
    }
    if(subrace == "tonaz'tlacar") {
        switch(cha) {
            case 18..40:
                choices += ({"silver"});
            case 16..17:
                choices += ({"emerald", "yellow", "amber"});
            case 14..15:
                choices += ({"sable", "chocolate", "coffee"});
            case 10..13:
                choices += ({"green", "hazel"});
            case 0..9:
                choices += ({"brown", "gray"});
                break;
        }
    }
    if(subrace == "aesatri" || subrace == "zin'charu") {
        switch(cha) {
            case 18..40:
                choices += ({"violet", "purple", "silver"});
            case 16..17:
                choices += ({"emerald", "sapphire"});
            case 14..15:
                choices += ({"azure", "cyan"});
            case 10..13:
                choices += ({"green"});
            case 0..9:
                choices += ({"blue", "gray"});
                break;
        }
    }
    return choices;
}

string *query_subraces(object who)
{
    string *subraces;
    subraces = ({"heartlander","zin'charu","aesatri","attayan","tsarven","morinnen","tonaz'tlacar","senzokuan","maalish"});
    if(OB_ACCOUNT->is_experienced(who->query_true_name()) ||
       OB_ACCOUNT->is_high_mortal(who->query_true_name()) ||
       avatarp(who) ||
       who->query("is_valid_npc"))
    {
        subraces += ({ "tiefling","aasimar","feytouched","air genasi","earth genasi","fire genasi","water genasi" });
    }
    return subraces;
}

string *query_languages(string subrace)
{
    return (["required":({"common",}),"optional":({"halfling","orcish","dwarvish","gnomish",})]);
}
