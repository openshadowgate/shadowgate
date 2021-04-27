#include <std.h>
inherit ARMOUR;

int OWNED,tracker;
string owner;

void create() {
   ::create();
   set_name("%^WHITE%^%^BOLD%^silvery anklet%^RESET%^");
   set_id(({"anklet","silver anklet","silvery anklet","fortunes charm","fortune's charm","Fortune's Charm","charm","Charm","Anklet"}));
   set_short("%^WHITE%^%^BOLD%^For%^BLUE%^t%^WHITE%^une's Cha%^BLUE%^r%^WHITE%^m%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^si%^RESET%^%^WHITE%^lv%^BOLD%^er%^RESET%^%^WHITE%^y a%^BOLD%^nk%^RESET%^%^WHITE%^le%^BOLD%^t%^RESET%^");
   set_long("%^GREEN%^This slender anklet is formed of a line of bright %^WHITE%^%^BOLD%^silvery "
"%^RESET%^%^GREEN%^links that glitter and sparkle.  Thin %^WHITE%^%^BOLD%^silver%^RESET%^%^GREEN%^ disks "
"hang from the chain links, chiming lightly with the movements of the wearer.  The largest disk is "
"engraved upon the underside, with the image of a beautiful human woman winking at you.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Only whispers of gossip have ever been heard concerning this anklet.  Some "
"claim that it was touched by Lady Luck herself, so that the one gifted with the fortune of wearing it "
"would feel whatever blessing suited her whim at the time.");
   set_property("lore difficulty",13);
   set_limbs(({"left leg"}));
   set_weight(2);
   set_value(0);
   set_size(2);
   set_ac(0);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   if(!((int)TP->query_alignment() % 3)) {
     notify_fail("The anklet doesn't fit you.\n");
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel as though Lady Luck herself has %^BLUE%^smiled%^WHITE%^ "
"upon you as you slip the anklet on.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" grins confidently as "+ETO->QS+" slips the anklet "
"on.",ETO);
   tracker = random(8)+1;
   switch(tracker) {
     case 1..2:
     ETO->add_stat_bonus("dexterity",1);
     break;
     case 3..4:
     ETO->add_stat_bonus("charisma",1);
     break;
     case 5..6:
     ETO->add_stat_bonus("wisdom",1);
     break;
     case 7..8:
     ETO->add_stat_bonus("intelligence",1);
     break;
   }
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel the anklet's %^BLUE%^luck%^WHITE%^ fade as you remove it.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" looks almost disappointed to remove the anklet.",ETO);
   switch(tracker) {
     case 1..2:
     ETO->add_stat_bonus("dexterity",-1);
     break;
     case 3..4:
     ETO->add_stat_bonus("charisma",-1);
     break;
     case 5..6:
     ETO->add_stat_bonus("wisdom",-1);
     break;
     case 7..8:
     ETO->add_stat_bonus("intelligence",-1);
     break;
   }
   return 1;
}