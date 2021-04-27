// /d/newbie/obj/misc/rock.c

#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_long("%^RESET%^%^RED%^At first glance one can immediately tell how this unique gem got its name.  Perfectly shaped and deep red in color, this gem is about the size of a large orange with no mars or facets on its surface.  Deep within the center of the gem a hazy cloud seems to be in motion and it is quite obvious that this is no run of the mill easy find.%^RESET%^");
   set_short("%^%^RESET%^%^RED%^A perfectly shaped blood ruby%^RESET%^");
   set_id(({"ruby","summoning stone","blood ruby","gem"}));
   set_weight(2);
   set_value(5000);
   set_property("enchantment",5);
}
