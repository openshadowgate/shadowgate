#include <std.h>
#include <daemons.h>
#include <levelcheck.h>

#define BUILDER      250
#define APPRENTICE   500
#define CREATOR      1000
#define DEVELOPER    1250
#define OVERSEER     1350
#define ELDER        1500
#define ARCH         1750
#define GOD          2000

inherit DAEMON;

string list_users(string *races, object tp);
int sort_by_level(object alpha, object beta);
int sort_by_login_time(object alpha, object beta);
mapping relmap;
object shape;


int cmd_who(string str)
{
    string *args, *races;
    //  mapping relmap;
    int i;

    races = ({});

    if (str)
    {
        i = sizeof(args = explode(str, " "));
        while (i--)
            if (RACE_D->is_race(args[i])) races += ({ args[i]});
    }
    this_player()->more(explode(list_users(races, TP), "\n"));
    return 1;
}


string race_color(object who)
{
    string tmp;

    tmp = "%^BOLD%^%^GREEN%^";
    return tmp;
}

string list_users(string *races, object tp)
{
    object *who, *wizzes, *rp_flags;
    mixed *deaths, *worldEvents;
    string mark, belphy, tmp, *person, melnmarn, title, rabbit, position;
    int i,j,maxj, max, x,length,inc,num,death_time;
    int gre;

    wizzes = filter_array(users(),"wizards",TO);
    who = users() + "/daemon/filters_d.c"->query_retired();
    who = filter_array(who, "which_users", this_object(), races);
    max = sizeof(wizzes+who);

    wizzes = sort_array(wizzes, "sort_by_level", this_object());
    who = sort_array(who, "sort_by_name", this_object());

    belphy = "%^GREEN%^--=%^BOLD%^< %^RESET%^%^WHITE%^There are "+max+" adventurers online!%^RESET%^%^GREEN%^%^BOLD%^ >%^RESET%^%^GREEN%^=--\n";

    who = wizzes +who;
    max = sizeof(who);


    if (max)
        for (i=0; i<max; i++)
        {
            position = who[i]->query_position();
            tmp = "";
            if (position == "Admin" ||
                position == "apprentice" ||
                position == "creator" ||
                position == "overseer" ||
                position == "elder" ||
                position == "arch")
                tmp += "%^BOLD%^%^BLACK%^Wizard %^BOLD%^%^BLACK%^----- ";
            else {
                if(((int)who[i]->query_login_time() + 60) > time())
                    rabbit = "someone";
                else if(objectp(shape = who[i]->query_property("shapeshifted")))
                    rabbit = (string)shape->query_shape_race();
                else rabbit=who[i]->query_race();

                if (ctime(time())[4..9]=="Apr  1") rabbit="%^WHITE%^rabbit";
                if (ctime(time())[4..9]=="Nov 23") rabbit="turkey";
                if (ctime(time())[4..9]=="May  1") rabbit="%^RED%^commie";
                if (ctime(time())[4..9]=="Oct 31") rabbit="%^ORANGE%^pumpkin";
                tmp += "%^MAGENTA%^"+ arrange_string(" "+ rabbit+"%^BOLD%^%^BLACK%^ ------------ ",12) +" ";
            }
            length = atoi(TP->getenv("SCREEN"))-32;
            if(!length||length<18)
                length=43;

            if ( wizardp(who[i]) && who[i]->query_quietness() ) {
                tmp += "%^BOLD%^%^CYAN%^Q %^RESET%^";
                length -=2;
            }

            if ( wizardp(who[i]) && who[i]->query_true_invis() && avatarp(tp) ) {
                tmp += "%^BOLD%^%^CYAN%^I %^RESET%^";
                length -=2;
            }

            if (in_edit(who[i]) || in_input(who[i])) {
                tmp += "%^BOLD%^**%^RESET%^ ";
                length -=3;
            }
            tmp += race_color(who[i]);
            if (!who[i]->query_alignment())
                melnmarn = capitalize((string)who[i]->query_name())+" the new adventurer";
            else if (((int)who[i]->query_login_time() + 60) > time() && (who[i]->query_level() < BUILDER)) {
                melnmarn = "is awakening";
            } else if ((string)who[i]->query_title())
                melnmarn = (string)who[i]->query_title();
            else
                melnmarn = "("+capitalize((string)who[i]->query_name())+")";
            if (in_edit(who[i]) || in_input(who[i]))
            {
                if (who[i]->query_invis());
                else if(who[i]->query_title())
                {
                    if (strlen((string)who[i]->query_title()) > length-4)
                        melnmarn = arrange_string(melnmarn,length-4);
                }
                else { continue; }
                melnmarn += "%^BOLD%^%^WHITE%^ **%^RESET%^";
            }
            melnmarn = arrange_string(melnmarn,length-1);
            tmp += melnmarn+" ";
            //
            if (who[i]->query_property("inactive"))
                tmp += "%^BOLD%^%^MAGENTA%^Inactive%^RESET%^";
            else if (interactive(who[i]) && query_idle(who[i]) > 60)
                tmp += "%^BOLD%^%^BLUE%^Idle "+sprintf("%3d",(query_idle(who[i]) / 60))+"%^RESET%^";
            else
                tmp += "%^RESET%^%^BLUE%^Active%^RESET%^  ";


            if (PRISON_D->is_imprisoned((string)who[i]->query_name()))
                tmp += "%^BOLD%^%^RED%^In Jail";
            else
                if(objectp(who[i]) && interactive(who[i]) && objectp(tp))
                {
                    tmp += LEVELCHECK->levelcheck_string(tp,who[i]);
                }
                else
                    tmp = arrange_string(tmp, 75);


            person = explode(tmp,"\n");
            maxj = sizeof(person);
            if (person) {
                tmp = person[0]+"\n";
                if (maxj>0)
                    for (j=1; j<maxj; j++) {
                        tmp += arrange_string("     "+race_color(who[i])+person[j],75);
                        tmp += "\n";
                    }
            }
            belphy += tmp;
        }
    rp_flags = "/daemon/user_d.c"->get_rp_flags();
    for(i = 0;i < sizeof(rp_flags);i++)
    {
        if(!objectp(rp_flags[i])) continue;
        tmp = "%^BOLD%^%^MAGENTA%^ RP Spear%^BOLD%^%^BLACK%^ -- " + rp_flags[i]->query_short();
        tmp += arrange_string(" ", (43 - strlen("/daemon/filters_d.c"->filter_colors(rp_flags[i]->query_short()))))+"\n";
        belphy += tmp;
    }
    if(pointerp(worldEvents = WORLD_EVENTS_D->parsable_world_events(tp)))
    {
        belphy+="%^GREEN%^--=%^BOLD%^< %^RESET%^%^ORANGE%^Active world events %^BOLD%^%^GREEN%^>%^RESET%^%^GREEN%^=--\n";
        foreach(tmp in worldEvents) { belphy += tmp +" event is currently active.\n"; continue; }
    }
    return belphy;
}

int wizards(object who)
{
    if ((avatarp(TP)) && (TP==who))
        return 1;
    if (!avatarp(who))
        return 0;
    if(wizardp(who) && who->query("true_quietness"))
        return 0;
    if (who->query_quietness()&&avatarp(who)&&(!avatarp(TP)))
        return 0;
    return 1;
}


int which_users(object who, string *races) {
    string my_race;
    int i;
    if (!who->query_name()) return 0;
    if (avatarp(who)) return 0;
    if (!(i=sizeof(races))) return 1;
    my_race = (string)who->query_race();
    while (i--) if (races[i] == my_race) return 1;
    return 0;
}


int new_logins(object who) {
    int logintime, oktime;
    logintime = (int)who->query_login_time();
    oktime = time() - 60;
    if((oktime < logintime) && !avatarp(TP) && (TP != who))
        return 0;
    return 1;
}


int sort_by_name(object alpha, object beta) {
    string name1,name2;
    if (wizardp(alpha) || wizardp(beta))
        return sort_by_level(alpha,beta);
    if ((((int)alpha->query_login_time() + 60) > time()) || (((int)beta->query_login_time() + 60) > time()))
    {
        if((int)alpha->query_login_time() != (int)beta->query_login_time())
        {
            return sort_by_login_time(alpha,beta); // to move all new logins to bottom of list by default
        }
    }
    if (((TP->isKnown(alpha->query_name()))
         && (TP->isKnown(beta->query_name()))) ||
        ((!TP->isKnown(alpha->query_name()))
         && (!TP->isKnown(beta->query_name())))) {
        if (avatarp(alpha) && alpha->query_disguised())
            name1 = alpha->query_vis_name();
        else if (TP->isKnown(alpha->query_name()))
            name1=TP->knownAs(alpha->query_true_name());
        //name1=relmap[(string)alpha->query_name()];
        else name1 = alpha->query_short();
        if (avatarp(beta) && beta->query_disguised())
            name2 = beta->query_vis_name();
        else if (TP->isKnown(beta->query_name()))
            name2=TP->knownAs(beta->query_true_name());
        //name2=relmap[(string)beta->query_name()];
        else name2 = beta->query_short();
//        write(identify(name1)); write(identify(name2));
        if(undefinedp(name1)) name1="";
        if(undefinedp(name2)) name2="";
        return strcmp(name1,name2);
    } else if (TP->isKnown(alpha->query_name())) return -1;
    else return 1;
}

int sort_by_level(object alpha, object beta) {
    int a, b;
    a = (int)alpha->query_level();
    b = (int)beta->query_level();
    if (a > b) return -1;
    if (b > a) return 1;
    a = wizardp(alpha);
    b = wizardp(beta);
    if ( (a && b) || (!a && !b) )
        return strcmp((string)alpha->query_name(), (string)beta->query_name());
    if (a) return 1;
    return -1;
}

int sort_by_login_time(object alpha, object beta) {
    int a, b;
    a = (int)alpha->query_login_time();
    b = (int)beta->query_login_time();
    if (a==b) return sort_by_name(alpha,beta);
    else if (a>b) return 1;
    else return -1;
}

string levelcheck_status(object tp, object other)
{
    int lvl,lvl2,low,diff,range, age;

    if(!objectp(tp))    { return ""; }
    if(!objectp(other)) { return ""; }

    if(tp == other) { return ""; }

    lvl = (int)tp->query_character_level();
    lvl2 = (int)other->query_character_level();

    if(lvl2 > lvl) { low = lvl; }
    else { low = lvl2; }

    diff = lvl - lvl2;
    diff = absolute_value(diff);

    switch(low)
    {
    case 1..29: range = 5; break;
    case 30..50: range = 10; break;
    default: return "";
    }

    if(diff > range) { return "   %^RESET%^%^BOLD%^%^RED%^F%^RESET%^"; }

    if(tp->query("no pk")) { return "   %^RESET%^%^BOLD%^%^YELLOW%^A%^RESET%^"; }
    if(other->query("no pk")) { return "   %^RESET%^%^BOLD%^%^YELLOW%^A%^RESET%^"; }

    if(tp->query_death_flag()) { return "   %^RESET%^%^BOLD%^%^YELLOW%^A%^RESET%^"; }
    if(other->query_death_flag()) { return "   %^RESET%^%^BOLD%^%^YELLOW%^A%^RESET%^"; }

    if(tp->get_pk_death_flag()) { return "   %^RESET%^%^BOLD%^%^YELLOW%^A%^RESET%^"; }
    if(other->get_pk_death_flag()) { return "   %^RESET%^%^BOLD%^%^YELLOW%^A%^RESET%^"; }

    return "   %^RESET%^%^BOLD%^%^GREEN%^K%^RESET%^";
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

who - show who is logged on

%^CYAN%^SYNOPSIS%^RESET%^

who [%^ULINE%^%^ORANGE%^RACE1%^RESET%^] [%^ULINE%^%^ORANGE%^RACE2%^RESET%^]...

%^CYAN%^DESCRIPTION%^RESET%^

Lists all players online.

If argument is provided, filters players by races.

%^CYAN%^PLAYER KILL FLAGS%^RESET%^

 %^RESET%^%^BOLD%^%^GREEN%^K%^RESET%^ in the end of the line indicates you're free to engage in player %^BOLD%^%^GREEN%^kill%^RESET%^ or adventures with that player.

 %^RESET%^%^BOLD%^%^YELLOW%^A%^RESET%^ means you're free to %^YELLOW%^adventure%^RESET%^ only and are forbidden to engage in player kill due to recent death or flag changes.

 %^RESET%^%^BOLD%^%^RED%^F%^RESET%^ means you're %^BOLD%^%^RED%^forbidden%^RESET%^ to adventure and engage in unrestricted player kill with the player due to difference in levels.

The difference in power is defined by the weakest character. To engage in adventures and PK the difference must be less than 5 levels for characters below level 30 and 10 levels for characters above.

%^CYAN%^SEE ALSO%^RESET%^

chfn, finger, mail, passwd, flag, pkilling, threaten, levelcheck, rules, notify

%^CYAN%^IMMORTALS%^RESET%^

quietness, invis
"
        );
}
