#include <std.h>
inherit "/d/common/mons/bat";

void create() {
   ::create();
   set_name("penguin");
   set_id(({"penguin","monster","animal"}));
   set_short("A pinguin");
   set_long("This is a black and white pinguin. "+
   " They like to hang around on the ice when "+
   "they are not swimming in the sea looking for fish to eat.");
   set_gender(random(2) ? "male" : "female");
   set_race("penguin");
}