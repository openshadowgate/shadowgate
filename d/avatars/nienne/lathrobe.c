// modified robes of the archmagi
#include <std.h>
inherit PARMOUR;

void create() {
   ::create();
   set_name("robe");
   set_id(({"robe","sunrise robe","mantle","mantle of the sun","mantle of the sun resplendant","sunrise-hued robe","sunrise hued robe"}));
   set_short("%^RESET%^%^RED%^Ma%^ORANGE%^nt%^RED%^le of the %^MAGENTA%^Su%^ORANGE%^n R%^YELLOW%^es%^MAGENTA%^"
"pl%^YELLOW%^en%^RESET%^%^ORANGE%^da%^MAGENTA%^nt%^RESET%^");
   set_obvious_short("%^RESET%^%^RED%^a s%^ORANGE%^un%^YELLOW%^ri%^MAGENTA%^se%^RED%^-%^MAGENTA%^hu%^YELLOW%^ed"
" %^RESET%^%^ORANGE%^ro%^RED%^be%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^This robe is absolutely stunning to behold.  It is formed in several layers, all "
"made of soft silks that rest gently against the skin.  The outer layer is %^RESET%^%^WHITE%^transparent"
"%^BOLD%^ with a high collar and long, flowing sleeves, and is decorated with sparkling hints that catch the "
"light in a %^RESET%^%^MAGENTA%^m%^RED%^y%^ORANGE%^r%^YELLOW%^i%^MAGENTA%^a%^RED%^d%^WHITE%^ of colors.  The "
"layers beneath are each of a different hue, from light to dark reflecting the colors of a %^RESET%^%^RED%^sp"
"%^ORANGE%^ri%^YELLOW%^ng %^MAGENTA%^s%^YELLOW%^un%^RESET%^%^ORANGE%^ri%^RED%^se%^WHITE%^%^BOLD%^.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^These distinctive robes are similar to the ceremonial robes of the Lathanderite "
"faith.  Often lay followers such as magi create such robes in honor of their Lord, that they too might show "
"his light to all they meet, quite clearly.  Such robes are often also heavily enchanted, as the followers of "
"the Dawnlord have no qualms about showing such elaborate displays, and so such robes are highly prized by "
"many within the faith.");
   set_property("lore difficulty",13);
   set_size(2);
   set_weight(5);
   set_type("clothing");
   set_property("enchantment",3);
   set_limbs(({"torso"}));
   set_max_internal_encumbrance(35);
   set_value(10000);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set("chabonus",2);
   set("intbonus",1);
}

int wear_fun() {
   if((int)ETO->query_highest_level() < 30) {
     tell_object(ETO,"%^RED%^%^BOLD%^The robes do not fit you!");
     return 0;
   }
   if((string)ETO->query_diety() != "lathander") {
     tell_object(ETO,"%^RED%^%^BOLD%^The robes do not fit you!");
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^You are wrapped in the %^RESET%^%^RED%^warmth%^WHITE%^%^BOLD%^ of the "
"%^RESET%^%^ORANGE%^d%^YELLOW%^aw%^RESET%^%^ORANGE%^n %^BOLD%^%^WHITE%^as you wear the robe.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+"'s robe sparkles %^RESET%^%^RED%^br%^ORANGE%^il%^YELLOW%^lia"
"%^RESET%^%^ORANGE%^nt%^RED%^ly%^WHITE%^%^BOLD%^ as "+ETO->QS+" wraps it around "+ETO->QO+"self.%^RESET%^",ETO);
   ETO->set_property("magic resistance",15);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel the %^RESET%^%^RED%^warmth%^WHITE%^%^BOLD%^ of the "
"%^RESET%^%^ORANGE%^su%^YELLOW%^nri%^RESET%^%^ORANGE%^se%^WHITE%^%^BOLD%^ slip away from you.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+"'s robes lose their sparkle as "+ETO->QS+" removes them."
"%^RESET%^",ETO);
   ETO->set_property("magic resistance",-15);
   return 1;
}

void init(){
   ::init();
   add_action("check_put","put");
}

int check_put(string str){
   if(!query_worn()) {
     notify_fail("You must be wearing the robes to place something in their pockets.\n");
     return 0;
   }
   if(query_worn()) return ::put_into();
}
