#include <std.h>
#include <clock.h>
#include <rooms.h>
#include <new_exp_table.h>
#include <objects.h>
#include <daemons.h>

int cmd_scoreproto(string args)
{
    string *output=({}), oline;
    object targ;

    if (args && avatarp(TP))
    {
        if(!(targ = find_player(args)))
        {
            return notify_fail("That person is not available for scoring.\n");
        }

        else if ((targ = find_player(args)))
        {
            if((int)targ->query_level() > (int)TP->query_level())
            {
                return notify_fail("That person is not available for scoring.\n");
            }
        }
    }
    else
    {
        targ = TP;
    }

    {
        string race_var;
        object shape;
        race_var = capitalize(targ->query_race());
        if(targ->query("subrace"))
        {
            if(strsrch(targ->query("subrace"),targ->query_race())<0)
                race_var = capitalize(targ->query("subrace"))+" "+race_var;
            else
                race_var = capitalize(targ->query("subrace"));
        }
        if(targ->is_undead())
        {
            if(targ->is_vampire())
                race_var = "Vampire "+race_var;
            else
                race_var = "Undead "+race_var;
        }
        if(objectp(shape = TP->query_property("shapeshifted")))
        {
            race_var = (string)shape->query_shape_race();
            race_var = capitalize(race_var);
        }
        output+=({"%^BOLD%^%^GREEN%^Race      : %^RESET%^"+capitalize(race_var)});
    }

    output+=({"%^BOLD%^%^GREEN%^Gender    : %^RESET%^"+capitalize(targ->query_gender())});

#define AL_COLOR ({"%^BOLD%^%^YELLOW%^", "%^BOLD%^%^WHITE%^", "%^WHITE%^","%^BOLD%^%^BLUE%^", "%^BLUE%^", "%^CYAN%^","%^ORANGE%^", "%^BOLD%^%^RED%^", "%^RED%^" })
    output+=({"%^BOLD%^%^GREEN%^Alignment : %^RESET%^"+AL_COLOR[targ->query_alignment()-1]+capitalize(targ->query_al_title(targ->query_alignment()))});


    output+=({"%^BOLD%^%^GREEN%^Age       : %^RESET%^"+targ->query_real_age()+" ("+targ->query_real_age_cat()+")"});
    output+=({"%^BOLD%^%^GREEN%^Height    : %^RESET%^"+targ->query_player_height()+" inches"});
    output+=({"%^BOLD%^%^GREEN%^Weight    : %^RESET%^"+targ->query_player_weight()+" lbs"});
    output+=({"%^BOLD%^%^GREEN%^Body type : %^RESET%^"+targ->query_body_type()});
    output+=({"%^BOLD%^%^GREEN%^Hair Color: %^RESET%^"+targ->query_hair_color()});
    output+=({"%^BOLD%^%^GREEN%^Eye Color : %^RESET%^"+targ->query_eye_color()});

    foreach(oline in output)
    {
        write(oline);
    }
    return 1;
}

string hunger2str(int perc)
{
    if(perc > 100*5/6)
        return "%^BOLD%^%^GREEN%^Stuffed%^RESET%^";
    if(perc > 100*4/6)
        return "%^GREEN%^Not hungry%^RESET%^";
    if(perc > 50)
        return "%^YELLOW%^Hungry%^RESET%^";
    if(perc > 100/3)
        return "%^RED%^Really hungry%^RESET%^";
    if(perc > 100/6)
        return "%^RED%^Very hungry%^RESET%^";

    return "%^RED%^%^BOLD%^Starving%^RESET%^";
}

string thirst2str(int perc)
{
    if(perc > 100*5/6)
        return "%^BOLD%^%^GREEN%^Quenched%^RESET%^";
    if(perc > 100*4/6)
        return "%^GREEN%^Not thirsty%^RESET%^";
    if(perc > 50)
        return "%^YELLOW%^Thirsty%^RESET%^";
    if(perc > 100/3)
        return "%^RED%^Really thirsty%^RESET%^";
    if(perc > 100/6)
        return "%^RED%^Very thirsty%^RESET%^";
    return "%^RED%^%^BOLD%^Parched%^RESET%^";
}

string intox2str(int perc)
{
    if(perc > 100*5/6)
        return "%^BOLD%^%^RED%^Wasted%^RESET%^";
    if(perc > 100*4/6)
        return "%^RED%^Drunk%^RESET%^";
    if(perc > 50)
        return "%^ORANGE%^Lipped%^RESET%^";
    if(perc > 100/3)
        return "%^ORANGE%^Tipsy%^RESET%^";
    if(perc > 100/6)
        return "%^GREEN%^Buzzed%^RESET%^";
    return "%^GREEN%^%^BOLD%^Sober%^RESET%^";
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

score - show your characters score sheet");
    if(avatarp(TP)) write("
%^CYAN%^SYNTAX%^RESET%^

score [%^ORANGE%^%^ULINE%^TARGET%^RESET%^]");
    write(
        "
%^CYAN%^DESCRIPTION%^RESET%^

This command gives you overview of your character, listing many various facts about them.

%^CYAN%^SEE ALSO%^RESET%^

hp, stats, biography, money, inventory, eq
");
}
