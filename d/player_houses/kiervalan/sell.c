// special storage room for Kiervalan's armor & weapons shop sales


#include <std.h>;

inherit ROOM;

void create() {
   ::create();
   set_name("Kiervalan store storage");
   set_short("Kiervalan's shop storage");
   set_long("Storage room for items to sell.");
   remove_property("no teleport");
   set_property("no teleport", 1);
   set_no_clean(1);
   set_storage(1);
   restore_room();
}
