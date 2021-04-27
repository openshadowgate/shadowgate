#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("gauntlets");
   set_id(({"gauntlets","loviatar gauntlets","nails","nails of black","black nails","black gauntlets","nails of the black"}));
   set_short("%^BLACK%^%^BOLD%^N%^RED%^a%^BLACK%^ils of the Bl%^RED%^a%^BLACK%^ck%^RESET%^");
   set_obvious_short("%^RED%^%^BOLD%^crimson-lined %^BLACK%^black gauntlets%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^Some smooth, %^BLACK%^%^BOLD%^blackened %^WHITE%^metal has been smithed to form "
"this pair of gauntlets, possibly steel or titanium by its appearance.  The metal has been carefully polished, and forms overlapping plates that, while allowing glimpses of the lining beneath, would protect the hands "
"quite effectively from harm.  Each finger comes to a sharpened point at the tip, like the talon of a predator "
"tinted with %^RESET%^%^RED%^dull crimson%^WHITE%^%^BOLD%^.  They are lined with soft cloth of a%^RED%^ "
"striking scarlet shade%^WHITE%^, which shows glimpses of red with the movement of the gauntlets.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^These gauntlets are rarely crafted, only gifted to members of the church of "
"Loviatar.  It is said that when they are worn by a truly blessed follower, that the wearer can bestow the "
"very suffering and misfortunes of the Maiden by their touch alone.");
   set_property("lore difficulty",13);
   set_weight(4);
   set_value(2700);
   set_ac(1);
   set_property("enchantment",2);
   set_type("chain");
   set_limbs(({"right hand","left hand"}));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   if((string)ETO->query_diety() != "loviatar") {
     tell_object(ETO,"%^BLACK%^%^BOLD%^A sharp sensation of pain runs through your fingertips, as you attempt "
"to wear the gauntlets!%^RESET%^");
     tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" tries to force the gauntlets over "+ETO->QP+" hands, and then "
"jerks away in pain.%^RESET%^",ETO);
     set_property("magic",1);
     ETO->do_damage("torso",random(20)+20);
     ETO->add_attacker(TO);
     ETO->continue_attack();
     ETO->remove_attacker(TO);
     remove_property("magic");
     return 0;
   }
   tell_object(ETO,"%^BLACK%^%^BOLD%^The gauntlets fit smoothly over your hands.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" slides the gauntlets over "+ETO->QP+" hands with a confident "
"smile.%^RESET%^",ETO);
   ETO->set_property("magic resistance",5);
   ETO->add_attack_bonus(1);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^The %^RED%^soft cloth lining %^BLACK%^slides softly over your hands as "
"you remove the gauntlets.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" easily slips "+ETO->QP+" hands free of the gauntlets."
"%^RESET%^",ETO);
   ETO->set_property("magic resistance",-5);
   ETO->add_attack_bonus(-1);
   return 1;
}

void init() {
   ::init();
   add_action("rush_fun","rush");
}

int rush_fun(string str) {
   object ob;

   if(!str) return notify_fail("You need to specify a target!\n");

   if (TP->query_bound() || TP->query_tripped()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }

   if(!TP->is_class("fighter")) return notify_fail("You haven't the skill to try this attack!\n");
   if(!(ob = present(str,ETP))) return notify_fail("Your target is not in range!\n");
   if(ob == TP) return notify_fail("What are you, two people?\n");

   if(!TP->ok_to_kill(ob)) {
      notify_fail("Supernatural forces prevent your attack.\n");
      return 0;
   }

   if(ob->query_property("no rush")) {
      notify_fail("This being would never let its defense down enough for you to do that!\n");
      return 0;
   }

   if(pointerp(TP->query_property("rushed")))
     if(member_array(ob,TP->query_property("rushed") ) != -1)
       return notify_fail("Your target may still be ready for that attack!\n");

   if(!TP->query_wielded()) return notify_fail("Rushing is useless without weapons!\n");

   tell_room(ETP,"%^BLACK%^%^BOLD%^A %^RESET%^%^RED%^dull crimson glow %^BLACK%^%^BOLD%^appears around "
+TP->QCN+"'s weapon, as "+TP->QS+" rushes at "+ob->query_name()+"!%^RESET%^",TP);
   tell_object(TP,"%^BLACK%^%^BOLD%^A %^RESET%^%^RED%^dull crimson glow %^BLACK%^%^BOLD%^appears around your "
"weapon, as you rush at "+ob->query_name()+"!%^RESET%^");
   return 0;
}
