#include <std.h>
#include <socket.h>
#include <daemons.h>

inherit DAEMON;

nosave string *valid_mtype = ({"chanmsg"});

void create()
{
    ::create();
    seteuid(getuid());
}
