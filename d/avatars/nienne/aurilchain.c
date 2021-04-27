#include <std.h>
inherit "/d/common/obj/armour/chain";

void create(){
   ::create();
   set_id(({"chain","chainmail","chain mail","silver chain","silver chainmail","frosty chain","frosty chainmail"}));
   set_short("%^BOLD%^%^WHITE%^fros%^CYAN%^t%^WHITE%^y si%^RESET%^l%^BOLD%^%^WHITE%^ver chainmail%^RESET%^");
   set_long("This armor is made of interlocking metal rings, each smelted "
"from %^BOLD%^%^WHITE%^bri%^RESET%^g%^BOLD%^%^WHITE%^ht si%^RESET%^l%^BOLD%^"
"%^WHITE%^ver%^RESET%^. It has a layer of %^BOLD%^%^WHITE%^quilted white "
"fabric %^RESET%^underneath, to prevent painful chafing and to cushion the "
"impact of blows.  Several layers of mail are hung over vital areas.  The "
"links yield easily to blows, absorbing some of the shock. Oddly, the metal "
"is %^BOLD%^%^CYAN%^icy-cold %^RESET%^to the touch, and coated with a faint "
"layer of %^BOLD%^%^WHITE%^fr%^CYAN%^os%^WHITE%^ty r%^CYAN%^im%^WHITE%^e"
"%^RESET%^, as though it had been just pulled out of a pile of %^BOLD%^"
"%^WHITE%^snow%^RESET%^.\n"); 
   set_lore("Such armor is commonly favored by warriors and travellers who "
"seek the added protection of metal armor, without the weight and "
"constrictive nature of heavier plated designs. Crafted in all kinds of "
"metals and designs, they offer good protection from many kinds of weapons. "
"This suit seems unusual in that it is always cold to the touch, with tiny "
"traces of frost still clinging to the rings of metal, as if it had just been "
"lifted from the snow.\n");
   set_property("lore difficulty",4);
   set_size(2);
   set_property("enchantment",1);
   set_value(700);
   set_wear((:TO,"wear_fun":));
}

int wear_fun(){
   if((string)ETO->query_diety() != "auril" && !avatarp(ETO)) {
     tell_object(ETO,"The armor is freezing cold! You think better of it.");
     tell_room(EETO,""+ETO->QCN+" seems to think twice about wearing the chilled armor.",ETO);
     return 0;
   }
   tell_object(ETO,"%^CYAN%^The chilled armor reminds you of the embrace of winter.%^RESET%^");
   return 1;
}
