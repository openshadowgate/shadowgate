#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int charges;
void setread();

void create() {
   ::create();
   set_name("silvery harp amulet");
   set_id(({"amulet","harp amulet","silvery amulet","silver amulet","silvery harp amulet","silver harp amulet","inspiration","milils inspiration","milil's inspiration"}));
   set_short("%^BOLD%^%^WHITE%^Mi%^RESET%^l%^BOLD%^%^BLACK%^i%^RESET%^l%^BOLD%^%^WHITE%^'s I%^GREEN%^n%^WHITE%^sp%^RESET%^i%^BOLD%^%^BLACK%^ra%^RESET%^ti%^BOLD%^%^WHITE%^on%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^si%^RESET%^l%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^%^WHITE%^ry h%^RESET%^ar%^BOLD%^%^WHITE%^p a%^RESET%^m%^BOLD%^%^BLACK%^ul%^RESET%^e%^BOLD%^%^WHITE%^t%^RESET%^");
   set_long("%^RESET%^Supported by a fine chain of %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r fi%^RESET%^l%^BOLD%^%^BLACK%^ig%^RESET%^r%^BOLD%^%^WHITE%^ee%^RESET%^, this amulet bears crafting beyond the "
"ken of mortal hands.  It is shaped as a %^ORANGE%^h%^RED%^a%^ORANGE%^rp%^RESET%^ of five strings, each so %^CYAN%^sl"
"%^MAGENTA%^e%^CYAN%^nd%^MAGENTA%^e%^CYAN%^r %^RESET%^they would surely break on contact.  The body of the instrument is "
"made entirely of %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r l%^RESET%^e%^BOLD%^%^BLACK%^"
"av%^RESET%^e%^BOLD%^%^WHITE%^s%^RESET%^, layered over each other from the base to the curled tip.  They are so "
"intricately detailed that you can see the veins upon each leaf, like %^GREEN%^li%^BOLD%^v%^RESET%^%^GREEN%^i%^ORANGE%^n"
"%^GREEN%^g fro%^YELLOW%^n%^GREEN%^d%^RESET%^%^GREEN%^s %^RESET%^in argent miniature.  An archaic form of looped script "
"details an inscription upon the flat underside of the amulet.\n");
   set_limbs(({"left hand","right hand"}));
   set_weight(0);
   set_value(0);
   set_ac(0);
   set_type("ring");
   set_language("wizish");
   charges = 24;
   setread();
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_property("death keep",1);
}

int wear_fun() {
   if(member_array("Achieved: %^CYAN%^Aided in the restoration of %^MAGENTA%^ba%^CYAN%^r%^GREEN%^di%^MAGENTA%^c m%^ORANGE%^u%^RED%^si%^MAGENTA%^c%^CYAN%^!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
     return 0;
   }
   tell_object(ETO,"%^GREEN%^The gentle notes of a harp reach your ears.%^RESET%^");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" smiles with an expression of quiet serenity.%^RESET%^",ETO);
   if(TO->query_property("enchantment")) TO->remove_property("enchantment");
   while ((int)TO->query_property("magic nonstacking") != 1) {
     TO->remove_property("magic nonstacking");
     TO->set_property("magic nonstacking",1);
   }
   TO->set_overallStatus(100);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^GREEN%^You feel a gentle sense of sadness as you remove the amulet.%^RESET%^");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" seems saddened to remove the amulet.%^RESET%^",ETO);
   return 1;
}

void init() {
   ::init();
   add_action("invoke_me","invoke");
}

int invoke_me(string str) {
   if(!str) {
     notify_fail("What do you want to invoke?\n");
     return 0;
   }
   if(!TO->query_worn()) {
     notify_fail("You need to wear the amulet first.\n");
     return 0;
   }
   if(charges < 1) {
     notify_fail("You've used up the power of the amulet, and it disappears!\n");
     TO->remove();
     return 0;
   }
   if(str != "the cat" && str != "the fox" && str != "the eagle" && str != "the heart" && str != "the mind" && str != "the soul") {
     notify_fail("You can't invoke that.\n");
     return 0;
   }
   tell_room(EETO,"%^GREEN%^The strings of the harp amulet seem to s%^BOLD%^t%^RESET%^%^GREEN%^rum by an unseen hand, as "
"a rip%^CYAN%^pl%^GREEN%^e of notes peal out.%^RESET%^");
   switch(str) {
     case "the cat": new("/cmds/spells/c/_cats_grace")->use_spell(ETO,ETO,30,100,"bard"); break;
     case "the fox": new("/cmds/spells/f/_foxs_cunning")->use_spell(ETO,ETO,30,100,"bard"); break;
     case "the eagle": new("/cmds/spells/e/_eagles_splendor")->use_spell(ETO,ETO,30,100,"bard"); break;
     case "the mind": new("/cmds/spells/t/_tongues")->use_spell(ETO,ETO,30,100,"bard"); break;
     case "the heart": new("/cmds/spells/h/_heroism")->use_spell(ETO,0,30,100,"bard"); break;
     case "the soul": new("/cmds/spells/r/_regeneration")->use_spell(ETO,ETO,30,100,"bard"); break;
     default: tell_object(ETO,"Something's gone wrong! Quick, page the liche!"); return 1; break;
   }
   charges = charges - 1;
   setread();
   return 1;
}

void setread() {
   set_read("\n\n%^BOLD%^%^WHITE%^Let song and silence inspire you%^RESET%^\n"
"%^BOLD%^%^YELLOW%^Invoke the cat %^WHITE%^for reflexes true%^RESET%^\n"
"%^BOLD%^%^YELLOW%^Invoke the fox %^WHITE%^for cunning and guile%^RESET%^\n"
"%^BOLD%^%^YELLOW%^Invoke the eagle %^WHITE%^for a winning smile%^RESET%^\n"
"%^BOLD%^%^YELLOW%^Invoke the mind %^WHITE%^to know all words spoken%^RESET%^\n"
"%^BOLD%^%^YELLOW%^Invoke the heart %^WHITE%^for courage unbroken%^RESET%^\n"
"%^BOLD%^%^YELLOW%^Invoke the soul %^WHITE%^to heal all pain%^RESET%^\n"
"%^BOLD%^%^WHITE%^Only "+charges+" songs left, til the harp is silent again%^RESET%^\n");
}
