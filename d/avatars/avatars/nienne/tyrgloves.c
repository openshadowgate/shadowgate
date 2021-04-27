#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("gloves");
   set_id(({"gloves","suede gloves","black and white gloves","black-and-white gloves","pair of gloves","hands of the god","hands of the maimed god"}));
   set_short("%^BOLD%^%^WHITE%^Hands of the %^BLACK%^M%^WHITE%^ai%^BLACK%^me%^WHITE%^d G%^BLACK%^o%^WHITE%^d%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^a pair of %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^-and-%^BOLD%^%^WHITE%^white %^RESET%^%^CYAN%^suede gloves%^RESET%^");
   set_long("%^BOLD%^%^CYAN%^Soft, malleable suede has been crafted by a master's hands to create these fine "
"gloves.  They are %^YELLOW%^thin %^CYAN%^enough to easily allow the sensation of touch through, as well as "
"affording complete %^RESET%^%^MAGENTA%^freedom %^BOLD%^%^CYAN%^of movement for one's fingers.  They enclose "
"the hand entirely up to the wrist, where they have been carefully hemmed with tiny stitches.  Oddly, however, "
"they do not match in color; the left hand is of a %^WHITE%^pure snowy-white shade%^CYAN%^, while the right is "
"%^BLACK%^midnight black%^CYAN%^.  The only ornamentation to the clothing is upon the underside of the palm, "
"not usually visible, where fine stiches mark out the shape of balanced scales resting upon a warhammer, in "
"%^BLUE%^metallic blue thread%^CYAN%^.%^RESET%^\n");
   set_type("clothing");
   set_limbs(({"right hand","left hand"}));
   set_size(2);
   set_property("enchantment",1);
   set_weight(4);
   set_value(450);
   set_lore("%^BOLD%^%^WHITE%^Gloves such of these, while appearing strange to some, are commonly worn among "
"the faithful of Tyr, particularly those blessed with His divine favor. They are always created with the left "
"hand colored white, and the right hand colored black, to symbolise the loss of Tyr's right hand during the "
"godswars. Many among Tyr's faithful believe that by wearing them, their hands are guided to just actions by "
"Grimjaws himself.\n");
   set_property("lore difficulty",12);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun(){
   if((string)ETO->query_diety() != "tyr" && !avatarp(ETO)) {
     tell_object(ETO,"The gloves don't seem to fit you.");
     tell_room(EETO,"The gloves don't seem to fit "+ETO->QCN+".",ETO);
     return 0;
   }
/*   if((int)ETO->query_lowest_level() < 21) {
     tell_object(ETO,"The gloves don't seem to fit you.");
     tell_room(EETO,"The gloves don't seem to fit "+ETO->QCN+".",ETO);
     return 0;
   } */
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" %^BOLD%^%^WHITE%^looks more confident as "+ETO->QS+" fits the "
"gloves over each hand.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^You fit the gloves over each hand, knowing that Tyr's justice will "
"guide you.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" %^BOLD%^%^WHITE%^carefully removes "+ETO->QP+ 
" gloves.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^You remove the gloves carefully, confident that Tyr will still watch over "
"you.%^RESET%^");
  return 1;
}

int struck_fun(int damage,object what,object who){
   if(random(2)){
     tell_room(EETO,"%^BOLD%^%^CYAN%^"+who->QCN+" aims a blow at "+ETOQCN+"'s right hand, but the attack "
"passes straight through as if "+ETO->QP+" %^BLACK%^black-gloved %^CYAN%^limb were not even "
"there!%^RESET%^",({ETO,who}));
     tell_object(ETO,"%^BOLD%^%^CYAN%^"+who->QCN+" aims a blow at your right hand, but the attack passes "
"straight through as if your %^BLACK%^black-gloved %^CYAN%^limb were not even there!%^RESET%^");
     tell_object(who,"%^BOLD%^%^CYAN%^You aim a blow at "+ETOQCN+"'s right hand, but the attack passes "
"straight through as if "+ETO->QP+" %^BLACK%^black-gloved %^CYAN%^limb were not even there!%^RESET%^");
     return (-1)*damage;
   }
}
