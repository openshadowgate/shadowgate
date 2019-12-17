#include <std.h>
#include <magic.h>

inherit ROOM;

object entry, rope;
string roomName;
string castname;

mapping extraitems;

void create() {
   ::create();
   set_light(1);
   set_property("indoors", 1);
   set_short("%^BOLD%^%^BLUE%^a small demiplane%^RESET%^");
   set_short("%^CYAN%^Nowhere%^RESET%^");
   set_long(
       "%^CYAN%^Nowhere
%^CYAN%^You stand in the middle of nothing, surrounded by a white haze.
"
   );

   set_property("no teleport",1);

}

void init() {
   ::init();
   add_action("pull_up_rope", "close");
   add_action("lower_rope", "open");
   add_action("command_space", "command");
}

int command_space(string str)
{
    string tmp, command;
    if(!regexp("^space ",str))
        return 0;
    if(TP!=caster)
        return 0;
    if(sscanf(str,"%s %s",tmp, command)!=2)
        return 0;
    return 1;
}

void set_entry(object ob, object rp, string where)
{
  entry = ob;
  rope = rp;
  roomName = where;
}

void set_castname(string str)
{
    castname = str;
}

int pull_up_rope(string str)
{
   object *inv;
   int x;

   if(str != "door")
       return 0;
   inv = all_inventory(TO);

   tell_room(TO, TPQCN+" locks the door, making this demiplane inaccessible.",TP);
   tell_object(TP, "You lock the door, making this demiplane inaccessible from outside.");
   rope->raise();
   TO->remove_exit("door");
   return 1;
}

int lower_rope(string str)
{
   if(str != "door")
       return 0;
   tell_room(TO, "%^ORANGE%^An old door reappears.",TP);
   tell_object(TP,"%^ORANGE%^You summon the door to material plane.");
   rope->lower();
   if(!objectp(entry))
	entry = find_object_or_load(roomName);
   TO->add_exit(base_name(entry), "door");
   return 1;
}

void save_space()
{
    mkdir("/d/save/summons/"+castname);
    save_object("/d/save/summons/"+castname+"/demiplane");
}

void restore_space()
{
    if(file_exists("/d/save/summons/"+castname+"/demiplane.o"))
    {
        restore_object("/d/save/summons/"+castname+"/demiplane.o");
    }
}

void destroy_space() {
   object *inv;
   int x;

   inv = all_inventory(TO);
   if(!objectp(entry))
       entry = find_object_or_load(roomName);
   tell_room(TO,"%^ORANGE%^Everything arround you disappears and you appear somewhere else.");

   save_space();

   for(x=0;x<sizeof(inv);x++)
       inv[x]->move(entry);
   "/daemon/virtual_room_d.c"->destroy_virtual_room(TO->query("my_virtual_name"), entry);
   TO->remove();
}
