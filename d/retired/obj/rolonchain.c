#include <std.h>
inherit "/d/common/obj/armour/chain";

void create() {
   ::create();
   set_id(({"armor","armour","chain","chainmail","mithril chain","mithril chainmail","shiny chain"}));
   set_short("%^WHITE%^A %^BOLD%^%^WHITE%^shiny %^RESET%^%^WHITE%^suit of mithril chain%^RESET%^");
   set_long("%^RESET%^This %^BOLD%^%^WHITE%^chainmail %^RESET%^seems of the %^BOLD%^%^WHITE%^highest quality %^RESET%^that one could find within the realms, made of sparkling%^BOLD%^%^WHITE%^ mithril%^RESET%^. A %^BOLD%^%^WHITE%^glossy finish %^RESET%^seems to make it sparkle and shine in the light. This looks be of the finest metal, but also appears to be quite newly made, perhaps even personally made for someone in particular recently.%^RESET%^\n");
   set_property("enchantment",2);
   set_item_bonus("dexterity",1);
   set_value(780);
   set_lore("%^WHITE%^%^BOLD%^You recall hearing that this suit of chainmail was personally made for one of "
"the pirate captains roaming on the pirate's cove by the name of Rolon Garrote. Quite vain, he had this suit "
"personally tailored to enchance his appearance in public, while simultaneously, giving him adequate room for "
"movement and flexibility in private combat.%^RESET%^\n");
   set_property("lore difficulty",13);
}