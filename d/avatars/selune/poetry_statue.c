//Description by Eiryasha - coded by Circe 6/7/04
//reward for the poetry contest
#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("statue");
   set_short("%^BOLD%^%^CYAN%^A gleaming crystal angel statue%^RESET%^");
   set_id(({"statue","angel statue","gleaming statue","crystal statue"}));
   set_long("Cut from a single piece of %^BOLD%^%^CYAN%^gleaming "+
      "crystal%^RESET%^, this statue diffuses the light in a brilliant "+
      "%^BOLD%^r%^BLUE%^a%^RED%^i%^GREEN%^n%^MAGENTA%^b%^CYAN%^o"+
      "%^YELLOW%^w %^RESET%^of color about in a wavering aura.  "+
      "Precisely cut to keen points and smooth curves the stature "+
      "protrays an awesomely impressive angelic figure clad for "+
      "battle.  Unfurled wings highlight the held high sword and "+
      "shield.  A light chain drapes the powerful figure.  An "+
      "androgynous mein shines brightest of all.  Thankfully the "+
      "statue has a stand of darkwood, for the keen points and "+
      "edges are too dangerous to handle with bare hands.");
   set_lore(
@CIRCE
This statue was presented to the winner of the Pre-written Poetry Contest held in Torm in the year 663 SG.
CIRCE
   );
   set_property("lore difficulty",5);
   set_weight(5);
   set_value(0);
}
