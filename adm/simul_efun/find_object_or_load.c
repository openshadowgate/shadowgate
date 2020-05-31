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
