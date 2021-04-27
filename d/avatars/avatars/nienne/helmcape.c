#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("half-cape");
   set_obvious_short("%^BOLD%^%^WHITE%^A stunning white half-cape%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^Cape of the %^BLUE%^Vi%^RESET%^%^BLUE%^g%^BOLD%^il%^RESET%^%^BLUE%^a%^BOLD%^nt E%^RESET%^%^BLUE%^y%^BOLD%^e%^RESET%^");
   set_id(({"cape","stunning cape","white cape","white half-cape","half-cape","half cape","cape of the watchful eye"}));
   set_long("%^WHITE%^%^BOLD%^This stunning cape is extremely lightweight, cut into a fashionable "
"half-length garment that would only just cover the wearer's back.  Woven around the seams of the "
"snow-white silk of the cape, are tiny, metallic threads of %^RESET%^%^BLUE%^deep blue%^BOLD%^%^WHITE%^, "
"that shimmer with the ripples of the cloth.  An ornate %^RESET%^%^WHITE%^platinum clasp%^BOLD%^ holds the "
"cape closed across the wearer's neck, crafted to form the image of a right-handed war gauntlet when "
"closed.  Upon the back of the gauntlet-shaped clasp is a emblem in %^BLUE%^blue enamel%^WHITE%^, of a "
"single vigilant, staring eye.%^RESET%^\n");
   set_lore("This cape was thought to be lost many decades ago, during a particularly vicious war between "
"the city of Antioch, and an invading force of evil from the ruins east of the city.  While the force was "
"eventually overcome, many noble warriors fell in the battle, most of whom were loyal to the faith of the "
"Watcher, and his cathedral in the city.  Carnak Ennorlon was one of the many lost that day, along with the "
"blessed cape he had been gifted with for services to his church.%^RESET%^");
   set_property("lore difficulty",10);
   set_weight(2);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_ac(0);
   set_value(540);
   set_property("enchantment",1);
   set_wear("%^BOLD%^%^WHITE%^You proudly fasten the clasp, letting the cape rest over your shoulders.");
   set_remove("%^BOLD%^%^WHITE%^You undo the clasp and remove the cape with a pang of regret.");
}

