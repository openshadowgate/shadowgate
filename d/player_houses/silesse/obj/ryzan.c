#include <std.h>
#include "../sil.h"

inherit ARMOUR;

void create(){
   ::create();
   set_name("faerzress ring");
   set_id(({"ring","faerzress ring","platinum ring","ryzan ring"}));
   set_short("%^BOLD%^%^WHITE%^pl%^RESET%^at%^BOLD%^inum%^RESET%^ ring");
   set_long("This sleek ring is a flat band crafted from "
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
   set_limbs(({"right hand"}));
   set_ac(0);
}

int is_faerzress_key(){ return 1; }