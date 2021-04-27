#include <std.h>
#include <magic.h>
#include "../defs.h"
inherit OBJECT;

string *wardedrooms = ({ ROOMS"meadow", ROOMS"tree", ROOMS"upstairs", ROOMS"workroom" });
int defender;
void notify_me();
void remove_me();

void create() {
   ::create();
   set_name("eldathynward");
   set("id", ({ "eldathynwardxxx"}) );
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);
   set_heart_beat(1);
   defender = 0;
}

void init() {
   ::init();
   if(userp(ETO)) call_out("notify_me",1);
   add_action("switch_on","defend");
   add_action("switch_off","forgo");
}

void heart_beat() {
   string roomname;
   if(!objectp(ETO)) { remove_me(); return; }
   if(!userp(ETO)) { remove_me(); return; }
   if(!objectp(EETO)) { remove_me(); return; }
   roomname = base_name(EETO);
   if(member_array(roomname,wardedrooms) == -1) { remove_me(); return; }
   if(sizeof(ETO->query_attackers())) EETO->trigger_eldathyn_ward();
}

int save_me(string file) { return 1; }

void notify_me() {
   tell_object(ETO,"%^RESET%^%^CYAN%^A feeling of peace and serenity descends "
"upon you.  You instinctively know that no violence can come to pass in this "
"place, and that you could %^BOLD%^<defend> %^RESET%^%^CYAN%^others in this "
"place if you choose. You could %^BOLD%^<forgo> %^RESET%^%^CYAN%^your defense "
"of those here if you change your mind.%^RESET%^\n");
}

int switch_on(string str) {
   if(!userp(ETO)) { remove_me(); return 1; }
   if(ETO != TP) return 0;
   if(str) {
     tell_object(TP,"%^RESET%^%^CYAN%^You only need to be certain that you wish "
"to <defend> this place.\n");
     return 1;
   }
   tell_object(TP,"%^RESET%^%^CYAN%^You concentrate for a moment, making it "
"clear by your thoughts that you stand as a protector of this place.  Somehow, "
"you get the feeling you have been understood.%^RESET%^");
   defender = 1;
   return 1;
}

int switch_off(string str) {
   if(!userp(ETO)) { remove_me(); return 1; }
   if(ETO != TP) return 0;
   if(str) {
     tell_object(TP,"%^RESET%^%^CYAN%^You only need to be certain that you wish "
"to <forgo> your defense this place.\n");
     return 1;
   }
   tell_object(TP,"%^RESET%^%^CYAN%^You concentrate for a moment, making it "
"clear by your thoughts that you no longer stand as a protector of this place.  "
"Somehow, you get the feeling you have been understood.%^RESET%^");
   defender = 0;
   return 1;
}

void remove_me() {
   if(userp(ETO)) tell_object(ETO,"%^RESET%^%^CYAN%^The overwhelming feeling of "
"serenity fades from you.%^RESET%^");
   TO->remove();
}

int is_combatant() { return defender; }