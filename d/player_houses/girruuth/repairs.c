// special storage room for Girruuth's armor & weapons repair
// by Styx, 12/2002

#include <std.h>;

inherit ROOM;

void create() {
   ::create();
   set_name("Girruuth repair storage");
   set_short("Girruuth's repair shop storage");
   set_long("Storage room for repaired and to be repaired items.");
   remove_property("no teleport");
   set_property("no teleport", 1);
   set_no_clean(1);
   set_storage(1);
   restore_room();
}