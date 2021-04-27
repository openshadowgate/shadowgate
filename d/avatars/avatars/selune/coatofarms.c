//coatofarms.c  Circe 4/24/03 - generic item for coat of arms
//coded for Selune to help with knight/noble rp
#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("coat of arms");
   set_short("coat of arms");
   set_id(({"coat","coat of arms","patent","patent of nobility"}));
   set_long(
      "This is a generic patent used to establish lineage and nobility."
   );
   set_weight(2);
   set_value(0);
}
