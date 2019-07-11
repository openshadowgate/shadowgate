//      Intermud communications blocker (iblock)
//      Thorn@Shadowgate
//      12/16/94
//      Admin Commands
//      _iblock.c

#include <security.h>
#include <daemons.h>
#include <std.h>

void bad_user(string str) {
        string who, where;
        if(!str) {
                notify_fail("'"+str+"' is not a correct argument."+
                "  Correct: iblock user <user@mudname>.\n");
                return 0;
}
        if(sscanf(str, "%s@%s", who, where) != 2) {
                notify_fail("'"+str+"' is not a correct argument.  "+
                "Correct: iblock user <user@mudname>.\n");
                return 0;
        }
        seteuid(UID_ROOT);
        SCREEN_D->set_bad_user(lower_case(who), lower_case(where));
        seteuid(getuid());
        write("ScreenDaemon reports iblock enabled on USER "+capitalize(str)+
        " successfully.\nUse unblock [user/mud] <name of mud or user> to disable.\n");
        return 1;
}

void bad_mud(string str) {
        string where;
        if(sscanf(str, "@%s", where) != 1 || !str) {
                notify_fail("'"+str+"' is not a correct argument.  Correct: iblock mud <@mudname>.\n");
                return 0;
        }
        seteuid(UID_ROOT);
        SCREEN_D->set_bad_mud(lower_case(where));
        seteuid(getuid());
        write("ScreenDaemon reports iblock enabled on MUD "+capitalize(str)+
        "successfully.\nUse unblock [user/mud] <name of mud or user> to disable.\n");
        return 1;
}

int cmd_iblock(string str) {
        string what, who;
        seteuid(getuid());
        if(!str) return 0;
        if(!archp(this_player())) return 0;
        if(sscanf(str, "%s %s", what, who) != 2) {
                notify_fail("iblock [user/mud] <name of user or mud>.\n");
                return 0;
        }
        if(what == "user") {
                bad_user(who);
                if((string)this_player()->query_position() != "god")
				    log_file("intermud", "Iblock enabled on "+who+" at "+ctime(time())+
				    " by "+TPQCN+".\n");
                return 1;
        }
        if(what == "mud") {
                bad_mud(who);
                if((string)this_player()->query_position() != "god")
				    log_file("intermud", "Iblock enabled on "+who+" at "+ctime(time())+
				    " by "+TPQCN+".\n");
                return 1;
        }
        notify_fail("iblock [user/mud] <name of user or mud>.\n");
        return 0;
}


help() {
        write(
@HELP

Usage: iblock user user@mudname
       iblock mud @mudname

        This command sets the intermud screening daemon to block out intermud
tells and (eventually) other things.  This command can block specific users
or whole MUDs by using the args "mud" or "user" after the command.
        In all cases the name of the MUD needs to be proceeded by a "@" in order
for the command to work correctly.  For instance, "iblock mud @BigMUD" will
work, but "iblock mud MUD of Doom" will not work.

See also: unblock, whoiblocked

HELP
        );
}


