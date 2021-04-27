//Odd Pod  - For Lurue - LoKi - 18-02-2008

#include <std.h>
inherit OBJECT;

object ob;


void create(){
    ::create();
    set_name("pod");
    set_id(({"pod","odd pod"}));
    set_short("%^RESET%^%^ORANGE%^An odd pod%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^Birthed in the depths of LoKi's mind,"+
" the pod calls plant people.. Just squeeze it%^RESET%^\n\n");
    set_weight(1);
    set_value(1);
}

void init() {
   ::init();
   add_action("squeeze","squeeze");
}

int squeeze(string str) {
    if(!str) {
      notify_fail("Squeeze what?");
      return 0;
    }
    tell_object(TP,"%^GREEN%^You squeeze the pod, creating an infested humanoid!");
    ob=new("/realms/loki/random/mobs/infested.c");
    ob->move(EETO);
    return 1;
}

