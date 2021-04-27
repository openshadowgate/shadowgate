//by ~Circe~ for Vicdaerrysn's room in Ryzan and Aunuit's house
//description stolen from the pants I coded for Tharis

#include <std.h>;
inherit ARMOUR;

void create(){
   ::create();
   set_name("pants");
   set_id(({"pants","black pants","black leather pants","leather pants","vicdaerrysn clothing","vic black pants"}));
   set_short("%^BOLD%^%^BLACK%^black leather pants%^RESET%^");
   set_long("This pair of breeches is made from tight-fitting "+
      "supple %^BOLD%^%^BLACK%^black leather%^RESET%^.  The leather is thin "+
      "and form-fitting, accentuating every aspect of the wearer's "+
      "legs - good or bad.  Only the most self-assured would "+
      "probably wear such pants - though they would likely look "+
      "quite nice in them.");
   set_type("clothing");
   set_limbs(({"right leg","left leg"}));
   set_weight(2);
   set_size(2);
   set_value(0);
}
