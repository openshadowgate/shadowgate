#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("lamp");
     set_short("%^RESET%^%^ORANGE%^Ts%^YELLOW%^a%^RESET%^%^ORANGE%^rven "
"%^YELLOW%^O%^RESET%^%^ORANGE%^il L%^YELLOW%^a%^RESET%^%^ORANGE%^mp%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^curious b%^YELLOW%^r%^RESET%^%^ORANGE%^on%^YELLOW%^z%^RESET%^%^ORANGE%^e curio%^RESET%^");
      set_id(({"curio","lamp","bronze curio","bronze lamp"}));
   set_long("%^RESET%^%^ORANGE%^Formed entirely "
"of bronze, this seems for all the world to be "
"a mundane piece of junk.");
}
