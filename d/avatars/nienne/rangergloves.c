#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("leather gloves");
   set_id(({"gloves","leather gloves","hands","hands of the hidden trails","hands of the trails"}));
   set_short("%^RESET%^%^ORANGE%^Hands of the %^GREEN%^Hi%^BOLD%^d%^RESET%^%^GREEN%^den Tra%^ORANGE%^i%^GREEN%^ls%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a pair of dark gloves%^RESET%^");
   set_long("%^CYAN%^These simple gloves are formed of %^ORANGE%^dark, tanned leather%^CYAN%^, enclosing "
"each hand up to the wrist.  They have no inner lining, but the leather would rest comfortably over the "
"hands, giving them light but sturdy protection from damage.  Across their surface, small images have been "
"burnt into the leather itself, of %^GREEN%^le%^ORANGE%^a%^GREEN%^ves%^CYAN%^ and small %^ORANGE%^cr%^RED%^e"
"%^ORANGE%^atu%^RED%^r%^ORANGE%^es%^CYAN%^ slinking across the tanned surface.  Occasionally, amidst the "
"images you can catch a small glimpse of %^BLACK%^%^BOLD%^shadowy runes%^RESET%^%^CYAN%^ flickering across "
"the leather, though they never remain in sight long enough to decipher a meaning.%^RESET%^\n");
   set_type("clothing");
   set_limbs(({"right arm","left arm"}));
   set_size(2);
   set_property("enchantment",4);
   set_item_bonus("attack bonus",2);
   set_weight(4);
   set_value(450);
   set_lore("%^WHITE%^%^BOLD%^This artifact was crafted within the now-lost elven city of El'kannor, lost "
"many decades past in the ogre raids that destroyed the city in the year 634SG, common reckoning.  While "
"many accounts say that survivors fled the village, there has been little proof to validate this claim.  "
"Occasional items of value have been restored over the years, though many still remain lost to the world, "
"remembered only in tales of the lost city.  This particular artifact was once the possession of the scout "
"leader of the village, and was known to be warded with many elven runes of protection, to guide his hands "
"in battle.%^RESET%^\n");
   set_property("lore difficulty",20);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun(){
   if((string)ETO->query_race() != "elf" && !avatarp(ETO)) {
     tell_object(ETO,"The gloves don't seem to fit you.");
     tell_room(EETO,"The gloves don't seem to fit "+ETO->QCN+".",ETO);
     return 0;
   }
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" slides the gloves easily over each hand, as %^BLACK%^%^BOLD%^dark "
"runes%^RESET%^%^ORANGE%^ flicker briefly across their surface.%^RESET%^",ETO);
   tell_object(ETO,"%^ORANGE%^You slide the gloves easily over each hand, and see %^BLACK%^%^BOLD%^dark "
"runes%^RESET%^%^ORANGE%^ flicker briefly across their surface.%^RESET%^");
   return 1;
}

int remove_fun(){
  tell_room(EETO,"%^ORANGE%^"+ETOQCN+" slides the gloves back off "+ETO->QP+" hands, and the%^BLACK%^%^BOLD%^"
" dark runes%^RESET%^%^ORANGE%^ upon them disappear.%^RESET%^",ETO);
  tell_object(ETO,"%^ORANGE%^You slide the gloves back off your hands, and the %^BLACK%^%^BOLD%^dark "
"runes%^RESET%^%^ORANGE%^ disappear.%^RESET%^");
  return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(2)){
     tell_room(EETO,"%^ORANGE%^The runes across "+ETOQCN+"'s gloves %^BLACK%^%^BOLD%^glimmer%^RESET%^"
"%^ORANGE%^ momentarily, and "+ETO->QS+" easily deflects "+who->QCN+"'s blow!",({ETO,who}));
     tell_object(ETO,"%^ORANGE%^The runes across your gloves %^BLACK%^%^BOLD%^glimmer%^RESET%^%^ORANGE%^ "
"momentarily, and you easily deflect "+who->QCN+"'s blow!%^RESET%^");
     tell_object(who,"%^ORANGE%^The runes across "+ETOQCN+"'s gloves %^BLACK%^%^BOLD%^glimmer%^RESET%^"
"%^ORANGE%^ momentarily, and "+ETO->QS+" easily deflects your blow!%^RESET%^");
     return (-1)*damage;
   }
}
