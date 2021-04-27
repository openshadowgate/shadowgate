//Odd Pod  - For Lurue - LoKi - 18-02-2008

#include <std.h>
inherit OBJECT;

object ob;


void create(){
    ::create();
    set_name("battery");
    set_id(({"battery","black Battery"}));
    set_short("%^BLACK%^%^BOLD%^A Black Battery%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^Birthed in the depths of LoKi's mind,"+
" the battery calls plant people.. Just stroke it%^RESET%^\n\n");
    set_weight(1);
    set_value(1);
}

void init() {
   ::init();
   add_action("stroke","stroke");
}

int stroke(string str) {
    if(!str) {
      notify_fail("Stroke what?");
      return 0;
    }
    tell_object(TP,"%^GREEN%^You stroke the battery, coaxing out an elemental!");
    ob=new("/realms/loki/random/mobs/babystorm.c");
    ob->move(EETO);
    return 1;
}

