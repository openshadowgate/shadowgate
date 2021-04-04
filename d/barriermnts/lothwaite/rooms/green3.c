//Village Green for Lothwaite.  Circe 9/18/04
#include <std.h>
#include "../lothwaite.h"

inherit STORAGE"green";

void create(){
   ::create();
   set_long( ::query_long()+"  A tall %^ORANGE%^wooden pole %^GREEN%^"+
      "stands on a low mound here.  You can see the ends of %^BOLD%^"+
      "%^MAGENTA%^r%^CYAN%^i%^BLUE%^b%^GREEN%^b%^MAGENTA%^o%^CYAN%^n"+
      "%^BLUE%^s %^RESET%^%^GREEN%^waving on the breeze from its tip.\n");
   add_item(({"pole","wooden pole","ribbons"}),"%^BOLD%^%^GREEN%^Used in a springtime "+
      "festival, this %^ORANGE%^p%^RESET%^%^ORANGE%^o%^BOLD%^l%^RESET%^%^ORANGE%^e %^BOLD%^%^GREEN%^is %^MAGENTA%^d%^CYAN%^e%^WHITE%^c%^MAGENTA%^o%^CYAN%^r%^WHITE%^a%^MAGENTA%^t%^CYAN%^e%^WHITE%^d %^GREEN%^each spring with %^RED%^r%^ORANGE%^i%^RED%^b%^ORANGE%^b%^RED%^o%^ORANGE%^n%^RED%^s%^GREEN%^, which "+
      "the young girls of the village %^CYAN%^w%^WHITE%^e%^CYAN%^a%^WHITE%^v%^CYAN%^e %^GREEN%^around the pole's base.  "+
      "Spring is seen as a time of %^ORANGE%^c%^CYAN%^e%^ORANGE%^l%^WHITE%^e%^ORANGE%^b%^CYAN%^r%^ORANGE%^a%^WHITE%^t%^ORANGE%^i%^CYAN%^o%^ORANGE%^n %^GREEN%^after the harsh winters, "+
      "and no firbolg maiden would dare miss this "+
      "%^MAGENTA%^j%^RESET%^%^MAGENTA%^o%^BOLD%^y%^RESET%^%^MAGENTA%^f%^BOLD%^u%^RESET%^%^MAGENTA%^l %^BOLD%^%^GREEN%^celebration.%^RESET%^");
   set_exits(([
      "south" : PATHEXIT"green1",
      "east" : PATHEXIT"green4",
      "southeast" : PATHEXIT"green2"
   ]));
}