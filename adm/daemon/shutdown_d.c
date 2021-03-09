//  Shutdown Daemon for ShadowGate v2.0
//  Thorn@ShadowGate
//  950506
//  /adm/daemon/shutdown_d.c

#include <std.h>
#include <objects.h>
#include <security.h>

// Now MAX_MEMORY is messured in Megs - Firedragon 12/7/2004
#define MAX_MEMORY 10240
#define DEFAULT_WARNING_TIME 20
#define PLANNED_TIME 60
#define TEST_INTERVAL 3
#define LAG_MINUTES 3

#define TEST 0
#define STANDARD 1
#define PLANNED 2
#define MANUAL 4
#define EMERGENCY 5
#define OTHER 6

inherit DAEMON;

object* queue;
int time_left, armShutdown, loginAllow;
int shutting_down, time_estimate;

create()
{
    ::create();
    shutting_down = 0;
    seteuid(UID_SHUTDOWN);
    queue = ({ });
    time_left = -1;
    loginAllow = 1;
    armShutdown = 0;
    time_estimate = time() + (TEST_INTERVAL * 60) + (LAG_MINUTES * 60);
    call_out("check_planned", 45);
    return 1;
}

int shutting_down()
{
    return shutting_down;
}

int notify_users(string msg)
{
    message("broadcast", "%^RED%^[%^BOLD%^shutdown%^RESET%^%^RED%^] %^ORANGE%^" + msg, users());
    return 1;
}

int start_shutdown(int type, int time)
{
    remove_call_out("count_down");
    if (geteuid(TO) != UID_SHUTDOWN) {
        return 0;
    }
    if (type != TEST) {
        shutting_down = 1;
    }
    switch (type) {
    case TEST:
        if (time < 1) {
            break;
        }
        time_left = time * 60;
        notify_users("Testing Shutdown Daemon (no shutdown will occur)");
        notify_users("Reboot in " + time + " minutes!");
        count_down();
        return TEST;
        break;
    case STANDARD:
        time_left = DEFAULT_WARNING_TIME * 60;
        notify_users("Regularly Scheduled Reboot Starting....");
        enable_shutdown();
        count_down();
        return STANDARD;
        break;
    case PLANNED:
        time_left = PLANNED_TIME * 60;
        notify_users("Pending planned automatic shutdown..");
        enable_shutdown();
        count_down();
        return PLANNED;
        break;
    case MANUAL:
        if (time < 1) {
            break;
        }
        time_left = time * 60;
        notify_users("Manual Reboot....");
        enable_shutdown();
        count_down();
        return MANUAL;
        break;
    case EMERGENCY:
        time_left = 60;
        notify_users("%^BOLD%^***Emergency Reboot***%^RESET%^");
        notify_users("Saving Players and Rebooting Immediately.");
        enable_shutdown();
        executeShutdown();
        return EMERGENCY;
        break;
    case OTHER:
        time_left = 60;
        notify_users("%^BOLD%^***Emergency Reboot***%^RESET%^");
        notify_users("Saving Players and Rebooting Immediately.");
        enable_shutdown();
        executeShutdown();
        return OTHER;
        break;
    }
    return 0;
}

int count_down()
{
    if (!time_left) {
        executeShutdown();
        return 2;
    }
    if (time_left < 11) {
        notify_users("Attention: Shutdown in 10 seconds!  Final Warning!\n");
        time_left = 0;
        call_out("count_down", 10);
        return 1;
    }
    if (time_left < 121 && time_left > 61) {
        notify_users("Attention: Shutdown in two minutes!\n");
        time_left -= 60;
        call_out("count_down", 60);
        return 1;
    }
    if (time_left < 61) {
        notify_users("Attention: Shutdown in one minute!\n");
        time_left -= 50;
        call_out("count_down", 50);
        return 1;
    }
    if (time_left > 3600) {
        notify_users("Attention: Shutdown in " + parse_time(time_left) + "\n");
        time_left -= 1200;
        call_out("count_down", 1200);
        return 1;
    }
    if (time_left > 600) {
        notify_users("Attention: Shutdown in " + parse_time(time_left) + "\n");
        time_left -= 600;
        call_out("count_down", 600);
        return 1;
    }

    notify_users("Attention: Shutdown in " + time_left / 60 + " minutes.\n");

    time_left -= 60;
    call_out("count_down", 60);
    return 1;
}

int executeShutdown()
{
    int all, x;
    object imm;

    if (!armShutdown) {
        return notify_users("Shutdown will not be executed.\n");
    }
    queue = users();
    loginAllow = 0;
    all = sizeof(queue);
    for (x = 0; x < all; x++) {
        queue[x]->toggle_quit(0);
    }
    notify_users("Shutting down within moments. Be back in a few minutes!\n");
    notify_users("Quit has been disabled for all remaining players.\n");

    for (x = 0; x < all; x++) {
        imm = queue[x];
        if (!imm) {
            notify_users("Error in reboot! (executeShutdown)\n");
            return 0;
            break;
        }
        imm->toggle_quit(1);
        imm->quit();
    }
    shutdown();
    return 1;
}

int check_planned()
{
    if (regexp(ctime(time()), " 07:00") && time_left < 0) {
        start_shutdown(PLANNED, 60);
    }
    call_out("check_planned", 45);
}

int enable_shutdown()
{
    if (armShutdown) {
        return -1;
    }
    armShutdown = 1;
    return 1;
}

int disable_shutdown()
{
    if (!armShutdown) {
        return -1;
    }
    armShutdown = 0;
    return 1;
}

protected void cancel_it()
{
    cancel_shutdown();
    return;
}

int cancel_shutdown()
{
    disable_shutdown();
    remove_call_out("count_down");
    if (time_left <= 10) {
        remove_call_out("executeShutdown");
    }
    notify_users("Attention: Shutdown cancelled. No reboot will occur.\n");
    time_left = 0;
    shutting_down = 0;
    return 1;
}

void do_armageddon(int tmp)
{
    start_shutdown(MANUAL, tmp);
    return;
}

int query_login_allow()
{
    return loginAllow;
}

int clean_up()
{
    return 0;
}

int query_time_left()
{
    return time_left;
}
