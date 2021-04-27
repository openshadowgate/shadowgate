#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("mistletoe");
   set_short("%^GREEN%^sprig of mistletoe%^RESET%^");
   set_id(({"mistletoe","sprig of mistletoe"}));
   set_long("%^GREEN%^This sprig of mistletoe consists of a collection of "
      "smooth-edged oval green leaves interspersed with clusters of "
      "%^RESET%^white berries%^GREEN%^.%^RESET%^");
   set_lore("Mistletoe is prized by druids and is often used in their "
      "rituals.  For others, it is often considered a weed and a nuisance.");
   set_property("lore difficulty",5);
   set_value(5);
}
