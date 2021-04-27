#include <std.h>
inherit WEAPONLESS;

string owner;

void create(){
   ::create();
   set_name("mithril golem");
   set_id(({"golem","mithril golem","guardian","mithril guardian","huge guardian","huge mithril guardian"}));
   set_short("%^BOLD%^%^CYAN%^A huge mithril guardian%^RESET%^");
  set_long((:TO,"long_desc":));
   set_alignment(5);
   set_race("golem");
   set_gender("neuter");
   set_body_type("humanoid");
   set_hd(30,12);
   set_stats("strength",12);
   set_stats("constitution",20);
   set_stats("dexterity",6);
   set_max_hp(500);
   set_hp(500);
   set_overall_ac(-16);
   set_exp(0);
   set_attacks_num(2);
   set_damage(2,6);
   set_size(3);
   set_weight(10000);
   set_mob_magic_resistance("average");
   set_property("knock unconscious",1);
   owner = "valas";
}

void init(){
   ::init();
   add_action("emote_fun","golememote");
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
    if(str != "golem") {
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
    if(str != "golem") {
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
    if(str != "golem") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != owner && !avatarp(TP)) {
      force_me("emote doesn't move.");
      return 1;
    }
    tell_room(ETO,"The golem's metallic coat shimmers momentarily, and then the whole "
"construction disappears.");
    TO->remove();
    return 1;
}

int emote_fun(string str) {
    if(!str) {
      notify_fail("What emote do you want the golem to send?");
      return 0;
    }
    if((string)TP->query_name() != owner && !avatarp(TP)) {
      force_me("emote doesn't move.");
      return 1;
    }
    tell_room(ETO,"The mithril golem "+str+"");
    return 1;
}

int protect_fun(string str) {
    if(!str) {
      notify_fail("What do you want the golem to protect?");
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
     tell_object(TP,"The golem doesn't seem to be able to keep hold of the item, and "
"drops it.");
     TO->force_me("drop "+inven[0]->query_name());
     return;
   }
}

string long_desc() {
   if ((string)TP->query_name() == owner || avatarp(TP)) {
     return("%^BOLD%^%^WHITE%^A golem of giant proportions looms before you.  While the "
"creature is sexless, it has been built with a powerful, masculine frame.  The golem has "
"been crafted from the highest quality %^CYAN%^mithril silver%^WHITE%^.  The artisanship "
"is flawless, few seams or attachments are visible.  The golem is built in a rugged frame "
"of thin metallic beams as a skeleton, but it has many powerful attachments.  The feet of "
"the golem are huge and powerful.  The arms are robust and covered in protective shields "
"for defense.  The golems chest is massive and houses a powerful energy source.  The head "
"resembles a thin pill-shape with an obedient, statuesque expression.  A gentle hum "
"resonates from its giant form.  Altogether, it is an amazing fusion of technology and "
"magic.  Owner is "+owner+".%^RESET%^\n"
"%^BOLD%^%^WHITE%^Your commands are: lead, unlead, protectme, golememote and dismiss.");
   }
   return("%^BOLD%^%^WHITE%^A golem of giant proportions looms before you.  While the "
"creature is sexless, it has been built with a powerful, masculine frame.  The golem has "
"been crafted from the highest quality %^CYAN%^mithril silver%^WHITE%^.  The artisanship "
"is flawless, few seams or attachments are visible.  The golem is built in a rugged frame "
"of thin metallic beams as a skeleton, but it has many powerful attachments.  The feet of "
"the golem are huge and powerful.  The arms are robust and covered in protective shields "
"for defense.  The golems chest is massive and houses a powerful energy source.  The head "
"resembles a thin pill-shape with an obedient, statuesque expression.  A gentle hum "
"resonates from its giant form.  Altogether, it is an amazing fusion of technology and "
"magic.  Owner is "+owner+".%^RESET%^");
}

void die(object ob) {
   tell_room(ETO,"The golem shudders, creaks, and then falls apart as the magic holding "
"it together fades.");
   ::die(TO);
}
