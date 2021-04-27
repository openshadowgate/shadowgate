#include <std.h>
inherit "/d/common/obj/weapon/lance";

int tracker;

void create() {
   ::create();
   set_name("golden lance");
   set_short("%^BOLD%^%^WHITE%^Lance of the %^YELLOW%^Li%^RESET%^%^ORANGE%^o%^YELLOW%^n's R%^RESET%^%^ORANGE%^o%^YELLOW%^ar%^RESET%^");
   set_obvious_short("%^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n%^WHITE%^ lance%^RESET%^");
   set_id(({"lance","golden lance","lance of the lion's roar","lance of the lions roar"}));
   set_long("%^RESET%^%^ORANGE%^This sturdy lance is made from a strong "
"beam of %^RESET%^white oak%^ORANGE%^. Its surface has been sanded smooth "
"and painted with a spiral of interchanging %^YELLOW%^gold "
"%^RESET%^%^ORANGE%^and %^BOLD%^%^BLUE%^blue %^RESET%^%^ORANGE%^stripes "
"that wrap their way down from the blunted tip along the full length of "
"the lance. The pole of the lance vanishes into the %^YELLOW%^gold "
"%^RESET%^%^ORANGE%^tinted steal mouth of a stylized %^YELLOW%^lion's "
"head %^RESET%^%^ORANGE%^whose mane is depicted as flared out around the "
"lion's neck to form a protective vanguard. Two bright %^BOLD%^%^CYAN%^"
"blue sapphires %^RESET%^%^ORANGE%^serve as the lion's eyes, their "
"exceptional quality and faceted cut catching and eagerly reflecting even "
"the smallest amount of light. The hilt or butt of the lance where the "
"wielder's hands would grip is wrapped in soft %^BOLD%^%^WHITE%^white "
"leather %^RESET%^%^ORANGE%^that has a somewhat coarse texture making for "
"a better grip. The harness, designed to be worn over the shoulder and "
"chest like a bandoleer, helps support the weight of the lance. It is "
"likewise made from %^BOLD%^%^WHITE%^white leather%^RESET%^%^ORANGE%^, "
"though has been hardened through a boiling process to make it more "
"secure and sturdy. Burnished %^RESET%^steel rivets %^ORANGE%^hold the "
"leather sections together, while matching buckles provide the ability to "
"adjust the straps for a snug fit.%^RESET%^ ");
   set_lore("The Lance of the Lion's Roar is as much a symbol of station "
"and piety as it is a weapon of war. Creating one requires a process of "
"prayers and devotions in which no less then six priests of Torm who are "
"of the rank of Warden or higher enter a state of communion with Torm. "
"The priests then bear witness of the Knight's dedication and faith in "
"the tenants of the church. Each priest must provide a unique recounting "
"which they have personally witnessed and there must be no doubt in their "
"hearts as to the nature of the Knight's true nobility and devotion. If, "
"at the end of the ritual, Torm is pleased, a billet of metal and two "
"gemstones will appear upon the altar. These are then used by a master "
"weapon smith to fashion the lance's stylized vanguard. It is said the "
"lance will only reveal its true abilities to the one for whom it was "
"made.");
   set_property("lore difficulty",18);
   set_value(8200);
   while((int)TO->query_property("enchantment") != 1){
      remove_property("enchantment");
      set_property("enchantment",1);
   }
//   set_hit((:TO,"hitme":));
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
   tracker = 0;
}

int wieldme() {
   if((string)ETO->query_diety() == "torm") {
     tell_object(ETO,"%^BOLD%^%^BLUE%^As you prepare to charge with the "
"%^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^"
"n l%^RESET%^%^ORANGE%^a%^YELLOW%^n%^RESET%^%^ORANGE%^c%^YELLOW%^e"
"%^BOLD%^%^BLUE%^, the sapphire eyes flash and a deep "
"roar issues from the lion shaped vanguard. In your mind you hear the "
"words: %^YELLOW%^To glory! To victory! To death shall we guide those "
"whose souls who are evil!%^RESET%^");
     tell_room(EETO,"%^YELLOW%^A flash of %^BOLD%^%^BLUE%^sapphire "
"%^YELLOW%^accompanies the deep roar that issues from the golden lance "
"as%^RESET%^ "+ETO->QCN+" %^YELLOW%^braces the weapon for a "
"charge.%^RESET%^",ETO);
     tracker = 1;
     while((int)TO->query_property("enchantment") != 3){
       remove_property("enchantment");
       set_property("enchantment",3);
     }
   }
   return 1;
}

int removeme() {
   if(tracker) {
     tell_object(ETO,"%^BOLD%^%^BLUE%^You feel the weight of the "
"%^YELLOW%^lion's eyes%^BLUE%^ upon you as you unwield the %^YELLOW%^g"
"%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n%^WHITE%^ "
"l%^RESET%^%^ORANGE%^a%^YELLOW%^n%^RESET%^%^ORANGE%^c%^YELLOW%^e"
"%^BLUE%^.%^RESET%^");
     tell_room(EETO,"%^YELLOW%^The %^BLUE%^glow %^YELLOW%^within the "
"lion's eyes dims as %^RESET%^"+ETO->QCN+" %^YELLOW%^unwields the "
"lance.%^RESET%^",ETO);
     tracker = 0;
   }
   while((int)TO->query_property("enchantment") != 1){
     remove_property("enchantment");
     set_property("enchantment",1);
   }
   return 1;
}
