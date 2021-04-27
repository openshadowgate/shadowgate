//Coded by Lujke


#include <std.h>
inherit OBJECT;


void create() {
    ::create();
    set_name("tracker");
    set_id( ({"tent tracker", "tracker"}) );
    set_short("an item that looks a bit like a compass");
    set_weight(1);
    set_long( "This small gnomish device has a wheel and needle similar to a compass. But it points to"
             +" tents. In fact, to one tent in particular. To use it, you can 'switch tracker on' or"
             +" 'switch tracker off' ");
    set_heart_beat(1);  
}

void init(){
  ::init();
  add_action("switch_me", "switch");
}

int switch_me(string str){
  string what, onoff;
  if (!stringp(str) || sscanf(str, "%s %s", what, onoff)<2 || !id(what)){
    notify_fail("Try 'switch tracker <on/off>'");
    return 0;
  }
  if (onoff == "on"){
    set_heart_beat(1);
    tell_object(TP, "You switch the tracker on");
    return 1;
  }
  if (onoff == "off"){
    set_heart_beat(0);
    tell_object(TP, "You switch the tracker off");
    return 1;
  }
  notify_fail("Try 'switch tracker <on/off>'");
  return 0;
}

void heart_beat() {
  int i;
  object * tents, where, env;
  tents = children("/d/avatars/lurue/tent.c");
  if (sizeof(tents)>0){
    for (i=0;i<sizeof(tents);i++){
       where = environment(tents[i]);
       if (objectp(where)){
         tell_object(ETO, "%^BOLD%^%^RED%^Tent alert! %^RESET%^A tent has been spotted at: " 
                         + (string)where->query_short() );
         env= environment(where);
         if (objectp(env)){
           tell_object(ETO, "This is at " + (string) env->query_short());
         }
       }
    }
  }
}