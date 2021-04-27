//tweaked up water elemental coded by hades 1/12/10
//control code stolen from nienne's golem
#include <std.h>
inherit "/d/magic/mon/priest_welemental";
string owner;

create(){
::create();
  set_hp(random(300)+100);
  set_property("damage resistance",1);
  set_class("thief");
  set_mlevel("thief",30);
  set_guild_level("thief",30);
  set_funcs(({"water"}));
  set_func_chance(100);
  add_search_path("/cmds/thief");
  set_scrambling(1);
  set_thief_skill("hide in shadows",95);
  set_thief_skill("move silently",95);
 }
 void init(){
   ::init();
   add_action("emote_fun","elementalemote");
   add_action("lead_fun","lead");
   add_action("unlead_fun","unlead");
   add_action("dismiss_fun","dismiss");
   add_action("protect_fun","protectme");
}
void set_owner(string str) { owner = str; }

int lead_fun(string str) {
    if(!str) {
      notify_fail("Lead what?");
      return 0;
    }
    if(str != "elemental") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != owner && !avatarp(TP)) {
      force_me("emote doesn't move.");
      return 1;
    }
    TP->add_follower(TO);
    tell_object(TP,query_cap_name()+" is now following you.");
    return 1;
}

int unlead_fun(string str) {
    if(!str) {
      notify_fail("Unlead what?");
      return 0;
    }
    if(str != "elemental") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if (member_array(TO,TP->query_followers()) == -1) 
      return notify_fail(""+TO->QCN+" is not following you now.\n");
    TP->remove_follower(TO);
    tell_object(TP,TO->QCN+" will no longer follow you.");
    tell_room(ETP, TPQCN+" commands "+TO->QCN+" to stop.", TP);
    return 1;
}


int dismiss_fun(string str) {
   object *inven;
   inven = all_inventory(TO);
    if(!str) {
      notify_fail("Dismiss what?");
      return 0;
    }
    if(str != "elemental") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != owner && !avatarp(TP)) {
      force_me("emote doesn't move.");
      return 1;
    }
    tell_room(ETO,"The elemental falls apart with a splash.");
    TO->remove();
    return 1;
}

int emote_fun(string str) {
    if(!str) {
      notify_fail("What emote do you want the elemental to send?");
      return 0;
    }
    if((string)TP->query_name() != owner && !avatarp(TP)) {
      force_me("emote doesn't move.");
      return 1;
    }
    tell_room(ETO,"The water elemental "+str+"");
    return 1;
}

int protect_fun(string str) {
    if(!str) {
      notify_fail("What do you want the elemental to protect?");
      return 0;
    }
    if(!present(str,ETO)) {
      notify_fail("That is not here to protect.");

      return 0;
    }
    if((string)TP->query_name() != owner && !avatarp(TP)) {
      force_me("emote doesn't move.");
      return 1;
    }
    force_me("protect "+str);
    return 1;
}

void receive_given_item(object obj){
   object *inven;
   inven = all_inventory(TO);
   if (sizeof(inven) > 0) {
     tell_object(TP,"The elemental doesn't seem"+
	 "to be able to keep hold of the item, and "+
     "drops it.");
     TO->force_me("drop "+inven[0]->query_name());
     return;
   }
}
 
 void water(object targ){
 if(!objectp(TO))return;
  if(!objectp(query_current_attacker())) { return ; } 
   if(query_attackers()==({ })) return;
   set_hidden(0);
   tell_object(targ,"%^BOLD%^%^BLUE%^A fist of water splashes into you as it reforms.");
   tell_room(ETO,"%^BOLD%^%^BLUE%^The elemental reforms and splashes a first into"+
   " "+targ->query_cap_name()+".",targ);
   targ->do_damage(targ->return_target_limb(),random(10)+20);
     return;
 }
 void heart_beat(){
   object *attackers;
  int x;
  ::heart_beat();
  if(!objectp(TO))return;
  if(!objectp(query_current_attacker())) { return ; } 
   if(query_attackers()==({ })) return;
   
    tell_room(environment(TO),"%^BOLD%^%^BLUE%^"+TOQCN+
	" sinks into a pool of water with a splash.",TO);
    TO->set_hidden(1);
 
 }
 
 void die(object ob) {
   tell_room(ETO,"The watery form breaks appart leaving only a puddle.");
   ::die(TO);
}
