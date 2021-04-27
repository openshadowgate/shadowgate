// no animate comp bag
// coded 12/7/09 by hades
#include <std.h>
#include <move.h>
#include <components.h>
inherit "/d/magic/comp_bag";

void create() {
   ::create();
   comp = ([]);
   set_weight(10);
   set_value(0);
   set_id(({"componenter", "bag","leather bag", "components bag",
"compx"}));
   set_name("no animate bag");
   set_short("%^BOLD%^A %^BLUE%^r%^WHITE%^u%^BLUE%^ne c%^WHITE%^o%^BLUE%^vered%^WHITE%^ leather bag%^RESET%^");
   set_long(
@MAGICK
           This is a small to medium-sized leather bag.  It is
           only in this bag that you store the material components
           for casting your spells.  
           There are several %^BOLD%^%^BLUE%^Glowing Runes%^RESET%^ on it.

           To check what is in the bag type <components>.
           To put a component into the bag type:
           <put [component name] into components bag>
           To retrieve components from the bag type:
           <produce [quantity] [component name]>
           <produce [all] [component name]>

MAGICK
           );
	set_property("no animate",1); // mages will love this
}
