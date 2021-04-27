#include <std.h>
inherit "/std/food";

void create() {
   ::create();
   set_name("food");
   set_short("sum fuds");
   set_long("Oh hai. This is sum fuds for eatz.");
   set_strength(15);
}
