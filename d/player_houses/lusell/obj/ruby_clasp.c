//changed to reflect Lusell's new faith.  Circe 5/19/04
#include <std.h>
inherit "/std/armour";

void create(){
   ::create();
   set_name("emerald clasp");
   set_short("%^BOLD%^%^GREEN%^Em%^RESET%^%^GREEN%^e%^RESET%^r%^GREEN%^"+
      "a%^BOLD%^ld %^BLACK%^Cl%^WHITE%^a%^BLACK%^sp%^RESET%^");
   set_id(({"emerald clasp","clasp","lusell_house clasp"}));
   set_long(
      "%^RESET%^%^GREEN%^The clasp is made of %^YELLOW%^gold "+
      "%^RESET%^%^GREEN%^and %^BOLD%^emeralds%^RESET%^%^GREEN%^.  "+
      "The gems are affixed to the surface of the %^YELLOW%^gold "+
      "%^RESET%^%^GREEN%^to resemble a %^BOLD%^%^BLACK%^clenched "+
      "fist%^RESET%^%^GREEN%^.  Inside the fist, a %^BOLD%^glow "+
      "%^RESET%^%^GREEN%^eminates caused by some enchanted emeralds. "+
      "The clasp is used to pin a cloak together just below the neck."
   );
   set_weight(1);
   set_value(0);
   set_ac(0);
   set_type("ring");
   set_limbs(({"neck"}));
}