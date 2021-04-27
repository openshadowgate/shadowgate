#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("violin");
   set_short("%^RESET%^%^ORANGE%^A mahogony violin%^RESET%^");
   set_id(({"violin","nice violin","instrument","mahogony violin"}));
   set_long("This violin is a masterwork of %^GREEN%^Elvish %^RESET%^design.  The wood is chesnut stained"
" mahogony and has been intricately carved and joined together.  An exquisite"
" %^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^e %^RESET%^inlay runs along the body of the instrument."
"  The strings are masterfully produced and well cared for.  Shiny %^BOLD%^%^WHITE%^ivory knobs"
" %^RESET%^sit at the head of the instrument allowing it to be tuned.");
   set_weight(3);
   set_value(500);
}

int is_instrument() { return 1; }