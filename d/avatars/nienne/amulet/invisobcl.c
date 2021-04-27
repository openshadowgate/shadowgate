#include <std.h>
inherit OBJECT;

int move_ok;

int go_vis();
void show_up();

void create() {
   ::create();
   set_name("invisob");
   set("id", ({ "invisobx999"}) );
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);

}

void init() {
   ::init();
   if(living(environment(TO)) && TP==environment(TO) ) {
      if(TO->query_property("spell")) {
       tell_object(TP,"%^BOLD%^%^BLACK%^You disappear among the shadows, moving with stealthy silence.%^RESET%^");
         if(TP->query_invis()) {
            TO->remove();
            return;
         }
      tell_room(environment(TP),"%^BOLD%^%^BLACK%^"+TP->QCN+" becomes one with the shadows and disappears!%^RESET%^",TP);

         TP->set_magic_hidden(1);
         set_heart_beat(5);
         add_action("go_vis","appear");
         call_out("check_attacks",2);
      } else {
         show_up();
      }
   }
}

int go_vis() {
   if(TO->query_property("spell"))
      TO->query_property("spell")->dest_effect();
   else
      show_up();
   return 1;
}

void show_up() {
   object cloaker;
   cloaker=environment(TO);
   if(!cloaker) {
      TO->remove();
      return;
   }
   if(!interactive(cloaker)) {
      TO->remove();
      return;
   }
   if(!cloaker->query_invis()) {
      TO->remove();
      return;
   }
   tell_object(cloaker,"%^GREEN%^You step forth from your shadowy concealment.%^RESET%^");
   tell_room(environment(cloaker),"%^GREEN%^A figure emerges from the shadows.%^RESET%^", cloaker);
   cloaker->set_magic_hidden(0);
   TO->remove();
   return;
}

void move(mixed dest) {
   if(!move_ok && interactive(dest))
      return 1;
   else {
      if( !interactive(dest) && interactive(environment(TO)) )
         go_vis();
      return ::move(dest);
   }
}

void move_is_ok(int a) {
   move_ok=a;
   return 1;
}

void heart_beat() {
   if( !environment(TO) )
      go_vis();
   if(!objectp(EETO)) { return; }
   if( !living(environment(TO)) ||
       !TO->query_property("spell") ||
       !environment(TO)->query_invis() ||
       (object *)environment(TO)->query_attackers() != ({}) )
      go_vis();
   return;
}

int save_me(string file){ return 1;}
int query_invis() { return 1; }
