#include <std.h>

#define YUCK_D "/daemon/yuck_d.c"

int cmd_recover(string str)
{
    object player;
    if(!userp(TP)) { return 1; }  
    if (!TP->query_property("voided"))
    {
        tell_object(TP, "You cannot use the recover command, because you"
          +" do not appear to have suffered from a known type of gear loss"
          +" bug. If you do need your gear restored for some other reason,"
          +" you will need to contact an Imm. Remember not to remain logged"
          +" in for 10 minutes or more at a stretch in between times.");
        return 1;
    }  
    tell_object(TP, "The recover command is an OOC facility intended to allow"
      +" you to restore your gear if you lose it due to a bug. Using it for"
      +" any other purpose is cheating. Are you sure you want to go ahead?"
      +" Type %^BOLD%^yes%^RESET%^ to continue, or anything else to abort");
    input_to("confirm_restore");
    return 1;
}


int confirm_restore(string str){    
    if (lower_case(str)!="yes")
    {
        tell_object ("Recovery abandoned. %^BOLD%^%^RED%^Note - if you have"
                     +" lost your gear to a bug, be sure to recover your gear within"
                     +" ten minutes of logging in. Otherwise, it may be lost completely.");
        return 1;
    }
    if(!get_dir("/inv/backup_inv/"+TPQN[0..0]+"/"+TPQN+"/"))
    {
        tell_object(TP,"Sorry, no backup currently exists for you.");
        return 1;
    }
    tell_object(TP,"Attempting to restore your inventory...");
    YUCK_D->load_inventory(TP,"/inv/backup_inv/"+TPQN[0..0]
                           +"/"+TPQN);
    tell_object(TP,"Inventory restored.");
    "/cmds/avatar/_note.c"->cmd_note("add "+ TPQN + " " + ctime(time()) + ": %^BOLD%^%^RED%^" + TPQN + " used the RECOVER command to restore " + TP->QP + " gear");
    TP->remove_property("voided");
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

recover - recover inventory

%^CYAN%^DESCRIPTION%^RESET%^

This command will attempt to restore your inventory from the most recent backup. It will only work if you have suffered gear loss due to a bug which lead to you seeing the message that you have been assimilated by the Borg, and only if you have not disconnected or logged out since that bug. If you are not able to restore your gear with this command, it may be worth trying to contact an Imm to see if we can do it.

%^CYAN%^SEE ALSO%^RESET%^

avatarmail, line use, tell, communication, thought, game
");
}

