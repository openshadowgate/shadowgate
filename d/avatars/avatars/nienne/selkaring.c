#include <std.h>
inherit ARMOUR;

object ob;

void create(){
   ::create();
   set_name("scar");
   set_id(({ "scar","small scar" }));
   set_short("%^RESET%^%^RED%^a small scar%^RESET%^");
   set_long("This is a small, long-healed scar on the hand.\n");
   set_weight(0);
   set_value(0);
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_size(2);
   set_ac(1);
   set_property("enchantment",-1);
   set_wear((:TO,"wear_fun":));
   set_property("death keep",1);
   set_hidden(1);
}

int is_detectable() { return 0; }

void init(){
   ::init();
   add_action("summon_fun","summon");
}

int wear_fun(){
    if((string)TP->query_name() != "aynetta" && !avatarp(TP)) {
      tell_object(TP,"You can't wear that.");
      return 0;
    }
    TO->set_hidden(1);
    return 1;
}

int summon_fun(string str) {
    if(!str) {
      notify_fail("Summon what?");
      return 0;
    }
    if(str != "selka" && str != "Selka") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if(present("selka")) {
      tell_object(TP,"That is already here!");
      return 1;
    }
    if(!TO->query_worn()) {
    tell_object(TP,"You need to have the scar on you.");
    return 1;
    }
    tell_room(EETO,"%^RESET%^%^BLUE%^"+TP->QCN+" calls quietly to something "
"unseen, and from a scar on her hand emerges a small, %^BOLD%^%^BLACK%^"
"shadowy %^RESET%^%^BLUE%^object.%^RESET%^",TP);
    tell_object(TP,"%^BLUE%^You call quietly to the selka, and it emerges "
"from the scar on your hand.%^RESET%^");
    ob=find_object_or_load("/d/avatars/nienne/selka");
    ob->move(EETO);
    return 1;
}
