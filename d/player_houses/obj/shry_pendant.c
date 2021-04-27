//shry_pendant.c - The pendant to keep butterflies from attacking in Shrydelhi's meadow.  Coded by Circe 9/26/03

#include <std.h>
#include "/d/player_houses/shrydelhi/shry.h"
inherit "/std/armour";

void create()
{
        ::create();
        set_name("shrydelhi pendant");
        set_short("A moonstone pendant");
        set_id(({"pendant","moonstone pendant","brooch","shrydelhi pendant"}));
        set_long(
           "%^BOLD%^%^WHITE%^This sparkling pendant is made of platinum "+
           "formed into a simple smooth brooch.  Set in the center is a "+
           "large oval moonstone, whose milky color seems to glow in the "+
           "moonlight.  The brooch may be worn as a cloak clasp or pinned "+
           "to a shirt."
        );
        set_weight(1);
        set_value(0);
        set_ac(0);
        set_type("ring");
        set_limbs(({"neck"}));
}
