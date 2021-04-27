#include <std.h>
inherit ARMOUR;

int mylevel,myench,mymr;

void create() {
   ::create();
   set_name("chain");
   set_id(({"chain","luminescent chain","pendant","necklace","pendant of serenity"}));
   set_short("%^BOLD%^%^WHITE%^Pend%^CYAN%^a%^WHITE%^nt of Ser%^CYAN%^e%^WHITE%^nity%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a lu%^RESET%^%^WHITE%^mi%^BOLD%^%^WHITE%^nes%^RESET%^%^WHITE%^ce%^BOLD%^%^BLACK%^nt chain%^RESET%^");
   set_long("%^CYAN%^This chain is unlike anything made by human hands. The "
"jewelry itself is made up of five slender %^BOLD%^%^BLACK%^s%^RESET%^"
"%^WHITE%^i%^BOLD%^%^WHITE%^lv%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^r "
"%^RESET%^%^CYAN%^threads, each interwoven in an %^MAGENTA%^intricate "
"%^CYAN%^pattern that criss-crosses down the length of the necklace. The "
"overall effect is a braided chain with a %^BOLD%^delicate%^RESET%^%^CYAN%^ "
"appearance, but surprising strength and resilience to damage. As to the "
"metal itself, it's impossible to say just what kind it is. It carries the "
"gloss and shine of %^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^i"
"%^BOLD%^%^WHITE%^lv%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^, "
"yet the colour swirls through all hues from a %^BOLD%^%^BLACK%^deep gray"
"%^RESET%^%^CYAN%^, through %^WHITE%^shining platinum%^CYAN%^, up to near "
"%^BOLD%^%^WHITE%^pure white%^RESET%^%^CYAN%^. In the centre, the chain "
"supports a detailed pendant crafted from the same metal as the necklace "
"itself. The pendant depicts a graceful %^RED%^drow %^CYAN%^female with a "
"secretive smile upon her lips, entirely naked and swathed in a halo of her "
"%^WHITE%^long, unrestrained hair%^CYAN%^. She stands poised with one leg "
"raised, as if in dance, with one hand grasping a %^BOLD%^%^BLACK%^shining "
"longsword%^RESET%^%^CYAN%^, and the other reaching upwards to the sky. The "
"entire piece holds an %^BOLD%^inner luminescence %^RESET%^%^CYAN%^all of its "
"own, that seems to brighten the very air around it.%^RESET%^\n");
   set_weight(2);
   set_value(3000);
   set_ac(0);
   set_limbs(({"neck"}));
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int drop(){ return 1; }

int wear_fun() {
   tell_object(ETO,"%^CYAN%^The silvery chain takes on a %^BOLD%^gentle glow "
"%^RESET%^%^CYAN%^as it settles around your neck.%^RESET%^");
   tell_room(EETO,"%^CYAN%^"+ETOQCN+" smiles warmly as the silvery chain "
"settles around "+ETO->QP+" neck.%^RESET%^",ETO);
   TO->set_overallStatus(100);
   mylevel = ETO->query_lowest_level();
   mymr = mylevel/2;
   myench = mylevel/9;
   while ((int)TO->query_property("enchantment") != myench) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",myench);
   }
   ETO->set_property("magic resistance",mymr);
   ETO->add_sight_bonus(-2);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^CYAN%^You already miss the soothing feel of the silvery "
"chain.%^RESET%^");
   tell_room(EETO,"%^CYAN%^"+ETO->QCN+" seems disappointed to remove the "
"silvery chain.%^RESET%^",ETO);
   TO->remove_property("enchantment");
   ETO->set_property("magic resistance",(-1)*mymr);
   ETO->add_sight_bonus(2);
   return 1;
}

int struck_fun(int damage, object what, object target) {
   if (!random(2)) {
     tell_object(ETO,"%^CYAN%^Your necklace %^BOLD%^%^BLACK%^sh%^RESET%^"
"%^WHITE%^i%^BOLD%^%^WHITE%^mm%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^rs "
"%^RESET%^%^CYAN%^softly and you a soothing sensation runs through you, "
"leaving you feeling invigorated!%^RESET%^");
     tell_room(EETO,"%^CYAN%^"+ETO->QCN+"'s necklace %^BOLD%^%^BLACK%^sh"
"%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^mm%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^rs "
"%^RESET%^%^CYAN%^softly, leaving "+ETO->QO+" looking "
"invigorated!%^RESET%^",ETO);
     ETO->add_hp(roll_dice(2,8));
   }
   return 1;
}
