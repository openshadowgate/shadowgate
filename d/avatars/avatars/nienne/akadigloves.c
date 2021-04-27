#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("gloves");
   set_id(({"gloves","akadi gloves","zephyr's caress","zephyrs caress","half-gloves","halfgloves","silken gloves","silken half-gloves"}));
   set_short("%^CYAN%^%^BOLD%^Ze%^WHITE%^p%^CYAN%^hy%^BLACK%^r%^CYAN%^'s C%^BLACK%^a%^CYAN%^re%^WHITE%^s%^CYAN%^s%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^s%^RESET%^%^WHITE%^i%^BOLD%^l%^CYAN%^k%^BLUE%^e%^CYAN%^n %^WHITE%^h%^RESET%^%^WHITE%^a%^BLACK%^%^BOLD%^l%^RESET%^%^WHITE%^f%^BOLD%^-%^CYAN%^g%^BLUE%^l%^CYAN%^o%^WHITE%^v%^RESET%^%^WHITE%^e%^BLACK%^%^BOLD%^s%^RESET%^");
   set_long("%^CYAN%^Soft, smooth silk has been manipulated to form these unique half-gloves, dyed in "
"rippling shades of %^WHITE%^w%^BOLD%^h%^RESET%^%^WHITE%^i%^BOLD%^t%^RESET%^%^WHITE%^e%^CYAN%^ and "
"%^BLUE%^%^BOLD%^b%^CYAN%^l%^BLUE%^u%^CYAN%^e%^RESET%^%^CYAN%^, in the colours of the summer sky.  A slender "
"line of the silk attaches the garment around the middle- and index-fingers of the hand, from where the "
"cloth flows in soft folds around the back of the hand and under the palm.  The garment ends at the wrist "
"with a fine tracing of %^WHITE%^white%^CYAN%^ stitches, which also outline the hem near the fingers.  They "
"seem mostly ornamental, though they would certainly allow for more freedom of movement than most normal "
"gloves.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^A rare few tales speak of such gloves as these.  Some hint at their original "
"creation by the clergy of the Queen of Air, blessed in a ritual to the Goddess herself.  They were said to be "
"stolen from the priesthood by a particularly vicious group of Grumbarryn duergar, who took the gloves to "
"their home beneath the earth.  It is unknown what became of them since their theft.");
   set_property("lore difficulty",12);
   set_weight(4);
   set_value(0);
   set_ac(0);
   set_property("enchantment",1);
   set_type("leather");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
   set_limbs(({"left hand","right hand"}));
}

int wear_fun() {
   if((string)TP->query_diety() != "akadi") {
     tell_object(ETO,"%^WHITE%^%^BOLD%^The gloves refuse to let you wear them!");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" tries to wear the gloves, but fails.",ETO);
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^A gentle breeze seems to run through your fingers as the gloves slide "
"over them.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" slips the gloves over each hand with a knowing smile.",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel the touch of the winds dissipate as you remove the gloves.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" looks disappointed to remove the gloves.",ETO);
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(6)){
     if(random(2)) {
       tell_room(EETO,"%^BOLD%^%^CYAN%^A brisk breeze picks up around "+ETOQCN+", as "+ETO->QS+" shifts "
"effortlessly into another attack at "+who->QCN+"!%^RESET%^",({ETO,who}));
       tell_object(ETO,"%^BOLD%^%^CYAN%^A brisk breeze picks up around you, guiding your hands into another "
"attack!%^RESET%^");
       tell_object(who,"%^BOLD%^%^CYAN%^A brisk breeze picks up around "+ETOQCN+", as "+ETO->QS+" shifts "
"effortlessly into another attack at you!%^RESET%^");
     }
     else {
       tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" moves with unnerving speed into another attack at "
+who->QCN+", causing a light breeze to ruffle through your hair with the sudden movement.%^RESET%^",({ETO,who}));
       tell_object(ETO,"%^BOLD%^%^WHITE%^You move quickly into another attack at "+who->QCN+", with such "
"sudden speed that the wind ruffles your hair lightly.%^RESET%^");
       tell_object(who,"%^BOLD%^%^WHITE%^"+ETOQCN+" moves with unnerving speed into another attack at you, "
"causing a light breeze to ruffle through your hair with the sudden movement.%^RESET%^");
     }
     ETO->execute_attack();
   }
}
