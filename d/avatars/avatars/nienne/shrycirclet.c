#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("silver circlet");
   set_id(({"silver circlet","mesh circlet","coronet","circlet","woven circlet","silver mesh circlet","woven silver mesh circlet","coronet of the enstarred"}));
   set_short("%^BOLD%^%^WHITE%^Co%^RESET%^r%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^WHITE%^et of the En%^CYAN%^s%^WHITE%^tar%^CYAN%^r%^WHITE%^ed%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^woven s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r mesh circ%^CYAN%^l%^WHITE%^et%^RESET%^");
   set_long("This beautiful circlet is formed of several strands of fine "
"%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r "
"%^RESET%^metal. Each has been woven into an %^MAGENTA%^el%^RED%^a"
"%^MAGENTA%^bor%^RED%^a%^MAGENTA%^te %^RESET%^pattern throughout the other "
"strands with gaps between, leaving a flat mesh of %^BOLD%^%^WHITE%^bright "
"metal %^RESET%^that could be worn around the head. At the very front, the "
"strands interweave into an oval frame that surrounds a small milky "
"%^BOLD%^mo%^RESET%^on%^BOLD%^s%^RESET%^to%^BOLD%^ne%^RESET%^, which would "
"rest upon the wearer's brow. The entire piece radiates a %^CYAN%^so%^BOLD%^"
"f%^RESET%^%^CYAN%^t g%^BOLD%^l%^RESET%^%^CYAN%^ow%^RESET%^, shedding gentle "
"light all around it.\n");
   set_lore("A precious item to the faith of the Moonmaiden, circlets such as "
"these are oft bestowed to the most devout of her followers. They are said to "
"carry the very light of the moon within them, so that the wearer is always "
"kept safe under Selune's watchful gaze.");
   set_property("lore difficulty",20);
   set_weight(4);
   set_value(4000);
   set_type("chain");
   set_limbs(({"head"}));
   set_property("enchantment",5);
   set_wear((:TO,"wearit":));
   set_remove((:TO,"removeme":));
}

int wearit() {
   if((string)ETO->query_diety() != "selune" && !avatarp(ETO)) {
     tell_object(ETO,"The delicate circlet does not seem to fit you!");
     return 0;
   }
   if((int)ETO->query_lowest_level() < 30){
     tell_object(ETO,"The delicate circlet does not seem to fit you!");
     return 0;
   }
   tell_object(ETO,"%^CYAN%^You place the circlet upon your head, and feel "
"the blessings of Selune as a gentle %^BOLD%^aura%^RESET%^%^CYAN%^ becomes "
"apparent around you.%^RESET%^");
   tell_room(EETO,"%^CYAN%^A gentle %^BOLD%^aura%^RESET%^%^CYAN%^ becomes "
"apparent around "+ETO->QCN+" as "+ETO->QS+" places the circlet upon "
+ETO->QP+" head.%^RESET%^",ETO);
   ETO->set("long","%^CYAN%^A soft %^BOLD%^%^WHITE%^si%^RESET%^l%^BOLD%^"
"%^BLACK%^v%^RESET%^e%^BOLD%^%^WHITE%^ry %^RESET%^%^CYAN%^aura surrounds "
+objective(ETO)+".%^RESET%^");
   ETO->set_property("empowered",1);
   return 1;
}
int removeme(){
   tell_object(ETO,"%^CYAN%^The soft %^BOLD%^aura%^RESET%^%^CYAN%^ fades "
"from around you, but you know Selune is still watching over you.%^RESET%^");
   tell_room(EETO,"%^CYAN%^The soft %^BOLD%^aura%^RESET%^%^CYAN%^ fades from "
"around "+ETO->QCN+".%^RESET%^",ETO);
   ETO->set_property("empowered",-1);
   ETO->set("long");
   return 1;
}
