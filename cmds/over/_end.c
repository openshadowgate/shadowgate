#include <std.h>
#include <security.h>
#include <objects.h>
#include <rooms.h>
#include <daemons.h>

inherit DAEMON;

int cmd_end(string str)
{
    object ob;
    int ShutdownTime;

    if (!stringp(str)) {
        return notify_fail("Please enter a number of minutes to count down.");
    }

    if (str == "cancel") {
        SHUT_D->cancel_shutdown();
        return 1;
    }


    if (!sscanf(str, "%d", ShutdownTime)) {
        write("Invalid parameter");
    }
    if (this_player()->query_forced()) {
        return 0;
    }

    seteuid(UID_SHUTDOWN);

    if (!ShutdownTime) {
        catch(call_other(SHUT_D, "start_shutdown", 4, 10));
    }else {
        catch(call_other(SHUT_D, "start_shutdown", 4, ShutdownTime));
    }
    seteuid(getuid());
    write("Ok.\n");
    log_file("adm/shutdown", "Manual Shutdown initiated by " +
             (this_player()->query_name()) + ": " + ctime(time()) + "\n");
    return 1;
}

int help()
{
    write(
"
%^CYAN%^NAME%^RESET%^

end - end the game

%^CYAN%^SYNTAX%^RESET%^

end [%^ORANGE%^%^ULINE%^TIME%^RESET%^|cancel]

%^CYAN%^DESCRIPTION%^RESET%^

This will turn the driver off in TIME minutes, or will cancel shutdown.

%^CYAN%^SEE ALSO%^RESET%^

shudown()
"
        );
    return 1;
}
