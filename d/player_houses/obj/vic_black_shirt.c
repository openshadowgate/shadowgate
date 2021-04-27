//by ~Circe~ for Vicdaerrysn's room in Ryzan and Aunuit's house
//description based on the shirt I coded for Tharis

#include <std.h>;
inherit ARMOUR;

void create(){
   ::create();
   set_name("shirt");
   set_id(({"shirt"}));
   set_short("%^BOLD%^%^BLACK%^an ebony shirt%^RESET%^");
   set_long("This well-made shirt is rather simple in design, made "+
      "for comfort and ease of movement rather than an ostentatious "+
      "display of wealth.  Still, the silk is very high quality, "+
      "and the design is flawless.  It has been dyed a %^BOLD%^%^BLACK%^"+
      "deep ebony%^RESET%^, the color saturating "+
      "each fiber to enhance the overall appearance.");
   set_type("clothing");
   set_limbs(({"torso"}));
   set_weight(3);
   set_size(2);
   set_value(0);
}
