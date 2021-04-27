#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("copper ring");
   set_id(({"ring","copper ring","tarnished ring","tarnished copper ring"}));
   set_short("%^RESET%^%^ORANGE%^a tarnished copper ring%^RESET%^");
   set_long("%^RESET%^This is a plain ring made of %^ORANGE%^copper metal"
"%^RESET%^, long aged and tarnished.  It appears fairly %^CYAN%^worthless "
"%^RESET%^and poor quality.\n");
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_size(2);
   set_weight(0);
   set_value(0);
   set_heart_beat(1);
}

void init() {
   ::init();
   if(!interactive(ETO) || avatarp(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !avatarp(TP)) {
     tell_object(TP,"The ring falls to dust in your hands!");
     TO->remove();
   }
}

void heart_beat() {
   object *myattackers;
   int i, hptotal, hppresent, hptarget, diff;
   if(!TO->query_worn()) return;
   if(!objectp(TO)|| !objectp(ETO) || !objectp(EETO)) return;
   if(!userp(ETO)) return;
   myattackers = ETO->query_attackers();
   if(!sizeof(myattackers)) return;
   if(random(15)) return;

   i = random(sizeof(myattackers));
   hptotal = myattackers[i]->query_max_hp();
   hppresent = myattackers[i]->query_hp();
   hptarget = hptotal / 5;
   diff = hppresent - hptarget;
   if(hppresent < 1 || diff < 1) {
     tell_object(myattackers[i],"%^MAGENTA%^"+ETO->QCN+" reaches out to you, "
"and you feel an icy chill as something tries to draw upon your life!%^RESET%^");
     tell_object(ETO,"%^MAGENTA%^You reach out and try to drain "
+myattackers[i]->QCN+"'s lifeforce, but it is too weak!%^RESET%^");
     tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" reaches out towards "
+myattackers[i]->QCN+" and "+myattackers[i]->QS+" looks a little "
"unsettled.%^RESET%^",({myattackers[i],ETO}));
     return;
   }
     tell_object(myattackers[i],"%^MAGENTA%^"+ETO->QCN+" reaches out to you, "
"and you feel an icy chill as something draws upon your life!%^RESET%^");
     tell_object(ETO,"%^MAGENTA%^You reach out and drain living energy from "
+myattackers[i]->QCN+"!%^RESET%^");
     tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" reaches out towards "
+myattackers[i]->QCN+" and "+myattackers[i]->QS+" turns %^CYAN%^deathly "
"pale%^MAGENTA%^.%^RESET%^",({myattackers[i],ETO}));
   TO->set_property("magic",1);
   myattackers[i]->do_damage("torso",diff);
   ETO->do_damage("waist",(-1)*diff);
   TO->set_property("magic",-1);
   return;
}
