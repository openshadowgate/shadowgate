#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("boots");
   set_id(({"boots","riding boots","ornate boots","ornate riding boots","leather boots","sturdy boots","sturdy leather boots"}));
   set_short("%^BOLD%^%^BLACK%^or%^YELLOW%^n%^BLACK%^ate riding bo%^YELLOW%^o%^BLACK%^ts%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^sturdy leather boots%^RESET%^");
   set_long("%^ORANGE%^These boots seem particularly sturdy and well-made, of flawless polished %^BOLD%^"
"%^BLACK%^black leather%^RESET%^%^ORANGE%^.  They would reach a short way past the ankle, and are shaped in a "
"style common to riding boots, with a somewhat flexible portion at each side to allow the foot to simply slide "
"inside.  A %^YELLOW%^single golden buckle %^RESET%^%^ORANGE%^above this section on each boot, secures them "
"from coming loose during strenuous activity, and it is obvious that the toe has been reinforced inside with "
"some sort of %^WHITE%^metal%^ORANGE%^, probably to better protect the foot.  The soles have been %^BOLD%^"
"%^BLACK%^thickly layered%^RESET%^%^ORANGE%^, to prevent any harm coming to the wearer from rough or dangerous "
"ground.  They seem ideal for anyone involved in combat or riding activities.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Boots such as these are commonly designed for horse riding, due in particular to "
"their sturdiness and ability to protect the foot from harm.  These particular ones, however, are better made "
"and somewhat more extravagant than most, and were probably designed for a person of nobility.");
   set_property("lore difficulty",7);
   set_limbs(({"right foot","left foot"}));
   set_weight(8);
   set_value(5600);
   set_size(2);
   set_ac(0);
   set_property("enchantment",2);
   while(TO->query_property("enchantment")< 2){
     remove_property("enchantment");
     set_property("enchantment",2);
   }
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"strikeme":));
}

int wear_fun() {
   if((string)ETO->query_name() != "adrian") {
     tell_object(ETO,"%^WHITE%^%^BOLD%^You can't make sense of how to secure the boots onto your feet.");
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^You carefully slip into the boots and buckle them up.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" carefully buckles the boots up the sides.",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You unbuckle the protective boots and set them aside.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" unbuckles the boots carefully.",ETO);
   return 1;
}

int strikeme(int damage, object what, object who){
   if(random(2)) {
     tell_object(ETO,"%^BOLD%^%^BLACK%^The sturdy boots absorb "+who->QCN+"'s blow harmlessly.%^RESET%^");
     tell_object(who,"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s sturdy boots absorb the force of your blow harmlessly."
"%^RESET%^");
     tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s sturdy boots absorb the force of "
+who->QCN+"'s blow harmlessly.%^RESET%^",({ETO,who}));
     return (-1)*(damage);
   }
   return 1;
}
