#include <daemons.h>

inherit OBJECT;

string *ROLL_CHAIN = ({"class", "race", "subrace", "template"});

int head = 0;

mapping char_sheet = ([]);

void create()
{
    ::create();
    set_short("A strange and powerful object");
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
    set_property("no drop", 1);
    set_property("death keep", 1);
    set_id(({ "setter object", "object", "charactercreationsetterobject" }));
    set_weight(0);
    set_property("no animate", 1);
    set_property("soulbound", 1);
}

void init()
{
    ::init();
    if (!objectp(TP)) {
        return;
    }
    if (!interactive(TP)) {
        return;
    }
    if (userp(ETO))
        if (!newbiep(ETO)) {
            TO->remove();
        }
// actions to add: reset done reroll add review pick check finalize brief recommended random
    add_action("_pick", "pick");
}

_pick(string str)
{
    if (call_other(TO, "select_" + ROLL_CHAIN[head], str)) {
        head++;
        if (head >= sizeof(ROLL_CHAIN)) {
            review();
        } else {
            call_other(TO, "display_" + ROLL_CHAIN[head]);
        }
    } else {
        call_other(TO, "display_" + ROLL_CHAIN[head]);
    }
}

review()
{
    string i;

    foreach(i in keys(char_sheet)) {
        tell_object(ETO, i + ":" + char_sheet[i]);
    }
}

// MODULES

select_class(string str)
{
    string * choices = generate_class();

    if (!member_array(str, choices)) {
        write("INVALID SELECTION " + str);
        return 0;
    }

    char_sheet["class"] = str;
    return 1;
}

display_class()
{
    string i;
    string * choices = generate_class();

    foreach(i in choices)
    {
        write("%^BOLD%^%^MAGENTA%^" + i);
    }
}

string *generate_class()
{
    string * choices;

    choices = get_dir("/std/class/*.c");
    choices = map(choices, (:replace_string($1, ".c", ""):));
    choices = filter_array(choices, (:!find_object_or_load("/std/class/" + $1)->is_prestige_class():));
    choices = filter_array(choices, (:!find_object_or_load("/std/class/" + $1)->is_locked_class():));

    return choices;
}
