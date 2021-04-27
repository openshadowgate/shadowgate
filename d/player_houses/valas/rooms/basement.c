//function for setting someone bound to the wall, they can talk and move about somewhat but not use items or cast spells unless they are only verbal
#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(STAIRWAY);
    set_name("basement");
    set_short("tower basement");
    set_long("This basement serves for storage mostly.  There are boxes about and several sacks of unknown goods.  However, towards the end opposite the stairway there is blocked off area with a set of manacles.");
    set_smell("default","The air is somewhat stuffy.");
    set_listen("default","Your own footsteps echo through this place.");

    set_items(([
        ({"sacks","crates"}) : "There are many strange things stored here",
        ({"chains","manacles"}) : "You could shackle someone to the wall with these manacles.",
        "brick" : "This brick looks out of place. Maybe you could push it?",
    ]));
    set_search("default","One brick looks out of place.");
    set_search("brick","This brick looks out of place. Maybe you could push it?");
}

void init() {
   ::init();
   add_action("bind_em","shackle");
   add_action("unbind_em","unshackle");
   add_action("push_fun","push");
}

int bind_em(string str) {
    object ob;

    if(!str) {
        notify_fail("Shackle who?\n");
        return 0;
    }
    ob = present(str);
    if(!ob || !userp(ob)) {
        notify_fail("That person is not here!\n");
        return 0;
    }
    if(ob->query_bound()){
        notify_fail("That person is already bound!\n");
        return 1;
    }
    if(ob->query_unconscious()){
        tell_object(TP,"You fasten the manacles about the wrists of your unconscious captive.\n");
        tell_room(ETP,""+TPQCN+" fastens the unconscious captive into a set of manacles connected to the wall.\n",TP);
        ob->set_bound(random(1000)+1000,"You are chained to the wall awaiting torture, how will you do that!");
        return 1;
    }
    tell_object(TP,"Your captive is conscious and refuses to be shackled.\n");
    tell_object(ob,""+TPQCN+" tries to chain you to the wall!\n",TP);
    tell_room(ETP,""+TPQCN+" tries to chain "+ob->QCN+" to the wall unsuccessfully.\n",({TP,ob}));
    return 1;
}

int unbind_em(string str) {
    object ob;

    if(!str) {
        notify_fail("Unshackle who?\n");
        return 0;
    }
    ob = present(str);
    if(!ob || !userp(ob)) {
        notify_fail("That person is nowhere to be found!\n");
        return 0;
    }
    if(ob->query_bound()){
        tell_object(TP,"You unfasten the manacles and free your captive!\n");
        tell_room(ETP,""+TPQCN+" unfastens the manacles holding the captive.\n",TP);
        ob->set_bound(0,"You are free!");
        return 1;
    }
    tell_object(TP,"The person you are trying to unshackle is already free!\n");
    return 1;
}

int push_fun(string str) {
   if(!str) return 0;
   if(str != "brick") return 0;
   if(member_array("up",TO->query_exits()) != -1) {
     remove_exit("up");
     tell_object(TP,"You push the loose brick, and the hidden doorway slides closed.");
     tell_room(TO,""+TP->QCN+" pushes a loose brick, and the hidden doorway slides closed.",TP);
     tell_room(ROOMS"tower1","The hidden doorway before you slides closed.");
     if(member_array("down",ROOMS"tower1"->query_exits()) != -1) ROOMS"tower1"->remove_exit("down");
     return 1;
   }
   add_exit(ROOMS"tower1","up");
   tell_object(TP,"You push the loose brick, and a hidden doorway slides open at the top of the stairs.");
   tell_room(TO,""+TP->QCN+" pushes a loose brick, and a hidden doorway slides open at the top of the stairs.",TP);
   tell_room(ROOMS"tower1","A hidden doorway slides open before you.");
   if(member_array("down",ROOMS"tower1"->query_exits()) == -1) ROOMS"tower1"->add_exit(ROOMS"basement","down");
   return 1;
}