#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("sparrow key");
   set_id(({"steel key","steel sparrow key","key","drille key"}));
   set_short("%^BOLD%^%^BLACK%^steel sparrow key%^RESET%^");
   set_long("%^CYAN%^This is a finely crafted key, made of fine, strong "
"steel. The handle sports two sparrows standing beak to beak.%^RESET%^\n");
   set_weight(1);
   set_value(0);
}
