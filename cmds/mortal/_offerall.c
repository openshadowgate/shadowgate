#include <std.h>

inherit DAEMON;

cmd_offerall() {
   object *inv, *living;
   int i,s,wt;

   inv = all_inventory(ETP);
   living = all_living(ETP);
   inv = inv - living;
   s = sizeof(inv);

   if (TP->query_bound()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   for(i=0;i<s;i++) {
      wt = TP->query_max_internal_encumbrance();
      if(inv[i]->query_property("monsterweapon")) {
         inv[i]->remove();
         continue;
      }
      if (!inv[i]->get()) {
          continue;
      }
      if(inv[i]->query_weight() > wt) {
         tell_object(TP,"You can't lift the "+inv[i]->query_name()+".");
         continue;
      }
      if(inv[i]->query_property("no offer") || inv[i]->query("not living")) {
         tell_object(TP, "The gods will not accept that gift.\n");
         continue;
      }

      if(inv[i]->query_property("plot_item")) {
         tell_object(TP, "The gods will not accept that gift.\n");
         continue;
      }

    if( (time() - (int)inv[i]->query_property("died time") < 600) && !TP->query_property("monsteroffer")) {
         tell_object(TP,"That object has recently been through a player death. You can not offer it yet.\n");
          continue;
        }
      if(inv[i]->query_value())
         TP->add_hp(random(2));
      inv[i]->remove();
   }
   tell_object(TP,"You offer everything in the room and bolts of lightning crash down around you.");
   tell_room(ETP,"Lightning crashes down around you as "+TPQCN+" offers everything in the room.",TP);
   return 1;
}

int help() {
   write("Syntax:  %^BOLD%^%^GREEN%^offerall%^RESET%^\n"+
      "%^BOLD%^This command will offer everything that's on the ground"+
      " in front of you. It is an OOC tool to keep the mud lag down and is not"+
      " to be used as RP tool to get rid of another player's equipment. Such"+
       " use is illegal (specifically stated in rule 2D).\n");
   return 1;
}
