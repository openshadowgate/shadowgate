#include <std.h>
#include <daemons.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("ring");
   set_id(({ "ring","opalescent ring","blue ring","opalescent blue ring" }));
   set_short("%^BOLD%^%^WHITE%^an %^CYAN%^op%^BLUE%^a%^CYAN%^les%^WHITE%^c%^BLUE%^en%^CYAN%^t %^WHITE%^blue ring%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This ring is beautiful in its simplicity, "
"cut from a single piece of what appears to be %^RESET%^%^CYAN%^wa"
"%^RESET%^te%^CYAN%^r opal%^BOLD%^%^WHITE%^.  Its surface glistens and "
"flashes with a myriad of %^CYAN%^bl%^BLUE%^u%^CYAN%^e %^WHITE%^shades in "
"every hue imaginable.  The only interruption to its otherwise smooth and "
"plain cut, is the etching of a single %^BLUE%^c%^CYAN%^re%^WHITE%^st"
"%^CYAN%^in%^BLUE%^g %^WHITE%^wave upon its upper surface.%^RESET%^\n");
   set_weight(0);
   set_value(0);
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_size(2);
   set_ac(1);
   set_property("enchantment",-1);
   set_wear((:TO,"wear_fun":));
   set_property("death keep",1);
}

void init(){
   ::init();
   add_action("summon_fun","summon");
}

int wear_fun(){
    if((string)ETO->query_name() != "snog" && !avatarp(ETO)) {
      tell_object(ETO,"You can't wear that.");
      return 0;
    }
    tell_object(ETO,"%^BOLD%^%^WHITE%^You remember as you put on the "
"ring, that it is %^YELLOW%^<summon puppy> %^WHITE%^to call to your "
"little friend.%^RESET%^");
    TO->set_overallStatus(100);
    return 1;
}

int summon_fun(string str) {
    object ob;
    if(!str) {
      notify_fail("Summon what?");
      return 0;
    }
    if(str != "puppy") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if(!TO->query_worn()) {
      tell_object(TP,"You should try wearing the ring first.");
      return 1;
    }
    if(present("snogpuppy")) {
      tell_object(TP,"That is already here!");
      return 1;
    }
    tell_room(EETO,"%^BOLD%^%^CYAN%^"+TP->QCN+" %^BOLD%^%^CYAN%^calls out "
"and clicks "+TP->QP+" fingers, and a little puppy comes running, nearly "
"falling over its own feet in its haste!%^RESET%^",TP);
    tell_object(TP,"%^BOLD%^%^CYAN%^You call out for your puppy and click "
"your fingers, and he comes bounding up, nearly tripping over his big "
"feet in his haste!");
    ob=find_object_or_load("/d/avatars/nienne/puppy");
    ob->move(EETO);
    return 1;
}
