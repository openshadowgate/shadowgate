#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("snow-white overcoat");
   set_id(({"coat","overcoat","white overcoat","snow-white overcoat","small overcoat","mantle","mantle of winter's chill"}));
   set_short("%^BOLD%^%^WHITE%^Mantle of W%^CYAN%^in%^WHITE%^ter's Ch%^CYAN%^il%^WHITE%^l%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^a small snow-white overcoat%^RESET%^");
   set_long("This little overcoat would only fit a child, due to its "
"%^MAGENTA%^ti%^RED%^n%^MAGENTA%^y %^RESET%^size. Along with this, it has been cut "
"in quite an odd shape, as if it were designed for a hunched and bent little "
"creature. It is quite clean, with only a few little %^ORANGE%^smudges %^RESET%^of "
"dirt and signs of wear upon its %^BOLD%^%^WHITE%^snowy-white %^RESET%^linen "
"surface. %^BOLD%^%^WHITE%^S%^CYAN%^il%^WHITE%^very-b%^CYAN%^lu%^WHITE%^e%^RESET%^ "
"thread trims the edges of the garment, and a few tiny %^BOLD%^%^WHITE%^"
"sn%^RESET%^o%^BOLD%^%^WHITE%^wfl%^RESET%^a%^BOLD%^%^WHITE%^kes %^RESET%^have been "
"embroidered across the linen in the same glittering thread.\n");
   set_lore("Such coats as this are prized by the priesthood of the Frostmaiden, "
"marking them as Auril's faithful amongst the masses. This coat seems specially "
"made for a creature not of human form though, judging by the cut and size of the "
"garment, and the small hole left as if to fit a tail at the back.");
   set_property("lore difficulty",11);
   set_weight(2);
   set_value(100);
   set_type("ring");
   set_limbs(({"torso"}));
   set_size(1);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   if((string)ETO->query_name() != "grigil" && !avatarp(ETO)) {
     tell_object(ETO,"The little coat doesn't seem to fit you.");
     return 0;
   }
   tell_object(ETO,"%^CYAN%^You slide into the overcoat, reminded of the %^BOLD%^"
"%^WHITE%^ch%^CYAN%^il%^WHITE%^l %^RESET%^%^CYAN%^touch of winter.%^RESET%^");
   tell_room(EETO,"%^CYAN%^"+ETOQCN+" draws the little overcoat around "+ETO->QP+
" shoulders.%^RESET%^",ETO);
   ETO->add_saving_bonus("all",1);
   ETO->set_property("magic resistance",5);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^CYAN%^You feel revealed and vulnerable without the protection "
"of the overcoat.%^RESET%^");
   tell_room(EETO,"%^CYAN%^"+ETOQCN+" looks a little uncomfortable after removing "
"the overcoat.",ETO);
   ETO->add_saving_bonus("all",(-1));
   ETO->set_property("magic resistance",-5);
   return 1;
}
