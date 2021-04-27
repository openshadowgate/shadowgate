#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int tracker;

void create() {
   ::create();
   set_name("ring");
   set_id(({"ring","istishia ring","raindrop ring","water opal ring","water-opal ring"}));
   set_short("%^BOLD%^%^BLUE%^Ra%^CYAN%^i%^BLUE%^ndr%^RESET%^%^CYAN%^o%^BLUE%^%^BOLD%^p Ri%^CYAN%^n%^BLUE%^g%^RESET%^");
   set_obvious_short("%^BLUE%^%^BOLD%^w%^CYAN%^at%^WHITE%^e%^CYAN%^r-%^RESET%^%^CYAN%^op%^BLUE%^a%^BOLD%^l r%^CYAN%^i%^RESET%^%^CYAN%^ng%^RESET%^");
   set_long("%^CYAN%^This piece of jewelry consists of a single smooth band, crafted from solid%^BLUE%^ "
"wa%^BOLD%^te%^CYAN%^r%^BLUE%^ op%^RESET%^%^BLUE%^al%^CYAN%^.  Etched into the upper surface of the ring is "
"a slender mark, that forms the simple outline of a water droplet.  The %^BOLD%^spa%^WHITE%^r%^CYAN%^kling"
"%^RESET%^%^CYAN%^, multi-hued surface of the ring reflects its surroundings in every shade of%^BLUE%^"
" b%^BOLD%^l%^RESET%^%^CYAN%^u%^BOLD%^e%^RESET%^%^CYAN%^ imaginable, and several more besides, constantly "
"shifting as if liquid moved within the ring itself.  Upon the underside, swirling letters have been carefully "
"etched.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Rumours abound concerning this jewelry and the clergy of the Mother of Water.  "
"The most common tells that pure droplets of the rain are captured by the most blessed of Istishia's "
"priests, and imbued within the ring. This lets the Lady's faithful may carry the waters with them wherever "
"they go, and feel the fresh touch of her blessings upon themselves in times of need.");
   set_property("lore difficulty",7);
   set("read","%^RESET%^\n\n%^BOLD%^%^BLUE%^Those true to the tides, in times of strife\n"
"%^BOLD%^%^CYAN%^Invoke the waters%^BLUE%^ to give you life%^RESET%^\n\n");
   set("language","common");
   set_weight(2);
   set_value(0);
   set_ac(0);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_limbs(({"right hand","left hand"}));
}

int wear_fun(){
   if((string)ETO->query_diety() != "istishia" && !avatarp(TP)) {
     tell_object(ETO,"%^BOLD%^%^BLUE%^The ring slips through your fingers like mist!%^RESET%^");
     return 0;
   }
   tell_object(ETO,"%^BOLD%^%^BLUE%^The ring is cool to the touch as it slips over your finger.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+" slides the glittering ring over a finger.%^RESET%^",ETO);
   ETO->set_property("magic resistance",5);
   return 1;
}

int remove_fun(){
   tell_object(ETO,"%^BOLD%^%^BLUE%^You feel the protection of the waters recede as you remove the ring.%^RESET%^");
   ETO->set_property("magic resistance",-5);
   return 1;
}

void init() {
   ::init();
   add_action("healz","invoke");
}

int healz(string str){
   int tmp;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     notify_fail("You need to be wearing the ring.");
     return 0;
   }
   if(!str) {
     notify_fail("Try to <invoke the waters>.");
     return 0;
   }
   if(str != "the waters") {
     notify_fail("Try to <invoke the waters>.");
     return 0;
   }
   if(tracker > time()) {
     tell_object(TP,"You've already used the power of the ring today.");
     return 1;
   }
   tracker = time() + 28800;
   tell_object(ETO,"%^RESET%^%^BLUE%^You offer a prayer to the waters, and from within the ring on your hand, "
"tendrils of %^RESET%^%^CYAN%^mi%^RESET%^s%^CYAN%^t %^BLUE%^reach out and drift about you.\n%^CYAN%^As the "
"fine droplets fall upon your skin, you feel cleansed and invigorated!%^RESET%^");
   tell_room(EETO,"%^RESET%^%^BLUE%^"+ETO->QCN+" closes "+ETO->QP+" eyes and murmurs a few sort words, and "
"from within the ring on "+ETO->QP+" hand, tendrils of %^RESET%^%^CYAN%^mi%^RESET%^s%^CYAN%^t %^BLUE%^reach "
"out and drift about "+ETO->QO+".\n%^CYAN%^The fine droplets fall upon "+ETO->QP+" skin in a glittering sheen, "
"and "+ETO->QS+" looks refreshed!%^RESET%^",ETO);
   if((int)ETO->query_hp() < (int)ETO->query_max_hp())
     ETO->do_damage(ETO->return_target_limb(),(int)ETO->query_hp() - ((int)ETO->query_max_hp()));
   ETO->remove_paralyzed();
   ETO->add_quenched(10000);
   ETO->set_poisoning((-1)*(int)ETO->query_poisoning());
   ETO->add_intox(-1*(int)ETO->query_intox());
   if(ETO->query_condition() < ETO->query_max_stamina()) {
     tmp = 2 * ((int)ETO->query_max_stamina() - (int)ETO->query_condition());
     if(tmp > 25) tmp = 25;
     ETO->use_stamina(-1*tmp);
   }
   return 1;
}
