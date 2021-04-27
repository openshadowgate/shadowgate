#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("necklace");
   set_id(({"necklace","malar necklace","hunter's pride","hunters pride","pride","necklace of bones","leather necklace","leather necklace of bones"}));
   set_short("%^BOLD%^%^BLACK%^H%^RESET%^%^ORANGE%^un%^RED%^t%^BOLD%^e%^RESET%^%^RED%^r%^ORANGE%^'s %^BOLD%^%^BLACK%^Pr%^RESET%^%^ORANGE%^id%^RED%^e%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^a leather necklace of %^WHITE%^bones%^RESET%^");
   set_long("%^CYAN%^This sturdy necklace consists primarily of a thick, braided cord of %^ORANGE%^dark leather"
"%^CYAN%^, not treated to a smooth texture, but instead left rough and rugged around its edges.  Draped from "
"the cord itself are numerous pieces of bone - fangs, talons and knuckles - in all shades of %^BOLD%^%^WHITE%^"
"ivory%^RESET%^%^CYAN%^ and %^WHITE%^off-white %^CYAN%^through to %^ORANGE%^dull brown%^CYAN%^, some stained "
"by what appears to be %^RED%^blood%^CYAN%^.  Interspersed among them are a few small tufts of %^BOLD%^"
"%^BLACK%^m%^RESET%^%^ORANGE%^ot%^BLACK%^%^BOLD%^tl%^RESET%^%^ORANGE%^ed %^BLACK%^%^BOLD%^fu%^RESET%^%^ORANGE%^"
"r%^CYAN%^, and a scattering of %^GREEN%^mul%^BLUE%^t%^GREEN%^ico%^MAGENTA%^lo%^BLUE%^r%^GREEN%^ed %^CYAN%^"
"feathers.  They seem to hold no sort of order or pattern, but the way they are displayed along the length of "
"the necklace is remeniscent of so many trophies.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Necklaces such as these are commonly prized amongst tribal and shamanistic "
"societies, carried as a sign of status by hunters, showing the creatures they have bested in battle.  They "
"are also prized in the same manner by followers of the Beastlord, worn proudly for all to see.%^RESET%^");
   set_property("lore difficulty",7);
   set_limbs(({"neck"}));
   set_weight(2);
   set_value(0);
   set_ac(0);
   set_property("enchantment",3);
   set_size(2);
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_item_bonus("magic resistance",1);
}

int wear_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel the thrill of the hunt racing through your veins!");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" gives a sly smile as "+ETO->QS+" wears the necklace.",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^%^WHITE%^%^BOLD%^You feel the bloodlust of the hunt leave you as you "
"remove the necklace.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" seems to calm down as "+ETO->QS+" removes the necklace.",ETO);
   return 1;
}
