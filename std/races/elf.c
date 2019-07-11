// Bonuses in lib: all subraces; +2 vs charm spells and sleep immunity, see /std/magic/spell.
// added Szarkai for specialty character support - all modifiers per drow race. -N, 03/11.
// Fey'ri new subrace. N, 1/14.
// note - /d/shadowgate/colors/elf has manual subrace select so that szarkai don't appear. Wild elves are manually restricted 
// also; the only case of a HM-restricted non-LA subrace in the game, so I didn't bother installing massive lib for it. N, 8/15.
#include <std.h>
#include <objects.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 102, 175, 233, 350 }); }

int *restricted_alignments(string subrace) {
    if(!subrace || subrace == "") return ({ 3, 6, 9 });
    if(subrace == "fey'ri") return ({ 1, 4, 7 });
    if(subrace == "szarkai") return ({ 1, 2, 4, 5, 7, 8 }); 
    return ({ 3, 6, 9 });
}

string *restricted_classes(string subrace) {
    if(!subrace || subrace == "") return ({ "psion", "psywarrior", "cavalier", "paladin", "monk" });
    switch(subrace) {
      case "wood elf": return ({ "mage", "psion", "psywarrior", "cavalier", "paladin", "monk" }); break;
      case "wild elf": return ({ "bard", "mage", "psion", "psywarrior", "cavalier", "paladin", "monk" }); break;
      case "sun elf": return ({ "psion", "psywarrior", "monk", "druid" }); break;
      case "fey'ri": return ({ "psion", "psywarrior", "monk", "druid" }); break;
      case "szarkai": return ({ "psion", "psywarrior", "cavalier", "paladin", "monk", "druid" }); break;
      default: return ({ "psion", "psywarrior", "cavalier", "paladin", "monk" }); break;
    }
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    if(!subrace || subrace == "") return ({ "shar","mask","bane","beshaba","cyric","auril","talos" });
    switch(subrace) {
      case "fey'ri": return ({ "anhur","helm","lathander","mielikki","oghma","selune","sune","torm","tymora","tyr" }); break;
      case "szarkai": return ({ "anhur","helm","lathander","mielikki","oghma","sune","torm","tymora","tyr" }); break;
      default: return ({ "shar","mask","bane","beshaba","cyric","auril","talos" }); break;
    }
}

int *stat_mods(string subrace) { // stats in order: str, dex, con, int, wis, cha
    if(!subrace || subrace == "") return ({ 0, 2, -2, 0, 0, 0 });
    switch(subrace) {
      case "sun elf": return ({ 0, 0, -2, 2, 0, 0 }); break;
      case "wood elf": return ({ 2, 2, 0, -2, 0, -2 }); break;
      case "wild elf": return ({ 0, 2, 0, -2, 0, 0 }); break;
      case "fey'ri": return ({ 0, 2, -2, 2, 0, 0 }); break;
      case "szarkai": return ({ 0, 2, -2, 2, 0, 0 }); break;
      default: return ({ 0, 2, -2, 0, 0, 0 }); break; //moon elf default
    }
}

mapping skill_mods(string subrace) {
    if(!subrace || subrace == "") return ([ "perception" : 2 ]);
    switch(subrace) {
      case "fey'ri": return ([ "perception" : 2, "influence" : 2 ]); break;
      case "szarkai": return ([ "perception" : 2]); break;          
      default: return ([ "perception" : 2 ]); break;
    }
}

int level_adjustment(string subrace) {
    if(!subrace || subrace == "") return 0;
    switch(subrace) {
      case "szarkai": return 2; break;
      case "fey'ri": return 3; break;
      default: return 0; break;
    }
}

int natural_AC(string subrace) { return 0; }

int sight_bonus(string subrace) {
    if(!subrace || subrace == "") return 3;
    if(subrace == "szarkai") return -2;
    return 3;
}

mapping daily_uses(string subrace) {
    if(!subrace || subrace == "") return ([]);
    if(subrace == "szarkai") return ([ "dancing lights" : 1, "faerie fire" : 1, "darkness" : 1 ]);
    if(subrace == "fey'ri") return ([ "darkness" : 1, "dimension door" : 1, "clairvoyance" : 1, "alter self" : -1 ]);
    return ([]);
}

mapping query_racial_innate(string subrace)
{
	switch(subrace)
	{
		case "fey'ri" : 
			return (["darkness" : (["type" : "spell", "casting level" : 0.5, 
				   "daily uses" : 1, "delay" : 1, "uses left" : 1, 
				   "refresh time" : -1, "level required" : 0, 
				   "class specific" : 0]), 
		   	"dimension door" : (["type" : "spell", "casting level" : 0.5, 
				   "daily uses" : 1, "delay" : 1, "uses left" : 1, 
				   "refresh time" : -1, "level required" : 0, 
				   "class specific" : 0]), 
		   	"clairvoyance" : (["type" : "spell", "casting level" : 0.5, 
				   "daily uses" : 1, "delay" : 1, "uses left" : 1, 
				   "refresh time" : -1, "level required" : 0, 
				   "class specific" : 0]),
		   	"alter self" : (["type" : "spell", "casting level" : 0.5, 
				   "daily uses" : -1, "delay" : 1, "uses left" : -1, 
				   "refresh time" : -1, "level required" : 0, 
				   "class specific" : 0]), ]);
			break;
		case "szarkai" : 
			return (["dancing lights" : (["type" : "spell", "casting level" : 0.5, 
				   "daily uses" : 1, "delay" : 1, "uses left" : 1, 
				   "refresh time" : -1, "level required" : 0, 
				   "class specific" : 0]), 
		   	"darkness" : (["type" : "spell", "casting level" : 0.5, 
				   "daily uses" : 1, "delay" : 1, "uses left" : 1, 
				   "refresh time" : -1, "level required" : 0, 
				   "class specific" : 0]), 
		   	"faerie fire" : (["type" : "spell", "casting level" : 0.5, 
				   "daily uses" : 1, "delay" : 1, "uses left" : 1, 
				   "refresh time" : -1, "level required" : 0, 
				   "class specific" : 0]), ]);
			break;
		default: 
			return (["commune" : (["type" : "spell", "casting level" : 0.5, 
				   "daily uses" : -1, "delay" : 1, "uses left" : -1,	
				   "refresh time" : -1, "level required" : 0, 
			         "class specific" : 0]), ]);				   
			break;
	}
	return 0;
}

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 3, 7, 6, 8, 3, 8 }); }
int *max_stats() { return ({ 18, 19, 17, 18, 18, 18 }); }
int *stat_adj() { return ({ 0, 1, -1, 0, 0, 0 }); }

int is_restricted() { return 0; } // restricted races by approval

// Stuff needed to replace what was in the old race database

string race_name() { return "elf"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 8000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 0, "con" : 0, "int" : 5, "wis" : 8, "dex" : 3, "cha" : 1 ]); }

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
    if(gender == "male") return 53;
    return 53;
}

int height_mod(string gender) {
    return 12;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 85;
    return 80;
}

int weight_mod(string gender) {
    return 6;
}

// used by /daemon/player_d 
mapping weight_values(string gender, int height)
{
    mapping map=([]);
    
    map["num"]  = 3;    
    
    switch(gender)
    {
    case "male":
        map["base"] = 90;
        switch(height)
        {
        case 55..57: map["adjust"] = -10; map["die"] = 15; break;
        case 58..62: map["adjust"] = 0;   map["die"] = 10; break;
        case 63..65: map["adjust"] = 0;   map["die"] = 15; break;
        case 66..68: map["adjust"] = 15;  map["die"] = 15; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 70;
        switch(height)
        {
        case 50..52: map["adjust"] = -15; map["die"] = 15; break;
        case 53..57: map["adjust"] = 0;   map["die"] = 10; break;
        case 58..60: map["adjust"] = 0;   map["die"] = 15; break;
        case 61..63: map["adjust"] = 5;   map["die"] = 15; break;        
        default:     map["adjust"] = 0;   map["die"] = 10; break;            
        }       
    }
    
    return map;   
}

string *query_hair_colors(object who) { 
    string *choices = ({}), subrace;
    int cha;
    cha = (int)who->query_stats("charisma");
    subrace = (string)who->query("subrace");
    if(!stringp(subrace) || subrace == "moon elf") {
        switch(cha) {
            case 16..30:
                choices += ({"silver", "platinum", "ebony"});
            case 12..15:
                choices += ({"blue"});
            case 0..11:
                choices += ({"black"});
                break;
        }
    }
    if(subrace == "sun elf" || subrace == "fey'ri") {
        switch(cha) {
            case 16..30:
                choices += ({"golden", "crimson", "scarlet", "auburn", "ebony"});
            case 12..15:
                choices += ({"red"});
            case 0..11:
                choices += ({"blonde", "black"});
                break;
        }
    }
    if(subrace == "szarkai") {
        choices += ({"white","silver","bald"});
    }
    if(subrace == "wood elf" || subrace == "wild elf") {
        if(subrace == "wood elf") cha -= 2;
        switch(cha) {
            case 16..30:
                choices += ({"golden", "crimson", "scarlet", "auburn", "ebony"});
            case 12..15:
                choices += ({"red", "blonde", "sable"});
            case 0..11:
                choices += ({"brown", "black"});
                break;
        }
    }
    return choices;
}

string *query_eye_colors(object who) {
    string *choices = ({}), subrace;
    int cha;
    cha = (int)who->query_stats("charisma");
    subrace = (string)who->query("subrace");
    if(!stringp(subrace) || subrace == "moon elf") {
        switch(cha) {
            case 16..30:
                choices += ({"sapphire", "azure", "cyan"});
            case 14..15:
                choices += ({"emerald"});
            case 0..13:
                choices += ({"green", "blue"});
                break;
        }
    }
    if(subrace == "sun elf" || subrace == "fey'ri") {
        switch(cha) {
            case 16..30:
                choices += ({"emerald", "golden"});
            case 14..15:
                choices += ({"amber"});
            case 0..13:
                choices += ({"green"});
                break;
        }
    }
    if(subrace == "szarkai") {
        switch(cha)
        {
        case 16..30:
            choices += ({"violet","purple"});
        case 0..15:
            choices += ({"red"});
            break;
        }
    }
    else if(subrace == "wood elf" || subrace == "wild elf") {
        if(subrace == "wood elf") cha -= 2;
        switch(cha) {
            case 16..30:
                choices += ({"emerald", "sable"});
            case 0..15:
                choices += ({"brown", "green", "hazel"});
                break;
        }
    }
    return choices;
}

string *query_subraces(object who) {
    string *subraces;
    subraces = ({"moon elf", "wood elf", "sun elf"});
    if(OB_ACCOUNT->is_experienced(who->query_true_name()) || OB_ACCOUNT->is_high_mortal(who->query_true_name()) || avatarp(who) || who->query("is_valid_npc")) {  
        subraces += ({"wild elf", "fey'ri", "szarkai"});
    }
    return subraces;
}
