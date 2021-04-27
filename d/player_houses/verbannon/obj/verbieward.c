#include <std.h>
#include <magic.h>
#include "../defs.h"
inherit OBJECT;

void notify_me();
void remove_me();

void create() {
   ::create();
   set_name("verbieward");
   set("id", ({ "verbiewardxxx"}) );
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);
   set_heart_beat(1);
}

void init() {
   ::init();
   if(userp(ETO)) call_out("notify_me",1);
}

void heart_beat() {
   string roomname;
   if(!objectp(ETO)) { remove_me(); return; }
   if(!userp(ETO)) { remove_me(); return; }
   if(!objectp(EETO)) { remove_me(); return; }
   roomname = base_name(EETO);
   if(strsrch(roomname,"/d/player_houses/verbannon/rooms/") == -1) remove_me();
   if(roomname == "/d/player_houses/verbannon/rooms/precipice") remove_me();
}

int save_me(string file) { return 1; }

void notify_me() {
   tell_object(ETO,"It's as if a thousand eyes and minds have turned their attentions to you, their sometimes intelligible whispering tickling your ears.\n");
}

void remove_me() {
   if(userp(ETO)) tell_object(ETO,"You can finally relax as the whispering in your ears abates.\n");
   TO->remove();
}