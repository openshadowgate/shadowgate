#include <std.h>
#include <daemons.h>

/**
 * @file
 * @brief Thid daemon manages soft lock notifications
 */

#define SAVEF "/daemon/save/softlock_d"

inherit DAEMON;

mapping locks;

void create()
{
    seteuid(getuid());
    restore_object(SAVEF);
    if(!sizeof(locks))
        locks = ([]);
}

void add_lock(string desc, int duration)
{
    mixed * item;
    string who = TP->query_name();
    int timekey = time();
    if(!who)
        return;

    item = allocate(3);
    item = ({who, desc, duration});
    locks += ([timekey:item]);

    notify_wizzes("%^BOLD%^%^ORANGE%^"+who+"%^WHITE%^ added pledge lock on %^BOLD%^%^GREEN%^"+locks[timekey][1]+"%^WHITE%^.
It should expire in %^ORANGE%^"+parse_time(locks[timekey][2])+"%^RESET%^");
    save_object(SAVEF);
}

void expire_locks()
{
    int timekey;
    int now = time();

    foreach(timekey in keys(locks))
        if(timekey+locks[timekey][2]<now)
            map_delete(locks,timekey);

    save_object(SAVEF);
}

void remove_lock(int timekey)
{
    string who = TP->query_name();
    if(!who)
        return;
    if(member_array(timekey,keys(locks))==-1)
        return;

    notify_wizzes("%^BOLD%^%^ORANGE%^"+who+"%^WHITE%^ removed pledge lock on %^BOLD%^%^GREEN%^"+sprintf("%.26s",locks[timekey][1])+"%^WHITE%^.
It should have expired in %^ORANGE%^"+parse_time(time()-timekey-locks[timekey][2])+"%^RESET%^");
    map_delete(locks,timekey);
    save_object(SAVEF);
}

mapping query_locks()
{
    expire_locks();
    return locks;
}

void notify_wizzes(string message)
{
    object * peeps = filter_array(users(),(:avatarp($1):));
    object peep;
    foreach(peep in peeps)
        tell_object(peep, message);
}
