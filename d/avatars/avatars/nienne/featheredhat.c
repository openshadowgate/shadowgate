#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("feathered hat");
   set_id(({"Hat","hat","feathered hat"}));
   set_short("%^BLUE%^%^BOLD%^l%^RESET%^%^BLUE%^on%^BOLD%^g-f%^RESET%^%^BLUE%^ea%^BOLD%^th%^RESET%^%^BLUE%^er%^BOLD%^ed %^BLACK%^leather hat%^RESET%^");
   set_long("%^GREEN%^This flamboyant hat is made of some sort of %^BLACK%^%^BOLD%^dark, tanned "
"leather%^RESET%^%^GREEN%^, with a cap portion to cover the head and a wide brim to shade the wearer's face. "
" At the back, one section of the brim has been folded up over itself, and a long "
"%^BLUE%^cob%^BOLD%^a%^RESET%^%^BLUE%^lt-b%^BOLD%^l%^RESET%^%^BLUE%^ue%^GREEN%^ feather has been stuck onto "
"one side.  Underneath, the cap-like portion of the hat is lined with %^BLACK%^%^BOLD%^thicker "
"leather%^RESET%^%^GREEN%^, which would obviously protect the head far better than a normal hat.%^RESET%^\n");
   set_type("leather");
   set_limbs(({"head"}));
   set_ac(1);
   set_size(2);
   set_weight(3);
   set_value(80);
   set_lore("%^WHITE%^%^BOLD%^This could be anyone's hat really, as it holds no distinctive markings to set "
"it apart as belonging to a specific person.  Such hats are commonly seen among the more flamboyant "
"travellers around the realms, generally entertainers and rogues with a distinctive style to "
"keep.%^RESET%^\n");
   set_property("lore difficulty",3);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun(){
   tell_room(EETO,"%^BLUE%^%^BOLD%^"+ETO->QCN+" sets the feathered hat upon "+ETO->QP+" head, and adjusts it "
"to sit to one side.%^RESET%^",ETO);
   tell_object(ETO,"%^BLUE%^%^BOLD%^You set the feathered hat upon your head, and tilt it slightly to one "
"side.%^RESET%^");
   ETO->add_stat_bonus("charisma",1);
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BLUE%^%^BOLD%^"+ETOQCN+" removes "+ETO->QP+" feathered hat with a "
"flourish.%^RESET%^",ETO);
   tell_object(ETO,"%^BLUE%^%^BOLD%^You remove the feathered hat with a flourish.%^RESET%^");
   ETO->add_stat_bonus("charisma",-1);
   return 1;
}