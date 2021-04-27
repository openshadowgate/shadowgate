#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("boots");
   set_id(({"boots","loviatar boots","high boots","black boots","high black boots","paces","paces of the painbringer"}));
   set_short("%^BLACK%^%^BOLD%^Pac%^RESET%^%^RED%^e%^BLACK%^%^BOLD%^s of the Pa%^RESET%^%^RED%^i%^BLACK%^%^BOLD%^nbri%^RESET%^%^RED%^n%^BLACK%^%^BOLD%^ger%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^high black boots%^RESET%^");
   set_long("%^CYAN%^Treated %^BLACK%^%^BOLD%^black leather%^RESET%^%^CYAN%^ forms this pair of high boots, "
"that would extend all the way to the knees when worn.  The lower sole of each is thickened to support the "
"foot, and buckles carved of %^BLACK%^%^BOLD%^jet%^RESET%^%^CYAN%^ secure them along the outer side of each "
"leg.  Along the inner surface of the boots is a lining of soft %^RED%^blood-red cloth%^CYAN%^, that would "
"give striking glimpses of %^RED%^%^BOLD%^crimson%^RESET%^%^CYAN%^ along the top and sides of the boots as the "
"wearer walks.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Rumours abound concerning these boots and the clergy of Loviatar.  The most "
"prevalent tells that boots such as these are gifted only to those of her clergy most familiar with her ways "
"and wishes, who are said to 'walk the path of the Maiden'.");
   set_property("lore difficulty",7);
   set_weight(2);
   set_value(0);
   set_ac(0);
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_wear((:TO,"wear_fun":));
   set_remove("%^WHITE%^%^BOLD%^You feel a shudder of pain as you remove the boots.");
}

int wear_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel the touch of your god carried within the boots.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" slides the boots onto "+ETO->QP+" feet with a look of "
"pride.",ETO);
   return 1;
}
