#include <std.h>
#include "../sil.h"

inherit ARMOUR;

void create(){
   ::create();
   set_name("faerzress bracelet");
   set_id(({"bracelet","faerzress bracelet","platinum bracelet","aunuit bracelet","bangle","bangle bracelet"}));
   set_short("%^BOLD%^%^WHITE%^pl%^RESET%^at%^BOLD%^inum%^RESET%^ bangle bracelet");
   set_long("This sleek bangle is two inches wide and crafted from "
      "%^BOLD%^%^WHITE%^pl%^RESET%^at%^BOLD%^inum%^RESET%^.  A single "
      "square-cut %^MAGENTA%^pur%^BOLD%^p%^RESET%^%^MAGENTA%^le stone "
      "%^RESET%^graces the center, adding an elegant touch of interest to the "
      "otherwise simple piece.");
   set_value(0);
   set_lore("Upon closer inspection, you realize that the purple stone is "
      "no ordinary amethyst - it is faerzress, found only in the deep reaches "
      "of the Underdark. What's more, a symbol has been carved within the stone, "
      "depicting a dragon rising from a plume of shadow.  You have heard tales "
      "of drow houses using such symbols.");
   set_property("lore difficulty", 20);
   set_weight(1);
   set_type("ring");
   set_limbs(({"right arm"}));
   set_ac(0);
}

int is_faerzress_key(){ return 1; }