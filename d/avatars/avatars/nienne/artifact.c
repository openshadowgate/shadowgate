#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword";

void create(){
   ::create();
   set_name("greatblade");
   set_id(({"sword","blade","talon","black greatblade","glowing greatblade","dread talon","talon of the hand","dread talon of the hand"}));
   set_short("%^BLACK%^%^BOLD%^Dr%^GREEN%^e%^BLACK%^ad Tal%^GREEN%^o%^BLACK%^n of the H%^GREEN%^a%^BLACK%^nd%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^g%^BOLD%^lo%^WHITE%^w%^GREEN%^in%^RESET%^%^GREEN%^g %^BLACK%^%^BOLD%^black greatblade%^RESET%^");
   set_long("%^RED%^This greatblade practically emanates power, in a great %^GREEN%^g%^BOLD%^lo%^WHITE%^w"
"%^GREEN%^in%^RESET%^%^GREEN%^g%^RED%^ aura that surrounds it without wavering.  Its blade is easily more "
"than six feet long, impressive even by the standards of most two-handed blades, and crafted from what "
"appears to be titanium, though it has been %^BLACK%^%^BOLD%^blackened%^RESET%^%^RED%^ to the colour of a "
"starless night sky.  It is secured within a hilt of perfect %^BLACK%^%^BOLD%^ebony%^RESET%^%^RED%^, "
"sculpted in the form of a mighty black dragon.  The creature's spread wings form the crosspiece, its tail "
"encircling the blade of the sword to secure it in place.  The dragon's head shows its expression held in an "
"eternal roar of fury, teeth bared, and within its foreclaws is held a single, perfect %^BLACK%^%^BOLD%^black"
" sa%^RESET%^%^WHITE%^p%^BLACK%^%^BOLD%^phire%^RESET%^%^RED%^ the size of an egg, that pulses with "
"%^GREEN%^dark energy%^RED%^.%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^This artifact was originally forged by the hand of the most powerful magi and "
"priests in the command of the Black Hand.  It was created with the intent to be the turning power in the "
"battle of Morgrash, in the hands of the Lord Knight Imperceptor, Dakhram Vilhon.  However, prior to the "
"battle's completion the blade was stolen and broken, and the pieces hidden from all attempts to locate "
"them.  The army, without the powers imbued into the blade to lead them to victory, was forced to simply "
"hold their foes at bay, in the hope that the artifact would be retrieved again.%^RESET%^");
   set_property("lore difficulty",20);
   set_wc(4,4);
   set_large_wc(4,6);
   set_weapon_speed(8);
   set_property("enchantment",8);
   set_value(1500);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
}

int wield_fun(){
   if(ETO->query_highest_level() < 60) {
     tell_object(ETO,"%^WHITE%^%^BOLD%^The sword glows with an aura of power, burning your hand and "
"repelling it forcibly!%^RESET%^");
     tell_room(EETO,"%^WHITE%^%^BOLD%^The sword glows with an aura of power, searing "+ETO->QCN+"'s hand and "
"repelling it forcibly!%^RESET%^",ETO);
     ETO->do_damage("torso",random(10)+20);
     return 0;
   }
   tell_room(EETO,"%^WHITE%^%^BOLD%^The %^RESET%^%^GREEN%^dull aura%^BOLD%^%^WHITE%^ of the blade %^GREEN%^flares%^WHITE%^ with inner power!%^RESET%^");
   ETO->set_property("evil item",1);
   return 1;
}

int unwield_fun() {
   tell_room(EETO,"%^WHITE%^%^BOLD%^The %^GREEN%^intense glow%^WHITE%^ of the blade dulls to a %^RESET%^%^GREEN%^pale aura%^WHITE%^%^BOLD%^.%^RESET%^");
   ETO->set_property("evil item",-1);
   return 1;
}