#include <daemons.h>
#include "genetics.h"

inherit OBJECT;

string *ROLL_CHAIN = ({"class", "race", "subrace", "template", "stats", "hair_color", "eye_color"});

string *SPECIAL_CHAIN = ({"stats"});

int head = 0;

mapping char_sheet = ([]);
mapping cache = ([]);

int brief = 0;

void create()
{
    ::create();
    set_short("%^MAGENTA%^A strange and powerful object%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This strange object radiates power " +
             "the likes of which you have never before seen. It seems to contain " +
             "the very essence of life, allowing one who holds it to " +
             "make choices which will alter the very fabric of their being. " +
             "You may <%^BOLD%^%^CYAN%^check%^BOLD%^%^WHITE%^> to glimpse " +
             "what choices it contains. You may <%^BOLD%^%^CYAN%^reset choice" +
             "%^BOLD%^%^WHITE%^> to alter one if you are unhappy with it. You " +
             "may <%^BOLD%^%^CYAN%^review%^BOLD%^%^WHITE%^> to see a list " +
             "of current options that this object affords you. It has " +
             "attached itself to you and will be with you for as long as you " +
             "are a newbie character in the world of ShadowGate.%^RESET%^");
    /* set_property("no drop", 1); */
    /* set_property("death keep", 1); */
    set_id(({ "setter object", "object", "charactercreationsetterobject" }));
    set_weight(0);
    /* set_property("no animate", 1); */
    /* set_property("soulbound", 1); */
}

void init()
{
    ::init();
    /* if (userp(ETO)) */
    /*     if (!newbiep(ETO)) { */
    /*         TO->remove(); */
    /*     } */
// actions to add: reset done reroll add review pick check finalize brief recommended random
    add_action("_pick", "pick");
    add_action("_review", "review");


}

_pick(string str)
{
    if (select_common(str)) {
        advance_head();
    } else {
        display_common();
    }
    return 1;
}

_review()
{
    display_common();
    return 1;
}

advance_head()
{
    head++;
    if (head >= sizeof(ROLL_CHAIN)) {
        review();
    } else {
        display_common();
    }
}

select_common(string str)
{
    string * choices;

    if (member_array(ROLL_CHAIN[head], SPECIAL_CHAIN) != -1) {
        call_other(TO, "select_" + ROLL_CHAIN[head]);
        return;
    }

    choices = call_other(TO, "generate_" + ROLL_CHAIN[head]);

    if (sizeof(choices)) {
        if (member_array(str, choices) == -1) {
            write("%^BOLD%^%^WHITE%^Selection %^RED%^" + str + "%^WHITE%^ is not valid for your %^RED%^" + ROLL_CHAIN[head] + "%^WHITE%^.");
            return 0;
        }
    }

    char_sheet[ROLL_CHAIN[head]] = str;

    write("%^BOLD%^%^WHITE%^You have selected %^CYAN%^" + str + "%^WHITE%^ for your %^CYAN%^" + replace_string(ROLL_CHAIN[head], "_", " ") + "%^WHITE%^.");
    return 1;
}

display_common()
{
    string i;
    string * choices;

    if (member_array(ROLL_CHAIN[head], SPECIAL_CHAIN) != -1) {
        call_other(TO, "display_" + ROLL_CHAIN[head]);
        return;
    }

    choices = call_other(TO, "generate_" + ROLL_CHAIN[head]);


    if (sizeof(choices) > 1) {
        write("%^BOLD%^%^WHITE%^You must now choose your %^CYAN%^" + replace_string(ROLL_CHAIN[head], "_", " ") + "%^WHITE%^ from the following:\n");
        foreach(i in choices)
        {
            write(" %^BOLD%^%^MAGENTA%^" + capitalize(i));
        }
    write("%^BOLD%^%^WHITE%^To choose type %^ORANGE%^<pick %^ULINE%^OPTION%^RESET%^%^ORANGE%^%^BOLD%^>%^WHITE%^, e.g. %^ORANGE%^<pick " + choices[0] + ">%^WHITE%^.");
    } else if (sizeof(choices) == 1) {
        select_common(choices[0]);
        advance_head();
    } else {
        advance_head();
    }

    write("
");

    if (brief == 0) {

    }
}

// MODULES

string *generate_class()
{
    string * choices;

    choices = get_dir("/std/class/*.c");
    choices = map(choices, (:replace_string($1, ".c", ""):));
    choices = filter_array(choices, (:!("/std/class/" + $1)->is_prestige_class():));
    choices = filter_array(choices, (:!("/std/class/" + $1)->is_locked_class():));

    return choices;
}

string *generate_race()
{
    string * choices;

    choices = get_dir("/std/races/*.c");
    choices = map(choices, (:replace_string($1, ".c", ""):));
    choices = filter_array(choices, (:member_array($1, ("/std/class/" + $2)->restricted_races()) == -1:), char_sheet["class"]);

    return choices;
}

string *generate_subrace()
{
    string * choices = ({});

    choices = ("/std/races/" + char_sheet["race"])->query_subraces(ETO);
    if (sizeof(choices)) {
        choices = filter_array(choices, (:
                                member_array($2, ("/std/races/" + char_sheet["race"])->restricted_classes($1)) == -1
                                :), char_sheet["class"]);
    }

    return choices;
}

string *generate_template()
{
    string * choices = ({});

    choices = map(filter_array(map(get_dir("/std/acquired_template/*.c"),(:"/std/acquired_template/" + $1:)), (:member_array($2, arrayp($1->races_allowed()) ? $1->races_allowed() : ({$2})) != -1:), char_sheet["race"]), (: replace_string(replace_string($1, "/std/acquired_template/", ""), ".c", "") :));

    return choices;
}

display_stats()
{
    string i;
    int sum = 0;

    if (!sizeof(char_sheet["stats"])) {
        char_sheet["stats"] = ([
                                   "strength":6,
                                   "dexterity":6,
                                   "constitution":6,
                                   "intelligence":6,
                                   "wisdom":6,
                                   "charisma":6,
                                   ]);

        add_action("_reroll_stats", "reroll");
        add_action("_add_stats", "add");
        add_action("_recommended_stats", "recommended");
        add_action("_done_stats", "done");
    }

    if (!sizeof(cache["minstats"])) {
        mapping tmpl_stats = ("/std/acquired_template/" + char_sheet["template"])->stat_requirements();

        cache["minstats"] = ("/std/class/" + char_sheet["class"])->stat_requirements();
        if (sizeof(tmpl_stats)) {
            foreach(i in keys(tmpl_stats)) {
                cache["minstats"][i] = max(({tmpl_stats[i], cache["minstats"][i]}));
            }
        }
    }

    char_sheet["stats"] += cache["minstats"];

    foreach(i in STATS) {
        write("%^BOLD%^%^GREEN%^" + capitalize(i) + " : " + char_sheet["stats"][i]);
        sum += char_sheet["stats"][i];
    }

    write("
%^BOLD%^%^GREEN%^You have %^CYAN%^" + (92 - sum) + "%^GREEN%^ points left to assign.");
    if (92 - sum == 0) {
        write("%^BOLD%^%^GREEN%^You may proceed to the next step.");
    }

    synopsis_stats();
}

synopsis_stats()
{
    write("
%^BOLD%^%^WHITE%^Use %^ORANGE%^<review>%^RESET%^%^BOLD%^ to view your current stats.
%^BOLD%^%^WHITE%^Use %^ORANGE%^<recommended>%^RESET%^%^BOLD%^ to set your stats to recommended value.
%^BOLD%^%^WHITE%^Use %^ORANGE%^<add %^ORANGE%^%^ULINE%^NUM%^RESET%^%^BOLD%^%^ORANGE%^ to %^ORANGE%^%^ULINE%^STAT%^RESET%^%^BOLD%^%^ORANGE%^>%^RESET%^%^BOLD%^ to increase your stat.
%^BOLD%^%^WHITE%^Use %^ORANGE%^<reroll>%^RESET%^%^BOLD%^ to start over.

%^BOLD%^%^WHITE%^Type %^ORANGE%^<done>%^RESET%^%^BOLD%^ when you're done with your selection.
");
}

_done_stats()
{
    string i;
    int sum = 0;

    foreach(i in STATS) {
        sum += char_sheet["stats"][i];
    }

    if (sum != 92) {
        write("
%^BOLD%^%^GREEN%^You have %^CYAN%^" + (92 - sum) + "%^GREEN%^ points left to assign.
%^BOLD%^%^WHITE%^You should assign them to continue.
");
        return 1;
    }

    remove_action("_reroll_stats", "reroll");
    remove_action("_add_stats", "add");
    remove_action("_recommended_stats", "recommended");
    remove_action("_done_stats", "done");

    advance_head();
    return 1;
}

_reroll_stats()
{
    cache["minstats"] = ([]);
    char_sheet["stats"] = ([]);
    display_stats();
    return 1;
}

_recommended_stats()
{
    string i;
    int sum = 0;

    mapping temp_stats = char_sheet["stats"];

    foreach(i in STATS) {
        temp_stats[i] = max(({RECOMMENDED_STATS[char_sheet["class"]][i], cache["minstats"][i]}));
        sum += temp_stats[i];
    }

    if (sum > 92) {
        write("%^BOLD%^%^WHITE%^The total amount of stats you have to get due to template and class limitation exceeds recommendations. You're on your own.");
        synopsis_stats();
        return 1;
    }

    char_sheet["stats"] = temp_stats;

    display_stats();
    return 1;
}

_add_stats(string str){
    int amount;
    string stat;

    string i;
    int sum = 0;

    if (!str) {
        display_stats();
        return 1;
    }

    if (sscanf(str, "%d to %s", amount, stat) != 2) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^Syntax is %^ORANGE%^<add %^ULINE%^NUMBER%^RESET%^%^BOLD%^%^ORANGE%^ to %^ULINE%^STAT%^RESET%^%^BOLD%^%^ORANGE%^>%^RESET%^, e.g. %^BOLD%^%^ORANGE%^<add 10 to intelligence>%^RESET%^%^WHITE.");
        return 1;
    }

    foreach(i in STATS) {
        sum += char_sheet["stats"][i];
    }

    if (amount > (92 - sum)) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You have only %^CYAN%^" + (92 - sum) + "%^RESET%^%^WHITE%^ points left to apply.");
        return 1;
    }

    if (stat == "str") {
        stat = "strength";
    }
    if (stat == "int") {
        stat = "intelligence";
    }
    if (stat == "dex") {
        stat = "dexterity";
    }
    if (stat == "con") {
        stat = "constitution";
    }
    if (stat == "cha") {
        stat = "charisma";
    }
    if (stat == "wis") {
        stat = "wisdom";
    }

    if (char_sheet["stats"][stat] + amount > 18) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^That score will exceed maximum allowed at start %^CYAN%^18%^WHITE%^.");
        return 1;
    }

    if (char_sheet["stats"][stat] + amount < 4) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^That score will be lower than minimum allowed at start %^CYAN%^4%^WHITE%^.");
        return 1;
    }

    if (char_sheet["stats"][stat] + amount < cache["minstats"][stat]) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^That score will be lower than minimum allowed for " +stat+" %^CYAN%^" +cache["stat"]+"%^WHITE%^ at your class and template combination.");
        return 1;
    }

    char_sheet["stats"][stat] += amount;
    display_stats();
    return 1;
}

select_stats()
{

    write("%^BOLD%^%^WHITE%^You must now set your %^CYAN%^stat points.\n");

    synopsis_stats();
}

string *generate_hair_color()
{
    string * choices;

    choices = ("/std/races/" + char_sheet["race"])->query_hair_colors(stringp(char_sheet["subrace"]) ? char_sheet["subrace"] : 0);

    return choices;
}

string *generate_eye_color()
{
    string * choices;

    choices = ("/std/races/" + char_sheet["race"])->query_eye_colors(stringp(char_sheet["subrace"]) ? char_sheet["subrace"] : 0);

    return choices;
}
