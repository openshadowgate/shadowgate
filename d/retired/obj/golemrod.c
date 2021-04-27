#include <std.h>
inherit ARMOUR;

int tracker;

void create() {
    ::create();
    set_name("mithril rod");
    set_id(({ "rod","mithril rod","runed rod","runed mithril rod","rod of golem control" }));
    set_short("%^BOLD%^%^WHITE%^Rod of %^RESET%^%^RED%^G%^ORANGE%^o%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^e%^RED%^m %^BOLD%^%^WHITE%^Control%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^a %^BLUE%^r%^CYAN%^u%^BLUE%^n%^CYAN%^e%^BLUE%^d %^WHITE%^mithril rod%^RESET%^");
    set_long("%^YELLOW%^This plain rod consists of a single spire of %^WHITE%^mith"
"%^CYAN%^r%^WHITE%^il%^YELLOW%^, blunted at the lower end by a polished knob of the same "
"metal.  At the upper end is a single flawless %^RESET%^crystal%^YELLOW%^, embedded in the "
"rod by metal claws that grip it securely.  No hint of color highlights the gemstone, "
"leaving it completely %^BLACK%^toneless %^YELLOW%^and %^RESET%^translucent%^YELLOW%^.  "
"Etched into its surface are what appear to be %^BOLD%^%^BLUE%^a%^CYAN%^r%^BLUE%^cane "
"ru%^CYAN%^ne%^BLUE%^s%^YELLOW%^, marking patterns up the length of the "
"instrument.  A hoop of %^RESET%^%^ORANGE%^leather %^YELLOW%^has been secured "
"around one end of the rod and feeds up to a longer leather thong that could "
"be looped around one's neck, keeping the rod in easy reach.%^RESET%^\n");
    set("read","%^BOLD%^%^WHITE%^The runes resolve themselves into two "
"words before your eyes:\n\n%^BOLD%^%^WHITE%^-%^YELLOW%^summon golem%^WHITE%^-%^RESET%^");
    set_language("wizish");
    set_value(1602);
    set_wear((:TO,"wield_fun":));
    set_type("ring");
    set_limbs(({"neck"}));
    set_weight(2);
}

void init() {
    ::init();
    add_action("my_conjure","summon");
}

int wield_fun() {
   if(!ETO->is_class("mage") && !avatarp(ETO)) {
     tell_object(ETO,"You're not sure quite how to use such an item effectively.");
     return 0;
   }
   if((int)ETO->query_class_level("mage") < 21) {
     tell_object(ETO,"You're not sure quite how to use such an item effectively.");
     return 0;
   }
   return 1;
}

int my_conjure(string str) {
   object ob;
   if(!str) {
     tell_object(TP,"Summon what?");
     return 0;
   }
   if(str != "golem") {
     tell_object(TP,"You can't summon that.");
     return 0;
   }
   if(tracker > time()) {
     tell_object(TP,"The golem is still regenerating.");
     return 0;
   }
   tracker = time() + 28800;
   tell_room(ETP,"%^BOLD%^%^WHITE%^The runes on the mithril rod %^YELLOW%^flare %^WHITE%^"
"to life, mirrored by the translucent crystal that takes on a %^CYAN%^brilliant azure glow"
"%^WHITE%^. A massive form begins to solidify before you.%^RESET%^");
   ob=new("/d/retired/obj/golem");
   ob->move(ETP);
   ob->set_owner((string)TP->query_name());
   return 1;
}

void reset_timer() {
   tracker = time();
}
