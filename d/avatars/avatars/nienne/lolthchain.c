#include <std.h>
inherit ARMOUR;

int gate1, gate2;

void create() {
   ::create();
   set_name("spider necklace");
   set_id(({"necklace","amber necklace","spider necklace","embrace"}));
   set_short("%^RESET%^%^ORANGE%^Lolth's embrace%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^an amber spider necklace%^RESET%^");
   set_long("The necklace has a %^BOLD%^%^WHITE%^silver chain %^RESET%^from "
"which hangs a large, polished piece of %^ORANGE%^amber%^RESET%^. Encased in "
"the center of the %^ORANGE%^amber%^RESET%^ is a spider that has been trapped "
"for eternity. It is a %^BOLD%^%^BLACK%^black%^RESET%^ widow, you can tell by "
"the %^RED%^red hourglass%^RESET%^ on its back. Its eight legs are "
"outstretched and it is pointed upwards.\n");
   set_weight(2);
   set_value(3000);
   set_ac(0);
   set_limbs(({"neck"}));
   set_type("ring");
   set_property("enchantment",3);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   gate1 = 0;
   gate2 = 0;
}

int drop(){ return 1; }

void init() {
   ::init();
   add_action("querybound","querybound");
   add_action("setbound","setbound");
   add_action("knockout","knockout");
   add_action("revive","revive");
}

int wear_fun() {
   tell_object(TP,"%^ORANGE%^There is a soothing aura about the amber "
"necklace and you believe it will protect you well.%^RESET%^");
   tell_room(ETP,"%^ORANGE%^"+TPQCN+" smiles slightly as"+TP->QS+" slips on "
"the amber necklace.%^RESET%^",TP);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^ORANGE%^You remove the necklace and feel much more "
"vulnerable.%^RESET%^");
   return 1;
}

int querybound(string pname) {
   object ob;
   if(!pname) {
     tell_object(TP,"Need a player name lawl.");
     return 1;
   }
   if(!userp(find_player(pname))) {
     tell_object(TP,"No such player online.");
     return 1;
   }
   ob = find_player(pname);
   tell_object(TP,""+pname+" is bound: %^YELLOW%^"+ob->query_bound()+"");
   return 1;
}

int setbound(string pname) {
   object ob;
   if(!pname) {
     tell_object(TP,"Need a player name lawl.");
     return 1;
   }
   if(!userp(find_player(pname))) {
     tell_object(TP,"No such player online.");
     return 1;
   }
   ob = find_player(pname);
   ob->set_bound(2000);
   tell_object(TP,""+pname+" is now bound: %^YELLOW%^2000");
   return 1;
}

int knockout(string pname) {
   object ob;
   if(!pname) {
     tell_object(TP,"Need a player name lawl.");
     return 1;
   }
   if(!userp(find_player(pname))) {
     tell_object(TP,"No such player online.");
     return 1;
   }
   ob = find_player(pname);
   tell_object(ob,"%^BOLD%^%^BLACK%^Tiny darts whistle through the air from "
"the shadows and sink into your flesh.%^RESET%^");
   tell_object(ob,"%^GREEN%^The world blurs, like paint being washed away in "
"the rain, and then there is only darkness.%^RESET%^");
   tell_room(environment(ob),"%^BOLD%^%^BLACK%^Tiny darts whistle through the "
"air from the shadows and sink into "+ob->QCN+"'s flesh.%^RESET%^",ob);
   tell_room(environment(ob),"%^GREEN%^"+ob->QCN+"'s eyes roll up, and "
+ob->QS+" slumps to the ground, unconscious.%^RESET%^",ob);
   ob->set_hp(-50);
   return 1;
}

int revive(string pname) {
   object ob;
   if (!pname) {
     tell_object(TP,"Need a player name lawl.");
     return 1;
   }
   if(!userp(find_player(pname))) {
     tell_object(TP,"No such player online.");
     return 1;
   }
   ob = find_player(pname);
   ob->set_hp(ob->query_max_hp());
   tell_object(ob,"%^CYAN%^The world slowly comes into a hazy focus around "
"you, as consciousness returns.%^RESET%^");
   tell_room(environment(ob),"%^CYAN%^"+ob->QCN+" moves a little, obviously "
"coming back around to consciousness.%^RESET%^",ob);
   return 1;
}
