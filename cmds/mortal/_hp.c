#include <std.h>
#include <clock.h>
#include <rooms.h>
#include <new_exp_table.h>
#include <objects.h>
#include <daemons.h>

mixed * genoutput(object targ)
{
    mixed * output=({});
    int max = targ->query_formula();
    int cur, perc;


    output+=({({"Health Points","%^RESET%^%^"+targ->query_hp()+"%^BOLD%^%^GREEN%^/%^WHITE%^"+targ->query_max_hp()})});
    if(targ->is_class("psion") ||
       targ->is_class("psywarrior"))
        output+=({({"Power Points","%^RESET%^%^"+targ->query_mp()+"%^BOLD%^%^GREEN%^/%^WHITE%^"+targ->query_max_mp()})});
    output+=({({"Carrying","%^RESET%^%^"+targ->query_internal_encumbrance()+"%^BOLD%^%^GREEN%^/%^WHITE%^"+targ->query_max_internal_encumbrance()})});

    if(!(targ->is_undead() ||
         FEATS_D->usable_feat(targ,"timeless body")))
    {
        cur = targ->query_stuffed();
        perc = cur*100/max;
        output+=({({"Hunger",arrange_string(hunger2str(perc)+"            ",10) + "%^BOLD%^ ("+perc+"%)"})});
        cur = targ->query_quenched();
        perc = cur*100/max;
        output+=({({"Hunger",arrange_string(thirst2str(perc)+"          ",10) + "%^BOLD%^ ("+perc+"%)"})});
    }
    else if(targ->is_vampire())
    {
        output+=({({"%^BOLD%^%^RED%^Blood Hunger",thirst2str(targ->query_bloodlust()/200)+ "%^BOLD%^%^RED%^ ("+targ->query_bloodlust()/200+"%)"})});
    }

    cur = targ->query_intox();
    perc = cur*100/max;
    output+=({({"Intox",arrange_string(intox2str(perc)+"          ",10) + "%^BOLD%^ ("+perc+"%)"})});

    if(POISON_D->is_poisoned(targ))
    {
        output+=({({"Poison","%^RED%^Poisoned"})});
    }

    if(!targ->is_undead())
    {
        output+=({({"Condition","%^BOLD%^%^MAGENTA%^"+targ->query_condition_string()})});
    }

    {
        object effects = targ->query_property("status_effects");
        {
            if(sizeof(effects))
                effects = filter_array(effects,(:objectp($1):));
            if(sizeof(effects))
                output+=({({"Status",implode(map_array(effects->query_name(),
                                        (:capitalize(replace_string($1,"effect_","")):)),", ")})});
        }
    }

    return output;
}

int cmd_hp(string args)
{
    mixed *output=({}), oline;
    object targ;
    int arrange = 14;

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

    output = genoutput(targ);

    foreach(oline in output)
    {
        write("%^BOLD%^%^GREEN%^ "+arrange_string(oline[0]+"%^BOLD%^%^BLACK%^ --------------",arrange)+"%^RESET%^%^GREEN%^ : %^RESET%^"+oline[1]);
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

hp - show your condition");
    if(avatarp(TP)) write("
%^CYAN%^SYNTAX%^RESET%^

hp [%^ORANGE%^%^ULINE%^TARGET%^RESET%^]");
    write(
        "
%^CYAN%^DESCRIPTION%^RESET%^

This command gives you overview of your condition.

%^CYAN%^SEE ALSO%^RESET%^

score, money, stats, biography, inventory, eq
");
}
