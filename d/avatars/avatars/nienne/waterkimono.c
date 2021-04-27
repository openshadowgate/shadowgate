#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("kimono");
   set_id(({"kimono","silk kimono","elegant kimono","elegant silk kimono","mantle","mantle of the mists","mantle of the azure mists"}));
   set_short("%^WHITE%^%^BOLD%^Mantle of the %^RESET%^%^CYAN%^Azu%^BOLD%^r%^RESET%^%^CYAN%^e Mi%^BOLD%^s%^RESET%^%^CYAN%^ts%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^an ele%^RESET%^%^BLUE%^g%^BOLD%^%^WHITE%^ant si%^CYAN%^l%^WHITE%^k kim%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^no%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^This garment is made from the finest of silks, left long and flowing for the "
"comfort of the wearer.  Its sleeves are long and draped, reaching down from the wrists to flow freely.  It is "
"worn wrapped around the body and crossed at the front, to give a high neck and accentuate the wearer's "
"figure.  It is secured at the waist by a %^RESET%^%^MAGENTA%^wide lavender sash %^WHITE%^%^BOLD%^, and tied "
"in a bow at the back.  The kimono itself has been dyed in pastel hues, in a marbled pattern resembling "
"ripples of water, ranging from %^RESET%^%^WHITE%^faded whites%^WHITE%^%^BOLD%^ and %^CYAN%^azure%^WHITE%^, "
"through to %^RESET%^%^BLUE%^deeper cobalt %^WHITE%^and %^RESET%^%^CYAN%^aquamarine%^WHITE%^%^BOLD%^.  The "
"garment has obviously been designed with elegance in mind.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^This exotic garment was once a simple kimono of unknown origins, transformed by "
"the divine blessings of the Istishian priestess Selve.  Through a dedicated ritual to the Goddess of Singing "
"Waters, the very essence of the ocean was imbued into the garment itself, permanently altering its nature and "
"appearance.");
   set_property("lore difficulty",21);
   set_weight(8);
   set_value(4000);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_size(2);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun() {
   if((ETO->query_highest_level() < 15) || (string)ETO->query_diety() != "istishia") {
     tell_object(ETO,"%^WHITE%^%^BOLD%^The kimono repels your touch, leaving a %^RESET%^%^CYAN%^light mist "
"%^WHITE%^%^BOLD%^upon your hands.%^RESET%^");
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^The beautiful kimono fits you perfectly, in unmatched comfort.%^RESET%^");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" drapes the silken kimono around "+ETO->QS+"self comfortably, "
"securing it with the wide sash.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You remove the silken kimono, already missing the touch of the "
"comfortable garment.%^RESET%^");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" looks almost disappointed to remove "+ETO->QP+" "
"kimono.%^RESET%^",ETO);
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(4)) {
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" extends both arms in a graceful motion, summoning forth a "
"%^RESET%^%^CYAN%^gentle mist %^WHITE%^%^BOLD%^in the air around "+who->QCN+"!%^RESET%^",({ETO,who}));
     tell_object(ETO,"%^WHITE%^%^BOLD%^You gracefully extend both arms and call upon the power of your god, "
"causing a %^RESET%^%^CYAN%^gentle mist %^BOLD%^%^WHITE%^to form in the air around "+who->QCN+"!%^RESET%^");
     tell_object(who,"%^WHITE%^%^BOLD%^"+ETOQCN+" gracefully extends both arms, causing a%^RESET%^%^CYAN%^ "
"shimmering mist %^BOLD%^%^WHITE%^to form in the air around you that disorients your senses!%^RESET%^");
     who->set_paralyzed((random(5)+15),"You're still trying to reorient yourself!");
     who->set_temporary_blinded(4,"You can't see past the shimmering cloud of mist!");
   }
   return 0;
}
