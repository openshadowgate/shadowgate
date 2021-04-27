#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("gemstone");
   set_id(({"gem","gemstone","clear gemstone"}));
   set_short("%^CYAN%^%^BOLD%^a clear gemstone%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^This %^CYAN%^clear gemstone %^WHITE%^is mostly transparent, with a little "
"clouding around the edges.  It holds no color whatsoever, and seems rather light, even for something of its "
"size.%^RESET%^");
   set_weight(1);
}
