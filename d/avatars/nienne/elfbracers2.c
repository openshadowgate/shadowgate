#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
   ::create();
   set_name("leather bracers");
   set_id(({"bracers","leather bracers","forestwalker's cuffs","cuffs","mottled bracers","mottled leather bracers"}));
   set_short("%^RESET%^%^GREEN%^For%^ORANGE%^e%^GREEN%^stwa%^ORANGE%^l%^GREEN%^ker's Cuffs%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^m%^ORANGE%^o%^GREEN%^tt%^ORANGE%^l%^GREEN%^ed %^ORANGE%^leather bracers%^RESET%^");
   set_long("Thickened %^ORANGE%^leather %^RESET%^forms these sturdy and "
"durable bracers, designed to protect the wearer's forearms. Interwoven laces "
"hold them secure beneath the wearer's arms, running up the underside of each "
"cuff. Despite their thickness, they seem fairly %^RED%^fl%^ORANGE%^e%^RED%^"
"xible %^RESET%^and allow for plenty of movement by the wearer. They have "
"been dyed in part in a dark shade of %^GREEN%^olive%^RESET%^, forming a "
"%^GREEN%^m%^ORANGE%^ot%^GREEN%^tl%^ORANGE%^ed %^RESET%^pattern that would "
"blend in well in forests or shadows. Upon each, a simple pattern of vines "
"and leaves has been %^BOLD%^%^BLACK%^burnt %^RESET%^into the leather itself, "
"accentuating their otherwise plain appearance.\n");
   set_ac(1);
   set_size(2);
   set_property("enchantment",2);
   set_item_bonus("stealth",2);
   set_value(450);
   set_lore("Bracers such as these are favored by elvenkind, particularly "
"forest scouts. Dyed darkly to allow for concealment within the forests, they "
"are formed of thickened leather to afford defense, without detracting from "
"the wearer's mobility. They are often decorated with patterns that the elves "
"hold a fondness for - trees, plants and animals of all kinds.\n");
   set_property("lore difficulty",7);
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
}

int check(){
   ::check();
   if((string)ETO->query_race() != "elf" && (string)ETO->query_race() != "half-elf" && (string)ETO->query_race() != "halfling" && !avatarp(ETO)) {
     tell_object(ETO,"The bracers don't seem to fit you.");
     tell_room(EETO,"The bracers don't seem to fit "+ETO->QCN+".",ETO);
     return 0;
   }
   tell_room(EETO,"%^GREEN%^"+ETO->QCN+" slides the mottled bracers over "
+ETO->QP+" forearms.%^RESET%^",ETO);
   tell_object(ETO,"%^GREEN%^The mottled bracers meld easily to fit around "
"your forearms.%^RESET%^");
   return 1;
}

int remove_fun(){
  tell_room(EETO,"%^GREEN%^"+ETOQCN+" gently removes the mottled "
"bracers.%^RESET%^",ETO);
  tell_object(ETO,"%^GREEN%^You slide your forearms free of the comfortable "
"bracers.%^RESET%^");
  return 1;
}
