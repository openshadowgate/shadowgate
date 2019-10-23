#include <std.h>
inherit DAEMON ;

int clean_up() { TO->remove(); return 1; }

int is_wizard(object ob) {
  if(!objectp(ob)) return 0;
  if(!userp(ob)) return 0;
  if(wizardp(ob)) return 1;
  return 0;
}

int is_avatar(object ob) {
  if(!objectp(ob)) return 0;
  if(!userp(ob)) return 0;
  if(avatarp(ob)) return 1;
  return 0;
}

int is_userp(object ob) {
  if(!objectp(ob)) return 0;
  if(!userp(ob)) return 1;
  return 0;
}

int is_objectp(object ob) {
  if(!objectp(ob)) return 0;
  if(objectp(ob)) return 1;
  return 0;
}

object * avatars() { return filter_array(users(),"is_avatar", TO); }
object * wizards() { return filter_array(users(),"is_wizard", TO); }


void local_message(string type, string what, object * recievers, object * excluded) {
  message(type,what,recievers,excluded);
}

void users_message(string type, string what, object * excluded) {
  message(type,what,users(),excluded);
}

void wizards_message(string type, string what, object * excluded) {
  message(type,what,wizards(),excluded);
}

void and_wizards_message(string type, string what,object * receivers, object * excluded) {
  message(type,what,distinct_array(wizards()+receivers),excluded);
}
void and_avatars_message(string type, string what,object * receivers, object *
excluded) {
  message(type,what,distinct_array(avatars()+receivers),excluded);
}
void avatars_message(string type, string what, object * excluded) {
  message(type,what,avatars(),excluded);
}

void first_death_message(string type, string what, object * receivers, object * excluded) {
     avatars_message(type, "%^BOLD%^%^WHITE%^Imm:"+what, ({ }));
     local_message(type, what, receivers - avatars() , excluded);
}
void delay_death_message(string type, string what, object * excluded) {
     avatars_message(type, "%^BOLD%^%^WHITE%^Mortal:"+what, ({ }));
     users_message(type, what, excluded + avatars() );
}

void delay_local_message(int delay, string type, string what, object * recievers, object * excluded)
{
    call_out("local_message", delay, type, what, recievers, excluded);
}
