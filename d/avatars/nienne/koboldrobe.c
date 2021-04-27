#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

void create() {
   ::create();
   set_name("embroidered robe");
   set_short("%^RESET%^%^ORANGE%^Robe of the %^BOLD%^%^BLACK%^Sh%^RESET%^ad%^BOLD%^%^BLACK%^ow %^RESET%^%^ORANGE%^Dragon%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^dark embroidered robe%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This long, flowing robe is made of a blend of "+
"cotton and linen left a natural shade of tan.  It is extremely "+
"comfortable and lightweight, as if "+
"it was made to be worn in a %^MAGENTA%^sultry, humid region"+
"%^ORANGE%^.  The long robes are loose in fit, perhaps to allow "+
"a %^CYAN%^cooling breeze %^ORANGE%^"+
"through the fabric's loose weave.  The robes have short sleeves, "+
"stopping just above the elbows, most likely for comfort and ease "+
"of movement.  The robes appear plain and almost monastic in "+
"design, with nothing ornate or special about them.  That is, "+
"until you see the detailed image of a %^BOLD%^%^BLACK%^sh%^RESET%^ad"+
"%^BOLD%^%^BLACK%^ow %^RESET%^%^ORANGE%^dragon %^RESET%^"+
"%^ORANGE%^in flight that covers the back of the robes.  The "+
"craftmanship on this embroidered image is extremely detailed - "+
"you can make out each individual scale on the dragon!  Something "+
"this fine and ornate must have taken years to create.%^RESET%^");
   set_value(3000);
   set_size(1);
   set_wear((:TO,"wear_stuff":));
   while((int)query_property("enchantment") != 2) {
     remove_property("enchantment");
     set_property("enchantment",2);
   }
}
