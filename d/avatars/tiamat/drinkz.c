#include <std.h>
inherit "/std/drink";

void create() {
   ::create();
   set_name("drink");
   set_short("sum drinkz");
   set_long("Oh hai. This is sum drinkz for drinkin.");
   set_strength(15);
   set_type("soft drink");
}
