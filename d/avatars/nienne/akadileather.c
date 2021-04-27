#include <std.h>
inherit "/d/common/obj/armour/studded";

void create(){
   ::create();
   set_name("%^BLACK%^%^BOLD%^pale gray studded leather%^RESET%^");
   set_id(({"leather","studded","studded leather","gray studded","gray leather","gray studded leather","pale gray leather","pale gray studded leather","pale gray studded","shroud","shroud of the tempest"}));
   set_short("%^BLACK%^%^BOLD%^Shroud of the T%^RESET%^%^WHITE%^em%^BLACK%^%^BOLD%^p%^RESET%^%^WHITE%^es%^BLACK%^%^BOLD%^t%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^dull gray studded leather%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^From a distance, this leather suit looks rather mundane, tinted a drab hue of "
"%^BLACK%^slate-gray%^WHITE%^.  Pale metal studs have been placed at even intervals across its surface, dulled "
"so as not to reflect any light.  The suit itself is quite sturdy, and would protect a wearer well, although "
"it seems a little lighter in weight than other similar pieces of armor.\n%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^Throughout the ages, there is no mention of any item such as this except for "
"one.  It belonged to an Akadian warrior whose name has been lost to the ages, although he was reknowned for "
"his battle skills through speed and grace, rather than his strength.  He undertook many tasks on Akadi's "
"behalf, travelling as a nomad across the lands.  It was said that one day, Akadi acted upon a whim and simply "
"took him from the earth and bore him away up through the wind and clouds, never to be seen again.%^RESET%^\n");
   set_property("lore difficulty",13);
   set_size(2);
   set_weight(20);
   set_value(4500);
   set_property("enchantment",2);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   if((string)ETO->query_diety() != "akadi") {
     tell_object(ETO,"You can't fit into the suit of leather!");
     return 0;
   }
   tell_room(EETO,"%^CYAN%^%^BOLD%^The %^BLACK%^dull %^CYAN%^suit of leather ripples and %^WHITE%^lightens "
"%^CYAN%^as "+ETOQCN+" slips into it.%^RESET%^",ETO);
   tell_object(ETO,"%^CYAN%^%^BOLD%^The %^BLACK%^dull %^CYAN%^suit of leather ripples and %^WHITE%^lightens "
"%^CYAN%^as you slip into it.%^RESET%^");
   ETO->add_attack_bonus(2);
   set_obvious_short("%^BLACK%^%^BOLD%^m%^RESET%^%^WHITE%^ot%^BLACK%^%^BOLD%^t%^RESET%^%^WHITE%^le%^BLACK%^%^BOLD%^d studded leather%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^From a distance, this leather suit looks rather mundane, tinted a drab hue of "
"%^BLACK%^slate-gray%^WHITE%^.  Upon a closer look, however, it becomes obvious that it is much more than "
"this.  All across its surface is a mottled, rippling pattern of %^RESET%^%^WHITE%^pale ashen shades%^BOLD%^, "
"like clouds drifting across the sky.  %^BLACK%^Pale metal studs %^WHITE%^have been placed at even intervals "
"across its surface, softly reflecting light in %^RESET%^%^WHITE%^milky hues%^BOLD%^.  The suit itself seems "
"quite sturdy, and would protect a wearer well, although it seems a little lighter in weight than other "
"similar pieces of armor.\n%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^CYAN%^%^BOLD%^The leather suit %^BLACK%^dulls %^CYAN%^again as it is removed.%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^dull gray studded leather%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^From a distance, this leather suit looks rather mundane, tinted a drab hue of "
"%^BLACK%^slate-gray%^WHITE%^.  Pale metal studs have been placed at even intervals across its surface, dulled "
"so as not to reflect any light.  The suit itself is quite sturdy, and would protect a wearer well, although "
"it seems a little lighter in weight than other similar pieces of armor.\n%^RESET%^");
   ETO->add_attack_bonus(-2);
   return 1;
}

void init() {
   ::init();
   add_action("stab_fun","stab");
}

int stab_fun(string str) {
   if(!TP->is_class("thief")) return 0;
   if(!str) return 0;
   if(!TO->query_worn()) return 0;
   if(!random(4)) return 0;

   if (present(str,EETO) && sizeof(TP->query_wielded())) {
     tell_room(ETP,"%^CYAN%^%^BOLD%^A %^WHITE%^light wind %^CYAN%^picks up around you, ruffling your hair and "
"clothes.%^RESET%^",TP);
     tell_object(TP,"%^CYAN%^%^BOLD%^A %^WHITE%^light wind %^CYAN%^picks up around you, seeming to guide your "
"weapons as you strike!%^RESET%^");
   }
   return 0;
}
