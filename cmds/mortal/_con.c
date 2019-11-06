//  Con command give you the monsters hp percentage
//  Created by Grayhawk@ShadowGate
//  June 16, 1995
//  Updated by Firedragon@ShadowGate
//  October 8, 1995
//  Changed to show general description instead of % for better RP feel.
//  Used the long describe info. from /std/living and added for negatives & above 100
//  *Styx*  11/26/02

#include <std.h>

inherit DAEMON;

int lightblind;

int help();


int cmd_con(string str)
{
    object ob;
    int x, y, z;
    string sub, check, pre;

    if(!str)
    {
        string output = "";
        object * attackers = TP->query_attackers();
        int i;

        if(sizeof(attackers))
        {
            output += "%^BOLD%^Attackers:\n";
            for (i = 0; i < sizeof(attackers); ++i)
            {
                output+="%^BOLD%^%^RED%^"+sprintf("%2d",i+1)+":%^RESET%^ "+obj_cond(attackers[i])+"\n";
            }
            write(output);
        }
        return 1;
    }

    if(TP->query_blind())
    {
        return notify_fail("You are blind you can't inspect your opponents condition.\n");
    }

    if (lightblind=TP->light_blind(0)) { return notify_fail(TP->light_blind_fail_message(lightblind)+"\n"); }

    //added by Circe 1/8/05 in response to bug reports that you could con while you couldn't see

    if((ob=present(lower_case(str),ETP)) || (ob=present(capitalize(str),ETP)))
    {
        if(environment(ob) != ETP)
        {
            write("Couldn't find \""+ str +"\" here.");
            return 1;
        }

        if(wizardp(ob) && !wizardp(TP) && (int)ob->query_invis() == 1)
        {
            write("Couldn't find \""+ str +"\" here.");
            return 1;
        }

        if(ob->query_invis() || ob == TP)
        {
            if(!TP->detecting_invis() || ob == TP)
            {
                write("Couldn't find \""+ str +"\" here.");
                return 1;
            }
        }

        if( ob -> is_monster() || ob -> is_player() )
        {
            write(obj_cond(ob));
            return 1;
        }

    }

    write("Couldn't find \""+ str +"\" here.");
    return 1;
}

string obj_cond(object ob)
{
    int x;
    string sub, pre, check;

    sub = ob->query_cap_name();
    pre = "%^RED%^"+sub+" is unconscious";
    x = (  ((int)ob->query_hp()*100)/(int)ob->query_max_hp());

    if(x>100)      check = "%^BOLD%^%^GREEN%^"+sub+" looks unusually healthy.";
    else if(x>90)  check = "%^YELLOW%^"+sub+" is in top shape.";
    else if(x>75)  check = "%^WHITE%^%^BOLD%^"+sub+" is in decent shape.";
    else if(x>60)  check = "%^WHITE%^"+sub+" is slightly injured.";
    else if(x>45)  check = "%^MAGENTA%^"+sub+" is hurting.";
    else if(x>30)  check = "%^ORANGE%^"+sub+" is badly injured.";
    else if(x>15)  check = "%^RED%^%^BOLD%^"+sub+" is terribly injured.";
    else if(x> -1) check = "%^RED%^"+sub+" is near death.";

    else if(ob->is_monster())
    {
        if(x> -10)          check = pre+" and probably should be dead.";
        else if(x> -200)    check = pre+" and should be dying from horrible wounds.";
        else                check = pre+" and at "+x+"%. Gross.";
        return check;
        return 1;
    }

    else if(x> -20)  check = pre+" from numerous wounds.";
    else if(x> -50)  check = pre+" from serious wounds.";
    else if(x> -100) check = pre+" and bleeding from critical wounds.";
    else if(x> -150) check = pre+" and bleeding profusely from grievous wounds.";
    else if(x> -180) check = pre+" and dying from horrific wounds.";
    else if(x> -202) check = pre+" from imminently fatal wounds.";
    else check = pre+" and at "+x+"%. Gross.";

    return check;

}


void help()
{
    write("
%^CYAN%^NAME%^RESET%^

con - check out condition of a being

%^CYAN%^SYNTAX%^RESET%^

con %^ORANGE%^[%^ULINE%^BEING%^RESET%^%^ORANGE%^]

%^CYAN%^DESCRIPTION%^RESET%^

This command will give you a general indication of a monster or PC's health, or lack thereof in human readable form.

Without an argument it will give you condition of all attackers.

%^CYAN%^SEE ALSO%^RESET%^

hp, score

");
}
