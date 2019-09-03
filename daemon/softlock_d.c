#include <std.h>
#include <daemons.h>

/**
 * @file
 * @brief Thid daemon manages soft lock notifications
 */

#define SAVEF "/daemon/save/softlock_d"

inherit DAEMON;

mixed *locks;

void create()
{
    seteuid(getuid());
    restore_object(SAVEF);
}

void add_lock(string desc, int duration)
{
    locks += ({desc, duration});
}

mixed * query_locks()
{
    return locks;
}
