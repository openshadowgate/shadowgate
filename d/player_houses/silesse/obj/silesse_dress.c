//by ~Circe~ for Vicdaerrysn's room in Ryzan and Aunuit's house

#include <std.h>;
inherit ARMOUR;

void create(){
   ::create();
   set_name("shift");
   set_id(({"shift","green shift","dress","green dress","vicdaerrysn clothing","vic green dress"}));
   set_short("%^RESET%^%^GREEN%^a delicate g%^BOLD%^r%^RESET%^%^GREEN%^e%^YELLOW%^e%^RESET%^%^GREEN%^n shift%^RESET%^");
   set_long("%^RESET%^%^GREEN%^Sewn from delicate forest g%^BOLD%^r"
      "%^RESET%^%^GREEN%^e%^YELLOW%^e%^RESET%^%^GREEN%^n silk, this "
      "shift seems meant for dancing or relaxing beneath the %^BOLD%^l"
      "%^YELLOW%^e%^GREEN%^av%^RESET%^e%^BOLD%^%^GREEN%^s %^RESET%^%^GREEN%^"
      "rather than hunting. The dress features a simple design with slender "
      "straps and a scooped neckline that naturally accentuates the "
      "wearer's form. The dress is designed to reach the wearer's ankles, "
      "though a slit up the left side provides ease of movement and an "
      "elegant grace. A coordinating %^BOLD%^sheer scarf %^RESET%^%^GREEN%^"
      "in the colors of the f%^YELLOW%^o%^RESET%^%^GREEN%^re%^BOLD%^s%^RESET%^"
      "%^GREEN%^t may be draped over the wearer's shoulders if desired.%^RESET%^");
   set_type("clothing");
   set_limbs(({"torso"}));
   set_weight(2);
   set_size(2);
   set_value(0);
}
