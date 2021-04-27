// special storage room for Kiervalan's armor & weapons repair


#include <std.h>;

inherit ROOM;

void create() {
   ::create();
   set_name("Kiervalan repair storage");
   set_short("Kiervalan's repair shop storage");
   set_long("Storage room for repaired and to be repaired items.");
   remove_property("no teleport");
   set_property("no teleport", 1);
   set_no_clean(1);
   set_storage(1);
   restore_room();
}
