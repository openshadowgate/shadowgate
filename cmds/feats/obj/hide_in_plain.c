#include <std.h>

inherit OBJECT;
object current_room;

string name;
object player;
void set_player_name(string str);
void dest_fun();
int force_cancel();

void set_player(object obj)
{
    player = obj;
}

void set_room(object rm) { if (objectp(rm)) current_room = rm; }

object query_player() { return player; }

void create()
{
    int score;
    ::create();
    set_id("hideobj","TSR80");
    set_name("hideobj");
    set_weight(0);
    set_property("no animate",1);
    set_property("no detect",1);
    name = "-1";
    set_heart_beat(1);
    set_no_clean(1);
}


void heart_beat()
{
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    return;
}

void init()
{
    ::init();
    if(objectp(player))
        current_room=environment(player);
    call_out("test_invis",5);
    add_action("force_cancel","step");  // changed to use force_cancel()
}

int cancel_inv()
{
    if(!objectp(player))
    {
        dest_fun();
        return 0;
    }
    if(player->query_hidden()) { player->set_hidden(0); }
    call_out("dest_fun",1);
    return 0;
}

int force_cancel()
{
  cancel_inv();
  return 1;
}

void dest_fun()
{
    if(objectp(player))
    {
        if(player->query_hidden()) { player->set_hidden(0); }
    }
    remove_call_out("test_invis");
    ::remove();
}

void test_invis()
{
    int percent;
    int score;

    if(!objectp(player)) { return; }

    if(player->query_in_vehicle() && objectp(player->query_in_vehicle()))
    {
        cancel_inv();
        return;
    }

    if (!player->query_hidden())
    {
        call_out("dest_fun",1);
        return 1;
    }
   call_out("test_invis",2);
}

int save_me(string file) {return 0;}

int remove() {
  object temp;
  temp = find_object_or_load("/cmds/mortal/_sneak.c");
  if (PO != temp)
    log_file("reports/hide","PO: "+identify(PO)+". At: "+ctime(time())+".\n");
    dest_fun();
    ::remove();
}
void internal_remove() { ::remove(); }
