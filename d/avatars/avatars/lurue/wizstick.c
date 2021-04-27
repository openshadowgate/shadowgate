#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("magic wand");
   set_id(({"wand","magic wand","wiztastic wand","wiztastic magic wand"}));
   set_short("%^BOLD%^%^CYAN%^wizta%^BLUE%^st%^CYAN%^ic magic wand%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is an odd little stick, blunt at one end and tapered to a fine point at "
"the other, much like a traditional wizard's wand.  It has been left much in its natural state like the branch "
"it was cut from, formed with bends and twists down its length.  There are two words on its side, %^YELLOW%^"
"<setprop> %^RESET%^%^ORANGE%^and %^YELLOW%^<remprop>%^RESET%^%^ORANGE%^.%^RESET%^\n");
   set_weight(0);
   set_value(0);
}

void init() {
   ::init();
   add_action("setprop","setprop");
   add_action("remprop","remprop");
}

int setprop(string str) {
   object myroom;
   if(!avatarp(TP)) {
     tell_object(TP,"Bad player. Bunnies dispatching now for stabbits.");
     TO->remove();
     return 1;
   }
   if(!str) {
     tell_object(TP,"Your arguments are <setprop tpward> or <setprop magicward>.");
     return 1;
   }
   if(str != "tpward" && str != "magicward") {
     tell_object(TP,"Your arguments are <setprop tpward> or <setprop magicward>.");
     return 1;
   }
   if(str == "tpward") {
     myroom = ETP;
     if((int)myroom->query_property("no teleport")) {
       tell_object(TP,"This room is already teleport proofed.");
       return 1;
     }
     tell_object(TP,"You have just set this room to no-teleport. You can <remprop tpward> to revoke it.");
     myroom->set_property("no teleport",1);
     return 1;
   }
   myroom = ETP;
   if((int)myroom->query_property("no magic")) {
     tell_object(TP,"This room is already magic proofed.");
     return 1;
   }
   tell_object(TP,"You have just set this room to no-magic. You can <remprop magicward> to revoke it.");
   myroom->set_property("no magic",1);
   return 1;
}

int remprop(string str) {
   object myroom;
   if(!avatarp(TP)) {
     tell_object(TP,"Bad player. Bunnies dispatching now for stabbits.");
     TO->remove();
     return 1;
   }
   if(!str) {
     tell_object(TP,"Your arguments are <remprop tpward> or <remprop magicward>.");
     return 1;
   }
   if(str != "tpward" && str != "magicward") {
     tell_object(TP,"Your arguments are <remprop tpward> or <remprop magicward>.");
     return 1;
   }
   if(str == "tpward") {
     myroom = ETP;
     if(!(int)myroom->query_property("no teleport")) {
       tell_object(TP,"This room is not teleport proofed.");
       return 1;
     }
     tell_object(TP,"You have just revoked no-teleport on this room. You can <setprop tpward> to restore it.");
     myroom->remove_property("no teleport",1);
     return 1;
   }
   myroom = ETP;
   if(!(int)myroom->query_property("no magic")) {
     tell_object(TP,"This room is not magic proofed.");
     return 1;
   }
   tell_object(TP,"You have just revoked no-magic on this room. You can <setprop magicward> to restore it.");
   myroom->remove_property("no magic",1);
   return 1;
}
