#include <daemons.h>
#include "genetics.h"

inherit OBJECT;

string *ROLL_CHAIN = ({"class", "race", "subrace", "template", "stats"});

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
    tell_object(FPL("ilmarinen"),":"+identify(choices));

    if (sizeof(choices)) {
        if (member_array(str, choices) == -1) {
            write("INVALID SELECTION " + str);
            return 0;
        }
    }

    char_sheet[ROLL_CHAIN[head]] = str;
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
        foreach(i in choices)
        {
            write("%^BOLD%^%^MAGENTA%^" + capitalize(i));
        }
    } else if (sizeof(choices) == 1) {
        select_common(choices[0]);
    } else {
        advance_head();
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

        add_action("_add_stats", "add");
        /* add_action("_recommended_stats", "recommended"); */
        /* add_action("_done_stats", "done"); */
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

    synopsis_stats();
}

synopsis_stats()
{
    write("
%^BOLD%^%^WHITE%^Use %^ORANGE%^<review>%^RESET%^%^BOLD%^ to view your current stats.
%^BOLD%^%^WHITE%^Use %^ORANGE%^<add %^ORANGE%^%^ULINE%^NUM%^RESET%^%^BOLD%^%^ORANGE%^ to %^ORANGE%^%^ULINE%^STAT%^RESET%^%^BOLD%^%^ORANGE%^>%^RESET%^%^BOLD%^ to increase your stat.

%^BOLD%^%^WHITE%^Type %^ORANGE%^<done>%^RESET%^%^BOLD%^ when you're done with your selection.
");
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
    synopsis_stats();
}
