#include <std.h>
inherit ARMOUR;

create() {
  ::create();
  set_name("An oddly shaped metal ring");
  set_id(({"ring","metal ring","oddly shaped metal ring","lusell_shop_key"}));
  set_short("An oddly shaped metal ring");
  set_long("%^BOLD%^%^BLACK%^The band of this ring is made from "+
  "a piece of dark metal.  A piece of %^RESET%^%^WHITE%^silver "+
  "metal%^BOLD%^%^BLACK%^ comes up off of the band at the top "+
  "and forms another band, this one horizontal.  In the center "+
  "of the horizontal band there rises another piece of "+
  "metal approximately an inch long and several small prongs "+
  "jut up from the band, in a circle around the longer "+
  "piece of metal.%^RESET%^");
  set_type("ring");
  set_limbs(({"right hand"}));
  set_weight(1);
  set_value(10);
}
