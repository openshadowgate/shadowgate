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

/**
 * @file
 */

/**
 * Finds object by file descriptor and loads it if no object had been found
 *
 * @param str File descriptor of an object
 * @return Object's descriptor.
 */
object find_object_or_load(string str)
{
    object ob;

    ob = find_object(str);
    if (ob != 0) {
        if (!objectp(ob)) {
            return ob;
        }
        if (clonep(ob)) {
            return ob;
        }
        if (!ob->is_room()) {
            return ob;
        }
        if (!ob->query_reset_number()) {
            ob->reset();
        }
        if (!ob->is_control_room()) {
            return ob;
        }
        if ((int)ob->query_reset_number() != (int)ob->query_property("lastresetmobs")) {
            ob->place_mobs();
        }
        return ob;
    }
    seteuid(UID_ROOT);
    catch(call_other(str, "???"));
    seteuid(0);
    ob = find_object(str);
    if (!objectp(ob)) {
        return ob;
    }
    if (clonep(ob)) {
        return ob;
    }
    if (!ob->is_room()) {
        return ob;
    }
    ob->reset();
    if (!ob->is_control_room()) {
        return ob;
    }
    ob->place_mobs();
    return ob;
}
