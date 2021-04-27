#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("scale");
   set_id(({"dragon scale","scale","white scale"}));
   set_short("%^WHITE%^%^BOLD%^white scale%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^This is a dragon scale.  It is perfectly shaped, and of a shimmering snowy-white "
"hue.%^RESET%^");
   set_weight(1);
}
