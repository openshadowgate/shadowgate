#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("silver fetish");
   set_id(({"amulet","fetish","silver fetish","geist"}));
   set_short("%^BLACK%^%^BOLD%^Hunter's Geist%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^a silver fetish%^RESET%^");
   set_long("%^RESET%^Crafted from %^BOLD%^silver%^RESET%^, this amulet is "
"shaped into the form of a "
"%^BLACK%^%^BOLD%^ja%^RESET%^g%^BLACK%^%^BOLD%^g%^RESET%^e%^BLACK%^%^BOLD%^d "
"sh%^RESET%^at%^BLACK%^%^BOLD%^ter%^RESET%^i%^BLACK%^%^BOLD%^ng%^RESET%^ "
"moon. Heavy woven strands of %^BLACK%^%^BOLD%^black hair%^RESET%^ have been "
"wound through the cracks in the moon, making an even more "
"%^RED%^sinister%^RESET%^ appearance to the pendant. It seems to almost "
"%^BOLD%^glow%^RESET%^ with a soft luster in the light. It hangs on a thick "
"chain of %^BOLD%^silver%^RESET%^.\n");
   set_lore("An amulet such as this, imbued with the right magicks, can be "
"used to keep werecreatures at bay. Twining the hairs of a particular beast "
"around the amulet will serve as far greater protection against that specific "
"creature.");
   set_property("lore difficulty",16);
   set_limbs(({"neck"}));
   set_weight(1);
   set_value(0);
   set_ac(0);
   set_size(2);
   set_type("ring");
}
