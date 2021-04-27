#include <std.h>
inherit WEAPONLESS;

void create() {
  ::create();
  set_name("selka");
  set_id(({"selka","prism","shadowy prism"}));
  set_short("%^BOLD%^%^BLACK%^A shadowy selka%^RESET%^");
  set_long((:TO,"long_desc":));
  set_race("selka");
  set_body_type("serpent");
  set_gender("neuter");
  set_size(1);
  set("aggressive",1);
  set_hd(4,2);
  set_level(1);
  set_class("fighter");
  set_mlevel("fighter",5);
  set_max_hp(20);
  set_hp(query_max_hp());
  set_exp(1);
  set_damage(1,2);
  set_attacks_num(1);
  set_base_damage_type("bludgeoning");
  set_ac(10);
  set_alignment(5);
  set_stats("intelligence",19);
  set_stats("wisdom",12);
  set_stats("strength",1);
  set_stats("charisma",11);
  set_stats("dexterity",19);
  set_stats("constitution",12);
  set_emotes(1,({"%^BLUE%^The shadowy prism skitters along through the air, like a feather tossed in a stormy gale.%^RESET%^","%^MAGENTA%^Constantly in motion, the hazy selka wobbles and spins like a top on its end.","%^GREEN%^The little selka plays across the ground, weaving like a drunk toddler.%^RESET%^"}),0);
}

void init(){
   ::init();
   add_action("lead_fun","lead");
   add_action("dismiss_fun","dismissme");
   add_action("emote_fun","selkaemote");
}

int lead_fun(string str) {
    if(!str) {
      notify_fail("Lead what?");
      return 0;
    }
    if(str != "selka" && str != "Selka") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != "aynetta" && !avatarp(TP)) {
      tell_object(TP,"It just tumbles around, paying you no heed.");
      return 1;
    }
    TP->add_follower(TO);
    tell_object(TP,query_cap_name()+" tumbles along after you.");
    return 1;
}

int dismiss_fun(string str) {
    if(!str) {
      notify_fail("Dismiss what?");
      return 0;
    }
    if(str != "selka" && str != "Selka") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if((string)TP->query_name() != "aynetta" && !avatarp(TP)) {
      tell_object(TP,"It just tumbles around, paying you no heed.");
      return 1;
    }
    force_me("emote winks out of existance!");
    TO->remove();
    return 1;
}

void receive_given_item(object obj){
   tell_object(TP,"The shadowy little selka can't seem to keep hold of it.");
   TO->force_me("drop all");
   return;
}

void die(object ob) {
   tell_room(ETO,"The selka winks out of existance!");
   TO->remove();
}

string long_desc() {
   if ((string)TP->query_name() == "aynetta" || avatarp(TP)) {
     return("%^RESET%^Created from the essence of the %^BOLD%^%^BLACK%^shadow plane"
"%^RESET%^, this small, murky, nearly %^CYAN%^insubstantial %^RESET%^creature "
"holds to a vague polyhedron shape.  Wisps of %^BLUE%^darkly hued%^RESET%^ "
"swirling energy twist and slither deep within and over its many surfaces, "
"giving it form and shape while drawing the %^BOLD%^%^WHITE%^lig%^YELLOW%^h"
"%^WHITE%^t %^RESET%^around it inward.  Constantly in motion, it wobbles and "
"spins like a top on its end.  Small enough to rest upon the palm of a child, "
"it could almost be missed but for its constant state of %^CYAN%^mo%^BOLD%^"
"v%^RESET%^%^CYAN%^eme%^BOLD%^n%^RESET%^%^CYAN%^t%^RESET%^."
"\n%^YELLOW%^Your commands are:%^RESET%^ lead, dismissme, selkaemote, duskgate "
"(set/open/close/location).");
   }
     return("%^RESET%^Created from the essence of the %^BOLD%^%^BLACK%^shadow plane"
"%^RESET%^, this small, murky, nearly %^CYAN%^insubstantial %^RESET%^creature "
"holds to a vague polyhedron shape.  Wisps of %^BLUE%^darkly hued%^RESET%^ "
"swirling energy twist and slither deep within and over its many surfaces, "
"giving it form and shape while drawing the %^BOLD%^%^WHITE%^lig%^YELLOW%^h"
"%^WHITE%^t %^RESET%^around it inward.  Constantly in motion, it wobbles and "
"spins like a top on its end.  Small enough to rest upon the palm of a child, "
"it could almost be missed but for its constant state of %^CYAN%^mo%^BOLD%^"
"v%^RESET%^%^CYAN%^eme%^BOLD%^n%^RESET%^%^CYAN%^t%^RESET%^.");
}

int emote_fun(string str) {
    if(!str) {
      notify_fail("What emote do you want the selka to send?");
      return 0;
    }
    if((string)TP->query_name() != "aynetta" && !avatarp(TP)) {
      notify_fail("The selka ignores you.");
      return 1;
    }
    tell_room(ETO,"The selka "+str+"");
    return 1;
}
