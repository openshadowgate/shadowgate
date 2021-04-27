#include <std.h>
inherit WEAPONLESS;

string location, translated, myowner;
int translating;

void create() {
  ::create();
  set_name("feystag");
  set_id(({"feystag","calygraunt"}));
  set_short("%^RESET%^%^ORANGE%^a little %^GREEN%^fe%^CYAN%^yst%^GREEN%^ag %^ORANGE%^with short, m%^RESET%^o%^ORANGE%^tt%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^ed fur%^RESET%^");
  set_long((:TO,"long_desc":));
  set_race("feystag");
  set_body_type("quadruped");
  set_gender("male");
  set_size(1);
  set_hd(6,50);
  set_level(5);
  set_class("fighter");
  set_mlevel("fighter",5);
  set_max_hp(300);
  set_hp(query_max_hp());
  set_exp(1);
  set_damage(1,2);
  set_attacks_num(1);
  set_base_damage_type("slashing");
  set_attack_limbs(({"right forepaw","left forepaw","teeth"}));
  set_ac(10);
  set_alignment(5);
  set_spoken("wizish");
  set_stats("intelligence",18);
  set_stats("wisdom",11);
  set_stats("strength",5);
  set_stats("charisma",14);
  set_stats("dexterity",17);
  set_stats("constitution",12);
  myowner = "nienne";
  translating = 0;
}

void init(){
   ::init();
   add_action("lead_fun","lead");
   add_action("unlead_fun","unlead");
   add_action("dismiss_fun","dismissme");
   add_action("translate_fun","translate");
   add_action("translateoff_fun","translateoff");
}

int lead_fun(string str) {
    if(!str) {
      notify_fail("Lead what?\n");
      return 0;
    }
    if(str != "feystag") {
      notify_fail("Nothing happens.\n");
      return 0;
    }
    if((string)TP->query_name() != myowner && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    }
    TP->add_follower(TO);
    tell_object(TP,query_cap_name()+" is now following you.");
    return 1;
}

int unlead_fun(string str) {
    if(!str) {
      notify_fail("Unlead what?\n");
      return 0;
    }
    if(str != "feystag") {
      notify_fail("Nothing happens.\n");
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
    if(!str) {
      notify_fail("Dismiss what?\n");
      return 0;
    }
    if(str != "feystag") {
      notify_fail("Nothing happens.\n");
      return 0;
    }
    if((string)TP->query_name() != myowner && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    }
    tell_room(ETO,"%^RESET%^%^GREEN%^The feystag claps its paws together, hisses a word, and %^BOLD%^%^CYAN%^v%^GREEN%^an%^CYAN%^is%^GREEN%^he%^CYAN%^s%^RESET%^%^GREEN%^!%^RESET%^");
    TO->remove();
    return 1;
}

int translate_fun(string str) {
    object targ;
//    targ = find_player(TP->realName(lower_case(str)));
    targ = TP;
/*    if((string)TP->query_name() != myowner && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    } */
    if(!userp(targ)) {
      notify_fail("There is no such person here.\n");
      return 0;
    }
    if(!present(targ,ETO)) {
      notify_fail("There is no such person here.\n");
      return 0;
    }
    translating = 1;
    translated = targ->query_name();
    location = base_name(ETO);
    tell_room(ETO,"%^RESET%^%^GREEN%^The feystag perks up its attention at a motion from "+TP->QCN+", and starts "
"concentrating on "+targ->QCN+".%^RESET%^",TP);
    tell_object(TP,"%^RESET%^%^GREEN%^The feystag perks up its attention at a motion from you, and starts concentrating "
"on "+targ->QCN+".%^RESET%^");
    return 1;
}

int translateoff_fun(string str) {
    if(str) {
      notify_fail("Just <translateoff>.\n");
      return 0;
    }
    if(!translating) {
      notify_fail("The feystag is not concentrating on anyone right now.\n");
      return 0;
    }
/*    if((string)TP->query_name() != myowner && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    } */
    translating = 0;
    translated = "";
    location = "";
    tell_room(ETO,"%^RESET%^%^GREEN%^The feystag gives a very human nod of its head as "+TP->QCN+" motions for it to "
"stop, and it relaxes.%^RESET%^",TP);
    tell_object(TP,"%^RESET%^%^GREEN%^The feystag gives a very human nod of its head as you motion for it to stop, and it "
"relaxes.%^RESET%^");
    return 1;
}

void receive_given_item(object obj){
   tell_object(TP,"%^RESET%^%^GREEN%^The feystag seems uninterested in the item, and sets it carefully back down before you.%^RESET%^");
   TO->force_me("drop "+obj->query_name());
}

string long_desc() {
   if ((string)TP->query_name() == myowner || avatarp(TP)) {
return("%^RESET%^%^GREEN%^This creature is known as a feystag, or a calygraunt.  At first glance it could be mistaken "
"for a large %^ORANGE%^ho%^RESET%^u%^ORANGE%^se%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^at%^GREEN%^, except that it has a "
"pair of %^RESET%^fro%^BOLD%^n%^RESET%^d-bra%^BOLD%^%^BLACK%^n%^RESET%^ched an%^BOLD%^t%^RESET%^lers %^GREEN%^that sweep "
"back from its head like those of a stag.  Its coat is a %^ORANGE%^mo%^BOLD%^%^BLACK%^ttl%^RESET%^%^ORANGE%^ed b%^BOLD%^"
"%^BLACK%^row%^RESET%^%^ORANGE%^n %^GREEN%^shade, giving the creature a natural form of camouflage in the wilds.  Its "
"%^ORANGE%^t%^RESET%^u%^ORANGE%^f%^BOLD%^%^BLACK%^te%^RESET%^%^ORANGE%^d %^GREEN%^tail curls around its hind legs as it "
"sits upright; despite looking as though it could run on all fours, it tends to spend more time on two.  At odds with its "
"strange appearance is the deep, alien intelligence present within its %^ORANGE%^pale o%^GREEN%^li%^ORANGE%^ve eyes"
"%^GREEN%^.  At its throat glitters a %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en %^RESET%^%^GREEN%^medallion, and it "
"clutches a %^BOLD%^%^BLUE%^gl%^CYAN%^o%^BLUE%^s%^RESET%^%^BLUE%^s%^BOLD%^y sa%^WHITE%^p%^CYAN%^p%^BLUE%^hi%^RESET%^"
"%^BLUE%^r%^BOLD%^e o%^CYAN%^r%^BLUE%^b %^RESET%^%^GREEN%^in one paw.%^RESET%^\n"
"%^BOLD%^%^WHITE%^Your commands are: %^YELLOW%^lead%^WHITE%^, %^YELLOW%^unlead%^WHITE%^, %^YELLOW%^dismissme%^WHITE%^, "
"%^YELLOW%^translate playername%^WHITE%^ and %^YELLOW%^translateoff%^WHITE%^.%^RESET%^");
   }
   return("%^RESET%^%^GREEN%^This creature is known as a feystag, or a calygraunt.  At first glance it could be mistaken "
"for a large %^ORANGE%^ho%^RESET%^u%^ORANGE%^se%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^at%^GREEN%^, except that it has a "
"pair of %^RESET%^fro%^BOLD%^n%^RESET%^d-bra%^BOLD%^%^BLACK%^n%^RESET%^ched an%^BOLD%^t%^RESET%^lers %^GREEN%^that sweep "
"back from its head like those of a stag.  Its coat is a %^ORANGE%^mo%^BOLD%^%^BLACK%^ttl%^RESET%^%^ORANGE%^ed b%^BOLD%^"
"%^BLACK%^row%^RESET%^%^ORANGE%^n %^GREEN%^shade, giving the creature a natural form of camouflage in the wilds.  Its "
"%^ORANGE%^t%^RESET%^u%^ORANGE%^f%^BOLD%^%^BLACK%^te%^RESET%^%^ORANGE%^d %^GREEN%^tail curls around its hind legs as it "
"sits upright; despite looking as though it could run on all fours, it tends to spend more time on two.  At odds with its "
"strange appearance is the deep, alien intelligence present within its %^ORANGE%^pale o%^GREEN%^li%^ORANGE%^ve eyes"
"%^GREEN%^.  At its throat glitters a %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en %^RESET%^%^GREEN%^medallion, and it "
"clutches a %^BOLD%^%^BLUE%^gl%^CYAN%^o%^BLUE%^s%^RESET%^%^BLUE%^s%^BOLD%^y sa%^WHITE%^p%^CYAN%^p%^BLUE%^hi%^RESET%^"
"%^BLUE%^r%^BOLD%^e o%^CYAN%^r%^BLUE%^b %^RESET%^%^GREEN%^in one paw.%^RESET%^");
}

void die(object ob) {
   tell_room(ETO,"%^RESET%^%^GREEN%^The feystag claps its paws together, hisses a word, and %^BOLD%^%^CYAN%^v%^GREEN%^an%^CYAN%^is%^GREEN%^he%^CYAN%^s%^RESET%^%^GREEN%^!%^RESET%^");
   TO->remove();
}

void catch_say(string msg){
   call_out("reply_fun",1,msg,TP);
}

void reply_fun(string msg, object who){
   string pretext, repeating;
   if(!msg || !objectp(who)) return;
   if(!translating) return;
   if((string)who->query_name() != translated) return;
   if(sscanf(msg,"%s: %s", pretext, repeating) != 2) return;
   force_me("speech translate in a willowy lilt");
   force_me("speak wizish");
   force_me("say "+repeating);
}

void heart_beat() {
   ::heart_beat();
   if(!translating) return;
   if(!present(translated,ETO)) {
     tell_room(ETO,"%^RESET%^%^GREEN%^The feystag relaxes as the subject of its attentions departs.%^RESET%^");
     translating = 0;
     translated = "";
     location = "";
   }
   else if(base_name(ETO) != location) {
     tell_room(ETO,"%^RESET%^%^GREEN%^The feystag reverts its attentions to travelling.%^RESET%^");
     translating = 0;
     translated = "";
     location = "";
   }
}
