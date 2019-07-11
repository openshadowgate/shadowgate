//
//_charge.c
/*
 *This cmd is a cavalier command designed around the cavalier
 *charging toward an opponent on his or her warhorse.
 */

#include <std.h>

#define VOID "/d/shadowgate/void"

inherit DAEMON;


int cmd_charge2(string str) {
    object ob;
    string target;

    if (!str)
        return notify_fail("You need to specify a target!\n");

    if (str == "off") {
        ob = TP->query_property("charging object");
        if (objectp(ob)) {
            ob->remove();
        }

      TP->remove_property("charging");
        TP->remove_property("charging object");      
        TP->remove_property("using instant feat");
        TP->remove_property("using charge");
        write("%^BOLD%^%^BLUE%^You stop charging");
        tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" pulls "+TPQP+" horse up.",TP);

        return 1;
    }
    if (TP->query_property("charging"))
        return notify_fail("You can only charge in one direction at a time!\n");

    if (ob = TP->query_property("charging object")) {
        if (objectp(ob)) {
            ob->remove();
        }
      TP->remove_property("charging");
        TP->remove_property("charging object");   
        TP->remove_property("using instant feat");
      TP->remove_property("using charge");
    }
    ob = new ("/cmds/cavalier/charge");
    
    ob->set_tp(TP);
    ob->set_target(str);
      TP->set_property("charging",1);
    ob->do_exit();
    if (objectp(ob)) {
        TP->set_property("charging object", ob);
        TP->add_post_exit_func((:call_other,ob,"do_exit":));
    }

    return 1;

    //    write(target+"\t"+direction+"\t"+distance);
}






int help(){
    write(
@OLI
    charge <target>

    This allows you to charge a target. If the target is in the room,
it simply charges the target. If the target is not in the room. You may
use exits to reach a room in which the target exists. You may move the
number of rooms equivilent to the number of levels in your cavalier class.
You also must complete your charge in the amount of time equals to your
level in heart beats (about 1.5 seconds). 

    charge off will remove the charge
OLI
    );

    return 1;
}

