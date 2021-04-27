#include <std.h>
inherit ARMOUR;

int OWNED;
string owner;

void create() {
   ::create();
   set_name("robe");
   set_id(({"robe","dusky robe","dusky gray robe","gray robe","shroud","shroud of the doomguide"}));
   set_short("%^BOLD%^%^BLACK%^Do%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^mgu%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^de's Shroud");
   set_obvious_short("%^BOLD%^%^BLACK%^smoky gray robe embroidered with %^YELLOW%^go%^RESET%^%^ORANGE%^l%^YELLOW%^d th%^RESET%^%^ORANGE%^r%^YELLOW%^ead%^RESET%^");
   set_long("%^CYAN%^This robe is of only simple design, with long open "
"sleeves and a softly folded high neckline. Stretching to the ground on "
"even the tallest of wearers, it is cut from %^BOLD%^%^BLACK%^somber gray "
"cloth %^RESET%^%^CYAN%^the color of an overcast sky. It would be a "
"fairly %^BLUE%^dull %^CYAN%^garment, were it not for the emblem "
"embroidered across the upper left side in %^YELLOW%^go%^RESET%^%^ORANGE%^"
"l%^YELLOW%^d%^RESET%^%^CYAN%^. The %^WHITE%^%^BOLD%^gl%^YELLOW%^i"
"%^WHITE%^tter%^MAGENTA%^i%^WHITE%^ng %^RESET%^%^CYAN%^thread outlines "
"the image of an upright %^WHITE%^sk%^BOLD%^e%^RESET%^%^WHITE%^letal "
"%^CYAN%^arm holding a set of %^BOLD%^%^BLACK%^balanced scales%^RESET%^"
"%^CYAN%^.%^RESET%^\n");
   set_lore("The symbol stitched into this robe marks it clearly as "
"a Kelemvorite vestment. Only the highest ranked among their priesthood "
"are so clothed, with the golden color of the thread denoting their "
"status. Lesser priests have theirs embroidered in silver, and acolytes "
"in iron gray.");
   set_property("lore difficulty",5);
   set_limbs(({"torso"}));
   set_weight(5);
   set_value(0);
   set_size(2);
   set_ac(0);
   set_property("enchantment",4);
   while(TO->query_property("enchantment")< 4){
      remove_property("enchantment");
      set_property("enchantment",4);
   }
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   if((string)TP->query_diety() != "kelemvor" && !avatarp(ETO)) {
     tell_object(ETO,"The robe seems not to fit you.");
     return 0;
   }
   if((OWNED && (string)ETO->query_name() == owner) || !OWNED || avatarp(ETO)) {
     tell_object(ETO,"%^CYAN%^You enfold yourself in the sacred vestments "
"of your faith and feel more sure of yourself.%^RESET%^");
     tell_room(EETO,"%^CYAN%^"+ETO->QCN+" wraps the %^BOLD%^%^BLACK%^"
"somber robe %^RESET%^%^CYAN%^around "+ETO->QP+" figure, and the "
"%^YELLOW%^go%^RESET%^%^ORANGE%^l%^YELLOW%^d-embr%^RESET%^%^ORANGE%^o"
"%^YELLOW%^idered %^RESET%^%^CYAN%^thread glitters with the "
"movement.%^RESET%^",ETO);
     if(interactive(ETO) && !OWNED && !avatarp(ETO)) {
       owner = ETO->query_name();
       OWNED = 1;
     }
     ETO->set_property("magic resistance",15);
     return 1;
   }
   tell_object(ETO,"The robe seems not to fit you.");
   return 0;
}

int remove_fun() {
   tell_object(ETO,"%^CYAN%^You remove the robe, but know Kelemvor is "
"still watching over you.%^RESET%^");
   ETO->set_property("magic resistance",-15);
   return 1;
}
