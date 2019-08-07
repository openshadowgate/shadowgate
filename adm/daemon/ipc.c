#include <std.h>
#include <socket.h>
#include <daemons.h>

inherit DAEMON;

static string *valid_mtype = ({"chanmsg"});

void create()
{
    ::create();
    seteuid(getuid());    
}

