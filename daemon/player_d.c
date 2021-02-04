/**
 * @file
 * @brief a daemon to keep track of player progress
 */

//      /adm/daemon/player_d.c
//      from the Nightmare Mudlib
//      a daemon to keep track of player progress
//      created by Descartes of Borg 10 july 1993

#include <objects.h>
#include <save.h>
#include <security.h>
#include <daemons.h>

string* monsters, * monsters2, * monsters3, * monsters4, * monsters5;

mapping* player_list;

void create()
{
    seteuid(getuid());
    monsters = ({});
    player_list = ({});
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_PLAYER_LIST);
    seteuid(getuid());
}

mapping* query_player_list()
{
    return player_list;
}

varargs void add_player_info(object ob)
{
    int exp, x;
    int i;

    if (!objectp(ob)) {
        if (!(ob = previous_object()) || !userp(ob)) {
            return;
        }
    }
    if (avatarp(ob)) {
        i = sizeof(player_list);
        while (i--) {
            if (player_list[i]["name"] == (string)ob->query_name() && avatarp(ob)) {
                player_list -= ({ player_list[i] });
            }
        }
        return;
    }
    x = -1;
    i = sizeof(player_list);
    while (i--) {
        if (player_list[i]["name"] == (string)ob->query_name()) {
            x = i;
        }
    }
    if ((sizeof(player_list) == 20) && (x == -1) &&
        (((int)ob->query_exp()) < player_list[19]["experience"])) {
        return;
    }
    if (x > -1) {
        player_list -= ({ player_list[x] });
    }
    if (!arrayp(player_list)) {
        player_list = ({});
    }

    player_list += ({ ([ "name" : (string)ob->query_name(), "experience" : (int)ob->query_exp(),
                         "kills" : sizeof((string*)ob->query_kills()),
                         "deaths" : sizeof((mixed*)ob->query_deaths()),
                         "quests" : sizeof((string*)ob->query_quests()),
                         "major accomplishments" : sizeof((mixed*)ob->query_mini_quests()),
                         "level" : (int)ob->query_level(),
                         "class" : (string)ob->query_class(),
                         "guild" : (string)ob->query_guild()
                       ]) });
    player_list = sort_array(player_list, "sort_list", this_object());
    if (sizeof(player_list) > 20) {
        player_list = player_list[0..19];
    }
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_PLAYER_LIST);
    seteuid(getuid());
}

int sort_list(mapping alpha, mapping beta)
{
    if (alpha["experience"] > beta["experience"]) {
        return -1;
    }else if (alpha["experience"] < beta["experience"]) {
        return 1;
    }else {
        return strcmp(alpha["name"], beta["name"]);
    }
}

int count_unique_monsters()
{
    int tmp, x;
    monsters -= ({ 0 });
    monsters2 -= ({ 0 });
    monsters3 -= ({ 0 });
    monsters4 -= ({ 0 });
    monsters5 -= ({ 0 });
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_PLAYER_LIST);
    seteuid(getuid());
    return (sizeof(monsters) + sizeof(monsters2) + sizeof(monsters3) + sizeof(monsters4) + sizeof(monsters5));
}

int add_kill(string str)
{
    int x;

    if (!monsters) {
        monsters = ({});
    }
    if (!monsters2) {
        monsters2 = ({});
    }
    if (!monsters3) {
        monsters3 = ({});
    }
    if (!monsters4) {
        monsters4 = ({});
    }
    if (!monsters5) {
        monsters5 = ({});
    }

    if ((x = member_array(str, monsters)) == -1) {
        if ((x = member_array(str, monsters2)) == -1) {
            if ((x = member_array(str, monsters3)) == -1) {
                if ((x = member_array(str, monsters4)) == -1) {
                    if ((x = member_array(str, monsters5)) == -1) {
                        monsters5 += ({ str });
                        x = member_array(str, monsters5);
                        seteuid(UID_DAEMONSAVE);
                        save_object(SAVE_PLAYER_LIST);
                        seteuid(getuid());
                    }
                    x += 15000;
                }
                x += 15000;
            }
            x += 15000;
        }
        x += 15000;
    }
    return x;
}

string query_monster(int x)
{
    if (x <= sizeof(monsters)) {
        if (!monsters[x]) {
            return "unknown";
        }else {
            return monsters[x];
        }
    }else if (x - 15000 <= sizeof(monsters2)) {
        x = x - 15000;
        if (!monsters2[x]) {
            return "unknown";
        }else {
            return monsters2[x];
        }
    }else if (x - 30000 <= sizeof(monsters3)) {
        x = x - 30000;
        if (!monsters3[x]) {
            return "unknown";
        }else {
            return monsters3[x];
        }
    }else if (x - 45000 <= sizeof(monsters4)) {
        x = x - 45000;
        if (!monsters4[x]) {
            return "unknown";
        }else {
            return monsters4[x];
        }
    }else if (x - 60000 <= sizeof(monsters5)) {
        x = x - 60000;
        if (!monsters5[x]) {
            return "unknown";
        }else {
            return monsters5[x];
        }
    }
    return "unknown";
}

void remove_player(int i)
{
    mapping tmp;
    player_list[i]["experience"] = 0;
    player_list -= ({ player_list[i] });
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_PLAYER_LIST);
    seteuid(getuid());
}

int sizeof_monsters()
{
    return sizeof(monsters4);
}
