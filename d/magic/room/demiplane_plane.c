#include <std.h>
#include <magic.h>

inherit ROOM;

object entry, rope;
string roomName;
string castname;

mapping extraitems=([]);

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
   add_action("set_plane_property", "set");
   add_action("set_plane_feature", "feature");
}

int set_plane_feature(string str)
{
    string tmp, cargs;
    if(!regexp(str,"^[add|remove|list|clear]"))
        return 0;

    if(regexp(str,"^add"))
    {
        if(sscanf(str,"add %s as %s",cargs,tmp)!=2)
        {
            write("You must provide feature name and its description.");
            return 1;
        }
        extraitems+=([cargs:tmp]);
        restore_items();
        save_space();
        write("Feature "+cargs+" added as: "+tmp);
    }

    if(regexp(str,"^remove"))
    {
        if(sscanf(str,"add %s",cargs)!=1)
        {
            write("You must provide feature name.");
            return 1;
        }
        map_delete(extraitems,cargs);
        restore_items();
        save_space();
        write("Feature "+cargs+" removed.");
    }

    if(regexp(str,"^list"))
    {
        string item;
        write("%^BOLD%^%^RED%^There are next features present:");
        foreach(item in keys(extraitems))
        {
            write(item);
        }
    }

    if(regexp(str,"^clear"))
    {
        extraitems=([]);
        restore_items();
        save_space();
        write("All features were removed");
    }
}

int set_plane_property(string str)
{
    string tmp, cargs;
    if(!regexp(str,"^plane [long|short|smell]"))
        return 0;
    if(regexp(str,"^plane long"))
    {
        if(sscanf(str,"plane long %s",cargs)!=1)
        {
            write("You must provide description");
            return 1;
        }
        TO->set_long(query_short()+"\n"+cargs+"\n");
        save_space();
        TP->force_me("look");
    }

    if(regexp(str,"^plane short"))
    {
        if(sscanf(str,"plane short %s",cargs)!=1)
        {
            write("You must provide description");
            return 1;
        }
        TO->set_short(cargs);
        TO->set_long(cargs+"\n"+TO->query_long());
        save_space();
        TP->force_me("look");
    }

    if(regexp(str,"^plane smell"))
    {
        if(sscanf(str,"plane smell %s",cargs)!=1)
        {
            write("You must provide description");
            return 1;
        }
        TO->set_smell("default",cargs);
        save_space();
        TP->force_me("look");
    }

    if(regexp(str,"^plane listen"))
    {
        if(sscanf(str,"plane listen %s",cargs)!=1)
        {
            write("You must provide description");
            return 1;
        }
        TO->set_listen("default",cargs);
        save_space();
        TP->force_me("look");
    }

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

   tell_room(TO, "%^ORANGE%^"+TPQCN+" locks the door and it disappears.",TP);
   tell_object(TP, "%^ORANGE%^You lock the door and it disappears.");
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
    restore_items();
}

void restore_items()
{
    string item;
    TO->set_items(([]));
    if(sizeof(extraitems))
        foreach(item in keys(extraitems))
        {
            add_item(item,extraitems[item]);
        }
}

void vape_items()
{
    extraitems = ([]);
    restore_items();
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
