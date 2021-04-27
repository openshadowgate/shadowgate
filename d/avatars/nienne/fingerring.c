#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("silver rings");
   set_id(({"rings","silver rings","chain-linked rings","chain linked rings","chain linked silver rings","chain-linked silver rings"}));
   set_short("%^BOLD%^%^WHITE%^chain-linked s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r rings%^RESET%^");
   set_long("This piece of jewelry is formed of four fine %^BOLD%^"
"%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r "
"%^RESET%^rings, each polished to a %^ORANGE%^br%^YELLOW%^il%^WHITE%^"
"l%^YELLOW%^ia%^RESET%^%^ORANGE%^nt %^RESET%^sheen.  Its unique "
"appearance is given by the thin chains of %^BOLD%^%^WHITE%^s%^RESET%^i"
"%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^, linking the "
"four rings together, but with a fair length of movement between each.  "
"It seems the entire piece is designed to be worn across several fingers, "
"with the chains left to dangle over the back of the hand.  A strange, "
"but pleasantly %^GREEN%^e%^CYAN%^x%^MAGENTA%^o%^CYAN%^t%^GREEN%^i"
"%^ORANGE%^c %^RESET%^item of jewelry.\n");
   set_lore("Such designs are uncommon among most surface races.  However"
", they are considered high fashion by the nobility of the drow, and are "
"often seen worn by matrons and other notable kindred of the higher "
"ranked households.  While for many they are merely fashionable, the "
"drow faith of Kiaransalee also wears such jewelry as a sign of dedication "
"to their patron. Many faithful of her surface-known aspect, Beshaba, are similarly fond of such fine designs, though they are far more rare.\n");
   set_property("lore difficulty",30);
   set_limbs(({"right hand","left hand"}));
   set_weight(0);
   set_value(530);
   set_ac(0);
   set_type("ring");
    set_item_bonus("charisma",1);
    set_property("enchantment",1);
    set_wear((:TO,"wear_fun":));
}

int wear_fun() {
   if((string)ETO->query_diety() != "beshaba" && !avatarp(TP)) {
     tell_object(ETO,"The rings don't seem to fit your fingers.  How unfortunate.");
     return 0;
   }
   return 1;
}
