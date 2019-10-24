#include <std.h>
#include <clock.h>
#include <rooms.h>
#include <new_exp_table.h>
#include <objects.h>
#include <daemons.h>

mixed * genoutput(object targ)
{
    mixed * output=({});
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
        if(targ->is_werewolf())
            race_var = "Werewolf "+race_var;
        if(objectp(shape = TP->query_property("shapeshifted")))
        {
            race_var = (string)shape->query_shape_race();
            race_var = capitalize(race_var);
        }
        output+=({({"Race","%^BOLD%^%^CYAN%^"+capitalize(race_var)})});
    }

    output+=({({"Gender","%^BOLD%^%^BLUE%^"+capitalize(targ->query_gender())})});

#define AL_COLOR ({"%^BOLD%^%^YELLOW%^", "%^BOLD%^%^WHITE%^", "%^WHITE%^","%^BOLD%^%^BLUE%^", "%^BLUE%^", "%^CYAN%^","%^ORANGE%^", "%^BOLD%^%^RED%^", "%^RED%^" })
    output+=({({"Alignment",AL_COLOR[targ->query_alignment()-1]+capitalize(targ->query_al_title(targ->query_alignment()))})});

    output+=({({"Class","%^BOLD%^%^MAGENTA%^"+implode(targ->query_classes(),"/")})});

    {
        string * classes = targ->query_classes();
        string cl;
        string * clvls = ({});

        foreach(cl in classes)
        {
            clvls+=({""+targ->query_class_level(cl)});
        }

        output+=({({"Level","%^BOLD%^%^GREEN%^"+implode(clvls,"/")+ " (%^RESET%^"+targ->query_character_level()+"%^BOLD%^%^GREEN%^)"+(targ->query("scaledlevel")?"%^RED%^(scaled)%^RESET%^":"")})});
    }

    if(targ->query_character_level()<100)
        output+=({({"Exp to Next","%^BOLD%^%^WHITE%^"+english_number(EXP_NEEDED[targ->query_character_level() + 1]-targ->query_exp())})});
    output+=({({"Exp Tax","%^BOLD%^%^CYAN%^"+english_number(targ->query_XP_tax()["improvement"]["amount"])})});
    output+=({({"Exp","%^BOLD%^%^CYAN%^"+english_number(targ->query_exp())})});


    output+=({({"Armor Class","%^BOLD%^%^WHITE%^"+BONUS_D->effective_ac(targ)+" base + "+BONUS_D->ac_bonus(targ,targ)+" dex"})});
    output+=({({"Base Hit",BONUS_D->new_bab(1, targ)})});

    if(stringp(targ->query_diety()))
        output+=({({"Deity","%^BOLD%^%^MAGENTA%^"+capitalize(targ->query_diety())})});
    if(stringp(targ->query_sphere()))
        output+=({({"Sphere","%^BOLD%^%^BLUE%^"+targ->query_sphere()})});
    if(targ->is_class("mage"))
        if(stringp(targ->query_school()))
            output+=({({"Speciality","%^BOLD%^%^CYAN%^"+targ->query_school()})});
    if(targ->is_class("psion"))
        if(stringp(targ->query_discipline()))
            output+=({({"Discipline","%^BOLD%^%^CYAN%^"+targ->query_discipline()})});
    if(targ->is_class("fighter"))
        if(stringp(targ->query_fighter_style()))
            output+=({({"Fighter Style","%^BOLD%^%^CYAN%^"+targ->query_fighter_style()})});
    if(targ->is_class("monk"))
        if(stringp(targ->query("monk way")))
            output+=({({"Monk Way","%^BOLD%^%^CYAN%^"+capitalize(targ->query("monk way"))})});
    if(targ->is_class("cleric"))
        if(pointerp(targ->query_divine_domain()))
            output+=({({"Divine Domain","%^BOLD%^%^WHITE%^"+implode(targ->query_divine_domain(),"/")})});

    output+=({({"Play Time","%^BOLD%^%^WHITE%^"+parse_time(targ->query_age())})});

    output+=({({"Age","%^BOLD%^"+targ->query_real_age()+" %^CYAN%^("+targ->query_real_age_cat()+")"})});
    output+=({({"Height","%^YELLOW%^"+targ->query_player_height()+" %^MAGENTA%^inches"})});
    output+=({({"Weight","%^YELLOW%^"+targ->query_player_weight()+" %^MAGENTA%^lbs"})});
    output+=({({"Body type","%^YELLOW%^"+targ->query_body_type()})});
    output+=({({"Hair Color","%^BOLD%^"+targ->query_hair_color()})});
    output+=({({"Eye Color","%^BOLD%^"+targ->query_eye_color()})});
    return output;
}

int cmd_score(string args)
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

    write("%^RESET%^%^GREEN%^--=%^BOLD%^<%^WHITE%^ "+targ->query_title()+ " %^BOLD%^%^GREEN%^>%^RESET%^%^GREEN%^=--%^RESET%^");

    {
        foreach(oline in output)
        {

            tell_object(TP,"%^BOLD%^%^GREEN%^ "+arrange_string(oline[0]+" %^BOLD%^%^BLACK%^--------------",arrange,)+"%^RESET%^%^GREEN%^ : %^RESET%^"+oline[1]);
        }
    }

    return 1;
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

hp, money, stats, biography, inventory, eq, flag, who
");
}
