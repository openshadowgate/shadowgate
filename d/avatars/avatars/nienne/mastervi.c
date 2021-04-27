#include <std.h>
inherit WEAPONLESS;

string location;

void create() {
  ::create();
  set_name("Master Vi");
  set_id(({"cat","demon","black cat","vi","Vi","master vi","Master Vi"}));
  set_short("%^BOLD%^%^BLACK%^A %^WHITE%^sm%^BLACK%^a%^WHITE%^rtl%^BLACK%^y dr%^WHITE%^e%^BLACK%^ss%^WHITE%^e%^BLACK%^d black cat in a %^WHITE%^b%^BLACK%^o%^WHITE%^wl%^BLACK%^e%^WHITE%^r hat%^RESET%^");
  set_long((:TO,"long_desc":));
  set_race("demon");
  set_body_type("quadruped");
  set_gender("male");
  set_size(1);
  set_hd(5,4);
  set_level(5);
  set_class("fighter");
  set_mlevel("fighter",5);
  set_max_hp(100);
  set_hp(query_max_hp());
  set_exp(1);
  set_damage(1,2);
  set_attacks_num(1);
  set_base_damage_type("slashing");
  set_attack_limbs(({"right forepaw","left forepaw","teeth"}));
  set_ac(10);
  set_alignment(5);
  set_spoken("common");
  set_stats("intelligence",12);
  set_stats("wisdom",6);
  set_stats("strength",5);
  set_stats("charisma",14);
  set_stats("dexterity",17);
  set_stats("constitution",12);
  command("speech purr");
}

void init(){
   ::init();
   add_action("emote_fun","viemote");
   add_action("pose_fun","vipose");
   add_action("say_fun","visay");
   add_action("lead_fun","lead");
   add_action("unlead_fun","unlead");
   add_action("dismiss_fun","shoo");
}

int lead_fun(string str) {
    if(!str) {
      notify_fail("Lead what?");
      return 0;
    }
    if(str != "vi") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != "balur" && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    }
    TP->add_follower(TO);
    tell_object(TP,"Master Vi is now following you.");
    return 1;
}

int unlead_fun(string str) {
    if(!str) {
      notify_fail("Unlead what?");
      return 0;
    }
    if(str != "vi") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if (member_array(TO,TP->query_followers()) == -1) 
      return notify_fail(""+TO->QCN+" is not following you now.\n");
    TP->remove_follower(TO);
    tell_object(TP,TO->QCN+" will no longer follow you.");
    tell_room(ETP,"The cat stops following "+TPQCN+".", TP);
    return 1;
}

int dismiss_fun(string str) {
   object *inven;
   inven = all_inventory(TO);
    if(!str) {
      notify_fail("Shoo what?");
      return 0;
    }
    if(str != "vi") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != "balur" && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    }
    if (sizeof(inven) > 0) {
      tell_room(ETO,"The cat drops what he is carrying.");
      TO->force_me("drop "+inven[0]->query_name());
    }
    tell_room(ETO,"The cat blinks out of existence.");
    TO->remove();
    return 1;
}

int emote_fun(string str) {
    if(!str) {
      notify_fail("What emote do you want Master Vi to send?");
      return 0;
    }
    if((string)TP->query_name() != "balur" && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    }
    force_me("emote "+str+"");
    return 1;
}

int pose_fun(string str) {
    if(!str) {
      notify_fail("How do you want Master Vi to pose?");
      return 0;
    }
    if((string)TP->query_name() != "balur" && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    }
    force_me("pose "+str+"");
    return 1;
}

int say_fun(string str) {
    if(!str) {
      notify_fail("What do you want Master Vi to say?");
      return 0;
    }
    if((string)TP->query_name() != "balur" && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    }
    force_me("say "+str+"");
    return 1;
}

void receive_given_item(object obj){
   tell_room(ETO,"The cat doesn't have hands - how can he carry something?");
   TO->force_me("drop "+obj->query_name());
}

string long_desc() {
   if ((string)TP->query_name() == "balur" || avatarp(TP))
   return("%^BOLD%^%^BLACK%^This sleek feline is quite the curious sight. His midnight fur is vibrant and clearly groomed but what is even more striking is the tiny %^WHITE%^clothing"
"%^BLACK%^ that appears to have been custom fitted to his feline body. A %^WHITE%^stylish%^BLACK%^ black and %^WHITE%^white%^BLACK%^ v%^WHITE%^e%^BLACK%^st with onyx buttons hugs his "
"torso while a tiny %^WHITE%^b%^BLACK%^o%^WHITE%^wl%^BLACK%^e%^WHITE%^r hat%^BLACK%^ is somehow affixed to his head. Beneath the hat his %^GREEN%^m%^MAGENTA%^i%^GREEN%^sm%^MAGENTA%^a"
"%^GREEN%^tch%^MAGENTA%^e%^GREEN%^d %^GREEN%^e%^MAGENTA%^y%^GREEN%^e%^MAGENTA%^s%^BLACK%^, one a deep %^MAGENTA%^violet%^BLACK%^ the other a %^GREEN%^verdant green%^BLACK%^, are a tad "
"off putting as they regard all that transpires with an uncanny intelligence. His every movement is smooth and effortless like a well-dressed shadow flowing over the terrain.%^RESET%^\n"
"%^BOLD%^%^WHITE%^Your commands are: %^YELLOW%^lead vi%^WHITE%^, %^YELLOW%^unlead vi%^WHITE%^, %^YELLOW%^viemote%^WHITE%^, %^YELLOW%^vipose%^WHITE%^, %^YELLOW%^visay %^WHITE%^"
"and %^YELLOW%^shoo vi%^WHITE%^.%^RESET%^");
   return("%^BOLD%^%^BLACK%^This sleek feline is quite the curious sight. His midnight fur is vibrant and clearly groomed but what is even more striking is the tiny %^WHITE%^clothing"
"%^BLACK%^ that appears to have been custom fitted to his feline body. A %^WHITE%^stylish%^BLACK%^ black and %^WHITE%^white%^BLACK%^ v%^WHITE%^e%^BLACK%^st with onyx buttons hugs his "
"torso while a tiny %^WHITE%^b%^BLACK%^o%^WHITE%^wl%^BLACK%^e%^WHITE%^r hat%^BLACK%^ is somehow affixed to his head. Beneath the hat his %^GREEN%^m%^MAGENTA%^i%^GREEN%^sm%^MAGENTA%^a"
"%^GREEN%^tch%^MAGENTA%^e%^GREEN%^d %^GREEN%^e%^MAGENTA%^y%^GREEN%^e%^MAGENTA%^s%^BLACK%^, one a deep %^MAGENTA%^violet%^BLACK%^ the other a %^GREEN%^verdant green%^BLACK%^, are a tad "
"off putting as they regard all that transpires with an uncanny intelligence. His every movement is smooth and effortless like a well-dressed shadow flowing over the terrain.%^RESET%^");
}

void die(object ob) {
   tell_room(ETO,"The cat blinks out of existence.");
   TO->remove();
}
