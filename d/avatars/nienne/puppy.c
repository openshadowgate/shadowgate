#include <std.h>
inherit WEAPONLESS;

string location;

void create() {
  ::create();
  set_name("hound");
  set_id(({"hound","dog","white hound","long eared hound","long-eared hound"}));
  set_short("%^BOLD%^%^WHITE%^a long-e%^BLACK%^ar%^WHITE%^ed white hound%^RESET%^");
  set_long((:TO,"long_desc":));
  set_race("dog");
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
  set_spoken("wizish");
  set_stats("intelligence",12);
  set_stats("wisdom",6);
  set_stats("strength",5);
  set_stats("charisma",14);
  set_stats("dexterity",17);
  set_stats("constitution",12);
  set_emotes(1,({"%^CYAN%^The hound leans back to have a vigorous scratch at a floppy ear.",
"%^RED%^The hound tilts his head to the side, one ear flopping halfway over his face with the motion.",
"%^GREEN%^The hounds's tail thumps lightly on the ground once.",
"%^ORANGE%^A little huff comes from the hound as he peers around."}), 0);
  command("message in trots in and peers around slowly.");
  command("message out shuffles $D.");
}

void init(){
   ::init();
   add_action("emote_fun","houndemote");
   add_action("pose_fun","houndpose");
   add_action("lead_fun","lead");
   add_action("unlead_fun","unlead");
   add_action("dismiss_fun","shoo");
}

int lead_fun(string str) {
    if(!str) {
      notify_fail("Lead what?");
      return 0;
    }
    if(str != "hound") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != "snog" && !avatarp(TP)) {
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
    if(str != "hound") {
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
    if(str != "hound") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != "snog" && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    }
    if (sizeof(inven) > 0) {
      tell_room(ETO,"The hound drops what he is carrying.");
      TO->force_me("drop "+inven[0]->query_name());
    }
    tell_room(ETO,"The hound looks up, distracted, and trots off.");
    TO->remove();
    return 1;
}

int emote_fun(string str) {
    if(!str) {
      notify_fail("What emote do you want the hound to send?");
      return 0;
    }
    if((string)TP->query_name() != "snog" && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    }
    tell_room(ETO,"The hound "+str+"");
    return 1;
}

int pose_fun(string str) {
    if(!str) {
      notify_fail("How do you want the hound to pose?");
      return 0;
    }
    if((string)TP->query_name() != "snog" && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    }
    force_me("pose "+str+"");
    return 1;
}

void receive_given_item(object obj){
   object *inven;
   inven = all_inventory(TO);
   if (sizeof(inven) > 1) {
     tell_object(TP,"The hound can't seem to carry more than one item at "
"a time... It tries to keep hold of both items, but drops one.");
     TO->force_me("drop "+inven[random(2)]->query_name());
     return;
   }
}

string long_desc() {
   if ((string)TP->query_name() == "snog" || avatarp(TP))
   return("%^RESET%^%^CYAN%^This hound seems to be all droops, from his ears to "
"his tail.  Nearly all %^BOLD%^%^WHITE%^white%^RESET%^%^CYAN%^, he bears a "
"large %^BOLD%^%^BLACK%^black patch %^RESET%^%^CYAN%^over one ear to break up "
"the otherwise plain coloration of his fur.  His legs seem a little too short "
"for his body, making his gait seem more like a shuffle than a walk at times.  "
"He has a habit of tilting his head to the side, letting his long ears flop "
"about over his face in a %^MAGENTA%^co%^RED%^mic%^MAGENTA%^al %^CYAN%^"
"expression.  His eyes are the color of %^ORANGE%^fresh coffee%^CYAN%^, dark "
"brown and constantly filled with a mournful appearance, though this seems "
"caused more by the drooped shape of his face than the dog's disposition.  He "
"often seems content to simply flop down on the ground, ears splayed out to "
"either side as he peers up at the world around him, as his tail sometimes "
"lifts in a hopeful wag when someone approaches close by.  A little "
"%^ORANGE%^leather collar %^CYAN%^rests around his neck, studded with small "
"round pieces of %^BOLD%^%^WHITE%^palladium%^RESET%^%^CYAN%^.%^RESET%^\n"
"%^BOLD%^%^WHITE%^Your commands are: %^YELLOW%^lead%^WHITE%^, %^YELLOW%^"
"unlead%^WHITE%^, %^YELLOW%^houndemote%^WHITE%^, %^YELLOW%^houndpose %^WHITE%^"
"and %^YELLOW%^shoo%^WHITE%^.%^RESET%^");
   return("%^RESET%^%^CYAN%^This hound seems to be all droops, from his ears to "
"his tail.  Nearly all %^BOLD%^%^WHITE%^white%^RESET%^%^CYAN%^, he bears a "
"large %^BOLD%^%^BLACK%^black patch %^RESET%^%^CYAN%^over one ear to break up "
"the otherwise plain coloration of his fur.  His legs seem a little too short "
"for his body, making his gait seem more like a shuffle than a walk at times.  "
"He has a habit of tilting his head to the side, letting his long ears flop "
"about over his face in a %^MAGENTA%^co%^RED%^mic%^MAGENTA%^al %^CYAN%^"
"expression.  His eyes are the color of %^ORANGE%^fresh coffee%^CYAN%^, dark "
"brown and constantly filled with a mournful appearance, though this seems "
"caused more by the drooped shape of his face than the dog's disposition.  He "
"often seems content to simply flop down on the ground, ears splayed out to "
"either side as he peers up at the world around him, as his tail sometimes "
"lifts in a hopeful wag when someone approaches close by.  A little "
"%^ORANGE%^leather collar %^CYAN%^rests around his neck, studded with small "
"round pieces of %^BOLD%^%^WHITE%^palladium%^RESET%^%^CYAN%^.%^RESET%^");
}

void die(object ob) {
   tell_room(ETO,"The hound whimpers in fright and scampers away!");
   TO->remove();
}
