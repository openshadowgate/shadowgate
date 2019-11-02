/**
 * @file
 * @brief New character generation
 */

/*****************************************************************************************
At some point people stopped to update this comment. Some data might be irrelevant.

Should allow any player the ability to recreate themselves up to the point at which they are no longer a newbie - supports
resetting choices up to the point when the character is ready to be finalized
resetting race/myclass/subrace essentially requires everything chosen after
either of those to be rechosen - removes the inventory of the player and sets them back to level 1
most other resets do not work this way
stats being reset requires that hair color/eye color and body type be chosen
alignment being reset requires rechoosing "unique" choice (mage school, discipline, etc.) and deity


Order of char creation
----------------------

Unique myclass choice moved after alignment - simply because of the way that warlock heritages rely on Alignment
Current Order = myclass -> race -> subrace -> [GENETICS] stats -> hair color -> eye color -> height -> weight -> body type -> age [END GENETICS] -> alignment -> unique myclass choice -> deity -> review -> finalize

This order can be changed relatively easily though there are a few places in the code in which it will need to be changed
the function build_restrictions() is used for myclass/race and will need to point to the appropriate place
stats are mostly seperate - so they will also need to point to the correct place
other than that the function choose() would need to be modified
order is controlled by the MyPlace string variable - this seemed the simplest way to me

in the future any new classes/races will be automatically used when added to their proper folders in /std/races or /std/class

genetics.h contains tester information, stats, height, weight, body type, age stuff, and
it contains RESET_TYPES which is greatly important to the reset function
there are numerous reset functions() that greatly depend on the order
above

also adding "Recommended Stats" to genetics.h to contain what stats will look like when
the recommended command is used during the stat phase of creation.

blurbs.h contains short information for myclass/race/subrace/deity selections

hair and eye colors, as well as subraces are now located in the correct race file in /std/races/

unique myclass - stuff - such as warlock heritages are located in the correct myclass file in /std/myclass
myclass files that previously received items at the end of creation have a function at the end
of their files to be ran when a character is finalized

the function name is newbie_func() - so if a new myclass needs to receive something or an old one for that matter
simply add this function in the myclass file - see /std/myclass/mage.c for an example

morality.h contains some information about alignments - not a lot of information but it is important
for this object to work correctly

*********************************************************************************************/

#include <std.h>
#include <daemons.h>
#include <rooms.h>
#include <objects.h>
#include "blurbs.h"
#include "morality.h"
#include "genetics.h"
#include "ansi.h"
#include <psions.h>
#include <dirs.h>
#include "/d/shadowgate/dieties.h"
#define TS_D "/daemon/treesave_d.c"
#define CMD_NOTE "/cmds/avatar/_note.c"
#define NEWBIE_START "/d/newbie/ooc/hub_room"

inherit OBJECT;

mapping MyCharacterInfo;
string MyPlace, StartFrom, EndAt, *BuildArray;
int MyBrief, FinalFlag, EndFlag, FirstBuild = 0, BeenBuilt, stats_setup;
static object MyObject;


static string *my_choices;
static string astr, unique;
static int bonus;

void ProcessStep();
void ShowStep();
//LIST OF RESET FUNCTIONS
varargs void reset_character_info(string what, int flag);
void confirm_reset(string str, string what);
varargs void full_reset();
void clear_deity();
void clear_alignment();
void clear_unique();
void clear_height();
void clear_weight();
void clear_body_type();
void clear_eyes();
void clear_hair();
void clear_age();
void clear_special();
void clear_race();
void clear_stats();
void clear_subrace();
//END OF RESET FUNCTIONS

//LIST OF CHARACTER BUILDING FUNCTIONS
void finalize_character();
void build_stats();
void build_myclasses();
void build_race();
void build_subrace();
void build_hair();
void build_eyes();
void build_unique();
void build_height();
void build_weight();
void build_body_type();
void build_age();
void build_alignment();
void build_deity();
void build_final();
//END OF CHARACTER BUILDING FUNCTIONS

void do_character_class();
void pick_class();
void pick_race();
void display_my_choices();
void pick_sub_race();
varargs int choose(string str, int flag);
int check_choices();
mixed check();
void pick_alignment();
void extra_display(string str);
void confirum_my_choice(string str, string choice);
void display_blurb(string str);
int okdone();
int reroll();
void setup_stats();
void display_stats(int flag);
int add_stat(string str);
int brief(string str);
int check_my_choice(string str);
void pick_special(string str);
int check_my_choice(string str);
void pick_my_unique();
void pick_genetics();
void header();
void pick_deity();
mixed display_my_character();
void build_restrictions(string type);

//Confirmation prompt for when reset is used
//after creation this will be changed
//to be available only up to the point where
//they are no longer newbies and only from places
//where they could advance in Level
void confirm_reset(string str, string what)
{
    if(str != "yes")
    {
        if(MyPlace == "stats") display_stats(0);
        else ProcessStep();
        return;
    }
    else
    {
        if(!stringp(what) && what != "")
        {
            tell_object(ETO, "\nResetting character and beginning anew!");
            ETO->move("/d/shadowgate/setter");
            tell_object(ETO, "You are whisked away to the start of creation!");
        }
        else tell_object(ETO, "\nResetting "+what+" and working forward from there!");
        if(what == "race" || what == "class" || what == "subrace" || what == "special") { ETO->move("/d/shadowgate/setter"); tell_object(ETO, "You are whisked away to the start of creation!"); }
        reset_character_info(what, 1);
        return;
    }
    return;
}
//END


//storing everything possible in the mapping up until they review/accept it all
//this will hopefully allow for them to make changes up until that point should they want
//to do so - could be possible to even allow them the ability to reset all the way up
//until they are no longer a newbie - Saide

//Reset Functions
varargs void full_reset()
{
        MyCharacterInfo = (["stats" : ([ "charisma" : 6, "intelligence" : 6, "dexterity" : 6, "constitution" : 6, "wisdom" : 6, "strength" : 6]) ]);
        MyCharacterInfo += (["race" : (["gender": "neuter", "race name" : "NIL", "hair color" : "NIL", "eye color" : "NIL", "height" : 0, "weight" : 0, "age" : 0, "restricted alignments" : ({}), "subrace" : "NIL", "bonus language": "NIL", "template" : "none" ]) ]);
        MyCharacterInfo += (["myclass" : (["minimum stats" : ([]), "myclass name" : "NIL", "available races" : ({}), "restricted alignments" : ({}), "available subraces" : ({}) ]) ]);
        MyCharacterInfo["myclass"] += (["alignment" : 0, "align title" : "NIL", "deity" : "NIL", "unique choice" : "NIL", "unique type" : "NIL" ]);
        MyCharacterInfo["race"] += (["psuedo race" : "NIL", "weight choice" : "NIL", "height choice" : "NIL", "age choice" : "NIL", "body type" : "NIL"]);
        BuildArray = ({});
        EndAt = "";
        stats_setup = 0;
        FirstBuild = 0;
        if(objectp(ETO)) ETO->remove_XP_tax("all");
        if(!FirstBuild && objectp(ETO)) ETO->set("score_inaccessible", 1);
}

void clear_stats()
{
    MyCharacterInfo["stats"]["charisma"] = 6;
    MyCharacterInfo["stats"]["intelligence"] = 6;
    MyCharacterInfo["stats"]["dexterity"] = 6;
    MyCharacterInfo["stats"]["constitution"] = 6;
    MyCharacterInfo["stats"]["wisdom"] = 6;
    MyCharacterInfo["stats"]["strength"] = 6;
    stats_setup = 0;
}

void clear_race()
{
    MyCharacterInfo["race"]["race name"] = "NIL";
}

void clear_gender()
{
    MyCharacterInfo["race"]["gender"] = "neuter";
}

void clear_special()
{
    MyCharacterInfo["race"]["psuedo race"] = "NIL";
}

void clear_subrace()
{
    MyCharacterInfo["race"]["subrace"] = "NIL";
}

void clear_age()
{
    MyCharacterInfo["race"]["age"] = 0;
    MyCharacterInfo["race"]["age choice"] = "NIL";
}

void clear_hair()
{
    MyCharacterInfo["race"]["hair color"] = "NIL";
}

void clear_eyes()
{
    MyCharacterInfo["race"]["eye color"] = "NIL";
}

void clear_bonus_language()
{
    MyCharacterInfo["race"]["bonus language"] = "NIL";
}

void clear_template()
{
    string template = MyCharacterInfo["race"]["template"];
    string tpfn;
    MyCharacterInfo["race"]["template"] = "none";

    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    tpfn = "/std/acquired_template/"+template+".c";
    if(!file_exists(tpfn))
        return;

    tpfn->remove_template(ETO);
}

void clear_body_type()
{
    MyCharacterInfo["race"]["body type"] = "NIL";
}

void clear_weight()
{
    MyCharacterInfo["race"]["weight"] = 0;
    MyCharacterInfo["race"]["weight choice"] = "NIL";
}

void clear_height()
{
    MyCharacterInfo["race"]["height"] = 0;
    MyCharacterInfo["race"]["height choice"] = "NIL";
}

void clear_unique()
{
    MyCharacterInfo["myclass"]["unique choice"] = "NIL";
    MyCharacterInfo["myclass"]["unique type"] = "NIL";
}

void clear_deity() { MyCharacterInfo["myclass"]["deity"] = "NIL"; }

void clear_alignment()
{
    MyCharacterInfo["myclass"]["alignment"] = 0;
    MyCharacterInfo["myclass"]["align title"] = "NIL";
    clear_deity();
}

varargs void reset_character_info(string what, int flag)
{
    string targ_reset;
    if(stringp(what)) what = lower_case(what);
    if(!flag)
    {
        if(!objectp(EETO)) return 0;
        if(!EETO->query_property("training"))
        {
            tell_object(ETO, "In order to reset anything with the object you must be in a place "+
            "that allows you to advance!");
            return 1;
        }
        if(!stringp(what)) tell_object(ETO, "\nWARNING: This will reset ALL choices you have made for your character up to this point. Do you wish to continue?");
        else if(what == "") tell_object(ETO, "\nWARNING: This will reset ALL choices you have made for your character up to this point. Do you wish to continue?");
        else if(member_array(what, keys(RESETTYPES)) == -1)
        {
            tell_object(ETO, "\nERROR: You cannot reset "+what+".");
            return 1;
        }
        else if(STEPVALUES[MyPlace] < STEPVALUES[RESETTYPES[what]])
        {
            tell_object(ETO, "\nERROR: You have not yet made it to the "+what+" step in creation!");
            return 1;
        }
        else if(what == "race" || what == "class" || "what" == "subrace")
        {
            tell_object(ETO, "\nWARNING: This will reset your "+what+" choice and ALL others made after it. Do you wish to continue?");
        }
        else tell_object(ETO, "\nWARNING: This will reset your "+what+ " choice. Do you wish to continue?");
        tell_object(ETO, "Type <%^BOLD%^%^RED%^yes%^RESET%^> to reset your choices, anything unless to abort.");
        input_to("confirm_reset", what);
        return 1;
    }
    if(!stringp(what) || what == "")
    {
        full_reset();
        MyPlace = "myclass";
    }
    else
    {
        EndFlag = 0;
        BuildArray = ({});
        targ_reset = RESETTYPES[what];
        switch(targ_reset)
        {
            case "myclass":
                full_reset();
                break;
            case "unique":
                if(MyCharacterInfo["myclass"]["myclass name"] == "warlock")
                {
                    clear_alignment();
                    clear_unique();
                    clear_deity();
                    if(FirstBuild) { BuildArray = ({"alignment", "unique", "deity"}); EndAt = "finalize"; }
                }
                else
                {
                    clear_unique();
                    if(FirstBuild) { BuildArray = ({"unique"}); EndAt = "finalize"; }
                }
                break;
            case "gender":
                clear_gender();
                clear_race();
                clear_subrace();
                clear_stats();
                clear_hair();
                clear_eyes();
                clear_height();
                clear_weight();
                clear_body_type();
                clear_age();
                clear_alignment();
                clear_bonus_language();
                clear_template();
                clear_deity();
                build_restrictions("myclass");
                FirstBuild = 0;
                ETO->remove_XP_tax("all");
                EndAt = "";
                break;
            case "race":
                clear_race();
                clear_subrace();
                clear_stats();
                clear_hair();
                clear_eyes();
                clear_height();
                clear_weight();
                clear_body_type();
                clear_age();
                clear_alignment();
                clear_bonus_language();
                clear_template();
                clear_deity();
                build_restrictions("myclass");
                FirstBuild = 0;
                ETO->remove_XP_tax("all");
                EndAt = "";
                break;
            case "special":
                clear_special();
                clear_stats();
                clear_hair();
                clear_eyes();
                clear_subrace();
                clear_bonus_language();
                clear_template();
                build_restrictions("myclass");
                build_restrictions("race");
                if(FirstBuild) { BuildArray = ({"special", "subrace", "stats", "hair color", "eye color", "bonus language"}); EndAt = "finalize"; }
                break;
            case "subrace":
                clear_subrace();
                clear_stats();
                clear_hair();
                clear_eyes();
                clear_height();
                clear_weight();
                clear_body_type();
                clear_age();
                clear_alignment();
                clear_bonus_language();
                clear_template();
                clear_deity();
                build_restrictions("myclass");
                build_restrictions("race");
                EndAt = "";
                FirstBuild = 0;
                ETO->remove_XP_tax("all");
                break;
            case "stats":
                clear_stats();
                if(FirstBuild) { BuildArray = ({"stats", "hair color", "eye color", "bonus language"}); EndAt = "finalize"; }
                break;
            case "hair color":
                clear_hair();
                if(FirstBuild) { BuildArray = ({"hair color"}); EndAt = "finalize"; }
                break;
            case "eye color":
                clear_eyes();
                if(FirstBuild) { BuildArray = ({"eye color"}); EndAt = "finalize"; }
                break;
            case "height":
                clear_height();
                if(FirstBuild) { BuildArray = ({"height"}); EndAt = "finalize"; }
                break;
            case "weight":
                clear_weight();
                clear_body_type();
                if(FirstBuild) { BuildArray = ({"weight", "body type"}); EndAt = "finalize"; }
                break;
            case "body type":
                clear_body_type();
                if(FirstBuild) { BuildArray = ({"body type"}); EndAt = "finalize"; }
                break;
            case "age":
                clear_age();
                if(FirstBuild) { BuildArray = ({"age"}); EndAt = "finalize"; }
                break;
            case "bonus language":
                clear_bonus_language();
                if(FirstBuild) { BuildArray = ({"bonus language"}); EndAt = "finalize"; }
                break;
            case "template":
                clear_bonus_language();
                if(FirstBuild) { BuildArray = ({"template"}); EndAt = "finalize"; }
                break;
            case "alignment":
                clear_alignment();
                if(FirstBuild) { BuildArray = ({"alignment", "deity"}); EndAt = "finalize"; }
                break;
            case "deity":
                clear_deity();
                BuildArray = ({"deity"}); EndAt = "finalize";
                break;
        }
        MyPlace = targ_reset;
    }
    if(StartFrom = "") StartFrom = MyPlace;
    BeenBuilt = 0;
    ProcessStep();
    return 1;
}
//End of Reset Function


void create()
{
    ::create();
    set_short("A strange and powerful object");
    set_long("%^BOLD%^%^WHITE%^This strange object radiates power "+
    "the likes of which you have never before seen. It seems to contain "+
    "the very essence of life, allowing one who holds it to "+
    "make choices which will alter the very fabric of their being. "+
    "You may <%^BOLD%^%^CYAN%^check%^BOLD%^%^WHITE%^> to glimpse "+
    "what choices it contains. You may <%^BOLD%^%^CYAN%^reset choice"+
    "%^BOLD%^%^WHITE%^> to alter one if you are unhappy with it. You "+
    "may <%^BOLD%^%^CYAN%^review%^BOLD%^%^WHITE%^> to see a list "+
    "of current options that this object affords you. It has "+
    "attached itself to you and will be with you for as long as you "+
    "are a newbie character in the world of ShadowGate.%^RESET%^");
    set_property("no drop", 1);
    set_property("death keep", 1);
    set_id(({"setter object", "object", "charactercreationsetterobject"}));
    set_weight(0);
    set_property("no animate", 1);
    set_property("soulbound", 1);
    StartFrom = "";
    reset_character_info("", 1);
    FinalFlag = 1;
}

void init()
{
    ::init();
    if(!objectp(TP)) return;
    if(!interactive(TP)) return;
    if(userp(ETO))
        if(!newbiep(ETO))
            TO->remove();
    add_action("reset_character_info","reset");
    add_action("okdone","done");
    add_action("reroll", "reroll");
    add_action("add_stat", "add");
    add_action("ShowStep", "review");
    add_action("choose","pick");
    add_action("display_my_character", "check");
    add_action("finalize_character", "finalize");
    add_action("brief", "brief");
    add_action("recommended", "recommended");
    add_action("randomize", "random");
}

void header()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    tell_object(ETO, "");
}


//Function that allows toggling on/off extra confirmation prompts
int brief(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(base_name(EETO) != "/d/shadowgate/setter") return 0;
    if(MyBrief)
    {
        MyBrief = 0;
        tell_object(ETO, "\n%^BOLD%^%^WHITE%^Turning %^BOLD%^%^CYAN%^off brief "+
        "mode%^BOLD%^%^WHITE%^, you will now see extra confirmation prompts.%^RESET%^");
        return 1;
    }
    if(!MyBrief)
    {
        MyBrief = 1;
        tell_object(ETO, "\n%^BOLD%^%^WHITE%^Turning %^BOLD%^%^CYAN%^on brief mode,"+
        "%^BOLD%^%^WHITE%^ you will no longer see extra confirmation prompts. As a "+
        "new player it is HIGHLY recommended that you leave this mode off.%^RESET%^");
        return 1;
    }
}
//end of brief toggle

//stats related code - Stats should be starting at the minimum needed for a myclass - Saide
void setup_stats()
{
    mapping tmp;
    int i, change;
    string *temp_data;
    stats_setup = 1;
    /*if(!bonus)*/ bonus = MAXPOINTS;
    tmp = MyCharacterInfo["myclass"]["minimum stats"];
    temp_data = keys(tmp);
    if(!sizeof(temp_data)) return;
    change = 0;
    for(i = 0;i < sizeof(temp_data);i++)
    {
        MyCharacterInfo["stats"][temp_data[i]] = tmp[temp_data[i]];
        change += tmp[temp_data[i]] - 6;
    }
    bonus -= change;
    display_stats(1);
}

void display_stats(int flag)
{
    if(flag == 1)
    {
        tell_object(ETO, "%^BOLD%^%^YELLOW%^You are given an extra "+bonus+" points to boost your starting scores.%^RESET%^");
        tell_object(ETO, "%^BOLD%^%^CYAN%^Each score must be at least %^BLUE%^6%^CYAN%^ and at most %^BLUE%^18.%^RESET%^");
        tell_object(ETO, "%^BOLD%^%^WHITE%^Syntax example: add %^RESET%^2 to strength");
        tell_object(ETO, "%^BOLD%^%^WHITE%^This will make your strength 2 points higher.");
        tell_object(ETO, "%^BOLD%^%^WHITE%^Type %^YELLOW%^done%^BOLD%^%^WHITE%^ when finished.");
    }
    header();
    tell_object(ETO, "%^BOLD%^%^MAGENTA%^    Current scores   %^RESET%^");
    header();
    tell_object(ETO, "%^BOLD%^%^GREEN%^ strength     --- %^BOLD%^%^WHITE%^"+MyCharacterInfo["stats"]["strength"]);
    tell_object(ETO, "%^BOLD%^%^GREEN%^ intelligence --- %^BOLD%^%^WHITE%^"+MyCharacterInfo["stats"]["intelligence"]);
    tell_object(ETO, "%^BOLD%^%^GREEN%^ dexterity    --- %^BOLD%^%^WHITE%^"+MyCharacterInfo["stats"]["dexterity"]);
    tell_object(ETO, "%^BOLD%^%^GREEN%^ constitution --- %^BOLD%^%^WHITE%^"+MyCharacterInfo["stats"]["constitution"]);
    tell_object(ETO, "%^BOLD%^%^GREEN%^ wisdom       --- %^BOLD%^%^WHITE%^"+MyCharacterInfo["stats"]["wisdom"]);
    tell_object(ETO, "%^BOLD%^%^GREEN%^ charisma     --- %^BOLD%^%^WHITE%^"+MyCharacterInfo["stats"]["charisma"]);
    header();

    if(bonus == 0)
    {
        tell_object(ETO, "\n%^BOLD%^%^WHITE%^You are finished. Please type %^MAGENTA%^done%^WHITE%^ to continue or "
        "%^MAGENTA%^reroll%^WHITE%^ to start again.%^RESET%^");
        if(flag) return;
    }
    else if(flag != 1) tell_object(ETO, "%^YELLOW%^You have "+bonus+" points left to add.%^RESET%^");
    if(flag == 2) tell_object(ETO, "%^BOLD%^%^YELLOW%^ Syntax: add # to stat");

    if(bonus && member_array(MyCharacterInfo["myclass"]["myclass name"], keys(RECOMMENDED_STATS)) != -1)
    {
        tell_object(ETO, "\n%^BOLD%^%^WHITE%^You may type <%^CYAN%^recommended%^BOLD%^%^WHITE%^> to have "+
        "your stats automatically set to what is recommended for your myclass.");
    }
    if(bonus)
    {
        tell_object(ETO, "\n%^BOLD%^%^WHITE%^You may type <%^CYAN%^random%^BOLD%^%^WHITE%^> to have "+
        "your stats completely randomized.%^RESET%^");
    }
    return;
}

int add_stat(string str)
{
    int amount;
    string stat;
    if(MyPlace != "stats") return 0;
    if(!str)
    {
        display_stats(2);
        return 1;
    }
    if(sscanf(str,"%d to %s",amount,stat)!= 2)
    {
        tell_object(ETO, "%^BOLD%^%^YELLOW%^Syntax: add # to stat");
        return 1;
    }
    if(amount > bonus)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^ You have only %^WHITE%^"+bonus+"%^BOLD%^%^RED%^ points left to apply.");
        return 1;
    }
    if(stat == "str") stat = "strength";
    if(stat == "int") stat = "intelligence";
    if(stat == "dex") stat = "dexterity";
    if(stat == "con") stat = "constitution";
    if(stat == "cha") stat = "charisma";
    if(stat == "wis") stat = "wisdom";
    if(member_array(stat, STATS) == -1)
    {
        tell_object(ETO, "%^BOLD%^%^CYAN%^Try a stat that you have.");
        return 1;
    }
    if((int)MyCharacterInfo["stats"][stat]+amount > 18 )
    {
        tell_object(ETO, "%^BOLD%^%^RED%^That score will exceed 18. %^WHITE%^Please reenter.");
        return 1;
    }
    if(amount < 0)
    {
        tell_object(ETO, "%^BOLD%^%^GREEN%^You cannot subtract points. Please %^WHITE%^reroll%^GREEN%^ if you need to start again.");
        return 1;
    }
    MyCharacterInfo["stats"][stat] += amount;
    bonus -= amount;
    display_stats(0);
    return 1;
}

int reroll()
{
    if(MyPlace != "stats") return 0;
    bonus = MAXPOINTS;
    MyCharacterInfo["stats"] = (["charisma" : 6, "intelligence" : 6, "dexterity" : 6, "constitution" : 6, "wisdom" : 6, "strength" : 6]);
    setup_stats();
    return 1;
}

int okdone()
{
    if(MyPlace != "stats" || bonus) return 0;
    ETO->set_stats("charisma", MyCharacterInfo["stats"]["charisma"]);
    if(MyCharacterInfo["race"]["subrace"] != "NIL") ETO->set("subrace", MyCharacterInfo["race"]["subrace"]);
    if((OB_ACCOUNT->is_experienced(ETO->query_true_name()) ||
        OB_ACCOUNT->is_high_mortal(ETO->query_true_name())))
        MyPlace = "template";
    else
        MyPlace = "hair color";
    ProcessStep();
    return 1;
}

int recommended()
{
    string temp, stat, *temp_stats;
    mapping recommended_stats;
    int x;

    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(MyPlace != "stats") return 0;
    temp = MyCharacterInfo["myclass"]["myclass name"];
    if(member_array(temp, keys(RECOMMENDED_STATS)) == -1) return 0;
    recommended_stats = RECOMMENDED_STATS[temp];
    if(!mapp(recommended_stats)) return 0;
    temp_stats = keys(recommended_stats);
    for(x = 0;x < sizeof(temp_stats);x++)
    {
        stat = temp_stats[x];
        MyCharacterInfo["stats"][stat] = recommended_stats[stat];
        continue;
    }
    bonus = 0;
    display_stats(0);
    return 1;
}

int randomize()
{
    int x, to_inc, y, cur_stat, diff;
    string *available_stats, stat;
    if(MyPlace != "stats" || !bonus) return 0;
    while(bonus)
    {
        y = sizeof(STATS);
        available_stats = STATS;
        for(x = 0;x < y;x++)
        {
            stat = available_stats[random(sizeof(available_stats))];
            available_stats -= ({stat});
            cur_stat = MyCharacterInfo["stats"][stat];
            if(cur_stat == 18) continue;
            to_inc = 1 + random(2) + random(3);
            if((bonus - to_inc) <= 0) { to_inc = bonus; bonus = 0; }
            else bonus -= to_inc;
            if((cur_stat + to_inc) > 18)
            {
                cur_stat += to_inc;
                diff = cur_stat - 18;
                to_inc -= diff;
                bonus += diff;
            }
            MyCharacterInfo["stats"][stat] += to_inc;
            if(bonus == 0) break;
            continue;
        }
        if(bonus == 0) break;
        continue;
    }
    display_stats(0);
    return 1;
}

//END OF STATS RELATED CODE

//Displays choices that a player has currently made - will review
//this screen and then finalize before the character is actually set up
mixed display_my_character()
{
    string temp, r, c, re, tmp, b, g, em, MyFile, by;
    int i, len, *race_mods, flag;

    r = "%^BOLD%^%^GREEN%^";
    c = "%^BOLD%^%^WHITE%^";
    b = "%^BOLD%^%^BLACK%^";
    re = "%^RESET%^";
    g = "%^RESET%^%^GREEN%^";
    em = "%^BOLD%^%^CYAN%^";
    by = "%^BOLD%^%^YELLOW%^";
    len = 16;

    //if(MyPlace != "finalize") return 0;
    tell_object(ETO, "\n%^BOLD%^%^WHITE%^Your current choices are as follows, please note that character name "+
    "and sex CANNOT be reset.\n");
    tell_object(ETO, "  "+arrange_string(r+"Character Name "+b+"--------", len) +g+" : "+re+c+capitalize(ETO->query_name()));
    tell_object(ETO, "  "+arrange_string(r+"Gender "+b+"----------------", len) +g+" : "+re+c+MyCharacterInfo["race"]["gender"]);
    tell_object(ETO, "  "+arrange_string(r+"Class "+b+"-----------------", len) +g+" : "+arrange_string(re+c+capitalize(MyCharacterInfo["myclass"]["myclass name"]), (len-4)));
    tmp = MyCharacterInfo["myclass"]["unique type"];
    if(tmp != "NIL")
    {
        tell_object(ETO, "  "+arrange_string(r+tmp +b+" -------------------", len)+g+" : "+re+c+capitalize(MyCharacterInfo["myclass"]["unique choice"]));
    }
    tell_object(ETO, "  "+arrange_string(r+"Race "+b+"---------------------------------", len)+g+" : "+re+c+capitalize(MyCharacterInfo["race"]["race name"]));
    tmp = MyCharacterInfo["race"]["subrace"];
    if(tmp != "NIL")
    {
        tell_object(ETO, "  "+arrange_string(r+"Subrace "+b+"--------------", len)+g+ " : "+re+c+capitalize(tmp));
    }
    tmp = MyCharacterInfo["race"]["psuedo race"];
    if(tmp != "NIL")
    {
        tell_object(ETO, "  "+arrange_string(r+"Parent Lineage "+b+"------------", len)+g+ " : "+re+c+capitalize(tmp));
    }
    MyFile = "/std/races/"+MyCharacterInfo["race"]["race name"]+".c";
    if(file_exists(MyFile))
    {
        temp = MyCharacterInfo["race"]["subrace"];
        if(temp != "NIL") race_mods = MyFile->stat_mods(temp);
        else race_mods = MyFile->stat_mods("");
    }
    for(i = 0;i < sizeof(STATS);i++)
    {
        temp = "  "+arrange_string(r + capitalize(STATS[i]) +b+" ----------", len)+g+" : ";
        temp += re+c+ arrange_string(MyCharacterInfo["stats"][STATS[i]], 6);
        if(pointerp(race_mods))
        {
            if(race_mods[i] != 0)
            {
                if(race_mods[i] > 0) temp += " (+"+em+race_mods[i]+re+c+")";
                else temp += " (%^BOLD%^%^RED%^"+race_mods[i]+re+c+")";
                flag = 1;
            }
        }
        tell_object(ETO, temp);
        continue;
    }
    tell_object(ETO, "  "+arrange_string(r+"Hair Color "+b+"-------------", len)+g+" : "+re+c+capitalize(MyCharacterInfo["race"]["hair color"]));
    tell_object(ETO, "  "+arrange_string(r+"Eye Color "+b+"--------------", len)+g+" : "+re+c+capitalize(MyCharacterInfo["race"]["eye color"]));
    tell_object(ETO, "  "+arrange_string(r+"Height "+b+"-----------------", len)+g+" : "+re+c+capitalize(MyCharacterInfo["race"]["height choice"]));
    tell_object(ETO, "  "+arrange_string(r+"Weight "+b+"-----------------", len)+g+" : "+re+c+capitalize(MyCharacterInfo["race"]["weight choice"]));
    tell_object(ETO, "  "+arrange_string(r+"Body Type "+b+"--------------", len)+g+" : "+re+c+capitalize(MyCharacterInfo["race"]["body type"]));
    tell_object(ETO, "  "+arrange_string(r+"Age "+b+"--------------------", len)+g+" : "+re+c+capitalize(MyCharacterInfo["race"]["age choice"]));
    if(MyCharacterInfo["stats"]["intelligence"]>16)
        tell_object(ETO, "  "+arrange_string(r+"Bonus Language "+b+"---------", len)+g+" : "+re+c+capitalize(MyCharacterInfo["race"]["bonus language"]));
    if(stringp(MyCharacterInfo["race"]["template"]))
        tell_object(ETO, "  "+arrange_string(r+"Template "+b+"---------------", len)+g+" : "+re+c+capitalize(MyCharacterInfo["race"]["template"]));
    tell_object(ETO, "  "+arrange_string(r+"Alignment "+b+"--------------", len)+g+" : "+re+c+capitalize(MyCharacterInfo["myclass"]["align title"]));
    tell_object(ETO, "  "+arrange_string(r+"Deity "+b+"------------------", len)+g+" : "+re+c+capitalize(MyCharacterInfo["myclass"]["deity"]));

    tell_object(ETO, "\n"+c+"Please note that you may "+em+"reset "+c+
    "any of these choices up to the point at which you are no longer a newbie "+
    "character."+re);

    tell_object(ETO, "\n"+c+"If you choose to reset class, race, subrace, or parent lineage, you will "+
    em+"LOSE"+c+" ALL of your "+em+"INVENTORY (except for vials)"+c+", "+em+"EXPERIENCE"+c+", and be set to "+em+"LEVEL 1"+
    c+". You will also be moved back to the start of creation.");

    tell_object(ETO, "\n"+by+"Syntax example: "+c+"<"+em+"reset class"+c+
    "> will reset your class and every decision made after it. NOTE: resetting race, myclass, or subrace will "+
    "reset every choice made after it and will reset your character and inventory. %^RESET%^");
    tell_object(ETO, "\n"+by+"NOTE: "+c+"<"+em+"reset hair color"+c+">"+
    " will reset only your hair color, most resets work this way though some are dependent on others. For example, "+
    "resetting stats will also reset hair, eye color and bonus language."+re);

    if(flag)
    {
        tell_object(ETO, "\n"+by+"NOTE:"+c+" Racial stat modifiers are shown next to your stats above. These will be "+
        "applied when your character is finalized. "+em+"Numbers"+c+" indicate an increase, %^BOLD%^%^RED%^"+
        "numbers"+c+" indicate a decrease.");
    }

    if(MyPlace == "finalize" && !BeenBuilt)
    {
        tell_object(ETO, "\n"+c+"If you are happy with your current choices "+
        "you can "+em+"finalize"+c+" to create your character and enter the world of ShadowGate.");
    }
    else if(BeenBuilt)
    {
        tell_object(ETO, "\n"+c+"Your character is currently finalized. If you change something "+
        "about yourself then you can "+em+"finalize"+c+" again to make the change take effect.");
    }
    return 1;
}
//END


//Character Building/Finalizing Functions
void finalize_character()
{
    object desc;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(MyPlace != "finalize" || BeenBuilt) return 0;
    //doing this only the first time they finalize (hopefully)
    BeenBuilt = 1;
    if(FirstBuild == 1)
    {
        ETO->convert_relationships();
    }
    if(objectp(to_object("/daemon/description_d")))
    if(desc = new("/daemon/description_d"))
    {
        desc->new_description_profile(ETO);
        destruct(desc);
    }
    if(EndAt != "" && FirstBuild == 2)
    {
        switch(StartFrom)
        {
            case "stats":
                build_stats();
                build_hair();
                build_eyes();
                break;
            case "unique":
                build_unique();
                break;
            case "hair color":
                build_hair();
                break;
            case "eye color":
                build_eyes();
                break;
            case "special":
                build_subrace();
                build_hair();
                build_eyes();
                break;
            case "height":
                build_height();
                break;
            case "weight":
                build_weight();
                build_body_type();
                break;
            case "body type":
                build_body_type();
                break;
            case "age":
                build_age();
                break;
            case "bonus language":
                build_bonus_language();
                break;
            case "template":
                build_template();
                break;
            case "alignment":
                build_alignment();
                build_deity();
                break;
            case "deity":
                build_deity();
                break;
        }
        tell_object(ETO, "You have used the object's power to alter your very being!");
        return 1;
    }
    build_stats();
    build_myclasses();
    build_gender();
    build_race();
    build_subrace();
    build_hair();
    build_eyes();
    build_unique();
    build_height();
    build_weight();
    build_body_type();
    build_age();
    build_alignment();
    build_deity();
    build_final();
    tell_object(ETO, "Entering the world of ShadowGate!");
    FirstBuild = 2;
    if(ETO->query("score_inaccessible")) ETO->delete("score_inaccessible");
    return 1;
}

void build_deity()
{
    object ob, mydeity;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    mydeity = MyCharacterInfo["myclass"]["deity"];
    while(objectp(ob = present("holy symbol", ETO))) { ob->remove(); }
    if(mydeity == "godless") ETO->set_diety(0);
    else {
      ETO->set_diety(mydeity);
      ob = new("/d/magic/symbols/holy_symbol.c");
      ob->set_short("The holy symbol of "+capitalize(mydeity));
      ob->move(ETO);
      ob->save(ETOQCN);
    }
    ETO->delete("god change");
    ETO->set("god changed",1);
    ETO->add_mp(ETO->query_max_mp());
    return 1;
}

void build_unique()
{
    string MyFile;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(MyCharacterInfo["myclass"]["unique choice"] == "NIL") return;
    MyFile = "/std/class/"+MyCharacterInfo["myclass"]["myclass name"]+".c";
    if(file_exists(MyFile)) MyFile->process_newbie_choice(ETO, MyCharacterInfo["myclass"]["unique choice"]);
}

void build_final()
{
    int i,j, newmax, feats;
    string *classes,temp, MyFile;
    string myclass;
    object newroom;

    MyFile = "/std/class/"+MyCharacterInfo["myclass"]["myclass name"]+".c";
    if(file_exists(MyFile)) MyFile->newbie_func(ETO);
    if(FirstBuild)
    {
        //ETO->set("no advance", 30);
        //temp = CMD_NOTE->format_checkpoint((string)ETO->query_name(),"%^ORANGE%^Standard non-AP level cap: "+ETO->query("no advance")+".%^RESET%^");
        //TS_D->add_value_to_array("notes",ETO->query_name(),capitalize(ETO->query_name()) + ", " + ctime(time()) + " - "+ temp);
        newroom = new(NEWBIE_START);
        ETO->move_player(newroom);
        ETO->setenv("LINES","20");
    }
    ETO->set("new_hp_rolled_two",1);
    ETO->set("no pk",1);
    ETO->set("new_hm_cap_set",1);
    ETO->set("new_stat_type2", 1);
    classes = ETO->query_classes();
    i = sizeof(classes);
    ETO->set_exp(0);
    ETO->add_exp(i);
    for(j=0;j<i;j++)
    {
        ETO->set_mlevel(classes[j],0);
        ETO->set_guild_level(classes[j], 0);
    }
    ETO->add_quenched(50);
    ETO->add_stuffed(500);
    ETO->add_hp(TP->query_max_hp());
    ETO->add_hp(TP->query_max_hp());
    ETO->update_channels();
    ETO->new_body();
    ETO->init_skills("blah");
    ETO->set("align ok",1);
    for(j=0;j<i;j++) ETO->add_search_path("/cmds/"+classes[j]);
    if(ETO->is_class("psywarrior"))
    { //add psions eventually
        newmax = PWPOINTS[0];
        ETO->set_max_mp(newmax);
        tell_object(ETO,"%^BOLD%^%^GREEN%^As a level 1 psywarrior, you have "
        ""+newmax+" power point(s). You must <prepare psywarrior points (times X)> "
        "to prepare your points for use.%^RESET%^");
    }
    ETO->force_me("fixspells");
    ETO->force_me("save");
    feats = (int)ETO->query_other_feats_gained();
    feats += (int)ETO->query("free_feats");
    ETO->clear_feats();
    ETO->set("free_feats",feats);
    ADVANCE_D->advance(TP,classes[0]);
    ETO->set("active myclass", classes[0]);
    ETO->set("new_class_type", 1);
    ETO->set_posed(classes[0]);
    if(ETO->query("new_class_type")) catch("/cmds/mortal/_advance.c"->add_class_feats(ETO,ETO->query_class()));
    ETO->set("hp_array",0);
    ETO->make_new_hitpoint_rolls(ETO);
    ETO->delete("stat_points_gained");
    for(j=0;j<i;j++)
    {
        "/d/shadowgate/class_news"->class_news(classes[j],ETOQCN+" has joined your ranks.");
        //NWP_D->advance_player(ETO,classes[j],1);
    }
    if(!ETO->query_money("gold")) ETO->add_money("gold", 200 + random(300));
    return 1;

}

void build_hair()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ETO->set_hair_color(MyCharacterInfo["race"]["hair color"]);
}

void build_alignment()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ETO->set_alignment(MyCharacterInfo["myclass"]["alignment"]);
}

void build_eyes()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ETO->set_eye_color(MyCharacterInfo["race"]["eye color"]);
}

void build_bonus_language()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ETO->set_lang(MyCharacterInfo["race"]["bonus language"],100);
}

void build_template()
{
    string template = MyCharacterInfo["race"]["template"];
    string tpfn;

    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    tpfn = "/std/acquired_template/"+template+".c";
    if(!file_exists(tpfn))
        return;

    tpfn->apply_template(ETO);
}

void build_subrace()
{
    int x;
    object *to_remove;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ETO->delete("subrace");
    if(MyCharacterInfo["race"]["subrace"] != "NIL") ETO->set("subrace", MyCharacterInfo["race"]["subrace"]);
    to_remove = all_inventory(ETO);
    to_remove -= ({TO});
    for(x = 0;x < sizeof(to_remove);x++)
    {
        if(to_remove[x]->id("kitxyz")) continue;
        to_remove[x]->remove();
    }
}

void build_stats()
{
    int i;
    string stat;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    for(i = 0;i < sizeof(STATS);i++)
    {
        stat = STATS[i];
        ETO->set_stats(STATS[i], MyCharacterInfo["stats"][stat]);
    }
    ETO->delete("stat_points_gained");
}

void build_gender()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ETO->set_gender(MyCharacterInfo["race"]["gender"]);
}

void build_race()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ETO->set_race(MyCharacterInfo["race"]["race name"]);
    ETO->init_lang();
    if(MyCharacterInfo["stats"]["intelligence"]>16)
        build_bonus_language();
    if(OB_ACCOUNT->is_experienced(ETO->query_true_name()) ||
       OB_ACCOUNT->is_high_mortal(ETO->query_true_name()))
        build_template();
}

void build_age()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ETO->setPlayerAgeCat(MyCharacterInfo["race"]["age"]);
}

void build_height()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ETO->set_player_height(PLAYER_D->calc_height(ETO, MyCharacterInfo["race"]["height"]));
}

void build_weight()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ETO->set_player_weight(MyCharacterInfo["race"]["weight"]);
}

void build_body_type()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ETO->set_body_type(MyCharacterInfo["race"]["body type"]);
}

void build_myclasses()
{
    string *classes;
    string myclass;
    int i;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    classes = ETO->query_classes();
    for(i = 0;i < sizeof(classes);i++)
    {
        myclass = classes[i];
        ETO->set_guild_level(myclass,0);
        ETO->set_mlevel(myclass,0);
        ETO->remove_class(myclass);
        if(myclass == "mage" || myclass == "bard") { ETO->set_school(0); }
        if(myclass == "mage" || myclass == "sorcerer" || myclass == "psywarrior" || myclass == "warlock" || myclass == "psion") { ETO->reset_mastered(); }
        if(myclass == "psion") { ETO->set_discipline(0); }
        if(myclass == "warlock") { ETO->delete("warlock heritage"); }
        if(myclass == "cleric" || myclass == "ranger" || myclass == "paladin" || myclass == "antipaladin") { ETO->set_divine_domain(({})); }
        if(myclass == "fighter") { TP->set_fighter_style(0); }
        continue;
    }
    myclass = MyCharacterInfo["myclass"]["myclass name"];
    ETO->set_class(myclass, 1);
    ETO->set_guild_level(myclass, 1);
    ETO->set_mlevel(myclass, 1);
    ETO->new_body();
    ETO->set_max_mp(0);
    ETO->set_mp(0);
    ETO->set_hp(20);
    ETO->init_spellcaster();
    ETO->add_exp(1);
}
//END OF BUILDING FUNCTIONS

//Function that uses MyPlace Variable to execute functions
//relating to customization choices a player can make
void ShowStep()
{
    if(MyPlace == "class") MyPlace = "myclass";
    switch(MyPlace)
    {
        case "myclass": case "class":
            do_character_class();
            break;
        case "gender":
            pick_gender();
            break;
        case "race":
            pick_race();
            break;
        case "special":
            pick_special(0);
            break;
        case "subrace":
            pick_sub_race();
            break;
        case "alignment":
            pick_alignment();
            break;
        case "stats":
            if(!stats_setup) setup_stats();
            else display_stats(0);
            break;
        case "unique":
            pick_my_unique();
            break;
        case "deity":
            pick_deity();
            break;
        case "hair color": case "eye color":
        case "height": case "weight": case "body type":
        case "age": case "bonus language": case "template":
            pick_genetics();
            break;
        case "finalize":
            display_my_character();
            break;
    }
    return 1;
}

string query_myPlace() { return MyPlace; }
void set_myPlace(string str) { MyPlace = str; }

int ProcessStep()
{
    if(!stringp(MyPlace))
    {
        reset_character_info();
    }
    if(EndAt != "")
    {
        if(pointerp(BuildArray))
        {
            if(EndFlag >= sizeof(BuildArray)) MyPlace = EndAt;
            else MyPlace = BuildArray[EndFlag];
            EndFlag++;
        }
    }
    ShowStep();
}
//End


//Function that builds a list of character classes
void do_character_class()
{
    string *possible_classes, myname;
    int i;
    object class_ob;
    myname = TP->query_name();
    //all possible classes - Saide
    possible_classes = get_dir("/std/class/*.c");
    possible_classes = explode(implode(possible_classes, ""), ".c");
    my_choices = ({});
    if(sizeof(possible_classes))
    {
        for(i=0;i<sizeof(possible_classes);i++)
        {
            //not requiring that knights start as cavaliers anymore - myclass is
            //pretty pointless outside of that - Saide
            if(possible_classes[i] == "cavalier" || possible_classes[i] == "antipaladin") continue;
            //if(possible_classes[i] == "antipaladin") continue;
            //Tester info added for ease of testing new classes ~Circe~ 9/3/15

            class_ob = find_object_or_load("/std/class/"+possible_classes[i]+".c");
            if(objectp(class_ob) && class_ob->is_prestige_class()) { continue; }

            if(sizeof(TESTCLASS))
            {
                if(member_array(possible_classes[i],TESTCLASS) != -1)
                {
                    if(member_array(myname,TESTERS) == -1){ continue; }
                }
            }
            my_choices += ({possible_classes[i]});
            continue;
        }
    }
    pick_class();
}
//end

//Display the list of choices a player can make
void display_my_choices()
{
    int i;
    if(!objectp(ETO)) return;
    if(!objectp(TO)) return;
    if(member_array(MyPlace, DONTSORT) == -1) my_choices = filter_array(my_choices, "alphabetical_sort", FILTERS_D);
    header();
    for(i=0;i<sizeof(my_choices);i++)
    {
        tell_object(ETO, "  %^BOLD%^%^MAGENTA%^"+capitalize(my_choices[i])+"");
    }
    header();
    tell_object(ETO, "%^BOLD%^%^WHITE%^You may type <%^CYAN%^brief%^BOLD%^%^WHITE%^> at any point if you are familiar "+
    "with the game and wish to skip the extra confirmation prompts.%^RESET%^");
}
//End

//Function that auto picks a choice if there is only 1 option
int check_choices()
{
    if(!sizeof(my_choices)) return 0;
    if(sizeof(my_choices) != 1) return 0;
    tell_object(ETO, "You only had one option for "+MyPlace+", so it has been chosen for you.");
    choose(my_choices[0], 0);
    return 1;
}
//END


//Function for building unique choices list for classes that have uncommon choices
//such as psion discipline, mage school, or fighter style
//special case in this function to point them to the help
//files for their unique choice
void pick_my_unique()
{
    string MyFile, temp;
    if(!objectp(ETO)) return;
    if(!objectp(TO)) return;
    MyFile = "/std/class/"+ MyCharacterInfo["myclass"]["myclass name"] +".c";
    if(!file_exists(MyFile))
    {
        tell_object(ETO, "ERROR: Could not find your class file, please notify a wiz!");
        return;
    }
    my_choices = MyFile->query_newbie_stuff(MyCharacterInfo["myclass"]["alignment"]);
    if(!pointerp(my_choices))
    {
        MyPlace = "deity";
        ProcessStep();
        return;
    }
    else
    {
        unique = MyFile->newbie_choice();
        tell_object(ETO,"\nYou must now choose your "+unique+".");
        display_my_choices();
        tell_object(ETO,"%^BOLD%^%^WHITE%^Type %^BOLD%^<%^CYAN%^pick "+my_choices[0]+"%^BOLD%^%^WHITE%^> to set your "+unique+
        " to "+my_choices[0]+".");
        temp = "%^BOLD%^%^WHITE%^You may review <%^CYAN%^help "+UNIQUE_HELP[unique];
        temp += "%^BOLD%^%^WHITE%^> to get further information.%^RESET%^";
        tell_object(ETO, temp);
        return;
    }
}
//END

//Function that shows available races
void pick_race()
{
    if(!objectp(ETO)) return;
    if(!objectp(TO)) return;
    my_choices = MyCharacterInfo["myclass"]["available races"];
    if(check_choices()) return;
    tell_object(ETO, "%^BOLD%^You must now choose your race. You may pick from the following:");
    if(!sizeof(my_choices)) tell_object(ETO, "%^BOLD%^%^MAGENTA%^Error generating race list - please contact a wiz.");
    else
    {
        display_my_choices();
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^Note: only races with no level adjustment can be rolled in creation, unless you have already linked to an account with experienced characters.\n");
    tell_object(ETO, "%^BOLD%^%^WHITE%^Please refer to <help request characters> for details on playing level-adjustment races.\n");
    tell_object(ETO, "%^BOLD%^Type %^BLACK%^<%^CYAN%^pick racename%^BLACK%^> %^WHITE%^to pick your race.");
    tell_object(ETO, "%^YELLOW%^Syntax example: %^WHITE%^pick "+my_choices[0]+" %^YELLOW%^will make you a "+my_choices[0]+".");
}
//END

void pick_gender()
{
    if(!objectp(ETO)) return;
    if(!objectp(TO)) return;
    my_choices = ({"female","male","other"});
    display_my_choices();

    tell_object(ETO, "\n%^BOLD%^%^WHITE%^Gender defines adjectives the game will use for you.\n");
    tell_object(ETO, "%^BOLD%^%^WHITE%^Note: %^RESET%^some races are locked to a specific gender.\n");
    tell_object(ETO, "%^BOLD%^Type %^BLACK%^<%^CYAN%^pick gendername%^BLACK%^> %^WHITE%^to pick your gender.");
    tell_object(ETO, "%^YELLOW%^Syntax example: %^WHITE%^pick male %^YELLOW%^will make you a male.");
}

//Function for half-elf/half-orcs, or others that need to be able
//to pick a lineage
void pick_special(string str)
{
    if(!objectp(ETO)) return;
    if(!objectp(TO)) return;
    if(!stringp(str)) str = MyCharacterInfo["race"]["race name"];
    if(!stringp(str)) return;
    if(str == "half-orc")
    {
        my_choices = ({"human", "orc"});
        tell_object(ETO, "\n%^BOLD%^%^GREEN%^You may decide which parent "+
        "you take after the most, your human side or your orcish side.");
    }
    else if(str == "half-elf")
    {
        my_choices = ({"human", "elf"});
        tell_object(ETO, "\n%^BOLD%^%^GREEN%^You may decide which parent you take after "+
        "the most, your human side or your elven side.");
    }
    display_my_choices();
    tell_object(ETO, "%^YELLOW%^Syntax example: %^WHITE%^pick "+my_choices[0]+" %^YELLOW%^will set the parent "+
    "that your character takes after the most.");
    return;
}
//END

//Function that shows available subraces
void pick_sub_race()
{
    if(!objectp(ETO)) return;
    if(!objectp(TO)) return;
    my_choices = MyCharacterInfo["myclass"]["available subraces"];
    if(check_choices()) return;
    tell_object(ETO, "%^BOLD%^You must now choose your subrace. You may pick from the following:");
    if(!sizeof(my_choices)) tell_object(ETO, "%^BOLD%^%^MAGENTA%^Error generating race list - please contact a wiz.");
    else
    {
        display_my_choices();
    }
    tell_object(ETO, "%^BOLD%^Type %^BLACK%^<%^CYAN%^pick subrace%^BLACK%^> %^WHITE%^to pick your subrace.");
    tell_object(ETO, "%^YELLOW%^Syntax example: %^WHITE%^pick "+my_choices[0]+" %^YELLOW%^will make you a "+my_choices[0]+".");
    if(MyCharacterInfo["race"]["race name"] == "human" || MyCharacterInfo["race"]["pseudo race"] == "human")
    {
        tell_object(ETO, "%^BOLD%^You may type help <%^BOLD%^%^CYAN%^human ethnicities%^RESET%^%^BOLD%^> to see relevant in depth information about each of the above.%^RESET%^");
    }
    else
    {
        tell_object(ETO, "%^BOLD%^You may type help <%^BOLD%^%^CYAN%^"+MyCharacterInfo["race"]["race name"]+"%^RESET%^%^BOLD%^> to see relevant in depth information about each of the above.%^RESET%^");
    }
}
//END


//genetics related choices - such as hair/eye color, height, weight, body type, and age
void pick_genetics()
{
    int x, max_weight, *weights;
    string MyFile;
    object race_ob;
    mixed targ;
    if(!objectp(ETO)) return;
    if(!objectp(TO)) return;
    if(MyPlace == "eye color" ||
       MyPlace == "hair color" ||
       MyPlace == "bonus language")
    {
        if(MyCharacterInfo["race"]["psuedo race"] != "NIL") targ = MyCharacterInfo["race"]["psuedo race"];
        else targ = MyCharacterInfo["race"]["race name"];
        MyFile = "/std/races/"+targ+".c";
        race_ob = find_object_or_load(MyFile);
        if(!objectp(race_ob))
        {
            tell_object(ETO,"There's something wrong with your race "+targ+", please contact a wiz.");
            return;
        }
    }
    tell_object(ETO, "%^BOLD%^You must now choose your "+MyPlace+". You may pick from the following:");
    switch(MyPlace)
    {
        case "hair color":
            my_choices = MyFile->query_hair_colors(MyCharacterInfo["race"]["subrace"]);
            break;
        case "eye color":
            my_choices = MyFile->query_eye_colors(MyCharacterInfo["race"]["subrace"]);
            break;
        case "bonus language":
        {
            string * langs;
            langs = MyFile->query_languages(MyCharacterInfo["race"]["subrace"])["optional"];
            if(sizeof(langs))
                my_choices = langs;
            else
                my_choices = ({"common","undercommon"});
        }
            break;
        case "template":
        {
            string possible_templates;
            possible_templates = explode(implode(get_dir("/std/acquired_template/*.c"), ""), ".c");

            my_choices = possible_templates;
        }
            break;
        case "height":
            my_choices = HEIGHTS;
            break;
        case "age":
            my_choices = AGES;
//            if(MyCharacterInfo["race"]["race name"] == "shade") my_choices -= ({"child"});
            break;
        case "weight":
            my_choices = keys(WEIGHT_CATS);
            if(!sizeof(my_choices)) tell_object(ETO, "%^BOLD%^%^MAGENTA%^Error generating "+MyPlace+" list - please contact a wiz.");
            //my_choices = filter_array(my_choices, "alphabetical_sort", FILTERS_D);
            my_choices = sort_array(my_choices, 1);
            header();
            for(x = 0;x < sizeof(my_choices);x++)
            {
                tell_object(ETO, "%^BOLD%^%^GREEN%^"+WEIGHT_CATS[my_choices[x]]["display name"]);
            }
            header();
            tell_object(ETO, "%^BOLD%^Type %^BLACK%^<%^CYAN%^pick "+my_choices[0]+"%^BLACK%^> %^WHITE%^"+
            "to set your "+MyPlace+" to "+WEIGHT_CATS[my_choices[0]]["choice"]+".");
            return;
            break;
        case "body type":
            weights = PLAYER_D->calc_weight(ETO, (int)MyCharacterInfo["race"]["weight"]);
            max_weight = weights[1];
            targ = (100 * (int)MyCharacterInfo["race"]["weight"]) / max_weight;
            if(targ <= 65) targ = 1;
            else if(targ > 65 && targ <= 75) targ = 2;
            else if(targ > 75 && targ <= 90) targ = 3;
            else if(targ > 90 && targ <= 110) targ = 4;
            else if(targ > 110 && targ <= 120) targ = 5;
            else if(targ > 120 && targ <= 130) targ = 6;
            else targ = 7;
            my_choices = BODY_TYPES[to_int(targ)];
            break;
    }
    if(check_choices()) return;
    if(!sizeof(my_choices)) tell_object(ETO, "%^BOLD%^%^MAGENTA%^Error generating "+MyPlace+" list - please contact a wiz.");
    else display_my_choices();
    if(sizeof(my_choices)) { tell_object(ETO, "%^BOLD%^Type %^BLACK%^<%^CYAN%^pick "+my_choices[0]+"%^BLACK%^> %^WHITE%^to set your "+MyPlace+" to "+my_choices[0]+"."); }
    return;

}
//END


//Function that shows available classes
void pick_class()
{
    if(!objectp(ETO)) return;
    if(!objectp(TO)) return;
    tell_object(ETO, "%^BOLD%^%^RED%^A grand voice booms from within your mind.");
    tell_object(ETO, "%^BOLD%^You must choose one of the following classes to join:");
    if(!sizeof(my_choices)) tell_object(ETO, "%^BOLD%^%^MAGENTA%^Error generating myclass list - please contact a wiz.");
    else
    {
        display_my_choices();
    }
    tell_object(ETO, "%^BOLD%^Type %^BLACK%^<%^CYAN%^pick classname%^BLACK%^> %^WHITE%^to choose your myclass.");
    tell_object(ETO, "%^YELLOW%^Ex%^BLACK%^: %^WHITE%^pick fighter%^RESET%^ to join the fighter myclass.");
    tell_object(ETO, "%^YELLOW%^Note%^BOLD%^%^BLACK%^: %^WHITE%^You can <%^CYAN%^review%^WHITE%^> to see this information again at any time.%^RESET%^");
    tell_object(ETO, "%^WHITE%^You may also do <%^CYAN%^help classname%^WHITE%^> in order to see detailed information about any given myclass.%^RESET%^");
    return 1;
}
//END


//Function that shows available alignments based on racial and myclass restrictions
void pick_alignment()
{
    int i, x;
    if(!objectp(ETO)) return;
    if(!objectp(TO)) return;
    my_choices = VALID_ALIGNS;
    my_choices -= MyCharacterInfo["race"]["restricted alignments"];
    my_choices -= MyCharacterInfo["myclass"]["restricted alignments"];
    if(!sizeof(my_choices)) tell_object(ETO, "%^BOLD%^%^MAGENTA%^Error generating alignment list - please contact a wiz.");

    tell_object(ETO, "%^YELLOW%^You must now select an alignment. Your race and myclass allow the following options:");
    header();
    for(i=1;i<10;i++)
    {
        if(member_array(i,my_choices) != -1)
        {
            x = i;
            switch(i)
            {
                case 1:
                    astr = "Lawful Good";
                    tell_object(ETO, "%^BOLD%^%^CYAN%^  1.) Lawful Good");
                    break;
                case 2:
                    astr = "Lawful Neutral";
                    tell_object(ETO, "%^BOLD%^%^CYAN%^  2.) Lawful Neutral");
                    break;
                case 3:
                    astr = "Lawful Evil";
                    tell_object(ETO, "%^BOLD%^%^CYAN%^  3.) Lawful Evil");
                    break;
                case 4:
                    astr = "Neutral Good";
                    tell_object(ETO, "%^BOLD%^%^CYAN%^  4.) Neutral Good");
                    break;
                case 5:
                    astr = "True Neutral";
                    tell_object(ETO,"%^BOLD%^%^CYAN%^  5.) True Neutral");
                    break;
                case 6:
                    astr = "Neutral Evil";
                    tell_object(ETO,"%^BOLD%^%^CYAN%^  6.) Neutral Evil");
                    break;
                case 7:
                    astr = "Chaotic Good";
                    tell_object(ETO, "%^BOLD%^%^CYAN%^  7.) Chaotic Good");
                    break;
                case 8:
                    astr = "Chaotic Neutral";
                    tell_object(ETO,"%^BOLD%^%^CYAN%^  8.) Chaotic Neutral");
                    break;
                case 9:
                    astr = "Chaotic Evil";
                    tell_object(ETO,"%^BOLD%^%^CYAN%^  9.) Chaotic Evil");
                    break;
                default: tell_object(ETO, "%^BOLD%^%^RED%^There has been an error selecting your alignment! Please contact a wiz."); break;
            }
        }
    }
    header();
    tell_object(ETO, "%^YELLOW%^Syntax example: pick "+x);
    tell_object(ETO, "%^BOLD%^%^WHITE%^This will set your alignment to "+astr+".");
}
//END

//FUNCTION to pick a deity
void pick_deity()
{
    int inc, align, myrace, mysubrace;
    string myfile, *badgods, *names, temp;

    my_choices = ({});
    align = MyCharacterInfo["myclass"]["alignment"];
    myrace = MyCharacterInfo["race"]["race name"];
    mysubrace = MyCharacterInfo["race"]["subrace"];
    if(mysubrace == "NIL") mysubrace = "";
    temp = MyCharacterInfo["myclass"]["myclass name"];
    names = keys(DIETIES);

    myfile = DIR_RACES+"/"+myrace+".c";
    badgods = ({});
    if(file_exists(myfile)) badgods += (string *)myfile->restricted_deities(mysubrace);
    names -= badgods;
    if(temp == "paladin" || temp == "cleric") // clergy/orders
    {
        for(inc = 0; inc < sizeof(names);inc ++)
        {
            if(member_array(align,DIETIES[names[inc]][2]) == -1) continue;
            my_choices += ({names[inc]});
        }
    }
    else
    {
        for(inc = 0; inc < sizeof(names);inc ++)
        {
            if(member_array(align,DIETIES[names[inc]][1]) == -1) continue;
            my_choices += ({names[inc]});
        }
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^You must now choose which deity you wish to follow.%^RESET%^");
    header();
    tell_object(ETO, "%^YELLOW%^Deity Name         Sphere of Control");
    tell_object(ETO, "%^BLUE%^------------         -------------------");
    for(inc = 0; inc < sizeof(my_choices);inc ++)
    {
        tell_object(ETO,sprintf("%%^CYAN%%^%-20s %%^GREEN%%^%s",capitalize(my_choices[inc]),capitalize(DIETIES[my_choices[inc]][0])));
    }
    header();
    tell_object(ETO, "%^BOLD%^Type %^BLACK%^<%^CYAN%^pick "+my_choices[0]+"%^BLACK%^> %^WHITE%^to set your "+MyPlace+" to "+my_choices[0]+".");
    tell_object(ETO, "%^BOLD%^Alternatively, you can %^BLACK%^<%^CYAN%^pick godless%^BLACK%^> %^WHITE%^to select no patron deity. However %^YELLOW%^please note%^BOLD%^%^WHITE%^, having no deity to intercede for you will put far more strain on your character if returned from the afterlife.");
    return 1;
}


//Function that builds a list of restrictions
//currently handles restrictions for myclass and race
//myclass restriction sets up available races and subraces
//race restriction sets up available subraces for a particular race given the myclass and race choice
void build_restrictions(string type)
{
    object MyOb;
    string MyFile, *possible_races, MyClass, *available_races, *available_subraces, *possible_subraces;
    string ThisSubRace, *temp_data, targ;
    mapping minimumstatsmap;
    int i, y, rflag = 1;

    switch(type)
    {
        //builds myclass based restrictions - IE races/alignments related to myclass/minimum stats - Saide
        case "myclass":
            available_races = ({});
            available_subraces = ({});
            possible_races = get_dir("/std/races/*.c");
            possible_races = explode(implode(possible_races, ""), ".c");
            //tell_object(ETO, "possible races = "+identify(possible_races));
            if(!pointerp(possible_races))
            {
                tell_object(ETO, "ERROR: Generating a list of possible races!");
                return;
            }
            MyClass = MyCharacterInfo["myclass"]["myclass name"];
            MyFile = "/std/class/"+MyClass+".c";
            if(file_exists(MyFile))
            {
                minimumstatsmap = MyFile->stat_requirements();
                if(mapp(minimumstatsmap))
                {
                    MyCharacterInfo["myclass"]["minimum stats"] = minimumstatsmap;
                }
                temp_data = MyFile->restricted_alignments();
                if(pointerp(temp_data))
                {
                    MyCharacterInfo["myclass"]["restricted alignments"] = temp_data;
                }
            }
            for(i = 0;i < sizeof(possible_races);i++)
            {
                MyFile = "/std/races/"+possible_races[i]+".c";
                if(!file_exists(MyFile)) continue;
                temp_data = MyFile->restricted_classes("");
                if(MyFile->is_restricted() && rflag)
                {
                    if(OB_ACCOUNT->is_experienced(ETO->query_true_name()) ||
                       OB_ACCOUNT->is_high_mortal(ETO->query_true_name()))
                        rflag = 0;
                    if(avatarp(ETO)) rflag = 0;
                    if(ETO->query("is_valid_npc")) rflag = 0;
                    if(rflag) continue;
                }
                if(MyFile->is_gender_locked(MyCharacterInfo["race"]["gender"]))
                    continue;
                if(member_array(MyClass, temp_data) == -1) available_races += ({possible_races[i]});
                //tell_object(ETO, "RACE OB existed!");
                possible_subraces = MyFile->query_subraces(ETO);
                if(pointerp(possible_subraces))
                {
                    for(y = 0;y < sizeof(possible_subraces);y++)
                    {
                        ThisSubRace = possible_subraces[y];
                        temp_data = MyFile->restricted_classes(ThisSubRace);
                        if(!pointerp(temp_data))
                        {
                            available_subraces += ({ThisSubRace});
                            continue;
                        }
                        else
                        {
                            if(member_array(MyClass, temp_data) == -1)
                            {
                                if(member_array(ThisSubRace, available_subraces) == -1) available_subraces += ({ThisSubRace});
                                if(member_array(possible_races[i], available_races) == -1) available_races += ({possible_races[i]});

                            }
                            continue;
                        }
                    }
                    continue;
                }
                //tell_object(ETO, "RACE OB DOES NOT EXIST for "+possible_races[i]+"!");
                continue;
            }
            available_races = distinct_array(available_races);
            available_subraces = distinct_array(available_subraces);
            MyCharacterInfo["myclass"]["available races"] = available_races;
            MyCharacterInfo["myclass"]["available subraces"] = available_subraces;
            break;
        case "race": case "subrace":
            MyFile = "/std/races/"+MyCharacterInfo["race"]["race name"] +".c";
            if(!file_exists(MyFile))
            {
                tell_object(ETO, "ERROR: Could not find your race file.");
                return;
            }
            if(type == "subrace") temp_data = MyFile->restricted_alignments(MyCharacterInfo["race"]["subrace"]);
            else temp_data = MyFile->restricted_alignments();
            if(pointerp(temp_data))
            {
                MyCharacterInfo["race"]["restricted alignments"] = temp_data;
            }
            if(type == "subrace") break;
            available_subraces = ({});

            if(MyCharacterInfo["race"]["psuedo race"] != "NIL") targ = MyCharacterInfo["race"]["psuedo race"];
            else targ = MyCharacterInfo["race"]["race name"];

            MyFile = "/std/races/"+targ+".c";
            if(file_exists(MyFile))
            {
                possible_subraces = MyFile->query_subraces(ETO);
                temp_data = MyCharacterInfo["myclass"]["available subraces"];
                for(i = 0;i < sizeof(possible_subraces);i++)
                {
                    if(member_array(possible_subraces[i], temp_data) != -1) available_subraces += ({possible_subraces[i]});
                    continue;
                }
            }
            else tell_object(ETO, "Failed to find a valid race obj");
            MyCharacterInfo["myclass"]["available subraces"] = available_subraces;
            //no subraces
            if(!sizeof(available_subraces))
            {
                if((targ = MyCharacterInfo["race"]["psuedo race"]) != "NIL")
                {
                    if(targ == "orc") MyCharacterInfo["myclass"]["available subraces"] = ({"gray orc"});
                    else if(targ == "elf") MyCharacterInfo["myclass"]["available subraces"] = "/std/races/elf.c"->query_subraces(ETO);
                    else if(targ == "human") MyCharacterInfo["myclass"]["available subraces"] = "/std/races/human.c"->query_subraces(ETO);
                    else MyPlace = "stats";
                }
                else MyPlace = "stats";
            }
            break;
    }
}
//END

//Function that displays what a player has chosen
void extra_display(string str)
{
    string temp = "\n";
    if(!objectp(ETO)) return;
    if(stringp(str))
    {
        if(MyPlace == "special") temp += "%^BOLD%^%^WHITE%^You have chosen take after your %^BOLD%^%^CYAN%^"+str+"%^BOLD%^%^WHITE%^ parent.%^RESET%^";
        else if(MyPlace == "unique") temp += "%^BOLD%^%^WHITE%^You have chosen %^BOLD%^%^CYAN%^"+str+ "%^BOLD%^%^WHITE%^ for your %^BOLD%^%^CYAN%^"+unique+"%^BOLD%^%^WHITE%^.%^RESET%^";
        else if(MyPlace == "weight") temp += "%^BOLD%^%^WHITE%^You have chosen %^BOLD%^%^CYAN%^"+ WEIGHT_CATS[str]["choice"] +"%^BOLD%^%^WHITE%^ for your %^BOLD%^%^CYAN%^"+MyPlace+"%^BOLD%^%^WHITE%^.%^RESET%^";
        else temp += "%^BOLD%^You have chosen %^BOLD%^%^CYAN%^"+str+"%^BOLD%^%^WHITE%^ for your %^BOLD%^%^CYAN%^"+MyPlace+"%^RESET%^.";
    }
    temp += "\nYou can also <%^CYAN%^review%^WHITE%^> to see your current options.\n"+
    "You can also <%^CYAN%^check%^WHITE%^> to see all choices you have made.";
    tell_object(ETO, temp);
}
//END

//Displays a list of blurbs based on where the player is in the system
//these should be contained in /d/shadowgate/blurbs.h
//currently supports race, myclass, and subrace - provides
//a brief description of each to a player with brieff mode off (default)
//so that they have an idea of what they are picking
void display_blurb(string str)
{
    if(!objectp(ETO)) return;
    tell_object(ETO, "%^BOLD%^%^BLUE%^\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    switch(MyPlace)
    {
        case "myclass":
            tell_object(ETO, "%^BOLD%^%^WHITE%^"+CLASS_BLURBS[str]);
            break;
        case "race":
            tell_object(ETO, "%^BOLD%^%^WHITE%^"+RACE_BLURBS[str]);
            break;
        case "subrace":
            tell_object(ETO, "%^BOLD%^%^WHITE%^"+SUB_RACE_BLURBS[str]);
            break;
        case "deity":
            tell_object(ETO, "%^BOLD%^%^WHITE%^"+DEITY_BLURBS[str]);
            break;
        case "unique":
            tell_object(ETO, "%^BOLD%^%^WHITE%^"+UNIQUE_BLURBS[unique][str]);
            break;
    }
    tell_object(ETO, "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n%^RESET%^");
    if(MyPlace == "unique")
    {
        tell_object(ETO, "Are you sure that you want to pick the %^BOLD%^%^CYAN%^"+unique+" "+str+
        "%^RESET%^? Enter %^BOLD%^%^CYAN%^yes%^RESET%^ to confirm or anything else to abort.");
    }
    else
    {
        tell_object(ETO, "Are you sure that you want to pick the %^BOLD%^%^CYAN%^"+MyPlace+" "+str+
        "%^RESET%^? Enter %^BOLD%^%^CYAN%^yes%^RESET%^ to confirm or anything else to abort.");
    }
    return;
}
//END


//Confirms a choice when there is extra information
//IE - do you want to be an elf given what the blurb shows about them?
void confirm_my_choice(string str, string choice)
{
    if(!stringp(str))
    {
        ProcessStep();
        return;
    }
    str = lower_case(str);
    if(str != "yes")
    {
        ProcessStep();
        return;
    }
    choose(choice, 1);
    return;
}
//END

//Checks the current choices list to make sure the choice
//the player entered is in that list
int check_my_choice(string str)
{
    if(MyPlace == "deity" && str == "godless") return 0; // needed this in to bypass without breaking the deities array!
    if(member_array(str,my_choices) == -1) {
        tell_object(ETO, "\n%^BOLD%^%^RED%^Sorry but %^MAGENTA%^"+str+"%^BOLD%^%^RED%^ is not a valid choice for you.");
        return 1;
    }
    return 0;
}
//END

//Arguable the most important function in the
//code - this actually checks a decision and sets it - handles
//all decisions except for stats - which are assigned, instead of picked
varargs int choose(string str, int flag)
{
    int numcl, x,ex;
    string *possible_races, *temp_data;
    if(!stringp(MyPlace)) reset_character_info();
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(stringp(str)) str = lower_case(str);
    switch(MyPlace)
    {
        case "myclass":
            if(check_my_choice(str)) { pick_class(); return 1; }
            if(!flag && !MyBrief)
            {
                temp_data = keys(CLASS_BLURBS);
                if(member_array(str, temp_data) != -1)
                {
                    display_blurb(str);
                    input_to("confirm_my_choice", 0, str);
                    break;
                }
            }
            extra_display(str);
            MyCharacterInfo["myclass"]["myclass name"] = str;
            MyPlace = "gender";
            ProcessStep();
            break;
        case "gender":
            if(check_my_choice(str)) { pick_gender(); return 1; }
            MyCharacterInfo["race"]["gender"] = str;
            MyPlace = "race";
            build_restrictions("myclass");
            ProcessStep();
            break;
        case "race":
            if(check_my_choice(str)) { pick_race(); return 1; }
            if(!flag && !MyBrief)
            {
                temp_data = keys(RACE_BLURBS);
                if(member_array(str, temp_data) != -1)
                {
                    display_blurb(str);
                    input_to("confirm_my_choice", 0, str);
                    break;
                }
            }
            extra_display(str);
            MyCharacterInfo["race"]["race name"] = str;
            ETO->set_race(str);
            if(str == "half-orc" || str == "half-elf")
            {
                MyPlace = "special";
                pick_special(str);
                break;
            }
            else
            {
                MyPlace = "subrace";
                build_restrictions("race");
                ProcessStep();
                break;
            }
            break;
        case "special":
            if(check_my_choice(str)) { pick_special(MyCharacterInfo["race"]["race name"]); return 1; }
            extra_display(str);
            MyCharacterInfo["race"]["psuedo race"] = str;
            MyPlace = "subrace";
            build_restrictions("race");
            ProcessStep();
            break;
        case "deity":
            if(check_my_choice(str)) { pick_deity(); return 1; }
            if(!flag && !MyBrief)
            {
                temp_data = keys(DEITY_BLURBS);
                if(member_array(str, temp_data) != -1)
                {
                    display_blurb(str);
                    input_to("confirm_my_choice", 0, str);
                    break;
                }
            }
            extra_display(str);
            MyCharacterInfo["myclass"]["deity"] = str;
            if(EndAt == "") FirstBuild = 1;
            MyPlace = "finalize";
            ProcessStep();
            break;
        case "subrace":
            if(check_my_choice(str)) { pick_sub_race(); return 1; }
            if(!flag && !MyBrief)
            {
                temp_data = keys(SUB_RACE_BLURBS);
                if(member_array(str, temp_data) != -1)
                {
                    display_blurb(str);
                    input_to("confirm_my_choice", 0, str);
                    break;
                }
            }
            extra_display(str);
            MyCharacterInfo["race"]["subrace"] = str;
            MyPlace = "stats";
            build_restrictions("subrace");
            ProcessStep();
            break;
        case "alignment":
            if(member_array(to_int(str),my_choices) == -1)
            {
                tell_object(ETO, "%^BOLD%^%^WHITE%^That is not a valid alignment for your race and myclass! Please try again.");
                pick_alignment();
                return 1;
            }

            astr = VALID_AL_TITLES[to_int(str)];
            tell_object(ETO, "\n%^YELLOW%^Your alignment is set to "+astr+".");
            extra_display(0);
            MyCharacterInfo["myclass"]["alignment"] = to_int(str);
            MyCharacterInfo["myclass"]["align title"] = astr;
            MyPlace = "unique";
            ProcessStep();
            break;
        case "stats":
            return 0;
            break;
        case "unique":
            if(check_my_choice(str)) { pick_my_unique(); return 1;}
            if(!flag && !MyBrief)
            {
                temp_data = keys(UNIQUE_BLURBS);
                if(member_array(unique, temp_data) != -1)
                {
                    temp_data = keys(UNIQUE_BLURBS[unique]);
                    if(member_array(str, temp_data) != -1)
                    {
                        display_blurb(str);
                        input_to("confirm_my_choice", 0, str);
                        break;
                    }
                }
            }
            extra_display(str);
            MyCharacterInfo["myclass"]["unique choice"] = str;
            MyCharacterInfo["myclass"]["unique type"] = unique;
            MyPlace = "deity";
            ProcessStep();
            break;
        case "hair color":
            if(check_my_choice(str)) { pick_genetics(); return 1;}
            extra_display(str);
            MyCharacterInfo["race"]["hair color"] = str;
            MyPlace = "eye color";
            ProcessStep();
            break;
        case "eye color":
            if(check_my_choice(str)) { pick_genetics(); return 1;}
            extra_display(str);
            MyCharacterInfo["race"]["eye color"] = str;
            MyPlace = "height";
            ProcessStep();
            break;
        case "height":
            if(check_my_choice(str)) { pick_genetics(); return 1;}
            extra_display(str);
            ETO->set_player_height(PLAYER_D->calc_height(ETO, HEIGHT_CATS[str]));
            MyCharacterInfo["race"]["height choice"] = str;
            MyCharacterInfo["race"]["height"] = HEIGHT_CATS[str];
            MyPlace = "weight";
            ProcessStep();
            break;
        case "weight":
            if(check_my_choice(str)) { pick_genetics(); return 1;}
            extra_display(str);
            temp_data = PLAYER_D->calc_weight(ETO, WEIGHT_CATS[str]["value"]);
            MyCharacterInfo["race"]["weight"] = temp_data[0];
            MyCharacterInfo["race"]["weight choice"] = WEIGHT_CATS[str]["choice"];
            MyPlace = "body type";
            ProcessStep();
            break;
        case "body type":
            if(check_my_choice(str)) { pick_genetics(); return 1;}
            extra_display(str);
            MyCharacterInfo["race"]["body type"] = str;
            MyPlace = "age";
            ProcessStep();
            break;
        case "template":
            if(check_my_choice(str)) { pick_genetics(); return 1;}
            extra_display(str);
            MyCharacterInfo["race"]["template"] = str;
            MyPlace = "hair color";
            ProcessStep();
            break;
        case "age":
            if(check_my_choice(str)) { pick_genetics(); return 1;}
            extra_display(str);
            MyCharacterInfo["race"]["age choice"] = str;
            MyCharacterInfo["race"]["age"] = AGE_CATS[str];
            if(MyCharacterInfo["stats"]["intelligence"]>16)
                MyPlace = "bonus language";
            else
                MyPlace = "alignment";
            ProcessStep();
            break;
        case "bonus language":
            if(check_my_choice(str)) { pick_genetics(); return 1;}
            extra_display(str);
            MyCharacterInfo["race"]["bonus language"] = str;
            MyPlace = "alignment";
            ProcessStep();
            break;
    }
    return 1;
}
//END
