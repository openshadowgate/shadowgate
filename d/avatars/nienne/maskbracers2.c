#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
   ::create();
   set_name("chalcedony bracers");
   set_id(({"bracers","cuffs","chalcedony bracers","gray bracers","grey bracers","cuffs of twilight whispers"}));
   set_short("%^BOLD%^%^BLACK%^s%^RESET%^m%^BOLD%^%^BLACK%^ok%^RESET%^y%^BOLD%^%^BLACK%^-gr%^RESET%^e%^BOLD%^%^BLACK%^y chalcedony bracers%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^s%^RESET%^m%^BOLD%^%^BLACK%^ok%^RESET%^y%^BOLD%^%^BLACK%^-gr%^RESET%^e%^BOLD%^%^BLACK%^y chalcedony bracers%^RESET%^");
   set_long("These unique-looking bracers have been carved from solid pieces of "
"%^BOLD%^%^BLACK%^grey ch%^RESET%^a%^BOLD%^%^BLACK%^lcedony%^RESET%^ - a smoky-gray stone "
"that resembles cloudy glass. The surfaces are %^MAGENTA%^smooth %^RESET%^and absolutely "
"%^BOLD%^%^CYAN%^flawless%^RESET%^, meeting upon the underside with clasps that are so "
"skillfully made as to be invisible when closed. Along the upper surface of each, "
"%^CYAN%^elaborate %^RESET%^runes of an unknown language have been etched into the stone "
"in delicate strokes, each lined with %^ORANGE%^glitte%^BOLD%^r%^RESET%^%^ORANGE%^ing "
"gold%^RESET%^. They are certainly %^GREEN%^beautiful%^RESET%^, though of such unique "
"appearance that you couldn't begin to imagine who may have crafted them.\n");
   set_ac(2);
   set_size(2);
   set_value(1350);
   set_lore("%^BOLD%^%^WHITE%^The origin of these bracers is still undiscovered. The last "
"known person to have owned them was a maskarran assassin known as around the Tharisian "
"area as the %^BLACK%^Shadowdancer%^WHITE%^. Her true identity was never revealed, but "
"rumors held that she was actually able to become one with the shadows, using them to "
"find and slay her targets before they even knew she was present. No word of further "
"victims to her has been heard in several years, leading many people to believe that she "
"finally met her demise.%^RESET%^\n");
   set_property("lore difficulty",25);
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int check(){
   ::check();
   if((string)ETO->query_diety() != "mask" && !avatarp(ETO)) {
     tell_object(ETO,"%^RED%^The bracers don't seem to fit you.%^RESET%^");
     tell_room(EETO,"%^RED%^The bracers don't seem to fit "+ETO->QCN+".%^RESET%^",ETO);
     return 0;
   }
   tell_room(EETO,"%^BOLD%^%^BLACK%^The "
"%^RESET%^%^ORANGE%^gol%^BOLD%^d%^RESET%^%^ORANGE%^en %^BOLD%^%^BLACK%^runes come to life "
"as "+ETO->QCN+" fits the bracers on, and they become nothing more than armguards of "
"%^RESET%^shadow%^BOLD%^%^BLACK%^.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^The "
"%^RESET%^%^ORANGE%^gol%^BOLD%^d%^RESET%^%^ORANGE%^en %^BOLD%^%^BLACK%^runes come to life "
"as you fit the bracers on, and they become nothing more than armguards of "
"%^RESET%^shadow%^BOLD%^%^BLACK%^.%^RESET%^");
   TO->set_property("enchantment",5);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   ETO->set_property("magic resistance",10);
   ETO->add_saving_bonus("all",1);
   TO->set_short("%^BOLD%^%^BLACK%^Cuffs of Tw%^RESET%^i%^BOLD%^%^BLACK%^li%^RESET%^g%^BOLD%^%^BLACK%^ht Whi%^RESET%^s%^BOLD%^%^BLACK%^pers%^RESET%^");
   TO->set_obvious_short("%^BOLD%^%^BLACK%^sh%^RESET%^a%^BOLD%^%^BLACK%^dow%^RESET%^y%^BOLD%^%^BLACK%^ gr%^RESET%^e%^BOLD%^%^BLACK%^y bracers%^RESET%^");
   TO->set_long("These bracers are hard to discern from the air around them, having the "
"substance and consistancy of pure %^BLUE%^haze %^RESET%^and "
"%^BOLD%^%^BLACK%^sha%^RESET%^d%^BOLD%^%^BLACK%^ow%^RESET%^. Somehow they remain drifting "
"around the wrists, like a cloud of mist wrapping each arm. Within the "
"%^BOLD%^%^BLACK%^haze%^RESET%^, along the upper surface of each, %^CYAN%^elaborate "
"%^RESET%^runes of an unknown language seem to carve strokes through the mist, each in "
"%^ORANGE%^spar%^BOLD%^k%^RESET%^%^ORANGE%^ling gold%^RESET%^. They are certainly "
"%^GREEN%^beautiful%^RESET%^ in their own strange, ethereal way.\n");
   return 1;
}

int remove_fun(){
  tell_room(EETO,"%^BOLD%^%^BLACK%^The "
"%^RESET%^%^ORANGE%^gol%^BOLD%^d%^RESET%^%^ORANGE%^en %^BOLD%^%^BLACK%^runes flicker and "
"die as the %^RESET%^shadowy %^BOLD%^%^BLACK%^bracers once again become inert "
"stone.%^RESET%^");
   ETO->set_property("magic resistance",-10);
   ETO->add_saving_bonus("all",(-1));
   TO->remove_property("enchantment");
   TO->set_short("%^BOLD%^%^BLACK%^s%^RESET%^m%^BOLD%^%^BLACK%^ok%^RESET%^y%^BOLD%^%^BLACK%^-gr%^RESET%^e%^BOLD%^%^BLACK%^y chalcedony bracers%^RESET%^");
   TO->set_obvious_short("%^BOLD%^%^BLACK%^s%^RESET%^m%^BOLD%^%^BLACK%^ok%^RESET%^y%^BOLD%^%^BLACK%^-gr%^RESET%^e%^BOLD%^%^BLACK%^y chalcedony bracers%^RESET%^");
   TO->set_long("These unique-looking bracers have been carved from solid pieces of "
"%^BOLD%^%^BLACK%^grey ch%^RESET%^a%^BOLD%^%^BLACK%^lcedony%^RESET%^ - a smoky-gray stone "
"that resembles cloudy glass. The surfaces are %^MAGENTA%^smooth %^RESET%^and absolutely "
"%^BOLD%^%^CYAN%^flawless%^RESET%^, meeting upon the underside with clasps that are so "
"skillfully made as to be invisible when closed. Along the upper surface of each, "
"%^CYAN%^elaborate %^RESET%^runes of an unknown language have been etched into the stone "
"in delicate strokes, each lined with %^ORANGE%^glitte%^BOLD%^r%^RESET%^%^ORANGE%^ing "
"gold%^RESET%^. They are certainly %^GREEN%^beautiful%^RESET%^, though of such unique "
"appearance that you couldn't begin to imagine who may have crafted them.\n");
   return 1;
}

int struck_fun(int damage, object what, object target) {
   if (!random(2)) {
     tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^ORANGE%^gol%^BOLD%^d%^RESET%^%^ORANGE%^en"
" %^BOLD%^%^BLACK%^runes on your bracers flare with light, and your entire body becomes "
"%^RESET%^shadowy %^BOLD%^%^BLACK%^and wraith-like, as "+target->QCN+"'s blow passes "
"right through you!%^RESET%^");
     tell_object(target,"%^BOLD%^%^BLACK%^The "
"%^RESET%^%^ORANGE%^gol%^BOLD%^d%^RESET%^%^ORANGE%^en %^BOLD%^%^BLACK%^runes on "+ETO->QCN+ "'s bracers flare with light, and "+ETO->QP+" entire body becomes %^RESET%^shadowy "
"%^BOLD%^%^BLACK%^and wraith-like, as your blow passes right through "
+ETO->QO+"!%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^BLACK%^%^BOLD%^%^BLACK%^The "
"%^RESET%^%^ORANGE%^gol%^BOLD%^d%^RESET%^%^ORANGE%^en %^BOLD%^%^BLACK%^runes on "+ETO->QCN+ "'s bracers flare with light, and "+ETO->QP+" entire body becomes %^RESET%^shadowy "
"%^BOLD%^%^BLACK%^and wraith-like, as "+target->QCN+"'s blow passes right through "
+ETO->QO+"!%^RESET%^",({ETO,target}));
     return (-1)*damage;
   }
   return 1;
}
