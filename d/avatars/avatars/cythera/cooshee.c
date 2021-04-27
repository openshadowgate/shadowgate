#include <std.h>
inherit WEAPONLESS;

string location;

void create() {
  ::create();
  set_name("cooshee");
  set_id(({"cooshee","elven dog","dog"}));
  set_short("%^RESET%^%^GREEN%^A cooshee%^RESET%^");
  set_long((:TO,"long_desc":));
  set_race("cooshee");
  set_body_type("quadruped");
  set_gender("male");
  set_size(1);
  set_hd(12,1);
  set_max_hp(query_hd()*8);
  set_hp(query_max_hp());
  set_exp(1);
  set_damage(2,3);
  set_attacks_num(2);
  set_base_damage_type("slashing");
  set_attack_limbs(({"right forepaw","left forepaw","teeth"}));
  set_ac(10);
  set_alignment(5);
  set_stats("intelligence",10);
  set_stats("wisdom",12);
  set_stats("strength",18);
  set_stats("charisma",14);
  set_stats("dexterity",22);
  set_stats("constitution",14);
  command("message in trots in.");
  command("message out ambles $D.");
}

void init(){
   ::init();
   add_action("emote_fun","petemote");
   add_action("lead_fun","lead");
   add_action("unlead_fun","unlead");
   add_action("dismiss_fun","shoo");
}

int lead_fun(string str) {
    if(!str) {
      notify_fail("Lead what?");
      return 0;
    }
    if(str != "cooshee") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != "phade" && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
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
    if(str != "cooshee") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if (member_array(TO,TP->query_followers()) == -1) 
      return notify_fail(""+TO->QCN+" is not following you now.\n");
    TP->remove_follower(TO);
    tell_object(TP,TO->QCN+" will no longer follow you.");
    tell_room(ETP, TPQCN+" tells "+TO->QCN+" to stay.", TP);
    return 1;
}

int dismiss_fun(string str) {
   object *inven;
   inven = all_inventory(TO);
    if(!str) {
      notify_fail("Shoo what?");
      return 0;
    }
    if(str != "cooshee") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != "phade" && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    }
    if (sizeof(inven) > 0) {
      tell_room(ETO,"The cooshee drops what it is carrying.");
      TO->force_me("drop "+inven[0]->query_name());
    }
    tell_room(ETO,"The cooshee takes heed of "+TP->query_name()+"'s gesture and scampers off.");
    TO->remove();
    return 1;
}

int emote_fun(string str) {
    if(!str) {
      notify_fail("What emote do you want the cooshee to send?");
      return 0;
    }
    if((string)TP->query_name() != "phade" && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    }
    tell_room(ETO,"The cooshee "+str+"");
    return 1;
}

void receive_given_item(object obj){
   object *inven;
   inven = all_inventory(TO);
   if (sizeof(inven) > 1) {
     tell_object(TP,"The cooshee can't seem to carry more than one item at "
"a time... It tries to keep hold of both items, but drops one.");
     TO->force_me("drop "+inven[random(2)]->query_name());
     return;
   }
}

string long_desc() {
   if ((string)TP->query_name() == "phade" || avatarp(TP)) {
     return("%^RESET%^%^GREEN%^This little guy is incredibly cute, in a roly-poly, waddling sort of way. Covered in "
"%^BOLD%^soft green fur %^RESET%^%^GREEN%^edged with %^BOLD%^%^WHITE%^white guard hairs%^RESET%^%^GREEN%^, he has huge "
"feet and a very long %^BOLD%^%^MAGENTA%^pink tongue %^RESET%^%^GREEN%^that curls up and touches his %^BOLD%^%^BLACK%^"
"black button nose %^RESET%^%^GREEN%^as he pants.  Two long ears stick up from the sides of his head, flopping over about "
"over half way up, giving him a perpetual look of perked curiosity.  Silvery%^BOLD%^%^CYAN%^ blue eyes %^RESET%^%^GREEN%^"
"hold a look of constant interest, especially when there appears to be a %^ORANGE%^treat %^GREEN%^nearby.%^RESET%^\n"
"%^BOLD%^%^WHITE%^Your commands are: %^YELLOW%^lead%^WHITE%^, %^YELLOW%^unlead%^WHITE%^, %^YELLOW%^petemote "
"%^WHITE%^and %^YELLOW%^shoo%^WHITE%^.%^RESET%^");
   }
   return("%^RESET%^%^GREEN%^This little guy is incredibly cute, in a roly-poly, waddling sort of way. Covered in "
"%^BOLD%^soft green fur %^RESET%^%^GREEN%^edged with %^BOLD%^%^WHITE%^white guard hairs%^RESET%^%^GREEN%^, he has huge "
"feet and a very long %^BOLD%^%^MAGENTA%^pink tongue %^RESET%^%^GREEN%^that curls up and touches his %^BOLD%^%^BLACK%^"
"black button nose %^RESET%^%^GREEN%^as he pants.  Two long ears stick up from the sides of his head, flopping over about "
"over half way up, giving him a perpetual look of perked curiosity.  Silvery%^BOLD%^%^CYAN%^ blue eyes %^RESET%^%^GREEN%^"
"hold a look of constant interest, especially when there appears to be a %^ORANGE%^treat %^GREEN%^nearby.%^RESET%^");
}

void die(object ob) {
   tell_room(ETO,"The cooshee scrambles away from harm and flees!");
   TO->remove();
}
