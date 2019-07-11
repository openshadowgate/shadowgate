/*====================================================================
// file: find_object_or_load.c
// Author either Huthar or Wayfarer
// Thanks to the folks at Portals for this one.
// Now a part of the distribution mudlib.
// Purpose: To either find the object with the matching file,
// and return it, or to load it, then return it.
   Updated December, 2016 by Saide 
   I've removed the reset call on create, in Object.c 
   I've added a room reset to this efun and I've removed
   the call to place_mobs in /std/random_monsters.c and used this efun to 
   accomplish the same thing. My sincerest hope is that by doing 
   so, by essentially splitting create, reset, and mob placement, 
   that we can eliminate the too deep recursion bugs that sometimes happen
   when a room is loaded 
   If anyone changes anything with this efun, keep this in mind. ** Saide **
=====================================================================*/
#include <security.h>
#include <daemons.h> 

object find_object_or_load (mixed str)
{
    object ob, ns;
    string err;
    
    if(objectp(str)) 
    { 
        if(!str->is_room()) return str;
        ns = ALT_WORLD_D->find_alt(str);
        if(objectp(ns)) str = ns;
        if(!str->query_reset_number()) { str->reset(); }
        if(!str->is_control_room()) return str;
        if((int)str->query_reset_number() != (int)str->query_property("lastresetmobs")) { str->place_mobs(); }  
        return str; 
    }
    ob = find_object(str);
    if (ob != 0)
    {
        if(!objectp(ob)) return ob;       
        if(!ob->is_room()) return ob;
        if(!ob->query_reset_number()) { ob->reset(); }
        ns = ALT_WORLD_D->find_alt(str, ob->query("alternative world"));
        if(objectp(ns)) ob = ns;
        if(!ob->is_control_room()) return ob;        
        if((int)ob->query_reset_number() != (int)ob->query_property("lastresetmobs")) { ob->place_mobs(); }       
        if(clonep(ob)) return ob;
        return ob;
    }
    seteuid(UID_ROOT);
    if(!file_exists(str)) { err = catch(call_other(str, "???")); }
    else if(!file_exists(str + ".c")) { err = catch(call_other(str, "???")); }
    else call_other(str,"???");
    if(err) { log_file("debug.log", "**ERROR: "+err+" -- when trying find_object_or_load(\""+str+"\""); }
    //seteuid(0);
    ob = find_object(str);
    if(!objectp(ob)) return ob;  
    if(!ob->is_room()) return ob;
    ns = ALT_WORLD_D->find_alt(ob, ob->query("alternative world"));
    if(objectp(ns)) ob = ns;
    ob->reset();
    if(clonep(ob)) return ob;    
    if(!ob->is_control_room()) return ob;
    ob->place_mobs();
    return ob;
}
