#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("bracelet");
   set_id(({"bracelet","delicate bracelet","leafy bracelet","delicate leafy bracelet"}));
   set_short("%^BOLD%^%^WHITE%^delicate %^RESET%^%^GREEN%^lea%^BOLD%^f%^RESET%^%^GREEN%^y %^WHITE%^%^BOLD%^bracelet%^RESET%^");
   set_long("%^BLACK%^%^BOLD%^This brightly-polished bracelet is formed by many joined pieces of %^RESET%^%^WHITE%^sh"
"%^BOLD%^i%^RESET%^%^WHITE%^mme%^BOLD%^r%^RESET%^%^WHITE%^ing %^BOLD%^platinum%^BLACK%^. Separate segments of metal "
"each form a delicate leaf, held together with tiny %^WHITE%^platinum%^BLACK%^ links, to give an overall look of a "
"leafy vine wrapping the wearer's wrist. Small etchings run across the surface of each leaf, all lined with sparkling "
"%^RESET%^%^GREEN%^em%^BOLD%^e%^RESET%^%^GREEN%^rald dust%^BLACK%^%^BOLD%^. A few words have been engraved upon the "
"underside of the bracelet.%^RESET%^\n");
   set("read","%^RESET%^%^GREEN%^~ %^WHITE%^%^BOLD%^peace comes only from within%^RESET%^%^GREEN%^ ~%^RESET%^");
   set("language","elven");
   set_limbs(({"right hand"}));
   set_weight(0);
   set_value(10);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_property("no steal",1);
   set_property("no offer",1);
   set_property("no animate",1);
}

void init(){
   ::init();
   add_action("wopme_fun","twop");
   add_action("knockout","knockout");
   add_action("revive","revive");
}

int wear_fun() {
   if(!avatarp(ETO)) return 0;
   ETO->set_property("magic resistance",30);
   return 1;
}

int remove_fun() {
   ETO->set_property("magic resistance",-30);
   return 1;
}

int wopme_fun() {
   if(!objectp(TO)) return 0;
   if(!objectp(TP)) return 0;
   if(!avatarp(TP)) return 0;
   if(!TO->query_worn()) return 0;
   if(ETP->is_temple() && (string)ETP->query_diety() == "selune"){
      tell_object(TP,"You are already in your temple!");
      return 1;
   }
   tell_object(TP,"%^BOLD%^%^WHITE%^You whisper fervently to your goddess and feel her loving embrace whisk you away to safety!%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+TPQCN+" whispers an urgent prayer and disappears suddenly, leaving behind a few moonmotes fluttering to the ground!%^RESET%^",TP);
   tell_room(find_object_or_load("/d/magic/temples/selune"),"%^BOLD%^%^WHITE%^A few dazzling moonmotes dance on the air in front of the altar before "+TPQCN+" suddenly appears, shrouded in brilliant moonlight!%^RESET%^",TP);
   TP->move_player("/d/magic/temples/selune");
   tell_object(TP,"%^BOLD%^%^WHITE%^Selune whispers soft blessings into your ears as she returns you to the sanctity of her temple, leaving you before the altar with a moonmotes dancing around you.%^RESET%^");
   return 1;
}

int knockout(string pname) {
   object myob;
   if(!pname) {
     tell_object(TP,"Need a player name lawl.");
     return 1;
   }
   myob = present(pname,ETP);
   if(!userp(myob)) {
     tell_object(TP,"No such player here.");
     return 1;
   }
   tell_object(myob,"%^BOLD%^%^WHITE%^"+TP->QCN+" flings a hand towards you, and a beam of pure moonlight knocks you from your feet!%^RESET%^");
   tell_object(myob,"%^GREEN%^The world blurs, like paint being washed away in the rain, and then there is only darkness.%^RESET%^");
   tell_room(environment(myob),"%^BOLD%^%^WHITE%^"+TP->QCN+" flings a hand towards "+myob->QCN+", and a beam of pure moonlight knocks "+myob->QO+" from "+myob->QP+" feet!%^RESET%^",myob);
   tell_room(environment(myob),"%^GREEN%^"+myob->QCN+"'s eyes roll up, and "+myob->QS+" slumps to the ground, unconscious.%^RESET%^",myob);
   myob->set_hp(-99);
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
   tell_object(ob,"%^CYAN%^The world slowly comes into a hazy focus around you, as consciousness returns.%^RESET%^");
   tell_room(environment(ob),"%^CYAN%^"+ob->QCN+" moves a little, obviously coming back around to consciousness.%^RESET%^",ob);
   return 1;
}