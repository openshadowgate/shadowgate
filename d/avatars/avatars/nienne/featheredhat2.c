#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("feathered hat");
   set_id(({"Hat","hat","feathered hat","thin hat","leather hat","thin leather hat"}));
   set_short("%^BOLD%^%^WHITE%^fe%^RESET%^at%^BOLD%^%^BLACK%^h%^RESET%^er%^BOLD%^%^WHITE%^ed h%^RESET%^a%^BOLD%^t%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^thin leather hat with a %^BOLD%^%^WHITE%^lo%^RESET%^n%^BOLD%^g fe%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^h%^BOLD%^%^WHITE%^er%^RESET%^");
   set_long("%^CYAN%^This flamboyant hat is made of some sort of %^WHITE%^pale, tanned leather%^CYAN%^, so "
"thin as to be almost cloth.  It has a cap portion to cover the head and a protruding brim all the way around, "
"though not enough to shade the wearer from the sun.  At the side, one section of the brim has been folded up "
"over itself, and a long %^BOLD%^%^WHITE%^si%^RESET%^l%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^%^WHITE%^ry "
"fe%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^h%^BOLD%^%^WHITE%^er %^RESET%^%^CYAN%^has been stuck onto one side.  "
"The entire piece looks excessively %^BOLD%^sh%^BLUE%^ow%^CYAN%^y %^RESET%^%^CYAN%^rather than practical or "
"protective.%^RESET%^\n");
   set_type("clothing");
   set_limbs(({"head"}));
   set_ac(0);
   set_size(2);
   set_property("enchantment",2);
   set_weight(4);
   set_value(80);
   set_lore("%^WHITE%^%^BOLD%^This hat was specially crafted for the winner of the first annual Spooky Story "
"contest in Tabor.  Devan was awarded the title of Grand Specter, for his startling performance before the "
"assembled watchers in the Rhapsody inn, and was also granted this hat as a prize for his victory.%^RESET%^\n");
   set_property("lore difficulty",19);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

void init(){
    ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    if(interactive(TP) && !avatarp(TP)) { set_size(TP->query_size()); }
}

int wear_fun(){
   if((string)ETO->query_name() != "devan") {
     tell_object(ETO,"%^BOLD%^%^WHITE%^This hat does not fit you!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" can't seem to figure out how to wear the hat.",ETO);
     return 0;
   }
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" sets the feathered hat upon "+ETO->QP+" head, and tilts it to "
"one side.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^You set the feathered hat upon your head, and tilt it to one "
"side.%^RESET%^");
   return 1;
}

int remove_fun(){
  tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" removes "+ETO->QP+" feathered hat with a flourish.%^RESET%^",ETO);
  tell_object(ETO,"%^BOLD%^%^WHITE%^You remove the feathered hat with a flourish.%^RESET%^");
  return 1;
}
