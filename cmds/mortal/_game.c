//Consolidation of the previus bug, typo, praise, and idea commands - Saide, January 2nd 2017
//The idea being to cut down on redundant code/commands that players have available - simplification :-)

#include <std.h>
#include <dirs.h>
#include <security.h>
#define VALID_ARGS ({"bug", "typo", "idea"})
#define TLOG (["bug" : "bugs", "typo" : "typos", "idea" : "ideas"])
inherit DAEMON;

void do_post(string arg, string mtitle);
string file, title, varg;

string notify_valid()
{
    string ret;
    ret = implode(VALID_ARGS[0..sizeof(VALID_ARGS)-2], ", ");
    ret += " and "+VALID_ARGS[sizeof(VALID_ARGS)-1];
    return ret;
}

string get_board()
{
    if(!stringp(varg)) return "bugboard";
    switch(varg)
    {
        case "bug":
            return "bugboard";
            break;
        case "typo":
            return "typoboard";
            break;
        case "idea":
            return "ideasboard";
            break;
    }
    return "bugboard";
}

int cmd_game(string str)
{
    string arg, mtitle;
    if(!str)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^Please specify the type of report that you want "+
        "to make. Valid options are "+notify_valid()+".%^RESET%^");
        return 1;
    }
    if(sscanf(str, "%s %s", arg, mtitle) != 2)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^Please specify the type of report that you want "+
        "to make, as well as a target object or title for the report.%^RESET%^");
        return 1;
    }
    if(member_array(arg, VALID_ARGS) == -1)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^That is not a valid type of report. Currently "+
        "supported options are "+notify_valid()+".%^RESET%^");
        return 1;
    }
    if(strlen(mtitle) > 72)
    {
       tell_object(TP, "Please be more brief on the title, less than 72 characters.\n  You can elaborate in the editor.\n");
       return 1;
    }
    do_post(arg, mtitle);
    return 1;
}

void do_post(string arg, string mtitle)
{
    string trash;
    object ob;
    if(!stringp(arg))
    {
        tell_object(TP, "Something went wrong.");
        return 1;
    }
    varg = arg;
    switch(arg)
    {
        case "bug":
            write("You are about to post to a board for the wizzes saying there is a "
            "bug related to %^BOLD%^%^YELLOW%^"+mtitle+"%^RESET%^.  If you "
            "specified 'here', it will report the specific room you are "
            "in.  Some things may be flukes or be difficult "
            "to track down and eradicate, but we do look into each report and "
            "try.  %^BOLD%^Please type in your message below.%^RESET%^  Any "
            "details you can provide about what was wrong, "
            "including a copy/paste or details of events just before the "
            "error are usually helpful.\n");
            break;
        case "typo":
            write("You are about to post to a board for the immortals saying there is a "
            "typo related to %^BOLD%^%^YELLOW%^"+mtitle+"%^RESET%^.  If you "
            "specified 'here', it will report the specific room you are "
            "in.  %^BOLD%^Please type in your message below.  "
            "%^RESET%^Feel free to copy/paste the relevant text from your screen "
            "and please indicate the corrections needed.\n");
            break;
        case "idea":
            write("You are about to post an idea to a board for the immortals to see. "+
            "Please note that all ideas are considered, regardless of where or who "+
            "they originate from. Also know that they may take time as the staff "+
            "continues to work on improving the game and you may or may not receive "+
            "a response.\n");
            break;
    }
    if(mtitle == "here")
    {
        file = base_name(ETP);
        title = file;
    }
    else if(ob = present(mtitle,TP) || ob = present(mtitle, ETP) )
    {
        file = base_name(ob);
        title = file;
    }
    if(!file)
    {
        title = mtitle;
        file = base_name(ETP);
    }
    rm(DIR_TMP+"/"+geteuid(previous_object())+"."+varg);
    previous_object()->edit(DIR_TMP+"/"+geteuid(previous_object())+"."+varg,
    "end_edit", TO);
}

end_edit()
{
    string *lines;
    string tmpfile;
    tmpfile = file+":\n"+read_file(DIR_TMP+"/"+geteuid(TP)+"."+varg);
    lines = explode(wrap(tmpfile, 72), "\n");
    rm("/tmp/"+TPQN+"."+varg);
    report(lines);
}

report(string *lines)
{
    string who, trash, *elements, rep, mlog;
    int x;
    string message;

    elements = explode(file, "/");
    if(elements[0] == "realms") who = elements[1];
    else if(elements[0] == "d") who = elements[1];
    else who = 0;
    switch(varg)
    {
        case "bug": case "typo": case "idea":
            rep = capitalize(varg) + " reported by "+capitalize(TPQN)+" " +ctime(time())+":\n";
            break;
    }
    mlog = TLOG[varg];
    seteuid(UID_LOG);
    log_file(mlog, rep);
    if(who) log_file("reports/"+who, rep);
    x = -1;
    while(++x < sizeof(lines))
    {
        log_file(mlog, lines[x]+"\n");
        if(who) log_file("reports/"+who, lines[x]+"\n");
    }
    message = lines[0]+"\n";
    x=0;
    while(++x < sizeof(lines))
    {
        message += lines[x]+"\n";
    }
    message = message + "\nReported from location "+base_name(ETP)+"\non "+ctime(time())+" related to %^BOLD%^"
    +file+"%^RESET%^.\n\n";
    //  title = file;
    if (strlen(title) > 30)
    {
        while(strlen(title) > 29)
            sscanf(title, "%s/%s", trash, title);
        title = "~" + title;
    }
    seteuid(UID_CRESAVE);
    "/adm/daemon/bboard_d.c"->direct_post(get_board(),capitalize(TPQN),title,message);
    seteuid(getuid());
    file = 0;
    write(capitalize(varg)+" reported!  Thank you!\n");
    return 1;
}

void abort()
{
    notify_fail(capitalize(varg)+" report aborted.\n");
    rm("/tmp/"+TPQN+"."+varg);
    file = 0;
    return 0;
}

int help()
{
    write(
"
%^CYAN%^NAME%^RESET%^

game - help the game

%^CYAN%^SYNTAX%^RESET%^

game bug here|%^ORANGE%^%^ULINE%^TARGET%^RESET%^|%^ORANGE%^%^ULINE%^DESCRIPTION%^RESET%^
game typo here|%^ORANGE%^%^ULINE%^TARGET%^RESET%^|%^ORANGE%^%^ULINE%^DESCRIPTION%^RESET%^
game idea here|%^ORANGE%^%^ULINE%^TARGET%^RESET%^|%^ORANGE%^%^ULINE%^DESCRIPTION%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command lets you report a bug, typo, an idea. If you are using the bug version of the command please ask for a wiz and state that you want to report a bug with a brief description of the problem before reporting it. A player or immortal may know if it's not a bug or it may help a wiz be able to get important information before time passes.

All versions of the command work with a %^ORANGE%^%^ULINE%^TARGET%^RESET%^, so if you can look at something with the target id then using this command will report that id (in order to help immortals know exactly what item you are referencing).

Using 'here' will report the room that you are currently in.

You can also enter a %^ORANGE%^%^ULINE%^DESCRIPTION%^RESET%^, for example, if a bug is not directly related to an object or the room that you are in. When using a description please be concise, you may elaborate within the editor for the command.

%^CYAN%^SEE ALSO%^RESET%^

fixmore, fixroom, feats, fixspells, bboard, line use, help
");
    return 1;
}
