#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("amulet");
   set_id(({"amulet","jet amulet","jet-black amulet","black amulet","symbol","holy symbol","symbol of vecna","holy symbol of vecna"}));
   set_short("%^BOLD%^%^BLACK%^Holy Symbol of %^BOLD%^%^MAGENTA%^V%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^n%^BOLD%^%^MAGENTA%^a%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^a jet-black amulet%^RESET%^");
   set_long("%^MAGENTA%^This unusual amulet consists of a perfect spherical disc of %^BOLD%^%^BLACK%^jet black"
"%^RESET%^%^MAGENTA%^. Upon one side it has been marked with a stylised symbol of a %^ORANGE%^gnarled, sinewy "
"hand %^MAGENTA%^clutching a staring %^RESET%^eyeball%^MAGENTA%^.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^This amulet bears the mark of the would-be deity, the Archlich Vecna. Eternally "
"obsessed with the search for power, Vecna was once a mortal mage who transcended the skill of nearly any "
"arcanist in history. Not content with an end to his mortal life, he became a lich through profane rituals "
"of necromancy, and continued in his once-mortal attempts to subvert others to his service. It was only "
"in 387SG, by the combined efforts of a group of adventurers and the temple of Mystra, that he was defeated. "
"Unable to slay the mighty undead, they instead permanently trapped him within the depths of the Demongate "
"tower.%^RESET%^\n");
   set_property("lore difficulty",40);
   set_type("ring");
   set_limbs(({"neck"}));
   set_weight(1);
   set_size(-1);
   set_value(5600);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^A burning pain runs through you as you wear the amulet!%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETO->QCN+" screams in pain as "+ETO->QS+" wears the amulet.%^RESET%^",ETO);
   ETO->do_damage("head",random(5)+5);
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" seems briefly unsettled as "+ETO->QS+" removes the amulet.%^RESET%^",ETO);
   tell_object(ETO,"%^BLACK%^%^BOLD%^An icy chill runs down your spine as you remove the amulet.%^RESET%^");
   return 1;
}