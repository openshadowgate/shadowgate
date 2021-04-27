//tweaked up illthid coded by hades 6/27/10
//control code stolen from nienne's golem
#include <std.h>
inherit "/d/laerad/mon/illithid";
string owner;

create(){
::create();
   set("aggressive",0);
   set_speed(0);
   set_heart_beat(0);
 }
 void init(){
   ::init();
   add_action("emote_fun","illemote");
   add_action("lead_fun","lead");
   add_action("unlead_fun","unlead");
   add_action("dismiss_fun","dismiss");
   add_action("protect_fun","protectem");
}
void set_owner(string str) { owner = str; }

int lead_fun(string str) {
    if(!str) {
      notify_fail("Lead what?");
      return 0;
    }
    if(str != "illithid") {
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
    if(str != "illithid") {
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
    if(str != "illithid") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != owner && !avatarp(TP)) {
      force_me("emote doesn't move.");
      return 1;
    }
    tell_room(ETO,"The illithid vanishes with a flash.");
	TO->move("/d/shadowgate/void");
    TO->remove();
    return 1;
}

int emote_fun(string str) {
    if(!str) {
      notify_fail("What emote do you want the illithid to send?");
      return 0;
    }
    if((string)TP->query_name() != owner && !avatarp(TP)) {
      force_me("emote doesn't move.");
      return 1;
    }
    tell_room(ETO,"The illithid "+str+"");
    return 1;
}

int protect_fun(string str) {
    if(!str) {
      notify_fail("What do you want the illithid to protect?");
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
     tell_object(TP,"The illithid doesn't seem"+
	 "to be able to keep hold of the item, and "+
     "drops it.");
     TO->force_me("drop "+inven[0]->query_name());
     return;
   }
}
