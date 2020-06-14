#include <daemons.h>
#include "genetics.h"
#include <dieties.h>

inherit OBJECT;

string *ROLL_CHAIN = ({"class", "gender", "race", "subrace", "template", "stats", "age", "height", "weight", "body_type", "alignment", "diety", "class_special"});

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

    add_action("_select", "pick");
    add_action("_select", "select");
    add_action("_select", "sel");

    add_action("_review", "review");

    _review();
}

_select(string str)
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
        display_char_sheet();
    } else {
        display_common();
    }
}

select_common(string str)
{
    string * choices;

    if (function_exists("select_" + ROLL_CHAIN[head], TO)) {
        call_other(TO, "select_" + ROLL_CHAIN[head], str);
        return;
    }

    str = lower_case(str);

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

    if (function_exists("display_" + ROLL_CHAIN[head], TO)) {
        call_other(TO, "display_" + ROLL_CHAIN[head]);
        return;
    }

    choices = call_other(TO, "generate_" + ROLL_CHAIN[head]);


    if (sizeof(choices) > 1) {
        write("%^BOLD%^%^WHITE%^You must now choose your %^CYAN%^" + replace_string(ROLL_CHAIN[head], "_", " ") + "%^WHITE%^ from the following:\n");
        foreach(i in choices)
        {
            write(" %^GREEN%^%^BOLD%^" + capitalize(i));
        }
    write("
%^BOLD%^%^WHITE%^To choose type %^ORANGE%^<select %^ULINE%^OPTION%^RESET%^%^ORANGE%^%^BOLD%^>%^WHITE%^, e.g. %^ORANGE%^<select " + choices[0] + ">%^WHITE%^.");
    } else if (sizeof(choices) == 1) {
        select_common(choices[0]);
        advance_head();
    } else {
        advance_head();
    }

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

string *generate_gender()
{
    return ({"male", "female", "other"});
}

string *generate_race()
{
    string * choices;

    choices = get_dir("/std/races/*.c");
    choices = map(choices, (:replace_string($1, ".c", ""):));
    choices = filter_array(choices, (:member_array($1, ("/std/class/" + $2)->restricted_races()) == -1:), char_sheet["class"]);
    choices = filter_array(choices, (:!(("/std/races/" + $1)->is_gender_locked(char_sheet["gender"])):));
    choices = filter_array(choices, (:sizeof(({1, 2, 3, 4, 5, 6, 7, 8, 9}) - (("/std/races/" + $1)->restricted_alignments(char_sheet["subrace"]) + ("/std/class/" + $2)->restricted_alignments())) :), char_sheet["class"]);

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
    mapping race_stats = ([]);

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
        char_sheet["stats"] += cache["minstats"];
    }

    {
        race_stats["strength"] = ("/std/races/" + char_sheet["race"])->stat_mods(char_sheet["subrace"])[0];
        race_stats["dexterity"] = ("/std/races/" + char_sheet["race"])->stat_mods(char_sheet["subrace"])[1];
        race_stats["constitution"] = ("/std/races/" + char_sheet["race"])->stat_mods(char_sheet["subrace"])[2];
        race_stats["intelligence"] = ("/std/races/" + char_sheet["race"])->stat_mods(char_sheet["subrace"])[3];
        race_stats["wisdom"] = ("/std/races/" + char_sheet["race"])->stat_mods(char_sheet["subrace"])[4];
        race_stats["charisma"] = ("/std/races/" + char_sheet["race"])->stat_mods(char_sheet["subrace"])[5];
    }

    write("
");
    foreach(i in STATS) {
        write("%^BOLD%^%^GREEN%^ " + arrange_string(capitalize(i) + " ", 12) + "%^BOLD%^%^BLACK%^ : %^WHITE%^" + sprintf("%2s", "" + char_sheet["stats"][i]) + (race_stats[i] ? ((race_stats[i] > 0 ? "%^BOLD%^%^CYAN%^ +" : "%^BOLD%^%^RED%^ ") + race_stats[i]) : ""));
        sum += char_sheet["stats"][i];
    }

    write("\n");
    if (92 - sum == 0) {
        write("%^BOLD%^%^GREEN%^You may proceed to the next step.");
    } else {
        write("%^BOLD%^%^GREEN%^You have %^CYAN%^" + (92 - sum) + "%^GREEN%^ points left to assign.");
    }


    synopsis_stats();
}

string *generate_hair_color()
{
    string * choices;

    choices = ("/std/races/" + char_sheet["race"])->query_hair_colors(stringp(char_sheet["subrace"]) ? char_sheet["subrace"] : 0);

    return sort_array(choices, 1);
}

string *generate_eye_color()
{
    string * choices;

    choices = ("/std/races/" + char_sheet["race"])->query_eye_colors(stringp(char_sheet["subrace"]) ? char_sheet["subrace"] : 0);

    return sort_array(choices, 1);
}

display_height()
{
    write("
");
    synopsis_height();
}

select_height(string str)
{
    int amount;

    string racefile = "/std/races/" + char_sheet["race"];

    int minh = racefile->height_base(char_sheet["gender"]);
    int maxh = minh + racefile->height_mod(char_sheet["gender"]);

    if (str == "random") {
        amount = minh + random(maxh - minh);
    } else {
        if (sscanf(str, "%d", amount) != 1) {
            write("%^BOLD%^%^RED%^You have to enter a number.");
            return 1;
        }

        if (amount > maxh || amount < minh) {
            write("%^BOLD%^%^RED%^Your height must be within allowed range.");
            return 1;
        }
    }

    char_sheet["height"] = amount;
    advance_head();
    return 1;
}

synopsis_height()
{
    string racefile = "/std/races/" + char_sheet["race"];

    int minh = racefile->height_base(char_sheet["gender"]);
    int maxh = minh + racefile->height_mod(char_sheet["gender"]);

    write("%^BOLD%^%^WHITE%^Choose height for your character, anywhere between %^CYAN%^" + minh + "%^WHITE%^ and %^CYAN%^" + maxh + "%^WHITE%^.");
    write("%^BOLD%^%^WHITE%^Enter your %^CYAN%^height%^WHITE%^ in %^CYAN%^inches%^WHITE%^.\n");
    write("%^BOLD%^%^WHITE%^Use %^BOLD%^%^ORANGE%^<select %^ULINE%^NUMBER%^RESET%^%^BOLD%^%^ORANGE%^>%^WHITE%^. For example, %^ORANGE%^<select " + minh + ">%^WHITE%^.");
    write("%^BOLD%^%^WHITE%^You can also select a random value with %^ORANGE%^<select random>%^WHITE%^.");
    write("\n");
}

display_weight()
{
    write("
");
    synopsis_weight();
}

select_weight(string str)
{
    int amount;

    string racefile = "/std/races/" + char_sheet["race"];

    int minh = racefile->weight_base(char_sheet["gender"]);
    int maxh = minh + racefile->weight_mod(char_sheet["gender"]);

    if (str == "random") {
        amount = minh + random(maxh - minh);
    } else {
        if (sscanf(str, "%d", amount) != 1) {
            write("%^BOLD%^%^RED%^You have to enter a number.");
            return 1;
        }

        if (amount > maxh || amount < minh) {
            write("%^BOLD%^%^RED%^Your height must be within allowed range.");
            return 1;
        }
    }

    char_sheet["weight"] = amount;
    advance_head();
    return 1;
}

synopsis_weight()
{
    string racefile = "/std/races/" + char_sheet["race"];

    int minh = racefile->weight_base(char_sheet["gender"]);
    int maxh = minh + racefile->weight_mod(char_sheet["gender"]);

    write("%^BOLD%^%^WHITE%^Choose weight for your character, anywhere between %^CYAN%^" + minh + "%^WHITE%^ and %^CYAN%^" + maxh + "%^WHITE%^.");
    write("%^BOLD%^%^WHITE%^Enter your %^CYAN%^weight%^WHITE%^ in %^CYAN%^pounds%^WHITE%^.\n");
    write("%^BOLD%^%^WHITE%^Use %^BOLD%^%^ORANGE%^<select %^ULINE%^NUMBER%^RESET%^%^BOLD%^%^ORANGE%^>%^WHITE%^. E.g. %^ORANGE%^<select " + minh + ">%^WHITE%^.\n");
    write("%^BOLD%^%^WHITE%^You can also select a random value with %^ORANGE%^<select random>%^WHITE%^.");
    write("\n");
}

string *generate_body_type()
{
    return ({"frail", "skinny", "slender", "svelte", "hardy", "portly", "heavy"});
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

    mapping temp_stats = char_sheet["stats"];

    if (sizeof(cache["minstats"]) && sizeof(("/std/acquired_template/" + char_sheet["template"])->stat_requirements())) {
        write("%^BOLD%^%^RED%^You can't use stat recommendations while having stat restrictions imposed by a template. You're on your own.");
        return 1;
    }

    foreach(i in STATS) {
        temp_stats[i] = RECOMMENDED_STATS[char_sheet["class"]][i];
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

    if (cache["minstats"][stat]) {
        if (char_sheet["stats"][stat] + amount < cache["minstats"][stat]) {
            tell_object(ETO,"%^BOLD%^%^WHITE%^That score will be lower than minimum allowed for " +stat+" %^CYAN%^" +cache["stat"]+"%^WHITE%^ at your class and template combination.");
            return 1;
        }
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

display_age()
{
    write("
");
    synopsis_age();
}

select_age(string str)
{
    int amount;
    int *age_brackets;

    string racefile = "/std/races/" + char_sheet["race"];
    string templatefile = "/std/acquired_template/" + char_sheet["template"];

    if (sscanf(str, "%d", amount) != 1) {
        write("%^BOLD%^%^RED%^You have to enter a number.");
        return 1;
    }

    age_brackets = racefile->age_brackets();

    if (amount < age_brackets[0]) {
        write("%^BOLD%^%^RED%^Your can't be that young.");
        return 1;
    }

    if (!templatefile->query_unbound_age()) {
        if (!racefile->query_unbound_age()) {
            if (amount > age_brackets[3] * 12 / 10) {
                write("%^BOLD%^%^WHITE%^Your can't be that old. Maximum allowed age for your race and template is %^CYAN%^" + age_brackets[3] * 12 / 10 + "%^WHITE%^.");
                return 1;
            }
        }
    }

    char_sheet["age"] = amount;
    advance_head();
    return 1;
}

synopsis_age()
{
    string racefile = "/std/races/" + char_sheet["race"];

    int *age_brackets;

    age_brackets = racefile->age_brackets();

    write("%^BOLD%^%^WHITE%^Choose age for your character.
");
    write("%^BOLD%^%^WHITE%^Values between %^GREEN%^" + age_brackets[0] + "%^WHITE%^ and %^GREEN%^" + age_brackets[1] + "%^WHITE%^ will make you of %^CYAN%^normal%^WHITE%^ age.");
    write("%^BOLD%^%^WHITE%^Values between %^GREEN%^" + age_brackets[1] + "%^WHITE%^ and %^GREEN%^" + age_brackets[2] + "%^WHITE%^ will make you %^CYAN%^middle%^WHITE%^ aged.");
    write("%^BOLD%^%^WHITE%^Values between %^GREEN%^" + age_brackets[2] + "%^WHITE%^ and %^GREEN%^" + age_brackets[3] + "%^WHITE%^ will make you %^CYAN%^old%^WHITE%^.");
    write("%^BOLD%^%^WHITE%^Values above %^GREEN%^" + age_brackets[3] + "%^WHITE%^ will make you %^CYAN%^venerable%^WHITE%^.");

    write("\n%^BOLD%^%^WHITE%^Enter your %^CYAN%^age%^WHITE%^ in %^CYAN%^years%^WHITE%^.\n");
    write("%^BOLD%^%^WHITE%^Use %^BOLD%^%^ORANGE%^<select %^ULINE%^NUMBER%^RESET%^%^BOLD%^%^ORANGE%^>%^WHITE%^. E.g. %^ORANGE%^<select " + (age_brackets[0] + random(age_brackets[1] - age_brackets[0]))+ ">%^WHITE%^.");
}

string *generate_alignment()
{
    string racefile = "/std/races/" + char_sheet["race"];
    string classfile = "/std/class/" + char_sheet["class"];

    int *alignments = ({1, 2, 3, 4, 5, 6, 7, 8, 9});

    string * choices;

    alignments -= racefile->restricted_alignments(char_sheet["subrace"]);
    alignments -= classfile->restricted_alignments();

    choices = map_array(alignments, (: $2->align_to_string($1) :), TO);

    return choices;
}


string *generate_diety()
{
    string * choices = ({});

    if (char_sheet["class"] == "cleric" ||
        char_sheet["class"] == "inquisitor") {
        choices = filter_array(keys(DIETIES), (:member_array($2, DIETIES[$1][2]) != -1:), str_to_align(char_sheet["alignment"]));
    } else {
        choices = filter_array(keys(DIETIES), (:member_array($2, DIETIES[$1][1]) != -1:), str_to_align(char_sheet["alignment"])) + ({"godless"});
        if (char_sheet["class"] == "paladin") {
            choices = choices - (choices - PALADIN_GODS);
        }
    }

    return choices;
}

display_diety()
{
    string * choices = generate_diety();
    string i;

    write("%^BOLD%^%^WHITE%^You must now choose your %^CYAN%^" + replace_string(ROLL_CHAIN[head], "_", " ") + "%^WHITE%^ from the following:\n");
    foreach(i in choices)
    {
        write(" %^GREEN%^%^BOLD%^" + implode(map(explode(i, " "), (:capitalize($1):)), " "));
    }

    write("
%^BOLD%^%^WHITE%^To choose type %^ORANGE%^<select %^ULINE%^OPTION%^RESET%^%^ORANGE%^%^BOLD%^>%^WHITE%^, e.g. %^ORANGE%^<select " + choices[0] + ">%^WHITE%^.");
}

string *generate_class_special()
{
    return ("/std/class/" + char_sheet["class"])->query_newbie_stuff(str_to_align(char_sheet["alignment"]));
}

// Modules end here

string align_to_string(int x)
{
    string * aligarr = ({
                            "lawful good",
                            "lawful neutral",
                            "lawful evil",
                            "neutral good",
                            "true neutral",
                            "neutral evil",
                            "chaotic good",
                            "chaotic neutral",
                            "chaotic evil",
                                });
    if (x > 9 || x < 1) {
        return "";
    }

    return aligarr[x - 1];
}

int str_to_align(string x)
{
    string * aligarr = ({
            "lawful good",
                "lawful neutral",
                "lawful evil",
                "neutral good",
                "true neutral",
                "neutral evil",
                "chaotic good",
                "chaotic neutral",
                "chaotic evil",
                });
    return member_array(x, aligarr) + 1;
}
