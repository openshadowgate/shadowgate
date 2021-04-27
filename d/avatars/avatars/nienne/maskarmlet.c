#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("armband");
   set_id(({"armband","crystal armband","crystalline armband"}));
   set_short("%^BOLD%^%^CYAN%^a crys%^WHITE%^t%^CYAN%^alline armb%^WHITE%^a%^CYAN%^nd%^RESET%^");
   set_long("%^CYAN%^This armband appears to be particularly delicate, shaped from a piece of faceted "
"%^BOLD%^crystal %^RESET%^%^CYAN%^that is utterly flawless, like a piece of %^BOLD%^%^WHITE%^unm%^CYAN%^e"
"%^WHITE%^lting ice%^RESET%^%^CYAN%^.  Unlike normal crystal though, it doesn't seem to %^YELLOW%^sparkle "
"%^RESET%^%^CYAN%^and reflect light that touches it - instead, it seems to drink it in, somehow "
"%^BOLD%^%^BLACK%^darkening %^RESET%^%^CYAN%^the air around it.  It has been etched into the silhouette of a "
"tiny %^GREEN%^dra%^BOLD%^g%^RESET%^%^GREEN%^on%^CYAN%^, its wings folded across its back, with its clawed "
"feet and coiled tail allowing it to grip the wearer's arm as though it were alive.  Two tiny %^RED%^crimson "
"%^CYAN%^gemstones form the eyes, enchanted or somehow made to %^RED%^g%^BOLD%^l%^RESET%^%^RED%^ow %^CYAN%^"
"with a light all their own.%^RESET%^\n");
   set_type("ring");
   set_limbs(({"right arm"}));
   set_ac(0);
   set_size(2);
   set_property("enchantment",1);
   set_weight(1);
   set_value(350);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun(){
   tell_room(EETO,"%^BOLD%^%^CYAN%^The armband seems to coil around "+ETO->QCN+"'s arm with a life of its own.%^RESET%^",ETO);
   tell_object(ETO,"%^ORANGE%^The armband coils around your arm, as though it has a life of its own.%^RESET%^");
   return 1;
}

int remove_fun(){
  tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" carefully slides off the armband.%^RESET%^",ETO);
  tell_object(ETO,"%^BOLD%^%^CYAN%^The armband loosens upon your arm, and you slide it free.%^RESET%^");
  return 1;
}
