#include <std.h>
inherit WEAPONLESS;

string location;

void create() {
  ::create();
  set_name("dragonet");
  set_id(({"dragonet","tiny dragonet","Dragonet"}));
  set_short("%^RESET%^%^GREEN%^A tiny dr%^BOLD%^a%^RESET%^%^GREEN%^go%^BOLD%^n%^RESET%^%^GREEN%^et%^RESET%^");
  set_long((:TO,"long_desc":));
  set_race("draconian");
  set_body_type("reptile");
  set_gender("neuter");
  set_size(1);
  set("aggressive",5);
  set_hd(4,2);
  set_level(1);
  set_class("fighter");
  set_mlevel("fighter",5);
  set_max_hp(100);
  set_hp(query_max_hp());
  set_exp(20);
  set_damage(1,8);
  set_attacks_num(3);
  set_base_damage_type("slashing");
  add_limb("claws","left foreleg",0,0,0);
  set_attack_limbs(({"right forepaw","left forepaw","teeth"}));
  set_ac(10);
  set_alignment(9);
  set_spoken("wizish");
  set_stats("intelligence",19);
  set_stats("wisdom",14);
  set_stats("strength",1);
  set_stats("charisma",11);
  set_stats("dexterity",19);
  set_stats("constitution",12);
  set_emotes(1,({"%^WHITE%^%^BOLD%^The tiny dragonet scratches its %^RESET%^%^GREEN%^sca%^BOLD%^l%^RESET%^%^GREEN%^y%^BOLD%^%^WHITE%^ neck with one clawed foot.%^RESET%^",
"%^WHITE%^%^BOLD%^The tiny dragonet peers around with its sparkling %^BOLD%^%^BLUE%^sa%^CYAN%^p%^WHITE%^ph%^CYAN%^i%^BLUE%^re%^WHITE%^ eyes.%^RESET%^",
"%^WHITE%^%^BOLD%^The tiny dragonet stretches its brilliant %^RED%^%^BOLD%^s%^RESET%^%^RED%^c%^BOLD%^a%^RESET%^%^RED%^r%^BOLD%^l%^RESET%^%^RED%^e%^BOLD%^t%^WHITE%^ wings.%^RESET%^",
"%^WHITE%^%^BOLD%^The tiny dragonet bobs its head, giving a few odd %^YELLOW%^chirps%^WHITE%^ and %^CYAN%^whistles%^WHITE%^.%^RESET%^"}), 0);
}

void init(){
   ::init();
   add_action("call_fun","callto");
   add_action("sendto_fun","sendto");
   add_action("lead_fun","lead");
   add_action("dismiss_fun","dismissme");
}

int call_fun(string str) {
    if(!str) {
      notify_fail("Callto what?");
      return 0;
    }
    if(str != "dragonet" && str != "Dragonet") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() == "amberly" || avatarp(TP)) {
    force_me("emote hops across at "+TP->QCN+"'s call and climbs up on "+TP->QP+" shoulder.");
    return 1;
    }
    force_me("emote glares at "+TP->QCN+", obviously unimpressed by "+TP->QP+" attempts to call it over.");
    return 1;
}

int sendto_fun(string str) {
   object *inven;
   inven = all_inventory(TO);
    if((string)TP->query_name() != "amberly" && !avatarp(TP)) {
      force_me("emote refuses to deliver anything for "+TPQCN+".");
      return 1;
    }
    if(!str) {
      notify_fail("Send a message to who?");
      return 0;
    }
    if(sizeof(all_inventory(TO)) < 1){
      force_me("emote holds out one clawed foot expectantly, as if waiting for something.");
      return 1;
    }
    if(!find_player(""+str+"")) {
      force_me("emote chirps once and disappears.");
      force_me("emote reappears beside "+TPQCN+" again with the item still in its claw.");
      tell_room(ETO,"The dragonet chirps something incomprehensible to "+TPQCN+".",TP);
      tell_object(TP,"%^RED%^%^BOLD%^A voice that could only be the dragonet's echoes in your head:%^WHITE%^ I couldn't find the person you requested.%^RESET%^\n");
      force_me("give "+inven[0]->query_name()+" to "+TP->query_name()+"");
      return 1;
    }
    force_me("emote chirps once and disappears.");
    location = base_name(environment(find_player(""+str+"")));
    move(location);
    force_me("emote appears in a puff of smoke with something in its claws.");
    force_me("give "+inven[0]->query_name()+" to "+str+"");
    force_me("emote disappears again with a flap of its %^RED%^%^BOLD%^s%^RESET%^%^RED%^c%^BOLD%^a%^RESET%^%^RED%^r%^BOLD%^l%^RESET%^%^RED%^e%^BOLD%^t%^RESET%^ wings.");
    location = base_name(ETP);
    move(location);
    force_me("emote reappears beside "+TPQCN+" again with a cheerful whistle.");
    return 1;
}

int lead_fun(string str) {
    if(!str) {
      notify_fail("Lead what?");
      return 0;
    }
    if(str != "dragonet" && str != "Dragonet") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != "amberly" && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
    }
    TP->add_follower(TO);
    tell_object(TP,query_cap_name()+" is now following you.");
    return 1;
}

int dismiss_fun(string str) {
   object *inven;
   inven = all_inventory(TO);
    if(!str) {
      notify_fail("Dismiss what?");
      return 0;
    }
    if(str != "dragonet" && str != "Dragonet") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != "amberly" && !avatarp(TP)) {
      force_me("emote pointedly ignores "+TPQCN+".");
      return 1;
   }
    if (sizeof(inven) > 0) {
      tell_room(ETO,"The dragonet drops what it is carrying.");
      TO->force_me("drop "+inven[0]->query_name());
    }
    force_me("emote disappears in a puff of %^GREEN%^g%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^e%^RESET%^%^GREEN%^n%^RESET%^ smoke!");
    TO->remove();
    return 1;
}

void receive_given_item(object obj){
   object *inven;
   inven = all_inventory(TO);
   if (sizeof(inven) > 1) {
     tell_object(TP,"The dragonet can't seem to carry more than one item at a time... "
"It tries to keep hold of both items, but drops one.");
     TO->force_me("drop "+inven[random(2)]->query_name());
     return;
   }
}

int kill_ob(object target, int i){
    ::kill_ob(target,i);
    if((string)target->query_name() != "dragonet" && (string)target->query_name() != "Dragonet") {
      notify_fail("Nothing happens.");
      return 0;
    }
    force_me("emote turns its %^BOLD%^%^BLUE%^a%^CYAN%^l%^WHITE%^e%^CYAN%^r%^BLUE%^t%^RESET%^ gaze upon "+TPQCN+".");
    TP->force_me("emote screams and clutches the sides of "+TP->QP+" head.");
    TP->add_attacker();
    TP->do_damage("head",random(10));
    TP->remove_attacker(TO);
    TO->remove_attacker(TP);
    TP->force_me("emote falls to "+TP->QP+" knees.");
    TP->set_paralyzed(10,"A throbbing ache fills your head, you struggle to shake free of it.");
    tell_object(TP,"%^RED%^%^BOLD%^A voice that could only be the dragonet's echoes in your head:%^WHITE%^ I'd suggest you think twice before trying something like that, mortal.%^RESET%^\n");
}

string long_desc() {
   if ((string)TP->query_name() == "amberly" || avatarp(TP)) {
     return("%^ORANGE%^This creature resembles a miniature dragon, only about two feet long from nose to "
"tail-tip. It has %^RESET%^%^GREEN%^sca%^BOLD%^l%^RESET%^%^GREEN%^y "
"gr%^BOLD%^e%^RESET%^%^GREEN%^en%^ORANGE%^ reptilian skin, with a comparitively large wingspan of a brilliant "
"%^RED%^%^BOLD%^s%^RESET%^%^RED%^c%^BOLD%^a%^RESET%^%^RED%^r%^BOLD%^l%^RESET%^%^RED%^e%^BOLD%^t%^RESET%^%^ORANGE%^ hue. "
"Its four clawed feet scratch upon the ground as it walks, flicking its long tail from side to side. Its "
"eyes are a sparkling %^BOLD%^%^BLUE%^sa%^CYAN%^p%^WHITE%^ph%^CYAN%^i%^BLUE%^re%^RESET%^%^ORANGE%^%^ "
"shade, glittering with intelligence.%^RESET%^\n%^YELLOW%^Your commands are: %^WHITE%^callto%^YELLOW%^, "
"%^WHITE%^sendto%^YELLOW%^, %^WHITE%^lead%^YELLOW%^ and %^WHITE%^dismissme%^YELLOW%^.%^RESET%^");
   }
   return("%^ORANGE%^This creature resembles a miniature dragon, only about two feet long from nose to "
"tail-tip. It has %^RESET%^%^GREEN%^sca%^BOLD%^l%^RESET%^%^GREEN%^y "
"gr%^BOLD%^e%^RESET%^%^GREEN%^en%^ORANGE%^ reptilian skin, with a comparitively large wingspan of a brilliant "
"%^RED%^%^BOLD%^s%^RESET%^%^RED%^c%^BOLD%^a%^RESET%^%^RED%^r%^BOLD%^l%^RESET%^%^RED%^e%^BOLD%^t%^RESET%^%^ORANGE%^ hue. "
"Its four clawed feet scratch upon the ground as it walks, flicking its long tail from side to side. Its "
"eyes are a sparkling %^BOLD%^%^BLUE%^sa%^CYAN%^p%^WHITE%^ph%^CYAN%^i%^BLUE%^re%^RESET%^%^ORANGE%^%^ "
"shade, glittering with intelligence.%^RESET%^");
}
