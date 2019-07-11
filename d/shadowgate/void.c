//recoded by Saide, May 2017 
//should use deep_inventory now, instead of all_inventory
//switched from heart beat to a call out, removed the init function entirely - handling players with the
//handle_player_object() function if a player happens to be inside the room when the call out happens. 

//I believe a lot of recent lag is related to the void having shit loads of objects inside of it, each with init functions, 
//likely calling each other 

#include <config.h>
#include <std.h>
#define PRISON_D ("/adm/daemon/prison_d")
#define JAIL ("/d/shadowgate/jail")
void check_my_inventory();
void clean_inventory();
inherit "/std/room";

void create() 
{
    ::create();
    set("short", "The void");
    set("long",
        "You have been assimilated.\n"
        "From this time on, you will service the Borg.");
    set_property("light", 1);
    call_out("check_my_inventory", 20);
    set_property("no teleport", 1);
    set_no_clean(1);
    return;
}

void handle_player_object(object ob)
{
    string start;
    if(!objectp(TO)) return;
    if(!objectp(ob) || !userp(ob)) return;
    if(PRISON_D->is_imprisoned(ob->query_true_name()))
    {
        ob->move_player(JAIL);
        return;
    }
    ob->set_property("voided", 1);
    if(stringp(start == ob->getenv("start")))
    {
        ob->move_player(start);
        return;
    }
    else
    {
        ob->move_player("/d/shadow/room/forest/road30");
        return;
    }
    return;
}

void clean_inventory()
{
    if(!objectp(TO)) return;
    foreach(object ob in deep_inventory(TO))
    {
        if(!objectp(ob)) continue;
        if(userp(ob))
        {
            handle_player_object(ob);
            continue;
        }
        ob->remove();
        if(objectp(ob)) destruct(ob);
        continue;
    }
    return;
}


void check_my_inventory()
{   
    if(!objectp(TO)) return;
    if(clonep(TO))
    {
        clean_inventory();
        reclaim_objects();
        TO->remove();        
        return;
    }
    clean_inventory();
    reclaim_objects();
    call_out("check_my_inventory", 20);
    return;
}
